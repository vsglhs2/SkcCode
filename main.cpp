#include "skc.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Skc w;
    QPixmap pixmap(":/icons/iconMini.png");
    w.setWindowTitle("Система контроля знаний");
    w.setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    w.setWindowIcon(pixmap);
    w.resize(482, 322);

    w.show();
    return a.exec();
}
