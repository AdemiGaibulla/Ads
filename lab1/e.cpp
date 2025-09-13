#include <iostream>

const size_t N = 10000;

class Queue {
    public:
    int arr[N];
    int size = 0;

    size_t push(int x){
        if(size < N){
            arr[size] = x;
            size++;
            return size;
        }
        else return -1;
    }
    
    int pop(){
        if(size > 0){
            int x = arr[0];
            arr[0] = 0;
            for(int i=0; i < size - 1; i++){
            arr[i] = arr[i+1];
        }
            size--;
            return x;
        }
        else return -1;
    }

    int front() const{
        if(size > 0){
            return arr[0];
        }
        else return -1;
    }

    bool empty() const{
        return size == 0;
    }
};

using namespace std;

int main(){
    Queue boris;
    Queue nursik;
    int round=0;
    int card1,card2;
    for(int i=0;i<5;i++){
        int n;
        cin>>n;
        boris.push(n);
    }
    for(int i=0;i<5;i++){
        int n;
        cin>>n;
        nursik.push(n);
    }
    for(int i=0;i<1000000;i++){
        if(boris.empty()){
            cout<<"Nursik "<<round;
            return 0;
        }
        else if(nursik.empty()){
            cout<<"Boris "<<round;
            return 0;
        }
        else if(boris.front()==9 && nursik.front()==0){
            card1 = boris.front();
            card2 = nursik.front();
            boris.pop();
            nursik.pop();
            nursik.push(card1);
            nursik.push(card2);
        }
        else if(nursik.front()==9 && boris.front()==0){
            card1 = nursik.front();
            card2 = boris.front();
            nursik.pop();
            boris.pop();
            boris.push(card2);
            boris.push(card1);
        }
        else if(nursik.front()>boris.front()){
            card1 = boris.front();
            card2 = nursik.front();
            boris.pop();
            nursik.pop();
            nursik.push(card1);
            nursik.push(card2);
        }
        else if(boris.front()>nursik.front()){
            card1 = nursik.front();
            card2 = boris.front();
            nursik.pop();
            boris.pop();
            boris.push(card2);
            boris.push(card1);
        }
        round++;
    }
    cout<<"blin nichya";
}