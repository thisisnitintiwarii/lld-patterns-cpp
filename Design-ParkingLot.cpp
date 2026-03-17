#include <bits/stdc++.h>
using namespace std;

// Design  ParkingLot 
// Classes -> ParkingLot ParkingFloor ParkingSpot Ticket Vehicle

enum VehicleType{
    CAR,
    BIKE,
    HV
};

class Vehicle{
public:
    string plate;
    VehicleType type;

    Vehicle(string plate, VehicleType type): plate(plate), type(type){};
};

class ParkingSpot{
public:
    int id;
    bool isFree;
    VehicleType type;
    Vehicle* vehicle;

    ParkingSpot(int id, VehicleType type){
        this->id = id;
        this->type = type;
        this->vehicle = nullptr;
        isFree = true;
    }

    void assignSpot(Vehicle* vehicle){
        this->vehicle = vehicle;
        isFree = false;
    }

    void removeVehicle(){
        this->vehicle = nullptr;
        isFree = true;
    }
    bool availability(){
        return isFree;
    }

};

class ParkingFloor{
public:
    int floorNumber;
    vector<ParkingSpot*> spots;

    ParkingFloor(int floorNumber){
        this->floorNumber = floorNumber;
    }

    void addParkingSpots(ParkingSpot* spot){
        spots.push_back(spot);
    }

    ParkingSpot* findSpot(VehicleType type){
        for(auto spot: spots){
            if(spot->type == type && spot->isFree){
                return spot;
            }
        }
        return nullptr;
    }

};

class ParkingLot{
public:
    vector<ParkingFloor*> floors;

    ParkingLot(){

    }

    void addFloors(ParkingFloor* floor){
        floors.push_back(floor);
    }

    ParkingSpot* findSpot(Vehicle* vehicle){
        VehicleType type = vehicle->type;
        ParkingSpot* ps = nullptr;
        int floorCounter = 0;
        for(auto floor : floors){
            ps = floor->findSpot(type);
            if(ps){
                ps->assignSpot(vehicle);
                cout << "spot is available for this vehicle\n";
                cout << ps->id <<' '<<floorCounter<<"\n";
                return ps;
            }
            floorCounter ++;
        }

        cout << "No spot is available for this vehicle\n";
        return nullptr;
    }
};

class Ticket{
public:
    int id;
    int charges;
    time_t parkingTime;
    VehicleType type;
    
    Ticket(int id,VehicleType type){
        this->id = id;
        this->type = type;
        parkingTime = time(0);
    }
};



void solve(){

    ParkingLot parking;
    ParkingFloor* pf = new ParkingFloor(0);
    ParkingFloor* pff = new ParkingFloor(1);
    ParkingFloor* pfff = new ParkingFloor(2);
    ParkingSpot* c = new ParkingSpot(0,CAR);
    ParkingSpot* b = new ParkingSpot(3,BIKE);
    ParkingSpot* a = new ParkingSpot(0,HV);

    pf->addParkingSpots(c);
    pff->addParkingSpots(b);
    pfff->addParkingSpots(a);
    parking.addFloors(pf);
    parking.addFloors(pff);
    parking.addFloors(pfff);

    Vehicle* vec = new Vehicle("0349",HV);
    Vehicle* v = new Vehicle("0399",BIKE);

    parking.findSpot(vec);
    parking.findSpot(v);

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    // cin >> t;
    t=1;
    while (t--) {
        solve();
    }
}