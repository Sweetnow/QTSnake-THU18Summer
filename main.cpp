#include"window.h"
#include"showwidget.h"
#include <QTime>
#include <QApplication>

int main(int argc, char *argv[])
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QApplication a(argc, argv);
    window w;
    w.show();
    return a.exec();
}
