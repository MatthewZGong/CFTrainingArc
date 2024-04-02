#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
template<typename T>
void print(T v[], int n, int i = 0){
    for(; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
template<typename T>
void print(vector<T> v){
    for(int i =0 ; i < v.size(); ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
#pragma endregion

void make_guess(int x, int y){ 
    cout << "? " << x << " " << y << endl;
}

void solve(){
    ll n, m;
    cin >> n >> m; 
    vector<pair<ll,ll>> guesses;
    make_guess(1, 1);
    ll d1, d2, d3; 
    ll b1, b2, b3; 
    cin >> d1; 
    b1 = d1+2; 
    // y = -x +b1;
    make_guess(1,m); 
    cin >> d2; 
    b2 = m-d2-1;
    
    make_guess(n,1);
    cin >> d3; 
    b3 = 1-(n-d3);
    if(abs(b1-b2)%2 == 0){ 
        ll intersection_x = (b1-b2)/2; 
        ll intersction_y = 1*intersection_x +b2;
        if(intersection_x >= 1 && intersection_x <= n && intersction_y >= 1 && intersction_y <= m){
            guesses.push_back({intersection_x, intersction_y}); 
        }
    }
    if(abs(b1-b3)%2 == 0){ 
        ll intersection_x = (b1-b3)/2;
        ll intersection_y = 1*intersection_x +b3;
        if(intersection_x >= 1 && intersection_x <= n && intersection_y >= 1 && intersection_y <= m){
            guesses.push_back({intersection_x, intersection_y}); 
        }
    }
    if(guesses.size() == 1){ 
        cout << "! " << guesses[0].first << " " << guesses[0].second << endl;
    }else{ 
        ll dist = 0;
        cout << "? " << guesses[0].first << " " << guesses[0].second << endl; 
        cin >> dist;
        if(dist == 0){ 
            cout << "! " << guesses[0].first << " " << guesses[0].second << endl;
        }else{ 
            cout << "! " << guesses[1].first << " " << guesses[1].second << endl;
        }
    }
    return;





}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
    }
    return 0;
}
