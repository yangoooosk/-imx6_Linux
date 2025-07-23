#include "widget.h"
#include <QApplication>

#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    int dex = QFontDatabase::addApplicationFont("./wenquanyi.ttf");
    if(dex != -1)
    {
        QStringList strlist(QFontDatabase::applicationFontFamilies(dex));
        if(strlist.count()>0)
        {
            QFont fontthis(strlist.at(0));
            fontthis.setPixelSize(20);
            a.setFont(fontthis);
        }
    }

    w.show();

    return a.exec();
}
