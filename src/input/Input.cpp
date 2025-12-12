#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <algorithm>
#include "input/Input.hpp"
#include "utils/Color.hpp"
#include "utils/Validator.hpp"
#include "menu/MenuView.hpp"
#include "utils/Console.hpp"

std::string Input::inputString(const std::string& text){
std::string value;

    while(true){
        std::cout << text;
        std::getline(std::cin, value);
        
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Membersihkan newline dari buffer setelah cin
            std::cout << Color::YELLOW << "Input Bermasalah, Silahkan Coba Lagi!" << Color::DEFAULT << std::endl;
        }else{
            return value;
        }
    }
}

int Input::inputInteger(const std::string& text){
    Validator validator;
    int number;
    std::string value;

    while(true){
        std::cout << text;
        std::cin >> value;

        if(validator.isNumber(value)){
            std::size_t size;
            number = std::stoi(value, &size);
            if(std::cin.fail() || number < 0){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << Color::YELLOW <<"Input Salah, Angka Tidak Boleh Minus!" << Color::DEFAULT << std::endl;
            }else{
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return number;
            }
        }else{
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << Color::RED <<"Input Salah, Harus Angka!" << Color::DEFAULT << std::endl;
        }
    }
}

double Input::inputDouble(const std::string& text){
    Validator validator;
    double number;
    std::string value;

    while (true){
        std::cout << text;
        std::cin >> value;

        if(validator.isDouble(value)){
            std::size_t size;
            std::replace(value.begin(), value.end(), ',', '.');
            number = std::stod(value, &size);
            if (std::cin.fail() || number < 0){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << Color::YELLOW <<"Input Salah, Angka Tidak Boleh Minus!" << Color::DEFAULT << std::endl;
            }else{
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return number;
            }
        }else{
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << Color::RED <<"Input Salah, Harus Angka!" << Color::DEFAULT << std::endl;
        }
    }
}

bool Input::inputOtherMenu(std::string& user, const std::string& text){
    Validator validator;
    MenuView view;
    
    while(true){
        view.textOpsiSelesai();
        std::cout << std::endl;
        view.textOpsiMenu();
        std::cin >> user;
        
        if(validator.isNumber(user)){
            try{
                
                int select = std::stoi(user);
                if (select == 0){
                    return false;
                }else if(select == 1){
                    return true;
                }else{
                    Console::clear_screen();
                    std::cout << Color::RED << "Silahkan Pilih Sesuai Menu!" << Color::DEFAULT << std::endl;
                }
            
            }catch(const std::exception& e){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                Console::clear_screen();
                std::cout << Color::RED << "System Error: " << e.what() << Color::DEFAULT << std::endl;
            }
        }else{
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Console::clear_screen();
            std::cout << Color::RED << text << Color::DEFAULT << std::endl;
        }
    }
}

bool Input::inputTableMenu(std::string& user, const std::string& text){
    Validator validator;
    MenuView view;
    
    while(true){
        view.textMenuTable();
        std::cout << std::endl;
        view.textOpsiMenu();
        std::cin >> user;
        
        if(validator.isNumber(user)){
            try{
                
                int select = std::stoi(user);
                if (select == 0){
                    return false;
                }else{
                    system("cls");
                    std::cout << Color::RED << "Silahkan Pilih Sesuai Menu!" << Color::DEFAULT << std::endl;
                }
            
            }catch(const std::exception& e){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                system("cls");
                std::cout << Color::RED << "System Error: " << e.what() << Color::DEFAULT << std::endl;
            }
        }else{
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("cls");
            std::cout << Color::RED << text << Color::DEFAULT << std::endl;
        }
    }
}