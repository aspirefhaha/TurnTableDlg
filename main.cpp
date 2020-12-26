#include "QTurnTableDlg.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTurnTableDlg w;
    w.show();
    return a.exec();
}
