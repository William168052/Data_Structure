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
//    int countTimes;
    //含有此话题的微博条数
    int blogPiece;
    struct topic *next;
    //定义一个标记记录此话题位于第几条记录
    int address;
    
    
}Topic;

Topic *initTopics(){
    Topic *t = (Topic *)malloc(sizeof(Topic));
    //计算话题被重复的次数
    t->blogPiece = 0;
//    t->countTimes = 0;
    t->topic = NULL;
    t->next = NULL;
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
        if(((c[i]>='A' && c[i]<='Z') || (c[i]>='a' && c[i]<='z')) || (c[i]>= '0' && c[i]<= '9') || c[i] == ' '){
            cNew[cIndex++] = c[i];
        }
    }
    return cNew;
}

_Bool isEqual(char *c1,char *c2){
    int equal = 1;
    for(int i = 0,j = 0;c1[i] != '\0'&&c2[j] != '\0';){
        if(c1[i] == c2[j]||
           c1[i] + 32 == c2[j]||
           c1[i] - 32 == c2[j]){
            i++;
            j++;
        }else if(c1[i] == ' '){   //遇到空格就跳过
            i++;
        }else if(c2[j] == ' '){
            j++;
        }else{
            equal = 0;
            break;
        }
    }
    return equal;
}

void topTopic(char **strArr,int strNum){
    //定义存储所有话题的链表
    Topic *topics = initTopics();
    //计算热门话题数
    int topicsNum = 0;
    
    for(int i = 0;i<strNum;i++){
//        printf("````%s`````\n",strArr[i]);
        
        //判断是否开始记录话题
        int isBegin = 0;
        //定义存储当前话题的字符串
        char *topicStr = (char *)malloc(sizeof(char) * TOPIC_MAX);
        //计算话题数组长度
        int topicLength = 0;
        for(int j = 0;strArr[i][j] != '\0';j++){
            if(strArr[i][j] == '#' && isBegin == 0){
                isBegin = 1;
                continue;
            }else if(strArr[i][j] == '#' && isBegin == 1){
                //一个话题结束
                topicStr[topicLength] = '\0';
                topicStr = formatString(topicStr);
                //在话题数组中寻找是否有此话题，若没有就放进去
                if(topics->topic == NULL){
//                    printf("....%s....",topicStr);
                    topics->topic = topicStr;
                    topics->address = i;
                    topics->blogPiece++;
//                    topics->countTimes++;
//                    topicsNum++;
                }else{
                    _Bool isFind = 0;
                    Topic *p = topics;
                    while(p!=NULL){
                        //字符串匹配
//                        printf("%s %s",p->topic,topicStr);
                        if(isEqual(p->topic, topicStr)){
                            if(p->address != i){
                                p->blogPiece++;
                                p->address = i;
                            }
                            isFind = 1;
//                            p->countTimes++;
                            break;
                        }
                        p = p->next;
                    }
                    if (isFind == 0) {
//                        topics[topicsNum].topic = topicStr;
//                        topics[topicsNum].countTimes++;
//                        topicsNum++;
                        //插入链表
                        Topic *t = initTopics();
//                        t->countTimes++;
                        t->topic = topicStr;
                        t->next = topics->next;
                        t->blogPiece++;
                        t->address = i;
                        topics->next = t;
                        
                        
                    }
                }
//                printf("%s\n",topic);
                
                topicLength = 0;
                isBegin = 0;
                continue;
            }
            if(isBegin == 1){
                topicStr[topicLength++] = strArr[i][j];
            }
        }
        
    }
//    int max = MAX_N;
//    for(int k = 0;k<topicsNum;k++){
//        printf("%s----%d",topics[k].topic,topics[k].countTimes);
//    }
    
    Topic *p = topics;
    int max = 0;
    char front_letter = '\0';
    Topic *PrintTopic = NULL;
    while(p!=NULL){
//        printf("%s-----%d\n",p->topic,topicsNum);
        if(p->blogPiece > max){
            front_letter = p->topic[0];
            max = p->blogPiece;
            PrintTopic = p;
//            if(p->next == NULL){
//                printf("%s\n%d\n",p->topic,p->blogPiece);
//                topicsNum--;
//                break;
//            }
        }else if(p->blogPiece == max){
            if(p->topic[0]<front_letter){
                front_letter = p->topic[0];
                PrintTopic = p;
//                if(p->next == NULL){
//                    printf("%s\n%d\n",p->topic,p->blogPiece);
//                    topicsNum--;
//                    break;
//                }
                topicsNum++;
            }

        }
        p = p->next;
    }
    if(PrintTopic!=NULL){
        printf("%s\n%d\n",PrintTopic->topic,PrintTopic->blogPiece);
//        topicsNum--;
    }
    if(topicsNum>0){
        printf("And %d more ...",topicsNum);
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
