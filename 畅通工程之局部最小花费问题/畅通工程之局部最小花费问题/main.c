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
#define MAX_VALUE 1e+8
//定义Prim算法求解最小生成树
int Prim(int **cities,int **touchState,int size){
    int sumMincost = 0;
    int *cost = (int *)malloc(sizeof(int) * size);
    int *flag = (int *)malloc(sizeof(int) * size);
    int mincost,k = 0;
    //将第一个作为开始节点
    for(int i = 0;i<size;i++){
        int isTouch = 1;
        static int firstEle = 0;
        //记录初始联通的节点个数
        int touchCount = 0;
        //判断初始是否有联通的节点
        for(int j = 0;j<size;j++){
            if(touchState[i][j] == 1){
                isTouch = 1;
                break;
            }else{
                isTouch = 0;
            }
        }
        //拿到已经联通的元素中的第一个元素
        if(isTouch == 1){
            touchCount++;
            if(touchCount == 1){
                firstEle = i;
            }
        }
        flag[i] = isTouch;
        printf("flag[%d] = %d\n",i,flag[i]);
        cost[i] = cities[firstEle][i];
    }
    for(int i = 1;i<size;i++){
        mincost = MAX_VALUE;          //将mincost赋值一个很大的值
        for(int j = 1;j<size;j++){
            if(flag[j] == 0 && cost[j] < mincost){
                mincost = cost[j];
                k = j;
            }
        }
        //找出最小花费的路线
        flag[k] = 1;
        for(int j = 1;j<size;j++){
            if(flag[j] == 0 && cities[k][j] < cost[j]){
                cost[j] = cities[k][j];
//                tree[j] = k;
            }
        }
    }
    for(int i = 0;i<size;i++){
        sumMincost += cost[i];
    }
    return sumMincost;
}
int main(int argc, const char * argv[]) {
    int m = 0;
    //定义城市间使用图的邻接矩阵存储以及未联通城市的存储
    int **cities , **touchState;
    scanf("%d",&m);
    //邻接矩阵存储
    touchState = (int **)malloc(sizeof(int *) * m);
    //邻接矩阵存储
    cities = (int **)malloc(sizeof(int *) * m);
    for(int i = 0;i<m;i++){
        cities[i] = (int *)malloc(sizeof(int) * m);
        touchState[i] = (int *)malloc(sizeof(int) * m);
    }
    for(int i = 0;i<m;i++){
        for(int j = 0;j<m;j++){
            cities[i][j] = 0;
            touchState[i][j] = 0;
        }
    }
    
//    for(int i = 0;i<m;i++){
//        for(int j = 0;j<m;j++){
//            printf("%d,%d\n",cities[i][j],touchState[i][j]);
//        }
//    }
    //输入数据总数
    int arrCount = m * (m-1) * 2;
    int temp[4];
    for(int i = 0;i < arrCount;i+=4){
        for(int j = i;j < i+4;j++){
            scanf("%d",&temp[j-i]);
//            printf("%d ",temp[j-i]);
        }
//        printf("\n");
        int a = temp[0]-1,b = temp[1]-1;
        //将结果赋值给邻接矩阵
        cities[a][b] = cities[b][a] = temp[2];
        //记录未联通的点(若联通赋值为1)
        if(temp[3] != 0){
            touchState[a][b] = touchState[b][a] = 1;
        }
    }
    
//    for(int i = 0;i<m;i++){
//        for(int j = 0;j<m;j++){
//            printf("city%d-city%d : cost = %d :isTouch = %d\n", i+1,j+1,cities[i][j],touchState[i][j]);
//        }
//    }
    
    printf("%d",Prim(cities, touchState, m));

    
/*
4
1 2 1 0
1 3 4 0
1 4 1 0
2 3 3 0
2 4 2 0
3 4 5 0
 */
    
    return 0;
}



