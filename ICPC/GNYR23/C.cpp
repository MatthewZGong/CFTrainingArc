#include<bits/stdc++.h>
// g++-14 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
#define uu __uint128_t 
// #define 
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
ll inv_mod_prime(ll a, ll MOD) {
  return a <= 1 ? a : MOD - (MOD/a) * inv_mod_prime(MOD % a, MOD) % MOD;
}
#pragma endregion

bool is_power_two(uu num){ 
    for(int i =0; i < 128; i++){ 
        auto pow = uu(1) << i;
        if(pow == num){ 
            return true;
        }
    }
    return false;
}

uu works(uu power, string& order){ 
    // uu res = 0;
    uu current = uu(1) << power;
    // cout << "start: " << uint64_t(current) << " " << uint64_t(power) << endl;
    for(int i = order.size() -1; i >= 0; --i){ 
        char op = order[i];
        // cout << uint64_t(current) << endl;
        if(op == 'O'){ 
            current -= 1; 
            if( (current%3) == 0){ 
                current /= 3;
            }else{ 
                // cout << "HI 4 " << endl;
                return 0;
            }
            if( (current%2) == 0 || current == 1){ 
                // cout << "HI 3 " << endl;
                return 0;
            }
            
        }else if(op == 'E') { 
            current *= 2;
            if( (current%2) == 1){ 
            // cout << "HI 2 " << endl;
                return 0;
            }
        }
        if(is_power_two(current)){ 
            // cout << "HI 1 " << endl;
            return 0;
        }
    }
    return current;

}

void solve(){
    string order; 
    cin >> order; 
    // cout << order.size() << endl;
    for(uu power = 0; power <= 48; ++power){ 
        if(auto res = works(power, order)){ 
            cout << uint64_t(res) << endl;
            return;
        }
    }
    cout << "INVALID" << endl;
    return;


}

int main(){
    // ios::sync_with_stdio(false); 
    // cin.tie(nullptr);
    // int t; 
    // cin >> t; 
    // while(t--){
        
        solve();
    // }
    return 0;
}