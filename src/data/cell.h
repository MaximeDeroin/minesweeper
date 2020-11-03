#ifndef CELL_H
#define CELL_H

#include <QString>
#include <QColor>

/**
 * @brief Stores info of a cell
 */
class Cell
{
public:
    Cell();

    bool hasMine() const;
    void setHasMine(bool hasMine);

    int numberOfAdjacentMines() const;
    void setNumberOfAdjacentMines(int numberOfAdjacentMines);

    bool isFlagged() const;

    bool isDiscovered() const;
    void setIsDiscovered(bool isDiscovered);

    bool changeFlagStatus();
    void sendSignal();

    QString textToPrint(QString &styleSheet);

private:
    bool m_hasMine;
    int m_numberOfAdjacentMines;
    bool m_isFlagged;
    bool m_isDiscovered;

    QColor textColor();
};

#endif // CELL_H
