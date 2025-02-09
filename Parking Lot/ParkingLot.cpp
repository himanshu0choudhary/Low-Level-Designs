#include "ParkingSpot.h"
#include "Vehicle.h"

#include <iostream>
#include <map>

using namespace std;

class ParkingLot
{
    map<ParkingSpotType, map<int, ParkingSpot>> parking_spots_map;
    map<int, int> vehicle_to_parking_spot_map;
    map<int, Vehicle> parked_vehicle_map;

public:
    int getEmptySpot(ParkingSpotType type)
    {
        for (auto it : parking_spots_map[type])
        {
            if (it.second.isEmpty())
                return it.first;
        }

        return -1;
    }

    int parkVehicle(Vehicle vehicle)
    {
        int empty_spot = getEmptySpot(vehicle.getType());
        if (empty_spot == -1)
            return -1;

        parked_vehicle_map.insert_or_assign(vehicle.getId(), vehicle);

        vehicle_to_parking_spot_map.insert_or_assign(vehicle.getId(), empty_spot);

        parking_spots_map[vehicle.getType()][empty_spot].parkVehicle();

        return empty_spot;
    }

    void leaveVehicle(int id)
    {
        if (parked_vehicle_map.find(id) == parked_vehicle_map.end())
            return;

        Vehicle vehicle = parked_vehicle_map[id];
        parked_vehicle_map.erase(id);

        int parking_spot_id = vehicle_to_parking_spot_map[id];
        vehicle_to_parking_spot_map.erase(id);

        parking_spots_map[vehicle.getType()][parking_spot_id].freeSpot();
    }

    void addSpot(ParkingSpot spot){
        parking_spots_map[spot.getType()].insert_or_assign(spot.getId(), spot);
    }
};