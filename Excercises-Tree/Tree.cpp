#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *right;
    Node *left;
    Node *parent;
};

Node *CreateNode(int n, Node *parent){
    Node *new_node = new Node();

    new_node->data = n;
    new_node->right = NULL;
    new_node->left = NULL;
    new_node->parent = parent;

    return new_node;
}

void insertNode(Node *&tree, int n, Node *parent){

    if(tree == NULL){
        Node *new_node = CreateNode(n, parent);
        tree = new_node;
    }
    else{
        if(n < tree->data){
            insertNode(tree->left,n,tree);
        }
        else{
            insertNode(tree->right,n,tree);
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

Node *minimum(Node *tree){ //Returns the leftmost node possible
    if(tree == NULL){
        return NULL;
    }
    else if(tree->left){
        return minimum(tree->left);
    }
    else{
        return tree;
    }
}

void replace(Node *tree, Node *new_node){
    if(tree->parent){ 
        //tree->parent have a new child
        if(tree->data == tree->parent->left->data){
            tree->parent->left = new_node;
        }
        else if(tree->data == tree->parent->right->data){
            tree->parent->right = new_node;
        }
    }
    if(new_node){
        //this child have a new parent
        new_node->parent = tree->parent;
    }
}

void destroyNode(Node *node){
    node->left = NULL;
    node->right = NULL;
    delete node;
}

void deleteNode(Node *deleteN){
    if(deleteN->left && deleteN->right){
        Node *min = minimum(deleteN->right);
        deleteN->data = min->data;
        deleteNode(min);
    }
    else if(deleteN->left){
        replace(deleteN, deleteN->left);
        destroyNode(deleteN);
    }
    else if(deleteN->right){
        replace(deleteN, deleteN->right);
        destroyNode(deleteN);
    }
    else{
        replace(deleteN, NULL);
        destroyNode(deleteN);
    }
}

void deleteTree(Node *tree, int n){
    if(tree == NULL){
        return;
    }
    else if(n < tree->data){
        deleteTree(tree->left,n);
    }
    else if(n > tree->data){
        deleteTree(tree->right,n);
    }
    else{
        deleteNode(tree);
    }
}


int main()
{
    Node *tree = NULL;

    insertNode(tree, 5, NULL);
    insertNode(tree, 10, NULL);
    insertNode(tree, 2, NULL);
    insertNode(tree, 4, NULL);
    insertNode(tree, 6, NULL);
    insertNode(tree, 11, NULL);

    showTree(tree,0);

    //cout << endl << "Do we find it? : " << searchNode(tree,7) << endl;

    //preOrder(tree);
    //inOrder(tree);
    //postOrder(tree);
    deleteTree(tree,5);
    showTree(tree,0);

    cout << "\nFinished\n" << endl;

    return 0;
}