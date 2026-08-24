#ifndef MINESWEEPERBOARD_H
#define MINESWEEPERBOARD_H
#include <vector>
#include <iostream>
#include <cstdlib> // zawiera funkcje rand() i srand()
#include <ctime>

enum GameMode { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};

class MinesweeperBoard
{
    std::vector<std::vector<Field>> board;

    int width;                // rzeczywista szerokość planszy
    int height;               // rzeczywista wysokość planszy
    int countmoves = 0;
    GameState state;
public:
    

    MinesweeperBoard();
    MinesweeperBoard(int width, int height, GameMode mode);
    void clearBoard();
    bool insideTheBoard(int row, int col) const;
    int chooseMineCount(int number);
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    int countMines(int row, int col) const;  
    bool hasFlag(int row, int col) const;
    void toggleFlag(int row, int col);
    void debug_display() const;
    void randMines(int percentage);
    bool isRevealed(int row, int col);
    void revealField(int row, int col);
    GameState getGameState() const;
    char getFieldInfo(int row, int col);
};



#endif // MINESWEEPERBOARD_H