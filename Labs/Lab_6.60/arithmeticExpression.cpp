#include "arithmeticExpression.h"
#include <stack>
#include <string>
#include <sstream>
#include <fstream>

/* Initializes an empty tree and sets the infixExpression
    to the value of parameter passed in. */
arithmeticExpression::arithmeticExpression(const string &input) {
    root = nullptr;
    infixExpression = input;
}

/* Converts the infixExpression to its equivalent postfix string
    and then generates the tree and assigns the root node to the 
    root data field. The key for the first node is 'a', 'b' for the second node and so on. */
void arithmeticExpression::buildTree() {
    string postfix =  infix_to_postfix();

    stack<TreeNode*> s;
    char data;
    char key = 'a';
    TreeNode *left_child, *right_child; // I removed the root pointer declaration from here because it was already declared as private class variable. 
    for(unsigned i = 0; i< postfix.size();++i){
        data = postfix.at(i);
        if (!isOpp(data)) {
            root = new TreeNode(data, key);
            root->data = data;
            root->key = key;
            s.push(root);
        } else { //c is an operator
            root = new TreeNode(data, key); // Theoretically the last pointer that root is assigned should be the true root of this tree, so no reassigning is needed after this loop.
            
            root->data = data;
            root->key = key;
            
            right_child = s.top();
            s.pop();
            left_child = s.top();
            s.pop();
            
            root->right = right_child;
            root->left = left_child;

            s.push(root);
        }
        key++;
    }
}

/* Calls the recursive infix function. */
void arithmeticExpression::infix() {
    infix(root);
}

/* Calls the recursive prefix function. */
void arithmeticExpression::prefix() {
    prefix(root);
}

/* Calls the recursive postfix function. */
void arithmeticExpression::postfix() {
    postfix(root);
}

/* Calls the recursive visualizeTree function and generates the .png file using system call. */
void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}




/* Helper function that returns an integer according to
       the priority of the given operator. */
int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

/* Helper function that returns the postfix notation equivalent
       to the given infix expression */
string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

/* Helper function that outputs the infix notation of the arithmetic expression tree
    by performing the inorder traversal of the tree.
    An opening and closing parenthesis must be added at the 
    beginning and ending of each expression. */
void arithmeticExpression::infix(TreeNode *subRoot) {
// I stole this pseudocode from the slides with some modifications:
if (subRoot) {
    if (subRoot->left)
        cout << '(';
    infix(subRoot->left);
    cout << subRoot->data;
    infix(subRoot->right);
    if (subRoot->right)
        cout << ')';
  }
}

/* Helper function that outputs the prefix notation of the arithmetic expression tree
    by performing the preorder traversal of the tree. */
void arithmeticExpression::prefix(TreeNode *subRoot) {
    if (subRoot) {
        cout << subRoot->data;
        prefix(subRoot->left);
        prefix(subRoot->right);
    }
}

/* Helper function that outputs the postfix notation of the arithmetic expression tree
    by performing the postorder traversal of the tree. */
void arithmeticExpression::postfix(TreeNode *subRoot) {
    if (subRoot) {
        postfix(subRoot->left);
        postfix(subRoot->right);
        cout << subRoot->data;
    }
}

/* Helper function for generating the dotty file. This is a recursive function. */
void arithmeticExpression::visualizeTree(ofstream & out, TreeNode *subRoot) {
    if(subRoot)
    {
        if(isOpp(subRoot->data))
        {
            out <<subRoot->key<<"[color = lightgreen, style = filled, label=\""<<subRoot->data<<"\"];"<<endl;
        }
        else
        {
            out <<subRoot->key<<"[color = orange, peripheries=2, style = filled, label=\""<<subRoot->data<<"\"];"<<endl;
        }
        if (subRoot->left) {
  
            out << subRoot->key<<" -> " << subRoot->left->key <<endl;

            out << subRoot->key<<" -> " << subRoot->right->key <<endl;
        }
        visualizeTree(out, subRoot->left);
        visualizeTree(out, subRoot->right);
    }
}