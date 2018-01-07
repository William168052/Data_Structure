//
//  main.c
//  PAT排名汇总
//
//  Created by William on 07/01/2018.
//  Copyright © 2018 William. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 13
typedef struct student{
    char *IDArray;
    int score;
    //最终排名
    int finalLevel;
    //考点排名
    int testPlaceLevel;
    //考点内排名
    int placeLevel;
}Student;

typedef struct listNode{
    Student *stuArr;
    int stuNum;
    struct listNode *next;
}ListNode,*List;

List init(){
    List l = (ListNode *)malloc(sizeof(ListNode));
    l->stuArr = (Student *)malloc(sizeof(Student) * 300);
    l->next = NULL;
    return l;
}

void sortAndPrint(List list,int wholeNum){
    Student *wholeStuArr = (Student *)malloc(sizeof(Student) * wholeNum);
    int index = 0;
    ListNode *p = list;
    while (p) {
//        printf("%d\n",p->stuNum);
        //考场内排名（选择排序）
        for(int i = 0;i<p->stuNum;i++){
            int max = 0;
            int maxIndex = 0;
            for(int j = i;j<p->stuNum;j++){
                if(p->stuArr[j].score > max){
                    max = p->stuArr[j].score;
                    maxIndex = j;
                }
            }
            //找到最大的将它放到最前面
            Student temp = p->stuArr[maxIndex];
            for(int j = maxIndex - 1;j>=i;j--){
                p->stuArr[j+1] = p->stuArr[j];
            }
            //设置名次
            if(temp.score == p->stuArr[i-1].score && i > 0){
                temp.placeLevel = p->stuArr[i-1].placeLevel;
            }else{
                temp.placeLevel = i+1;
            }
            
            //放到第一个位置
            p->stuArr[i] = temp;
            //把它装进总的数组中
            wholeStuArr[index++] = temp;
        }
        p = p->next;
    }
    //此时已经在考场内排好名次了
//    for(int i = 0;i<wholeNum;i++){
//        printf("%s %d\n",wholeStuArr[i].IDArray,wholeStuArr[i].score);
//    }
    //使用选择排序排名
    for(int i = 0;i<wholeNum;i++){
        int max = 0;
        int maxIndex = 0;
        for(int j = i;j<wholeNum;j++){
            if(wholeStuArr[j].score > max){
                max = wholeStuArr[j].score;
                maxIndex = j;
            }
        }
        Student temp = wholeStuArr[maxIndex];
        for(int j = maxIndex-1;j>=i;j--){
            wholeStuArr[j+1] = wholeStuArr[j];
        }
        if(temp.score == wholeStuArr[i-1].score && i > 0){
            temp.finalLevel = wholeStuArr[i-1].finalLevel;
        }else{
            temp.finalLevel = i+1;
        }
        wholeStuArr[i] = temp;
    }
    //打印结果
    printf("%d\n",wholeNum);
    for(int i = 0;i<wholeNum;i++){
        printf("%s %d %d %d\n",wholeStuArr[i].IDArray,wholeStuArr[i].finalLevel,wholeStuArr[i].testPlaceLevel,wholeStuArr[i].placeLevel);
    }
    
}
int main(int argc, const char * argv[]) {
    int N,wholeNum = 0;
    scanf("%d",&N);
    List stuList = NULL;
    for(int i = 0;i<N;i++){
        int K;
        scanf("%d",&K);
        //计算总人数
        wholeNum += K;
        ListNode *node = init();
        node->next = NULL;
        node->stuNum = K;
        Student *stuArr = (Student *)malloc(sizeof(Student) * K);
        for(int j = 0;j<K;j++){
            stuArr[j].IDArray = (char *)malloc(sizeof(char) * MAX);
            scanf("%s %d",stuArr[j].IDArray,&stuArr[j].score);
            //考场排名
            stuArr[j].testPlaceLevel = i+1;
        }
        node->stuArr = stuArr;
        if(stuList == NULL){
            stuList = node;
        }else if(stuList->next == NULL){
            stuList->next = node;
        }else{
            ListNode *temp = stuList->next;
            stuList->next = node;
            node->next = temp;
        }
    }
    sortAndPrint(stuList,wholeNum);
    return 0;
}
