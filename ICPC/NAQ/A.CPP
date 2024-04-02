#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long lon
#pragma endregion

int schools[100005];
void solve(int n, int k, int c){
    vector<pair<int,int>> overflow; 
    vector<pair<int,int>> passed;
    for(int i =0; i < n; i++){ 
        int t,s;
        cin >> t >> s; 
        if(schools[s] < c){ 
            passed.emplace_back(i, t);
        }else{ 
            overflow.emplace_back(i,t);
        }
        schools[s]++;
    }
    int i =0;
    while(passed.size() < k){
        passed.push_back(overflow[i]);
        i++;
    }
    sort(passed.begin(), passed.end()); 
    for(int i =0; i < k; i++){
        cout << passed[i].second << '\n';
    }

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int n, k, c; 
    cin >> n >> k >> c; 
    solve(n,k,c);
}
