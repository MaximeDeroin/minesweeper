#include <QApplication>
#include "gui/guimanager.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GuiManager guiManager;

    return app.exec();
}
