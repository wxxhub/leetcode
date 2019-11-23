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
}


// 提升速度, 但是内存增加.
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }

        if (lists.size() == 1) {
            return lists[0];
        }

        if (lists.size() <= 2) {
            return mergeTwoLists(lists[0], lists[1]);
        }

        sortHead(lists);

        list<ListNode*> cache;
        ListNode *head = lists[0];
        ListNode *index_node = head;

        int index_flag = 1;
        int size = lists.size();

        addCacheNode(cache, lists[1]);
        addCacheNode(cache, lists[0]->next);


        while (!cache.empty() || index_flag < size - 1) {
            ListNode *current_node = cache.front();
            cache.pop_front();

            index_node->next = current_node;
            index_node = current_node;

            if (index_flag < size - 1 && current_node == lists[index_flag]) {
                addCacheNode(cache, lists[++index_flag]);
            }

            if (current_node->next != NULL) {
                addCacheNode(cache, current_node->next);
            }
        }

        return head;
    }

    /*
1 3 6
2 3 4
2 3 5
 */

    void addCacheNode(list<ListNode*>& lists, ListNode *node) {
        if (node == NULL) {
            return;
        }

        if (lists.empty()) {
            lists.push_back(node);
            return;
        }

        list<ListNode*>::iterator iter = lists.begin();

        while (iter != lists.end()) {
//            cout << (*iter)->val << endl;
            if ((*iter)->val < node->val) {
                ++iter;
            } else {
                break;
            }
        }

        if (iter == lists.end()) {
            lists.push_back(node);
        } else {
            lists.insert(iter, node);
        }
    }

    void sortHead(vector<ListNode*>& lists) {
        for (vector<ListNode*>::iterator iter = lists.begin(); iter != lists.end(); ) {
            if ((*iter) != NULL ) {
                iter++;
            } else {
                iter = lists.erase(iter);
            }
        }
        fastSort(lists, 0, lists.size() - 1);
    }

    void fastSort(vector<ListNode*>& lists, int start, int end) {
        if (start >= end)
            return;

        ListNode *key = lists[end];
        int i = start;
        int j = end - 1;

        while (i < j) {
            while (lists[i]->val <= key->val && i < j) {
                ++i;
            }

            while (lists[j]->val > key->val && i < j) {
                --j;
            }

            if (i < j) {
                ListNode *mid_node = lists[i];
                lists[i] = lists[j];
                lists[j] = mid_node;
            }
        }

        if (lists[i]->val > key->val) {
            lists[end] = lists[i];
            lists[i] = key;
        }

        fastSort(lists, start, i);
        fastSort(lists, i + 1, end);
    }

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

// 低内存, 但是耗时.
//class Solution {
//public:
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        if (lists.empty()) {
//            return NULL;
//        }
//
//        while (lists.size() > 1) {
//            ListNode *l1 = *lists.begin();
//            lists.erase(lists.begin());
//            ListNode *l2 = *lists.begin();
//            lists.erase(lists.begin());
//            lists.push_back(mergeTwoLists(l1, l2));
//        }
//
//        return lists[0];
//    }
//
//    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//        if (l1 == NULL) {
//            return l2;
//        }
//
//        if (l2 == NULL) {
//            return l1;
//        }
//        ListNode *index1 = l1;
//        ListNode *index2 = l2;
//        ListNode *result;
//
//        if (index1->val > index2->val) {
//            result = index2;
//            index2 = index2->next;
//        } else {
//            result = index1;
//            index1 = index1->next;
//        }
//
//        ListNode *result_index = result;
//
//        while (index1 != NULL && index2 != NULL) {
//            if (index1->val > index2->val) {
//                result_index->next = index2;
//                index2 = index2->next;
//            } else {
//                result_index->next = index1;
//                index1 = index1->next;
//            }
//            result_index = result_index->next;
//        }
//
//        if (index1 != NULL) {
//            result_index->next = index1;
//        } else {
//            result_index->next = index2;
//        }
//
//        return result;
//    }
//};

int main() {
    Solution solution;
    vector<ListNode*> lists;
//    ListNode *list1 = new ListNode(4);
//    ListNode *list2 = new ListNode(6);
//    ListNode *list3 = new ListNode(5);
//    ListNode *list0 = NULL;
//
//    pushNode(list1, 3);
//    pushNode(list1, 2);
//
//    pushNode(list2, 3);
//    pushNode(list2, 1);
//
//    pushNode(list3, 3);
//    pushNode(list3, 2);
//
//    lists.push_back(list1);
//    lists.push_back(list2);
//    lists.push_back(list0);
//    lists.push_back(list3);

    ListNode *list1 = new ListNode(5);
    ListNode *list2 = new ListNode(6);
    ListNode *list3 = new ListNode(0);
    ListNode *list4 = NULL;
//    ListNode *list0 = NULL;

    pushNode(list1, 4);
    pushNode(list1, 1);
    pushNode(list1, -2);

    pushNode(list2, 5);
    pushNode(list2, -2);

    pushNode(list3, -2);

    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);
    lists.push_back(list4);

    printNode(solution.mergeKLists(lists));
    return 0;
}