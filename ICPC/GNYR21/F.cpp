
//JUST WRONG XD
// #include<bits/stdc++.h>
// // g++-12 -o main [file].cpp;
// //./main < input.txt > output.txt
// using namespace std;

// #pragma region
// #define ll long long

// #pragma endregion
// struct Face{ 
//     double cords[2];
//     double x,y; 
//     bool spider; 
//     bool fly; 
//     Face(){ 
//         fly = false; 
//         spider = false;
//     }
//     Face(double wi, double hi){ 
//         cords[0] = wi; 
//         cords[1] = hi;
//         spider = false; 
//         fly = false;
//     }
//     Face(const Face& rhs){ 
//         cords[0] = rhs.cords[0];
//         cords[1] = rhs.cords[1];
//         x = rhs.x; 
//         y = rhs.y; 
//         spider = rhs.spider; 
//         fly = rhs.fly;
//     }
//     void set_entity(int x1, int y1, char c){ 
//         if(c == 's'){
//             spider = true; 
//         }else{ 
//             fly = true;
//         }
//         x = x1; 
//         y = y1;
//     }
//     pair<double,double> relative_position(int corner){
//         // cout << x << "  " << y << " " << cords[0] << " " << cords[1] << endl;
//         if(!fly && !spider){ 
//             cout << "SOMETHING WENT WRONG" << endl;
//         }
//         if(corner == 0){ 
//             return make_pair(x,y);
//         } 
//         else if(corner == 1){ 
//             return make_pair(cords[0]-x, y);
//         }
//         else if(corner == 2){ 
//             return make_pair(x, cords[1]-y); 
//         }
//         else{
//             return make_pair(cords[0]-x, cords[1]-y);
//         }
//     }
// };

// Face box[6];
// double w,h,l;
// int nets[3][4] = {{0,1,2,3}, // l h l h 
//                   {0,4,2,5}, // w h w h 
//                   {3,4,1,5}};// w l w l
// tuple<int,int,int> nets_info[3][4] = {
//                   { {0,1,0},{1,1,0},{2,1,2},{3,1,2} },
//                   { {0,0,0},{4,0,0},{2,0,2},{5,0,2} }, 
//                   { {3,0,0},{4,1,0},{1,0,2},{5,1,2} }
//                   };
//                   //face cords orientation
// int set_entity(char c, double x, double y, double  z){
//     if(x  == 0){ 
//         box[5].set_entity(y,z, c);
//         return 5;
//     }else if(x == w){ 
//         box[4].set_entity(y,z, c);
//         return 4;
//     }else if(y == 0){ 
//         box[0].set_entity(x,z, c);
//         return 0;
//     }else if(y == h){ 
//         box[2].set_entity(x,z,c);
//         return 2;
//     }else if(z == 0){
//         box[3].set_entity(x,y,c);
//         return 3;
//     }else{ 
//         box[1].set_entity(x,y,c);
//         return 1;
//     }
// }
// double get_distance(double sx, double sy, double fx, double fy){ 
//     cout << sx<< " "<< sy << " " << fx << " " << fy << " " << sqrt(pow(sx-fx,2) + pow(sy-fy,2)) << endl; 
//     return sqrt(pow(sx-fx,2) + pow(sy-fy,2));

// }
// double solve_net(int spider, int fly, int net){ 
//     int start = -1;
//     for(int i =0; i < 4; i++){ 
//         if(get<0>(nets_info[net][i]) == spider) start = i;
//     }
//     if(start == -1){ 
//         return 1e9;
//     }
//     double res = 1e9;
//     double forward = 1e9; 
//     double backwards = 1e9;
//     auto [face, cord, orien] = nets_info[net][start];
//     auto [sx, sy] = box[face].relative_position(orien); 
//     // cout << sx << " " << sy << endl;
//     double rel_y = box[face].cords[cord];
//     for(int i =1; i < 4; i++){ 
//         auto [face, cord, orien] = nets_info[net][(start+i)%4];
//         if(face == fly){ 
//             // cout << face << endl;
//             auto [fx,fy] = box[face].relative_position(orien);
//             fy += rel_y;
//             res = min(res, get_distance(sx,sy, fx, fy));
//             // cout << sx << " " << sy<< " " << fx <<" "<< fy <<  " " <<rel_y << endl; 
//             break;
//         }else{ 
//             rel_y += box[face].cords[cord];
//         }
//     }
//     rel_y = 0;
//     for(int i =1; i < 4; i++){ 
//         auto [face, cord, orien] = nets_info[net][(start-i+4)%4];
//         if(face == fly){
//             // cout << face << endl; 
//             auto [fx,fy] = box[face].relative_position(orien);
//             fy = box[face].cords[1]-fy;
//             fy *= -1;
//             fy += rel_y;
//             // cout << sx << " " << sy<< " " << fx <<" "<< fy  << " " << rel_y<< endl; 
//             res = min(res, get_distance(sx,sy, fx, fy));

//             break;
//         }else{ 
//             rel_y -= box[face].cords[cord];
//         }
//     }
//     // cout << res << endl;
//     return res;
// }
// void create_box(){ 
//     box[0] = Face(w,l);
//     box[1] = Face(w,h);
//     box[2] = Face(w,l);  
//     box[3] = Face(w,h);
//     box[4] = Face(h,l);
//     box[5] = Face(h,l);
// }
// void solve(){
//     double sx, sy, sz; 
//     double fx, fy, fz;
//     cin >> w >> h >> l; 
//     cin >> sx >> sy >> sz; 
//     cin >> fx >> fy >> fz; 
//     create_box();
//     int spider = set_entity('s', sx, sy, sz); 
//     // cout << w << " " << h << " " << l << endl;; 
//     // cout << sx << " " <<  sy << " " <<sz << endl;
//     // cout << fx << " " <<  fy << " " <<fz << endl;
//     int fly = set_entity('f', fx, fy, fz);

//     // cout << fly << " " << spider << endl;
//     double res = 1e9; 
//     res = fmin(res, solve_net(spider,fly,0)); 
//     res = fmin(res, solve_net(spider,fly,1)); 
//     res = fmin(res, solve_net(spider,fly,2));
//     cout << setprecision(3) << res << endl;
// }

// int main(){
//     ios::sync_with_stdio(false); 
//     cin.tie(nullptr);
//     solve(); 
// }
