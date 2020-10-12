#include "menuwindow.h"
#include "parameter.h"



MenuWindow::MenuWindow(QWidget *parent) : QWidget(parent)
{
    setFixedSize(400,400);
    setWindowTitle("Minesweeper");

    this->createParameters();
    this->setMenu();
}

void MenuWindow::startAGame()
{
    int width = m_gameWidth->getValue();
    int height = m_gameHeight->getValue();
    int mineNumber = m_gameMineNumber->getValue();

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
    m_gameWidth = new Parameter("Game Width", 10, 1,20);
    m_gameHeight = new Parameter("Game Height", 10, 1, 20);
    m_gameMineNumber = new Parameter("Mine Number", 10, 1, 20);
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
    m_mainLayout->addLayout(m_gameWidth->getParameterLayout());
    m_mainLayout->addLayout(m_gameHeight->getParameterLayout());
    m_mainLayout->addLayout(m_gameMineNumber->getParameterLayout());
    m_mainLayout->addWidget(m_quitButton);

    this->setLayout(m_mainLayout);
    //this->update();
}

void MenuWindow::connectMenuButtons()
{
    connect(m_playButton, SIGNAL(clicked()), this, SLOT(startAGame()));
    connect(m_quitButton,SIGNAL(clicked()), qApp, SLOT(quit()));

}
