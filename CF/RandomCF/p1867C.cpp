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

bool nums[100001];
bool solve(){
    int n; 
    cin >> n; 
    for(int i =0;i <= n; i++){ 
        nums[i] = false;
    }
    for(int i =0; i < n; i++){ 
        int num; 
        cin >> num; 
        if(num <= n)
            nums[num] = true;
    }
    
    int i = 0;
    while(nums[i]) i++;
    cout << i << endl;
    cout.flush();
    bool play = true;
    while(play){ 
        int move;
        cin >> move; 
        if(move == -1){ 
            return true;
        }else if(move == -2){ 
            return false;
        }
        cout << move << endl;
        cout.flush();
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t-- && solve()){
    }

}
