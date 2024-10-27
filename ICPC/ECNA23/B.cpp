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

double houses[2000];

double dp[2001][101];

int solve(){
    int m, n, k; 
    double s;
    cin >> m >> n >> k >> s;
    for(int i =0; i < m + n; i++){ 
        cin >> houses[i];
    }
    
    sort(houses, houses+m+n);
    for(int point = 0; point < k+1; point++){ 
        for(int house = 0; house < m+n+1; house++){ 
            dp[house][point] = 1e18;
        }
    }
    dp[m+n][k] = 0;
    double y_dist = s/2.0;
    for(int point = k-1; point >= 0; point--){ 
        for(int house = m+n-1; house >= 0; house--){ 
            double current_total = 0;
            double current_square = 0;
            for(int next_house = house; next_house < m+n; next_house++){ 
                current_total += houses[next_house];
                current_square += pow(houses[next_house],2);
                double total_houses = next_house-house+1;
                double average = current_total /total_houses;
                double distance = total_houses*pow(average,2.0)+ total_houses*pow(y_dist,2.0) + current_square - 2*current_total*average;
                dp[house][point] = min(dp[house][point], distance+dp[next_house+1][point+1]);
            }
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
        
        solve();

}
