//
//  Student.h
//  02SelectionSortTemplate
//
//  Created by xkzhai on 2020/7/15.
//  Copyright © 2020 njust. All rights reserved.
//

// 宏定义，解决有可能出现的头文件多重引用问题
#ifndef Student_h
#define Student_h

using namespace std; // 有可能出现命名空间污染

struct Student{
  
    string name;
    int score;
    
    // 对小于运算符重载,使结构体可以进行比较(Java中的Compareto)
    bool operator<(const Student &otherStudent){
        // return score < otherStudent.score; // 分数由低到高排列
        // return score > otherStudent.score; // 分数由高到低排列
        return score!= otherStudent.score ? score > otherStudent.score : name < otherStudent.name; // 三目运算符，分数相同时使用字符串的字典序
    }
    
    // 打印输出结果，对输出运算符进行重载(Java中的toString)
    friend ostream& operator<<(ostream &os, const Student &student){
        os<<"Student:"<<student.name<<" "<<student.score<<endl;
        return os;
    }
    
};

#endif /* Student_h */
