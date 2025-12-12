#include "menu/Menu.hpp"
#include "menu/MenuLogic.hpp"
#include "menu/MenuView.hpp"
#include "utils/Color.hpp"

void MenuLogic::pilihMenu(int pilihan, bool &running){
    MenuView view;

    switch(pilihan){
        case 0: {
            running = false;
        }
        break;

        case 1: {
            Menu menu;
            menu.tampilkanSemuaBarang();
        }
        break;
        
        case 2: {
            Menu menu;
            menu.tambahBarang();
        }
        break;

        case 3: {
            std::cout << Color::YELLOW;
            std::cout << "Fitur Cari Barang belum tersedia." << std::endl;
            std::cout << Color::DEFAULT;
            view.textOpsiMenu();
        }
        break;

        case 4: {
            Menu menu;
            menu.updateBarang();
        }
        break;

        case 5: {
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