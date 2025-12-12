#include "menu/MenuView.hpp"
#include "utils/Color.hpp"
#include <iostream>

void MenuView::menampilkanMenu(){
    std::cout << "<======= MENU UTAMA ======>" << std::endl;
    std::cout << Color::CYAN;
    std::cout << "1. Tampilkan Semua Barang" << std::endl;
    std::cout << "2. Tambah Barang" << std::endl;
    std::cout << "3. Cari Barang" << std::endl;
    std::cout << "4. Update Stok Barang" << std::endl;
    std::cout << "5. Hapus Barang" << std::endl;
    std::cout << "0. Keluar" << std::endl;
    std::cout << Color::DEFAULT;
    std::cout << "<=========================>" << std::endl;
    std::cout << Color::CYAN << "Pilih menu (1-5)\n" << Color::DEFAULT << std::endl;
}

void MenuView::textOpsiMenu(){
    std::cout << Color::BLACK << Color::BG_BRIGHT_CYAN;
    std::cout << "Pilih:";
    std::cout << Color::DEFAULT << Color::BG_DEFAULT << " ";
}

void MenuView::textOpsiSelesai(){
    std::cout << "<======= MENU LAINNYA ======>" << std::endl;
    std::cout << Color::CYAN;
    std::cout << "1. Lagi" << std::endl;
    std::cout << "0. Kembali" << std::endl;
    std::cout << Color::DEFAULT;
    std::cout << "<===========================>" << std::endl;
}

void MenuView::textMenuTable(){
    std::cout << Color::CYAN;
    std::cout << "0: Kembali" << std::endl;
    std::cout << Color::DEFAULT;
}