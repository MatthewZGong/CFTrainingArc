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

tuple<int,int> points[200005];
map<int, int> v;
map<int, int> h; 
map<int, int> pos; 
map<int, int> neg; 
void solve(){
    int n; 
    cin >> n; 
    for(int i =0; i <n; i++){
        int& x = get<0>(points[i]);
        int& y = get<1>(points[i]);
        cin >> x; 
        cin >> y;
        if(v.count(x)){ 
            v[x] += 1;
        }else{ 
            v[x] = 1;
        }
        if(h.count(y)){ 
            h[y] += 1;
        }else{
            h[y] = 1;
        }
        if(pos.count(x-y)){
            pos[x-y] +=1;
        }else{
            pos[x-y] =1;
        }
        if(neg.count(x+y)){
            neg[x+y] +=1;
        }else{
            neg[x+y] = 1;
        }

    }
    ll res =0;
    for(int i =0; i <n; i++){
        int& x = get<0>(points[i]);
        int& y = get<1>(points[i]);
        res +=  v[x]-1;
        res += h[y]-1;
        res += pos[x-y]-1;
        res += neg[x+y]-1;
    }
    v.clear();
    h.clear();
    pos.clear();
    neg.clear();
    cout << res << endl;
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
