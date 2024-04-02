#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
template<typename T>
void print(T v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
void print1(int v[], int n){
    for(int i =1 ; i <= n; ++i){ 
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
int g, n; 
bool distance(ll x1, ll y1, ll x2, ll y2, ll distance){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) <= distance*distance;
}
bool in_range(tuple<ll,ll,ll,bool> start, tuple<ll,ll,ll,bool> end, tuple<ll,ll,ll,bool> cow){
    auto [ts, sx, sy, bs] = start; 
    auto [te, ex, ey, be] = end;
    auto [t, x, y, b] = cow;
    // cout << sx << " " <<  sy << " | " <<  x << " " << y << " | " << ex << " " << ey << endl;
    // cout << distance(sx,sy,x,y, abs(ts-t)) << " " << distance(ex,ey,x,y, abs(te-t)) << endl;
    return distance(sx,sy,x,y, abs(ts-t)) && distance(ex,ey,x,y, abs(te-t));
}
int cows_in_range(tuple<ll,ll,ll,bool> start, tuple<ll,ll,ll,bool> end, vector<tuple<ll,ll,ll,bool>>& cows){ 
    int reachable = 0;
    for(int i = 0; i < cows.size(); i++){
        reachable += in_range(start, end, cows[i]);
    }
    // cout << res << endl;
    return cows.size()-reachable;
}
void solve(){
    cin >> g >> n; 
    vector<tuple<ll,ll,ll,bool>> points; 
    vector<tuple<ll,ll,ll,bool>> cows; 
    for(int i = 0; i < g; i++){ 
        ll x, y, t; 
        cin >> x >> y >> t;
        points.push_back({t,x,y,false});

    }
    for(int i = 0; i < n; i++){ 
        ll x, y, t; 
        cin >> x >> y >> t; 
        points.push_back({t,x,y,true});
    }
    sort(points.begin(), points.end());
    tuple<ll,ll,ll,bool> start = {-2e9,0,0, false}; 
    tuple<ll,ll,ll,bool> end = {-2e9,0,0, false};
    points.push_back({2e9, 0,0, false});
    // cout << (points.size()) << endl;;
    
    int res =0;
    for(int i = 0; i < points.size(); i++){ 
        if(get<3>(points[i])){ 
            cows.push_back(points[i]);
        }else{  
            start = end;
            end = points[i];
            res += cows_in_range(start, end, cows);
            cows.clear();
        }
    }   
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();

}
