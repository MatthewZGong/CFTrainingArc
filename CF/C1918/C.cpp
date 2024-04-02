#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;
 
#pragma region
#define ll long long
// void Sieve(){
//     memset(vis, true, sizeof(vis));
    
//     vis[0] = vis[1] = false;
//     for(int i = 4 ; i < N ; i += 2)
//         vis[i] = false;
//     for(int i = 3 ; i < N / i ; i += 2){
//         if(!vis[i])continue;
//         for(int j = i * i ; j < N ; j += i + i)
//             vis[j] = false;
//     }
// }
 
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
 
 // i gave mysefl cancer coding this 
void solve(){
    ll a, b, r; 
    cin >> a >> b >> r;
    // cout << "a: " << a << " b: " << b << " r: " << r << endl;
    ll x = 0; 
    int set = 0;
    ll i = 0; 
    for(i = 63; i >= 0; --i){ 
        ll current = 1ll << i;
        bool set_now = false; 
        if( ((a & current) != (b & current)) && set == 0){ 
            if(a& current){
                set = 1;
            }else{
                set = 2;
            }
            set_now = true;
            // cout << "set: " << set << " current: " << current << endl;
        }
        if((r & current)){ 
            if(((a & current) == (b & current) ) || set_now){
                break;
            }
            
            if(set == 1){ 
                if(a & current){ 
                    x += current;
                }else{ 
                    break;
                }
            }else if(set == 2){ 
                if(b & current){ 
                    x += current;
                }else{ 
                    break;
                }
            }
        }
    }
    i--;
    for(; i >= 0; --i){
        ll current = 1ll << i;
        if((a & current) == (b & current)){ 
            continue;
        }
        if(set == 0){ 
            if(a & current){
                set = 1;
            }else{
                set = 2;
            }
        }else if(set == 1){ 
            if(a & current){ 
                x += current;
            }
        }else if(set == 2){ 
            if(b & current){ 
                x += current;
            }
        }
        
    }
    // cout << "x: " << x << endl;
    cout << abs((a ^ x) - (b ^ x)) << endl;
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