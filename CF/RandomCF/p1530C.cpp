#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
using namespace std;
void print(int v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}

int a[100005]; 
int b[100005];
int aSum[100005];
int bSum[100005];
void solve(){
    int n; 
    cin >> n; 
    int aScore =0; 
    int bScore = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        aScore += a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        bScore += b[i];
    }
    sort(a, a+n, greater<>());
    sort(b, b+n, greater<>());
    for(int i =0; i < n; i++){
        aSum[i+1] = aSum[i]+a[i];
        bSum[i+1] = bSum[i]+b[i];
    }
    // print(a,n);
    // print(bSum,n+1);
    // print(b,n);
    // print(bSum,n+1);
    int start = 0; 
    int end = n+1; 
    while(start < end){
        int res = (start+end)/2;
        int aScore, bScore; 
        int i = (n+res) -(n+res)/4;
        aScore  = (i <= res) ? 100*i:100*res +aSum[i-res];
        bScore = bSum[min(n,i)];
        // cout << res << " " << aScore << " " << bScore << endl;
        if(aScore >= bScore){
            end = res;
        }else{
            start = res+1;
        }
    }

    cout << start << endl;
    // cout << "----------------" << endl;

}
int main(){ 
    int t; 
    cin >> t; 
    while(t--){
        solve();
    }

}
