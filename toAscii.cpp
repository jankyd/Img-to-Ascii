#include <stdlib.h>
#include <iostream>
#include <opencv2/imgproc.hpp>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: toAscii [Image file] OR toAscii -h" << std::endl;
    }
    
    else {
        std::string fileName = argv[1];
        if (fileName == "-h" || fileName == "-H") {
            std::cout << "" << std::endl; //TODO: help output
            return 0;
        }
    } 
    return 0;
}