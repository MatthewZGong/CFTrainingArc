#include<bits/stdc++.h>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;
 
#pragma region
#define ll long long
#pragma endregion
 

int counts[15]; 
int cards[105];
ll dp[105][15];
map<char, int> card_map {
    {'A', 1},
    {'2', 2},
    {'3', 3}, 
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'T', 10},
    {'J', 11},
    {'Q', 12},
    {'K', 13}
};
// map<int, int> test {
//     make_pair(1,2),
//     make_pair(2,3)
// };
ll solve_sum(int i, int sum){ 
    if(sum < 0){ 
        return 0;
    }
    if(sum == 0){ 
        return 1;
    }
    if(i < 0) return 0;
    if(dp[i][sum]){ 
        return dp[i][sum];
    }

    ll res = 0;
    res += solve_sum(i-1, sum-cards[i]);
    res += solve_sum(i-1, sum);
    // cout << i << " " << sum << " " << free << " " << res << endl;
    dp[i][sum] = res;
    return res;
}
ll comb2(ll n){ 
    return n*(n-1)/2;
}

void get_score(int n){ 
    ll score = 0; 
    int length = 0;
    ll len_score = 1;

    //runs
    for(int i =1 ; i <= 13; i++ ){ 
        if(counts[i] == 0){ 
            if(length >= 3){ 
                score += length*len_score;
            }
            length = 0; 
            len_score = 1;
        }else{ 
            len_score *= counts[i];
            length += 1;
        }
        // cout << length*len_score << " ";
    }
    // cout << endl;
    if(length >= 3){ 
        score += length*len_score;
    }
    // cout << score << endl; 
    //repeats
    for(int i = 1; i <= 13; i++){ 
        if(counts[i] >= 2){ 
            score +=  2*comb2(counts[i]);
        }
    }
    // cout << score << endl;
    //sums 
    score += 2*solve_sum(n-1, 15);
    cout << score << endl; 
}
void solve(){
    int n; 
    cin >> n; 
    for(int i =0; i < n; i++){ 
        char card; 
        cin >> card; 
        int val = card_map[card]; 
        counts[val] += 1; 
        cards[i] = min(10,val);
    }
    // for(int i =0; i < n; i++){ 
    //     cout << cards[i] << " "; 
    // }
    // cout << endl;
    // cout << endl;
    // for(int i = 1; i <= 13; i++){ 
    //     cout << sums[i] << " ";
    // }
    // cout << endl;
    // for(int i = 1; i <= 13; i++){ 
    //     cout << counts[i] << " ";
    // }
    // cout << endl;
    get_score(n);
}   
 
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
}