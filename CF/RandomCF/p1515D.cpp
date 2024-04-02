#include<bits/stdc++.h>
//https://codeforces.com/problemset/problem/1515/D
using namespace std;

void print(int socks[], int n){
    cout << "Socks: ";
    for(int i =0; i <n+1; ++i){
        cout << socks[i] << " ";
    }
    cout << endl;
}

int solve(){
    int n, l,r;
    cin >> n >> l >> r; 
    int socks[n+1];
    for(int i = 0; i < n+1; ++i){
        socks[i] = 0;
    }
    int v;
    int lc = l; 
    int rc = r;
    int sock;
    for(int i = 0 ; i < l; ++i){ 
        cin >> sock; 
        socks[sock] += 1; 
        
    }
    for(int i = 0 ; i < r; ++i){ 
        cin >> sock; 
        if(socks[sock] > 0){
            lc -= 1;
            rc -= 1;
        }
        socks[sock] -= 1;
    }
    // print(socks, n);
    int cost = 0; 
    // cout <<"count: "<< lc << " " << rc << endl;
    if(lc > rc){
        // cout << "left count more" << endl;
        cost = rc;
        for(int i =1; i < n+1; ++i){ 
            if(socks[i] > 0){
                int pairs = socks[i] >> 1;
                // cout << "pairs " <<pairs << endl;

                lc -= (pairs << 1);
                cost += pairs;
            }
            if(lc <= rc){
                cost -= (rc-lc)/2;
                lc = rc;
                break;
            }
        }
        cost += (lc-rc);
    }else if(lc < rc){
        // cout << "right count more" << endl;
        cost = lc;
        for(int i =1; i < n+1; ++i){ 
            if(socks[i] < 0){
                socks[i] *= -1;
                int pairs = socks[i] >> 1;
                // cout << "pairs " <<pairs << endl;
                rc -= (pairs << 1);
                cost += pairs;
            }
            if(rc <= lc){
                
                cost -= (lc-rc)/2;
                rc = lc;
                break;
            }
        }
        cost += (rc-lc);
    }else{ 
        return lc;
    }
    return cost;
}

int main(){ 
    int t; 
    cin >> t; 
    for(int i = 0; i < t; ++i){

        cout << solve() << endl;;
    }

}
