//
//  main.c
//  社交网络图中结点的“重要性”计算
//
//  Created by William on 2017/12/9.
//  Copyright © 2017年 William. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
typedef struct graph{
    int *vexs;
    int **edges;
}MGragh;

//运用Dijkstra算法求最短路径
void ShortPath_Dijkstra(MGragh *G,int vexIndex){
    
}

int main(int argc, const char * argv[]) {
    int eleNum,borderNum,calculateNum;   //定义节点个数和边的个数
    scanf("%d %d",&eleNum,&borderNum);
    MGragh *G = (MGragh *)malloc(sizeof(MGragh));
    G->vexs = (int *)malloc(sizeof(int) * eleNum);
    G->edges = (int **)malloc(sizeof(int *) * eleNum);
    //定义图的邻接矩阵存储方式并初始化为零
//    int **mGragh = (int **)malloc(sizeof(int *) * eleNum);
    for(int i = 0;i<eleNum;i++){
        G->vexs[i] = i+i;
        int *n = (int *)malloc(sizeof(int) * eleNum);
        for (int j = 0; j<eleNum; j++) {
            n[j] = 0;
        }
        G->edges[i] = n;
    }
    
    for(int i = 0;i<borderNum;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        G->edges[a-1][b-1] = 1;
    }
    
//    for(int i = 0;i<eleNum;i++){
//        for(int j = 0;j<eleNum;j++){
//            if(G->edges[i][j] == 1)
//            printf("%d--%d\n",i+1,j+1);
//        }
//
//    }
    scanf("%d",&calculateNum);
    int *calculateNode = (int *)malloc(sizeof(int) * calculateNum);
    for(int i = 0;i<calculateNum;i++){
        scanf("%d",&calculateNode[i]);
    }
    
//    for(int i = 0;i<calculateNum;i++){
//        printf("%d ",calculateNode[i]);
//    }
}


