#ifndef CELLBUTTON_H
#define CELLBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class CellButton : public QPushButton
{
    Q_OBJECT
public:
    CellButton(const QString &initialText);

    void repaintButton(const QString& text, const QString& styleSheet, bool disable);

private slots:
    void mousePressEvent(QMouseEvent *e);

signals:
    void rightClicked();

private:
    void drawFlag();

    int BUTTON_SIZE = 30;
};

#endif // CELLBUTTON_H
