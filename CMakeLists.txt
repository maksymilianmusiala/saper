cmake_minimum_required(VERSION 3.10)
project(SAPER)

# Ustawienie standardu C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dodanie pliku wykonywalnego i wskazanie pliku w folderze src
add_executable(SAPER src/main.cpp
                    src/MinesweeperBoard.cpp
                    src/MSBoardTextView.cpp)

# Wskazanie folderu z plikami nagłówkowymi (.h / .hpp), 
# aby kompilator wiedział, gdzie ich szukać przy instrukcji #include
target_include_directories(SAPER PRIVATE include)