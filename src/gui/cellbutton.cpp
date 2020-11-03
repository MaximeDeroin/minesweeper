#include "cellbutton.h"

CellButton::CellButton(const QString& initialText):
    QPushButton(initialText)
{
    this->setFixedSize(30,30);
}


void CellButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton)
    {
        emit rightClicked();
    }
    else
    {
        QPushButton::mousePressEvent(e);
    }
}
