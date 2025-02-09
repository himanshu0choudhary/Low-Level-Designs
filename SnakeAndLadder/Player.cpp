#include <iostream>
#include <random>
using namespace std;

class Player
{
    int position;

public:
    Player()
    {
        this->position = 0;
    }

    int getPosition()
    {
        return position;
    }

    void setPosition(int position)
    {
        this->position = position;
    }
};
