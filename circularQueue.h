//
// Created by yusuf on 12/21/22.
//

#ifndef DSAPRO_CIRCULARQUEUE_H
#define DSAPRO_CIRCULARQUEUE_H

using namespace std;
#define SIZE 100

class circularQueue {
   private:
	int items[SIZE], front, rear;

   public:
    circularQueue() {
    front = -1;
    rear = -1;
  }
  // Check if the queue is full
  bool isFull() {
    if (front == 0 && rear == SIZE - 1) {
      return true;
    }
    if (front == rear + 1) {
      return true;
    }
    return false;
  }
  // Check if the queue is empty
  bool isEmpty() {
    if (front == -1)
      return true;
    else
      return false;
  }
  // Adding an element
  void enQueue(int element) {
    if (!isFull()) {
      if (front == -1) front = 0;
      rear = (rear + 1) % SIZE;
      items[rear] = element;
    }
  }
  // Removing an element
  int deQueue() {
    int element;
    if (!isEmpty()) {
      element = items[front];
      if (front == rear) {
        front = -1;
        rear = -1;
      }
      // Q has only one element,
      // so we reset the queue after deleting it.
      else {
        front = (front + 1) % SIZE;
      }
      return (element);
    }
    return(-1);
}



  std::string display() {
    // Function to display status of Circular Queue
    int i;
    string ans="";
    if (!isEmpty()) {
      for (i = front; i != rear; i = (i + 1) % SIZE){
        ans+=to_string(items[i])+"<-";
	  }
       ans+=to_string(items[i])+"<-";
      //cout << endl;
    }
    return ans;
  }
};
#endif //DSAPRO_CIRCULARQUEUE_H
