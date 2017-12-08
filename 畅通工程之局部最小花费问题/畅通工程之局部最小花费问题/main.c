//
//  main.c
//  畅通工程之局部最小花费问题
//
//  Created by William on 2017/12/8.
//  Copyright © 2017年 William. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
//定义Prim算法求解最小生成树
void Prim(int gm[MAX][MAX],int tree[MAX],int cost[MAX],int gmSize){
    int *flag = (int *)malloc(sizeof(int) * gmSize);
    int mincost,k = 0;
    for(int i = 0;i<gmSize;i++){
        cost[i] = gm[0][i];
        tree[i] = 0;
        flag[i] = 0;
    }
    flag[0] = 1;
    
    for(int i = 1;i<gmSize;i++){
        mincost = 100000;          //将mincost赋值一个很大的值
        for(int j = 1;j<gmSize;j++){
            if(flag[j] == 0 && cost[j] < mincost){
                mincost = cost[j];
                k = j;
            }
        }
        flag[k] = 1;
        
        for(int j = 1;j<gmSize;j++){
            if(flag[j] == 0 && gm[k][j] < cost[j]){
                cost[j] = gm[k][j];
                tree[j] = k;
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    int m,n;
    scanf("%d %d",&m,&n);
    //定义图的邻接矩阵存储
    int **cities = (int **)malloc(sizeof(int *) * n);
    for(int i = 0;i<n;i++){
        cities[i] = (int *)malloc(sizeof(int) * m);
    }
    
    
    
    
    
    return 0;
}



