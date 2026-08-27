#include "MSBoardTextView.h"
/*****************************************************************************************/
/*            FUNKCJA DO WYŚWIETLANIA STANU GRY DLA GRACZA                               */
/*****************************************************************************************/


void MSBoardTextView::display() {
    for(int row = 0; row < newBoard.getBoardHeight(); row++) {
        for(int col = 0; col < newBoard.getBoardWidth(); col++) {
            std::cout << newBoard.getFieldInfo(row, col) << "\t";
        }
      std::cout << std::endl;
    }
}