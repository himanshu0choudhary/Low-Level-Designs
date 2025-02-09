#include <iostream>
#include <random>
using namespace std;

class Dice
{
public:
    int getNextMoveCount()
    {
        random_device dev;
        mt19937 rng(dev());
        uniform_int_distribution<std::mt19937::result_type> dist6(1, 6);
        return dist6(rng);
    }

    void test(int cnt)
    {
        for (int i = 0; i < cnt; i++)
        {
            cout << getNextMoveCount() << endl;
        }
    }
};
