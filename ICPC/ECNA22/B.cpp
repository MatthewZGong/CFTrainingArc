#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;
 
#pragma region
#define ll long long
#pragma endregion
bool dp[1005][1005][1005];
int music[1001];
 
void solve(){
    int n, c; 
    cin >> c >> n;
    int a = 0; 
    int b = 0;
    int total = 0;
    for(int i =0; i < n; i++){ 
        cin >> music[i];
 
    }
    for(int i =0; i < n; i++){ 
        dp[i][0][0] = true;
        // cout << music[i] << endl;
    }
 
    dp[0][music[0]][0] = true; 
    dp[0][0][music[0]] = true; 
    for(int i =1; i < n; i++){ 
        int time = music[i];
        for(int j = 0; j <= c; j++){ 
            for(int k =0; k <= c; k++){ 
                dp[i][j][k] |= dp[i-1][j][k];
                if(k >= time){ dp[i][j][k] |= dp[i-1][j][k-time]; dp[i][j][k] |= dp[i-1][k-time][j];}
            }
        }
    }
    for(int i =0; i <= c; i++){ 
        for(int j =0; j <= c; j++){ 
            if(dp[n-1][i][j] && (i+j) >= total){ 
                // cout << i + j << endl; 
                if( (i+j) > total){ 
                    a = i; 
                    b = j;
                }else if(abs(i-j) < abs(a-b)){ 
                    a = i; 
                    b = j;
                }
                total = i+j;
            }
        }
    }
    // cout << total << endl; 
    if(a < b){ 
        swap(a,b);
    }
    cout << a << " " << b << endl;
    
}   
 
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
}