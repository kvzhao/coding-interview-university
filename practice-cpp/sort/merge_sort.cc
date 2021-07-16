
#include "sort_algorithm.hpp"

#include <iostream>
#include <vector>

void MergeSort::sort(std::vector<int>& arr) {

    aux.assign(arr.begin(), arr.end());
    _sort(arr, aux, 0, arr.size() - 1);
}

void MergeSort::_sort(vector<int>& arr, vector<int>& aux, int lo, int hi) {

    if (hi <= lo) {
        return;
    }

    int mid = lo + (hi - lo) / 2;

    // switch arr and aux for eliminating copy
    _sort(aux, arr, lo, mid);
    _sort(aux, arr, mid + 1, hi);
    merge(arr, aux, lo, mid, hi);
}

void MergeSort::merge(vector<int>& arr, vector<int>& aux, int lo, int mid, int hi) {

    int left = lo, right = mid + 1;

    for (int i = lo; i < hi + 1; i++) {
        if (left > mid) {
            arr[i] = aux[right++];
        } else if (right > hi) {
            arr[i] = aux[left++];
        } else if (aux[right] < aux[left]) {
            arr[i] = aux[right++];
        } else {
            arr[i] = aux[left++];
        }
    }
}