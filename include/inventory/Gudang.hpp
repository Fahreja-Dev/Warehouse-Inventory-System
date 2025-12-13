#pragma once
#include <vector>
#include "Barang.hpp"

struct Gudang: Barang{
    private:
    std::vector<Barang> data;

    public:
    void getSemuaBarang() const;
    void tambahBarang(Barang& brg);
    void updateStokBarang(const std::string& path, const std::string& kodeBarang, int stokBaru);
    void hapusBarang(const std::string& path, const std::string& kodeBarang);
    void cariBarang(const std::string& path, const std::string& keyword);
};