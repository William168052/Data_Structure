//
//  main.c
//  新浪微博热门话题
//
//  Created by William on 2017/12/22.
//  Copyright © 2017年 William. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX 140
#define TOPIC_MAX 40
#define MAX_N 1e+5

typedef struct topic{
    char **topic;
    int countTimes;
    
    
}Topic;

Topic *initTopics(){
    Topic *t = (Topic *)malloc(sizeof(Topic *) * MAX_N);
    
    //计算话题被重复的次数
    t->countTimes = 0;
    for(int i = 0;i<MAX_N;i++){
        
    }
    return t;
}

void topTopic(char **strArr,int strNum){
    Topic *topics = initTopics();
    //计算话题数
    int topicsNum = 0;
    for(int i = 0;i<strNum;i++){
//        printf("````%s`````\n",strArr[i]);
        //判断是否开始记录话题
        int isBegin = 0;
        //定义存储当前话题
        char *topic = (char *)malloc(sizeof(char) * TOPIC_MAX);
        //计算话题数组长度
        int topicLength = 0;
        for(int j = 0;strArr[i][j] != '\0';j++){
            if(strArr[i][j] == '#' && isBegin == 0){
                isBegin = 1;
                continue;
            }else if(strArr[i][j] == '#' && isBegin == 1){
                //一个话题结束
                topic[topicLength] = '\0';
                //在话题数组中寻找是否有此话题，有的话直接加一，若没有就放进去
                if(topicsNum == 0){
                    topics->topic[topicsNum++] = topic;
                    
                }else{
                    for(int index = 0;index<topicsNum;index++){
                        //字符串匹配
                    }
                }
                
                topicLength = 0;
                isBegin = 0;
                continue;
            }
            if(isBegin == 1){
                topic[topicLength++] = strArr[i][j];
//                printf("-----%c-----\n",strArr[i][j]);
            }
        }
        topic[topicLength] = '\0';
//        printf("%s\n",topic);
    }
}

int main(int argc, const char * argv[]) {
    int num;
    scanf("%d",&num);
    getchar();
    //存储字符串的数组
    char **strArr = (char **)malloc(sizeof(char *) * num);
    for(int i = 0;i<num;i++){
        strArr[i] = (char *)malloc(sizeof(char) * MAX);
    }
    //读取字符串
    for(int i = 0;i<num;i++){
        char *str = (char *)malloc(sizeof(char) * MAX);
        char c = '\0';
        int j = 0;
        while(1){
            scanf("%c",&c);
            if(c == '\n')
                break;
            str[j++] = c;
        }
        str[j] = '\0';
        strArr[i] = str;
//        printf("%s\n",strArr[i]);
    }
//    strArr[0] = "123123";
//    strArr[1] = "asdsad";
//    strArr[2] = "awww";
//    strArr[3] = "asdfgdfgsad";
    
    topTopic(strArr, num);
//    for(int i = 0;i<num;i++){
//        printf("%s\n",strArr[i]);
//    }
    return 0;
}
