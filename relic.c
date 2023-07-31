#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "relics.h"
#define BUFF_SIZE 500000//缓冲区大小

relic* load_json(void);

int main()
{
    relic *relics;
    puts("欢迎使用圣遗物评分工具");
    relics = load_json();
}

relic* load_json(void)
{
    //载入json文件
    char name[50];
    FILE *file = NULL;
    puts("请输入json文件地址（由YAS生成，下载地址请查看README文件）");
    while(file == NULL)
    {
        scanf("%s",name);
        file = fopen(name,"r");
        if(file == NULL)
        {
            puts("读取失败，请重新输入地址");
        }
    }

    //将json读取到字符串中
    char json_string[BUFF_SIZE];
    char ch = 0;
    char *ptr = json_string;
    while(ch != EOF)
    {
        ch = getc(file);
        if(ch == EOF)
        {
            *ptr = '\0';
        }
        else
        {
            *ptr = ch;
            ptr++;
        }
        if((ptr - json_string) == BUFF_SIZE)
        {
            puts("警告，缓存区溢出");
            exit(1);
        }
    }
    fclose(file);

    //解析json
    cJSON *json = cJSON_Parse(json_string);
    cJSON *node = json -> child -> next;
    cJSON *json_ptr = node -> child;//1级指针
    cJSON *json_ptr1 = json_ptr -> child;//2级指针
    cJSON *json_ptr2 = NULL;//3级指针
    relic *relics = malloc(1500 * sizeof(relic));
    relic *relic_ptr;
    int index = 0;
    while(node != NULL)
    {
        while(json_ptr != NULL)
        {
            //导入套装名
            strncpy(relic_ptr -> setname,json_ptr1 -> valuestring, 30);
            //导入位置
            json_ptr1 = json_ptr1 -> next;
            strncpy(relic_ptr -> position,json_ptr1 -> valuestring,10);
            //导入主词条
            json_ptr1 = json_ptr1 -> next;
            json_ptr2 = json_ptr1 -> child;
            strncpy(relic_ptr -> main_tag.name, json_ptr2 -> valuestring, 20);
            json_ptr2 = json_ptr2 -> next;
            relic_ptr -> main_tag.value = json_ptr2 -> valueint;
            //导入副词条
            json_ptr1 = json_ptr1 -> next;
            json_ptr2 = json_ptr1 -> child;
            while(json_ptr2 != NULL)
            {
                int count = 0;
                strncpy(relic_ptr -> normal_tags[count].name,json_ptr2 -> child -> valuestring,20);
                relic_ptr -> normal_tags[count++].value = json_ptr2 -> child -> next ->valuedouble;
                json_ptr2 = json_ptr2 -> next;
            }
            //导入等级
            json_ptr1 = json_ptr1 -> next -> next;
            relic_ptr -> level = json_ptr1 ->valueint;
            //导入星级
            json_ptr1 = json_ptr1 -> next;
            relic_ptr -> star = json_ptr1 -> valueint;
            relics[index++] = *relic_ptr;
            //读取下一个圣遗物
            json_ptr = json_ptr -> next;
        }
        //导入下一项
        node = node -> next;
    }
    cJSON_Delete(json);
    return relics;
}
