#include "square.h"

Square::Square(int width, int height, const QString& initialText)
{
    m_width = width;
    m_height = height;

    m_button = new QPushButton(initialText);
    connect(m_button, &QPushButton::clicked, this, &Square::onClicked);
}

Square::~Square()
{
    delete m_button;
}

QPushButton* Square::button() const
{
    return this->m_button;
}

void Square::setButton(const QString & newCharacter)
{
    m_button->setText(newCharacter);
}

void Square::onClicked()
{
    emit clicked(m_width, m_height);
}
