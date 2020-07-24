//
//  main.cpp
//  01MergeSort
//
//  Created by xkzhai on 2020/7/21.
//  Copyright © 2020 njust. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "InsertSort.h"

using namespace std;

// 对arr[l...mid]和arr[mid+1...r]两部分进行归并
template<typename T>
void __merge(T arr[],int l,int mid,int r){
    
    // 将合并前的序列备份
    // arr[l...r] <---> aux[0...r-l]
    T aux[r-l+1];
    for(int i=l;i<=r;i++)
        aux[i-l] = arr[i];
    
    int i = l, j = mid+1; // i, j的初始索引位置
    
    for(int k=l;k<=r;k++){
        // 如果第一个子序列已归并完成，则直接将第二个序列填充到后续位置即可
        if(i>mid){
            arr[k] = aux[j-l];
            j++;
        }
        // 同理，如果第二个子序列已归并完成，则直接将第一个序列填充到后续位置即可
        else if(j>r){
            arr[k] = aux[i-l];
            i++;
        }
        // 对比第一个序列和第二个序列当前位置元素的大小
        else if(aux[i-l]<aux[j-l]){
            arr[k] = aux[i-l];
            i++;
        }
        else{
            arr[k] = aux[j-l];
            j++;
        }
    }
}

// 递归使用归并排序，对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort(T arr[],int l,int r){
//    if(l>=r)
//        return;
  
    // 序列规模小到一定程度时，改用插入排序
    if(r-l <= 15){
        insertionSort(arr, l, r);
        return;
    }
    
    int mid = l+(r-l)/2;
    //将待排序序列分为两部分，每部分单独排序
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    
    // 只有在第二个子序列的最小值小于第一个序列的最大值时，才进行合并
    if(arr[mid]>arr[mid+1])
        __merge(arr,l,mid,r);
}

template<typename T>
void mergeSort(T arr[],int n){
    // python风格，表私有函数
    __mergeSort(arr,0,n-1);
}

int main(int argc, const char * argv[]) {
    
    int n = 50000;
    cout<<"Test for Random Array, size= "<<n<<",random range[0,"<<n<<"]"<<endl;
    int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Insertion Sort", insertionSort,arr1, n); // 1.307 s
    SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n); // 0.0086 s
    
    delete[] arr1;
    delete[] arr2;
    
    std::cout << "Hello, World!"<<endl;
    
    int swapTimes = 10;
    cout<<"Test for Nearly Ordered Array, size= "<<n<<",swapTime="<<swapTimes<<endl;
    
    arr1 = SortTestHelper::generateNearlyOrderArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Insertion Sort", insertionSort,arr1, n); // 0.000659 s
    SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n); // 0.00477 s, 0.001693 s, 0.001497 s
    
    delete[] arr1;
    delete[] arr2;
    
    
    return 0;
}
