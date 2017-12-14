//
//  main.c
//  Binary_Tree_1
//
//  Created by William on 2017/12/14.
//  Copyright © 2017年 William. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define DataType int
#define MAX 1000

//定义二叉树节点结构
typedef struct node{
    DataType data;
    struct node *lchild;
    struct node *rchild;
    //flag为标记，默认需初始化为0
    int flag;
}BNode,*BiTree;

//定义栈的结构
typedef struct stack{
    BNode *data[MAX];
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
void push_Stack(BNode *data,Stack *s){
    if(s->top+1!=MAX){
        s->data[++s->top] = data;
        s->length++;
    }
    return;
    
}

//出栈
BNode *pop_Stack(Stack *s){
    if(s->top--!=-1){
        s->length--;
        return s->data[--s->top];
    }
    return 0;
    
}

//取栈顶元素
BNode *getTop(Stack *s){
    if(s->top == -1){
        return 0;
    }
    return s->data[s->top];
}

/*
 递归算法
 */

//1.节点个数
int TreeNodeNum_Recursion(BiTree t){
    if(t == NULL){
        return 0;
    }
    //计算左、右子树节点数之和
    return TreeNodeNum_Recursion(t->lchild)+TreeNodeNum_Recursion(t->rchild)+1;
    
}
//2.树的深度
int TreeHeight_Recursion(BiTree t){
    if(t == NULL){
        return 0;
    }
    int treeHeight = 0;
    //计算左右子树的深度
    int lHeight = TreeHeight_Recursion(t->lchild);
    int rHeight = TreeHeight_Recursion(t->rchild);
    treeHeight += lHeight > rHeight ? lHeight : rHeight;
    return treeHeight+1;
}
//4.交换左右子树(注意：不能用中序次序交换)
void TransLRTree_Recursion(BiTree t){
    if(t == NULL){
        return;
    }
    BiTree temp;
    //先交换根的左右子树
    temp = t->lchild;
    t->lchild = t->rchild;
    t->rchild = temp;
    //再交换左右孩子的子树
    TransLRTree_Recursion(t->lchild);
    TransLRTree_Recursion(t->rchild);
}

/*
 非递归算法
 */

//1.节点个数（先序遍历）
int TreeNodeNum_Non_Recursion(BiTree t){
    if(t == NULL){
        return 0;
    }
    Stack *s = init_Stack();
    int nodeNum = 0;
    BNode *n = t;
    while(!(s->top==-1 && n==NULL)){
        while(n!=NULL){
            nodeNum++;
            push_Stack(n,s);
            //访问左孩子
            n = n->lchild;
        }
        //当n为空就出栈访问其右孩子
        n = pop_Stack(s);
        n = n->rchild;
    }
    return nodeNum;
}
//2.树的深度（后序遍历）
int TreeHeight_Non_Recursion(BiTree t){
    if(t == NULL){
        return 0;
    }
    int treeHeight = 0;
    Stack *s = init_Stack();
    BNode *n = t;
    while(!(s->top == -1 && n == NULL)){
        while (n != NULL) {
            push_Stack(n, s);
            n = n->lchild;
        }
        //当n为空判断栈顶元素被访问了几次若被访问过一次则将其flag赋为1并访问其右孩子，若被访问过两次则说明是从右孩子返回的则需取深度最大的那个值
        if(getTop(s)->flag == 1){
            treeHeight = treeHeight > s->length ? treeHeight : s->length;
            pop_Stack(s);
        }else{
            n = pop_Stack(s);
            //更改flag值
            n->flag = 1;
            n = n->rchild;
            
        }
    }
    return treeHeight;
   
}
//3.各节点层数（后序遍历）
void TreeNodeTier_Non_Recursion(BiTree t){
    if(t == NULL){
        return;
    }
    Stack *s = init_Stack();
    BiTree bt = t;
    int level = 0;
    while(!(s->top == -1 && bt!=NULL)){
        while(bt!=NULL){
            push_Stack(bt, s);
            level++;
            printf("Node:%d <----> Level:%d",bt->data,level);
            bt = bt->lchild;
        }
        //bt为空时出栈
        if(getTop(s)->flag == 1){
            
            printf("Node:%d <----> Level:%d",pop_Stack(s)->data,level);
            level--;
        }else{
            bt = getTop(s);
            //更改flag值
            bt->flag = 1;
            bt = bt->rchild;
        }
    }
}
//4.交换左右子树（先序遍历）
void TransLRTree_Non_Recursion(BiTree t){
    if(t == NULL){
        return;
    }
    BNode *n = t;
    Stack *s = init_Stack();
    while(!(s->top == -1 && n == NULL)){
        while(n != NULL){
            //交换左右子树
            BiTree temp = n->lchild;
            n->lchild = n->rchild;
            n->rchild = temp;
            push_Stack(n, s);
            n = n->lchild;
        }
        //当n为空出栈
        n = pop_Stack(s);
        n = n->rchild;
    }
    
}
int main(int argc, const char * argv[]) {
    
    return 0;
}
