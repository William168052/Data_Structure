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
    char *topic;
    //被提到次数
    int countTimes;
    //含有此话题的微博条数
    int blogPiece;
    
    
}Topic;

Topic *initTopics(){
    Topic *t = (Topic *)malloc(sizeof(Topic) * MAX_N);
    //计算话题被重复的次数
    for(int i = 0;i<MAX_N;i++){
        t[i].countTimes = 0;
        t[i].blogPiece = 0;
    }
    return t;
}

char *formatString(char *c){
    char *cNew = (char *)malloc(sizeof(char) * TOPIC_MAX);
    int cIndex = 0;
    for(int i = 0;c[i] != '\0';i++){
        if(i == 0 && (c[i]>='a' && c[i]<='z')){
            cNew[cIndex++] = c[i]-32;
            continue;
        }else if(i != 0 && (c[i]>='A' && c[i]<='Z')){
            cNew[cIndex++] = c[i]+32;
            continue;
        }
        if(((c[i]>='A' && c[i]<='Z') || (c[i]>='a' && c[i]<='z')) || (c[i]>= '0' && c[i]<= '9')){
            cNew[cIndex++] = c[i];
        }
    }
    return cNew;
}

_Bool isEqual(char *c1,char *c2){
    int equal = 1;
    for(int i = 0;c1[i] != '\0';){
        if(c1[i] == c2[i]||
           c1[i] + 32 == c2[i]||
           c1[i] - 32 == c2[i]){
            i++;
        }else{
            equal = 0;
            break;
        }
    }
    return equal;
}

void topTopic(char **strArr,int strNum){
    //定义存储话题的数组
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
                topic = formatString(topic);
                //在话题数组中寻找是否有此话题，有的话直接加一，若没有就放进去
                if(topicsNum == 0){
//                    printf("....%s....",topic);
                    topics[topicsNum].topic = topic;
                    topics[topicsNum].countTimes++;
                    topicsNum++;
                }else{
                    _Bool isFind = 0;
                    for(int index = 0;index<topicsNum;index++){
                        //字符串匹配
                        if(isEqual(topics[index].topic, topic)){
                            isFind = 1;
                            topics[index].countTimes++;
                            break;
                        }
                    }
                    if (isFind == 0) {
                        topics[topicsNum].topic = topic;
                        topics[topicsNum].countTimes++;
                        topicsNum++;
                    }
                }
//                printf("%s\n",topic);
                
                topicLength = 0;
                isBegin = 0;
                continue;
            }
            if(isBegin == 1){
                topic[topicLength++] = strArr[i][j];
//                printf("-----%c-----\n",strArr[i][j]);
            }
        }
//        topic[topicLength] = '\0';
        
    }
//    int max = MAX_N;
    for(int k = 0;k<topicsNum;k++){
        printf("%s----%d",topics[k].topic,topics[k].countTimes);
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
    }


    topTopic(strArr, num);

    return 0;
}
