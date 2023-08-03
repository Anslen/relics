#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tag
{
    char name[20];
    double value;
} tag;

typedef struct relic
{
    char setname[30];
    char position[10];
    tag main_tag;
    tag normal_tags[4];
    int level;
    int star;
    float weight;
} relic;

char* trans_posi(const char* string)
{
    if(strcmp(string,"flower") == 0)
    {
        return "��֮��";
    }else if(strcmp(string,"feather") == 0)
    {
        return "��֮��";
    }else if(strcmp(string,"sand") == 0)
    {
        return "ʱ֮ɳ";
    }else if(strcmp(string,"cup") == 0)
    {
        return "��֮��";
    }else if(strcmp(string,"head") == 0)
    {
        return "��֮��";
    }else
    {
        printf("��λ������ʧ��:%s\n",string);
    }
}

char* trans_setname(const char* string)
{
    if(strcmp(string,"VourukashasGlow") == 0)
    {
        return "������¶";
    }else if(strcmp(string,"NymphsDream") == 0)
    {
        return "ˮ��֮��";
    }else if(strcmp(string,"FlowerOfParadiseLost") == 0)
    {
        return "��԰֮��";
    }else if(strcmp(string,"DesertPavilionChronicle") == 0)
    {
        return "ɳ��¥��";
    }else if(strcmp(string,"GildedDreams") == 0)
    {
        return "�ν�֮��";
    }else if(strcmp(string,"DeepwoodMemories") == 0)
    {
        return "���ּ���";
    }else if(strcmp(string,"EchoesOfAnOffering") == 0)
    {
        return "�������";
    }else if(strcmp(string,"VermillionHereafter") == 0)
    {
        return "��ɰ����";
    }else if(strcmp(string,"oceanHuedClam") == 0)
    {
        return "��Ⱦ���";
    }else if(strcmp(string,"huskOfOpulentDreams") == 0)
    {
        return "��������";
    }else if(strcmp(string,"emblemOfSeveredFate") == 0)
    {
        return "��Ե��ӡ";
    }else if(strcmp(string,"shimenawaReminiscence") == 0)
    {
        return "׷��ע��";
    }else if(strcmp(string,"paleFlame") == 0)
    {
        return "�԰�֮��";
    }else if(strcmp(string,"tenacityOfTheMillelith") == 0)
    {
        return "ǧ���ι�";
    }else if(strcmp(string,"heartOfDepth") == 0)
    {
        return "����֮��";
    }else if(strcmp(string,"blizzardStrayer") == 0)
    {
        return "������;";
    }else if(strcmp(string,"crimsonWitch") == 0)
    {
        return "��֮ħŮ";
    }else if(strcmp(string,"lavaWalker") == 0)
    {
        return "�ɻ�����";
    }else if(strcmp(string,"thunderingFury") == 0)
    {
        return "����ʢŭ";
    }else if(strcmp(string,"thunderSmoother") == 0)
    {
        return "ƽ������";
    }else if(strcmp(string,"viridescentVenerer") == 0)
    {
        return "����֮Ӱ";
    }else if(strcmp(string,"maidenBeloved") == 0)
    {
        return "������Ů";
    }else if(strcmp(string,"bloodstainedChivalry") == 0)
    {
        return "ȾѪ��ʿ";
    }else if(strcmp(string,"noblesseOblige") == 0)
    {
        return "��������";
    }else if(strcmp(string,"wandererTroupe") == 0)
    {
        return "��������";
    }else if(strcmp(string,"gladiatorFinale") == 0)
    {
        return "�Ƕ�ʿ";
    }else if(strcmp(string,"prayersForWisdom") == 0)
    {
        return "����֮��";
    }else if(strcmp(string,"scholar") == 0)
    {
        return "ѧʿ";
    }else if(strcmp(string,"prayersForIllumination") == 0)
    {
        return "����֮��";
    }else if(strcmp(string,"exile") == 0)
    {
        return "������";
    }else if(strcmp(string,"instructor") == 0)
    {
        return "�̹�";
    }else if(strcmp(string,"berserker") == 0)
    {
        return "ս��";
    }else if(strcmp(string,"resolutionOfSojourner") == 0)
    {
        return "����֮��";
    }else if(strcmp(string,"travelingDoctor") == 0)
    {
        return "��ҽ";
    }else if(strcmp(string,"luckyDog") == 0)
    {
        return "���˶�";
    }else if(strcmp(string,"adventurer") == 0)
    {
        return "ð�ռ�";
    }else if(strcmp(string,"retracingBolide") == 0)
    {
        return "�������";
    }else if(strcmp(string,"archaicPetra") == 0)
    {
        return "�ƹ�����";
    }else if(strcmp(string,"braveHeart") == 0)
    {
        return "����֮��";
    }else if(strcmp(string,"prayersToSpringtime") == 0)
    {
        return "����֮��";
    }else if(strcmp(string,"tinyMiracle") == 0)
    {
        return "�漣";
    }else if(strcmp(string,"gambler") == 0)
    {
        return "��ͽ";
    }else if(strcmp(string,"martialArtist") == 0)
    {
        return "����";
    }else if(strcmp(string,"defenderWill") == 0)
    {
        return "�ػ�֮��";
    }else if(strcmp(string,"prayersForDestiny") == 0)
    {
        return "��ˮ֮��";
    }
    else
    {
        printf("��װ������ʧ��:%s\n",string);
    }
}

