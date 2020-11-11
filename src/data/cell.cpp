#include "cell.h"

Cell::Cell():
    m_hasMine(false),
    m_numberOfAdjacentMines(0),
    m_isFlagged(false),
    m_isDiscovered(false)
{

}

bool Cell::hasMine() const
{
    return m_hasMine;
}

void Cell::setHasMine(bool hasMine)
{
    m_hasMine = hasMine;
}

int Cell::numberOfAdjacentMines() const
{
    return m_numberOfAdjacentMines;
}

void Cell::setNumberOfAdjacentMines(int numberOfAdjacentMines)
{
    m_numberOfAdjacentMines = numberOfAdjacentMines;
}

bool Cell::isFlagged() const
{
    return m_isFlagged;
}

bool Cell::isDiscovered() const
{
    return m_isDiscovered;
}

void Cell::setIsDiscovered(bool isDiscovered)
{
    m_isDiscovered = isDiscovered;
}

bool Cell::changeFlagStatus()
{
    m_isFlagged = !m_isFlagged;
    return m_isFlagged;
}
