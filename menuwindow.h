#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>

#include "parameter.h"
#include "gamewindow.h"

class MenuWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MenuWindow(QWidget *parent = 0);

public slots:
    void startAGame();

private:
    Parameter* m_gameWidth;
    Parameter* m_gameHeight;
    Parameter* m_gameMineNumber;

    QPushButton* m_playButton;
    QPushButton* m_quitButton;

    QVBoxLayout* m_mainLayout;

    void createParameters();

    void setMenu();

    void createMenuButtons();
    void createMenuLayout();
    void connectMenuButtons();

};


#endif // MENUWINDOW_H
