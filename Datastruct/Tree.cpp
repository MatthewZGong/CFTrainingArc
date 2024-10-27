
#include<bits/stdc++.h>
// g++-14 -o main [file].cpp;
//./main < input.txt > output.txt
using namespace std;




//LOL rotation is cancer
template <typename T, typename Comp = std::less<T>> 
class RBTree{ 
    private: 
        struct Node{
            Node(T val): value(val), black(false){ 

            }
            bool black;
            T value;
            Node* parent; 
            Node* left; 
            Node* right;
        }
    
    public:
        RBtree(): root(nullptr){
        }
        
        void insert(T val){ 
            Node* node = new Node(val);
            if(root == nullptr){ 
                node.black = true;
                root = node;
                return; 
            }
            _insert(root, node);

        }


    private:
        Node* _insert(Node* current, Node* new_node){ 
            if(current != nullptr){
                if(Comp(new_node.value, current.value)){ 
                    current.left = _insert(current, current.left, new_node);
                }else{ 
                    current.right = _insert(current, current.right, new_node); 
                }
            }else{ 
                return new_node
            }
            if(!current.black)
            if(current.left != nullptr && !current.left.black){ 
            }else if(!current.left != nullptr && !current.right.black){ 

            }
            return current;

        }
        size_t size; 
        Node* root;

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    return 0;
}
