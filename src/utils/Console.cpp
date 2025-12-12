#include "utils/Console.hpp"
#include <cstdlib>

namespace Console{
    void clear_screen(){
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    std::string detect_os(){
        #ifdef _WIN32
            return "Windows";
        #elif __linux__
            return "Linux";
        #elif __APPLE__
            return "macOS";
        #else
            return "Unknown";
        #endif
    }
}