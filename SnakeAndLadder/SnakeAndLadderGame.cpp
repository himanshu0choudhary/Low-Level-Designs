#include "./Board.cpp"
#include "./Dice.cpp"
#include "./GameSettings.cpp"
#include "./Player.cpp"

#include <iostream>
#include <vector>

using namespace std;

class SnakeAndLadderGame
{
    Board board;
    Dice dice;
    GameSettings gameSettings;
    vector<Player> players;

    int turn;

public:
    SnakeAndLadderGame(GameSettings gameSettings, Dice dice)
    {
        this->gameSettings = gameSettings;
        this->board = Board(gameSettings.getBoardSize());
        this->dice = dice;
        this->players = vector<Player>(gameSettings.getNumberOfPlayers());

        turn = 0;
    }

    void printPlayerLocations()
    {
        for (int i = 0; i < players.size(); i++)
        {
            printf("Player %d is on %d\n", i, players[i].getPosition());
        }
    }

    void makeMove()
    {
        int steps = dice.getNextMoveCount();
        int nextPosition = board.getNextPosition(players[turn].getPosition(), steps);

        if (nextPosition != -1)
            players[turn].setPosition(nextPosition);

        if (nextPosition == board.getWinnerPosition())
        {
            end();
        }

        turn = (turn + 1) % players.size();
    }

    void end()
    {
        printf("Player %d wins the game", turn);
        exit(0);
    }
};

int main()
{
    GameSettings gameSettings = GameSettings(2, 10);
    Dice dice = Dice();

    SnakeAndLadderGame game = SnakeAndLadderGame(gameSettings, dice);

    while (1)
    {
        game.makeMove();
        game.printPlayerLocations();
        cout << "Press enter to continue" << endl;
        cin.get();
    }
}