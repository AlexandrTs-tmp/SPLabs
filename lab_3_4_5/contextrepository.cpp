#include "contextrepository.h"

ContextRepository::ContextRepository()
{
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.open()) {
    };

    QSqlQuery query;

    if (!query.exec("CREATE TABLE IF NOT EXISTS hero_default ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "hp INT,"
                    "energy INT,"
                    "mood INT)")) {
        QTextStream(stdout) << query.lastError().text();
    }

    db.close();
}

int* ContextRepository::selectByIndex(int ind) {
    int* res = new int[3];

    QSqlDatabase db = QSqlDatabase::database();

    if (!db.open()) {
    }

    QSqlQuery query;
    query.prepare("SELECT hp, energy, mood FROM hero_default WHERE id = :id");
    query.bindValue(":id", ind);
    query.exec();

    while (query.next()) {
        res[0] = query.value(0).toInt();
        res[1] = query.value(1).toInt();
        res[2] = query.value(2).toInt();
    }

    db.close();

    return res;
}

void ContextRepository::update(int ind, int* values) {
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.open()) {
    }

    QSqlQuery query;
    query.prepare("UPDATE hero_default SET "
                       "hp = ?"
                       "energy = ?"
                       "mood = ?"
                       "WHERE id = ?");
    query.addBindValue(values[0]);
    query.addBindValue(values[1]);
    query.addBindValue(values[2]);
    query.addBindValue(ind);


    if (!query.exec()) {
        QTextStream(stdout) << query.lastError().text();
    }

    db.close();
}

void ContextRepository::create(int* values) {
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.open()) {
    }

    QSqlQuery query;
    query.prepare("INSERT INTO hero_default (hp, energy, mood) VALUES (?, ?, ?)");
    query.addBindValue(values[0]);
    query.addBindValue(values[1]);
    query.addBindValue(values[2]);

    if (!query.exec())
    {
        QTextStream(stdout) << query.lastError().text();
    }

    db.close();
}
