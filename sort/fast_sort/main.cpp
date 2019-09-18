#include <iostream>
#include <vector>

using namespace std;

void fastSort(vector<int> &list, int start, int end) {
    if (start >= end)
        return;

    int key = list[end];
    int i = start;
    int j = end - 1;

    while (i < j) {
        while (list[i] < key && i < j) {
            ++i;
        }

        while (list[j] > key && i < j) {
            --j;
        }

        if (i < j) {
            int mid = list[i];
            list[i] = list[j];
            list[j] = mid;
        }
    }

    if (list[i] > key) {
        list[end] = list[i];
        list[i] = key;
    }

    fastSort(list, start, i);
    fastSort(list, i + 1, end);
}

int main() {
    vector<int> list = {3, 1, 2, 5, 4, 6, 9, 7, 10, 8};

    fastSort(list, 0, list.size() - 1);

    for (int i = 0; i < list.size(); ++i) {
        cout << list[i] << ",";
    }

    cout << endl;
    return 0;
}