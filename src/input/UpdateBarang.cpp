#include <iostream>
#include "input/UpdateBarang.hpp"
#include "inventory/Gudang.hpp"
#include "menu/MenuView.hpp"
#include "input/Input.hpp"
#include "utils/Console.hpp"

void UpdateBarang::updateBarang() {
    MenuView view;
    Input input;
    bool running = true;

    while(running){
        Barang barang;
        Gudang gudang;
        std::string user;
        
        Console::clear_screen();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Membersihkan newline dari buffer setelah cin
        
        barang.kode = input.inputString("Masukkan Kode Barang: ");
        barang.stok = input.inputInteger("Masukkan Stok Barang: ");
        
        gudang.updateStokBarang("data/barang.json", barang.kode, barang.stok);
        
        std::cout << "\n";
        
        running = input.inputOtherMenu(user, "Input Salah, Hanya Diperbolehkan Angka!");
    
    }

    Console::clear_screen();
    view.menampilkanMenu();
    view.textOpsiMenu();
}