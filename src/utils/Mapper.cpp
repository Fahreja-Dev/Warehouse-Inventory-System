#include <fstream>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include "utils/Mapper.hpp"
#include "utils/TextHelper.hpp"
#include "../../lib/struct_mapping/include/struct_mapping/struct_mapping.h"

struct BarangWrapper{
    std::vector<Barang> barang;
};

void Mapper::registerBarangMapping(){
    /*
    Barang::kode → dipakai saat registrasi mapping (butuh alamat field di class).
    this->kode → dipakai saat method objek berjalan (butuh nilai field dari objek).
        
    Jadi Tujuan nya penggunaan ( Barang::kode ) untuk mengakses field milik ( struct ) pada ( Barang ) secara langsung, sedangkan ( this->kode ) digunakan untuk mengakses nilai field dari instance ( objek ) yang sedang berjalan.
    */
    struct_mapping::reg(&Barang::kode, "kode");
    struct_mapping::reg(&Barang::nama, "nama");
    struct_mapping::reg(&Barang::harga, "harga");
    struct_mapping::reg(&Barang::stok, "stok");
    // Registrasi untuk vector barang.
    struct_mapping::reg(&BarangWrapper::barang, "barang");
}

std::vector<Barang> Mapper::loadBarang(const std::string& path){
    BarangWrapper wrapper;
    // std::ifstream ifs(path) adalah bertujuan untuk baca data yang sudah ada di file JSON.
    std::ifstream ifs(path);
    if(ifs.good() && ifs.peek() != std::ifstream::traits_type::eof()){
        struct_mapping::map_json_to_struct(wrapper, ifs);
        return wrapper.barang;
    }
    return {};
}

void Mapper::saveBarang(const std::string& path, const std::vector<Barang>& data){
    // BarangWrapper wrapper{data} adalah bertujuan untuk copy data ke wrapper saat objek dibuat lewat konstruktor, untuk disimpan.
    BarangWrapper wrapper{data};
    std::ofstream ofs(path);
    struct_mapping::map_struct_to_json(wrapper, ofs, " ");
}

void Mapper::updateStokBarang(const std::string& path, const std::string& kodeBarang, int stokBaru){
    auto barangList = loadBarang(path);

    for(auto &b: barangList){
        if(b.kode == kodeBarang){
            b.stok = stokBaru;
        }
    }

    saveBarang(path, barangList);
}

void Mapper::hapusBarang(const std::string& path, const std::string& kodeBarang){
    auto barangList = loadBarang(path);

    barangList.erase(
        std::remove_if(barangList.begin(), barangList.end(), [&](const Barang& b){
            return b.kode == kodeBarang;
        }),
        barangList.end()
    );

    saveBarang(path, barangList);
}

std::vector<Barang> Mapper::cariBarang(const std::string& path, const std::string& keyword){
    auto barangList = loadBarang(path);
    std::vector<Barang> hasil;

    std::string keywordLower = TextHelper::toLower(keyword);

    for(const auto& b : barangList){
        std::string kodeLower = TextHelper::toLower(b.kode);
        std::string namaLower = TextHelper::toLower(b.nama);

        if(kodeLower.find(keywordLower) != std::string::npos || namaLower.find(keywordLower) != std::string::npos){
            hasil.push_back(b);
        }
    }

    return hasil;
}