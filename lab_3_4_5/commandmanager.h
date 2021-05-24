#ifndef COMMANDREADER_H
#define COMMANDREADER_H

#include <map>
#include "data.h"

class CommandManager
{
private:
    std::map<QString, CommandAction> commands;
public:
    CommandManager();
    CommandManager(DataContext*);
    void readCommand(DataContext*, QMainWindow*, QString);
    void updateCommands(DataContext* context);
};

#endif // COMMANDREADER_H
