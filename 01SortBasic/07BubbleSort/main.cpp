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
#include "InsertSort.h"
using namespace std;

template<typename T>
void bubbleSort(T arr[], int n){
    // 外循环为走访次数，length个元素，需要走访length-1次
    for(int i=0;i<n-1;i++){
        int tmp;
        // 内循环为每次走访比较的次数，第i次需要比较length-(i+1)次
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    
    int *arr3 = SortTestHelper::copyIntArray(arr, n);
    
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n); // 0.05 s
    SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n); // 0.08 s
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n); // 0.21 s
    
    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    
    int *arr4 = SortTestHelper::generateNearlyOrderArray(n, 100);
    int *arr5 = SortTestHelper::copyIntArray(arr4, n);
     int *arr6 = SortTestHelper::copyIntArray(arr4, n);
    
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr4, n); // 0.0016 s
    SortTestHelper::testSort("Selection Sort", selectionSort, arr5, n); // 0.08 s
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr6, n); // 0.092 s
       
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    std::cout << "Hello, World!\n";
    return 0;
}
