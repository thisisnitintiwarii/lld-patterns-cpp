// Factory Design pattern

#include <bits/stdc++.h>
using namespace std;

class Notification{
public: 
    virtual void send(const string& message) = 0;
};



class EmailNotification : public Notification{ 
public: 
    void send(const string& message) override { 
        cout << message <<"\n";
    }
};
class PushNotification : public Notification{
public:
    void send(const string& message) override {
        cout << message <<"\n";
    }
};
class SMSNotification : public Notification{
public:
    void send(const string& message) override {
     cout << message <<"\n";
     }
};




class NotificationCreator{
public:
    virtual Notification* createNotification() = 0;

    void send(const string& message){
        Notification* Notification = createNotification();
        Notification->send(message);
        delete Notification;
    }

    virtual ~NotificationCreator() {}
};

class EmailNotificationCreator : public NotificationCreator{
public:
    Notification* createNotification () override {
        return new EmailNotification();
    }
};
class SMSNotificationCreator : public NotificationCreator {
public:
    Notification* createNotification() override {
        return new SMSNotification();
    }
};
class PushNotificationCreator : public NotificationCreator {
public:
    Notification* createNotification() override {
        return new PushNotification();
    }
};


int main() {
    NotificationCreator* notify;
    notify = new EmailNotificationCreator();
    notify->send("This is an Email"); 

    return 0;
}
