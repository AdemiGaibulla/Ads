#include <iostream>
#include <cctype>

using namespace std;

int main(){
    string first,second;
    cin>>first>>second;
    string first_result,second_result;
    for(int i=0;i<first.size();i++){
        if(isalpha(first[i])){
            first_result+=first[i];
        }
        else{
            first_result.pop_back();
        }
    }
    for(int i=0;i<second.size();i++){
        if(isalpha(second[i])){
            second_result+=second[i];
        }
        else{
            second_result.pop_back();
        }
    }
    if(first_result==second_result){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

}