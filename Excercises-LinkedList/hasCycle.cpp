#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head){

    ListNode* tmp = head;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

bool hasCycle(ListNode *head)
{

    ListNode *slow = head, *fast = head;

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

int main()
{
    //cout << hasCycle(head) << endl;

    return 0;
}