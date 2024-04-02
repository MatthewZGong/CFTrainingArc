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

// // struct Score{ 
// //     int i; 
// //     int s; 
// //     int p; 
// // };
// int times[200005];
// pair<ll, LL> b[200005];
// int solve(){
//     int n, m, h; 
//     cin >> n >> m >> h; 
//     for(int i = 0 ; i < n; i++){ 
//         // vector<int> times; 
//         for(int j =0; j < m; j++){ 
//             int h; 
//             cin >> h; 
//             times[j] = h;
//         }
//         sort(times, times+m); 
//         int s = 0; 
//         int p = 0;
//         int t = 0;
//         for(int j =0; j < m; j++){ 
//             t += times[j]; 
//             if(t <= h){ 
//                 s++;
//                 p += t;
//             }else{ 
//                 break;
//             }
//         }
//         b[i].i = i; 
//         b[i].s = s; 
//         b[i].p = p;
//     }
//     sort(b, b+n, );
//     for(int i =0; i <n; i++){ 
//         // cout << board[i].s  << " " << board[i].p << " " << board[i].i << endl;
//         if(b[i].i == 0){ 
//             cout << i+1 << endl;
//         }
//     }
//     // cout << "____" << endl;

    

// }

// struct Score{ 
//     int i; 
//     int s; 
//     int p; 
// };
int times[200005];
pair<ll, ll> b[200005];
int solve(){
    int n, m, h; 
    cin >> n >> m >> h; 
    pair<ll, ll> res; 
    for(int i = 0 ; i < n; i++){ 
        // vector<int> times; 
        for(int j =0; j < m; j++){ 
            int h; 
            cin >> h; 
            times[j] = h;
        }
        sort(times, times+m); 
        ll s = 0; 
        ll p = 0;
        ll t = 0;
        for(int j =0; j < m; j++){ 
            t += times[j]; 
            if(t <= h){ 
                s++;
                p += t;
            }else{ 
                break;
            }
        }
        b[i].first = s; 
        b[i].second = p;
        if(i == 0){ 
            res = b[i];
        }
    }
    sort(b, b+n, [&](pair<ll,ll> a, pair<ll,ll> b){ 
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    });
    for(int i =0; i <n; i++){ 
        if(b[i] == res){ 
            cout << i+1 << endl;
            return 0;
        }
    }
    return 0; 

    

}
int main(){
    int t; 
    cin >> t; 
    while(t--){
        solve();
    }

}
