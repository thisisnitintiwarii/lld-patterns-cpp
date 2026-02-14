// Design a HashMap 

#include <bits/stdc++.h>
using namespace std;

template <typename K, typename V>
class HashMap{
private:
    struct Node{
        K key;
        V value;
        Node* next;

        Node(K k, V v) : key(k), value(v), next(nullptr){}; 
    };

    vector<Node*> bucket;
    int capacity;
    int currSize;
    double loadFactor = 0.75;


    int hashFunction(K key){
        return hash<K>{}(key)%capacity;
    }

    void rehash(){

        vector<Node*> oldBucket = bucket;
        bucket.clear();
        capacity = capacity * 2;
        bucket.resize(capacity,nullptr);
        currSize = 0;

        for(int i = 0; i < oldBucket.size(); i ++){

            Node* head = oldBucket[i];

            while(head){
                Node* temp = head;
                put(head->key,head->value);
                head = head->next;
                delete temp;
            }

        }

    }


public:

    HashMap(){
        capacity = 4;
        currSize = 0;
        bucket.resize(capacity, nullptr);
    }

    void put(K key, V value){

        int index = hashFunction(key);

        // check is it alread present

        Node* head = bucket[index];
        while(head){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        // insert a new Node
        head = bucket[index];
        Node* newNode = new Node(key,value);
        newNode->next = head;
        bucket[index] = newNode;
        currSize++;

        // if load factor threshhold excede then rehash

        if((double)currSize / capacity > loadFactor){
            rehash();
        }
    }


    V get(K key){
        int index = hashFunction(key);

        Node* head = bucket[index];
        while(head){
            if(head->key == key){
                return head->value;
            }
            head = head->next;
        }
        throw runtime_error("Key not found");
    }

    void remove(K key){
        int index = hashFunction(key);

        Node* head = bucket[index];
        if(!head) return;
        if(head->key == key){
            bucket[index] = head->next;
            currSize--;
            delete head;
            return;
        } 
        Node* prev = head;
        head = head->next;
        while(head){
            if(head->key == key){
                prev->next = head->next;
                currSize--;
                delete head;
                return;
            }
            prev = head;
            head = head->next;
        }
    }


    bool containsKey(K key) {
        int index = hashFunction(key);
        Node* head = bucket[index];

        while (head) {
            if (head->key == key) return true;
            head = head->next;
        }
        return false;
    }

    int size(){
        return currSize;
    }
};



int main() {

    HashMap<int,string> map;

    map.put(1, "One");
    map.put(2, "Two");
    map.put(3, "Three");

    cout << map.get(1) <<"\n";
    cout << map.size() <<"\n";

    return 0;
}
