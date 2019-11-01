#include <iostream>

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
    ListNode *index = l;

    while (index != NULL) {
        cout << index->val << " ";
        index = index->next;
    }
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }

        if (l2 == NULL) {
            return l1;
        }
        ListNode *index1 = l1;
        ListNode *index2 = l2;
        ListNode *result;

        if (index1->val > index2->val) {
            result = index2;
            index2 = index2->next;
        } else {
            result = index1;
            index1 = index1->next;
        }

        ListNode *result_index = result;

        while (index1 != NULL && index2 != NULL) {
            if (index1->val > index2->val) {
                result_index->next = index2;
                index2 = index2->next;
            } else {
                result_index->next = index1;
                index1 = index1->next;
            }
            result_index = result_index->next;
        }

        if (index1 != NULL) {
            result_index->next = index1;
        } else {
            result_index->next = index2;
        }

        return result;
    }
};

int main() {
    Solution solution;
    ListNode *list1 = new ListNode(4);
    ListNode *list2 = new ListNode(4);

    pushNode(list1, 2);
    pushNode(list1, 1);

    pushNode(list2, 3);
    pushNode(list2, 1);

    printNode(solution.mergeTwoLists(list1, list2));
    return 0;
}