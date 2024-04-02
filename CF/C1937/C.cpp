#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
template<typename T>
void print(T v[], int n, int i = 0){
    for(; i < n; ++i){ 
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

char query(int a, int b, int c, int d){ 
    cout <<"? " <<  a << " " << b << " " << c << " " <<  d << endl;
    char judge; 
    cin >> judge; 
    return judge;
}

void solve(){
    int n; 
    cin >> n; 
    int largest = 0; 
    for(int i = 1; i < n; i++){ 
        char judge = query(largest, largest, i, i); 
        if(judge == '<'){ 
            largest = i;
        }
    }
    vector<int> candidates = {0};
    int target = 0;
    for(int i = 1; i < n; i++){ 
        char judge = query(largest, target, largest, i); 
        if(judge == '<'){ 
            target = i; 
            candidates = {i};
        }else if(judge == '='){ 
            candidates.push_back(i);
        }
    }

    int comp = candidates[0]; 
    for(int i = 1; i <candidates.size(); i++){ 
        char judge = query(comp, comp, candidates[i], candidates[i]); 
        if(judge == '>'){ 
            comp = candidates[i];
        }
    }

    cout << "! " << comp << " " << largest << endl;



}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
    }
    return 0;
}
