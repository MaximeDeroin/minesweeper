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

    void setIsClickable(bool isClickable);

    void disable();
public slots:
    void onLeftClicked();
    void onRightClicked();

signals:
    void leftClicked(int width, int height);
    void rightClicked(int width, int height);

private:
    int m_width;
    int m_height;

    bool m_isClickable;

    CellButton* m_button;
};

#endif // SQUARE_H
