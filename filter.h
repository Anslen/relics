#ifndef FILTER_INCLUDED
#define FILTER_INCLUDED 1
#include "relics.h"
#include <string.h>
#define FILTER_NUM 1//筛选器的数量

typedef double(*func)(relic*);
double score_critical(relic*);

func filters[FILTER_NUM] = {score_critical};
double min_score[FILTER_NUM] = {0};//筛选最低得分
char filter_name[FILTER_NUM][20] = {"双暴"};

double score_critical(relic* input)
{
    //双爆分
    int index = 0;
    double score = 0;
    while(index < 4)
    {
        if(strcmp(input -> normal_tags[index].name,"end") == 0)
        {
            break;
        }
        if(strcmp(input -> normal_tags[index].name,"暴击率") == 0)
        {
            score += (input->normal_tags[index].value) * 2;
        }
        if(strcmp(input -> normal_tags[index].name,"暴击伤害") == 0)
        {
            score += input->normal_tags[index].value;
        }
        index++;
    }
    return score;
}

#endif
