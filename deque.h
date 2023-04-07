//
// Created by yusuf on 12/29/22.
//

#ifndef DSAPRO_DEQUE_H
#define DSAPRO_DEQUE_H
#include<iostream>
using namespace std;
#define SIZE 10
class dequeue {
public:
    int a[20],f,r;
public:

    dequeue() {
        f=-1;
        r=-1;
    }
    void insertRear(int i) {
        if(r>=SIZE-1) {
            //cout<<"\n insertion is not possible, overflow!!!!";
        } else {
            if(f==-1) {
                f++;
                r++;
            } else {
                r=r+1;
            }
            a[r]=i;
            //cout<<"\nInserted item is"<<a[r];
        }
    }
    void insertFront(int i) {
        if(f==-1) {
            f=0;
            a[++r]=i;
            //cout<<"\n inserted element is:"<<i;
        } else if(f!=0) {
            a[--f]=i;
            //cout<<"\n inserted element is:"<<i;
        } else {
            //cout<<"\n insertion is not possible, overflow!!!";
        }
    }
    void deleteFront() {
        if(f==-1) {
           // cout<<"deletion is not possible::dequeue is empty";
            return;
        }
        else {
           // cout<<"the deleted element is:"<<a[f];
            if(f==r) {
                f=r=-1;
                return;
            } else
                f=f+1;
        }
    }
    void deleteRear() {
        if(f==-1) {
            //cout<<"deletion is not possible::dequeue is empty";
            return;
        }
        else {
            //cout<<"the deleted element is:"<<a[r];
            if(f==r) {
                f=r=-1;
            } else
                r=r-1;
        }
    }
    string display () {
        string ans="";
        if(f==-1) {
            //cout<<"Dequeue is empty";
        } else {
            for(int i=f;i<=r;i++) {
                ans=ans+" -> "+std::to_string(a[i]);         }
        }
        return ans;

    }

};
#endif //DSAPRO_DEQUE_H
