#include "game.h"


//Game::Game()
//{

//}

Game::Game(int width, int height, int mineNumber):
    m_started(false),
    m_finished(false),
    m_width(width),
    m_height(height),
    m_mineNumber(mineNumber),
    m_undiscoveredSquares(width*height),
    m_gameState(Game::GameState::ONGOING),
    m_cellGrid(QVector<Cell*>())
{
    for (int i=0; i<height; i++)
       for (int j=0; j<width; j++)
       {
           m_cellGrid.push_back(new Cell());
       }
}

Game::~Game()
{
    for (Cell* cell: m_cellGrid)
    {
        delete cell;
    }
}

bool Game::started() const
{
    return m_started;
}

bool Game::finished() const
{
    return m_finished;
}

void Game::startGame(int i, int j)
{
    placeMines(i, j);
    computeAdjacentMineNumbers();
    m_started = true;
}

int Game::width() const
{
    return m_width;
}

int Game::height() const
{
    return m_height;
}

int Game::mineNumber() const
{
    return m_mineNumber;
}

Game::GameState Game::gameState() const
{
    return m_gameState;
}

void Game::placeMines(int i, int j)
{
    int numberOfSquares = m_width*m_height;
    int numberOfMinePlaced = 0;
    int squareClicked = i*m_width + j;

    while (numberOfMinePlaced != m_mineNumber) {
        int randomNumber = std::rand() % numberOfSquares;
//        std::cout << "randomNumber: " << randomNumber << std::endl;
        if (randomNumber != squareClicked) {
            if(m_cellGrid[randomNumber]->hasMine()==false){
                m_cellGrid[randomNumber]->setHasMine(true);
                numberOfMinePlaced++;
            }
        }
    }
}

void Game::computeAdjacentMineNumbers() {
    for (int i=0; i<m_height; i++)
        for (int j=0; j<m_width; j++) {
            if (!(hasMine(i,j))) {
                int adjacentMines = computeAdjacentMines(i,j);

                setAdjacentMinesNumber(i,j,adjacentMines);
            }
        }
}

int Game::computeAdjacentMines(int i, int j) {
    int neighborsNumber = 0;
    if (hasMine(i-1, j-1))
        neighborsNumber++;
    if (hasMine(i, j-1))
        neighborsNumber++;
    if (hasMine(i+1, j-1))
        neighborsNumber++;
    if (hasMine(i-1, j))
        neighborsNumber++;
    if (hasMine(i+1, j))
        neighborsNumber++;
    if (hasMine(i-1, j+1))
        neighborsNumber++;
    if (hasMine(i, j+1))
        neighborsNumber++;
    if (hasMine(i+1, j+1))
        neighborsNumber++;

    return neighborsNumber;
}


void Game::setAdjacentMinesNumber(int i, int j, int neighborNumber)
{
    m_cellGrid[i*m_width+j]->setNumberOfAdjacentMines(neighborNumber);
}

void Game::discover(int i, int j)
{
    if (m_gameState != Game::GameState::ONGOING)
        return;

    if (!isInBoard(i,j))
        return;

    Cell* clickedCell = cell(i, j);

    if (clickedCell->isDiscovered() || cell(i, j)->isFlagged())
        return;

    clickedCell->setIsDiscovered(true);
    m_undiscoveredSquares--;

    if (clickedCell->hasMine())
    {
        m_gameState = Game::GameState::LOST;
    }
    else if (m_undiscoveredSquares == m_mineNumber)
    {
        m_gameState = Game::GameState::WON;
    }

    if (getNeighborNumber(i, j) == 0) {
        discover(i-1, j-1);
        discover(i, j-1);
        discover(i+1, j-1);
        discover(i-1, j);
        discover(i+1, j);
        discover(i-1, j+1);
        discover(i, j+1);
        discover(i+1, j+1);
    }
}

QString Game::textToPrint(int i, int j)
{
    return m_cellGrid[i*m_width+j]->textToPrint();
}

int Game::getNeighborNumber(int i, int j)
{
    return m_cellGrid[i*m_width+j]->numberOfAdjacentMines();
}

bool Game::hasMine(int i, int j) const{
    //std::cout << i << "; " << j << "; "<<m_gameGrid[i*m_gameWidth+j]->getHasMine()<<std::endl;
    if (isInBoard(i,j)) {
        return cell(i,j)->hasMine();
    } else {
        return false;
    }
}

bool Game::isInBoard(int i, int j) const{
    if (i>=0 && i<m_height)
        if(j>=0 && j<m_width)
            return true;

    return false;
}

Cell* Game::cell(int i, int j) const
{
    if (isInBoard(i, j))
    {
        return m_cellGrid[i*m_width+j];
    }
    else
    {
        return nullptr;
    }
}

