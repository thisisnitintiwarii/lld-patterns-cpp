#include <bits/stdc++.h>
using namespace std;

// Design  Elevator System

enum Direction{
    UP,
    DOWN,
    IDLE
};

class Request{
public:
    int floorNumber;
    Direction dir;

    Request(int floorNumber, Direction dir) : floorNumber(floorNumber), dir(dir){};
};

class Elevator{
public:
    int id;
    int floorNumber;
    Direction dir;
    priority_queue<int, vector<int>, greater<int>> up;
    priority_queue<int> down;

    Elevator(int id){
        floorNumber = 0;
        this->id = id;
        dir = IDLE;
    }

    void addRequest(int floor){
        if(floor > floorNumber){
            up.push(floor);
        }else{
            down.push(floor);
        }
    }

    void move(){
        while(up.size()){
            dir = UP;
            int nextFloor = up.top();
            floorNumber = nextFloor;
            up.pop();
            cout << "Next stop is : " << nextFloor<<"\n";
        }

        while(down.size()){
            dir = DOWN;
            int nextFloor = down.top();
            floorNumber = nextFloor;
            down.pop();
            cout << "Next stop is : " << nextFloor<<"\n";
        }
        dir = IDLE;
    }
};

class ElevatorSchedular{
public:
    Elevator* selectElevator(vector<Elevator*>& elevators, Request& req){
        int floor = req.floorNumber;
        Elevator* ele = nullptr;
        int dis = INT_MAX;

        for(auto &it : elevators){
            int curr = abs(floor - it->floorNumber);
            if(curr < dis){
                dis = curr;
                ele = it;
            }
        }
        return ele;
    }
};

class ElevatorSystem{
public:
    vector<Elevator*> elevators;
    ElevatorSchedular es;

    ElevatorSystem(int n){
        for(int i = 0; i < n; i ++){
            elevators.push_back(new Elevator(i));
        }
    }

    void submitRequest(Request req){
        Elevator* el = es.selectElevator(elevators,req);
        cout << "Request assigned to Elevator " << el->id << endl;
        el->addRequest(req.floorNumber);
        el->move();
    } 

};

void solve(){

    ElevatorSystem es(8);
    es.submitRequest(Request(7,UP));
    es.submitRequest(Request(3,DOWN));

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