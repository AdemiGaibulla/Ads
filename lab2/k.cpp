#include <iostream>
#include <deque>
#include <map>

using namespace std;

int main(){
    int test_cases;
    cin>>test_cases;
    for(int i=0; i<test_cases; i++){
        int n;
        cin>>n;
        deque<char> dq;
        map<char, int> frequency;
        for(int i=0; i<n; i++){
            char letter;
            cin>>letter;
            frequency[letter]++;
            dq.push_back(letter); 
            while (!dq.empty() && frequency[dq.front()] > 1) {
                dq.pop_front();
            }
            if (dq.empty()) cout << -1 << " ";
            else cout << dq.front() << " ";
        }
        cout<<endl;
    }

}