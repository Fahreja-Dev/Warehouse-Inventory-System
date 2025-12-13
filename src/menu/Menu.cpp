#include "menu/Menu.hpp"
#include "menu/MenuView.hpp"
#include "menu/MenuLogic.hpp"
#include "inventory/Gudang.hpp"
#include "input/TambahBarang.hpp"
#include "input/UpdateBarang.hpp"
#include "input/HapusBarang.hpp"
#include "input/CariBarang.hpp"

void Menu::prosesPilihan(int pilihan, bool &running, MenuLogic& logic){
    logic.pilihMenu(pilihan, running);
}

void Menu::tampilkanSemuaBarang(){
    Gudang gudang;
    gudang.getSemuaBarang();
}

void Menu::tambahBarang(){
    TambahBarang tambahBarang;
    tambahBarang.tambahBarang();
}

void Menu::updateBarang(){
    UpdateBarang updateBarang;

    updateBarang.updateBarang();
}

void Menu::hapusBarang(){
    HapusBarang hapusBarang;

    hapusBarang.hapusBarang();
}

void Menu::cariBarang(){
    CariBarang cariBarang;

    cariBarang.cariBarang();
}