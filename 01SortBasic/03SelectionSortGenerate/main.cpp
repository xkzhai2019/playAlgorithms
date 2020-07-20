//
//  main.cpp
//  03SelectionSortGenerate
//
//  Created by xkzhai on 2020/7/15.
//  Copyright © 2020 njust. All rights reserved.
//

#include <iostream>
#include <algorithm> // 旧标准， 包含swap
#include <string> // 旧标准，包含string
#include "SortTestHelper.h"

using namespace std; // C++ 11标准，内置swap

template<typename T> // 模版函数，泛型，

void selectionSort(T arr[], int n){
    for(int i = 0; i<n ; i++){
        
        // 寻找[i,n)区间的最小值所在索引
        int minIndex = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i],arr[minIndex]); // C++ 11标准库内置
    }
}

int main(int argc, const char * argv[]) {
    
    int n = 10000;
    
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    selectionSort(arr, n);
    SortTestHelper::printArray(arr, n);
//    for (int i=0; i<n; i++) {
//        cout<<arr[i]<<" ";
//    }
//    cout<<endl;
    
    // 释放数组空间，不然存在内存泄露的风险
    delete[] arr;
    
    cout << "Hello, World!\n";
    return 0;
}
