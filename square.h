#ifndef SQUARE_H
#define SQUARE_H

#include <QPushButton>
#include <QObject>

class Square : public QObject
{
    Q_OBJECT
public:

    Square(int width, int height, const QString &initialText = "-");
    virtual ~Square();

    QPushButton* button() const;
    void setButton(const QString & newCharacter);

public slots:
    void onClicked();
signals:
    void clicked(int, int);

private:
    int m_width;
    int m_height;

    QPushButton* m_button;
};

#endif // SQUARE_H
