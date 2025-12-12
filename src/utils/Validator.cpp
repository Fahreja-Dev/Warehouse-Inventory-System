#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <algorithm>
#include "utils/Validator.hpp"
#include "utils/Color.hpp"

bool Validator::isNumber(const std::string& str){
    if (str.empty())
        return false;
    for (char c : str){
        if (!std::isdigit(c))
            return false;
    }
    return true;
}

bool Validator::isDouble(const std::string& str){
    std::string temp = str;
    temp.erase(0, temp.find_first_not_of(" \t\n"));
    temp.erase(temp.find_last_not_of(" \t\n") + 1);

    std::replace(temp.begin(), temp.end(), ',', '.');

    try{
        size_t size;
        std::stod(temp, &size);
        return size == temp.size();
    }catch(...){
        return false;
    }
}