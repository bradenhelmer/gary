// Main test invocation.
#include <cassert>
#include <cstdio>

extern void test_lexer_main();

using std::printf;

int main(int argc, char *argv[]) {
    test_lexer_main();

    printf("All tests passed.\n");
    return 0;
}
