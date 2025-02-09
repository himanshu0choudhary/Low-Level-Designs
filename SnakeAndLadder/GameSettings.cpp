#include <iostream>
#include <random>
using namespace std;

class GameSettings
{
    int numberOfPlayers;
    int boardSize;

public:
    GameSettings() {}

    GameSettings(int numberOfPlayers, int boardSize)
    {
        this->numberOfPlayers = numberOfPlayers;
        this->boardSize = boardSize;
    }

    int getNumberOfPlayers()
    {
        return numberOfPlayers;
    }

    int getBoardSize()
    {
        return boardSize;
    }

    void setNumberOfPlayers(int numberOfPlayers)
    {
        this->numberOfPlayers = numberOfPlayers;
    }

    void setBoardSize(int boardSize)
    {
        this->boardSize = boardSize;
    }
};
