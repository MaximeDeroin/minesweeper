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

QString Cell::textToPrint(QString& styleSheet)
{
    styleSheet = "font-size: 14pt;font-weight: bold";
    if (m_isDiscovered)
    {
        if (m_hasMine == true)
        {
            return QString("*");
        }
        else if (m_numberOfAdjacentMines >= 1)
        {
            QColor col(textColor());
            styleSheet += QString("; color: %1").arg(col.name());
            return QString::number(m_numberOfAdjacentMines);
        }
        else
        {
            return QString(" ");
        }
    }
    else
    {
        if (m_isFlagged)
        {
            return QString("F");
        }
        else
        {
            return QString(" ");
        }
    }
}

QColor Cell::textColor()
{
    QColor textColor(Qt::black);
    switch(m_numberOfAdjacentMines)
    {
        case 1:
            textColor = Qt::blue;
            break;
        case 2:
            textColor = Qt::darkGreen;
            break;
        case 3:
            textColor = Qt::red;
            break;
        case 4:
            textColor = Qt::darkBlue;
            break;
        case 5:
            textColor = Qt::darkMagenta;
            break;
        case 6:
            textColor = Qt::darkCyan;
            break;
        case 7:
            textColor = Qt::darkYellow;
            break;
        case 8:
            textColor = Qt::gray;
            break;
        default:
            break;
    }
    return textColor;
}
