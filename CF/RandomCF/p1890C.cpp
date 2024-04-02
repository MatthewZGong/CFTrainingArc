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

// void print_s(vector<char>& left, vector<char>& right){ 
//     for(int i =0; i < left.size(); i++){ 

//     }
// }
int solve(){
    int n; 
    cin >> n; 
    string s; 
    cin >> s;
    // cout << s << endl;
    int bal = 0; 
    for(int i =0; i < n; i++){ 
        if(s[i] == '1') bal++;
        if(s[i] == '0') bal--;
    }
    if(bal != 0){
        cout << "-1" << endl; 
        return 0;
    }

    vector<int> seq; 
    deque<char> word;
    for(int i =0; i < n; i++){ 
        word.push_back(s[i]);
    }
    int i = 0, j = n; 
    while(seq.size() <= 300 && word.size()){ 

        if(word.front() != word.back()){ 
            i++;
            j--; 
            // cout << *(left.end()-1) << " " << *(right.end()-1) << endl;
            word.pop_back();
            word.pop_front();
        }else{ 
            if(word.front() == '0'){ 
                word.push_back('0'); 
                word.push_back('1');
                seq.push_back(j); 
            }else{ 
                word.push_front('1'); 
                word.push_front('0'); 
                seq.push_back(i);
            }
            j += 2; 
        }
    }
    // cout << seq.size() << endl;
    if(seq.size() > 300){ 
        cout << "-1" << endl;
        return 0; 
    }
    cout << seq.size() << endl; 
    for(int i =0; i < seq.size(); i++){ 
        cout << seq[i] << " "; 
    }
    cout << endl;

    return 0; 
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    int i = 0; 
    while(t--){
        // cout << i++ << endl;
        solve();
    }

}
