#include<bits/stdc++.h>
#include <bitset>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long

#pragma endregion
ll dp[4005];
const ll MOD = 100007;
size_t addrs[70000];
void solve(){
    int n; 
    cin >> n; 
    for(int i =0; i < n; i++){ 
        size_t sect; 
        char blank;
        size_t addr = 0; 
        cin >> sect; 
        addr += (sect << 24);

        cin >> blank;
        cin >> sect; 
        addr += (sect << 16); 

        cin >> blank; 
        cin >> sect;
        addr += (sect << 8); 

        cin >> blank; 
        cin >> sect; 
        addr += sect; 

        addrs[i] = addr;   
    }
    int ind = -1;
    size_t prev = addrs[0];
    // cout << bitset<32>(addrs[0]) << endl;

    for(int i =1; i < n; i++){ 
        size_t current = addrs[i];
        // cout << bitset<32>(addrs[i]) << endl;
        for(int j =ind; j < 32; j++){ 
            size_t bit = 1 << j;
            if((prev & bit) != (current & bit)){ 
                ind = j;
            }
        }
        prev = current;
    } 
    int res =  32-(ind+1);
    if(res == 0){ 
        cout << 32 << endl;
    }else{
    cout << 32-(ind+1) << endl;
    }

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve(); 
}
