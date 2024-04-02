#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;
 
#pragma region
#define ll long long
#pragma endregion
ll bucket[10];
string getNext(string& current){ 
    // memset(bucket,0, sizeof(bucket)); 
    for(char& c: current){ 
        bucket[c-'0']++;
    }
    string nxt; 
    for(int i =0; i <= 9; i++){ 
        if(bucket[i]){
            nxt += to_string(bucket[i]);
            nxt += char(i+'0');
        }
        bucket[i] = 0;
    }
    return nxt;
    
}
void solve(string& start, string& target){ 
    string current = start; 
    int i = 1;
    while(current.size() <= 100){ 
        if(current == target){
            cout << i << endl; 
            return;
        }
        for(char& c: current){ 
            bucket[c-'0']++;
        }
        string nxt; 
        for(int i =0; i <= 9; i++){ 
            if(bucket[i]){
                nxt += to_string(bucket[i]);
                nxt += char(i+'0');
            }
            bucket[i] = 0;
        }
        if(nxt == current || i > 100){
            cout << "Does not appear" << endl;
            return;
        }
        swap(nxt,current);
        i += 1;
        // cout << current << endl;
    }
    cout << "I'm bored" << endl; 
}
void solve(){
    string start, target; 
    cin >> start >> target; 
    // cout << start << " " << target << endl;
    if(target.size() > 100){
        cout << "I'm bored" << endl; 
        return;
    }
    solve(start, target);
    
}   
 
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
}