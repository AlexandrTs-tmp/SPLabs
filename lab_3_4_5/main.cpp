#include "mainwindow.h"
#include <QApplication>


std::map<QString, Scene*> Data::Samples::Scenes = {};
std::map<QString, Scene> Data::Samples::Events = {};

int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("accounts.db");

    Data::Samples::Initialize();

    QApplication a(argc, argv);
    MainWindow w;


    return a.exec();
}
