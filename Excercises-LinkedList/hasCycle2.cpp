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

void makeloop(Node *list, int k)
{

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

bool hasCycle(Node *head)
{

    Node *slow = head, *fast = head;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}

Node *detectCycle(Node *head)
{

    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main()
{
    Node *list = NULL;
    int n, option = 9, temp;

    insertElement(list, 3);
    insertElement(list, 2);
    insertElement(list, 0);
    insertElement(list, -4);
    printList(list);

    makeloop(list, 2);

    cout << detectCycle(list)->data << endl;

    return 0;
}