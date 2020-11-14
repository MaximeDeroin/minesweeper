#include "squarewidget.h"

SquareWidget::SquareWidget(int row, int col):
    m_row(row),
    m_col(col),
    m_isClickable(true),
    m_button(new CellButton())

{
    connect(m_button, &QPushButton::clicked, this, &SquareWidget::onLeftClicked);
    connect(m_button, &CellButton::rightClicked, this, &SquareWidget::onRightClicked);
}


SquareWidget::~SquareWidget()
{
    delete m_button;
}

CellButton* SquareWidget::button() const
{
    return this->m_button;
}

void SquareWidget::onLeftClicked()
{
    if (m_isClickable)
    {
        emit leftClicked(m_row, m_col);
        m_button->setDisabled(true);
    }
}

void SquareWidget::onRightClicked()
{
    emit rightClicked(m_row, m_col);
}

void SquareWidget::setIsClickable(bool isClickable)
{
    m_isClickable = isClickable;
}

void SquareWidget::disable()
{
    disconnect(m_button, &QPushButton::clicked, this, &SquareWidget::onLeftClicked);
    disconnect(m_button, &CellButton::rightClicked, this, &SquareWidget::onRightClicked);
}
