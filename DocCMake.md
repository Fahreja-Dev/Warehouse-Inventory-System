# Documentation CMake
## Mengatur Versi dan Nama Project
```cmake
cmake_minimum_required(VERSION 3.15)
project(AplikasiGudang VERSION 1.0.0 LANGUAGES CXX)
```

- Mendefinisikan **nama project** -> `AplikasiGudang`.
- Memberikan **versi project** -> `1.0.0`.
- Menentukan **bahasa yang dipakai** -> `CXX` (C++).

## Mengatur Standar C++

```cmake
set(CMAKE_CXX_STANDARD 17)
```

- Meminta compiler menggunakan **C++17** sebagai standar bahasa.
- Jadi fitur-fitur C++17 (structured bindings, `std::optional`, dll) bisa dipakai. 

```cmake
set(CMAKE_CXX_STANDARD_REQUIRED ON)
```
- Menandakan bahwa standar yang diminta **wajib** dipakai.
- Kalau compiler tidak mendukung C++17, build akan gagal.
- Jika fitur ini tidak di aktifkan, compiler bisa jatuh ke versi lebih rendah (misalnya C++14).

```cmake
set(CMAKE_CXX_EXTENSIONS OFF)
```

- Mematikan **compiler extensions** (fitur non-standar seperti `-std=gnu++17` di GCC/Clang).
- Dengan OFF, CMake akan pakai mode standar murni `-std=c++17`, bukan GNU++17.
- Tujuannya: menjaga kode tetap portable dan sesuai standar resmi.

## Mencari File Dengan Pola Tertentu

```cmake
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
```

- `file(GLOB_RECURSE ...)` -> Perintah CMake untuk mencari file dengan pola tertentu.
- `SOURCES` -> Nama variabel yang akan menyimpan daftar file hasil pencarian.
- `"${PROJECT_SOURCE_DIR}/src/*.cpp"` -> Pola pencarian: semua file dengan ekstensi `.cpp` di folder `src` (dan subfoldernya, karena ada `RECURSE`).

contoh lainnya:
```cmake
file(GLOB_RECURSE HEADERS 
    "${PROJECT_SOURCE_DIR}/include/*.hpp"
    "${PROJECT_SOURCE_DIR}/include/*.h"
)
```

```cmake
file(GLOB_RECURSE LIBRARIES
"${PROJECT_SOURCE_DIR}/lib/*.hpp"
"${PROJECT_SOURCE_DIR}/lib/*.h"
)
```

Jadi, tujuan nya adalah untuk mempermudah dalam menggunakan library atau menghubungkan file `.cpp` atau `.hpp` yang kita gunakan.

Contoh:

```text
src/
 ├─ main.cpp
 ├─ utils/
 │   └─ Mapper.cpp
include/
 ├─ utils/
 │   └─ Mapper.hpp
```

contoh penggunakan library:

```cpp
#include "utils/Mapper.hpp"
```

## Pengambilan Library External

```cmake
include(FetchContent)
```

Mengaktifkan modul FetchContent, yang bertujuan mengambil dan build library external

```cmake
FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG        e69e5f977d458f2650bb346dadf2ad30c5320281)
```

- `fmt` -> Nama paket/depedency yang kita deklarasikan.
- `GIT_REPOSITORY` -> URL repo Git yang berisi source code library (disini: `fmtlib/fmt`).
- `GIT_TAG` -> Commit hash atau tag versi tertentu yang ingin kita ambil.
    - Contoh: bisa berupa `10.2.1` (versi release) atau hash commit spesifik.

```cmake
FetchContent_MakeAvailable(fmt)
``` 
- `fmt` -> Berasal dari **nama paket** yang kita deklarasikan di `FetchContent_Declare`.
- `FetchContent_MakeAvailable(fmt)` -> Mengambil deklarasi `fmt`, download dari repo, build, dan expose target `fmt::fmt`
- `fmt::fmt` -> Target resmi yang disediakan oleh library setelah berhasil di build, dan siap pakai di `target_link_libraries`.

## Memberitahu Compiler Tempat Mencari File

```cmake
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/lib
)
```

- `include_directories(...)` -> Memberi tahu compiler dimana harus mencari file header (`.h` atau `.hpp`).
- `${PROJECT_SOURCE_DIR}/include` -> Folder `include` di root project, biasanya berisi header publik.
- `${PROJECT_SOURCE_DIR}/lib` -> Folder `lib` di root project, bisa berisi header/library tambahan.

Contoh: 
```cpp
#include "Gudang.hpp"
#include "Validator.h"
```
Compiler akan tahu mencari di folder `include/` atau `lib/`.

## Membuat Executable dari File Sumber

```cmake
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
```

- `add_executable` -> Untuk membuat target program executable.
- `${PROJECT_NAME}` -> Variabel otomatis yang berisi nama project, yang didefinisi dari `project(...)`. Jadi nama file yang dihasilkan sesuai dengan nama project.
- `${SOURCES}` -> Kumpulan file `.cpp` yang berisi implementasi program.
- `${HEADERS}` -> Kumpulan file `.hpp` atau `.h` yang telah kita tambahkan agar IDE/CMake tahu mereka bagian dari project.

```cmake
target_link_libraries(AplikasiGudang PRIVATE fmt::fmt)
```
- `AplikasiGudang` -> Target executable yang kita definisikan dengan `add_excutable(AplikasiGudang ...)`.
- `fmt::fmt` -> Target library resmi dari fmt (library format string, float, boolean, integer, dan lain-lain)
- `PRIVATE` -> `Scope visibility` Maksudnya, hanya AplikasiGudang sendiri yang butuh `fmt`. Depedensi tersebut tidak diwariskan ke target lain yang mungkin bergantung pada AplikasiGudang

```cmake
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}
)
```

- `set_target_properties` -> Mengubah properti dari target tertentu (disini: `${PROJECT_NAME}`).
- `RUNTIME_OUTPUT_DIRECTORY` -> Menentukan folder tempat file executable (runtime binary) akan diletakkan.
- `RUNTIME_OUTPUT_DIRECTORY_DEBUG` -> Khusus untuk build konfigurasi **Debug**.
- `RUNTIME_OUTPUT_DIRECTORY_RELEASE` -> Khusus untuk build konfigurasi **Release**.
- `${PROJECT_SOURCE_DIR}` -> Path root project (folder tempat `CMakeLists.txt` utama berada).

Contoh lainnya:

```cmake
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
)
```

Jika kita tidak mau mengatur nya, cukup seperti ini saja. Karena sudah otomatis berlaku untuk semua konfigurasi seperti (Debug, Release, dll).