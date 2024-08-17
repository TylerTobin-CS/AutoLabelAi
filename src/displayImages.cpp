// This will display open the directory and display the images

#include <iostream>
#include <filesystem>
#include "../include/displayImages.h"


DisplayImages::DisplayImages() {}

bool DisplayImages::validateDirectory(std::string directoryEntered)
{
    if (std::filesystem::exists(directoryEntered) && std::filesystem::is_directory(directoryEntered))
        {
            std::cout << "--- Directory exists ---" << std::endl;
            return true;
        }
        else
        {
            std::cout << "Directory does not exist or is a file. Please try again." << std::endl;
            return false;
        }
}

bool DisplayImages::validateImagesExist(std::string validDirectory) {
    for (const auto& entry : std::filesystem::directory_iterator(validDirectory)) {
        if (entry.is_regular_file()) {
            std::string extension = entry.path().extension().string();
            std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
            if (extension == ".jpeg" || extension == ".jpg") {
                return true;
            }
        }
    }
    return false;
}