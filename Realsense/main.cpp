#include "realsense.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Realsense w;
    w.show();

    return a.exec();
}
