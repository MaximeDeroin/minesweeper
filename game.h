#ifndef GAME_H
#define GAME_H

#include "cell.h"


#include <QVector>

class Game
{
public:
    explicit Game(int width, int height, int mineNumber);

    ~Game();

    enum class GameState
    {
        ONGOING = 0,
        WON = 1,
        LOST = 2
    };

///// getters //////////////////////
    bool started() const;
    bool finished() const;

    int width() const;
    int height() const;
    int mineNumber() const;
    GameState gameState() const;
////////////////////////////////////

    void startGame(int i, int j);

    void discover(int i, int j);

    QString textToPrint(int i, int j);

private:
    bool m_started;
    bool m_finished;

    int m_width;
    int m_height;
    int m_mineNumber;

    int m_undiscoveredSquares;
    GameState m_gameState;

    QVector<Cell*> m_cellGrid;

    void placeMines(int i, int j);
    void computeAdjacentMineNumbers();
    int computeAdjacentMines(int i, int j);
    void setAdjacentMinesNumber(int i, int j, int neighborNumber);


    bool hasMine(int i, int j) const;
    bool isInBoard(int i, int j) const;

    int getNeighborNumber(int i, int j);
    Cell *cell(int i, int j) const;
};

#endif // GAME_H
