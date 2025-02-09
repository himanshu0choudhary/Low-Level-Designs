#pragma once

#include "ParkingSpot.h"
#include <string>

class Vehicle
{
public:
    Vehicle();
    Vehicle(int id, std::string number_plate, ParkingSpotType type);

    int getId();
    std::string getNumberPlate();
    ParkingSpotType getType();
};