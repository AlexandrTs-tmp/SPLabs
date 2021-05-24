#include "datacontext.h"

DataContext::DataContext(Scene* scene)
{
    ContextRepository* rep = new ContextRepository();

    updates = 0;
    hero = new Hero(rep->selectByIndex(Hero::HERO_DEFAULT_INDEX));
    // hero = new Hero();
    this->scene = scene;
}
