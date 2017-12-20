//
//  main.c
//  Binary_Tree_3
//
//  Created by William on 2017/12/20.
//  Copyright © 2017年 William. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define DataType int
#define MAX 10000

typedef struct node{
    DataType data;
    struct node *lchild;
    struct node *rchild;
    //标记
    int flag;
}BNode ,*BiTree;

BiTree initTree(){
    BiTree t = (BiTree)malloc(sizeof(BNode));
    t->lchild = NULL;
    t->rchild = NULL;
    t->flag = 0;
    return t;
}

//定义栈的存储结构
typedef struct stack{
    BNode data[MAX];
    int top;
}Stack;

//置空栈
Stack *initStack(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

//入栈和出栈
void pushStack(Stack *s,BNode *node){
    if(s->top == MAX){
        return;
    }
    s->data[++s->top] = *node;
}

BNode *popStack(Stack *s){
    if(s->top == -1){
        return 0;
    }
    return &s->data[s->top--];
}

//取栈顶元素
BNode *getTop(Stack *s){
    if(s->top == -1){
        return 0;
    }
    return &s->data[s->top];
}

//使用非递归的后序遍历算法改进
void printSuperNode_(BiTree t,DataType x){
    if(t == NULL){
        return;
    }
    //创建一个栈来存储节点
    Stack *nodes = initStack();
    BiTree s = t;
    while(!(s == NULL && nodes->top == -1)){
        while(s != NULL){
            //如果找到x元素
            if(s->data == x){
                //将栈中元素打印
                while(nodes->top != -1){
                    printf("%d",popStack(nodes)->data);
                }
                break;
            }
            //入栈
            pushStack(nodes, s);
            s = s->lchild;
        }
        //如果栈空直接跳出循环
        if(nodes->top < 0)
            break;
        //判断是第几次访问节点
        if(getTop(nodes)->flag == 0){
            //访问右孩子
            s = getTop(nodes);
            s = s->rchild;
        }else{
            popStack(nodes);
            s = NULL;
        }
        
    }
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
