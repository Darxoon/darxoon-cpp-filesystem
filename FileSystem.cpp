//
// Created by Jakob on 25/02/2020.
//

#include "FileSystem.h"
#include <iostream>
#include <fstream>
#include <string>

namespace FileSystem {

    int readFile(const std::string &path, std::vector<char> &output) {
        std::ifstream file (path, std::ios::binary | std::ios::ate);
        std::streamsize size = getFileSize(file);
        file.seekg(0, std::ios::beg);

        std::vector<char> buffer(size);
        if(file.read(buffer.data(), size)) {
            file.close();
            output = buffer;
            return 0;
        } else {
            file.close();
            std::cout << "Error: file called '" + path + "' couldn't be read.";
            return 1;
        }
    }
    int readFile(const std::string &path, std::string &output) {
        std::vector<char> contentRead;
        int readSuccess = readFile(path, contentRead);
        if(readSuccess != 0)
            return readSuccess;
        output = std::string(contentRead.data());
        return 0;
    }

    int writeFile(const std::string &path, const std::vector<char> &content) {
        std::ofstream file (path, std::ios::binary | std::ios::trunc);
        if(!file || !file.is_open()) {
            std::cout << "Error: file called '" + path + "' couldn't be opened.";
            return 1;
        }

        file.write(content.data(), content.size());
        if(!file || file.bad()) {
            std::cout << "Error: file called '" + path + "' couldn't be written to.";
        }
        return 0;
    }
    int writeFile(const std::string &path, const std::string &content) {
        int writeSuccess = writeFile(path, std::vector<char>(content.begin(), content.end()));
        if(writeSuccess != 0)
            return writeSuccess;
        return 0;
    }

    long getFileSize(const std::string &path) { // TODO: implement properly without tellg()
        std::ifstream file(path, std::ios::binary | std::ios::ate);
        std::streamsize size = file.tellg();
        return size;
    }

    long getFileSize(std::ifstream &stream) { // TODO: implement properly without tellg()
        std::streamsize size = stream.tellg();
        return size;
    }

}
