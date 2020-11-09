#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include <QStackedWidget>
#include "gui/menuwindow.h"
#include "gui/gamewindow.h"

/*!
 * \brief Manages the Graphical User Interface of the application
 */
class GuiManager : public QStackedWidget
{
    Q_OBJECT
public:
    /*!
     * @brief Class constructor
     * @param[in] parent Parent widget
     */
    explicit GuiManager();

    /*!
     * @brief Default destructor
     */
    virtual ~GuiManager();

private:
    MenuWindow* m_menuWindow; //!< Menu window
    GameWindow* m_currentGameWindow; //!< Window of the ongoing game

    int m_width; //!< Width of the game in number of cells
    int m_height; //!< Height of the game in number of cells
    int m_mineNumber; //!< Number of mines in the game

    /*!
     * @brief Enumerates the different gui pages
     */
    enum class Page
    {
        MENU = 0, //!< Menu page
        GAME = 1 //!< Game page
    };

    /*!
     * \brief Replaces the game window by a new one
     * \param[in] New game window
     */
    void replaceGameWindow(GameWindow *newGameWindow);

    /*!
     * \brief Connects game window buttons to GUI manager slots
     * \param[in] gameWindow Game window
     */
    void connectGameWindow(GameWindow *gameWindow);

    /*!
     * \brief Disonnects game window buttons to GUI manager slots
     * \param[in] gameWindow Game window
     */
    void disconnectGameWindow(GameWindow *gameWindow);

public slots:
    /*!
     * \brief Creates a new game window with the input parameters
     * @param[in] width width of the game grid
     * @param[in] height height of the game grid
     * @param[in] mineNumber number of mines in the grid
     */
    void newGameClicked(int width, int height, int mineNumber);

    /*!
     * \brief Closes the game window
     */
    void quitGameClicked();

    /*!
     * \brief Creates a new game window
     */
    void restartGameClicked();
};

#endif // GUIMANAGER_H
