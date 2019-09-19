#include <iostream>
#include <vector>

using namespace std;

void mergeArray(vector<int> &list, int left_start, int mid, int right_end) {
    int i = left_start;
    int j = mid;
    int k = 0;

    vector<int> temp(right_end-left_start);
    while (i < mid && j < right_end) {
        if (list[i] < list[j]) {
            temp[k++] = list[i++];
        } else {
            temp[k++] = list[j++];
        }
    }

    while (i < mid) {
        temp[k++] = list[i++];
    }

    while (j < right_end) {
        temp[k++] = list[j++];
    }

    i = left_start;
    k = 0;
    for (; i < right_end; ++i, ++k) {
        list[i] = temp[k];
    }
}

void mergeSort(vector<int> &list, int left_start, int mid, int right_end) {
    if (mid < right_end && left_start != mid) {
        mergeSort(list, left_start, (left_start + mid)/2, mid);
        mergeSort(list, mid, (right_end + mid)/2, right_end);
        mergeArray(list, left_start, mid, right_end);
    }
}

int main() {
    vector<int> list = {3, 1, 2, 5, 4, 6, 9, 7, 10, 8};

    mergeSort(list, 0, list.size()/2, list.size());

    for (int i = 0; i < list.size(); ++i) {
        cout << list[i] << ",";
    }

    cout << endl;
    return 0;
}