#include<bits/stdc++.h>
// g++-14 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#define ll long long




void solve(){
    int p, u; 
    cin >> p >> u;
    vector<int> pinned; 
    vector<int> unpinned; 
    vector<bool> is_org_pinned(p+u+1, false);
    vector<bool> is_suppose_pinned(p+u+1, false);
    vector<bool> is_set(p+u+1, false);
    for(int i =0; i < p; i++){ 
        int file; 
        cin >> file; 
        pinned.push_back(file);
        is_org_pinned[file] = true;

    }
    for(int i =0; i < u; i++){ 
        int file; 
        cin >> file; 
        unpinned.push_back(file);
    }
    int fp, fu; 
    cin >> fp >> fu; 
    vector<int> final_pinned; 
    vector<int> final_unpinned; 
    for(int i =0; i < fp; i++){ 
        int file; 
        cin >> file; 
        final_pinned.push_back(file);
        is_suppose_pinned[file] = true;
    }
    for(int i =0; i < fu; i++){ 
        int file; 
        cin >> file; 
        final_unpinned.push_back(file);
    }
    reverse(final_unpinned.begin(), final_unpinned.end());
    reverse( unpinned.begin(), unpinned.end());
    int ops = 0;
    for(int pinned_file : final_pinned){ 
        if (is_org_pinned[pinned_file]){ 
            int i = 0;
            while(pinned[i] != pinned_file){ 
                i++;
            }
            int file_loc = i;
            i++; 
            for(; i < pinned.size(); i++){ 
                int cur_file = pinned[i]; 
                if(is_set[cur_file] && is_suppose_pinned[cur_file]){ 
                    ops += 2;
                    pinned.erase( pinned.begin()+file_loc);
                    pinned.push_back(pinned_file);
                    break;
                }
            }
        }else{ 
            ops += 1; 
            auto itr = find(unpinned.begin(), unpinned.end(), pinned_file);
            unpinned.erase(itr);
            pinned.push_back(pinned_file);
        }
        is_set[pinned_file] = true;
    }
    for(int unpinned_file : final_unpinned){ 
        if (is_org_pinned[unpinned_file]){ 
            ops += 1;; 
            auto itr = find(pinned.begin(), pinned.end(), unpinned_file); 
            pinned.erase(itr);
            unpinned.push_back( unpinned_file);
        }else{ 
            int i = 0;
            while(unpinned[i] != unpinned_file){ 
                i++;
            }
            int file_loc = i;
            i++; 
            for(; i < unpinned.size(); i++){ 
                int cur_file = unpinned[i]; 
                if(is_set[cur_file] && !is_suppose_pinned[cur_file]){ 
                    ops += 2;
                    unpinned.erase(unpinned.begin()+file_loc);
                    unpinned.push_back(unpinned_file);
                    break;
                }
            }

        }
        is_set[unpinned_file] = true;
    }
    cout << ops << endl;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
}