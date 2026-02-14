//Design VendingMachine  ->  State design Pattern

#include <bits/stdc++.h>
using namespace std;

class VendingMachine;


class State {
public: 
    virtual void selectProduct(VendingMachine* vm, int productId) = 0;
    virtual void insertMoney(VendingMachine* vm,int amount) = 0;
    virtual void dispense(VendingMachine* vm) = 0;
    virtual ~State() {}
};

class Product{
public:
    string name;
    int id;
    int price;
    int quantity;

    Product(){};
    Product(string n, int id, int p, int q) : name(n), id(id), price(p), quantity(q){};
};


// State Declaration to avoid forward decleration problem and using this new keyword


class IdleState : public State {
public:
    void selectProduct(VendingMachine* vm, int productId) override;
    void insertMoney(VendingMachine* vm, int amount) override;
    void dispense(VendingMachine* vm) override;
};

class HasMoneyState : public State {
public:
    void selectProduct(VendingMachine* vm, int productId) override;
    void insertMoney(VendingMachine* vm, int amount) override;
    void dispense(VendingMachine* vm) override;
};

class DispenseState : public State {
public:
    void selectProduct(VendingMachine* vm, int productId) override;
    void insertMoney(VendingMachine* vm, int amount) override;
    void dispense(VendingMachine* vm) override;
};



class VendingMachine{

public:
    State* currentState;
    map<int,Product> products;
    int balance;
    int selectedProduct;

    VendingMachine(){
        balance = 0;
        selectedProduct = -1;
        currentState = new IdleState();
    }


    void addProduct(string name, int id, int price, int quantity){
        products[id] = Product(name,id,price,quantity);
    }

    void setState(State* s){
        currentState = s;
    }

    void insertMoney(int amount){
        currentState->insertMoney(this,amount);
    }

    void selectProduct(int productId){
        currentState->selectProduct(this,productId);
    }

    void dispense(){
        currentState->dispense(this);
    }
};



// Idle state override functions

void IdleState::selectProduct(VendingMachine* vm, int productId){
    if(vm->products.count(productId) == 0){
        cout << "Invalid Product ID";
        return;
    }

    vm->selectedProduct = productId;

    if(vm->products[vm->selectedProduct].quantity <= 0){
        cout << "Item is out of stock\n";
        vm->setState(new IdleState());
        return;
    }

    cout << vm->products[vm->selectedProduct].name <<" is selected \n";
    cout << vm->products[vm->selectedProduct].price <<" is price \n";

    vm->setState(new HasMoneyState());
}

void IdleState::insertMoney(VendingMachine* vm, int amount) {
    cout << "Select product first.\n";
}

void IdleState::dispense(VendingMachine* vm) {
    cout << "Select product first.\n";
}





// HashMoney state override functions

void HasMoneyState::selectProduct(VendingMachine* vm, int productId) {
    cout << "Product already selected.\n";
}

void HasMoneyState::insertMoney(VendingMachine* vm, int amount) {
    vm->balance += amount;
    Product&p = vm->products[vm->selectedProduct];
    if(vm->balance >= p.price){
        vm->setState(new DispenseState());
    }
    cout << "Money inserted: " << amount << endl;
}

void HasMoneyState::dispense(VendingMachine* vm){
    cout << "Please insert the money First";
} 



// HashMoney state override functions


void DispenseState::selectProduct(VendingMachine* vm, int productId) {
    cout << "Dispensing in progress.\n";
}

void DispenseState::insertMoney(VendingMachine* vm, int amount) {
    cout << "Dispensing in progress.\n";
}

void DispenseState::dispense(VendingMachine* vm){
    Product&p = vm->products[vm->selectedProduct];

    p.quantity--;
    vm->balance -= p.price;

    cout << "Dispensed: " << p.name << endl;
    cout << "Change returned: " << vm->balance << endl;

    vm->setState(new IdleState());

}



int main(){

    VendingMachine vm;

    vm.addProduct("slice",9,40,5);
    vm.addProduct("pepsi",8,50,5);
    vm.addProduct("coke",7,60,5);


    vm.selectProduct(9);
    vm.insertMoney(50);
    vm.dispense();

    return 0;
}