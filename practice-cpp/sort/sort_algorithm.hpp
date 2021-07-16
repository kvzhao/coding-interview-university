
#pragma once

#include <vector>

using namespace std;

class MergeSort {

public:
void sort(vector<int>& arr);

private:

void merge(vector<int>& arr, vector<int>& aux, int low, int mid, int high);
void _sort(vector<int>& arr, vector<int>& aux, int low, int high);

vector<int> aux;

};


class QuickSort {

public:
void sort(vector<int>& arr);

private:
void _sort();
void _partition();

};