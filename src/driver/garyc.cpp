#include "frontend/parser.h"
#include <fcntl.h>
#include <iostream>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        std::cout << "\ngaryc Compiler for Gary - a GPU acclerated array langauge.\n\n"
                  << "Usage: garyc <file> OPTIONS\n";
        return 1;
    }

    Parser parser(argv[1]);
    parser.printFile();

    return 0;
}
