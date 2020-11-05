#ifndef SQUARE_H
#define SQUARE_H

#include "cellbutton.h"

/*!
 * @brief Button that displays the state of a cell
 */
class SquareWidget : public QObject
{
    Q_OBJECT
public:
    /*!
     * @brief Constructor of the class
     * @param[in] row Row of the cell
     * @param[in] col Column of the cell
     */
    explicit SquareWidget(int row, int col);

    /*!
     * @brief Default destructor
     */
    virtual ~SquareWidget();

    CellButton* button() const; //!< Getter of m_button
    void setButton(const QString& newCharacter); //!< Setter of m_button

    void setIsClickable(bool isClickable); //!< Setter of m_isClickable

    /*!
     * @brief Disables the cell button
     */
    void disable();

public slots:
    /*!
     * @brief Manages a left click on the cell button
     */
    void onLeftClicked();

    /*!
     * @brief Manages a right click on the cell button
     */
    void onRightClicked();

signals:
    /*!
     * @brief Signals a left click on the cell button
     * @param[in] row Row of the cell
     * @param[in] col Column of the cell
     */
    void leftClicked(int row, int col);

    /*!
     * @brief Signals a right click on the cell button
     * @param[in] row Row of the cell
     * @param[in] col Column of the cell
     */
    void rightClicked(int row, int col);

private:
    int m_row; //!< Width of the game in number of cells
    int m_col; //!< Height of the game in number of cells

    bool m_isClickable; //!< Indicates if the player can click on the cell

    CellButton* m_button; //!< Button of the cell
};

#endif // SQUARE_H
