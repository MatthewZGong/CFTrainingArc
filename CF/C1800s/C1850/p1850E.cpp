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

ll s[200005];
ll calc(ll w, int n, ll c){
    ll area =0; 
    for(int i =0; i < n; i++){
        if(c/w < w){
            return 1;
        }
        if(c-2*w < s[i]){
            return 1;
        }
        ll length = s[i]+2*w;
        if(c/length < length){
            return 1;
        }
        area += (length*length);
        if(area > c){ 
            return 1;
        }
    }
    // cout << w << " " << area << endl;
    if(area < c){ 
        return -1;
    }
    return 0;
}
void solve(){
    int n; 
    ll c; 
    cin >> n >> c; 
    ll start = 1; 
    ll end = c/2;
    for(int i =0; i < n; i++){
        cin >> s[i];
    }
    while(start < end){ 
        ll mid = (start+end)/2; 
        ll area = calc(mid, n,c); 
        if(area == 1){ 
            end = mid;
        }else if(area == -1){
            start = mid+1;
        }else{ 
            // cout << " RES " <<endl;
            cout << mid << endl;
            // cout << "HIIIII " <<  c   << endl; 
            // calc(mid ,n, c);
            return;
        }

    }
    // cout << " RES " <<endl;
    cout << start << endl;
    // cout << "HIIIII " <<  c   << endl; 
    // calc(start,n, c);
    return;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        // cout << "_________" << endl;
        solve();
    }

}
