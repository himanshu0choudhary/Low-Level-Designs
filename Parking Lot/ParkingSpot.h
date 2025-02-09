#pragma once

enum class ParkingSpotType;

class ParkingSpot
{
public:
    ParkingSpot();
    ParkingSpot(int id, ParkingSpotType type);

    int getId();

    bool isEmpty();

    ParkingSpotType getType();

    void parkVehicle();

    void freeSpot();
};