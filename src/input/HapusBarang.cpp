#include <iostream>
#include "input/HapusBarang.hpp"
#include "inventory/Gudang.hpp"
#include "menu/MenuView.hpp"
#include "input/Input.hpp"
#include "utils/Console.hpp"

void HapusBarang::hapusBarang() {
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
        
        gudang.hapusBarang("data/barang.json", barang.kode);
        
        std::cout << "\n";
        
        running = input.inputOtherMenu(user, "Input Salah, Hanya Diperbolehkan Angka!");
    
    }

    Console::clear_screen();
    view.menampilkanMenu();
    view.textOpsiMenu();
}