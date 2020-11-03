#include "squarewidget.h"

SquareWidget::SquareWidget(int width, int height, const QString& initialText):
    m_width(width),
    m_height(height),
    m_isClickable(true),
    m_button(new CellButton(initialText))

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

void SquareWidget::setButton(const QString & newCharacter)
{
    m_button->setText(newCharacter);
}

void SquareWidget::onLeftClicked()
{
    if (m_isClickable)
    {
        emit leftClicked(m_width, m_height);
        m_button->setDisabled(true);
    }
}

void SquareWidget::onRightClicked()
{
    emit rightClicked(m_width, m_height);
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
