#include "MineSweeperBoard.h"


/*********************************************************************************************/
/*                PIERWSZY KONSTUKTOR - TWORZY PLANSZE 10X10                                 */
/*********************************************************************************************/
MinesweeperBoard ::MinesweeperBoard() {

    width = 10;
    height = 10;
    board.resize(height);
    for(std::vector<std::vector<Field>>::size_type i = 0; i < board.size(); i++) {
        board[i].resize(width);
    }

    clearBoard();

    board[0][0].hasMine = true;
    board[1][1].isRevealed = true;
    board[0][2].hasMine = true;
    board[0][2].hasFlag = true;

    state = RUNNING;
    countmoves = 0;

}

/***********************************************************************************************/
/*                       DRUGI KONTRUKTOR - PRZYJMUJE TRZY ARGUMENTY                           */
/***********************************************************************************************/
MinesweeperBoard::MinesweeperBoard(int newWidth, int newHeight, GameMode mode) {
    width = newWidth;
    height = newHeight;
    if(width<0 || height < 0) {
        std::cout << "Plansza nie może mieć ujemnej szerokosci ani dlugosci" << std::endl;
    }
    board.resize(height);
    for (std::vector<std::vector<Field>>::size_type i = 0; i < board.size(); i++) {
        board[i].resize(width);
    }

    clearBoard();

    int number = 0;
    switch(mode)
    {
        case EASY:
        number = chooseMineCount(10);
        randMines(number);
        break;
        case NORMAL:
        number = chooseMineCount(20);
        randMines(number);
        break;
        case HARD:
        number = chooseMineCount(30);
        randMines(number);
        break;
        case DEBUG:
            for(int i = 0; i < width; i++) {
                board[0][i].hasMine = true;
            }
            for(int j = 0; j < width && j < height; j++) {
                board[j][j].hasMine = true;
            }
            for(int k = 0; k < height; k+=2) {
                board[k][0].hasMine = true;
            }
        break;
        default: 
        std::cout << "Bledne wybranie trybu" <<  std::endl;
        exit(1);    
    }

    state = RUNNING;
    countmoves = 0;
}
/**************************************************************************/
/*              FUNKCJA CZYSZCZACA PLANSZE                                */
/**************************************************************************/

void MinesweeperBoard::clearBoard() {
    for(int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            board[row][col].hasMine = false;
            board[row][col].isRevealed = false;
            board[row][col].hasFlag = false;
        }
    }
}

/****************************************************************************/
/*          FUNKCJA DO SPRAWDZANIA CZY JESTESMY POZA PLANSZA                */
/****************************************************************************/
bool MinesweeperBoard::insideTheBoard(int row, int col) const {
    if (row < height && col < width && row >= 0 && col >= 0)
        return true;
    else
        return false;
}
/*****************************************************************************/
/*        WYBOR LICZBY MIN W ZALEZNOSCI OD TRYBU I ROZMIARU TABLICY          */
/*****************************************************************************/
int MinesweeperBoard::chooseMineCount(int percentage) {
     int number = width * height * percentage / 100;
          if(width*height*percentage%100!=0)
            number++;
    return number;
}
/*************************************************************************/
/*               FUNKCJA POMOCNICZA DO KONSTRUKTORA                      */
/*************************************************************************/
void MinesweeperBoard::randMines(int number) {
    while(number > 0) {
        int columns = rand() % width;
        int rows = rand() % height;
        if(!board[rows][columns].hasMine) {
            board[rows][columns].hasMine = true;
            number--;
        }
    }
}
/***************************************************************************/
/*           PODSTAWOWE FUNKCJE DO GRY                                     */
/***************************************************************************/
int MinesweeperBoard::getBoardWidth() const {
    return width;
}

int MinesweeperBoard::getBoardHeight() const {
    return height;
}

 int MinesweeperBoard::getMineCount() const {
    int number = 0;
    for(int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if(board[row][col].hasMine)
            number++;
        }
    }

    return number;
 }

/**************************************************************************************/
/*                        FUNKCJA DO ZLICZANIA MIN WOKOL DANEGO POLA                  */
/**************************************************************************************/
int MinesweeperBoard::countMines(int row, int col) const {
    
    int numberOfMines = 0;
 
    if(!(insideTheBoard(row, col))) {
        return -1;
    }

    if(!board[row][col].isRevealed) {
        return -1;
    }

    for (int i = -1; i<2; i++) {
        for(int j = -1; j<2; j++)  {
            if(insideTheBoard(row + i, col + j)) {
            if(board[row + i][col + j].hasMine)
            numberOfMines++;
            }

        }
    }
    
    return numberOfMines;
}
 /***********************************************************************/
 /*         FUNKCJA SPRAWDZAJACA CZY DANE POLE MA FLAGE                 */
 /***********************************************************************/
 bool MinesweeperBoard::hasFlag(int row, int col) const {
    if(row >= height || col >=width || row < 0 || col < 0) {
        return false;
    }
    if(board[row][col].isRevealed) {
        return false;
    }
    if(!board[row][col].hasFlag)
        return false;
    else 
        return true;
 }  

