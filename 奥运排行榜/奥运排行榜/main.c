//
//  main.c
//  奥运排行榜
//
//  Created by William on 04/01/2018.
//  Copyright © 2018 William. All rights reserved.
//

#include <stdio.h>
#define MAX 1000
int levelByGold(int index,int gold[],int length){
    int max = gold[index];
    int level = 1;
    for(int i = 0;i<length;i++){
        if(gold[i]>max){
            level++;
        }
    }
    return level;
}
int levelBymedal(int index,int medal[],int length){
    int max = medal[index];
    int level = 1;
    for(int i = 0;i<length;i++){
        if(medal[i]>max){
            level++;
        }
    }
    return level;
}
int levelBymGold(int index,int population[],int gold[],int length){
    double max = (double)gold[index]/population[index];
    int level = 1;
    for(int i = 0;i<length;i++){
        if((double)gold[i]/population[i]> max){
            level++;
        }
    }
    return level;
}
int levelBymMedal(int index,int population[],int medal[],int length){
    double max = (double)medal[index]/population[index];
    int level = 1;
    for(int i = 0;i<length;i++){
        if((double)medal[i]/population[i] > max){
            level++;
        }
    }
    return level;
}

int getMin(int gold,int goldFlag,int medal,int medalFlag,int mGold,int mGoldFlag,int mMedal,int mMedalFlag){
    int min;
    int minFlag;
    if(gold < medal){
        min = gold;
        minFlag = goldFlag;
    }else{
        if(gold == medal){
            minFlag = goldFlag;
            min = gold;
        }else{
            min = medal;
            minFlag = medalFlag;
        }
        
    }
    if(min > mGold){
        min = mGold;
        minFlag = mGoldFlag;
    }else{
        if(minFlag > mGoldFlag && min == mGold){
            min = mGold;
            minFlag = mGoldFlag;
        }
    }
    if(min > mMedal){
        min = mMedal;
        minFlag = mMedalFlag;
    }else{
        if(minFlag > mMedalFlag && min == mMedal){
            min = mMedal;
            minFlag = mMedalFlag;
        }
    }
    return minFlag;
    
}
int main(int argc, const char * argv[]) {
    int N,M;
    int gold[MAX],medal[MAX],population[MAX];
    int contry;
    scanf("%d %d",&N,&M);
        for(int i = 0;i<N;i++){
            scanf("%d %d %d",&gold[i],&medal[i],&population[i]);
        }
    for(int i = 0;i<M-1;i++){
        scanf("%d",&contry);
        switch (getMin(levelByGold(contry, gold, N), 1, levelBymedal(contry, medal, N), 2, levelBymGold(contry, population,gold, N), 3, levelBymMedal(contry,population,medal,N), 4)) {
            case 1:
                printf("%d:%d ",levelByGold(contry, gold, N),1);
                break;
            case 2:
                printf("%d:%d ",levelBymedal(contry, medal, N),2);
                break;
            case 3:
                printf("%d:%d ",levelBymGold(contry, population,gold, N),3);
                break;
                
            case 4:
                printf("%d:%d ",levelBymMedal(contry, population,medal, N),4);
                break;
                
            default:
                break;
        }
    }
    scanf("%d",&contry);
    switch (getMin(levelByGold(contry, gold, N), 1, levelBymedal(contry, medal, N), 2, levelBymGold(contry, population,gold, N), 3, levelBymMedal(contry,population,medal,N), 4)) {
        case 1:
            printf("%d:%d",levelByGold(contry, gold, N),1);
            break;
        case 2:
            printf("%d:%d",levelBymedal(contry, medal, N),2);
            break;
        case 3:
            printf("%d:%d",levelBymGold(contry, population,gold, N),3);
            break;
            
        case 4:
            printf("%d:%d",levelBymMedal(contry, population,medal, N),4);
            break;
            
        default:
            break;
    }
    
    
    
    
    return 0;
}
