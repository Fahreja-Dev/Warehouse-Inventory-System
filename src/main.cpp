#include <iostream>
#include <string>
#include "menu/Menu.hpp"
#include "menu/MenuView.hpp"
#include "menu/MenuLogic.hpp"
#include "utils/Color.hpp"
#include "utils/Validator.hpp"
#include "input/Input.hpp"

int main() {
    Menu menu;
    MenuView view;
    MenuLogic logic;
    Validator validator;
    Input input;
    std::string user;
    bool running = true;

    view.menampilkanMenu();
    view.textOpsiMenu();
    
    while(running) {
        try {
            std::cin >> user;
            if(!validator.isNumber(user)){
                std::cout << Color::RED << "Input Tidak Valid, Masukkan Angka!" << Color::DEFAULT << std::endl;
                view.textOpsiMenu();
                continue;
            }
            int pilihan = std::stoi(user);
            menu.prosesPilihan(pilihan, running, logic);
        } catch (const std::exception& e){
            std::cout << "Terjadi Kesalahan: " << e.what() << std::endl;
        }
    }
}