#include <iostream>
#include <random>
#include <map>
#include <set>
using namespace std;

class Board
{
    int size;

    map<int, int> ladderBottomToTop, snakeMouthToTail;

    set<int> ladderEnds, snakeEnds;

public:
    Board() {}

    Board(int size)
    {
        this->size = size;
    }

    int getWinnerPosition()
    {
        return size * size;
    }

    void addSnake(int mouthLocation, int tailLocation)
    {
        if (tailLocation >= mouthLocation)
        {
            throw invalid_argument("mouthLocation: " + to_string(mouthLocation) + "and tailLocation: " + to_string(tailLocation) + " is invalid");
        }

        if (mouthLocation <= 0 or mouthLocation > size * size or snakeMouthToTail.find(mouthLocation) != snakeMouthToTail.end() or ladderEnds.find(mouthLocation) != ladderEnds.end())
        {
            throw invalid_argument("mouthLocation: " + to_string(mouthLocation) + " is invalid");
        }

        if (tailLocation <= 0 or tailLocation > size * size or ladderEnds.find(tailLocation) != ladderEnds.end())
        {
            throw invalid_argument("tailLocation: " + to_string(tailLocation) + " is invalid");
        }

        snakeEnds.insert(mouthLocation);
        snakeEnds.insert(tailLocation);

        snakeMouthToTail[mouthLocation] = tailLocation;
    }

    void addLadder(int bottom, int top)
    {
        if (bottom >= top)
        {
            throw invalid_argument("bottom: " + to_string(bottom) + "and top: " + to_string(top) + " is invalid");
        }

        if (bottom <= 0 or bottom > size * size or ladderBottomToTop.find(bottom) != ladderBottomToTop.end() or snakeEnds.find(bottom) != snakeEnds.end())
        {
            throw invalid_argument("bottom: " + to_string(bottom) + " is invalid");
        }

        if (top <= 0 or top > size * size or snakeEnds.find(top) != snakeEnds.end())
        {
            throw invalid_argument("top: " + to_string(top) + " is invalid");
        }

        ladderEnds.insert(bottom);
        ladderEnds.insert(top);

        ladderBottomToTop[bottom] = top;
    }

    int getNextPosition(int currentPoition, int stepsCount)
    {
        if (currentPoition + stepsCount > size * size)
            return -1;

        currentPoition += stepsCount;

        if (ladderBottomToTop.find(currentPoition) != ladderBottomToTop.end())
        {
            currentPoition = ladderBottomToTop[currentPoition];
        }

        if (snakeMouthToTail.find(currentPoition) != snakeMouthToTail.end())
        {
            currentPoition = snakeMouthToTail[currentPoition];
        }

        return currentPoition;
    }
};
