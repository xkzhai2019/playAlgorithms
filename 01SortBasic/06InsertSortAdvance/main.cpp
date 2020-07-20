//
//  main.cpp
//  05InsertSort
//
//  Created by xkzhai on 2020/7/15.
//  Copyright © 2020 njust. All rights reserved.
//

#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
using namespace std;

template<typename T>
void insertionSort(T arr[], int n){
    for(int i = 1;i<n;i++){
        // 寻找元素arr[i]合适的插入位置
        T e = arr[i];
        int j; // j保存元素e应该插入的位置
        for(j = i; j>0 && arr[j-1]>e;j--){
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

int main(int argc, const char * argv[]) {
    
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n); // 0.05 s
    SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n); // 0.08 s
    
    delete[] arr;
    delete[] arr2;
    
    int *arr3 = SortTestHelper::generateNearlyOrderArray(n, 100);
    int *arr4 = SortTestHelper::copyIntArray(arr3, n);
    
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr3, n); // 0.0014 s
    SortTestHelper::testSort("Selection Sort", selectionSort, arr4, n); // 0.08 s
    
    delete[] arr3;
    delete[] arr4;

    std::cout << "Hello, World!\n";
    return 0;
}
