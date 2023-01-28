#include <iostream>
#include <fstream>

std::string readFile(const std::string& filePath) {
    std::ifstream inputFile(filePath);
    assert(!inputFile.fail() && "Could not open input file");

    return {std::istreambuf_iterator<char>(inputFile),
            std::istreambuf_iterator<char>()};
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "no file to compile" << std::endl;
        return 1;
    }

    std::string fileContents = readFile(argv[1]);

    return 0;
}