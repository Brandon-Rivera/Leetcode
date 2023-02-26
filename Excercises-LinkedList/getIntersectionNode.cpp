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

    while ((temp1 != NULL))
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

void deleteAll(Node *&list)
{

    Node *temp = list;
    list = temp->next;
    delete temp;
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

Node *getIntersectionNode(Node *headA, Node *headB)
{
    Node *temp = headA, *temp2 = headB;

    while (temp != NULL)
    {

        temp2 = headB;

        while (temp2 != NULL)
        {
            if (temp == temp2)
            {
                return temp;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }

    return NULL;
}

int main()
{
    Node *list = NULL, *list2 = NULL, *list3 = NULL;

    //Case 1: With intersection

    insertElement(list, 4);
    insertElement(list, 1);

    insertElement(list2, 5);
    insertElement(list2, 6);
    insertElement(list2, 1);

    insertElement(list3, 8);
    insertElement(list3, 4);
    insertElement(list3, 5);

    list->next->next = list3;
    list2->next->next->next = list3;

    //Case 2: Without intersection

    // insertElement(list,2);
    // insertElement(list,6);
    // insertElement(list,4);

    // insertElement(list2,1);
    // insertElement(list2,5);

    printList(list);
    printList(list2);

    cout << endl;

    cout << getIntersectionNode(list, list2)->data << endl;


    return 0;
}
