#include "square.h"


/*Square::Square(QObject *parent)
{

}*/

Square::Square(int width, int height, bool hasMine)
{
    m_width = width;
    m_height = height;
    m_hasMine = hasMine;
    m_neighborNumber = -1;

    m_button = new QPushButton("-");
    connect(m_button, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
}

Square::~Square()
{
    delete m_button;
}


void Square::setHasMine(bool value)
{
    m_hasMine = value;
}

bool Square::getHasMine() const
{
    return m_hasMine;
}

void Square::setNeighborNumber(int value)
{
    m_neighborNumber = value;
}

int Square::getNeighborNumber() const
{
    return m_neighborNumber;
}

QPushButton* Square::getButton() const
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

/* voidsetButton()
{
    return this->m_button;
}
*/
