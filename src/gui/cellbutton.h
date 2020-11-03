#ifndef CELLBUTTON_H
#define CELLBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class CellButton : public QPushButton
{
    Q_OBJECT
public:
    CellButton(const QString &initialText);

private slots:
    void mousePressEvent(QMouseEvent *e);

signals:
    void rightClicked();
};

#endif // CELLBUTTON_H
