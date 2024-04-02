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



int solve(string f, string s, char t_store,  vector<pair<int,int>>& res){ 
    bool is_holding = false;

    while(s.size() > 1 || f.size() > 1){ 
        // cout << s.back() << " " << f.back() << endl;
        if(s.size() == 0 || f.size() == 0 ||s.back() == f.back()){ 
            if(s.size() > f.size()){
                if(f.size() == 0){ 
                    f.push_back(s.back());
                }
                s.pop_back(); 
                res.push_back({2,1});
            }  else{ 
                if(s.size() == 0){
                    s.push_back(f.back());
                }
                f.pop_back();
                res.push_back({1,2});
            }
        }else{ 

            if(s.back() == t_store){ 
                s.pop_back(); 
                res.push_back({2,3});
            }else{ 
                f.pop_back();
                res.push_back({1,3});
            }
            is_holding = true;
        }
    }
    if(s.size() > 0 && f.size() > 0 && s.back() == f.back()){
        res.push_back({1,2});
    }

    if(is_holding){
        if(s.size() == 0){ 
            if(f.back() == t_store){ 
                res.push_back({3,1});
            }else{ 
                res.push_back({3,2});
            }
        }else if(f.size() == 0){ 
            if(s.back() == t_store){ 
                res.push_back({3,2});
            }else{ 
                res.push_back({3,1});
            }

        }else{ 

            if(s.back() == t_store){ 
                res.push_back({3,2});
            }else{ 
                res.push_back({3,1});
            }
        }
    }
    return res.size();

}


void solve(){

    int N, P; 
    cin >> N >> P;
    string f; 
    cin >> f;
    string s; 
    cin >> s;
    // cout << f << " " << s << endl;
    string simplified_s;
    string simplified_f;
    simplified_s += s[0];
    simplified_f += f[0];
    for(int i = 1; i < s.size(); i++){ 
        if(s[i] != s[i-1]){ 
            simplified_s += s[i];
        }
    }
    for(int i = 1; i < f.size(); i++){
        if(f[i] != f[i-1]){ 
            simplified_f += f[i];
        }
    }
    // cout << simplified_f << " " << simplified_s << endl;
    vector<pair<int,int>>  res1;
    vector<pair<int,int>>  res2;
    solve(simplified_f, simplified_s, '1', res1);
    solve(simplified_f, simplified_s, '2', res2);
    // cout << "RES1: " << endl;
    // for(auto [a,b] : res1){ 
    //     cout << a << " " << b << endl;
    // }
    // cout << "RES2: " << endl;
    // for(auto [a,b] : res2){ 
    //     cout << a << " " << b << endl;
    // }
    if(res1.size() <= res2.size()){
        cout << res1.size() << endl; 
        if(P > 1){ 
            for(auto [a,b] : res1){ 
                cout << a << " " << b << endl;
            }
        }
    }else{ 
        cout << res2.size() << endl; 
        if(P > 1){ 
            for(auto [a,b] : res2){ 
                cout << a << " " << b << endl;
            }
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
        // cout << endl;
    }

}
