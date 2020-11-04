#include "gamewindow.h"
#include <iostream>

GameWindow::GameWindow(int width, int height, int mineNumber):
    m_gameWidth(width),
    m_gameHeight(height),
    m_buttons(QVector<SquareWidget*>()),
    m_game(new Game(width, height, mineNumber))
{
    setFixedSize(30+30*width,30+30*height);
    this->setWindowIcon(QIcon(":/img/mine.png"));

    initializeLayout();
}

GameWindow::~GameWindow()
{
    for (SquareWidget* s: m_buttons)
    {
        delete s;
    }
}

SquareWidget* GameWindow::squareWidget(int i, int j)
{
    int index = i*m_gameWidth+j;
    if (index >= 0 && index < m_gameWidth*m_gameHeight)
    {
        return m_buttons[index];
    }
    else
    {
        return nullptr;
    }
}

void GameWindow::initializeLayout()
{
    m_gameLayout = new QGridLayout();

    for (int i=0; i<m_gameHeight; i++)
        for (int j=0; j<m_gameWidth; j++)
        {
            SquareWidget* button = new SquareWidget(i, j);
            m_buttons.push_back(button);

            m_gameLayout->addWidget(button->button(), i, j);

            connect(button, &SquareWidget::leftClicked, this, &GameWindow::squareLeftClicked);
            connect(button, &SquareWidget::rightClicked, this, &GameWindow::squareRightClicked);
        }

    this->setLayout(m_gameLayout);
}

void GameWindow::repaintGame()
{
    for (int i=0; i<m_gameHeight; i++)
        for (int j=0; j<m_gameWidth; j++)
        {
            QString styleSheet;
            QString text(m_game->textToPrint(i, j, styleSheet));
            bool celltoDisable(m_game->cellIsDiscovered(i, j));
            squareWidget(i,j)->button()->repaintButton(text, styleSheet, celltoDisable);
        }
}

void GameWindow::squareLeftClicked(int i, int j)
{
    if (m_game->finished())
    {
        return;
    }

    if (!m_game->started())
    {
        m_game->startGame(i, j);
    }

    bool gameEnds = m_game->discover(i,j);
    if (gameEnds)
    {
        for (int i=0; i<m_gameHeight; i++)
            for (int j=0; j<m_gameWidth; j++)
            {
                squareWidget(i,j)->disable();
            }
    }

    if(m_game->gameState() == Game::GameState::LOST)
    {
        QMessageBox::information(this, "Mine!", "You lost the game...");

    }
    else if (m_game->gameState() == Game::GameState::WON)
    {
        QMessageBox::information(this, "Victory", "You won the game!");
    }

    repaintGame();
}

void GameWindow::squareRightClicked(int i, int j)
{
    bool cellFlagged = m_game->flag(i,j);
    squareWidget(i,j)->setIsClickable(!cellFlagged);
    repaintGame();
}
