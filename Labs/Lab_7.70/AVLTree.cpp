#include "AVLTree.h"

using namespace std;
// Fixme
// int key = 0;
AVLTree::AVLTree()
{
    root = nullptr;
}//end of default constructor

// 

void AVLTree::destructorHelper(Node* node)
{
    if (node)
    {
        destructorHelper(node->left);
        destructorHelper(node->right);
        delete node;
    }
}

AVLTree::~AVLTree()
{
    destructorHelper(root);
}

/* Mutators */
void AVLTree::insert(const string &newString)
{
   Node* node = new Node(newString);
   if (root)
   {
      Node* temp = root;
      Node* prev = temp;
      while (temp)
      {
         prev = temp;
         if (temp->data == newString)
         {
            temp->count++;
            return;
         }//end of if that checks if duplicate value
         else if (temp->data > newString)
         {
            temp = temp->left;
         }
         else
         {
            temp = temp->right;
         }
      }//end of while loop
      
      if (prev->data > newString)
         prev->left = node;
      else
         prev->right = node;   
        rotate(findUnbalancedNode(newString));
   }//end of if is tree is populated
   else
   {
      root = node;
   }//end of if that checks if tree is empty
}//end of insert

Node* AVLTree::findUnbalancedNode(const string& insertedNode)
{
    Node* currNode = root;
    Node* unbalanced = nullptr;
    while (currNode->data != insertedNode)
    {
        if (balanceFactor(currNode) == 2 || balanceFactor(currNode) == -2)
        {
            unbalanced = currNode;
        }//end of if that checks if duplicate value
        if (currNode->data > insertedNode)
        {
            currNode = currNode->left;
        }
        else
        {
            currNode = currNode->right;
        }
    }//end of while loop
    return unbalanced;
}


int AVLTree::balanceFactor(Node* node) {
    return height(node->left) - height(node->right);
}

void AVLTree::printBalanceFactors() {
    printBalanceFactors(root);
}

void AVLTree::rotate(Node* node)
{
    /* * * * * * * * * * * * * * * * * * * * * * * * 
     *  Right       Left    Right   Left           *
     *              Right   Left                   *
     *      O        O       O       O             *
     *     /        /         \       \            *
     *    O        O           O       O           *
     *   /          \         /         \          *
     *  O            O       O           O         *
     * * * * * * * * * * * * * * * * * * * * * * * */
     if(!node) return; 
     if(balanceFactor(node) > 1) //cases 1 and 2
     {
         if(node->left->left && !node->left->right) // case 1
         {  
             rotateRight(node);
         }
         else//case 2
         {
             rotateLeft(node->left);
             rotateRight(node);
         }
     }
     else//cases 3 and 4
     {
         if(node->right->right && !node->right->left)//case 4
         {
             rotateLeft(node);
         }
         else//case 3
         {
             rotateRight(node->right);
             rotateLeft(node);
         }
     }
}



void AVLTree::rotateLeft(Node* node)
{
    Node* child = node->right->left;
    Node* temp = node->left;
    node->left = new Node(node->data);

    node->left->count = node->count;
    node->left->right = child;
    node->left->left = temp;

    node->data = node->right->data;
    node->count =  node->right->count;
    delete node->right;
    node->right = node->right->right;
}

void AVLTree::rotateRight(Node* node)
{
    Node* child = node->left->right;
    Node* temp = node->right;
    node->right = new Node(node->data);

    node->right->count = node->count;
    node->right->left = child;
    node->right->right = temp;
    
    node->data = node->left->data;
    node->count =  node->left->count;  
    delete node->left;
    node->left = node->left->left;
}


void AVLTree::printBalanceFactors(Node *subRoot) {
    // if(balanceFactor(subRoot) == 2 || balanceFactor(subRoot) == -2)
    // { rotate(subRoot); }

    if (subRoot) {
        printBalanceFactors(subRoot->left);
        cout << subRoot->data << "(" << balanceFactor(subRoot) << "), ";
        printBalanceFactors(subRoot->right);
    }
}

