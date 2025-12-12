#pragma once
#include <string>

struct Input{
    public:
    std::string inputString(const std::string& text);
    int inputInteger(const std::string& text);
    double inputDouble(const std::string& text);
    bool inputOtherMenu(std::string& user ,const std::string& text);
    bool inputTableMenu(std::string& user, const std::string& text);
};