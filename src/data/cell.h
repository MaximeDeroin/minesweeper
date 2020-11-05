#ifndef CELL_H
#define CELL_H

#include <QString>
#include <QColor>

/*!
 * @brief Stores info of a cell
 */
class Cell
{
public:
    /*!
     * @brief Default constructor
     * Initializes members
     */
    explicit Cell();

    bool hasMine() const; //!< Getter of m_hasMine
    void setHasMine(bool hasMine); //!< Setter of m_hasMine

    int numberOfAdjacentMines() const; //!< Getter of m_numberOfAdjacentMines
    void setNumberOfAdjacentMines(int numberOfAdjacentMines); //!< Setter of m_numberOfAdjacentMines

    bool isFlagged() const; //!< Getter of m_isFlagged

    bool isDiscovered() const; //!< Getter of m_isDiscovered
    void setIsDiscovered(bool isDiscovered); //!< Setter of m_isDiscovered

    /*!
     * @brief Changes value of m_isFlagged (switch between true and false)
     * @return New value of m_isFlagged
     */
    bool changeFlagStatus();

    /*!
     * @brief Provides text to display on the cell.
     * Returns m_numberOfAdjacentMines if it is from 1 to 8
     * Return space id m_numberOfAdjacentMines = 0
     * Returns F is the cell is flagged (m_isFlagged = true)
     * @param[out] styleSheet Style of the text
     * @todo Check if this process should be done in the gui classes
     * @return Text to print on the cell
     */
    QString textToPrint(QString &styleSheet);

private:
    bool m_hasMine; //!< Indicates if the cell contains a mine
    int m_numberOfAdjacentMines; //!< Contains the number of adjacent cells with a mine
    bool m_isFlagged; //!< Indicates if the cell is currently flagged
    bool m_isDiscovered; //!< Indicates if the cell has been discovered

    /*!
     * @brief Provides color of the text to display on the cell
     * @todo Check if this process should be done in the gui classes
     * @return Color of the text to display on the cell
     */
    QColor textColor();
};

#endif // CELL_H
