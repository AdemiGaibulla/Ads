#include <iostream>

using namespace std;

const size_t N = 200000;

class Queue {
public:
    int arr[N];
    int head = 0;
    int tail = 0;

    void push(int x) {
        arr[tail++] = x;
    }

    int pop() {
        return arr[head++];
    }

    int front() {
        return arr[head];
    }

    bool empty() {
        return head == tail;
    }
};


int main(){
    int n;
    cin >> n;
    Queue q1,q2;
    for(int i=0;i<n;i++){
        char student;
        cin>>student;
        if(student=='S') q1.push(i);
        else q2.push(i);
    }
    while(!q1.empty() && !q2.empty()){
        int s = q1.front();
        int k = q2.front();
        if (s < k) {
            q1.pop();
            q2.pop();
            q1.push(s + n);
        } else {
            q1.pop();
            q2.pop();
            q2.push(k + n);
        }

    }
    if(q1.empty()) cout<<"KATSURAGI";
    else cout<<"SAKAYANAGI";
}