#include <iostream>

using namespace std;

const size_t N = 10000;

class Stack {
    public:
    int arr[N];
    int size = 0;

    size_t push(int x){
        if(size < N){
            arr[size] = x;
            size++;
            return size;
        } else {
            return -1;
        }
        }

    int pop(){
        if (size > 0){
            int x = arr[size-1];
            arr[size-1] = 0;
            size--;
             return x;
        } else {
            return -1;
        }
        }

    int top() const {
        if (size > 0) {
            return arr[size - 1];
        } else {
            return -1;
        }
    }

    bool empty() const {
        return size == 0;
    }

};

int main(){
    int N;
    cin>>N;
    Stack st;
    for(int i=0;i<N;i++){
        int persons_age;
        cin>>persons_age;
        while(!st.empty() && st.top()>persons_age){
            st.pop();
        }
        if(st.empty()){
            cout<<-1<<" ";
        }
        else{
            cout<<st.top()<<" ";
        }
        st.push(persons_age);
    }

    }