// MSTextController.cpp
#include "MSTextController.h"
#include <iostream>

void MSTextController::play() {
    while (board.getGameState() == RUNNING) {
        board.debug_display();
    system("clear");
        view.display();
        int row, col;
        std::cout << "Enter row and column with space: ";
        std::cin >> row >> col;

        if (!(board.insideTheBoard(row, col))) {
            continue;
        }

        std::string todo;
        std::cout << "What do you what to do (reveal field/r,change flag status/f): ";
        std::cin >> todo;

        if (todo == "R" || todo == "r") {
            board.revealField(row, col);
        } else if (todo == "R" || todo == "r") {
            board.toggleFlag(row, col);
        }
    }
    system("clear");
    view.display();
    if (board.getGameState() == FINISHED_WIN) {
        std::cout << "WINNER" << std::endl;
    } else {
        std::cout << "LOSER" << std::endl;
    }
}