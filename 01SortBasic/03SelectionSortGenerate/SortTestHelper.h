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
#include <ctime> // 随机种子srand及时间统计
#include <cassert> // 断言函数assert;

using namespace std;

namespace SortTestHelper {
    
    // 生成有n个元素的随机数组，每个元素的随机范围是[rangeL,rangeR]
    int* generateRandomArray(int n, int rangeL, int rangeR){
        
        assert(rangeL <= rangeR); // 左边界应小于右边界
        
        int *arr = new int[n];
        srand(time(NULL)); // 设置随机种子为当前时间
        for(int i=0;i<n;i++)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        return arr;
    }

    // 打印数组前n个元素
    template<typename T>
    void printArray(T arr[], int n){
        for (int i=0; i<n; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        
        return;
    }
}

#endif /* SortTestHelper_h */
