#include "BSTree.h"

using namespace std;
// Fixme
// int key = 0;
BSTree::BSTree()
{
    root = nullptr;
}//end of default constructor

// 


void BSTree::destructorHelper(Node* node)
{
    if (node)
    {
        destructorHelper(node->left);
        destructorHelper(node->right);
        delete node;
    }
}

BSTree::~BSTree()
{
    destructorHelper(root);
}

// BSTree::~BSTree()
// {
//     while(root)
//     {
//         root->count = 1;
//         Node* temp = root;
//         remove(root->data);
//         delete temp;
//     }//end of while
// }//end of deconstructor

/* Mutators */
void BSTree::insert(const string &newString)
{
   Node* node = new Node(newString);
//    node->key = key;
//    key++;
//    if(key.at(1) == 'Z')
//    {
//        key.at(1) = 'A';
//        key.at(0)++;
//    }
   if (root)
   {
      Node* temp = root;
      Node* prev = temp;
      // while (temp->data != newString)
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


      //temp = node;
   }//end of if is tree is populated
   else
   {
      root = node;
   }//end of if that checks if tree is empty
}//end of insert
       
void BSTree::remove(const string &key)
{
    Node* par = nullptr;
    Node* cur = root;
    while (cur) 
    { // Search for node
        if (cur->data == key) 
        { // Node found 
            if(cur->count > 1)
            {
                cur->count--;
                return;
            }
            else if (!cur->left && !cur->right) 
            { // Remove leaf
                if (!par) // Node is root
                    root = nullptr;
                else if (par->left == cur) 
                    par->left = nullptr;
                else
                    par->right = nullptr;
            }
            else if (cur->left)// Remove node with two children
            {
            // Find pre-successor (rightmost child of left subtree)
                Node* preSuc = cur->left;
                while (preSuc->right)
                    preSuc = preSuc->right;             
                string preSuccessorData =preSuc->data;
                int preSuccessorCount = preSuc->count;
                preSuc->count = 1;
                remove(preSuc->data);     // Remove pre-successor
                cur->data = preSuccessorData;
                cur->count = preSuccessorCount;
            }
            else{   // Replace with successor
                Node* suc = cur->right;
                while (suc->left)
                    suc = suc->left;             
                string successorData =suc->data;
                int successorCount = suc->count;
                suc->count = 1;
                remove(suc->data);     // Remove successor
                cur->data = successorData;
                cur->count = successorCount;
            }
            return; // Node found and removed
        }
        else if (cur->data < key) 
        { // Search right
            par = cur;
            cur = cur->right;
        }
        else 
        {                     // Search left
            par = cur;
            cur = cur->left;
        }
   }
   return; // Node not found
}//end of remove

        
bool BSTree::search(const string &key) const
{
    return search(key, root);
}//end of search

bool BSTree::search(const string &key, Node* subRoot) const
{
    if(subRoot)
    {
      if(subRoot->data == key)
         return true;
      else if (search(key, subRoot->left) || search(key, subRoot->right))
         return true;
      else
         return false;
    }//base case
    return false;
}

string BSTree::largest() const
{
   Node* temp = root;
   Node* prev = temp;
   while (temp) 
   {
      prev = temp;
      temp = temp->right;
   }
   if (prev) return prev->data;
   else return "";
}//end of largest

string BSTree::smallest() const
{
   Node* temp = root;
   Node* prev = temp;
   while (temp) 
   {
      prev = temp;
      temp = temp->left;
   }
   if (prev) return prev->data;
   else return "";
}//end of smallest

int BSTree::height(const string& entry) const
{
//    if(!search(entry))
//    {
//        return -1;
//    }

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

    return height(entry, temp);
}

int BSTree::height(const string& entry, Node* subRoot) const
{
   if (!subRoot)
      return -1;
   else {
      int leftHeight = height(entry, subRoot->left);
      int rightHeight = height(entry, subRoot->right);
      if (leftHeight > rightHeight)
         return 1 + leftHeight;
      else
         return 1 + rightHeight;
   }
}//end of height

void BSTree::preOrder() const
{
    preOrder(root);
}//end of preorder

void BSTree::preOrder(Node* subRoot) const
{
    if(subRoot)
    {
        cout<<subRoot->data<<"(" << subRoot->count<<"), ";
        preOrder(subRoot->left);
        preOrder(subRoot->right);
    }
}//end of preorder

void BSTree::postOrder() const
{
    postOrder(root);
}//end of postorder

void BSTree::postOrder(Node* subRoot) const
{
    if(subRoot)
    {
        postOrder(subRoot->left);
        postOrder(subRoot->right);
        cout<<subRoot->data<<"(" << subRoot->count<<"), ";
    }
}//end of preorder

void BSTree::inOrder() const
{
    inOrder(root);
}//end of inOrder

void BSTree::inOrder(Node* subRoot) const
{
    if(subRoot)
    {
        inOrder(subRoot->left);
        cout<<subRoot->data<<"(" << subRoot->count<<"), ";
        inOrder(subRoot->right);
    }
}//end of preorder


void BSTree::visualizeTree(const string &outputFilename)
{
        ofstream outFS(outputFilename.c_str());
        if(!outFS.is_open()){
            cout<<"Error opening "<< outputFilename<<endl;
            return;
        }
        outFS<<"digraph G {"<<endl;
        visualizeTree(outFS,root);
        outFS<<"}";
        outFS.close();
        string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".png";
        // string command = "dot -Tjpg " + outputFilename + " " + jpgFilename;
        string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
        system(command.c_str());
}

void BSTree::visualizeTree(ofstream & out, Node *subRoot) {
    if(subRoot)
    {
        
        out <<subRoot->data<<"[color = orange, fontsize=27 peripheries=2, style = filled, label=\""<<subRoot->data<<"("<<subRoot->count<<")"<<"\"];"<<endl;
        
        if (subRoot->left) 
        {
            out << subRoot->data<<" -> " << subRoot->left->data <<endl;
            visualizeTree(out, subRoot->left);
        }
        if (subRoot->right) 
        {
            out << subRoot->data<<" -> " << subRoot->right->data <<endl;
            visualizeTree(out, subRoot->right);
        }  
    }
    
}