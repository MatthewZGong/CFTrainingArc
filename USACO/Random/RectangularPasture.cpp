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
#pragma endregion

tuple<int,int> points[2501]; 
ll greaterThan[2501][2501];
ll lesserThan[2501][2501];

ll solve(int n){
    for (int i =0; i < n; i++){ 
        cin >> get<0>(points[i]) >> get<1>(points[i]); 
        // cout << get<0>(points[i]) << " " << get<1>(points[i]) << endl;
    }
    sort(points, points+n); 
    for(int i = 1; i <= n; i++){ 
        // int ind = get<2>(points[i]);
        for(int j = 1; j <= n; j++){ 
                greaterThan[i][j] = greaterThan[i][j-1];
                lesserThan[i][j] = lesserThan[i][j-1];
            if(get<1>(points[i-1]) <= get<1>(points[j-1])){ 
                greaterThan[i][j] ++;
            }
            if(get<1>(points[i-1]) >= get<1>(points[j-1])){ 
                lesserThan[i][j] ++;
            }

        }
    }
    ll ans = 1;
    for(int i =1; i<= n; i++){ 
        auto [x1, y1] = points[i-1];
        for(int j = i; j<=n; j++){ 
            auto [x2,y2] = points[j-1];
            // cout << x1 << "," << y1 << " | " << x2 << "," << y2 << endl;
            if(y2 > y1){ 
                // cout << "1: " << (lesserThan[i][j]-lesserThan[i][i-1]) << " " << (greaterThan[j][j]-greaterThan[j][i-1]) << endl;  
                ans += (lesserThan[i][j]-lesserThan[i][i-1])*(greaterThan[j][j]-greaterThan[j][i-1]);
            }else{
                // cout << "2: "<< greaterThan[i][j]-greaterThan[i][i-1] << " " << lesserThan[j][j]-lesserThan[j][i-1] << endl;;
                ans += (greaterThan[i][j]-greaterThan[i][i-1])*(lesserThan[j][j]-lesserThan[j][i-1]);
            }
        }
    }
    return ans;
}
void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    ios::sync_with_stdio(false); 
    // setIO("lifeguards");
    cin.tie(nullptr);
    int n; 
    cin >> n;     
    cout << solve(n) << endl;


}
