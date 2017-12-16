//
//  main.c
//  Binary_Tree_2
//
//  Created by William on 2017/12/15.
//  Copyright © 2017年 William. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define DataType int
#define MAX 10000
typedef struct tree{
    DataType *data;
    int nodeNum;
}*BiTree;

//定义栈的结构
typedef struct stack{
    int data[MAX];
    int top;
    int length;
}Stack;

//初始化栈
Stack *init_Stack(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    s->length = 0;
    return s;
}

//入栈
void push_Stack(int data,Stack *s){
    if(s->top+1!=MAX){
        s->data[++s->top] = data;
        s->length++;
    }
    return;
    
}

//出栈
int pop_Stack(Stack *s){
    if(s->top!=-1){
        s->length--;
        return s->data[s->top--];
    }
    return 0;
    
}

//取栈顶元素
int getTop(Stack *s){
    if(s->top == -1){
        return 0;
    }
    return s->data[s->top];
}

//通过修改非递归先序遍历的算法实现
void Pre_Order_complete_BiTree(BiTree t){
    if(t==NULL){
        return;
    }
    Stack *s = init_Stack();
    int i = 1;
    while(!(i>t->nodeNum && s->top==-1)){
        //若i所在的节点在数组中
        while(i<t->nodeNum){
            printf("%d",t->data[i]);
            push_Stack(i, s);
            //访问其左孩子
            i = i * 2;
        }
        //若不在数组中则出栈
        i = pop_Stack(s);
        i = i * 2 + 1;
    }
}

int main(int argc, const char * argv[]) {
    return 0;
}
