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
    
    swap(arr[l],arr[j]); // arr[l...j-1] < v; arr[j] = v; arr[j+1...i)>v
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

// 对arr[l...r]部分进行partition操作
// 返回p，使得arr[l...p-1] <= arr[p] <= arr[p+1...r]
template<typename T>
int __partition2(T arr[],int l, int r){
    
    // 随机选取基准值
    swap(arr[l], arr[rand() % (r-l+1) + l]);
    T v = arr[l];
    
    // arr[l+1...i) <= v; arr(j...r] >= v
     // 初始情况下两段都为空
    int i = l+1,j=r;
    while(true){
        // 后移i，直至遇到第一位>=v的元素
        while(i<= r && arr[i]<v)
            i++;
        // 前移j,直至遇到第一位<=v的元素
        while(j>=l+1 && arr[j]>v)
            j--;
        
        // i移到了j的后面，表明序列本身有序
        if(i>j)
            break;
        // 交换i,j位置的元素，使得第一部分<=v，第二部分>=v
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    
    // 访问完成后，交换基准值与>=v的首尾元素
    swap(arr[l],arr[j]);
    return j;
}

// 对arr[l...r]部分进行快速排序
template<typename T>
void __quickSort2(T arr[],int l, int r){
//    if(l>=r)
//        return;
    
    if(r-l<=15){
        insertionSort(arr, l, r);
        return;
    }
    
    // 对arr[l...r]分块
    int p = __partition2(arr,l,r);
    
    // 对<=v部分快速排序
    __quickSort2(arr,l,p-1);
    
    // 对>=v部分快速排序
    __quickSort2(arr, p+1, r);
}


template<typename T>
void quickSort2(T arr[], int n){
    srand(time(NULL));
    __quickSort2(arr,0,n-1);
}

int main(int argc, const char * argv[]) {
    
    int n = 1000000;
    
   cout<<"Test for Random Array, size= "<<n<<",random range[0,"<<n<<"]"<<endl;
    
    int* arr1 = SortTestHelper::generateRandomArray(n, 0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    int* arr3 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Merge Sort", mergeSort,arr1, n); // 0.18 s
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n); // 0.17 s
    SortTestHelper::testSort("Quick Sort2", quickSort2, arr3, n); // 0.15 s
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    
    int swapTimes = 100;
    cout<<"Test for Nearly Ordered Array, size= "<<n<<",swapTime="<<swapTimes<<endl;
    
    arr1 = SortTestHelper::generateNearlyOrderArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Merge Sort", mergeSort,arr1, n); // 0.0438 s
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n); // 0.11 s
    SortTestHelper::testSort("Quick Sort2", quickSort2, arr3, n); // 0.049 s
    
    
    cout<<"Test for Random Array, size= "<<n<<",random range[0,"<<"10"<<"]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n, 0, 10);;
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr2, n);
       
    SortTestHelper::testSort("Merge Sort", mergeSort,arr1, n); // 对重复元素很多时，0.123 s
    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n); // 对重复元素很多时，78 s
    SortTestHelper::testSort("Quick Sort2", quickSort2, arr3, n); // 优化后，0.09 s
       
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    
    std::cout << "Hello, World!\n";
    return 0;
}
