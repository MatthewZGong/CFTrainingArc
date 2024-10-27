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

int solve(){
    ll n, P, l, t;
    cin >> n >> P >> l >> t;
    ll work = 0;
    ll total_tasks = (n+6)/7;

    //can do two tasks 
    ll days = total_tasks/2; 

    ll credits = l+2*t;

    if(days*credits <= P){ 
        P -= days*credits;
        work += days;
    }else{ 
        work += (P+credits-1)/credits;
        cout << n - work << endl;
        return 0;
    }

    if(total_tasks%2 == 1 && P > 0){ 
        P -= l+t;
        work++;
    }

    //no more tasks
    if(P > 0)
        work += (P+l-1)/l;

    cout << n - work << endl;
    return 0;


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
