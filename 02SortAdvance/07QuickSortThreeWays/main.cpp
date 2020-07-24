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
// 返回p，使得arr[l...p-1] < arr[p] < arr[p+1...r]
template<typename T>
int __partition2(T arr[],int l, int r){
    
    swap(arr[l], arr[rand() % (r-l+1) + l]);
    T v = arr[l];
    
    // arr[l+1...i) <= v; arr(j...r) >= v
     // 初始情况下两段都为空
    int i = l+1,j=r;
    while(true){
        while(i<= r && arr[i]<v)
            i++;
        while(j>=l+1 && arr[j]>v)
            j--;
        if(i>j)
            break;
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    
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
    
    int p = __partition2(arr,l,r);
    __quickSort2(arr,l,p-1);
    __quickSort2(arr, p+1, r);
}


template<typename T>
void quickSort2(T arr[], int n){
    srand(time(NULL));
    __quickSort2(arr,0,n-1);
}


// 三路快速排序处理 arr[l...r]
// 将arr[l...r] 分为 <v; ==v; >v 三部分
// 之后递归时，对<v；>v 两部分继续进行三路快速排序
template<typename T>
void __quickSort3ways(T arr[],int l, int r){
    
    if(r-l<=15){
        insertionSort(arr, l, r);
        return;
    }
    
    // partition，分块
    // 随机选取基准值
    swap(arr[l],arr[rand()%(r-l+1)+l]);
    T v = arr[l];
    
    // 初始三段都为空
    int lt = l; // arr[l+1...lt] < v
    int gt = r+1; // arr[gt...r] > v
    int i = l+1; // arr[lt+1...i)==v
    
    while(i<gt){
        
        // 当前访问元素小于v，将i位置元素和lt+1位置处元素互换位置，同时后移i和lt
        if(arr[i]<v){
            swap(arr[i],arr[lt+1]);
            lt++;
            i++;
        }
        // 当前访问元素大于v，将i位置元素和gt-1位置处元素互换位置，同时前移gt
        else if(arr[i]>v){
            swap(arr[i],arr[gt-1]);
            gt--;
        }
        // 当前访问元素等于v，后移i
        else{// arr[i]==v
            i++;
        }
    }
    
    // 访问完成后，交换基准值与lt位置的元素
    swap(arr[l],arr[lt]);
    // 分块完成后，对<v，>v部分单独快速排序
    __quickSort3ways(arr, l, lt-1);
    __quickSort3ways(arr, gt, r);
}

template<typename T>
void quickSort3Ways(T arr[], int n){
    srand(time(NULL));
    __quickSort3ways(arr,0,n-1);
}

int main(int argc, const char * argv[]) {
    
    int n = 1000000;
    
    cout<<"Test for Random Array, size= "<<n<<",random range[0,"<<n<<"]"<<endl;
    
    int* arr1 = SortTestHelper::generateRandomArray(n, 0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1, n);
    int* arr3 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Merge Sort", mergeSort,arr1, n); // 0.18 s
    SortTestHelper::testSort("Quick Sort2", quickSort2, arr2, n); // 0.15 s
    SortTestHelper::testSort("Quick Sort3", quickSort3Ways, arr3, n); // 0.22 s
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    
    int swapTimes = 100;
    cout<<"Test for Nearly Ordered Array, size= "<<n<<",swapTime="<<swapTimes<<endl;
    
    arr1 = SortTestHelper::generateNearlyOrderArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr1, n);
    
    SortTestHelper::testSort("Merge Sort", mergeSort,arr1, n); // 0.048 s
    SortTestHelper::testSort("Quick Sort2", quickSort2, arr2, n); // 0.046 s
    SortTestHelper::testSort("Quick Sort3", quickSort3Ways, arr3, n); // 0.178 s
    
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    
    cout<<"Test for Random Array, size= "<<n<<",random range[0,"<<"10"<<"]"<<endl;
    arr1 = SortTestHelper::generateRandomArray(n, 0, 10);;
    arr2 = SortTestHelper::copyIntArray(arr1, n);
    arr3 = SortTestHelper::copyIntArray(arr2, n);
       
    SortTestHelper::testSort("Merge Sort", mergeSort,arr1, n); // 0.123 s
    SortTestHelper::testSort("Quick Sort2", quickSort2, arr2, n); // 0.09 s
    SortTestHelper::testSort("Quick Sort3", quickSort3Ways, arr3, n); // 0.029 s
       
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    
    std::cout << "Hello, World!\n";
    return 0;
}
