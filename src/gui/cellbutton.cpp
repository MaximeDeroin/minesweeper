#include "cellbutton.h"

CellButton::CellButton():
    QPushButton(QString(" "))
{
    this->setFixedSize(BUTTON_SIZE,BUTTON_SIZE);
}

void CellButton::repaintButton(const QString &text, const QString &styleSheet, bool disable)
{
    if (text == QString("F"))
    {
        this->drawFlag();
    }
    else
    {
        this->setText(text);
        this->setStyleSheet(styleSheet);
        this->setIcon(QIcon());
    }
    this->setDisabled(disable);
    this->repaint();
}

void CellButton::drawFlag()
{
    QPixmap pixmap(":/img/flag.png");
    QIcon ButtonIcon(pixmap);
    this->setIcon(ButtonIcon);
    this->setIconSize(QSize(BUTTON_SIZE, BUTTON_SIZE));
}

void CellButton::mousePressEvent(QMouseEvent* event)
{
    if(event->button()==Qt::RightButton)
    {
        emit rightClicked();
    }
    else
    {
        QPushButton::mousePressEvent(event);
    }
}

QString CellButton::textToPrint(Cell const* cell, QString& styleSheet)
{
    styleSheet = "font-size: "+QString::number(TEXT_SIZE)+"pt;font-weight: bold";
    int numberOfAdjacentMines = cell->numberOfAdjacentMines();
    if (cell->isDiscovered())
    {
        if (cell->hasMine() == true)
        {
            return QString("*");
        }
        else if (numberOfAdjacentMines >= 1)
        {
            QColor col(textColor(numberOfAdjacentMines));
            styleSheet += QString("; color: %1").arg(col.name());
            return QString::number(numberOfAdjacentMines);
        }
        else
        {
            return QString(" ");
        }
    }
    else
    {
        if (cell->isFlagged())
        {
            return QString("F");
        }
        else
        {
            return QString(" ");
        }
    }
}

QColor CellButton::textColor(int numberToDisplay)
{
    QColor textColor(Qt::black);
    switch(numberToDisplay)
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
