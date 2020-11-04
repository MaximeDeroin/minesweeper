#ifndef GAME_H
#define GAME_H

#include "cell.h"
#include <QVector>

/**
 * @brief Stores info of a game
 */
class Game
{
public:
    /**
     * @brief Class constructor
     * Initializes members
     * @param[in] width Width of the game in cells
     * @param[in] height Height of the game in cells
     * @param[in] mineNumber Number of mines in the game
     */
    explicit Game(int width, int height, int mineNumber);

    /**
     * @brief Default destructor
     */
    virtual ~Game();

    /**
     * @brief Describes the current game state
     */
    enum class GameState
    {
        ONGOING = 0, //<! The game is ongoing
        WON = 1, //<! The player has won the game
        LOST = 2 //<! The player has lost the game
    };

    bool started() const; //!< Getter of m_started
    bool finished() const; //!< Getter of m_finished

    int width() const; //!< Getter of m_width
    int height() const; //!< Getter of m_height
    int mineNumber() const; //!< Getter of m_mineNumber

    GameState gameState() const; //!< Getter of m_gameState

    /**
     * @brief Initializes the game
     * @param[in] i Row number of the first played cell
     * @param[in] j Column number of the first played cell
     */
    void startGame(int i, int j);

    /**
     * @brief Discovers a cell
     * @param[in] i Row number of the cell
     * @param[in] j Column number of the cell
     * @return True if the discover action ends the game.
     */
    bool discover(int i, int j);

    /**
     * @brief Flag or unflag a cell
     * @param[in] i Row number of the cell
     * @param[in] j Column number of the cell
     * @return True if cell is now flagged
     */
    bool flag(int i, int j);

    /**
     * @brief Provides text to display on the cell.
     * @param[in] i Row number of the cell
     * @param[in] j Column number of the cell
     * @param[out] styleSheet Style of the text
     * @return Text to print on the cell
     */
    QString textToPrint(int i, int j, QString &styleSheet);

    /**
     * @brief Indicates if a cell is discovered
     * @param[in] i Row number of the cell
     * @param[in] j Column number of the cell
     * @return True if the cell is discovered
     */
    bool cellIsDiscovered(int i, int j);

private:
    bool m_started; //!< Indicates if the game is started
    bool m_finished; //!< Indicates if the game is finished

    int m_width; //!< Width of the game in number of cells
    int m_height; //!< Height of the game in number of cells
    int m_mineNumber; //!< Number of mines in the game

    int m_undiscoveredSquares; //!< Number of undiscovered squares
    GameState m_gameState; //!< State of the game

    QVector<Cell*> m_cellGrid; //!< Grid of cells representing the minefield

    /**
     * @brief Places mines in the grid
     * @param[in] i Row number of the first played cell
     * @param[in] j Column number of the first played cell
     * @details First played cell cannot contain a mine
     */
    void placeMines(int i, int j);

    /**
     * @brief Computes adjacent mine numbers for all cells in the field
     */
    void computeAdjacentMineNumbers();

    /**
     * @brief Computes adjacent mine numbers for a specific cell
     * @param[in] i Row number of the cell
     * @param[in] j Column number of the cell
     * @return Number of adjacent cells with a mine
     */
    int computeAdjacentMines(int i, int j);

    /**
     * @brief Set number of adjacent cells with a mine in the Cell object
     * @param[in] i Row number of the cell
     * @param[in] j Column number of the cell
     * @param[in] neighborNumber Number of adjacent cells with a mine
     */
    void setAdjacentMinesNumber(int i, int j, int neighborNumber);

    /**
     * @brief Indicates if a cell contains a mine
     * @param[in] i Row number of the cell
     * @param[in] j Column number of the cell
     * @return True if the cell contains a mine
     */
    bool hasMine(int i, int j) const;

    /**
     * @brief Indicates if the coordinates correspond to a cell in the field
     * @param[in] i Row number of the cell
     * @param[in] j Column number of the cell
     * @return True if cell(i,j) is a cell in the grid
     */
    bool isInBoard(int i, int j) const;

    /**
     * @brief Getter of the number of adjacent cells with a mine for a specific cell
     * @param[in] i Row number of the cell
     * @param[in] j Column number of the cell
     * @return Number of adjacent cells with a mine
     */
    int getNeighborNumber(int i, int j);

    /**
     * @brief Getter of a cell
     * @param[in] i Row number of the cell
     * @param[in] j Column number of the cell
     * @return Cell to access. nullptr if (i,j) is not in grid
     * @details Used to increase code readability
     */
    Cell* cell(int i, int j) const;
};

#endif // GAME_H
