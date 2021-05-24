#include "commandmanager.h"

CommandManager::CommandManager() {

}

CommandManager::CommandManager(DataContext* data) {
    for (auto i : data->scene->commands) {
        commands[i.first] = i.second;
    }
}

void CommandManager::readCommand(DataContext* context, QMainWindow* window, QString command) {
    if (commands.find(command) != commands.end()) {
        commands[command](context);
        updateCommands(context);
    }
}

void CommandManager::updateCommands(DataContext* context) {
    commands.clear();
    for (auto i : context->scene->commands) {
        commands[i.first] = i.second;
    }
}
