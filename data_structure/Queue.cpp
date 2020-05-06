#include <iostream>
#include <vector>
using namespace std;

class MyQueue {
private:
    // store elements
    vector<int> data;
    // a pointer to indicate the start position
    int p_start;
public:
    MyQueue(){p_start = 0;}
    /** insert an element into the queue, return true if the operation is successful */
        bool enQueue(int x) {
            data.push_back(x);
            return true;
        };
    /** delete an element from the queue. return true if the operation is successful */
        bool deQueue() {
            if (isEmpty()){
                return false;
            }
            p_start++;
            return true;
        };
        /** get the front item from queue */
        int Front() {
            return data[p_start];
        };
        /** checks whether the queue is empty or not */
        bool isEmpty(){
            return p_start >= data.size();
        }
};

class MyCirclarQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;
public:
    /** initialize your queue, set the size of the queue to be */
    MyCirclarQueue(int k){
        data.resize(k);
        head = -1;
        tail = -1;
        size = k;
    }

    /** insert an element into the circular queue. retuen true if the operation is successful. */
    bool enQueue(int value){
        if (isFull()){
            return false;
        }
        if (isEmpty()){
            head = 0;
        }
        tail = (tail + 1) % size;
        data[tail] = value;
        return true;

    }

    /** delete an element from the circular queue. trturn true if the operation is successful.*/
    bool deQueue(){
        if (isEmpty()){
            return false;
        }
        if (head == tail){
            head = -1;
            tail = -1;
            return true;
        }
        head = (head + 1) % size;
        return true;
    }

    //** get the last item from the queue*/
    int Rear() {
        if (isEmpty()){
            return -1;
        }
        return data[tail];

    }

    //** get the front item from the queue*/
    int Front(){
        if (isEmpty()){
            return -1;
        }
        return data[head];
    }

    //** chech whether the circular queue is empty or not*/
    bool isEmpty(){
        return head == -1;
    }

    //** check whether the circular queue is full or not*/
    bool isFull(){
        return (tail + 1) % size == head;

    }

};

int main()
{
    //** test queue*/
    cout<<"testing queue"<<endl;
    MyQueue q;
    q.enQueue(5);
    q.enQueue(3);
    if (!q.isEmpty()){
        cout << q.Front() << endl;
    }
    q.deQueue();
    if (!q.isEmpty()){
        cout << q.Front() << endl;
    }
    q.deQueue();
    if (!q.isEmpty()){
        cout << q.Front() << endl;
    }

    //** test circular queue/
    cout<<"testing circular queue"<<endl;
    MyCirclarQueue q1(5);
    q1.enQueue(1);
    q1.enQueue(2);
    q1.enQueue(3);
    q1.enQueue(4);
    q1.enQueue(5);
    q1.enQueue(6);
    q1.deQueue();
    q1.enQueue(6);
    cout<<"q1 is full:"<<q1.isFull()<<endl;
    while(!q1.isEmpty()){
        cout<<q1.Front()<<endl;
        q1.deQueue();
    }
}
