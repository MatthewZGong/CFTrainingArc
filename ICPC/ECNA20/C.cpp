#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
#pragma endregion

map<string, string> trades;
set<string> visited;
const int NINF = -1000000;

int find_cycle(const string& s){ 
    // cout << s << endl;
    if(visited.count(s)){ 
        return 0;
    }
    if(trades.count(s)){ 
        visited.insert(s);
        return find_cycle(trades[s])+1;
    }else{ 
        return NINF;
    }
}
void solve(){
    int n; 
    cin >> n;
    for(int i =0; i < n; i++){ 
        string name, has, wants; 
        cin >> name >> has >> wants; 
        trades[has] = wants;
    }
    int res = 0;
    for(auto& [has, wants]: trades){ 
        if(!visited.count(has)){ 
            res = max(find_cycle(has), res);
        }
    } 
    if(res == 0){ 
        cout << "No trades possible" << endl;
    }else{ 
        cout << res << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
    return 0;
}
