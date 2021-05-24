#ifndef DBWINDOW_H
#define DBWINDOW_H

#include <QListWidgetItem>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QAction>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include "profilerepository.h"

class DbWindow : public QObject
{
    Q_OBJECT
public:
    DbWindow();
    ~DbWindow();
    DataContext* getDataContext();
    ProfileRepository* rep;
private:
    DataContext* dc;
    QListWidget* dbList;

private slots:
    void onDoubleClick(QModelIndex ind);
        signals:
    void selected();
};

class DbListItem : public QListWidgetItem
{
    public: int id;
};

#endif // DBWINDOW_H
