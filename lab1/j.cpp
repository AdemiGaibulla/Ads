#include <iostream>
#include <cctype>

using namespace std;

size_t const N = 10000;

class Deque{
    public:
    int arr[N];
    int size_of_arr=0;

    size_t push_front(int x){
        if(size_of_arr < N){
            for(int i=size_of_arr; i>0;i--){
                arr[i]=arr[i-1];
            }
            arr[0] = x;
            size_of_arr++;
            return size_of_arr;
        }
        else return -1;  
    }

    size_t push_back(int x){
        if(size_of_arr < N){
            arr[size_of_arr] = x;
            size_of_arr++;
            return size_of_arr;
        }
        else return -1;
    }

    int pop_front(){
        if(size_of_arr > 0){
            int x = arr[0];
            arr[0]=0;
            for(int i=0; i<size_of_arr-1 ;i++){
                arr[i] = arr[i+1];
            }
            size_of_arr--;
            return x;
        }
        else return -1;
    }

    int pop_back(){
        if(size_of_arr > 0){
            int x = arr[size_of_arr-1];
            arr[size_of_arr-1]=0;
            size_of_arr--;
            return x;
        }
        else return -1;
    }

    int front() const{
        if(size_of_arr > 0){
            return arr[0];
        }
        else return -1;
    }

    int back() const{
        if( size_of_arr> 0){
            return arr[size_of_arr-1];
        }
        else return -1;
    }

    bool empty(){
        return size_of_arr == 0;
    }

    int size(){
        return size_of_arr;
    }
};

int main(){
    string variable;
    Deque dq;
    string operation;
    while(cin>>variable){
        if (variable=="!") break;
        else if(variable=="*" && dq.empty()) cout<<"error"<<endl;
        else if(variable=="*" && !dq.empty() && dq.size()>1) {
            cout<<dq.front()+dq.back()<<endl;
            dq.pop_back();
            dq.pop_front();
        }
        else if(variable=="*" && !dq.empty() && dq.size()==1) {
            cout<<dq.front()+dq.back()<<endl;
            dq.pop_back();
        }
        else if(variable=="+") operation="+";
        else if(variable=="-") operation="-";
        else{
            if(operation=="+") dq.push_front(stoi(variable));
            else if(operation=="-") dq.push_back(stoi(variable));
        }
    }
}