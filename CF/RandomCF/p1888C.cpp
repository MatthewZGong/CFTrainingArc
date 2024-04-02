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

template<typename T>
void print1(T v[], int n){
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
int a[2'00'001]; 
bool isLeft[2'00'001]; 
bool isRight[2'00'001]; 
int solve(){
    int n; 
    cin >> n; 
    memset(isLeft, 0, sizeof(isLeft)); 
    memset(isRight, 0, sizeof(isRight));
    for(int i = 1; i <= n; i++){ 
        cin >> a[i]; 
    }
    map<int, int> left_most; 
    map<int,int> right_most; 
    int right_count = 0; 
    for(int i =1 ; i <= n; i++){ 
        if(!left_most.count(a[i])){ 
            left_most[a[i]] = i; 
            isLeft[i] = true;
        }
        if(right_most.count(a[i])){ 
            isRight[i] = true;
            isRight[right_most[a[i]]] = false;
            right_most[a[i]] =i;  
        }else{ 
            right_most[a[i]] = i; 
            isRight[i] = true;
            right_count++;
        }
    }
    // print1(a, n);
    // print1(isLeft, n); 
    // print1(isRight, n);
    ll res =0;
    for(int i = 1; i <= n; i++){ 
        if(isLeft[i]){ 
            res += right_count;
        }
        if(isRight[i]){ 
            right_count--;
        }
    }
    cout << res << endl; 
    return 0; 
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
        // cout << endl;
    }

}
