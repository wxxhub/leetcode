#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void pushNode(ListNode *&node, int i) {
    ListNode *new_node = new ListNode(i);
    new_node->next = node;
    node = new_node;
}

void printNode(ListNode *l) {

    while (l != NULL) {
        cout << l->val << " ";
        l = l->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *end_node = head;
        ListNode *new_head= head;

        if (reverse(k,new_head, end_node) == k) {
            end_node->next = reverseKGroup(end_node->next, k);
        } else { // 如果交换的长度比k小, 则交换回来, 在k比较小, 总长度远大与k时效果好.
            end_node = new_head;
            reverse(k,new_head, end_node);
        }

        return new_head;
    }

    int reverse(int k,ListNode *&new_head, ListNode *&end_node) {
        ListNode *index_node = new_head->next;
        int i = 1;
        for (; index_node != NULL && i < k; index_node = end_node->next, ++i) {
            end_node->next = index_node->next;
            index_node->next = new_head;
            new_head = index_node;
        }

        return i;
    }
};

int main() {
    ListNode *list1 = new ListNode(8);
    pushNode(list1, 7);
    pushNode(list1, 6);
    pushNode(list1, 5);
    pushNode(list1, 4);
    pushNode(list1, 3);
    pushNode(list1, 2);
    pushNode(list1, 1);
    printNode(list1);
    Solution solution;
    ListNode *list2 = solution.reverseKGroup(list1, 3);
    cout << "after swap:";
    printNode(list2);

    return 0;
}