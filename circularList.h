//
// Created by yusuf on 12/26/22.
//

#ifndef DSAPRO_CIRCULARLIST_H
#define DSAPRO_CIRCULARLIST_H
#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
class circularList{
public:
    int noElements = 0;
    //insert a new node in an empty list
    struct Node *insertInEmpty(struct Node *last, int new_data)
    {
        // if last is not null then list is not empty, so return
        if (last != NULL)
            return last;

        // allocate memory for node
        struct Node *temp = new Node;

        // Assign the data.
        temp -> data = new_data;
        last = temp;

        // Create the link.
        last->next = last;

        return last;
    }
//insert new node at the end of the list
    struct Node *insertAtEnd(struct Node *last, int new_data){
        //if list is empty then add the node by calling insertInEmpty
        if (last == NULL)
            return insertInEmpty(last, new_data);

        //else create a new node
        struct Node *temp = new Node;

        //assign data to new node
        temp -> data = new_data;
        temp -> next = last -> next;
        last -> next = temp;
        last = temp;
        noElements++;
        return last;
    }

//traverse the circular linked list
    string traverseList(struct Node *last) {
        string ans="";
        struct Node *p;

        // If list is empty, return.
        if (last == NULL) {
            return "Empty";
        }
        p = last -> next; // Point to the first Node in the list.

// Traverse the list starting from first node until first node is visited again

        do {
            ans+=to_string(p -> data);
            ans+= "==>";
            p = p -> next;
        } while(p != last->next);
        if(p == last->next)
            ans+=to_string( p -> data);
        return ans;
    }

//delete the node from the list
    void deleteNode(Node** head, int key){
        // If linked list is empty retun
        if (*head == NULL)
            return;

        // If the list contains only a single node,delete that node; list is empty
//        if((*head)->data==key && (*head)->next==*head) {
//            free(*head);
//        }
        Node *last=*head,*d;

// If key is the head
        if((*head)->data==key) {
            while(last->next!=*head) // Find the last node of the list
                last=last->next;

            // point last node to next of head or second node of the list
            last->next=(*head)->next;
            free(*head);
            *head=last->next;
        }

// end of list is reached or node to be deleted not there in the list
        while(last->next!=*head&&last->next->data!=key) {
            last=last->next;
        }
// node to be deleted is found, so free the memory and display the list
        if(last->next->data==key) {
            d=last->next;
            last->next=d->next;
            free(d);
            traverseList(last);
        }
        noElements--;
    }
};


#endif //DSAPRO_CIRCULARLIST_H
