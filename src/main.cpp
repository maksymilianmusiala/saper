#include "MineSweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"

int main() {
    srand(time(nullptr));
    // int row, col;
    // GameMode mode;
    // std::cout << "Wprowadź wysokość i szerokość planszy, na ktorej chcesz grac:" << std::endl;
    // std::cout << "Wysokosc (z zakresu 0-100): ";
    // std::cin >> row;
    // std::cout << "Szerokosc (z zakresu 0-100): ";
    // std::cin >> col;
    // system("clear");

    MinesweeperBoard board(10, 10, GameMode::DEBUG);
    MSBoardTextView view(board);
    MSTextController ctrl(board, view);

    ctrl.play();

    return 0;
}