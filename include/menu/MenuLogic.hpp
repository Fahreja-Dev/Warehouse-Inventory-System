#pragma once
#include <iostream>
#include <string>
#include "utils/Color.hpp"

enum MenuOption{
    EXIT = 0,
    TAMPILKAN_BARANG = 1,
    TAMBAH_BARANG = 2,
    CARI_BARANG = 3,
    UPDATE_BARANG = 4,
    HAPUS_BARANG = 5
};

struct MenuLogic{
    public:
    void pilihMenu(int pilihan, bool &running);
    void handleError(int pilihan);
};