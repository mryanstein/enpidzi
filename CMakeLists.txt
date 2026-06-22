cmake_minimum_required(VERSION 3.15)
project(enpidzi)

# Wymagamy standardu C++17 (potrzebny do nowszych mechanizmów)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Dodajemy katalog 'inc', aby kompilator widział plik Student.hpp
include_directories(inc)

# Automatycznie zbieramy wszystkie pliki źródłowe z głównego folderu oraz z 'src'
file(GLOB_RECURSE SOURCES "*.cpp" "src/*.cpp")

# Tworzymy plik wykonywalny o nazwie "Program" z zebranych źródeł
add_executable(Program ${SOURCES})