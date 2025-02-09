#include "ParkingSpot.h"

#include <iostream>
using namespace std;

enum class ParkingSpotType
{
    SMALL,
    MEDIUM,
    LARGE
};

class ParkingSpot
{
    int id;
    bool is_empty;
    ParkingSpotType type;

public:
    ParkingSpot(){};

    ParkingSpot(int id, ParkingSpotType type) : id(id), type(type) {}

    int getId() { return id; }

    bool isEmpty()
    {
        return is_empty;
    }

    ParkingSpotType getType() { return type; }

    void parkVehicle()
    {
        this->is_empty = false;
    }

    void freeSpot()
    {
        this->is_empty = true;
    }
};