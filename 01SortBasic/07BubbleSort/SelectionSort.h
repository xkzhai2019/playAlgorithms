//
//  SelectionSort.h
//  05InsertSort
//
//  Created by xkzhai on 2020/7/15.
//  Copyright © 2020 njust. All rights reserved.
//

#ifndef SelectionSort_h
#define SelectionSort_h

#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void selectionSort(T arr[],int n){
    for(int i=0;i<n;i++){
        int minIndex = i;
        for(int j = i+1;j<n;j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        // swap(arr[i],arr[minIndex]);
        int tmp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = tmp;
    }
}

#endif /* SelectionSort_h */
