#ifndef __AVLTree_H__
#define __AVLTree_H__

#include "Node.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

class AVLTree {
    private:
        Node *root;
        void preOrder(Node*) const;
        void postOrder(Node*) const;
        void inOrder(Node*) const;
        
        int height(Node*) const;
        void visualizeTree(ofstream &, Node*);
        Node* findUnbalancedNode(const string&);
        void rotate(Node*);
        void rotateLeft(Node*);
        void rotateRight(Node*);
        void printBalanceFactors(Node *);
        
    public:
        AVLTree();
        ~AVLTree();
        void destructorHelper(Node*);
        void insert(const string &newString);
        int height(const string&) const;
        int balanceFactor(Node*);
        void printBalanceFactors();
        void preOrder() const;
        void postOrder() const;
        void inOrder() const;

        void visualizeTree(const string &);
        
};

#endif // __AVLTree_H__