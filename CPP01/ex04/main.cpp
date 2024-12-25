#include <iostream>
#include <fstream>
#include <string>

void replaceInFile(const std::string& filename, const std::string& s1, const std::string& s2) {
    std::ifstream inFile(filename.c_str());
    if (!inFile.is_open()) {
        std::cerr << "Error: Cannot open input file" << std::endl;
        return;
    }

    std::string outFilename = filename + ".replace";
    std::ofstream outFile(outFilename.c_str());
    if (!outFile.is_open()) {
        std::cerr << "Error: Cannot create output file" << std::endl;
        inFile.close();
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        outFile << line;
        if (!inFile.eof())
            outFile << std::endl;
    }

    inFile.close();
    outFile.close();
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: string1 cannot be empty" << std::endl;
        return 1;
    }

    replaceInFile(filename, s1, s2);
    return 0;
}