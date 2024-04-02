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
#pragma endregion

pair<int,int> caseA(int i, string& s){
    int res = 0; 
    int smallest = 0;
    int length = 0;
    bool empty = true;
    while(i < s.size()){
        if(s[i] != 'A'){ 
            empty = false;
            if(length == 0){ 
                // cout << "got here" << endl;
                return make_pair(res, i);
            }
            if(smallest == 0){ 
                smallest = length;
            }else{ 
                smallest = min(length, smallest);
            }
            res += length;
            length = 0;
            if(s[i] == 'C'){ 
                return make_pair(res-smallest, i);
            }
        }else{ 
            length++;
        }
        i++;
    }
    if(!empty){
        res += length;
        smallest = min(length, smallest);
    }

    // cout << "got here 2" << endl;
    return make_pair(res-smallest, i-1);    
}
pair<int, int> caseB(int i, string& s){ 
    int res = 0;
    while(i < s.size()){ 
        if(s[i] != 'A'){ 
            return make_pair(res, i);
        }
        i++;
        res++;
    }
    return make_pair(res, i-1);
}

void solve(){
    string s; 
    cin >> s;
    int coins = 0;
    char prev = 'C';
    int i =0;
    while(i < s.size()){ 
        if(s[i] == 'A'){ 
            if(prev == 'C'){ 
                pair<int,int> tmp  = caseA(i, s);
                coins += tmp.first; 
                i = tmp.second;
            }else{ 
                pair<int,int> tmp = caseB(i, s);
                coins += tmp.first; 
                i = tmp.second;
            }
        }
        prev = s[i];
        i++;
    }
    cout << coins << endl;

}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int t; 
    cin >> t; 
    while(t--){
        // cout << "----------------------" << endl;
        solve();
        // cout << "----------------------" << endl;
    }

}
