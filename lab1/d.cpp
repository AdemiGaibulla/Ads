#include <iostream>

using namespace std;

const size_t N=10000;

class Stack{
    public:
    char arr[N];
    int size = 0;

    bool push(char x){
        if(size < N){
            arr[size] = x;
            size++;
            return true;
        }
        else return false;
    }

    char pop(){
        if(size > 0){
            char x = arr[size-1];
            arr[size-1]=0;
            size--;
            return x;
        }
        else return '\0';
    }

    char top() const{
        if(size > 0){
            return arr[size-1];
        }
        else return '\0';
    }

    bool empty() const{
        return size ==0;
    }
};

int main(){
    string s;
    cin>>s;
    Stack st;

    for(int i=0;i<s.size();i++){
        if(st.empty()) st.push(s[i]);
        else if(st.top()==s[i]) st.pop();
        else if(st.top()!=s[i]) st.push(s[i]);
    }
    if(st.empty()) cout<<"YES";
    else cout<<"NO";
}