#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region
#define ll long long
#pragma endregion
ll char_to_int[256];
char int_to_char[40];
ll matrix[10][10]; 

void get_components(string&s , int n, vector<vector<ll>>& components){ 
    int i = 0;
    while(i < s.size()){
        vector<ll> compon;
        for(int j =0; j < n; j++){ 
            if(i+j<s.size()){
                compon.push_back(char_to_int[s[i+j]]);

            }else{ 
                compon.push_back(char_to_int[' ']);
            }
        }
        i += n;
        components.push_back(compon);
        // cout  << "hello" << endl;
    }
}
void multiple_row(int i, const vector<ll>& comp){ 
    ll res = 0;
    for(int j =0; j < comp.size(); j++){ 
        // cout << matrix[i][j] << " ";
        res += comp[j]*matrix[i][j];
    }
    // cout << endl;
    res %= 37; 
    cout << int_to_char[res];
    // cout << endl;
}
void encrypt_comp(int n,const vector<ll>& comp){ 
    for(int i =0; i < n; i++){ 
        multiple_row(i,comp);
    }
}
void compute_encryption(int n, vector<vector<ll>>& components){ 
    for(const auto& comp: components){ 
       encrypt_comp(n, comp); 
    }
}
void solve(){
    int n; 
    cin >> n; 
    //set up char to int
    for(char c = 'A'; c <= 'Z'; c++){ 
        char_to_int[c] = c-'A';
    }
    for(char i = '0'; i <= '9'; i++){ 
        char_to_int[i] = (i-'0')+26;
    }
    char_to_int[' '] = 36;

    //set int to char 
    for(char c = 'A'; c <= 'Z'; c++){ 
        int_to_char[c-'A'] = c;
    }
    for(char i = '0'; i <= '9'; i++){ 
        int_to_char[(i-'0')+26] = i;
    }
    int_to_char[36] = ' ';
    // for(int i =0; i < 36; i++){ 
    //     cout << int_to_char[i] << " ";
    // }
    // cout << endl;

    for(int i =0; i < n; i++){ 
        for(int j =0; j < n; j++){ 
            ll val; 
            cin >> val; 
            matrix[i][j] = val;
            // cout << val << endl; 
        }
    }
    cin.get();
    string s; 
    getline(cin, s);
    // cout << s << endl;
    vector<vector<ll>> components;  
    // cout << "HELLOOO" << endl;
    get_components(s, n, components);
    // for(int i =0; i < components.size(); i++){ 
    //     for(int j =0; j < components[i].size(); j++){ 
    //         cout << components[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    compute_encryption(n, components);
    cout << endl; 
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);  
    solve();

}
