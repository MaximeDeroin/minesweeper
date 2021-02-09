#include "guimanager.h"

GuiManager::GuiManager():
    m_menuWindow(new MenuWindow()),
    m_currentGameWindow(nullptr),
    m_width(0),
    m_height(0),
    m_mineNumber(0)
{
    this->addWidget(m_menuWindow);
    setFixedSize(400,400);
    setWindowIcon(QIcon(QPixmap(":/img/mine.png")));

    connect(m_menuWindow, &MenuWindow::newGame, this, &GuiManager::newGameClicked);

    this->show();
}


GuiManager::~GuiManager()
{
    if (m_menuWindow)
    {
        delete m_menuWindow;
    }
    if (m_currentGameWindow)
    {
        delete m_currentGameWindow;
    }
}

void GuiManager::newGameClicked(int width, int height, int mineNumber)
{
    m_width = width;
    m_height = height;
    m_mineNumber = mineNumber;

    GameWindow *newGameWindow = new GameWindow(width, height, mineNumber);

    replaceGameWindow(newGameWindow);
    connectGameWindow(newGameWindow);

    this->setCurrentIndex(static_cast<int>(Page::GAME));
    this->setFixedSize(qMax(400, 30+30*width), qMax(400, 110+30*height));
}

void GuiManager::quitGameClicked()
{
    this->setCurrentIndex(static_cast<int>(Page::MENU));
    setFixedSize(400,400);
}

void GuiManager::restartGameClicked()
{
    this->newGameClicked(m_width, m_height, m_mineNumber);
}

void GuiManager::replaceGameWindow(GameWindow *newGameWindow)
{
    if (m_currentGameWindow)
    {
        disconnectGameWindow(m_currentGameWindow);
        this->removeWidget(m_currentGameWindow);
        delete m_currentGameWindow;
    }
    this->addWidget(newGameWindow);
    m_currentGameWindow = newGameWindow;
}

void GuiManager::connectGameWindow(GameWindow *gameWindow)
{
    connect(gameWindow, &GameWindow::returnToMenu, this, &GuiManager::quitGameClicked);
    connect(gameWindow->returnButton(), &QPushButton::clicked, this, &GuiManager::quitGameClicked);
    connect(gameWindow->restartButton(), &QPushButton::clicked, this, &GuiManager::restartGameClicked);
}

void GuiManager::disconnectGameWindow(GameWindow *gameWindow)
{
    disconnect(gameWindow, &GameWindow::returnToMenu, this, &GuiManager::quitGameClicked);
    disconnect(gameWindow->returnButton(), &QPushButton::clicked, this, &GuiManager::quitGameClicked);
    disconnect(gameWindow->restartButton(), &QPushButton::clicked, this, &GuiManager::restartGameClicked);
}
