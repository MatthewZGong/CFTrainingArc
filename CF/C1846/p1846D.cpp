#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
void print(double v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
#pragma endregion
double branches[200005];
int solve(){
    int n; 
    double d; 
    double h; 
    cin >> n >> d >> h; 
    for(int i =0; i < n; i++){ 
        cin >> branches[i]; 
    }
    sort(branches, branches+n); 
    double vol = 0;
    double prev = 0; 
    // print(branches, n);
    for(int i =0; i <n; i++){ 
        vol += d*h/2; 
        if(i != 0){ 
            double k = branches[i]-prev; 
            double ph = h-k; 
            if(ph > 0){
                vol -= d*ph*ph/h/2;
            }
        }
        prev = branches[i];
    }
    cout << fixed << setprecision(8) << vol << endl;
    return 0;
}

int main(){

    int t; 
    cin >> t; 
    while(t--){
        
        solve();
    }

}
