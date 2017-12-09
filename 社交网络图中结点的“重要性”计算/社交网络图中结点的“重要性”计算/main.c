//
//  main.c
//  社交网络图中结点的“重要性”计算
//
//  Created by William on 2017/12/9.
//  Copyright © 2017年 William. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int eleNum,borderNum,calculateNum;   //定义节点个数和边的个数
    scanf("%d %d",&eleNum,&borderNum);
    //定义图的邻接矩阵存储方式并初始化为零
    int **node = (int **)malloc(sizeof(int *) * eleNum);
    for(int i = 0;i<eleNum;i++){
        int *n = (int *)malloc(sizeof(int) * eleNum);
        for (int j = 0; j<eleNum; j++) {
            n[j] = 0;
        }
        node[i] = n;
    }
    
    for(int i = 0;i<borderNum;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        node[a-1][b-1] = 1;
    }
    
    for(int i = 0;i<eleNum;i++){
        for(int j = 0;j<eleNum;j++){
            if(node[i][j] == 1)
            printf("%d--%d\n",i+1,j+1);
        }

    }
    scanf("%d",&calculateNum);
    int *calculateNode = (int *)malloc(sizeof(int) * calculateNum);
    for(int i = 0;i<calculateNum;i++){
        scanf("%d",&calculateNode[i]);
    }
    
    for(int i = 0;i<calculateNum;i++){
        printf("%d ",calculateNode[i]);
    }
}


