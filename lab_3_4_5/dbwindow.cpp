#include "dbwindow.h"

DbWindow::DbWindow()
{
    dc = new DataContext(Data::Samples::Scenes["prologue"]);
    rep = new ProfileRepository();
    dbList = new QListWidget();

    dbList->setWindowTitle("NEET Adventures");
    dbList->setGeometry(100, 200, 500, 400);
    dbList->setMinimumSize(200, 200);
    dbList->setWindowFlag(Qt::WindowStaysOnTopHint);
    dbList->addItem("New profile");
    for (auto i : *(rep->selectAll())) {
        QString s = QString::number(i.id);
        s += " ";
        s += QString::number((*i.hero)[Hero::HP]);
        s += " ";
        s += QString::number((*i.hero)[Hero::ENERGY]);
        s += " ";
        s += QString::number((*i.hero)[Hero::MOOD]);

        dbList->addItem(s);
    }
    dbList->resize(300,300);
    dbList->show();

    connect(dbList, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onDoubleClick(QModelIndex)));
}

DbWindow::~DbWindow(){
    delete dbList;
}

void DbWindow::onDoubleClick(QModelIndex ind) {
    if(QListWidgetItem* item = dbList->takeItem(ind.row()))
    {
        if (ind.row() != 0) {
            dc = rep->selectByIndex(item->text().split(" ").at(0).toInt());
        }
        dbList->close();
        emit selected();
    }
}

DataContext* DbWindow::getDataContext() {
    return dc;
}
