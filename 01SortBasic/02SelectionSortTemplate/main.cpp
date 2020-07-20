//
//  main.cpp
//  01SelectionSort
//
//  Created by xkzhai on 2020/7/15.
//  Copyright © 2020 njust. All rights reserved.
//

#include <iostream>
#include <algorithm> // 旧标准， 包含swap
#include <string> // 旧标准，包含string
#include "Student.h" // 自己编写的h文件，使用双引号
using namespace std; // C++ 11标准，内置swap

template<typename T> // 模版函数，泛型

void selectionSort(T arr[], int n){
    for(int i = 0; i<n ; i++){
        
        // 寻找[i,n)区间的最小值所在索引
        int minIndex = i;
        for(int j = i+1; j<n; j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i],arr[minIndex]); // C++ 11标准库内置
    }
}

int main(int argc, const char * argv[]) {
    
    int a[10] = {4,7,10,3,2,1,6,8,5,9};
    selectionSort(a, 10);
    for (int i=0; i<10; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl; // 1 2 3 4 5 6 7 8 9 10
    
    
    float b[4] = {2.1,1.0,2.1,3.2};
    selectionSort(b, 4);
    for (int i=0; i<4; i++) {
        cout<<b[i]<<" ";
    }
    cout<<endl; // 1.0 2.1 2.1 3.2
    
    string c[5] = {"D","E","A","C","B"};
    selectionSort(c, 5);
    for (int i=0; i<5; i++) {
        cout<<c[i]<<" ";
    }
    cout<<endl; // A B C D E
    
    Student d[4] = {{"D",90},{"C",100},{"B",95},{"A",90}};
    selectionSort(d, 4);
    for (int i=0; i<4; i++) {
        cout<<d[i];
    }
    cout<<endl; // C: 100 B: 95 A: 90 D: 90
    
    cout << "Hello, World!\n";
    return 0;
}
