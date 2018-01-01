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
    //创建一个空的逆邻接表并初始化
    Graph InvG = (Graph)malloc(sizeof(Graph));
    InvG->graph = (VertexNode *)malloc(sizeof(VertexNode) * G->nodeNum);
    InvG->nodeNum = G->nodeNum;
    for(int i = 0;i<G->nodeNum;i++){
        InvG->graph[i].data = G->graph[i].data;
        InvG->graph[i].firstEdge = NULL;
    }
    //遍历邻接表
    for(int i = 0;i<G->nodeNum;i++){
        if(G->graph[i].firstEdge != NULL){
            //创建一个指针指向第一个邻接节点
            EdgeNode *n = G->graph[i].firstEdge;
            //创建一个新的邻接节点
            EdgeNode *edge = (EdgeNode *)malloc(sizeof(EdgeNode));
            edge->adjvex = i;
            edge->next = NULL;
            while (n!=NULL) {
                if(InvG->graph[n->adjvex].firstEdge == NULL){
                    InvG->graph[n->adjvex].firstEdge = edge;
                }else{
                    EdgeNode *temp = InvG->graph[n->adjvex].firstEdge;
                    InvG->graph[n->adjvex].firstEdge = edge;
                    temp = edge->next;
                }
                n = n->next;
            }
        }
        
    }
    return InvG;
}


int main(int argc, const char * argv[]) {
    
    return 0;
}
