#ifndef CONTEXTREPOSITORY_H
#define CONTEXTREPOSITORY_H

#include <QtSql>

class ContextRepository
{
public:
    ContextRepository();
    int* selectByIndex(int);
    void update(int, int*);
    void create(int*);
};

#endif // CONTEXTREPOSITORY_H
