//
// Created by Brandocean on 12/6/2022.
//
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

void insertElement(Node* &list, int n){
    Node* new_node = new Node();
    new_node->data = n;

    Node* temp1 = list;
    Node* temp2;

    while((temp1 != NULL) && (temp1->data < n)){
        temp2 = temp1;
        temp1 = temp1->next;
    }

    if(list == temp1){
        list = new_node;
    } else{
        temp2->next = new_node;
    }

    new_node->next = temp1;
}

void printList(Node* list){
    while(list != NULL){
        cout << "[" << list->data << "] ";
    }
    cout << endl;
}

int main(){
    Node* list = NULL;
    int n;

    while (n != 0){
        cout << "N: ";
        cin >> n;
        insertElement(list,n);
    }

    printList(list);

    return 0;
}