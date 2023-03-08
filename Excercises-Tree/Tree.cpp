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

bool SearchNode(Node *tree, int n){

    if(tree == NULL){
        return false;
    }
    else if(n == tree->data){
        return true;
    }
    else if(n < tree->data){
        return SearchNode(tree->left,n);
    }
    else{
        return SearchNode(tree->right,n);
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

    cout << endl << "Do we find it? : " << SearchNode(tree,7) << endl;

    cout << "\nFinished\n" << endl;

    return 0;
}