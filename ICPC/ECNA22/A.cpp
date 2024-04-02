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

const int N = 0; 
const int E = 1;
const int S = 2; 
const int W = 3;
const int INF = 10000;
int char_to_dir[256];
struct Directions{ 
    bool directions[4] = {true,true,true,true}; //N E S W 
};
int directions[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
struct State{ 
    int x; 
    int y;
    int direction;
};
Directions maze[52][52];
int distances[52][52][52][52][4][2];

void move_forward(deque<pair<State,State>>& bfs, State robot1, State robot2, int move, int prev_bump){ 
    auto& [dy1, dx1] = directions[robot1.direction]; 
    auto& [dy2, dx2] = directions[robot2.direction];
    int bump = 0; 
    if(maze[robot1.y][robot1.x].directions[robot1.direction]){
        robot1.y += dy1; 
        robot1.x += dx1;
    }else{ 
        bump += (robot1.y != 0);
    }
    if(maze[robot2.y][robot2.x].directions[robot2.direction]){ 
        robot2.y += dy2; 
        robot2.x += dx2;
    }else{ 
        bump += (robot2.y != 0);
    }
    if(bump == 2){ 
        return;
    }
    if(robot1.y != 0 && robot2.y != 0 && robot2.x == robot1.x && robot2.y == robot1.y){ 
        return;
    }
    // if(robot1.x < 1 || robot2.x < 1 || robot1.x > 7 || robot2.x > 7 || robot1.y < 1 || robot2.y <1|| robot1.y > 4 || robot2.y > 4  ){ 
    //     cout << robot1.x << " " << robot1.y << " " << robot1.direction << " " << dx1 << " " << dy1 << endl;
    //     cout << robot2.x << " " << robot2.y << " " << robot2.direction << " " << dx2 << " " << dy2 << endl;
    //     cout << "one robot finished " << move << endl;
    // }
    if(distances[robot1.y][robot1.x][robot2.y][robot2.x][robot1.direction][0] < move+1 ){ 
        return;
    }
    if(distances[robot1.y][robot1.x][robot2.y][robot2.x][robot1.direction][0] == move+1){ 
        distances[robot1.y][robot1.x][robot2.y][robot2.x][robot1.direction][1] = min(prev_bump+bump, distances[robot1.y][robot1.x][robot2.y][robot2.x][robot1.direction][1]);   
        return;
    }
    // cout << "move start" << endl;
    // cout << robot1.x << " " << robot1.y << " " << robot1.direction << " " << dx1 << " " << dy1 << endl;
    // cout << robot2.x << " " << robot2.y << " " << robot2.direction << " " << dx2 << " " << dy2 << endl;
    // cout << "move: " << move << endl;
    distances[robot1.y][robot1.x][robot2.y][robot2.x][robot1.direction][0] = move+1;   
    distances[robot1.y][robot1.x][robot2.y][robot2.x][robot1.direction][1] = min(prev_bump+bump, distances[robot1.y][robot1.x][robot2.y][robot2.x][robot1.direction][1]);   
    bfs.emplace_back(robot1, robot2);
}
void change_directions( deque<pair<State,State>>& bfs, State robot1, State robot2, int move, int prev_bump){ 
    for(int i = 1; i <= 3; i++){ 
        robot1.direction++; 
        robot1.direction %= 4;
        robot2.direction++; 
        robot2.direction %= 4;
        auto [dist, bumps] = distances[robot1.y][robot1.x][robot2.y][robot2.x][robot1.direction];
        if(dist > move){
            // cout << robot1.x << " " << robot1.y << " " << robot1.direction << endl;
            // cout << robot2.x << " " << robot2.y << " " << robot2.direction << endl; 
            distances[robot1.y][robot1.x][robot2.y][robot2.x][robot1.direction][0] = move;
            distances[robot1.y][robot1.x][robot2.y][robot2.x][robot1.direction][1] = prev_bump;
            bfs.emplace_front(robot1, robot2);     
        }else if(dist == move && prev_bump < bumps){ 
            distances[robot1.y][robot1.x][robot2.y][robot2.x][robot1.direction][1] = prev_bump;
        }
    }
}

void find_shortest_path(deque<pair<State,State>>& bfs, int e){ 
    while(bfs.size()){ 
        // cout << bfs.size() << endl;
        auto [robot1, robot2] = bfs.front();

        bfs.pop_front();
        int prev_bump = distances[robot1.y][robot1.x][robot2.y][robot2.x][robot1.direction][1];
        int move =  distances[robot1.y][robot1.x][robot2.y][robot2.x][robot1.direction][0];
        // cout << "BFS start1" << endl;
        // cout << robot1.x << " " << robot1.y << " " << robot1.direction << endl;
        // cout << robot2.x << " " << robot2.y << " " << robot2.direction << endl;
        // cout << "BFS move: " << move << endl;
        if(distances[0][e][0][e][S][0] < move) return;
        change_directions(bfs, robot1, robot2, move, prev_bump);
        // cout << "BFS start2" << endl;
        // cout << robot1.x << " " << robot1.y << " " << robot1.direction << endl;
        // cout << robot2.x << " " << robot2.y << " " << robot2.direction << endl;
        // cout << "BFS move: " << move << endl; 
        move_forward(bfs, robot1, robot2, move, prev_bump); 
    }
    return;
}
void print_maze(int c, int r){ 
    for(int i = 1; i <= c; i++){
        cout << " ";
        if(!maze[1][i].directions[S]){ 
            cout << "-";
        }else{ 
            cout << " ";
        }
        cout << " ";

    }
    cout << endl;
    for(int i = 1; i <= r; i++){ 
        if(!maze[i][1].directions[W]){ 
            cout << "|";
        }else{ 
            cout << " ";
        }

        for(int j = 1; j <= c; j++){ 
            cout << i << j; 
            if(!maze[i][j].directions[E]){ 
                cout << "|";
            }else{ 
                cout << " ";
            }
        }
        cout << endl;
        for(int j = 1; j <= c; j++){ 
            cout << " ";
            if(!maze[i][j].directions[N]){ 
                cout << "-";
            }else{ 
                cout << " ";
            }
            cout << " ";
            
        }
        cout << endl;
    }
}

void solve(){
    char_to_dir['N'] = 0; 
    char_to_dir['E'] = 1; 
    char_to_dir['S'] = 2; 
    char_to_dir['W'] = 3; 
    int c,r ,e;
    cin >> c >> r >> e;
    for(int i = 1; i <=c; i++){ 
        maze[1][i].directions[S] = false; 
        maze[r][i].directions[N] = false;
    }
    for(int i = 1; i <= r; i++){ 
        maze[i][1].directions[W] = false; 
        maze[i][c].directions[E] = false;
    }
    //set the exit to true;
    maze[1][e].directions[S] = true;
    for(int i =0; i <= c; i++){ 
        maze[0][i].directions[N] = false;
        maze[0][i].directions[E] = false;
        maze[0][i].directions[S] = false;
        maze[0][i].directions[W] = false;
    }
    maze[0][e].directions[N] = false;
    maze[0][e].directions[E] = false;
    maze[0][e].directions[S] = false;
    maze[0][e].directions[W] = false;
    deque<pair<State,State>> bfs;
    int x1, y1, x2, y2; 
    char d1,d2; 
    cin >> x1 >> y1 >> d1;
    cin >> x2 >> y2 >> d2; 
    memset(distances, 63, sizeof(distances));

    distances[y1][x1][y2][x2][char_to_dir[d1]][1] = 0; 
    distances[y1][x1][y2][x2][char_to_dir[d1]][0] = 0; 


    pair<State,State> start = make_pair( State{x1,y1,char_to_dir[d1]} , State{x2,y2,char_to_dir[d2]});
    int n; 
    cin >> n; 
    //horizontal walls
    for(int i =0; i < n; i++){ 
        int wallr, wallc; 
        cin >> wallc >> wallr; 
        maze[wallr][wallc].directions[N] = false;
        maze[wallr+1][wallc].directions[S] = false; 
    }
    //vertical wall
    cin >> n; 
    for(int i =0; i < n; i++){ 
        int wallr, wallc; 
        cin >> wallc >> wallr; 
        maze[wallr][wallc].directions[E] = false; 
        maze[wallr][wallc+1].directions[W] = false;
    }
    maze[1][e].directions[S] = true;

    // print_maze(c,r);

    // for(int i = 1; i <= r; i++){ 
    //     for(int j = 1; j <= c; j++){ 

    //     }
    // }
    bfs.push_back(start); 
    // cout << start.first.direction << " " << start.second.direction  << endl;
    find_shortest_path(bfs, e);
    // move_forward(deque<pair<State,State>>& bfs, State robot1, State robot2, int move, int prev_bump){ 

    // cout << distances[1][e][1][e][S][0] << " " << distances[1][e][1][e][S][1] << endl;

    cout << distances[0][e][0][e][S][0] << " " << distances[0][e][0][e][S][1] << endl;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    solve();
}
