


#include<bits/stdc++.h>
#include <bitset>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long

#pragma endregion


bool rows[15][15]; 
bool cols[15][15];
int matrix[15][15];
bool fixed_val[15][15];
bool isNeighbor[15][15][15][15];
int n;
int start_r, start_c;
const double TIME_CUTOFF = (1.0 / 60) * 1e6;

auto chrono_begin = chrono::steady_clock::now();

double time_so_far() {
    return chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - chrono_begin).count();
}

void print_matrix(int n){ 
    for(int i =0; i < n; i++){ 
        for(int j =0; j <n; j++){
            if(matrix[i][j]) 
                cout << matrix[i][j] << " ";
            else
                cout << ". ";
        }
        cout <<endl;
    }
}
bool outOfBound( int r, int c){
    return r < 0 || r >= n || c < 0 || c >= n;
}

bool isValid( int r, int c, int val){ 
    bool valid = true;
    if(!outOfBound(r+1, c) && matrix[r+1][c]){ 
        if(isNeighbor[r][c][r+1][c]){
            valid &= (abs(matrix[r][c]-matrix[r+1][c]) == 1);
        }else{ 
            valid &= (abs(matrix[r][c]-matrix[r+1][c]) > 1);
        }
    }
    if(!outOfBound(r-1, c) && matrix[r-1][c]){ 
        if(isNeighbor[r][c][r-1][c]){
            valid &= (abs(matrix[r][c]-matrix[r-1][c]) == 1);
        }else{ 
            valid &= (abs(matrix[r][c]-matrix[r-1][c]) > 1);
        }
    }
    if(!outOfBound(r, c+1) && matrix[r][c+1]){ 
        if(isNeighbor[r][c][r][c+1]){
            valid &= (abs(matrix[r][c]-matrix[r][c+1]) == 1);
        }else{ 
            valid &= (abs(matrix[r][c]-matrix[r][c+1]) > 1);
        }
    }
    if(!outOfBound(r, c-1) && matrix[r][c-1]){ 
        if(isNeighbor[r][c][r][c-1]){
            valid &= (abs(matrix[r][c]-matrix[r][c-1]) == 1);
        }else{ 
            valid &= (abs(matrix[r][c]-matrix[r][c-1]) > 1);
        }
    }
    // cout << valid << endl;
    return valid;
}
ll break_count = 0;
bool count_down( int r, int c, int d){
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
        if(isValid(r,c, matrix[r][c])) return count_down(r, c+1,d+1); 
        break_count += 1 << (30 - 3*d);
        return false;
    }
    bool res = false;
    for(int i = 1; i <= n; i++){
        matrix[r][c] = i;
        if( !cols[c][i] && !rows[r][i] && isValid( r, c, i)){ 
            rows[r][i] = true; 
            cols[c][i] = true; 
            res = count_down(r, c+1, d+1);
            if(res){
                rows[r][i] = false; 
                cols[c][i] = false;
                matrix[r][c] = 0; 
                 return res;
            }
            rows[r][i] = false; 
            cols[c][i] = false; 
        }
        matrix[r][c] = 0;

    }
    // break_count++;
    break_count += 1 << (30 - 3*d);

    return res;
}
bool solve_up( int r, int c){ 
    if(c == -1){ 
        c = n-1;
        r -= 1;
    }
    if(r < 0){
        return true;
    }
    if(fixed_val[r][c]){ 
        if(isValid(r,c, matrix[r][c])) return solve_up( r, c-1); 
        return false;
    }
    bool res = false;
    for(int i = 1; i <= n; i++){
        matrix[r][c] = i;
        if( !cols[c][i] && !rows[r][i] && isValid( r, c, i)){ 
            rows[r][i] = true; 
            cols[c][i] = true; 
            res = solve_up( r, c-1);
            if(res) return res;
            rows[r][i] = false; 
            cols[c][i] = false; 
        }
        matrix[r][c] = 0;

    }
    return res;
}
bool solve_down( int r, int c){ 
    if(c == n){ 
        c = 0;
        r += 1;
    }
    if(r >= n){ 
        return solve_up(start_r, start_c-1);
    }
    if(fixed_val[r][c]){ 
        if(isValid(r,c, matrix[r][c])) return solve_down( r, c+1); 
        return false;
    }
    bool res = false;
    for(int i = 1; i <= n; i++){
        matrix[r][c] = i;
        if( !cols[c][i] && !rows[r][i] && isValid( r, c, i)){ 
            rows[r][i] = true; 
            cols[c][i] = true; 
            res = solve_down( r, c+1);
            if(res) return res;
            rows[r][i] = false; 
            cols[c][i] = false; 
        }
        matrix[r][c] = 0;

    }
    return res;
}

void solve(){
    int  k; 
    cin >> n >> k; 
    // cout << n << " " << k << endl;
    for(int i =0; i < n; i++){ 
        char val;
        for(int j =0; j < n-1; j++){ 
            cin >> val; 
            // cout << val; 
            if(val == '1'){ 
                isNeighbor[i][j][i][j+1] = true; 
                isNeighbor[i][j+1][i][j] = true;
            }
        }
        // cout << endl;
        if(i != n-1){
            for(int j =0; j < n; j++){ 
                cin >> val;
                // cout << val;
                if(val == '1'){ 
                    isNeighbor[i][j][i+1][j] = true; 
                    isNeighbor[i+1][j][i][j] = true; 
                }
            }
        }
        // cout << endl;
    }
    for(int i =0; i < k; i++){ 
        int r, c, val;
        cin >> r >> c >> val; 
        r--; c--;  //off set it 
        matrix[r][c] = val; 
        fixed_val[r][c] = true;
        rows[r][val] = true;
        cols[c][val] = true;
    }
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
    // print_matrix(n);
    solve_down(start_r,start_c);
    // cout << endl; 
    print_matrix(n);
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve(); 
}