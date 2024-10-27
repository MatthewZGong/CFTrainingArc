#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
int a[55]; 
int b[55];
void print(int v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
#pragma endregion

void solve(){
    int n,m;
    cin >> n >> m;
    for(int i =0; i < n; ++i){
        cin >> a[i];
    }
    for(int i =0; i < m; ++i){
        cin >> b[i];
    }
    int i = 0;
    int j =0;
    // sort(a,a+n);
    // sort(b,b+m);
    // print(a,n);
    // print(b,m);
    while(a[n-1] > 0 && b[m-1] >0){
        int holder = a[i]; 
        a[i] -= b[j]; 
        b[j] -= holder;
        if(a[i] <= 0){
            i++;
        }
        if(b[j] <= 0){
            j++;
        }
    }
    // print(a,n);
    // print(b,m);
    if(a[n-1] <= 0 && b[m-1] <=0){
        cout << "Draw" << endl;
    }else if(a[n-1] <= 0){
        cout << "Tenzing" << endl;
    }else{
        cout << "Tsondu" << endl;
    }
}

int main(){
    int t; 
    cin >> t; 
    while(t--){
        solve();
    }

}
