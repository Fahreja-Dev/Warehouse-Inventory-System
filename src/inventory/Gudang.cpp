#include <iostream>
#include "utils/Mapper.hpp"
#include "inventory/Gudang.hpp"
#include "utils/Color.hpp"
#include "table/CppConsoleTable.hpp"
#include "utils/Mapper.hpp"
#include "fmt/core.h"
#include "input/Input.hpp"
#include "menu/MenuView.hpp"
#include "menu/Menu.hpp"
#include "utils/Console.hpp"

void Gudang::tambahBarang(Barang& barang){
    Mapper::registerBarangMapping();
    auto data = Mapper::loadBarang("data/barang.json");
    data.push_back(barang);
    Mapper::saveBarang("data/barang.json", data);
    std::cout << Color::BRIGHT_GREEN << "\nData berhasil disimpan (Total: " << data.size() << " item)" << Color::DEFAULT << std::endl;
}

void Gudang::getSemuaBarang() const{
    Console::clear_screen();
    Input input;
    MenuView view;
    using ConsoleTable = samilton::ConsoleTable;
    Mapper::registerBarangMapping();
    bool running = true;
    auto data = Mapper::loadBarang("data/barang.json");

    ConsoleTable table(1 + data.size(), 4);
    
    table[0][0] = "Kode";
    table[0][1] = "Nama";
    table[0][2] = "Harga";
    table[0][3] = "Stok";

    for(size_t i = 0;i < data.size(); i++){
        const auto& d = data[i];

        table[1 + i][0] = d.kode;
        table[1 + i][1] = d.nama;
        table[1 + i][2] = fmt::format("{}", d.harga);
        table[1 + i][3] = fmt::format("{}", d.stok);
    }
    
    std::cout << "<======== DAFTAR BARANG ========>" << std::endl;
    std::cout << table << std::endl;

    while(running){
        std::string user;
        running = input.inputTableMenu(user, "Input Salah, Hanya Diperbolehkan Angka!");
    }

    Console::clear_screen();
    view.menampilkanMenu();
    view.textOpsiMenu();
}

void Gudang::updateStokBarang(const std::string& path, const std::string& kodeBarang, int stokBaru){
    Mapper::registerBarangMapping();

    Mapper::updateStokBarang(path, kodeBarang, stokBaru);
}

void Gudang::hapusBarang(const std::string& path, const std::string& kodeBarang){
    Mapper::hapusBarang(path, kodeBarang);
}

void Gudang::cariBarang(const std::string& path, const std::string& keyword){
    Console::clear_screen();
    Input input;
    MenuView view;
    Mapper::registerBarangMapping();

    auto hasil = Mapper::cariBarang(path, keyword);

    using ConsoleTable = samilton::ConsoleTable;

    ConsoleTable table(1 + hasil.size(), 4);

    table[0][0] = "Kode";
    table[0][1] = "Nama";
    table[0][2] = "Harga";
    table[0][3] = "Stok";

    for(size_t i = 0; i < hasil.size(); i++){
        const auto& d = hasil[i];
        table[1 + i][0] = d.kode;
        table[1 + i][1] = d.nama;
        table[1 + i][2] = fmt::format("{}", d.harga);
        table[1 + i][3] = fmt::format("{}", d.stok);
    }

    std::cout << "<======== HASIL PENCARIAN ========>" << std::endl;

    if(hasil.empty()){
        std::cout << "Barang tidak ditemukan." << std::endl;
    } else {
        std::cout << table << std::endl;
    }

}