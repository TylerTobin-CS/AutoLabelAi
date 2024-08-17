
#include <iostream>
#include <filesystem>
#include "../include/startProgram.h"
#include "../include/displayImages.h"

startProgram::startProgram(){
    DisplayImages displayImages;

    // Check directory exists

    std::string directoryEntered = "";
    bool validDirectory = false;

    while(!validDirectory){
        std::cout << "Please enter the directory name containing all images: " << std::endl;
        std::cin >> directoryEntered;

        if (displayImages.validateDirectory(directoryEntered) == true)
        {
            validDirectory = true;
        }

    }

    // Check directory contains images

    std::cout << "Checking images exist ..." << std::endl;
    if (displayImages.validateImagesExist(directoryEntered)) 
    {
        std::cout << "--- Images found ---" << std::endl;
    }
    else
    {
        std::cout << "No images found, exiting ..." << std::endl;
    }
}
