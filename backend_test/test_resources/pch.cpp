#include "pch.h"

// given a function that generates a random character,
// return a string of the requested length
std::string randomStr() {
    std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string newstr;
    int pos;
    while (newstr.size() != 10) {
        pos = ((rand() % (str.size() - 1)));
        newstr += str.substr(pos, 1);
    }
    return newstr;
}

int cleanUpTempDir() {
    return std::filesystem::remove_all(ROOT.string().c_str());
}

void setUpTempDir() {
    //delete dir if last test run here was interrupted
    cleanUpTempDir();

    std::filesystem::create_directory(ROOT);
}