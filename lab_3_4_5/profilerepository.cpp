#include "profilerepository.h"

ProfileRepository::ProfileRepository()
{
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.open()) {
        QTextStream(stdout) << "lol";
    };

    QSqlQuery query;

    if (!query.exec("CREATE TABLE IF NOT EXISTS accounts ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "hp INT,"
                    "energy INT,"
                    "mood INT,"
                    "day INT)")) {
        QTextStream(stdout) << query.lastError().text();
    }

    db.close();
}

std::list<DataContext>* ProfileRepository::selectAll() {
    std::list<DataContext>* dcList = new std::list<DataContext>();
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.open()) {
    }

    QSqlQuery query;

    if (!query.exec("SELECT hp, energy, mood, day, id FROM accounts")) {
        QTextStream(stdout) << query.lastError().text();
    }

    std::list<int*> accounts;

    while (query.next()) {
        accounts.push_back(new int[5] {
                query.value(0).toInt(),
                query.value(1).toInt(),
                query.value(2).toInt(),
                query.value(3).toInt(),
                query.value(4).toInt() });
    }

    db.close();

    for (auto i : accounts)
    {
        DataContext* res = new DataContext(Data::Samples::Scenes["day"]);
        (*res->hero)[Hero::HP] = i[0];
        (*res->hero)[Hero::ENERGY] = i[1];
        (*res->hero)[Hero::MOOD] = i[2];
        res->updates = i[3];
        res->id = i[4];
        dcList->push_back(*res);
    }

    return dcList;
}

DataContext* ProfileRepository::selectByIndex(int ind) {
    DataContext* res = new DataContext(Data::Samples::Scenes["day"]);

    QSqlDatabase db = QSqlDatabase::database();

    if (!db.open()) {
    }

    QSqlQuery query;
    query.prepare("SELECT hp, energy, mood, day, id FROM accounts WHERE id = :id");
    query.bindValue(":id", ind);
    query.exec();

    while (query.next()) {
        (*res->hero)[Hero::HP] = query.value(0).toInt();
        (*res->hero)[Hero::ENERGY] = query.value(1).toInt();
        (*res->hero)[Hero::MOOD] = query.value(2).toInt();
        res->updates = query.value(3).toInt();
    }

    db.close();

    return res;
}

void ProfileRepository::update(DataContext* res) {
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.open()) {
    }

    QSqlQuery query;
    query.prepare("UPDATE accounts SET"
                       "hp = ?,"
                       "energy = ?,"
                       "mood = ?,"
                       "day = ?,"
                       "WHERE id = ?");
    query.addBindValue((*res->hero)[Hero::HP]);
    query.addBindValue((*res->hero)[Hero::ENERGY]);
    query.addBindValue((*res->hero)[Hero::MOOD]);
    query.addBindValue(res->updates);
    query.addBindValue(res->id);

    if (query.exec()) {

    }

    db.close();
}

void ProfileRepository::create(DataContext* context) {
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.open()) {
    }

    QSqlQuery query;
    query.prepare("INSERT INTO accounts (hp, energy, mood, day) VALUES (?, ?, ?, ?)");
    query.addBindValue((*context->hero)[Hero::HP]);
    query.addBindValue((*context->hero)[Hero::ENERGY]);
    query.addBindValue((*context->hero)[Hero::MOOD]);
    query.addBindValue(context->updates);

    if (!query.exec())
    {
        QTextStream(stdout) << query.lastError().text();
    }

    db.close();
}
