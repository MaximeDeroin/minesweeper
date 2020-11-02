#ifndef SQUARE_H
#define SQUARE_H

#include "cellbutton.h"

class SquareWidget : public QObject
{
    Q_OBJECT
public:

    SquareWidget(int width, int height, const QString &initialText = "-");
    virtual ~SquareWidget();

    CellButton* button() const;
    void setButton(const QString & newCharacter);

public slots:
    void onClicked();
signals:
    void clicked(int, int);

private:
    int m_width;
    int m_height;

    CellButton* m_button;
};

#endif // SQUARE_H
