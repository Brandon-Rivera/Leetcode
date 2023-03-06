#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *der;
    Node *izq;
};

Node *CreateNode(int n){
    Node *new_node = new Node();

    new_node->data = n;
    new_node->der = NULL;
    new_node->izq = NULL;

    return new_node;
}

void insertNode(Node *&tree, int n){

    if(tree == NULL){
        Node *new_node = CreateNode(n);
        tree = new_node;
    }
    else{
        if(n < tree->data){
            insertNode(tree->izq,n);
        }
        else{
            insertNode(tree->der,n);
        }
    }
}

int main()
{
    Node *tree = NULL;

    insertNode(tree, 5);
    insertNode(tree, 10);
    insertNode(tree, 2);
    insertNode(tree, 4);

    return 0;
}