//
// Created by yusuf on 12/13/22.
//

#ifndef DSAPRO_STACK_H
#define DSAPRO_STACK_H
#include <string>
class stack{
public:
    int stackSize=100;
    int top;
    int length;
    int st[100];
    stack(){ // without public it says that it is declared private
        top=-1;
        length=0;
    }
    bool isFull(){
        return top>=stackSize-1;
    }
    bool isEmpty(){
        return top==-1;
    }
    void push(int value){
        if(!isFull()){
            st[++top]=value;
            length++;
        }
    }
    void pop(){
        if(!isEmpty()){
            top--;
            length--;
        }
    }
    std::string peek(){
        if(!isEmpty()){
            return to_string(st[top]);
        }
        return "Empty";
    }
    std::string display(){
        std::string ans="";
        int index=top;
        while(index!=-1){

            ans+=std::to_string(st[index--])+" <- ";
        }
        return ans;
    }
};
#endif //DSAPRO_STACK_H