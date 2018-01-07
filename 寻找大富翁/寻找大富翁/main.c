//
//  main.c
//  寻找大富翁
//
//  Created by William on 07/01/2018.
//  Copyright © 2018 William. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char * argv[]) {
    int N,M;
    scanf("%d %d",&N,&M);
    if(N < M){
        M = N;
    }
    int *arr = (int *)malloc(sizeof(int) * N);
    for(int i = 0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    //选择排序
    for(int i = 0;i<M;i++){
        int max = 0;
        int maxIndex = 0;
        for(int j = i;j<N;j++){
            if(arr[j] > max){
                max = arr[j];
                maxIndex = j;
            }
        }
        
//        printf("%d",max);
        //一趟找出最大的将其放到最前面
        for(int j = maxIndex - 1;j>=i;j--){
            arr[j + 1] = arr[j];
        }
        arr[i] = max;
    }
    
    for(int i = 0;i<M;i++){
        if(i < M-1){
            printf("%d ",arr[i]);
        }else{
            printf("%d",arr[i]);
        }
    }
    return 0;
}
