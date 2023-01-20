#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
};

Node *tree = NULL;

Node* createNode(int n){
    Node* new_node = new Node();

    new_node->data = n;
    new_node->right = NULL;
    new_node->left = NULL;

    return new_node;
}

void insertNode(Node* &tree, int n){
    if(tree == NULL){ //empty tree
        Node* new_node = createNode(n);
        tree = new_node;
    } 
    else{ //tree with something
        int rootValue = tree->data;
        if(n < rootValue){ //If it is smaller than rootValue
            insertNode(tree->left,n);
        }
        else{ // If it is greater than rootValue
            insertNode(tree->right,n);
        }
    }
}


int main()
{

    return 0;
}