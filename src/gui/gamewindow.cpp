#include "gamewindow.h"
#include <iostream>
#include <QFrame>
#include <QSpacerItem>

GameWindow::GameWindow(int width, int height, int mineNumber):
    m_gameWidth(width),
    m_gameHeight(height),
    m_restartButton(new QPushButton("Start new game")),
    m_returnButton(new QPushButton("Return to menu")),
    m_buttons(QVector<SquareWidget*>()),
    m_game(new Game(width, height, mineNumber))
{
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

QPushButton *GameWindow::restartButton() const
{
    return m_restartButton;
}

QPushButton *GameWindow::returnButton() const
{
    return m_returnButton;
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
    QSpacerItem* verticalSpacer1(new QSpacerItem(100,100, QSizePolicy::Minimum, QSizePolicy::Expanding));
    QSpacerItem* verticalSpacer2(new QSpacerItem(100,100, QSizePolicy::Minimum, QSizePolicy::Expanding));
    QSpacerItem* horizontalSpacer1(new QSpacerItem(100,100, QSizePolicy::Expanding, QSizePolicy::Minimum));
    QSpacerItem* horizontalSpacer2(new QSpacerItem(100,100, QSizePolicy::Expanding, QSizePolicy::Minimum));

    QVBoxLayout* mainLayout(new QVBoxLayout(this));
    m_cellLayout = new QGridLayout(this);

    for (int i=0; i<m_gameHeight; i++)
        for (int j=0; j<m_gameWidth; j++)
        {
            SquareWidget* button = new SquareWidget(i, j);
            m_buttons.push_back(button);

            m_cellLayout->addWidget(button->button(), i, j);

            connect(button, &SquareWidget::leftClicked, this, &GameWindow::squareLeftClicked);
            connect(button, &SquareWidget::rightClicked, this, &GameWindow::squareRightClicked);
        }

    QHBoxLayout* fieldLayout(new QHBoxLayout(this));
    fieldLayout->addSpacerItem(horizontalSpacer1);
    fieldLayout->addLayout(m_cellLayout);
    fieldLayout->addSpacerItem(horizontalSpacer2);

    mainLayout->addSpacerItem(verticalSpacer1);
    mainLayout->addLayout(fieldLayout);
    QFrame *horizontalLine = new QFrame(this);
    horizontalLine->setFrameShape(QFrame::HLine);
    horizontalLine->setFixedHeight(5);
    mainLayout->addSpacerItem(verticalSpacer2);

    mainLayout->addWidget(horizontalLine);
    mainLayout->addWidget(m_restartButton);
    mainLayout->addWidget(m_returnButton);

    this->setLayout(mainLayout);
}

void GameWindow::repaintGame()
{
    for (int i=0; i<m_gameHeight; i++)
        for (int j=0; j<m_gameWidth; j++)
        {
            QString styleSheet;
            CellButton* cellButton = squareWidget(i,j)->button();
            QString text(cellButton->textToPrint(m_game->cell(i,j), styleSheet));
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
        disableAllCells();
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

void GameWindow::disableAllCells()
{
    for (int i=0; i<m_gameHeight; i++)
        for (int j=0; j<m_gameWidth; j++)
        {
            squareWidget(i,j)->disable();
        }
}

void GameWindow::squareRightClicked(int i, int j)
{
    bool cellFlagged = m_game->flag(i,j);
    squareWidget(i,j)->setIsClickable(!cellFlagged);
    repaintGame();
}
