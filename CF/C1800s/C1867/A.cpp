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


int solve(){
    int n, m; 
    cin >> n >> m;
    string x, s; 
    cin >> x >> s; 
    // cout << x << endl;
    while(x.size() < 2*m || x.size() < 2*n){ 
        x += x; 
    }
    // cout << x << endl; 
    int ind = x.find(s);
    if(ind ==  string::npos){ 
        return -1;
    }else{ 
        // cout <<"Ind: "<< ind << endl;
        ind += (s.size()-1);
        int res = 0;
        int start = n; 
        while(start <= ind){ 
            res += 1; 
            start += start;
        }
        return res;
    }
    
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        
        cout << solve() << endl;
    }

}
