#include "menu/Menu.hpp"
#include "menu/MenuLogic.hpp"
#include "menu/MenuView.hpp"
#include "utils/Color.hpp"

void MenuLogic::pilihMenu(int pilihan, bool &running){
    MenuView view;

    switch(pilihan){
        case MenuOption::EXIT : {
            running = false;
        }
        break;

        case MenuOption::TAMPILKAN_BARANG : {
            Menu menu;
            menu.tampilkanSemuaBarang();
        }
        break;
        
        case MenuOption::TAMBAH_BARANG : {
            Menu menu;
            menu.tambahBarang();
        }
        break;

        case MenuOption::CARI_BARANG : {
            std::cout << Color::YELLOW;
            std::cout << "Fitur Cari Barang belum tersedia." << std::endl;
            std::cout << Color::DEFAULT;
            view.textOpsiMenu();
        }
        break;

        case MenuOption::UPDATE_BARANG : {
            Menu menu;
            menu.updateBarang();
        }
        break;

        case MenuOption::HAPUS_BARANG : {
            Menu menu;
            menu.hapusBarang();
        }
        break;

        default:
        std::cout << Color::RED;
        std::cout << "Pilihan tidak valid!" << std::endl;
        std::cout << Color::DEFAULT;
        view.textOpsiMenu();
        break;
    }
    
}

void MenuLogic::handleError(int pilihan){
    std::cerr << "Terjadi error pada pilihan: " << pilihan << std::endl;
}