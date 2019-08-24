#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = NULL;
        ListNode *index = result;

        ListNode *l1_iter = l1;
        ListNode *l2_iter = l2;

        int over = 0;
        while (l1_iter != NULL || l2_iter != NULL) {
            int value;
            if (l1_iter != NULL && l2_iter != NULL) {
                value = l1_iter->val + l2_iter->val + over;

                l1_iter = l1_iter->next;
                l2_iter = l2_iter->next;
            } else if (l1_iter != NULL) {
                value = l1_iter->val + over;
                l1_iter = l1_iter->next;
                if (value/10 == 0){
                    ListNode *node = new ListNode(value % 10);
                    index->next = node;
                    index = index->next;
                    index->next = l1_iter;
                    return  result;
                }
            } else {
                value = l2_iter->val + over;
                l2_iter = l2_iter->next;
                if (value/10 == 0){
                    ListNode *node = new ListNode(value % 10);
                    index->next = node;
                    index = index->next;
                    index->next = l2_iter;
                    return  result;
                }
            };

            over = value / 10;

            if (result == NULL){
                result = new ListNode(value % 10);
                index = result;
            } else {
                ListNode *node = new ListNode(value % 10);

                index->next = node;
                index = index->next;
            }

        }

        if (over != 0){
            ListNode *node = new ListNode(over);

            index->next = node;
        }
        return  result;
    }
};



int main() {
    ListNode *node1 = new ListNode (2);

    ListNode *node2 = new ListNode (4);
    node1->next = node2;

    ListNode *node3 = new ListNode (3);
    node2->next = node3;

    ListNode *node4 = new ListNode (9);
    node3->next = node4;

    ListNode *node1_1 = new ListNode (5);

    ListNode *node1_2 = new ListNode (6);
    node1_1->next = node1_2;

    ListNode *node1_3 = new ListNode (4);
    node1_2->next = node1_3;
    Solution solution;

    ListNode *result = solution.addTwoNumbers(node1, node1_1);

    while (result != NULL){
        cout << " -> " << result->val;
        result = result->next;
    }
    return 0;
}