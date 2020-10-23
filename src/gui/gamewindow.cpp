#include "gamewindow.h"
#include <iostream>

GameWindow::GameWindow(int width, int height, int mineNumber):
    m_buttons(QVector<Square*>()),
    m_game(new Game(width, height, mineNumber))
{
    setFixedSize(30*width,30*height);

    initializeAttributes(width, height);

    initializeLayout();
}

GameWindow::~GameWindow()
{
    for (Square* s: m_buttons)
    {
        delete s;
    }
}

void GameWindow::squareClicked(int i, int j)
{
    if (m_game->finished())
        return;

    if (!m_game->started())
    {
        m_game->startGame(i, j);
    }

    m_game->discover(i,j);

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

void GameWindow::initializeAttributes(int width, int height)
{
    m_gameWidth = width;
    m_gameHeight = height;
}

void GameWindow::initializeLayout()
{
    m_gameLayout = new QGridLayout();

    for (int i=0; i<m_gameHeight; i++)
        for (int j=0; j<m_gameWidth; j++){
            Square* button = new Square(i, j, "-");
            m_buttons.push_back(button);
            m_gameLayout->addWidget(button->button(), i, j);

            connect(button, &Square::clicked, this, &GameWindow::squareClicked);
        }

    this->setLayout(m_gameLayout);
}

void GameWindow::repaintGame()
{
    for (int i=0; i<m_gameHeight; i++)
        for (int j=0; j<m_gameWidth; j++)
        {
            int index = i*m_gameWidth+j;
            QPushButton* button = m_buttons[index]->button();
            button->setText(m_game->textToPrint(i, j));
            button->repaint();
        }
}
