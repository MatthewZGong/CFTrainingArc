#include<bits/stdc++.h>
//https://codeforces.com/problemset/problem/1530/D
using namespace std;

int a[200010];
int b[200010];
int taken[200010];
void clear(int n){
    for(int i = 1 ; i <= n; ++i){
        taken[i] = 0;
        a[i] = 0; 
        b[i] =0;
    }
}
void print(int v[], int n){
    for(int i =1 ; i <= n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
void solve(){
    int n; 
    cin >> n;
    clear(n);
    int res = 0;
    for(int i = 1 ; i <= n; ++i){
        cin >> a[i];
        if(!taken[a[i]]){
            taken[a[i]] = i;
            b[i] = a[i];
            res++;
        }
    }
    if(res == n){
        cout << res << endl;
        print(b, n);
        return;
    }
    vector<int> send, recv; 
    // cout << "----" << endl;
    for(int i = 1; i <= n; ++i){
        if(!taken[i]){
            int r = i; 
            int s = i;
            while(b[s]){
                s = b[s];
            }
            send.push_back(s); 
            recv.push_back(r); 
        }
    }
    for(int i =0; i < send.size(); ++i){
        if(i == send.size()-1){
            // cout << "hellooo" << endl;
            // cout << send[i] << " " << recv[0] << endl;
            b[send[i]] = recv[0];
            continue;
        }
        b[send[i]] = recv[i+1];
    }
    if(send.size() == 1 &&  send[0] == recv[0]){
        b[send[0]] = a[send[0]];
        b[taken[a[send[0]]]] = send[0];
    }
    cout << res << endl;
    print(b, n);
    return;
}


int main(){ 
    int t; 
    cin >> t; 
    while(t--){
        solve();
    }

}
