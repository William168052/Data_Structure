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
/*

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

*/

typedef struct friend{
    DataType index;
    struct friend *next;
}Friend;

typedef struct person{
    DataType index;
    _Bool isVisited;
    Friend *friends;
}Person;



typedef struct circle{
    Person *p;
    int pNum;
}FriendCircle;

//定义队列的数据类型
typedef struct queue{
    DataType *Quedata;
    int QLength;
    int front;
    int rear;
}Queue;
//置空队
Queue *initQueue(int QLength){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->Quedata = (DataType *)malloc(sizeof(DataType) * QLength);
    q->front = -1;
    q->rear = -1;
    q->QLength = QLength;
    return q;
}

//入队
void Push(Queue *Q,DataType data){
    if(Q->rear+1 == Q->QLength){
        return;
    }else{
        Q->Quedata[++Q->rear] = data;
    }
}


//出队
DataType Pop(Queue *Q){
    if(Q->front == Q->rear){
        return (DataType)0;
    }else{
        return Q->Quedata[++Q->front];
    }
}

void addFriend(DataType index,Person *p){
    Friend *f = (Friend *)malloc(sizeof(Friend));
    f->index = index;
    if(p->friends != NULL){
        Friend *temp;
        temp = p->friends;
        f->next = temp;
    }
    p->friends = f;
}

int MaxCircle(FriendCircle *FC){
   /*
    
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
    */

    Queue *Q = initQueue(FC->pNum);
    int count = 1;
    int countMax = 0;
    int i = 1;
    //把第一个元素入队
    Push(Q, FC->p[i].index);
    
    //如果队列不空且数组没有完全遍历就执行循环
    while(!(Q->front == Q->rear && i<FC->pNum)){
        
        //队列不空出队
        while(Q->front != Q->rear){
            DataType index = Pop(Q);
            //如果没被访问过就访问
            if(FC->p[index].isVisited != 1){
                Person p = FC->p[index];
                p.isVisited = 1;
                Friend *f = p.friends;
                //访问它的friends
                while (f) {
                    //没被访问过的入队
                    if(FC->p[f->index].isVisited != 1){
                        //入队
                        Push(Q, f->index);
                        count++;
                    }
                    f = f->next;
                }
            }
        }
        
        
        
        
        //若队列空
        i++;
        if(FC->p[i].isVisited != 1){
            if(count>countMax){
                countMax = count;
            }
            count = 0;
            Person p = FC->p[i];
            p.isVisited = 1;
            Friend *f = p.friends;
            //访问它的friends
            while (f) {
                //没被访问过的入队
                if(FC->p[f->index].isVisited != 1){
                    //入队
                    Push(Q, f->index);
                    count++;
                }
                f = f->next;
            }
        }
        
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
        p[i].index = i;
        p[i].isVisited = 0;
        p[i].friends = NULL;
    }
//    for (int i = 0; i<n+1; i++) {
//        printf("%d ",p[i].friends);
//    }
    //循环读取俱乐部的人员
    for(int j = 0;j<m;j++){
        int num;
        scanf("%d",&num);
//        printf("%d",c->eleNum);
        for(int k = 0;k<num;k++){
            int pIndex;
            Friend *temp;
            Friend *f = (Friend *)malloc(sizeof(Friend));
            scanf("%d",&pIndex);
            //插入操作
            
        }
    }

    FriendCircle *circle = (FriendCircle *)malloc(sizeof(FriendCircle));
    circle->p = p;
    circle->pNum = n+1;

    printf("%d",MaxCircle(circle));
    return 0;
}
