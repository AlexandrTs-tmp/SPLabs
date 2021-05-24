#ifndef DATA_H
#define DATA_H

#include "datacontext.h"
#include <stdlib.h>

namespace Data {

struct Samples {
public:
    static std::map<QString, Scene> Events;
    static std::map<QString, Scene*> Scenes;

    static void Initialize() {

        std::map<QString, CommandAction>* prologue = new std::map<QString, CommandAction>();
        (*prologue)["eat"] = [](DataContext* context){
            context->hero->add(Hero::HP, 5);
            context->hero->add(Hero::MOOD, 5);
            context->hero->add(Hero::ENERGY, -10);

            context->scene = new Scene(*Scenes["day"]);
            context->scene->desk = "Вы съели мороженое.\n\n" + context->scene->desk;
        };
        (*prologue)["wait"] = [](DataContext* context){
            context->hero->add(Hero::HP, 1);
            context->hero->add(Hero::MOOD, -5);
            context->hero->add(Hero::ENERGY, 1);

            context->scene = new Scene(*Scenes["day"]);
            context->scene->desk = "Вы долго смотрели в потолок.\n\n" + context->scene->desk;
        };
        (*prologue)["play"] = [](DataContext* context){
            context->hero->add(Hero::HP, 0);
            context->hero->add(Hero::MOOD, 10);
            context->hero->add(Hero::ENERGY, -10);

            context->scene = new Scene(*Scenes["day"]);
            context->scene->desk = "Вы поиграли в покер. Вам не понравилось.\n\n" + context->scene->desk;
        };
        (*prologue)["sleep"] = [](DataContext* context){
            context->hero->add(Hero::HP, 10);
            context->hero->add(Hero::MOOD, -10);
            context->hero->add(Hero::ENERGY, 40);

            context->scene = new Scene(*Scenes["day"]);
            context->scene->desk = "Вы проснулись от кошмара. Вам снилось, что вы нашли работу.\n\n" + context->scene->desk;
        };

        std::map<QString, CommandAction>* day = new std::map<QString, CommandAction>();
        (*day)["eat"] = [](DataContext* context){
            context->hero->add(Hero::HP, 5);
            context->hero->add(Hero::MOOD, 5);
            context->hero->add(Hero::ENERGY, -10);

            context->scene = new Scene(*Scenes["evening"]);
            context->scene->desk = "Вы съели замечательный кусок чего-то, что валялось на полу.\n\n" + context->scene->desk;
        };
        (*day)["wait"] = [](DataContext* context){
            context->hero->add(Hero::HP, 1);
            context->hero->add(Hero::MOOD, -5);
            context->hero->add(Hero::ENERGY, 1);

            context->scene = new Scene(*Scenes["evening"]);
            context->scene->desk = "Вы долго смотрели в потолок.\n\n" + context->scene->desk;
        };
        (*day)["play"] = [](DataContext* context){
            context->hero->add(Hero::HP, 0);
            context->hero->add(Hero::MOOD, 10);
            context->hero->add(Hero::ENERGY, -10);

            context->scene = new Scene(*Scenes["evening"]);
            context->scene->desk = "Вы поиграли в какую-то онлайн РПГ, но не заработали ни копейки.\n\n" + context->scene->desk;
        };
        (*day)["sleep"] = [](DataContext* context){
            context->hero->add(Hero::HP, 10);
            context->hero->add(Hero::MOOD, -10);
            context->hero->add(Hero::ENERGY, 40);

            context->scene = new Scene(*Scenes["evening"]);
            context->scene->desk = "Вы проснулись и хотите спать.\n\n" + context->scene->desk;
        };


        std::map<QString, CommandAction>* evening = new std::map<QString, CommandAction>();
        (*evening)["eat"] = [](DataContext* context){
            context->hero->add(Hero::HP, 5);
            context->hero->add(Hero::MOOD, 5);
            context->hero->add(Hero::ENERGY, -10);

            context->scene = new Scene(*Scenes["night"]);
            context->scene->desk = "Вы съели замечательный кусок пиццы.\n\n" + context->scene->desk;
        };
        (*evening)["wait"] = [](DataContext* context){
            context->hero->add(Hero::HP, 1);
            context->hero->add(Hero::MOOD, -5);
            context->hero->add(Hero::ENERGY, 1);

            context->scene = new Scene(*Scenes["night"]);
            context->scene->desk = "Вы долго смотрели в потолок.\n\n" + context->scene->desk;
        };
        (*evening)["play"] = [](DataContext* context){
            context->hero->add(Hero::HP, 0);
            context->hero->add(Hero::MOOD, 10);
            context->hero->add(Hero::ENERGY, -10);

            context->scene = new Scene(*Scenes["night"]);
            context->scene->desk = "Вы поиграли в денди и остались довольны.\n\n" + context->scene->desk;
        };
        (*evening)["sleep"] = [](DataContext* context){
            context->hero->add(Hero::HP, 10);
            context->hero->add(Hero::MOOD, -10);
            context->hero->add(Hero::ENERGY, 40);

            context->scene = new Scene(*Scenes["night"]);
            context->scene->desk = "Вы проснулись, но чувствуете, будто и не спали.\n\n" + context->scene->desk;
        };

        std::map<QString, CommandAction>* night = new std::map<QString, CommandAction>();
        (*night)["eat"] = [](DataContext* context){
            context->hero->add(Hero::HP, 5);
            context->hero->add(Hero::MOOD, 5);
            context->hero->add(Hero::ENERGY, -10);

            context->scene = new Scene(*Scenes["day"]);
            context->scene->desk = "Вы съели замечательную пачку чипсов.\n\n" + context->scene->desk;
        };
        (*night)["park"] = [](DataContext* context){
            context->hero->add(Hero::HP, -10);
            context->hero->add(Hero::MOOD, -10);
            context->hero->add(Hero::ENERGY, -10);

            context->scene = new Scene(*Scenes["day"]);
            context->scene->desk = "Вы испугались своей двери и решили остаться дома.\n\n" + context->scene->desk;
        };
        (*night)["shop"] = [](DataContext* context){
            context->hero->add(Hero::HP, -10);
            context->hero->add(Hero::MOOD, -10);
            context->hero->add(Hero::ENERGY, -10);

            context->scene = new Scene(*Scenes["day"]);
            context->scene->desk = "Вы испугались своей двери и решили остаться дома.\n\n" + context->scene->desk;
        };
        (*night)["sleep"] = [](DataContext* context){
            context->hero->add(Hero::HP, 10);
            context->hero->add(Hero::MOOD, -10);
            context->hero->add(Hero::ENERGY, 40);

            context->scene = new Scene(*Scenes["day"]);
            context->scene->desk = "Вы крепко поспали. Вам снилось, как вы выходите из дома.\n\n" + context->scene->desk;
        };

        Scenes["prologue"] = new Scene(*prologue);
        Scenes["prologue"]->desk = "Вы - NEET. В последний раз вы разговаривали с людьми 4 года назад.\n"
                                   "Раз в неделю, поздно ночью, вы выходите в магазин за продуктами, стараясь ни с кем не видеться.\n"
                                   "Для поддержания своего тела в тонусе, время от времени, поздно ночью, вы выходите погулять в парк.\n\n"
                                   "Сегодня совершенно обычный день. Чем бы вам заняться?\n"
                                   "Поесть (eat)\n"
                                   "Поспать (sleep)\n"
                                   "Поиграть (play)\n"
                                   "Подождать (wait)\n";
        Scenes["day"] = new Scene(*day);
        Scenes["day"]->desk = "Наступил день.\n"
                              "Что будете делать теперь?\n\n"
                              "Поесть (eat)\n"
                              "Поспать (sleep)\n"
                              "Поиграть (play)\n"
                              "Подождать (wait)\n";
        Scenes["evening"] = new Scene(*evening);
        Scenes["evening"]->desk = "Наступил вечер.\n"
                                  "Что будете делать теперь?\n\n"
                                  "Поесть (eat)\n"
                                  "Поспать (sleep)\n"
                                  "Поиграть (play)\n"
                                  "Подождать (wait)\n";

        Scenes["night"] = new Scene(*night);
        Scenes["night"]->desk = "Наступила ночь.\n"
                                "Что будете делать теперь?\n\n"
                                "Поесть (eat)\n"
                                "Поспать (sleep)\n"
                                "Пойти в магазин (shop)\n"
                                "Погулять в парке (park)\n";

    }
};
};
#endif // DATA_H
