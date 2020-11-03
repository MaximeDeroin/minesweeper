#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <vector>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>

#include <iostream>

#include "squarewidget.h"

#include "../data/game.h"
#include "../data/cell.h"

class GameWindow : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief GameWindow create a game with the parameters in argument
     * @param width width of the game grid
     * @param height height of the game grid
     * @param mineNumber number of mines in the grid
     * @warning requires that the number of mine is compatible, there must be at least 1 mine and
     * one empty square in the grid (width*height < mineNumber
     */
    explicit GameWindow(int width, int height, int mineNumber);

    virtual ~GameWindow();

signals:

public slots:

private:
    int m_gameWidth;
    int m_gameHeight;
    int m_gameMineNumber;

    /**
     * @brief stores the game buttons in a 1D vector.
     * In the buttons array, the element in position (x,y) will be in position
     * x*m_gameWidth+y in the vector
     * @note indices go from 0 to m_gameWidth*m_gameHeight - 1 after the
     * vector is initialized
     */
    QVector<SquareWidget*> m_buttons;

    QGridLayout* m_gameLayout;

    Game* m_game;

    void initializeAttributes(int width, int height);
    void initializeLayout();

    void placeMines(int width, int height);

    void computeAdjacentMineNumbers();
    int computeAdjacentMines(int i, int j);

    QString getButtonText(int i, int j) const;
    void setButtonText(int i, int j, int mineNumber);
    void setButtonText(int i, int j, QString text);

    void setNeighborNumber(int i, int j, int neighborNumber);
    int getNeighborNumber(int i, int j);
    void discover(int i, int j);


    void paintInitialGame();
    void repaintGame();

    bool hasMine(int i, int j) const;

    bool isInBoard(int i, int j) const;

private slots:
    void squareLeftClicked(int width, int height);
    void squareRightClicked(int width, int height);

private:
    SquareWidget* squareWidget(int i, int j);

};

#endif // GAMEWINDOW_H
