#ifndef SCENE_H
#define SCENE_H

#include <QString>
#include <list>
#include <QMainWindow>
#include <QMessageBox>

class DataContext;
typedef void (*CommandAction)(DataContext*);

struct Scene
{
    std::map<QString, CommandAction> commands;
    QString desk;

    Scene();
    Scene(Scene const &scene);
    Scene(std::map<QString, CommandAction> _commands, QString _desk = "test");
    Scene& operator=(Scene scene) {
        commands = scene.commands;
        return *this;
    }
};

#endif // SCENE_H
