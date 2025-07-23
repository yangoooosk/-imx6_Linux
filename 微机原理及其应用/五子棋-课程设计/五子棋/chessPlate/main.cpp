#include "chessform.h"
#include "chessplate.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chessForm w;
    w.show();
//    chessPlate e;
//    e.show();
    return a.exec();
}
