#include<bits/stdc++.h>
// g++-14 -o main [file].cpp;
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
ll inv_mod_prime(ll a, ll MOD) {
  return a <= 1 ? a : MOD - (MOD/a) * inv_mod_prime(MOD % a, MOD) % MOD;
}
// count number of bits 
// only for int64 and int32
//__builtin_popcount 
 
// void sieve(int n){ 
//     // cout << "sieved" << endl;
//     memset(lowest_divisors, 63, sizeof(lowest_divisors));
//     for(int i = 2; i <= n; ++i){ 
//         // cout << i << endl;
//         if(lowest_divisors[i] > i){ 
        
//             primes.push_back(i);
//             adj.push_back({});
//             lowest_divisors[i] = primes.size()-1;
//             for(int j = i+i; j <= A_SIZE; j+= i){ 
//                 lowest_divisors[j] = min(lowest_divisors[j], int(primes.size()-1));
//             }
//         }
//     }
//     for(int i = n; i <= A_SIZE; ++i){ 
//         if(lowest_divisors[i] > i){ 
//             lowest_divisors[i] = primes.size();
//             primes.push_back(i);
//             adj.push_back({}); 
//         }
//     }
// }
#pragma endregion
 
int dp[100'000][3];
string row1; 
string row2; 
int n;
 
const int ROW = 0; 
const int LEFT_DOWN = 1; //L
const int LEFT_UP = 2; 
const int RIGHT_DOWN = 3; //L 
const int RIGHT_UP = 4; 
 
//row it starts at
int get_votes(int column, int r, int type){ 
    if(type == ROW){ 
        if(r == 0){ 
            return ((row1[column] == 'A') + (row1[column+1] == 'A') + (row1[column+2] == 'A') )> 1;
        }else{ 
            return ((row2[column] == 'A')+ (row2[column+1] == 'A') + (row2[column+2] == 'A')) > 1;
        }
    }else if(type == LEFT_DOWN){ 
        // A
        // A A 
        // i
        return ((row1[column] == 'A') + (row2[column] == 'A') + (row2[column+1] == 'A')) > 1;
    }else if(type== LEFT_UP){ 
        return ((row1[column] == 'A') + (row2[column] == 'A') + (row1[column+1] == 'A')) > 1;
    }else if(type == RIGHT_DOWN){ 
        //   A
        // A A
        // i
        return ((row2[column] == 'A') + (row1[column+1] == 'A') + (row2[column+1] == 'A')) > 1;
    }else if(type == RIGHT_UP){
        // A A
        //   A
        // i 
        return ((row1[column]  == 'A') + (row2[column+1]  == 'A')+ (row1[column+1] == 'A')) >1 ;
 
    }
 
    return -100;
}
 
 
 
 
int most_votes(int i, int offset){ 
    if(i == n && offset == 0){ 
        return 0;
    }
    if(i >= n){ 
        return -100;
    }
    if(dp[i][offset] >= 0){ 
        return dp[i][offset];
    }
    if (offset == 0) {  
        int take_row = get_votes(i, 0, ROW) + get_votes(i, 1, ROW)+ most_votes(i+3, 0);
        int take_left_d = get_votes(i, 0, LEFT_DOWN) + most_votes(i+1, 1);
        int take_left_u = get_votes(i, 0, LEFT_UP) + most_votes(i+1, 2);
        int res = max(take_row, take_left_d); 
        return dp[i][offset] = max(res, take_left_u);
    } else if(offset == 1) {  
        // X  
        // X X
        //   i
        int take_row = -100;
        if(n-i >= 3) take_row = get_votes(i, 0, ROW ) + get_votes(i+1, 1, ROW) + most_votes(i+3, offset);

        int take_right_u = get_votes(i, 0, RIGHT_UP) + most_votes(i+2, 0);
        return dp[i][offset] = max(take_row, take_right_u);
    }else{ 
        // X X 
        // X 
        //   i
        int take_row = -100;
        if(n-i >= 3) take_row = get_votes(i+1, 0, ROW ) + get_votes(i, 1, ROW) + most_votes(i+3, offset);
        int take_right_down = get_votes(i, 0, RIGHT_DOWN) + most_votes(i+2, 0);
        return dp[i][offset] = max(take_row, take_right_down);
    }
 
}
 
void solve(){
    cin >> n;
    for(int i =0; i < n; i++){ 
        dp[i][0] = -100;
        dp[i][1] = -100;
        dp[i][2] = -100;
    }
    cin >> row1; 
    cin >> row2;
    // cout<< row1 << endl;
    // cout  << row2 << endl;
    // cout << get_votes(0, 0, ROW) << endl;
    cout << most_votes(0, 0) << endl;
    // cout << "-------------" << endl;
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