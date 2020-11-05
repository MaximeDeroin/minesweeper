#include "menuwindow.h"
#include "parameter.h"



MenuWindow::MenuWindow(QWidget *parent) : QWidget(parent)
{
    setFixedSize(400,400);
    setWindowTitle("Minesweeper");
    this->setWindowIcon(QIcon(":/img/mine.png"));

    this->createParameters();
    this->setMenu();
}

void MenuWindow::startAGame()
{
    int width = m_gameWidth->value();
    int height = m_gameHeight->value();
    int mineNumber = m_gameMineNumber->value();

    if (width*height <= mineNumber) {
        QMessageBox::warning(this, "Incompatible parameters",
            "The number of mine is too big, please change the parameters");
    } else {
        GameWindow *gameWindow = new GameWindow(width, height, mineNumber);
        gameWindow->show();
    }
}

void MenuWindow::createParameters()
{
    m_gameWidth = new Parameter("Game Width", 10, 5,20, this);
    m_gameHeight = new Parameter("Game Height", 10, 5, 20, this);
    m_gameMineNumber = new Parameter("Mine Number", 10, 1, 100, this);
}

void MenuWindow::setMenu()
{
    this->createMenuButtons();
    this->createMenuLayout();
    this->connectMenuButtons();
}

void MenuWindow::createMenuButtons()
{
    m_playButton = new QPushButton("Play");
    m_quitButton = new QPushButton("Quit");
}

void MenuWindow::createMenuLayout()
{
    m_mainLayout = new QVBoxLayout;
    m_mainLayout->addWidget(m_playButton);
    m_mainLayout->addLayout(m_gameWidth->parameterLayout());
    m_mainLayout->addLayout(m_gameHeight->parameterLayout());
    m_mainLayout->addLayout(m_gameMineNumber->parameterLayout());
    m_mainLayout->addWidget(m_quitButton);

    this->setLayout(m_mainLayout);
    //this->update();
}

void MenuWindow::connectMenuButtons()
{
    connect(m_playButton, &QPushButton::clicked, this, &MenuWindow::startAGame);
    connect(m_quitButton, &QPushButton::clicked, qApp, &QApplication::quit);
}
