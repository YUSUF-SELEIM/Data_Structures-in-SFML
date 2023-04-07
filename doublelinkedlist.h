#include<iostream>
using namespace std;


class Nodee {
public:
    int data;
    Nodee *next;
    Nodee *prev;
public:
    Nodee(int value) {
        data = value;
        next = prev = nullptr;
    }
};
class doublelinkedlist{
public :
    Nodee* head;
    Nodee* tail;
    int size;
    Nodee *prev;

    void insert_front(int value){
        Nodee* temp = new Nodee(value);
        if (head == NULL) head = tail = temp;
        else {
            head->prev = temp; temp->next = head; head = temp; } size++;
    }

    void insert_back(int value){
        Nodee* temp = new Nodee(value);
        if (tail == NULL) head = tail = temp;
        else { tail->next = temp; temp->prev = tail; tail = temp; } size++;
    }
    int delete_front(){
        if (!is_empty()) {
            Nodee* temp = head;
            if (head == tail) {
                tail = NULL; }
            int delValue = temp->data;
            head = head->next;
            delete temp;
            size--;
            return delValue; }
        return 0;
    }


    int delete_back(){
        if (!is_empty()) { Nodee* temp = tail;
            if (head == tail) { head = NULL;
            }
            int delValue = temp->data; tail->next = NULL; tail = tail->prev; delete temp; size--; return delValue;
        } return 0;
    }
    bool is_empty(){
        if (size <= 0) { return true;
        } return false;}


    string display(){
        string ans="";
        Nodee* temp = head;
        while (temp != NULL) {


            ans=ans+ " -> "+ to_string(temp->data) ;

            temp = temp->next;

        }
        return ans ;
    }

    int length(){
        return size;
    }
};