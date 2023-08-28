#ifndef FILTER_INCLUDED
#define FILTER_INCLUDED 1
#include "relics.h"
#include <string.h>
#define FILTER_NUM 1//ɸѡ��������

typedef double(*func)(relic*);
double score_critical(relic*);

func filters[FILTER_NUM] = {score_critical};
double min_score[FILTER_NUM] = {0};//ɸѡ��͵÷�
char filter_name[FILTER_NUM][20] = {"˫��"};

double score_critical(relic* input)
{
    //˫����
    int index = 0;
    double score = 0;
    while(index < 4)
    {
        if(strcmp(input -> normal_tags[index].name,"end") == 0)
        {
            break;
        }
        if(strcmp(input -> normal_tags[index].name,"������") == 0)
        {
            score += (input->normal_tags[index].value) * 2;
        }
        if(strcmp(input -> normal_tags[index].name,"�����˺�") == 0)
        {
            score += input->normal_tags[index].value;
        }
        index++;
    }
    return score;
}

#endif
