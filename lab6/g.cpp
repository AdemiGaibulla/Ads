//find first and last nickname
#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    cin>>n;
    map<string,string> nicknames;
    for(int i=0;i<n;i++){
        string oldname,newname;
        cin>>oldname>>newname;
        bool a = false;
        for(auto& el : nicknames){
            if(oldname == el.second){
                a = true;
                el.second = newname;
            }
        }
        if(a == false){
            nicknames[oldname] = newname;
        }
    }
    cout<<nicknames.size()<<endl;
    for(auto el : nicknames){
        cout<<el.first<<" "<<el.second<<endl;
    }

}