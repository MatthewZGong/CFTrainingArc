#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
template<typename T>
void print(T v[], int n){
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

vector<int> primes; 
bool possible[1000001];
int primes_factors[1000001];
void get_primes(){ 
    for(int i = 2; i < 1000001; i++){ 
        if(possible[i]) continue;
        primes.push_back(i);
        int j = 1; 
        while(j*i < 100001){
            possible[j*i] = true;
            j++;
        }

    }
}
void get_factors(int n, set<int>& used){
    int i = 0;
    while(n > 1 && i < primes.size() && primes[i]*primes[i] <= n){
        int current_prime = primes[i];
        if(n%current_prime == 0){ 
            primes_factors[current_prime]++;
            n/=current_prime;
            used.insert(current_prime);
        }else{ 
            i++;
        }
        // cout << n << endl;
    }
    if(n > 1){
        primes_factors[n]++;
        used.insert(n);
    }
    // assert(n == 1);
            // cout << n << endl;

}
int solve(){
    memset(primes_factors, 0, sizeof(primes_factors));
    int n; 
    cin >> n; 
    set<int> used;
    for(int i =0; i < n; i++){ 
        int val; 
        cin >> val;
        // cout << val << endl;
        get_factors(val, used);
    }
    for(int i: used){
        if(primes_factors[i] % n != 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    get_primes();
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
    }

}
