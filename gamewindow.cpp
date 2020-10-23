#include "gamewindow.h"
#include <iostream>


GameWindow::GameWindow(int width, int height, int mineNumber):
    m_game(new Game(width, height, mineNumber)),
    m_buttons(QVector<Square*>())
{
    setFixedSize(30*width,30*height);

    initializeAttributes(width, height, mineNumber);

    initializeLayout();

    std::srand(std::time(0));
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
//        placeMines(i, j);
//        computeAdjacentMineNumbers();
//        gameStarted = true;
    }

    m_game->discover(i,j);

    if(m_game->gameState() == Game::GameState::LOST)
    {
//        setButtonText(i, j, "*");
        QMessageBox::information(this, "Raté", "Vous avez perdu...");

    }
    else if (m_game->gameState() == Game::GameState::WON)
    {
        QMessageBox::information(this, "Victoire", "Vous avez gagné !");
    }

    repaintGame();
}

void GameWindow::initializeAttributes(int width, int height, int mineNumber)
{
    m_gameWidth = width;
    m_gameHeight = height;
//    m_gameMineNumber = mineNumber;
//    m_discoveredSquares = width*height;

//    gameStarted = false;
//    gameFinished = false;

//    for (int i=0; i<m_gameHeight; i++)
//       for (int j=0; j<m_gameWidth; j++) {
//           Square* initialSquare = new Square(i, j, false);
//           m_gameGrid.push_back(initialSquare);
//       }
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
//            Square* currentSquare = m_gameGrid[i*m_gameWidth+j];
//            //int index = i*m_gameWidth+j;

//            m_gameLayout->addWidget(currentSquare->getButton(), i, j);
//            //connect(&currentSquare, SIGNAL(clicked()), this, SLOT()  )

//            connect(currentSquare, SIGNAL(clicked(int, int)), this, SLOT(squareClicked(int,int)));

        }

    this->setLayout(m_gameLayout);
}

//void GameWindow::placeMines(int i, int j)
//{
//    int numberOfSquares = m_gameWidth*m_gameHeight;
//    int numberOfMinePlaced = 0;
//    int squareClicked = i*m_gameWidth + j;

//    while (numberOfMinePlaced != m_gameMineNumber) {
//        int randomNumber = std::rand() % numberOfSquares;
//        std::cout << "randomNumber: " << randomNumber << std::endl;
//        if (randomNumber != squareClicked) {
//            if(m_gameGrid[randomNumber]->getHasMine()==false){
//                m_gameGrid[randomNumber]->setHasMine(true);
//                numberOfMinePlaced++;
//            }
//        }
//    }
//}

//void GameWindow::computeAdjacentMineNumbers() {
//    for (int i=0; i<m_gameHeight; i++)
//        for (int j=0; j<m_gameWidth; j++) {
//            if (!(hasMine(i,j))) {
//                int adjacentMines = computeAdjacentMines(i,j);

//                setNeighborNumber(i,j,adjacentMines);
//            }
//        }
//}

//int GameWindow::computeAdjacentMines(int i, int j) {
//    int neighborsNumber = 0;
//    if (hasMine(i-1, j-1))
//        neighborsNumber++;
//    if (hasMine(i, j-1))
//        neighborsNumber++;
//    if (hasMine(i+1, j-1))
//        neighborsNumber++;
//    if (hasMine(i-1, j))
//        neighborsNumber++;
//    if (hasMine(i+1, j))
//        neighborsNumber++;
//    if (hasMine(i-1, j+1))
//        neighborsNumber++;
//    if (hasMine(i, j+1))
//        neighborsNumber++;
//    if (hasMine(i+1, j+1))
//        neighborsNumber++;

//    return neighborsNumber;
//}

//void GameWindow::discover(int i, int j) {
//    if (!isInBoard(i,j))
//        return;
//    if (getButtonText(i,j) != "-")
//        return;

//    m_discoveredSquares--;
//    setButtonText(i,j, getNeighborNumber(i,j));

//    if (getNeighborNumber(i, j) == 0) {
//        discover(i-1, j-1);
//        discover(i, j-1);
//        discover(i+1, j-1);
//        discover(i-1, j);
//        discover(i+1, j);
//        discover(i-1, j+1);
//        discover(i, j+1);
//        discover(i+1, j+1);
//    }
//}

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


//bool GameWindow::hasMine(int i, int j) const{
//    //std::cout << i << "; " << j << "; "<<m_gameGrid[i*m_gameWidth+j]->getHasMine()<<std::endl;
//    if (isInBoard(i,j)) {
//        return m_gameGrid[i*m_gameWidth+j]->getHasMine();
//    } else {
//        return false;
//    }
//}

//bool GameWindow::isInBoard (int i, int j) const{
//    if (i>=0 && i<m_gameHeight)
//        if(j>=0 && j<m_gameWidth)
//            return true;

//    return false;
//}



