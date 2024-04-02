#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long

#pragma endregion
void solve(){
    vector<int> found; 
    int n; 
    cin >> n; 
    int k; 
    cin >> k;
    if(k == 0){
        cout << 0 << endl; 
        return;
    }
    int i = 2;
    for(; i <= n; i++){
        int target; 
        cin >> target;
        int sum = 0; 
        for(int j= 0; j < found.size(); j++){ 
            sum += i%found[j]; 
        } 
        sum += i*(k-found.size()); 
        int diff = sum - target; 
        for(int j =0; j < diff/i; j++){ 
            found.push_back(i); 
        }
        if(found.size() == k){ 
            break;
        }
    }
    // while(found.size() < k){ 
    //     found.push_back(i);
    // }
    cout << k << " "; 
    for(int i =0; i < found.size(); i++){ 
        cout  << found[i] << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve(); 
}
