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
    int m = 0,countUntch = 0;
    //定义城市间使用图的邻接矩阵存储以及未联通城市的存储
    int **cities , **untch;
    scanf("%d",&m);
    //邻接矩阵存储
    untch = (int **)malloc(sizeof(int *) * m);
    //邻接矩阵存储
    cities = (int **)malloc(sizeof(int *) * m);
    for(int i = 0;i<m;i++){
        cities[i] = (int *)malloc(sizeof(int) * m);
        untch[i] = (int *)malloc(sizeof(int) * m);
    }
    for(int i = 0;i<m;i++){
        for(int j = 0;j<m;j++){
            cities[i][j] = 0;
            untch[i][j] = 0;
        }
    }
    
    for(int i = 0;i<m;i++){
        for(int j = 0;j<m;j++){
            printf("%d,%d\n",cities[i][j],untch[i][j]);
        }
    }
    //输入数据总数
    int arrCount = m * (m-1) * 2;
    int temp[4];
    for(int i = 0;i < arrCount;i+=4){
        for(int j = i;j < j+4;j++){
            scanf("%d ",&temp[j-i]);
        }
        int a = temp[0],b = temp[1];
        //将结果赋值给邻接矩阵
        cities[a][b] = cities[b][a] = temp[2];
        //记录未联通的点(若联通赋值为1)
        if(temp[3] != 0){
            untch[a][b] = untch[b][a] = 1;
        }
    }
    
    for(int i = 0;i<m;i++){
        for(int j = 0;j<m;j++){
            printf("city%d-city%d : cost = %d :isTouch = %d\n", i+1,j+1,cities[i][j],untch[i][j]);
        }
    }
    
    
    
    
    
    return 0;
}



