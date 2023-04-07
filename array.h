//
// Created by yusuf on 12/26/22.
//

#ifndef DSAPRO_ARRAY_H
#define DSAPRO_ARRAY_H
# include <iostream>
#include <cstring>

using namespace std;
class Array {
public :
    int size;
    int * items;
    int length;

    Array(int nSize){
        size=nSize;
        items=new int[size];
        length=0;
    }

    void Fill(string f) {
        if (length < size) {
        items[length] = stoi(f);
        length++;
    }
    }
    
    void delet(string f){
        if(length!=0 and stoi(f)<=length){
            for(int i=stoi(f);i<length-1;i++){
                items[i]=items[i+1];
            }
            length--;
        }
    }

    std::string sort(){
        std::string ans="";
        int tempArray[length];
        for(int i=0;i<length;i++){
            tempArray[i]=items[i];
        }
        std::sort(tempArray, tempArray + length);
        for(int i=0;i<length;i++){
            ans+=std::to_string(tempArray[i])+" ";
        }
        return ans;
    }

    void Enlarge() {
        size_t newSize = size * 2;
        int* newArr = new int[newSize];
        std::memcpy( newArr, items, size * sizeof(int) );
        size = newSize;
        delete [] items;
        items = newArr;
    }

    string display (){
        string ans="";
        for (int i=0;i<length ;i++){
            ans=ans+ " -> "+to_string(items[i]);
        }
        return ans;
    }


};
#endif //DSAPRO_ARRAY_H
