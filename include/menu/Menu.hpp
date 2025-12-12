#pragma once
#include <string>
#include <iostream>

struct MenuView;
struct MenuLogic;

struct Menu{
    public:
    void tampilkanSemuaBarang();
    void prosesPilihan(int pilihan, bool &running, MenuLogic& logic);
    void tampilkanMenuTable();
    void tambahBarang();
    void updateBarang();
    void hapusBarang();
};