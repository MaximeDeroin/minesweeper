#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>

#include "parameter.h"
#include "gamewindow.h"

/*!
 * @brief Manages the menu gui
 */
class MenuWindow : public QWidget
{
    Q_OBJECT
public:
    /*!
     * @brief Class constructor
     * @param[in] parent Parnet widget
     */
    explicit MenuWindow(QWidget *parent = nullptr);

public slots:
    /*!
     * @brief Starts a game
     */
    void startAGame();

private:
    Parameter* m_gameWidth; //!< Parameter managing the width of the game
    Parameter* m_gameHeight; //!< Parameter managing the height of the game
    Parameter* m_gameMineNumber; //!< Parameter managing the number of mines in the game

    QPushButton* m_playButton; //!< Play button
    QPushButton* m_quitButton; //!< Quit button

    QVBoxLayout* m_mainLayout; //!< Layout of the window

    /*!
     * @brief Create the Parameter objects
     */
    void createParameters();

    /*!
     * @brief Initializes the menu display
     */
    void setMenu();

    /*!
     * @brief Initializes the menu buttons
     */
    void createMenuButtons();

    /*!
     * @brief Initializes the menu layout
     */
    void createMenuLayout();

    /*!
     * @brief Connect the menu button signals
     */
    void connectMenuButtons();
};


#endif // MENUWINDOW_H
