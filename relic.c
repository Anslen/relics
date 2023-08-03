#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "relics.h"
#define BUFF_SIZE 500000//��������С

relic* load_json(char*);
FILE* get_file(void);

int main(int argc,char** argv)
{
    relic *relics;
    int index = 0;
    puts("��ӭʹ��ʥ�������ֹ���");
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
    //��ȡ�ļ�������
    FILE *file = NULL;
    char name[50];
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
    return file;
}

relic* load_json(char *name)
{
    //����json�ļ�
    FILE *file = NULL;
    file = fopen(name,"r");
    if(file == NULL)
    {
        file = get_file();
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
    cJSON *node = json -> child -> next;//ָ��һ����λ
    cJSON *json_ptr = node -> child;//ָ��һ��ʥ����
    cJSON *json_ptr1 = json_ptr -> child;//ָ��һ������
    cJSON *json_ptr2 = NULL;//ָ����/��������
    relic *relics = malloc(1501 * sizeof(relic));
    int index = 0;
    while(node != NULL)
    {
        while(json_ptr != NULL)
        {
            relic now;//���ڽ��е����ʥ����
            printf("%s\n",cJSON_Print(json_ptr));
            //������װ��
            strncpy(now.setname,json_ptr1 -> valuestring, 30);
            putchar('1');
            //����λ��
            json_ptr1 = json_ptr1 -> next;
            strncpy(now.position,json_ptr1 -> valuestring,10);
            //����������
            json_ptr1 = json_ptr1 -> next;
            json_ptr2 = json_ptr1 -> child;
            strncpy(now.main_tag.name, json_ptr2 -> valuestring, 20);
            json_ptr2 = json_ptr2 -> next;
            now.main_tag.value = json_ptr2 -> valueint;
            //���븱����
            json_ptr1 = json_ptr1 -> next;
            json_ptr2 = json_ptr1 -> child;
            while(json_ptr2 != NULL)
            {
                int count = 0;
                strncpy(now.normal_tags[count].name,json_ptr2 -> child -> valuestring,20);
                now.normal_tags[count++].value = json_ptr2 -> child -> next ->valuedouble;
                json_ptr2 = json_ptr2 -> next;
            }
            //����ȼ�
            json_ptr1 = json_ptr1 -> next -> next;
            now.level = json_ptr1 ->valueint;
            //�����Ǽ�
            json_ptr1 = json_ptr1 -> next;
            now.star = json_ptr1 -> valueint;
            relics[index++] = now;
            //��ȡ��һ��ʥ����
            json_ptr = json_ptr -> next;
        }
        //������һ��
        node = node -> next;
        json_ptr = node -> child;
        json_ptr1 = json_ptr -> child;
    }
    strcpy(relics[index].setname,"end");
    cJSON_Delete(json);
    putchar('1');
    return relics;
}
