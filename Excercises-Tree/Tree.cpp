#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *right;
    Node *left;
};

Node *CreateNode(int n){
    Node *new_node = new Node();

    new_node->data = n;
    new_node->right = NULL;
    new_node->left = NULL;

    return new_node;
}

void insertNode(Node *&tree, int n){

    if(tree == NULL){
        Node *new_node = CreateNode(n);
        tree = new_node;
    }
    else{
        if(n < tree->data){
            insertNode(tree->left,n);
        }
        else{
            insertNode(tree->right,n);
        }
    }
}

void showTree(Node *tree, int cnt){
    
    if(tree == NULL){
        return;
    }
    else{
        showTree(tree->right,cnt+1);
        for(int i = 0; i < cnt; i++){
            cout << "   ";
        }
        cout << tree->data << endl;
        showTree(tree->left,cnt+1);
    }
}

bool searchNode(Node *tree, int n){

    if(tree == NULL){
        return false;
    }
    else if(n == tree->data){
        return true;
    }
    else if(n < tree->data){
        return searchNode(tree->left,n);
    }
    else{
        return searchNode(tree->right,n);
    }

}

void preOrder(Node *tree){ //Raiz -> Izquierda -> derecha
    if(tree == NULL){
        return;
    }
    else{
        cout << tree->data << " - ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void inOrder(Node *tree){ //Izquierda -> Raiz -> derecha
    if(tree == NULL){
        return;
    }
    else{
        inOrder(tree->left);
        cout << tree->data << " - ";
        inOrder(tree->right);
    }
}

void postOrder(Node *tree){ //Izquierda -> derecha -> Raiz (muestra primero el nodo más izquierdo posible)
    if(tree == NULL){
        return;
    }
    else{
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->data << " - ";
    }
}



int main()
{
    Node *tree = NULL;

    insertNode(tree, 5);
    insertNode(tree, 10);
    insertNode(tree, 2);
    insertNode(tree, 4);
    insertNode(tree, 6);
    insertNode(tree, 11);

    showTree(tree,0);

    //cout << endl << "Do we find it? : " << searchNode(tree,7) << endl;

    //preOrder(tree);
    //inOrder(tree);
    postOrder(tree);

    cout << "\nFinished\n" << endl;

    return 0;
}