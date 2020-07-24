//
//  main.cpp
//  04QuickSort
//
//  Created by xkzhai on 2020/7/21.
//  Copyright © 2020 njust. All rights reserved.
//

#include <iostream>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "InsertSort.h"

using namespace std;

// 对arr[l...r]部分进行partition操作
// 返回p，使得arr[l...p-1] < arr[p] < arr[p+1...r]
template<typename T>
int __partition(T arr[],int l, int r){
    // 随机选取基准值
    swap(arr[l], arr[rand() % (r-l+1) + l]);
    T v = arr[l];
    
    // arr[l+1...j] < v; arr[j+1...i)>v
    
    // 初始情况下两段都为空
    int j = l;
    for(int i = l+1;i<=r;i++){
        if(arr[i] < v){
            swap(arr[j+1],arr[i]);
            j++;
        }
    }
    
    // 访问完所有元素后，交换基准值与<v部分末尾元素
    swap(arr[l],arr[j]); // arr[l...j-1] < v; arr[j] = v; arr[j+1...i)>v
    // 返回基准值所在位置
    return j;
}


// 对arr[l...r]部分进行快速排序
template<typename T>
void __quickSort(T arr[],int l, int r){
//    if(l>=r)
//        return;
    
    if(r-l<=15){
        insertionSort(arr, l, r);
        return;
    }
    
    int p = __partition(arr,l,r);
    __quickSort(arr,l,p-1);
    __quickSort(arr, p+1, r);
}


template<typename T>
void quickSort(T arr[], int n){
    srand(time(NULL));
    __quickSort(arr,0,n-1);
}

int main(int argc, const char * argv[]) {
    
    int n = 1000000;
    cout<<"Test for Random Array, size= "<<n<<",random range[0,"<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Merge Sort", mergeSort,arr1, n); // 0.18 s
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n); // 0.17 s
    
    delete[] arr1;
    delete[] arr2;
    
    int swapTimes = 100;
    cout<<"Test for Nearly Ordered Array, size= "<<n<<",swapTime="<<swapTimes<<endl;
    
    arr1 = SortTestHelper::generateNearlyOrderArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Merge Sort", mergeSort,arr1, n); // 0.0438 s
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n); // 优化后，0.106 s
    
    delete[] arr1;
    delete[] arr2;
    
    return 0;
}
