## Language Core

```gary
fn dist(ax: f32, ay: f32, bx: f32, by: f32) -> f32 {
    return sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
}

fn saxpy(n: i32, a: f32, x: [f32], y: [f32]) -> [f32] {
    return map(i in 0..n) { a * x[i] + y[i] };
}

fn dot(n: i32, x: [f32], y: [f32]) -> f32 {
    return reduce(i in 0..n, init 0.0) { acc + x[i]*y[i] };
}
```

- Types: `i32`, `f32` (add `i64/f64` only when a benchmark needs them).
- Parallel primitives: `map` / `reduce` over an index range. Nested `map` =
  deferred (V2 at the earliest — combinator scheduling is a project of its own).
- No structs, no strings, no modules, no closures in V0. Scalar fns + array
  fns + `main` with CLI-shaped array inputs. Boring on purpose: frontend small,
  backend arrives fast.
- Deliberate open design decisions to resolve in-repo docs (each = devlog
  material): array value semantics vs. views; reduction determinism (fixed tree
  order V0 — nondeterministic atomics never); how `main` declares shapes.


## Grammar

This is the rough grammar definition for the gary language.

'E' denotes the empty symbol.

Punctuation tokens and reseved keywords are enclosed in quotes.

```

comment -> ^//.*

type -> "f32" | "i32"

id -> ^[a-zA-Z_][a-zA-Z0-9_]*$

int_literal -> ^(0|[1-9][0-9]*)$
 
float_literal -> ^(0|[1-9][0-9]*)\.[0-9]+$

gary-program -> function_decl_list

function_decl_list -> function_decl | function_decl_list function_decl

function_decl -> "fn" id "(" param_decl_list ")" "->" primitive_type "{" function_body "}"

param_decl_list -> E | param_decl | param_decl_list "," param_decl

param_decl -> id ":" primitive_type

primitive_type -> type | "[" type "]"

function_body -> "return" expression ";"

primary_expression -> parallel_primitive | id | int_literal | float_literal | "(" expression ")"

expression -> equality_expression

equality_expression -> relational_expression | equality_expression "==" relational_expression | equality_expression "!=" relational_expression

relational_expression -> additive_expression | relational_expression "<" additive_expression | relational_expression ">" additive_expression
                                             | relational_expression "<=" additive_expression | relational_expression ">=" additive_expression

additive_expression -> multiplicative_expression | additive_expression '+' multiplicative_expression | additive_expression '-' multiplicative_expression

multiplicative_expression -> unary_expression | multiplicative_expression '*' unary_expression | multiplicative_expression '/' unary_expression
                                                                                               | multiplicative_expression "%" unary_expression 

unary_expression -> postfix_expression | '-' unary_expression

postfix_expression -> postfix_expression "(" arg_list ")" | postfix_expression "[" expression "]" | primary_expression

arg_list -> E | expression | arg_list "," expression

parallel_primitive -> parallel_primitive_call "{" expression "}"

parallel_primitive_call -> map_call | reduce_call

map_call -> "map" "(" id "in" range ")"

reduce_call -> "reduce" "(" id "in" range "," "init" expression ")"

range -> expression ".." expression
```

### Notes

- Comparisons are currently C-Style, evaluating to 1 or 0, since no conditional statements to consume boolean types yet.
- Current reserved keywords:
  - f32
  - i32
  - fn
  - return
  - in
  - init
  - map
  - reduce
  - acc
- Builtin functions (user functions cannot shadow these names, treated as reserved.)
  - sqrt (f32)
  - abs (f32/i32)
  - min (f32/i32)
  - max (f32/i32)


## Semantics

- Range semantics: lo <= i < hi (half open), lo >= hi is zero iterations
- i32 divison/modulo by zero is a program error.
- i32 truncation is _towards_ zero. C-style to match PTX integer
- Reduction order is strict sequential left fold.
- Arrays are **not** first-class expression values.
  - `map` results are only valid as a function's return value
  - Scalar, bare arrays are sema errors.
- Deferring `let` statements for future.
