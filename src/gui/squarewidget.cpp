#include "squarewidget.h"

SquareWidget::SquareWidget(int width, int height, const QString& initialText)
{
    m_width = width;
    m_height = height;

    m_button = new CellButton(initialText);
    connect(m_button, &QPushButton::clicked, this, &SquareWidget::onClicked);
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

void SquareWidget::onClicked()
{
    emit clicked(m_width, m_height);
    m_button->setDisabled(true);
}
