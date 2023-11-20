#include "Files.h"
#include<iostream>
#include <fstream>
#include <string>

int Files :: ReadFile(std :: string filePath ) {

    std::ifstream file(filePath);

    // Check if the file is open
    if (!file.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1;
    }

    std::string line;

    // Read and print each line from the file
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    // Close the file
    file.close();
    return 0;
}


