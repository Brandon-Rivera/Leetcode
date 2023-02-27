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

Node *removeNthFromEnd(Node *head, int n)
{
    Node *temp = new Node();
    temp->next = head;

    Node *fast = temp;
    Node *slow = temp;

    for (int i = 1; i <= n; i++)
    {
        fast = fast->next;
    }

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    Node *gaya = slow->next;
    slow->next = slow->next->next;
    delete (gaya);

    return temp->next;
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

int main()
{
    Node *list = NULL;
    int n, option = 9, temp;

    insertElement(list, 1);
    insertElement(list, 2);
    insertElement(list, 3);
    insertElement(list, 4);
    insertElement(list, 5);

    printList(removeNthFromEnd(list,2));

    // Corregir codigo para que se vea mas chevere

    return 0;
}