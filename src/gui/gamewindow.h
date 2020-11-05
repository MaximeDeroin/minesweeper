#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <vector>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>

#include "squarewidget.h"

#include "../data/game.h"
#include "../data/cell.h"

/*!
 * @brief Manages the game widow
 */
class GameWindow : public QWidget
{
    Q_OBJECT
public:
    /*!
     * @brief GameWindow create a game with the parameters in argument
     * @param[in] width width of the game grid
     * @param[in] height height of the game grid
     * @param[in] mineNumber number of mines in the grid
     * @warning requires that the number of mine is compatible, there must be at least 1 mine and
     * one empty square in the grid (width*height < mineNumber
     */
    explicit GameWindow(int width, int height, int mineNumber);

    /*!
     * @brief Default destructor
     */
    virtual ~GameWindow();

signals:

public slots:

private:
    int m_gameWidth; //!< Width of the game in number of cells
    int m_gameHeight; //!< Height of the game in number of cells
    int m_gameMineNumber; //!< Number of mines in the game

    /*!
     * @brief stores the game buttons in a 1D vector.
     * In the buttons array, the element in position (x,y) will be in position
     * x*m_gameWidth+y in the vector
     * @note indices go from 0 to m_gameWidth*m_gameHeight - 1 after the
     * vector is initialized
     */
    QVector<SquareWidget*> m_buttons;

    QGridLayout* m_gameLayout; //!< Layout of the game

    Game* m_game; //!< Information of the game

    /*!
     * @brief Initizes the window layout
     */
    void initializeLayout();

    /*!
     * @brief Updates the game display
     */
    void repaintGame();

private slots:
    /*!
     * @brief Manages a left click on a cell
     * @param[in] i Row number of the cell
     * @param[in] j Column number of the cell
     */
    void squareLeftClicked(int i, int j);

    /*!
     * @brief Manages a right click on a cell
     * @param[in] i Row number of the cell
     * @param[in] j Column number of the cell
     */
    void squareRightClicked(int i, int j);

private:
    /*!
     * @brief Getter for the cell widget
     * @param[in] i Row number of the cell
     * @param[in] j Column number of the cell
     * @return Cell widget
     */
    SquareWidget* squareWidget(int i, int j);
};

#endif // GAMEWINDOW_H
