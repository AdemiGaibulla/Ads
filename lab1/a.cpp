#include <iostream>

using namespace std;

const size_t N=10000;

class Deque{
    public:
    int arr[N];
    int size =0;

    size_t push_front(int x){
        if(size < N){
            for(int i=size; i>0; i--){
                arr[i] = arr[i-1];
            }
            arr[0] = x;
            size++;
            return size;
        }
        else return -1;
    }

    size_t push_back(int x){
        if(size < N){
            arr[size] = x;
            size++;
            return size;
        }
        else return -1;
    }

    int pop_front(){
        if (size > 0){
            int x = arr[0];
            arr[0]=0;
            for(int i=0; i<size-1; i++){
                arr[i] = arr[i+1];
            }
            size--;
            return x;
        }
        else return -1;
    }
    
    int pop_back(){
        if (size > 0){
            int x = arr[size-1];
            arr[size-1]=0;
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

    int back() const{
        if(size > 0){
            return arr[size-1];
        }
        else return -1;
    }

    int* begin() {
        return arr; 
    }

    int* end() {
        return arr + size;
    }

    const int* begin() const {
        return arr;
    }
    
    const int* end() const {
        return arr + size;
    }

};

int main(){
    int T,n;
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>n;
        Deque d;
        for(int j=n; j>0; j--){
            d.push_front(j);
                for (int k=0; k<j; k++){
                    int last = d.back();
                    d.pop_back();
                    d.push_front(last); 
                }
        }
        for(int el : d){
            cout<<el<<" ";
        }
        cout<<endl;
    }
    return 0;
}