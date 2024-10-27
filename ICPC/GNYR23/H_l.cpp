#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int INF = 1000000000;

const int EAST = 0;
const int NORTH = 1;
const int WEST = 2;
const int SOUTH = 3;

const int NO_EDGE = -1;

bool first = true;
map<char, int> cm; // 'E' -> EAST
map<int, int> im; // EAST -> WEST

int left90(int dir) {
    return (dir + 1) % 4;
}

int right90(int dir) {
    return (dir + 3) % 4;
}

struct Node {
    int x, y;
    int adj[4][2];

    int get_next_dir(int cur_dir) {
        if (first) {
            first = false;
            return cur_dir;
        }
        // store left to right
        vector<int> v;

        int c = left90(cur_dir);
        if (adj[c][0] != NO_EDGE) {
            v.push_back(c);
        }

        c = right90(c);
        if (adj[c][0] != NO_EDGE) {
            v.push_back(c);
        }

        c = right90(c);
        if (adj[c][0] != NO_EDGE) {
            v.push_back(c);
        }

        if (v.size() == 3) {
            return v[1];
        } else if (v.size() == 2) {
            return v[0];
        } else if (v.size() == 1) {
            return v[0];
        }
        
        return NO_EDGE;
    }

} nodes[2501];

int get_dir_from(Node a, Node b) {
    if (a.x == b.x) {
        if (a.y < b.y) {
            return NORTH;
        } else {
            return SOUTH;
        }
    } else if (a.x < b.x) {
        return EAST;
    } else {
        return WEST;
    }
}

int N, M;

int main() {
    cm['E'] = EAST;
    cm['N'] = NORTH;
    cm['W'] = WEST;
    cm['S'] = SOUTH;


    im[EAST] = WEST;
    im[NORTH] = SOUTH;
    im[WEST] = EAST;
    im[SOUTH] = NORTH;

    for (int i = 1; i <= 2500; ++i) {
        nodes[i].adj[EAST][0] = NO_EDGE;
        nodes[i].adj[EAST][1] = 0;

        nodes[i].adj[NORTH][0] = NO_EDGE;
        nodes[i].adj[NORTH][1] = 0;

        nodes[i].adj[WEST][0] = NO_EDGE;
        nodes[i].adj[WEST][1] = 0;

        nodes[i].adj[SOUTH][0] = NO_EDGE;
        nodes[i].adj[SOUTH][1] = 0;
    }

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> nodes[i].x >> nodes[i].y;
    }

    for (int i = 1; i <= M; ++i) {
        int a, b, w;
        cin >> a >> b >> w;

        int dir = get_dir_from(nodes[a], nodes[b]);

        nodes[a].adj[dir][0] = b;
        nodes[a].adj[dir][1] = w;

        nodes[b].adj[im[dir]][0] = a;
        nodes[b].adj[im[dir]][1] = w;
    }

    int cur; char d;
    cin >> cur >> d;
    int dir = cm[d];

    auto update_edges = [&](pair<int, int> cycle_start, auto &to_subtract) {
        // to_subtract
        // a1 -> a2 -> ... -> v -> ... -> v (STOP)
        int smallest_weight = INF;
        int cur_cnt = 0;
        reverse(to_subtract.begin(), to_subtract.end());
        for (auto [v, dd] : to_subtract) {
            if (make_pair(v, dd) == cycle_start) {
                ++cur_cnt; 
            }

            smallest_weight = min(smallest_weight, nodes[v].adj[dd][1]);
            if (cur_cnt == 2) {
                break;
            }
        }

        cur_cnt = 0;
        for (auto [v, dd] : to_subtract) {
            if (make_pair(v,dd) == cycle_start) {
                ++cur_cnt; 
            }

            nodes[v].adj[dd][1] -= smallest_weight;
            if (nodes[v].adj[dd][1] == 0) {
                nodes[v].adj[dd][0] = NO_EDGE;
            }

            if (make_pair(v,dd) == cycle_start) {
                break;
            }
        }
    };

    bool dead_end = false;
    while (!dead_end) {
        /* cout << "WHAT" << endl; */
        vector<pair<int, int>> to_subtract;
        // stores vec of {node, direction} for subtraction
        
        vector<vector<int>> vis(2501, vector<int>(4, 0));
        int cycle_start_dir = -1;
        while (true) {
            int next_dir = nodes[cur].get_next_dir(dir);
            if (next_dir == NO_EDGE) {
                dead_end = true;
                break;
            }

            if (vis[cur][next_dir]) {
                cycle_start_dir = next_dir;
                break;
            }

            int next_node = nodes[cur].adj[next_dir][0];
            --nodes[cur].adj[next_dir][1];
            --nodes[next_node].adj[im[next_dir]][1];
            if (nodes[cur].adj[next_dir][1] == 0) {
                nodes[cur].adj[next_dir][0] = NO_EDGE;
                nodes[next_node].adj[im[next_dir]][0] = NO_EDGE;
                vis = vector<vector<int>>(2501, vector<int>(4, 0));
                to_subtract.clear();
                cur = next_node;
                dir = next_dir;
                break;
            }

            vis[cur][next_dir] = 1;

            // subtract on the outbound edge of cur
            to_subtract.emplace_back(cur, next_dir);
            cur = nodes[cur].adj[next_dir][0];

            // subtract on the inbound edge of cur which is now the neighbor
            to_subtract.emplace_back(cur, im[next_dir]);

            dir = next_dir;
        }

        update_edges(make_pair(cur, cycle_start_dir), to_subtract);
    }

    std::cout << nodes[cur].x << ' ' << nodes[cur].y << '\n';

    return 0;
}

