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

vector<int> stacks[100005];
int plates[100005];
void print_plates(int start){ 
    cout << "____________" << endl;
    int i = start; 
    while(stacks[i].size() > 0){ 
        for(int j =0; j < stacks[i].size(); j++){ 
            cout << stacks[i][j] << " ";
        }
        cout << endl;
        i++;
    }

    cout << "____________" << endl;
}
int find_insert(int start, int end, int val){ 
    while(start < end){ 
        int mid = (start+end)/2; 
        if(val > stacks[mid][0]){ 
            start = mid+1;
        }else{ 
            end = mid;
        }
    }
    if(stacks[end].size() > 0 && val > stacks[end][0]){ 
        start++;
    }
    return start;
}

pair<int,int> clear_plates(int index, int val, int start){
    int res = 0;
    int clean_top = 0;
    for(int i = start; i < index; i++){ 
        res += stacks[i].size();
        clean_top = stacks[i][0];

    }
    vector<int>& stack = stacks[index];
    while(stack[stack.size()-1] < val){
        clean_top = stack[stack.size()-1];
        stack.pop_back();
        res += 1;
    }
    return make_pair(res, clean_top);
}

int solve(int n){ 
    int start = 0;
    int end = 0;
    int clean_top = 0;
    for(int  i  = 0; i < n; i++){ 
        cin >> plates[i];
    }
    int res = 0;
    for(int i =0; i <n ; i++){
        // cout << start << " | " << end << endl;
        // print_plates(start);
        int val = plates[i];
        if(val < clean_top){
            int j = start; 
            while(stacks[j].size()){ 
                res += stacks[j].size();
                clean_top = stacks[j][0];
                j += 1;
            }
            return res;
        }
        int index = find_insert(start,end, val);
        end = max(index,end);
        // cout << index << endl;
        vector<int>& stack = stacks[index];
        if(stack.size() > 0 && stack[stack.size()-1] < val){
            // cout << "hi i am here" << endl;
            pair<int,int>  res_top = clear_plates(index, val, start);
            start = index;
            res += res_top.first; 
            clean_top = res_top.second;
        }
        // if(index == end+1){ 
        //     end = index;
        // }
        stack.push_back(val);
        // cout << start << " | " << end << endl;
        // print_plates(start);
    }
    int j = start; 
    while(stacks[j].size()){ 
        res += stacks[j].size();
        clean_top = stacks[j][0];
        j += 1;
    }
    return res;
    
}

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    ios::sync_with_stdio(false); 
    setIO("dishes");
    cin.tie(nullptr);
    int n; 
    cin >> n;     
    cout << solve(n) << endl;


}