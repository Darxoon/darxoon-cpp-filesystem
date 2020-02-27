//
// Created by Jakob on 25/02/2020.
//

#include <iostream>
#include <vector>

#ifndef IMGTEST_FILESYSTEM_H
#define IMGTEST_FILESYSTEM_H


namespace FileSystem {

    /**
     * Reads a file into a vector<char>
     * @param path The file path
     * @param output The output vector variable
     * @return Success (0 means success, everything other means error of some sort)
     */
    int readFile(const std::string &path, std::vector<char> &output);
    /**
     * Reads a file into a string
     * @param path The file path
     * @param output The output string variable
     * @return Success (0 means success, everything other means error of some sort)
     */
    int readFile(const std::string &path, std::string &output);

    /**
     * Writes a vector<char> to a file. If it already exists, it gets cleared.
     * @param path The file path
     * @param content The content to be written
     * @return Success (0 means success, everything other means error of some sort)
     */
    int writeFile(const std::string &path, const std::vector<char> &content);
    /**
     * Writes a string to a file. If it already exists, it gets cleared.
     * @param path The file path
     * @param content The content to be written
     * @return Success (0 means success, everything other means error of some sort)
     */
    int writeFile(const std::string& path, const std::string &content);

    /**
     * Gets the file size of a specified file
     * @param path The path of the file
     * @return The file size
     */
    long getFileSize(const std::string &path);
    /**
     * Gets the file size of a specified file by an existing input file stream
     * @param stream The file stream
     * @return The file size
     */
    long getFileSize(std::ifstream &stream);

}


#endif //IMGTEST_FILESYSTEM_H
