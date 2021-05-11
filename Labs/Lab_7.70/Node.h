#include <string>

using namespace std;

class Node {  
    public:
        string data;
        int count;
        Node* left;
        Node* right;
        Node(string data):data(data),count(1),left(nullptr),right(nullptr){}
};//end node 
