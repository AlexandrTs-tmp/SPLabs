#ifndef PROFILEREPOSITORY_H
#define PROFILEREPOSITORY_H

#include <QtSql>
#include "commandmanager.h"

class ProfileRepository
{
public:
    ProfileRepository();
    DataContext* selectByIndex(int ind);
    std::list<DataContext>* selectAll();
    void update(DataContext*);
    void create(DataContext*);
private:
    // QSqlDatabase* db;
};

#endif // PROFILEREPOSITORY_H
