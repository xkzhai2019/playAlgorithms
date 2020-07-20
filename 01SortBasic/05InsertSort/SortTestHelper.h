//
//  SortTestHelper.h
//  03SelectionSortGenerate
//
//  Created by xkzhai on 2020/7/15.
//  Copyright © 2020 njust. All rights reserved.
//

#ifndef SortTestHelper_h
#define SortTestHelper_h

#include <iostream>
#include <ctime> // 随机种子srand及时间统计clock
#include <cassert> // 断言函数assert;

using namespace std;

namespace SortTestHelper {
    
    // 生成有n个元素的随机数组，每个元素的随机范围是[rangeL,rangeR]
    int* generateRandomArray(int n, int rangeL, int rangeR){
        
        assert(rangeL <= rangeR);
        
        int *arr = new int[n];
        srand(time(NULL)); // 设置随机种子为当前时间
        for(int i=0;i<n;i++)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n){
        for (int i=0; i<n; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        
        return;
    }

    // 判读数组是否排序成功
    template<typename T>
    bool isSorted(T arr[], int n){
        for (int i=0; i<n-1; i++) {
            if(arr[i]>arr[i+1])
                return false;
        }
        cout<<endl;
        
        return true;
    }
    
    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n){
        clock_t startTime = clock();
        sort(arr,n);
        clock_t endTime = clock();
        
        assert(isSorted(arr,n)); // 如果false,则程序中断
        cout<<sortName<<":"<< double(endTime - startTime) / CLOCKS_PER_SEC << "s"<<endl;
        return;
    }

    // 使用泛型时，注意深拷贝与浅拷贝的处理
    int* copyIntArray(int a[],int n){
        int *arr = new int[n];
        copy(a,a+n,arr); // std内置
        return arr;
    }
}

#endif /* SortTestHelper_h */
