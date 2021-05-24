#include "scene.h"

Scene::Scene()
{
}

Scene::Scene(std::map<QString, CommandAction> _commands, QString _desk)
{
    commands = _commands;
    desk = _desk;
}

Scene::Scene(Scene const &scene)
{
    commands = scene.commands;
    desk = scene.desk;
}
