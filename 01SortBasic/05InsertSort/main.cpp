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
        for(int j = i; j>0;j--){
            if (arr[j]<arr[j-1])
                swap(arr[j],arr[j-1]);
            else
                break;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n); // 0.1701s
    SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n); // 0.08 s
    
    delete[] arr;
    delete[] arr2;
    std::cout << "Hello, World!\n";
    return 0;
}
