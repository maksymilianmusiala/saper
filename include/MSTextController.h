#ifndef MSTEXTCONTROLLER_H
#define MSTEXTCONTROLLER_H

#include "MineSweeperBoard.h"
#include "MSBoardTextView.h" 

class MSTextController {
private:
    MinesweeperBoard& board;
    MSBoardTextView& view;

public:
    MSTextController(MinesweeperBoard& board, MSBoardTextView& view) : board(board), view(view) {}
    void play();
};

#endif // MSTEXTCONTROLLER_H