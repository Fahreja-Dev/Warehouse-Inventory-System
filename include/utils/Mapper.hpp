#pragma once
#include <string>
#include "inventory/Gudang.hpp"

namespace Mapper{
    void registerBarangMapping();
    std::vector<Barang> loadBarang(const std::string& path);
    void saveBarang(const std::string& path, const std::vector<Barang>& data);
    void updateStokBarang(const std::string& path, const std::string& kodeBarang, int stokBaru);
    void hapusBarang(const std::string& path, const std::string& kodeBarang);
}