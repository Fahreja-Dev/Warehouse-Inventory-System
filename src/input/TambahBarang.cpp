#include <iostream>
#include "input/TambahBarang.hpp"
#include "inventory/Gudang.hpp"
#include "menu/Menu.hpp"
#include "menu/MenuView.hpp"
#include "utils/Validator.hpp"
#include "input/Input.hpp"
#include "utils/Console.hpp"

void TambahBarang::tambahBarang() {
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
        barang.nama = input.inputString("Masukkan Nama Barang: ");
        barang.harga = input.inputInteger("Masukkan Harga Barang: ");
        barang.stok = input.inputInteger("Masukkan Stok Barang: ");
        
        gudang.tambahBarang(barang);
        
        std::cout << "\n";
        
        running = input.inputOtherMenu(user, "Input Salah, Hanya Diperbolehkan Angka!");
    
    }

    Console::clear_screen();
    view.menampilkanMenu();
    view.textOpsiMenu();
}