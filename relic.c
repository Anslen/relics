#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "relics.h"
#define BUFF_SIZE 500000//��������С

relic* load_json(char*);
FILE* get_file(void);
relic alys_relic(cJSON*);

int main(int argc,char** argv)
{
    relic *relics;
    int index = 0;
    puts("��ӭʹ��RAA");
    if(argc > 1)
        relics = load_json(argv[1]);
    else
        relics = load_json(NULL);
    while(strcmp(relics[index].setname,"end") != 0)
    {
        relic_print(relics + index++);
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

relic alys_relic(cJSON *rlc)
{
    //����json�е�һ��ʥ����
    relic export;
    cJSON *ptr_entry = rlc -> child;//ָ��ʥ������һ����
    cJSON *ptr_tag;//ָ�򸱴���
    cJSON *ptr_inner;//ָ�򸱴�����
    //��װ��
    char setname[30];
    strcpy(setname,ptr_entry->valuestring);
    strcpy(export.setname,trans_setname(setname));
    //��λ��
    char position[10];
    ptr_entry = ptr_entry -> next;
    strcpy(position,ptr_entry->valuestring);
    strcpy(export.position,trans_posi(position));
    //������
    char tag[20];
    ptr_entry = ptr_entry -> next;
    ptr_tag = ptr_entry -> child;
    strcpy(tag,ptr_tag->valuestring);
    strcpy(export.main_tag.name,trans_tag(tag));
    ptr_tag = ptr_tag -> next;
    export.main_tag.value = ptr_tag -> valuedouble;
    //������
    ptr_entry = ptr_entry -> next;
    ptr_tag = ptr_entry -> child;
    int index = 0;
    while(ptr_tag != NULL)
    {
        char sub_tag[20];
        ptr_inner = ptr_tag -> child;
        strcpy(sub_tag,ptr_inner->valuestring);
        strcpy(export.normal_tags[index].name,trans_tag(sub_tag));
        ptr_inner = ptr_inner -> next;
        export.normal_tags[index].value = ptr_inner -> valuedouble;
        index++;
        ptr_tag = ptr_tag -> next;
    }
    if(index != 4) strcpy(export.normal_tags[index].name,"end");
    ptr_entry = ptr_entry -> next -> next;
    export.level = ptr_entry -> valueint;
    ptr_entry = ptr_entry -> next;
    export.star = ptr_entry -> valueint;
    return export;
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
            fclose(file);
            exit(1);
        }
    }
    fclose(file);

    //����json
    cJSON *json = cJSON_Parse(json_string);
    cJSON *ptr_posi = json -> child -> next;//ָ��һ����λ
    cJSON *ptr_rlc;//ָ��һ��ʥ����
    relic *relics = malloc(1501 * sizeof(relic));
    int index = 0;
    while(ptr_posi != NULL)
    {
        if(ptr_posi->child != NULL)
        {
            ptr_rlc = ptr_posi -> child;
            while(ptr_rlc != NULL)
            {
                relics[index++] = alys_relic(ptr_rlc);
                ptr_rlc = ptr_rlc -> next;
            }
        }
        ptr_posi = ptr_posi -> next;
    }
    strcpy(relics[index].setname,"end");
    cJSON_Delete(json);
    return relics;
}
