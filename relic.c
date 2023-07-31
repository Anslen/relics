#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "relics.h"
#define BUFF_SIZE 500000//��������С

relic* load_json(void);

int main()
{
    relic *relics;
    puts("��ӭʹ��ʥ�������ֹ���");
    relics = load_json();
}

relic* load_json(void)
{
    //����json�ļ�
    char name[50];
    FILE *file = NULL;
    puts("������json�ļ���ַ����YAS���ɣ����ص�ַ��鿴README�ļ���");
    while(file == NULL)
    {
        scanf("%s",name);
        file = fopen(name,"r");
        if(file == NULL)
        {
            puts("��ȡʧ�ܣ������������ַ");
        }
    }

    //��json��ȡ���ַ�����
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
            puts("���棬���������");
            exit(1);
        }
    }
    fclose(file);

    //����json
    cJSON *json = cJSON_Parse(json_string);
    cJSON *node = json -> child -> next;
    cJSON *json_ptr = node -> child;//1��ָ��
    cJSON *json_ptr1 = json_ptr -> child;//2��ָ��
    cJSON *json_ptr2 = NULL;//3��ָ��
    relic *relics = malloc(1500 * sizeof(relic));
    relic *relic_ptr;
    int index = 0;
    while(node != NULL)
    {
        while(json_ptr != NULL)
        {
            //������װ��
            strncpy(relic_ptr -> setname,json_ptr1 -> valuestring, 30);
            //����λ��
            json_ptr1 = json_ptr1 -> next;
            strncpy(relic_ptr -> position,json_ptr1 -> valuestring,10);
            //����������
            json_ptr1 = json_ptr1 -> next;
            json_ptr2 = json_ptr1 -> child;
            strncpy(relic_ptr -> main_tag.name, json_ptr2 -> valuestring, 20);
            json_ptr2 = json_ptr2 -> next;
            relic_ptr -> main_tag.value = json_ptr2 -> valueint;
            //���븱����
            json_ptr1 = json_ptr1 -> next;
            json_ptr2 = json_ptr1 -> child;
            while(json_ptr2 != NULL)
            {
                int count = 0;
                strncpy(relic_ptr -> normal_tags[count].name,json_ptr2 -> child -> valuestring,20);
                relic_ptr -> normal_tags[count++].value = json_ptr2 -> child -> next ->valuedouble;
                json_ptr2 = json_ptr2 -> next;
            }
            //����ȼ�
            json_ptr1 = json_ptr1 -> next -> next;
            relic_ptr -> level = json_ptr1 ->valueint;
            //�����Ǽ�
            json_ptr1 = json_ptr1 -> next;
            relic_ptr -> star = json_ptr1 -> valueint;
            relics[index++] = *relic_ptr;
            //��ȡ��һ��ʥ����
            json_ptr = json_ptr -> next;
        }
        //������һ��
        node = node -> next;
    }
    cJSON_Delete(json);
    return relics;
}
