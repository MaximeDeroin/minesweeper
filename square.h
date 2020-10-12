#ifndef SQUARE_H
#define SQUARE_H

#include <QPushButton>
#include <QObject>

class Square : public QObject
{
    Q_OBJECT
public:

    //Square(QObject* parent=0);
    Square(int width, int height, bool hasMine=false);
    virtual ~Square();

    void setHasMine(bool value);
    bool getHasMine() const;

    void setNeighborNumber(int value);
    int getNeighborNumber() const;

    QPushButton* getButton() const;
    void setButton(const QString & newCharacter);


public slots:
    void onClicked();
signals:
    void clicked(int, int);

private:
    int m_width;
    int m_height;
    bool m_hasMine;

    int m_neighborNumber;

    QPushButton* m_button;

};

#endif // SQUARE_H
