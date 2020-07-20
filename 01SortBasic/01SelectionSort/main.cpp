//
//  main.cpp
//  01SelectionSort
//
//  Created by xkzhai on 2020/7/15.
//  Copyright © 2020 njust. All rights reserved.
//

#include <iostream>
#include <algorithm> // 旧标准， 包含swap
using namespace std; // C++ 11标准，内置swap

void selectionSort(int arr[], int n){
    for(int i = 0; i<n ; i++){
        
        // 寻找[i,n)区间的最小值所在索引
        int minIndex = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i],arr[minIndex]); // C++ 11标准库内置，交换两位置的元素
    }
}

int main(int argc, const char * argv[]) {
    
    int a[10] = {4,7,10,3,2,1,6,8,5,9};
    selectionSort(a, 10);
    for (int i=0; i<10; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    cout << "Hello, World!\n";
    return 0;
}
