#ifndef SQUARE_H
#define SQUARE_H

#include <QPushButton>

class SquareWidget : public QObject
{
    Q_OBJECT
public:

    SquareWidget(int width, int height, const QString &initialText = "-");
    virtual ~SquareWidget();

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
