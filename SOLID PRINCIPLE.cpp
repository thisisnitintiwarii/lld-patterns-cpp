#include <bits/stdc++.h>
using namespace std;

// SINGLE RESPONSIBILITY PRINCIPLE

class Invoice{
private :
    int amount;

public:
    Invoice(int amt) : amount(amt){};

    int getAmount(){
        return amount;
    }
};

class InvoicePrinter{
    Invoice* invoice;
public:
    InvoicePrinter(Invoice* invoice) : invoice(invoice){};
    void print(){
        cout << invoice->getAmount() <<"\n";
    }
};

class SaveToDataBase{
    Invoice* invoice;
public:
    SaveToDataBase(Invoice* invoice) : invoice(invoice){};
    void saveToDB(){
        cout <<"Data saved in DB successfully\n";
    }
};
void solve(){
    Invoice invoice(900);

    InvoicePrinter printer(&invoice);
    SaveToDataBase save(&invoice);
    printer.print();
    save.saveToDB();
};


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t=1;
    while (t--) {
        solve();
    }
}


// OPEN CLOSED PRINCIPLE

#include <bits/stdc++.h>
using namespace std;

class Shape{
public:
    virtual double area() = 0;
};

class Rectangle : public Shape{
    int l,b;
public:
    Rectangle(int l, int b) : l(l) , b(b){};
    double area() override {
        double ans = l * b;
        return ans;
    }
};

class Circle : public Shape {
private:
    int radius;

public:
    Circle(int r) {
        radius = r;
    }

    double area() override {
        return 3.14 * radius * radius;
    }
};


void solve(){
    Shape* rc = new Rectangle(3,4);
    Shape* c = new Circle(3);
    cout << rc->area() <<"\n";
    cout << c->area() << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t=1;
    while (t--) {
        solve();
    }
}


// INTERFACE SEGREATION PRINCIPLE

#include <bits/stdc++.h>
using namespace std;

class Printer{
public:
    virtual void print() = 0;
};
class Scanner{
public:
    virtual void scan() = 0;
};

class MulitFunctionPrinter: public Printer,public Scanner{
public:
    void print() override {
        cout << "Print the pages\n";
    }
    void scan() override {
        cout << "Scan the pages \n";
    }
};
class BasicPrinter : public Printer {
public:
    void print() override {
        cout << "Printing..." << endl;
    }
};

void solve(){
    MulitFunctionPrinter mfp;
    BasicPrinter bp;
    mfp.scan();
    mfp.print();

    bp.print();


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t=1;
    while (t--) {
        solve();
    }
}


// DEPENDENCY SEGREGATION PRINCIPLE

#include <bits/stdc++.h>
using namespace std;

class Database{
public:
    virtual void connect() = 0;
};
class MongoDB: public Database{
public:
    void connect() override {
        cout << "Connect to the MongoBD database\n";
    }
};
class MySQL : public Database{
public:
    void connect() override {
        cout << "Connect to the MY Sql database\n";
    }
};

class UserService{
    Database* db;
public:
    UserService(Database* db) : db(db){};
    
    void DBconnection(){
        db->connect();
    }
};

void solve(){

    Database* db = new MySQL();
    UserService service(db);

    service.DBconnection();

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t=1;
    while (t--) {
        solve();
    }
}