#include "cellbutton.h"

CellButton::CellButton(const QString& initialText):
    QPushButton(initialText)
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
