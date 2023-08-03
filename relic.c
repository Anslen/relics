#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "relics.h"
#define BUFF_SIZE 500000//缓冲区大小

relic* load_json(char*);
FILE* get_file(void);

int main(int argc,char** argv)
{
    relic *relics;
    int index = 0;
    puts("欢迎使用圣遗物评分工具");
    if(argc > 1)
    {
        relics = load_json(argv[1]);
    }
    else
    {
        relics = load_json(NULL);
    }
    while(strcmp(relics[index].setname,"end") != 0)
    {
        trans_tag(relics[index].main_tag.name);
        int count = 0;
        while(strcmp(relics[index].normal_tags[count].name,"end") != 0)
        {
            trans_tag(relics[index].normal_tags[count].name);
        }
        trans_setname(relics[index].setname);
        index++;
    }
    free(relics);
    return 0;
}

FILE* get_file(void)
{
    //获取文件名并打开
    FILE *file = NULL;
    char name[50];
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
    return file;
}

relic* load_json(char *name)
{
    //载入json文件
    FILE *file = NULL;
    file = fopen(name,"r");
    if(file == NULL)
    {
        file = get_file();
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
    cJSON *node = json -> child -> next;//指向一个部位
    cJSON *json_ptr = node -> child;//指向一个圣遗物
    cJSON *json_ptr1 = json_ptr -> child;//指向一个词条
    cJSON *json_ptr2 = NULL;//指向主/副词条内
    relic *relics = malloc(1501 * sizeof(relic));
    int index = 0;
    while(node != NULL)
    {
        while(json_ptr != NULL)
        {
            relic now;//正在进行导入的圣遗物
            printf("%s\n",cJSON_Print(json_ptr));
            //导入套装名
            strncpy(now.setname,json_ptr1 -> valuestring, 30);
            putchar('1');
            //导入位置
            json_ptr1 = json_ptr1 -> next;
            strncpy(now.position,json_ptr1 -> valuestring,10);
            //导入主词条
            json_ptr1 = json_ptr1 -> next;
            json_ptr2 = json_ptr1 -> child;
            strncpy(now.main_tag.name, json_ptr2 -> valuestring, 20);
            json_ptr2 = json_ptr2 -> next;
            now.main_tag.value = json_ptr2 -> valueint;
            //导入副词条
            json_ptr1 = json_ptr1 -> next;
            json_ptr2 = json_ptr1 -> child;
            while(json_ptr2 != NULL)
            {
                int count = 0;
                strncpy(now.normal_tags[count].name,json_ptr2 -> child -> valuestring,20);
                now.normal_tags[count++].value = json_ptr2 -> child -> next ->valuedouble;
                json_ptr2 = json_ptr2 -> next;
            }
            //导入等级
            json_ptr1 = json_ptr1 -> next -> next;
            now.level = json_ptr1 ->valueint;
            //导入星级
            json_ptr1 = json_ptr1 -> next;
            now.star = json_ptr1 -> valueint;
            relics[index++] = now;
            //读取下一个圣遗物
            json_ptr = json_ptr -> next;
        }
        //导入下一项
        node = node -> next;
        json_ptr = node -> child;
        json_ptr1 = json_ptr -> child;
    }
    strcpy(relics[index].setname,"end");
    cJSON_Delete(json);
    putchar('1');
    return relics;
}
