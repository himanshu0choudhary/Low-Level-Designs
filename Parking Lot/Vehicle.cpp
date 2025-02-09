#include "Vehicle.h"
#include "ParkingSpot.h"

#include <iostream>

using namespace std;

class Vehicle
{
    int id;
    string number_plate;
    ParkingSpotType type;

public:
    Vehicle(){};
    Vehicle(int id, string number_plate, ParkingSpotType type) : id(id), number_plate(number_plate), type(type) {}

    int getId() { return id; }

    string getNumberPlate() { return number_plate; }

    ParkingSpotType getType() { return type; }
};