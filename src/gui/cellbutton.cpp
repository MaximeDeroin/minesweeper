#include "cellbutton.h"

CellButton::CellButton(const QString& initialText):
    QPushButton(initialText)
{
    this->setFixedSize(30,30);
}
