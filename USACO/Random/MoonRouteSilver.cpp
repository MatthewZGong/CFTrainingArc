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
int a[1'000'000]; 
int n;

int move_right(int i, string& res){ 
    while(i != n && a[i] != 0){ 
        res += 'R';
        a[i]--;
        i++;
    }
    return i;
}
int move_left(int i, string& res){
    while(i != 0 && a[i-1] > a[i]){ 
        res += 'L';
        a[i-1]--;
        i--;
    }
    return i;
}

         
int solve(){
    cin >> n;
    int steps = 0;
    for(int i =0; i < n; i++){ 
        cin >> a[i];
        steps += a[i];
    }
    string res = ""; 
    int i = 0;
    while(res.length() < steps){ 
        i = move_right(i, res);
        i = move_left(i, res);
        // print(a, n);
        // cout << i << endl;
    }
    cout << res << endl;
    return 0;
    

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
    

}
