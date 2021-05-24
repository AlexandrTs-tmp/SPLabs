#ifndef HERO_H
#define HERO_H

class Hero
{
private:
    int parms[3];
public:
    static const int HERO_DEFAULT_INDEX = 1;
    static const int HP = 0;
    static const int ENERGY = 1;
    static const int MOOD = 2;

    Hero(int* _parms = new int[3] {100, 100, 100});
    void add(int parm, int value);
    bool isAlive();
    int& operator[](int parm);
};

#endif // HERO_H