int AVLTree::height(const string& entry) const
{
   Node* temp = root;
   while(temp && (entry != temp->data))
   {
        if(temp->data> entry)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    return height(temp);
}

int AVLTree::height(Node* subRoot) const
{
   if (!subRoot)
      return -1;
   else {
      int leftHeight = height(subRoot->left);
      int rightHeight = height(subRoot->right);
      if (leftHeight > rightHeight)
         return 1 + leftHeight;
      else
         return 1 + rightHeight;
   }
}//end of height

void AVLTree::preOrder() const
{
    preOrder(root);
}//end of preorder

void AVLTree::preOrder(Node* subRoot) const
{
    if(subRoot)
    {
        cout<<subRoot->data<<"(" << subRoot->count<<"), ";
        preOrder(subRoot->left);
        preOrder(subRoot->right);
    }
}//end of preorder

void AVLTree::postOrder() const
{
    postOrder(root);
}//end of postorder

void AVLTree::postOrder(Node* subRoot) const
{
    if(subRoot)
    {
        postOrder(subRoot->left);
        postOrder(subRoot->right);
        cout<<subRoot->data<<"(" << subRoot->count<<"), ";
    }
}//end of preorder

void AVLTree::inOrder() const
{
    inOrder(root);
}//end of inOrder

void AVLTree::inOrder(Node* subRoot) const
{
    if(subRoot)
    {
        inOrder(subRoot->left);
        cout<<subRoot->data<<"(" << subRoot->count<<"), ";
        inOrder(subRoot->right);
    }
}//end of preorder


// void AVLTree::visualizeTree(const string &outputFilename)
// {
//         ofstream outFS(outputFilename.c_str());
//         if(!outFS.is_open()){
//             cout<<"Error opening "<< outputFilename<<endl;
//             return;
//         }
//         outFS<<"digraph G {"<<endl;
//         visualizeTree(outFS,root);
//         outFS<<"}";
//         outFS.close();
//         string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".png";
//         // string command = "dot -Tjpg " + outputFilename + " " + jpgFilename;
//         string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
//         system(command.c_str());
// }

// void AVLTree::visualizeTree(ofstream & out, Node *subRoot) {
//     if(subRoot)
//     {
        
//         out <<subRoot->data<<"[color = orange, fontsize=27 peripheries=2, style = filled, label=\""<<subRoot->data<<"("<<subRoot->count<<")"<<"\"];"<<endl;
        
//         if (subRoot->left) 
//         {
//             visualizeTree(out, subRoot->left);
//             out << subRoot->data<<" -> " << subRoot->left->data <<endl;
//         }
//         if (subRoot->right) 
//         {
//             visualizeTree(out, subRoot->right);
//             out << subRoot->data<<" -> " << subRoot->right->data <<endl;
//         }  
//         if (!subRoot->left) 
//         {
//             out << subRoot->data<<" -> null_left_"<<subRoot->data <<endl;
//         }
//         if (!subRoot->right) 
//         {
//             out << subRoot->data<<" -> null_right_"<<subRoot->data <<endl;
//         } 
//     }
    
// }

void AVLTree::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
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

void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    
    if(n){
        outFS <<n->data<<"[color = lightblue, peripheries=2, style = filled];"<<endl;
        
                if(!n->left)
                {
                    outFS<<n->data <<" -> null_left" <<n->data<<";"<<endl;      
                    outFS<<"null_left"<<n->data<<"[shape = point];"<<endl;
                }
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->data <<" -> " <<n->left->data<<";"<<endl;    
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->data <<" -> " <<n->right->data<<";"<<endl;    
        }
            if(!n->right)
            {
                outFS<<n->data <<" -> null_right" <<n->data<<";"<<endl; 
                outFS<<"null_right"<<n->data<<"[shape = point];"<<endl;
            }
        
    }
}