#include<bits/stdc++.h>

using namespace std;


int arr[200000+5];
int a[200000+5];

int solve(){
    int l, r; 
    cin >> l >> r; 
    if(r == l){
        return 1;
    }
    if(r-l == 1){
        return 2;
    }
    int res = (arr[r]-arr[l])+1; 
    if(arr[r] == arr[l]){
        return 2;
    }
    if(arr[l+1] == arr[l]){
        res += 1;
    }
    return res;
}

void process(int n){
    bool flag = false; 
    int adj = 0;
    for(int i = 1; i < n+1; ++i){
        if(a[i] <= a[i-1]){
            if(flag){
                ++adj; 
            }else{ 
                flag = true;
            }
            arr[i] = i-adj;
        }else{ 
            flag = false;
            arr[i] = i-adj;
        }
    }

}

void print(int n){
    for(int i =1 ; i < n+1; ++i){ 
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i =1 ; i < n+1; ++i){ 
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){ 
    int n, q; 
    cin >> n >> q; 
    for(int i = 1; i < n+1; ++i){
        int h;
        cin >> h;
        a[i] = h;
    }
    process(n);
    // print(n);
    for(int i =0 ; i < q; ++i){ 
        cout << solve() << endl;
    }

}
