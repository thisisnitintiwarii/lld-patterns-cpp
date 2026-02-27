// Adapter Design pattern

#include <bits/stdc++.h>
using namespace std;

// Interface 
class MobileCharger{
public:
    virtual int getVoltage5() = 0;
};

// Third Party class / Adaptee class
class WallSocket{
public:
    int getVoltage220(){
        return 220;
    }
};

// Adaptor Class
class VoltageAdaptor : public MobileCharger{
private:
    WallSocket ws;
public:
    int getVoltage5() override {
        cout << "Converting the 5V supply to 220V supply\n";
        int volt = ws.getVoltage220();
        return volt/44;
    }
};

int main() {

    MobileCharger* mc = new VoltageAdaptor();
    cout << mc->getVoltage5() <<"\n";

    return 0;
}
