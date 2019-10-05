#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void createList(ListNode *&head, ListNode *&current_node, int val) {
    current_node = new ListNode(val);
    head = current_node;
}

void add(ListNode *&current_node, int val) {
    ListNode *new_node = new ListNode(val);
    current_node->next = new_node;
    current_node = new_node;
}

void printList(ListNode *head) {
    ListNode *index_node = head;

    while (index_node != NULL) {
        cout << index_node->val;

        if (index_node->next != NULL) {
            cout << "->";
        }
        index_node = index_node->next;
    }

    cout << endl;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *end_node = head;
        ListNode *current_node = head;
        ListNode *pre_node = head;

        int len = 0;
        while (end_node != NULL) {
            if (len < n) {
                end_node = end_node->next;
                ++len;
            } else {
                end_node = end_node->next;
                pre_node = current_node;
                current_node = current_node->next;
            }
        }

        if (current_node == head) {
            head = current_node->next;
        } else {
            pre_node->next = current_node->next;
        }

        delete(current_node);

        return head;
    }
};

int main() {
    ListNode *head, *current_node;
    Solution solution;

    createList(head, current_node, 1);

    add(current_node, 2);
    add(current_node, 3);
    add(current_node, 4);
    add(current_node, 5);

    printList(head);

    head = solution.removeNthFromEnd(head, 2);

    printList(head);
    return 0;
}