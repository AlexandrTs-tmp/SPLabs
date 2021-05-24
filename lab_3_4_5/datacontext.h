#ifndef DATACONTEXT_H
#define DATACONTEXT_H

#include "scene.h"
#include "hero.h"
#include "contextrepository.h"

class DataContext
{
public:
    Scene* scene;
    Hero* hero;
    int updates;
    int id;
    DataContext(Scene* scene);
};

#endif // DATACONTEXT_H
