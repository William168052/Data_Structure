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
    int nodeNum = 0;
    if(t!=NULL){
        //计算左、右子树节点数
        nodeNum += TreeNodeNum_Recursion(t->lchild);
        nodeNum += TreeNodeNum_Recursion(t->rchild);
        return nodeNum+1;
    }else{
        return 0;
    }
    
}
//2.树的深度
int TreeHeight_Recursion(BiTree t){
    int treeHeight = 0;
    if(t != NULL){
        treeHeight++;
        //计算左右子树的深度
        int lHeight = TreeHeight_Recursion(t->lchild);
        int rHeight = TreeHeight_Recursion(t->rchild);
        treeHeight += lHeight > rHeight ? lHeight : rHeight;
        return treeHeight;
    }else{
        return 0;
    }
    return 0;
}
//3.各节点层数
int TreeNodeTier_Recursion(BiTree t){
    
    return 0;
}
//4.交换左右子树(注意：不能用中序次序交换)
void TransLRTree_Recursion(BiTree t){
    if(t != NULL){
        BiTree temp;
        //先交换根的左右子树
        temp = t->lchild;
        t->lchild = t->rchild;
        t->rchild = temp;
        //再交换左右孩子的子树
        TransLRTree_Recursion(t->lchild);
        TransLRTree_Recursion(t->rchild);
    }else{
        return;
    }
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
