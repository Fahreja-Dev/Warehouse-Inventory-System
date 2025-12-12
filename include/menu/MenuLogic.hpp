#pragma once
#include <iostream>
#include <string>
#include "utils/Color.hpp"

struct MenuLogic{
    public:
    void pilihMenu(int pilihan, bool &running);
    void handleError(int pilihan);
};