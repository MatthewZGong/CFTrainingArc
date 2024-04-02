// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


#include<bits/stdc++.h>
#include <bitset>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long

#pragma endregion


int rows[15]; 
int cols[15];
int matrix[15][15];
bool fixed_val[15][15];
bool isNeighbor[15][15][2];
int n;
int start_r, start_c;
const double TIME_CUTOFF = (1.0 / 60) * 1e6;

auto chrono_begin = chrono::steady_clock::now();

// auto time_so_far = [=]() { return 
//     chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - chrono_begin).count();
// };

double time_so_far() {
    return chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - chrono_begin).count();
}
// int directions[2][2] = {{-1,0}, {0,-1}};

void print_matrix(int n){ 
    for(int i =0; i < n; i++){ 
        for(int j =0; j <n; j++){
            if(matrix[i][j]){
                int val = matrix[i][j];
                int res = 1; 
                while(val >>= 1) res ++; 
                cout << res << " ";
            }
            else
                cout << ". ";
        }
        cout <<endl;
    }
}
bool outOfBound(int r, int c){
    return r < 0 || r >= n || c < 0 || c >= n;
}


bool isValid(int r, int c, int mask){ 
    bool valid = true;
    if(!outOfBound( r-1, c) && matrix[r-1][c]){ 
        bool nei = ((mask >> 1) == matrix[r-1][c] || (mask << 1) == matrix[r-1][c] );  
        if(!isNeighbor[r-1][c][1]) nei = !nei;
        valid &= nei;
        
    }
    if(!outOfBound(r, c-1) && matrix[r][c-1]){ 
        bool nei = ((mask >> 1) == matrix[r][c-1] || (mask << 1) == matrix[r][c-1] );
        if(!isNeighbor[r][c-1][0]) nei = !nei;
        valid &= nei;
    }
    if(!outOfBound(r+1, c) && matrix[r+1][c]){ 
        bool nei = ((mask >> 1) == matrix[r+1][c] || (mask << 1) == matrix[r+1][c] );
        if(!isNeighbor[r][c][1]) nei = !nei;
        valid &= nei;
    }
    if(!outOfBound(r, c+1) && matrix[r][c+1]){ 
        bool nei = ((mask >> 1) == matrix[r][c+1] || (mask << 1) == matrix[r][c+1] );
        if(!isNeighbor[r][c][0]) nei = !nei;
        valid &= nei;
    }
    return valid;
}

ll break_count = 0;
bool count_down(int r, int c, int d){
    if(d > 10){ 
        return false;
    }
    if(time_so_far() > TIME_CUTOFF){ 
        return true;
    }
    if(c == n){ 
        c = 0;
        r += 1;
    }
    // print_matrix(n);
    if(r >= n){ 
        return true;
    }
    if(fixed_val[r][c]){ 
        if(isValid(r,c, matrix[r][c])) return count_down(r, c+1, d+1); 
        break_count += 1 << (30 - 3*d);
        return false;
    }
    int mask = 1 << (n);
    int possible = (1 << n) -1; 
    possible &= (~cols[c]); 
    possible &= (~rows[r]);
    bool res = false;
    while(mask >>= 1){
        matrix[r][c] = mask; 
        if((possible & mask) && isValid(r, c, mask)){
            rows[r] |= mask;
            cols[c] |= mask;
            if(count_down(r, c+1, d+1)){
                rows[r] &= ~mask; 
                cols[c] &= ~mask;
                matrix[r][c] = 0 ;
                return true;
            } 
            rows[r] &= ~mask; 
            cols[c] &= ~mask;
        }
        matrix[r][c] = 0 ;
    }
    // break_count++;
    break_count += 1 << (30 - 3*d);

    return res;
}
bool solve_up(int r, int c){ 
    if(c == -1){ 
        c = n-1;
        r -= 1;
    }
    // print_matrix(n);
    if(r < 0){ 
        return true;
    }
    if(fixed_val[r][c]){ 
        if(isValid(r,c, matrix[r][c])) return solve_up(r, c-1); 
        return false;
    }
    int mask = 1 << (n);
    int possible = (1 << n) -1; 
    possible &= (~cols[c]); 
    possible &= (~rows[r]);
    bool res = false;
    while(mask >>= 1){
        matrix[r][c] = mask; 
        if((possible & mask) && isValid(r, c, mask)){
            rows[r] |= mask;
            cols[c] |= mask;
            if(solve_up(r, c-1)) 
                return true;
            rows[r] &= ~mask; 
            cols[c] &= ~mask;
        }
        matrix[r][c] = 0 ;
    }
    return res;
}

bool solve_down(int r, int c){ 
    if(c == n){ 
        c = 0;
        r += 1;
    }
    // print_matrix(n);
    if(r >= n){ 
        return solve_up(start_r, start_c-1);
    }
    if(fixed_val[r][c]){ 
        if(isValid(r,c, matrix[r][c])) return solve_down(r, c+1); 
        return false;
    }
    int mask = 1 << (n);
    int possible = (1 << n) -1; 
    possible &= (~cols[c]); 
    possible &= (~rows[r]);
    bool res = false;
    while(mask >>= 1){
        matrix[r][c] = mask; 
        if((possible & mask) && isValid(r, c, mask)){
            rows[r] |= mask;
            cols[c] |= mask;
            if(solve_down(r, c+1)) 
                return true;
            rows[r] &= ~mask; 
            cols[c] &= ~mask;
        }
        matrix[r][c] = 0 ;
    }
    return res;
}

void solve(){
    int k; 
    cin >> n >> k; 
    // cout << n << " " << k << endl;
    for(int i =0; i < n; i++){ 
        char val;
        for(int j =0; j < n-1; j++){ 
            cin >> val; 
            if(val == '1'){ 
                isNeighbor[i][j][0] = true; 
            }
        }
        if(i != n-1){
            for(int j =0; j < n; j++){ 
                cin >> val;
                if(val == '1'){ 
                    isNeighbor[i][j][1] = true; 
                }
            }
        }
    }
    // int start_r, start_c;
    vector<pair<int,int>> fixed_p;
    for(int i =0; i < k; i++){ 
        int r, c, val;
        cin >> r >> c >> val; 
        r--; c--;  //off set it 
        int mask = 1<<(val-1); 
        // cout << bitset<32>(mask) << endl;
        matrix[r][c] = mask; 
        fixed_val[r][c] = true;
        rows[r] |= mask; 
        cols[c] |= mask;
        fixed_p.emplace_back(r,c);
    }
    // sort(fixed_p.begin(), fixed_p.end(), greater<>());
    // // auto f = [](){};
    // int distances = n*n;
    // for(int i =1; i < k; i++){ 
    //     int dist = (fixed_p[i-1].first*n+fixed_p[i-1].second)-(fixed_p[i].first*n+fixed_p[i].second);
    //     if(dist < distances){ 
    //         distances = dist; 
    //         // start_r = fixed_p[i].first; 
    //         // start_c = fixed_p[i].second;
    //     }
    // }
    int max_break = -1e9;
    for(int i = 0 ; i < n; i++){ 
        for(int j =0; j < n; j++){
            // print_matrix(n);
            break_count = 0;
            chrono_begin = chrono::steady_clock::now();
            count_down(i,j, 0);
            if(max_break < break_count){ 
                max_break = break_count;
                start_r = i; 
                start_c = j;
            }
            // cout << i << " " << j << " " << break_count << endl;
        }
    }
    // cout << start_r << " " << start_c << endl;
    // p
    solve_down(start_r, start_c);
    // solve_up(n-1, n-1);
    print_matrix(n);
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve(); 
}



