// Observer Design pattern

#include <bits/stdc++.h>
using namespace std;

class ISubscriber{
public:
    virtual void update() = 0;
    virtual ~ISubscriber(){};
};

class IChannel{
public:
    virtual void subscribe(ISubscriber*) = 0;
    virtual void unsubscribe(ISubscriber*) = 0;
    virtual void notify() = 0;
    virtual ~IChannel(){};
};

class Channel : public IChannel{
private:
    vector<ISubscriber*> observer;
    string newVideo;
    string channelName;
public:
    Channel(const string& name){
        channelName = name;
    }
    void subscribe(ISubscriber* sub) override {
        observer.push_back(sub);
    }
    void unsubscribe(ISubscriber* sub) override {
        for(int i = 0; i < observer.size(); i ++){
            if(observer[i] == sub){
                observer.erase(observer.begin() + i);
                return;
            }
        }
    }
    void notify() override {
        for(auto i : observer){
            i->update();
        }
    }
    void uploadVideo(const string& title){
        newVideo = title;
        cout << "Video Uploaded Successfully\n";
        notify();
    }
    string getVideo(){
        return "CheckOut new Video" + newVideo + "\n";
    }
};

class Subscriber : public ISubscriber{
private: 
    string name;
    Channel* channel;
public:
    Subscriber(const string& n, Channel* c){
        channel = c;
        name = n;
    }
    void update() override {
        cout << "Hey " << name <<" , " << channel->getVideo();
    }
};

int main() {
    Channel* ch = new Channel("TOM&JERRY");

    Subscriber* a = new Subscriber("NITN",ch);
    Subscriber* b = new Subscriber("PIYUSH",ch);

    ch->subscribe(a);
    ch->subscribe(b);

    ch->uploadVideo("CONSPIRACY THEORY");

    ch->unsubscribe(a);

    ch->uploadVideo("NEW VIDEO IS LIVE");
    return 0;
}
