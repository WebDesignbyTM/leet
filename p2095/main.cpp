#include <iostream>
#include <vector>
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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        ListNode* current = head;
        ListNode* middle = head;
        ListNode* target = nullptr;
        int cnt = 0;

        while (current != nullptr) {
            ++cnt;
            if ((cnt & 1) == 0) {
                target = middle;
                middle = middle->next;
            }
            current = current->next;
        }
        target->next = middle->next;

        return head;
    }
};

void printList(ListNode* head) {
    if (head == nullptr)
        return;
    cout << head->val << ' ';
    printList(head->next);
}

int main() {
    ListNode a(6);
    ListNode b(2, &a);
    ListNode c(1, &b);
    ListNode d(7, &c);
    ListNode e(4, &d);
    ListNode f(3, &e);
    ListNode g(1, &f);

    printList(&g);
    cout << '\n';
    Solution sol;
    sol.deleteMiddle(&g);
    printList(&g);
    return 0;
}