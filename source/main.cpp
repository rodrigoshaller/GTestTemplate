#include "mainwindow.h"
#include <QApplication>
#include "../tests/all_tests.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Run the tests
    testing::InitGoogleTest(&argc, argv);
    int testsRet = RUN_ALL_TESTS(); Q_UNUSED(testsRet)
    //End testing

    MainWindow w;
    w.show();

    return a.exec();
}
