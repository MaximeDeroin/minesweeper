#include <QApplication>
#include "gui/menuwindow.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MenuWindow window;
    window.show();

    return app.exec();
}
