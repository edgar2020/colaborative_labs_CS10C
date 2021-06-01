#include <string>

using namespace std;

class Node {  
    public:
        string data;
        int count;
        Node* left;
        Node* right;
        // FIXME
        int key;
        Node(string data):data(data),count(1),left(nullptr),right(nullptr),key(key){}
};//end in 
