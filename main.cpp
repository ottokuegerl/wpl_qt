#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    int value = a.exec();

    qInfo() << "main() return value: " << "---> " << value << " <---";

    return value;
}