char* trans_tag(const char* string)
{
    //ת��������Ϊ����
    if(string == NULL) return 0;
    //��ͨ����
    if(strcmp(string,"lifeStatic") == 0)
    {
        return "����";
    }else if(strcmp(string,"lifePercentage") == 0)
    {
        return "�ٷֱ�����";
    }else if(strcmp(string,"attackStatic") == 0)
    {
        return "����";
    }else if(strcmp(string,"attackPercentage") == 0)
    {
        return "�ٷֱȹ���";
    }else if(strcmp(string,"defendStatic") == 0)
    {
        return "����";
    }else if(strcmp(string,"defendPercentage") == 0)
    {
        return "�ٷֱȷ���";
    }else if(strcmp(string,"elementalMastery") == 0)
    {
        return "��ͨ";
    }else if(strcmp(string,"critical") == 0)
    {
        return "������";
    }else if(strcmp(string,"criticalDamage") == 0)
    {
        return "�����˺�";
    }else if(strcmp(string,"recharge") == 0)
    {
        return "����";
    }else if(strcmp(string,"cureEffect") == 0)
    {
        return "���Ƽӳ�";
    }
    //Ԫ�ؼ���
    else if(strcmp(string,"iceBonus") == 0)
    {
        return "������";
    }else if(strcmp(string,"fireBonus") == 0)
    {
        return "�����";
    }else if(strcmp(string,"waterBonus") == 0)
    {
        return "ˮ����";
    }else if(strcmp(string,"windBonus") == 0)
    {
        return "�����";
    }else if(strcmp(string,"thunderBonus") == 0)
    {
        return "�׼���";
    }else if(strcmp(string,"dendroBonus") == 0)
    {
        return "�ݼ���";
    }else if(strcmp(string,"rockBonus") == 0)
    {
        return "�Ҽ���";
    }
    else
    {
        printf("����������ʧ��:%s",string);
    }
}

bool is_percent(char *string)
{
    //�жϴ����Ƿ�Ϊ�ٷֱ�����
    //�ǰٷֱ�����ʱ����True,���򷵻�False
    if(strcmp(string,"critical")==0 || strcmp(string,"criticalDamage")==0 ||
    strcmp(string,"cureEffect")==0)//���������ˣ����Ƽӳ�
        return true;
    if(strcmp(string + strlen(string) - 10,"Percentage") == 0)//�����������������ٷֱ�
        return true;
    if(strcmp(string + strlen(string) - 5,"Bonus") == 0)//Ԫ�ؼ���
        return true;
    return false;
}

void relic_print(relic *rlc)
{
    //��ʾʥ������Ϣ
    printf("%d��%s %s+%d\n",rlc->star,trans_setname(rlc->setname),trans_posi(rlc->position),rlc->level);
    if(is_percent(rlc->main_tag.name))
        printf("%s%.3lf\n",trans_tag(rlc->main_tag.name),rlc->main_tag.value);
    else
        printf("%s%d\n",trans_tag(rlc->main_tag.name),(int)rlc->main_tag.value);
    int index = 0;
    printf("  ");
    while(strcmp(rlc->normal_tags[index].name,"end") != 0 && index < 4)
    {
        if(is_percent(rlc->normal_tags[index].name))
            printf("%s%.3lf ",trans_tag(rlc->normal_tags[index].name),rlc->normal_tags[index].value);
        else
            printf("%s%.d ",trans_tag(rlc->normal_tags[index].name),(int)rlc->normal_tags[index].value);
        index++;
    }
    printf("\n\n");
}

void relic_print_short(relic *rlc)
{
    //�����Է�ʽ��ʾʥ������Ϣ
    printf("%d��%s %s+%d ",rlc->star,trans_setname(rlc->setname),trans_posi(rlc->position),rlc->level);
    if(is_percent(rlc->main_tag.name))
        printf("%s%.3lf",trans_tag(rlc->main_tag.name),rlc->main_tag.value);
    else
        printf("%s%d",trans_tag(rlc->main_tag.name),(int)rlc->main_tag.value);
    int index = 0;
    printf("  ||  ");
    while(strcmp(rlc->normal_tags[index].name,"end") != 0 && index < 4)
    {
        if(is_percent(rlc->normal_tags[index].name))
            printf("%s%.3lf ",trans_tag(rlc->normal_tags[index].name),rlc->normal_tags[index].value);
        else
            printf("%s%.d ",trans_tag(rlc->normal_tags[index].name),(int)rlc->normal_tags[index].value);
        index++;
    }
    putchar('\n');
}
