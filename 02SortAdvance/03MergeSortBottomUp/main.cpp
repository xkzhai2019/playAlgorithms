//
//  main.cpp
//  03MergeSortBottomUp
//
//  Created by xkzhai on 2020/7/21.
//  Copyright © 2020 njust. All rights reserved.
//

#include <iostream>
#include "MergeSort.h"

using namespace std;

template<typename T>
void mergeSortBU(T arr[],int n){
    for(int sz = 1;sz<=n;sz+=sz){
        for(int i = 0;i+sz<n;i+=sz+sz){
            // 对arr[i...i+sz-1] 和arr[i+sz...i+2*sz-1]进行归并
            __merge(arr,i,i+sz-1,min(i+sz+sz-1,n-1));
        }
    }
}

int main(int argc, const char * argv[]) {
    
    std::cout << "Hello, World!\n";
    return 0;
}
