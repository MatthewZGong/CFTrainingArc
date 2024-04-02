#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
#pragma endregion
int b[1000];
int k[1000]; 
int solve(){
    int n,k; 
    cin >> n >> k; 
    for(int i =0; i < n; i++){ 
        cin >> b[i]; 
    }
    int mb = *max_element(b,b+n);
    // cout << mb << endl;
    int res = 0; 
    for(int i =1; i <= mb; i++){ 
        int current = 0; 
        for(int j =0; j < n; j++){ 
            current += b[j]/i; 
        }
        if(current >= k){ 
            res = max(res, i*k/2);
            continue;
        }
        priority_queue<int> leftover; 
        for(int j =0; j < n; j++){ 
            leftover.push(b[j]%i); 
        }
        int unfilled = k-current; 
        int berries = max(0,current-k/2)*i; 
        while(unfilled > k/2 && leftover.size()){ 
            leftover.pop(); 
            unfilled--; 
        }
        while(unfilled && leftover.size()){ 
            berries += leftover.top(); 
            leftover.pop(); 
            unfilled--;
        }
        res = max(berries, res);
    }
    return res; 

}
void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    ios::sync_with_stdio(false); 
    setIO("berries");
    cin.tie(nullptr);
    cout << solve() << endl;
}
