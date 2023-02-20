#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insertElement(Node *&list, int n)
{
    Node *new_node = new Node();
    new_node->data = n;

    Node *temp1 = list;
    Node *temp2;

    while ((temp1 != NULL) && (temp1->data < n))
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    if (list == temp1)
    {
        list = new_node;
    }
    else
    {
        temp2->next = new_node;
    }

    new_node->next = temp1;
}

void searchElement(Node *list, int n)
{
    bool flag = false;

    Node *current = new Node();
    current = list;

    while ((current != NULL) && (current->data <= n))
    {
        if (current->data == n)
        {
            flag = true;
        }
        current = current->next;
    }

    if (flag)
    {
        cout << "Element " << n << " finded\n";
    }
    else
    {
        cout << "Not finded\n";
    }
}

void deleteElement(Node *list, int n)
{
    Node *temp;
    Node *previous = NULL;

    temp = list;

    // Search in the list
    while ((temp != NULL) && (temp->data != n))
    {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Not finded, not deleted\n";
    }
    // The first element is going to be deleted
    else if (previous == NULL)
    {
        list = list->next;
        delete temp;
    }
    // The element is not the first element
    else
    {
        previous->next = temp->next;
        delete temp;
    }
}

void printList(Node *list)
{
    Node *temp1 = new Node();
    temp1 = list;

    while (temp1 != NULL)
    {
        cout << "[" << temp1->data << "] ";
        temp1 = temp1->next;
    }
    cout << endl;
}

void makeloop(Node *list, int k){
    
    Node *temp = new Node();
    int count = 1;
    temp = list;
    
    while (count < k)
    {
        temp = temp->next;
		count++;
    }

    Node *join = temp;

    while (temp->next != NULL)
		temp = temp->next;
    
    temp->next = join;
}

int main()
{
    Node *list = NULL;
    insertElement(list, -4);
    insertElement(list, 0);
    insertElement(list, 2);
    insertElement(list, 3);
    printList(list);

    int k = 3;
    makeloop(list, k);

    printList(list);

    return 0;
}