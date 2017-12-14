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

//定义二叉树节点结构
typedef struct node{
    DataType data;
    struct node *lchild;
    struct node *rchild;
}BNode,*BiTree;

/*
 递归算法
 */

//1.节点个数
int TreeNodeNum_Recursion(BiTree t){
    return 0;
}
//2.树的深度
int TreeHeight_Recursion(BiTree t){
    return 0;
}
//3.各节点层数
int TreeNodeTier_Recursion(BiTree t){
    return 0;
}
//4.交换左右子树
int TransLRTree_Recursion(BiTree t){
    return 0;
}

/*
 非递归算法
 */

//1.节点个数
int TreeNodeNum_Non_Recursion(BiTree t){
    return 0;
}
//2.树的深度
int TreeHeight_Non_Recursion(BiTree t){
    return 0;
}
//3.各节点层数
int TreeNodeTier_Non_Recursion(BiTree t){
    return 0;
}
//4.交换左右子树
int TransLRTree_Non_Recursion(BiTree t){
    return 0;
}
int main(int argc, const char * argv[]) {
    
    return 0;
}
