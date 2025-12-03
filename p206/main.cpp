#include <iostream>
#include <stack>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;

        stack<ListNode*> nodes;
        ListNode* newHead;

        nodes.push(nullptr);
        while (head != nullptr) {
            nodes.push(head);
            head = head->next;
        }

        newHead = nodes.top();

        while (nodes.top() != nullptr) {
            head = nodes.top();
            nodes.pop();
            head->next = nodes.top();
        }

        return newHead;
    }
};

int main() {
    ListNode a(5);
    ListNode b(4, &a);
    ListNode c(3, &b);
    ListNode d(2, &c);
    ListNode e(1, &d);

    Solution sol;
    ListNode* start = sol.reverseList(&e);
    while (start != nullptr) {
        cout << start->val << ' ';
        start = start->next;
    }


    return 0;
}