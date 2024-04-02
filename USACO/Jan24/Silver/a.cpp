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
int N, Q, C;
int c[1'00'001]; 
bool was_set[1'00'001];
int q[1'00'001];
void solve(){
    cin >> N >> Q >> C; 
    for(int i = 1; i <= N; i++){ 
        q[i] = 0;
        was_set[i] = false;
        cin >> c[i];
        if(c[i]){ 
            was_set[i] = true;
        }else{ 
            c[i] = 1;
        }
    }
    for(int i = 0; i < Q; i++){ 
        int a, h; 
        cin >> a >> h; 
        q[a] = h;
    }
    for(int i = 1; i <= N; i++){ 
        if(q[i]){ 
            int j = i+1;
            for(; j < q[i]; j++){ 
                if(q[j] && q[j] != q[i]){ 
                    cout << -1 << endl;
                    return;
                }
                q[j] = q[i];
            }
            i = j-1;
        }
    }
    int cur_max = 1;
    int next_max = 1;
    for(int i = 1; i <= N; i++){ 
        cur_max = max(cur_max, c[i]);
        next_max = max(next_max, c[i]);
        if(q[i] == 0){ 
            continue;
        }
        next_max = max(next_max, *max_element(c+i, c+q[i])); 

        if( next_max > cur_max){
            int j = i;
            for(; j >= 1; j--){ 
                if(q[j] != 0 && q[j] != q[i]){ 
                    cout << -1 << endl;
                    return;
                }
                if(!was_set[j]){ 
                    c[j] = next_max;
                    break;
                }
            }
            if(j == 0){ 
                cout << -1 << endl;
                return;
            }
        }
        cur_max = max(cur_max, next_max);
        if(!was_set[q[i]]){ 
            c[q[i]] = next_max+1;
        }
        if(c[q[i]] <= next_max){ 
            cout << -1 << endl;
            return;
        }
        i = q[i]-1;
    }

    for(int i = 1; i <= N; i++){ 
        if(c[i] > C){ 
            cout << -1 << endl;
            return;
        }
    }
    for(int i = 1; i <= N; i++){ 
        if(i == N) cout << c[i] << endl;
        else cout << c[i] << " ";
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
