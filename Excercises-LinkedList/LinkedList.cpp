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

int main()
{
    Node *list = NULL;
    int n, option = 9, temp;

    while (option != 0)
    {
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Print" << endl;
        cout << "5. Delete ALL" << endl;
        cout << "0. Exit" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "\nN: ";
            cin >> n;
            cout << endl;
            insertElement(list, n);
            break;

        case 2:
            cout << "\nElement to search: ";
            cin >> temp;
            cout << endl;
            searchElement(list, temp);
            break;

        case 3:
            cout << "\nElement to delete: ";
            cin >> temp;
            cout << endl;
            deleteElement(list, temp);
            break;

        case 4:
            cout << endl;
            printList(list);
            cout << endl;
            break;

        case 5:
            cout << endl;
            while (list != NULL)
            {
                deleteAll(list);
            }
            cout << "Elements deleted" << endl;
            cout << endl;
            break;

        default:
            break;
        }
    }

    return 0;
}