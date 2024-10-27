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
    vector<vector<int>> park; 
    vector<int> ascending; 
    vector<int> descending; 
    for(int i =0; i < n; i++){ 
        park.push_back({});
        for(int j =0; j < m; j++){ 
            int statue; 
            cin >> statue;
            park[i].push_back(statue);
            ascending.push_back(statue); 
            descending.push_back(statue);
        }
    }
    sort(ascending.begin(), ascending.end());
    sort(descending.begin(), descending.end(), std::greater<int>());

    int NE = 0; 
    int SW = 0;

    for(int i =0; i < n; i++){ 
        while(i < 0)
    }


    int NW = 0; 
    int SE = 0; 

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
}