/*******************************************************************************/
/*              FUNKCJA ZMMIENIAJACA STATUS FLAGI DLA POLA                     */
/*******************************************************************************/
 void MinesweeperBoard::toggleFlag(int row, int col) {

    if(!(insideTheBoard(row, col))) {
        return;
    }
    if(board[row][col].isRevealed) {
        return;
    }
    if(getGameState()!= RUNNING) {
        return;
    }
    
    board[row][col].hasFlag = !board[row][col].hasFlag;
}
/*********************************************************************************/
/*                  FUNKCJA ODKRYWAJACA POLA Z TABLICY                           */
/*********************************************************************************/
void MinesweeperBoard::revealField(int row, int col) {
     if (!(insideTheBoard(row, col)))
         return;

     if (board[row][col].isRevealed)
         return;

     if (state!= RUNNING)
         return;

     if (board[row][col].hasFlag) 
         return;


    if(countmoves == 0 and board[row][col].hasMine) {
        int newRow = 0;
        int newCol = 0;
        do {
            newRow = rand() % height;
            newCol = rand() % width;
        }  while (board[newRow][newCol].hasMine);

        board[newRow][newCol].hasMine = true;   
        board[row][col].hasMine = false;
        }

    board[row][col].isRevealed = true;
    state = getGameState();
    countmoves++;

    if(countMines(row, col) == 0) {
        for (int i = -1; i<2; i++) {
        for(int j = -1; j<2; j++)  {
            if(insideTheBoard(row + i, col + j)) {
            revealField(row + i, col + j);
            }
        }
        }
    }
    
     
 } 

 /*********************************************************************************/
 /*              FUNKCJA SPRAWDZAJACA CZY DANE PLE JEST ODKRYTE                   */
 /*********************************************************************************/
 bool MinesweeperBoard::isRevealed(int row, int col) {
    if (!(row < height || col < width || row >= 0 || col >= 0))
         return false;
    if (board[row][col].isRevealed)
        return true;
    else 
        return false;
 }

 /************************************************************************************/
 /*         FUNKCJA PRZYDA SIE DO WYSWIETLANIA PLANSZY DLA GRACZA                    */
 /************************************************************************************/
 char MinesweeperBoard::getFieldInfo(int row, int col) {
    if (!(insideTheBoard(row, col)))
        return '#';
    else if(!board[row][col].isRevealed && board[row][col].hasFlag)
        return 'F';
    else if(!board[row][col].isRevealed && !board[row][col].hasFlag)
        return '_';
    else if(board[row][col].isRevealed && board[row][col].hasMine)
        return 'X';
    else if(board[row][col].isRevealed && countMines(row, col) == 0)
        return ' ';
    else
        return (countMines(row,col))+'0';
    
 }
/***************************************************************************************/
/*                         FUNKCJA DO OKRESLENIA STANU GRY                             */
/***************************************************************************************/
GameState MinesweeperBoard::getGameState() const {
    int winningnumber = 0, losingnumber = 0;
    for(int row = 0; row < height; row++) {
     for (int col = 0; col < width; col++) {
        if((board[row][col].isRevealed && !board[row][col].hasMine) || (!board[row][col].isRevealed && board[row][col].hasMine)) {
            winningnumber++;
        }
        else if(board[row][col].isRevealed && board[row][col].hasMine) {
            losingnumber++;
        }
    }
    }

    if(winningnumber == height*width) {
    return FINISHED_WIN;
    }
    else if(losingnumber >= 1) {
    return FINISHED_LOSS;
    }
    else {
    return RUNNING;
    }
}
/***************************************************************************************/
/*          FUNKCJA DO WYSWIETLANIA AKTUALNEGO STANU PLANSZY                           */
/***************************************************************************************/
void MinesweeperBoard::debug_display() const {
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            std::cout << "[";
            std::cout << (board[row][col].hasMine ? "M" : ".");
            std::cout << (board[row][col].isRevealed ? "o" : ".");
            std::cout << (board[row][col].hasFlag ? "f" : ".");
            std::cout << "]";
        }
        std::cout << std::endl;
    }
}
