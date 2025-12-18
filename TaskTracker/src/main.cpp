#include "tasktracker.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TaskTracker window;
    window.show();
    return app.exec();
}
