#include<bits/stdc++.h>
#include<string>
// g++-12 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;

#pragma region

char board[3][3]; 
void print(int v[], int n){
    for(int i =0 ; i < n; ++i){ 
        cout << v[i] << " ";
    }
    cout << endl;
}
#pragma endregion

int solve(){

    string win;

    for(int i =0; i < 3; ++i){ 
        int hcount = 0;
        for(int j =0; j < 3; ++j){ 
            cin >> board[i][j];
            if(j != 0 and board[i][j] == board[i][j-1]){ 
                hcount++;
            }else if(j == 0){ 
                hcount ++;
            }else{ 
                hcount = 0;
            }
        }
        if(hcount == 3){ 
            win.push_back(board[i][0]);
        }
    }
    for(int i =0; i <3; ++i){ 
        int vcount = 0; 
        for(int j =0; j < 3; ++j){ 
            if(j != 0 and board[j][i] == board[j-1][i]){ 
                vcount++;
            }else if(j == 0){ 
                vcount ++;
            }else{ 
                vcount = 0;
            }
        }
        if(vcount == 3){ 
           win.push_back(board[0][i]);
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] ==board[2][2]){ 
        win.push_back(board[1][1]);
    }
    if(board[2][0] == board[1][1] && board[1][1] ==board[0][2]){ 
        win.push_back(board[1][1]);
    }
    if(win.size() != 0 and win[0] != '.'){
        cout << win << endl;
    }else{
        cout << "DRAW" << endl;
    }
}

int main(){
    int t; 
    cin >> t; 
    while(t--){
        solve();
    }

}
