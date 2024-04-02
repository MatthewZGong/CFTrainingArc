#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
void print(int v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
#pragma endregion

ll cities[200005][2]; 
ll dist_a[200005]; 
ll dist_b[200005];
void solve(){
    ll n, k, a ,b; 
    cin >> n >> k  >> a >> b; 
    for(int i =1; i <= n; i++){ 
        cin >> cities[i][0] >> cities[i][1];
    }
    ll ax, ay, bx, by; 
    ax = cities[a][0];
    ay = cities[a][1];
    bx = cities[b][0]; 
    by = cities[b][1]; 
    for(int i =1; i <= k; i++){ 
        dist_a[i] = abs(ax-cities[i][0]) + abs(ay - cities[i][1]); 
        dist_b[i] = abs(bx-cities[i][0]) + abs(by - cities[i][1]);
    }
    ll res = abs(ax-bx) + abs(ay - by);
    if(k == 0){ 
        cout << res << endl;
    }else{
        res = min(res, *min_element(dist_a+1, dist_a+k+1)+ *min_element(dist_b+1, dist_b+k+1));
        cout << res << endl;
    }
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
        
    }

}
