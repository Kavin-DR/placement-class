#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* point1 = headA;
        ListNode* point2 = headB;

        while (point1 != point2) {

            if (point1 == NULL)
                point1 = headB;
            else
                point1 = point1->next;

            if (point2 == NULL)
                point2 = headA;
            else
                point2 = point2->next;
        }

        return point1;
    }
};

int main() {

    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    Solution obj;

    ListNode* ans = obj.getIntersectionNode(headA, headB);

    if (ans != NULL)
        cout << "Intersection Node = " << ans->val << endl;
    else
        cout << "No Intersection" << endl;

    return 0;
}