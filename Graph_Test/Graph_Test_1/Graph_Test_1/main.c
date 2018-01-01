//
//  main.c
//  Graph_Test_1
//
//  Created by William on 2018/1/1.
//  Copyright © 2018年 William. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define DataType int
#define MAX 10000
//定义邻接点的数据类型
typedef struct node{
    int adjvex;
    struct node *next;
}EdgeNode;
//定义顶点的数据类型
typedef struct vnode{
    DataType data;
    EdgeNode *firstEdge;
    
}VertexNode;
//图的存储类型
typedef struct graph{
    VertexNode *graph;
    int nodeNum;
}*Graph;
//构造逆邻接表
Graph getInverse(Graph G){
    Graph InvG = NULL;
    InvG->graph = (VertexNode *)malloc(sizeof(VertexNode) * G->nodeNum);
    InvG->nodeNum = G->nodeNum;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
