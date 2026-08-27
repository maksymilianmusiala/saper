#ifndef SAPER_MSBOARDTEXTVIEW_H
#define SAPER_MSBOARDTEXTVIEW_H

#include "MineSweeperBoard.h"


class MSBoardTextView {
    MinesweeperBoard &newBoard;
 public:
    MSBoardTextView(MinesweeperBoard &board) : newBoard(board) {}
    void display();
};


#endif //SAPER_MSBOARDTEXTVIEW_H