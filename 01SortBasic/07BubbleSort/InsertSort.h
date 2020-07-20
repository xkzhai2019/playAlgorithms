//
//  InsertSort.h
//  07BubbleSort
//
//  Created by xkzhai on 2020/7/20.
//  Copyright © 2020 njust. All rights reserved.
//

#ifndef InsertSort_h
#define InsertSort_h

#include <iostream>
#include <algorithm>

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

#endif /* InsertSort_h */
