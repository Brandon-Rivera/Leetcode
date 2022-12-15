// Linked List

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middleNode(ListNode *head)
{
    ListNode *middle = head;
    ListNode *end = head;

    while (end != NULL && end->next != NULL)
    {
        middle = middle->next;
        end = end->next->next;
    }

    return middle;
}

void insertElement(ListNode *&list, int n)
{
    ListNode *new_node = new ListNode();
    new_node->val = n;

    ListNode* temp1 = list;
    ListNode* temp2;

    while ((temp1 != NULL) && (temp1->val < n))
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

void printList(ListNode *list)
{
    ListNode* temp1 = list;

    while (temp1 != NULL)
    {
        cout << "[" << temp1->val << "] ";
        temp1 = temp1->next;
    }
    cout << endl;
}

int main()
{
    ListNode* head = NULL;
    insertElement(head, 1);
    insertElement(head, 2);
    insertElement(head, 3);
    insertElement(head, 4);
    insertElement(head, 5);
    insertElement(head, 6);
    cout << "Head:" << endl;
    printList(head);

    cout << "Middle:" << endl;
    ListNode* middle = middleNode(head);
    printList(middle);

    return 0;
}
