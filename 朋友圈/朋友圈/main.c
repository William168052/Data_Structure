//
//  main.c
//  朋友圈
//
//  Created by William on 2017/12/11.
//  Copyright © 2017年 William. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define DataType int
typedef struct club{
    int eleNum;
    struct club *next;
}Club;

Club *initClub(int eleNum){
    Club *c = (Club *)malloc(sizeof(Club));
    c->eleNum = eleNum;
    c->next = NULL;
    return c;
}


typedef struct person{
    DataType data;
    Club *clubs;
}Person;

typedef struct circle{
    Person *p;
    int pNum;
}FriendCircle;
int MaxCircle(FriendCircle *FC){
    //定义一个计数变量
    int countMax = 0;
    int count = 0;
    for (int i = 1; i < FC -> pNum; i++) {
        count = 0;
        Person p = FC->p[i];
        Club *c = p.clubs;
        while(c){
            count += c -> eleNum-1;
            c = c -> next;
        }
        //加上自己
        count++;
        countMax = count > countMax ? count : countMax;
    }
    return countMax;
}


int main(int argc, const char * argv[]) {
    //定义学生总数和俱乐部的个数
    int n,m;
    scanf("%d %d",&n,&m);
    //从第一号元素开始存
    Person *p = (Person *)malloc(sizeof(Person) * n+1);
    for(int i = 1;i<n+1;i++){
        p[i].data = i;
        p[i].clubs = NULL;
    }
//    for (int i = 0; i<n+1; i++) {
//        printf("%d ",p[i].data);
//    }
    for(int j = 0;j<m;j++){
        int num;
        scanf("%d",&num);
        Club *c = initClub(num);
//        printf("%d",c->eleNum);
        for(int k = 0;k<num;k++){
            int pIndex;
            Club *temp;
            scanf("%d",&pIndex);
            //插入操作
            if(p[pIndex].clubs != NULL){
                temp = p[pIndex].clubs;
                c->next = temp;
            }
            p[pIndex].clubs = c;
        }
    }
    
    FriendCircle *circle = (FriendCircle *)malloc(sizeof(FriendCircle));
    circle->p = p;
    circle->pNum = n+1;
    
    printf("%d",MaxCircle(circle));
    return 0;
}
