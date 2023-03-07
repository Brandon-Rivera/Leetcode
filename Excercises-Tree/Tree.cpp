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

void showTree(Node *tree, int cnt){
    
    if(tree == NULL){
        return;
    }
    else{
        showTree(tree->der,cnt+1);
        for(int i = 0; i < cnt; i++){
            cout << "   ";
        }
        cout << tree->data << endl;
        showTree(tree->izq,cnt+1);
    }
}

int main()
{
    Node *tree = NULL;

    insertNode(tree, 5);
    insertNode(tree, 10);
    insertNode(tree, 2);
    insertNode(tree, 4);

    showTree(tree,0);

    cout << "\nFinished" << endl;

    return 0;
}