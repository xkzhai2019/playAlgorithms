//
//  MergeSort.h
//  03MergeSortBottomUp
//
//  Created by xkzhai on 2020/7/21.
//  Copyright © 2020 njust. All rights reserved.
//

#ifndef MergeSort_h
#define MergeSort_h

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
  
    if(r-l <= 15){
        insertionSort(arr, l, r);
        return;
    }
    
    int mid = l+(r-l)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    if(arr[mid]>arr[mid+1])
        __merge(arr,l,mid,r);
}



template<typename T>
void mergeSort(T arr[],int n){
    // python风格，表私有函数
    __mergeSort(arr,0,n-1);
}

#endif /* MergeSort_h */
