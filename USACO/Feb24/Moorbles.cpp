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

int mk[3'00'000][4];
pair<int,int> evens[3'00'000]; 
pair<int,int> odds[3'00'000];
pair<bool,int> best_case[3'00'000];
int offsets[3'00'001];
void solve(){
    int N, M, K; 
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++)
    { 
        odds[i].first = 2000;
        odds[i].second = 0;
        evens[i].first = 2000; 
        evens[i].second = 0;
        for(int j = 0; j < K; j++)
        { 
            cin >> mk[i][j];
            if(mk[i][j] % 2 == 1)
            { 
                odds[i].first = min(odds[i].first, mk[i][j]);
                odds[i].second = max(odds[i].second, mk[i][j]);
            }else
            { 
                evens[i].first = min(evens[i].first, mk[i][j]);
                evens[i].second = max(evens[i].second, mk[i][j]);
            }
        }
        if(odds[i].second == 0)
        { 
            best_case[i] = {true, evens[i].first};
        }
        else if(evens[i].second == 0){ 
            best_case[i] = {false, odds[i].first};

        }else if(evens[i].second > odds[i].second){ 
            best_case[i] = {true, -odds[i].second};

        }else if(odds[i].second > evens[i].second){  
            best_case[i] = {false, -evens[i].second} ;
        }else{ 
            assert("SOMETHING WENT WRONG");
        }
    }
    offsets[M] = 0;
    int current_offset = 0;
    int lowest = best_case[0].second;

    for(int i = M-1; i >= 0; i--){ 
        if(best_case[i].second < 0){ 
            if(current_offset > 0){ 
                current_offset = best_case[i].second;
            }else{ 
                current_offset += best_case[i].second;
            }
        }else{
            current_offset += best_case[i].second;
        }
        offsets[i] = current_offset;
    }
    // offsets[0] = lowest; 
    // for(int i = 1; i < M; i++){ 
    //     offsets[i] = offsets[i-1]-best_case[i-1].second;
    // }
    // for(int i = 0; i < M; i++){ 
    //     cout << best_case[i].first << " " << best_case[i].second << " " << offsets[i] << endl;
    // }
    // cout << endl;
    
    int current = N;
    if(offsets[0]+current <= 0){ 
        cout << "-1" << endl;
        return;
    }


    for(int i = 0; i < M; i++){ 
        int next_current = current;
        if(best_case[i].first){ 

            next_current += best_case[i].second;
        }else{ 
            next_current -= odds[i].second; //subtract the largest odd
        }
        if(next_current <= 0 || (next_current+offsets[i+1]) <= 0){
            current += best_case[i].second;
        }else{ 
            current = next_current;
            best_case[i].first = true;
        }
        if(current <= 0 || (current+offsets[i+1]) <= 0){
            break;
        }
    

    }
    for(int i = 0; i < M; i++){ 
        if (best_case[i].first){ 
            cout << "Even";
        }else{ 
            cout << "Odd";
        }
        if(i < M-1){ 
            cout << " ";
        }else{ 
            cout << endl;
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        
        solve();
    }

}
