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
    ListNode *index = l;

    while (index != NULL) {
        cout << index->val << " ";
        index = index->next;
    }
    cout << endl;
}

// 优化内存及时间
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *head_index = head;
        ListNode *end_index = head_index->next;
        ListNode *new_head = head->next;

        ListNode *pre_node;

        // node1->node2->node2.next
        head_index->next = end_index->next;
        end_index->next = head_index;
        // node2->node1->node2.next
        pre_node = head_index;

        // move node1 node1 = node2.next, node2 = node1.next
        head_index = head_index->next;

        if (head_index != NULL && head_index->next) {
            end_index = head_index->next;
            process(pre_node, head_index, end_index);
        }

        return new_head;
    }

    void process(ListNode *&pre_node, ListNode *&node1, ListNode *&node2) {
        // node1->node2->node2.next
        node1->next = node2->next;
        node2->next = node1;
        // node2->node1->node2.next

        pre_node->next = node2;
        pre_node = node1;

        // move node1 node1 = node2.next, node2 = node1.next
        node1 = node1->next;

        if (node1 != NULL && node1->next) {
            node2 = node1->next;
            process(pre_node, node1, node2);
        }
    }
};

// 第一次实现
//class Solution {
//public:
//    ListNode* swapPairs(ListNode* head) {
//        if (head == NULL || head->next == NULL) {
//            return head;
//        }
//
//        ListNode *end_index = head->next;
//        ListNode *head_index = head;
//
//        ListNode *new_head = end_index;
//        ListNode *pre_node = NULL;
//
//        process(pre_node, head_index, end_index);
//        while (pre_node != NULL) {
//            process(pre_node, head_index, end_index);
//        }
//
//        return new_head;
//    }
//
//    // return pre_node, if NULL node1->next or node2->next is NULL
//    void process(ListNode *&pre_node, ListNode *&node1, ListNode *&node2) {
//        // node1->node2->node2.next
//        node1->next = node2->next;
//        node2->next = node1;
//        // node2->node1->node2.next
//        if (pre_node != NULL) {
//            pre_node->next = node2;
//        }
//        pre_node = node1;
//
//        // move node1 node1 = node2.next, node2 = node1.next
//        node1 = node1->next;
//
//        if (node1 != NULL && node1->next) {
//            node2 = node1->next;
//        } else {
//            pre_node = NULL;
//        }
//    }
//};

int main() {
    ListNode *list1 = new ListNode(6);
    pushNode(list1, 5);
    pushNode(list1, 4);
    pushNode(list1, 3);
    pushNode(list1, 2);
    pushNode(list1, 1);
    printNode(list1);
    Solution solution;
    ListNode *list2 = solution.swapPairs(list1);
    cout << "after swap:";
    printNode(list2);

    return 0;
}