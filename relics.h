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
        return "生之花";
    }else if(strcmp(string,"feather") == 0)
    {
        return "死之羽";
    }else if(strcmp(string,"sand") == 0)
    {
        return "时之沙";
    }else if(strcmp(string,"cup") == 0)
    {
        return "空之杯";
    }else if(strcmp(string,"head") == 0)
    {
        return "理之冠";
    }else
    {
        printf("部位名解析失败:%s\n",string);
    }
}

char* trans_setname(const char* string)
{
    if(strcmp(string,"VourukashasGlow") == 0)
    {
        return "花海甘露";
    }else if(strcmp(string,"NymphsDream") == 0)
    {
        return "水仙之梦";
    }else if(strcmp(string,"FlowerOfParadiseLost") == 0)
    {
        return "乐园之花";
    }else if(strcmp(string,"DesertPavilionChronicle") == 0)
    {
        return "沙上楼阁";
    }else if(strcmp(string,"GildedDreams") == 0)
    {
        return "饰金之梦";
    }else if(strcmp(string,"DeepwoodMemories") == 0)
    {
        return "深林记忆";
    }else if(strcmp(string,"EchoesOfAnOffering") == 0)
    {
        return "来歆余响";
    }else if(strcmp(string,"VermillionHereafter") == 0)
    {
        return "辰砂往生";
    }else if(strcmp(string,"oceanHuedClam") == 0)
    {
        return "海染砗磲";
    }else if(strcmp(string,"huskOfOpulentDreams") == 0)
    {
        return "华冠梦醒";
    }else if(strcmp(string,"emblemOfSeveredFate") == 0)
    {
        return "绝缘旗印";
    }else if(strcmp(string,"shimenawaReminiscence") == 0)
    {
        return "追忆注连";
    }else if(strcmp(string,"paleFlame") == 0)
    {
        return "苍白之火";
    }else if(strcmp(string,"tenacityOfTheMillelith") == 0)
    {
        return "千岩牢固";
    }else if(strcmp(string,"heartOfDepth") == 0)
    {
        return "沉沦之心";
    }else if(strcmp(string,"blizzardStrayer") == 0)
    {
        return "冰封迷途";
    }else if(strcmp(string,"crimsonWitch") == 0)
    {
        return "炎之魔女";
    }else if(strcmp(string,"lavaWalker") == 0)
    {
        return "渡火贤人";
    }else if(strcmp(string,"thunderingFury") == 0)
    {
        return "如雷盛怒";
    }else if(strcmp(string,"thunderSmoother") == 0)
    {
        return "平雷尊者";
    }else if(strcmp(string,"viridescentVenerer") == 0)
    {
        return "翠绿之影";
    }else if(strcmp(string,"maidenBeloved") == 0)
    {
        return "怜爱少女";
    }else if(strcmp(string,"bloodstainedChivalry") == 0)
    {
        return "染血骑士";
    }else if(strcmp(string,"noblesseOblige") == 0)
    {
        return "昔日宗室";
    }else if(strcmp(string,"wandererTroupe") == 0)
    {
        return "流浪乐团";
    }else if(strcmp(string,"gladiatorFinale") == 0)
    {
        return "角斗士";
    }else if(strcmp(string,"prayersForWisdom") == 0)
    {
        return "祭雷之人";
    }else if(strcmp(string,"scholar") == 0)
    {
        return "学士";
    }else if(strcmp(string,"prayersForIllumination") == 0)
    {
        return "祭火之人";
    }else if(strcmp(string,"exile") == 0)
    {
        return "流放者";
    }else if(strcmp(string,"instructor") == 0)
    {
        return "教官";
    }else if(strcmp(string,"berserker") == 0)
    {
        return "战狂";
    }else if(strcmp(string,"resolutionOfSojourner") == 0)
    {
        return "行者之心";
    }else if(strcmp(string,"travelingDoctor") == 0)
    {
        return "游医";
    }else if(strcmp(string,"luckyDog") == 0)
    {
        return "幸运儿";
    }else if(strcmp(string,"adventurer") == 0)
    {
        return "冒险家";
    }else if(strcmp(string,"retracingBolide") == 0)
    {
        return "逆飞流星";
    }else if(strcmp(string,"archaicPetra") == 0)
    {
        return "悠古磐岩";
    }else if(strcmp(string,"braveHeart") == 0)
    {
        return "勇者之心";
    }else if(strcmp(string,"prayersToSpringtime") == 0)
    {
        return "祭冰之人";
    }else if(strcmp(string,"tinyMiracle") == 0)
    {
        return "奇迹";
    }else if(strcmp(string,"gambler") == 0)
    {
        return "赌徒";
    }else if(strcmp(string,"martialArtist") == 0)
    {
        return "武人";
    }else if(strcmp(string,"defenderWill") == 0)
    {
        return "守护之心";
    }else if(strcmp(string,"prayersForDestiny") == 0)
    {
        return "祭水之人";
    }
    else
    {
        printf("套装名解析失败:%s\n",string);
    }
}

char* trans_tag(const char* string)
{
    //转换词条名为中文
    if(string == NULL) return 0;
    //普通词条
    if(strcmp(string,"lifeStatic") == 0)
    {
        return "生命";
    }else if(strcmp(string,"lifePercentage") == 0)
    {
        return "百分比生命";
    }else if(strcmp(string,"attackStatic") == 0)
    {
        return "攻击";
    }else if(strcmp(string,"attackPercentage") == 0)
    {
        return "百分比攻击";
    }else if(strcmp(string,"defendStatic") == 0)
    {
        return "防御";
    }else if(strcmp(string,"defendPercentage") == 0)
    {
        return "百分比防御";
    }else if(strcmp(string,"elementalMastery") == 0)
    {
        return "精通";
    }else if(strcmp(string,"critical") == 0)
    {
        return "暴击率";
    }else if(strcmp(string,"criticalDamage") == 0)
    {
        return "暴击伤害";
    }else if(strcmp(string,"recharge") == 0)
    {
        return "充能";
    }else if(strcmp(string,"cureEffect") == 0)
    {
        return "治疗加成";
    }
    //元素加伤
    else if(strcmp(string,"iceBonus") == 0)
    {
        return "冰加伤";
    }else if(strcmp(string,"fireBonus") == 0)
    {
        return "火加伤";
    }else if(strcmp(string,"waterBonus") == 0)
    {
        return "水加伤";
    }else if(strcmp(string,"windBonus") == 0)
    {
        return "风加伤";
    }else if(strcmp(string,"thunderBonus") == 0)
    {
        return "雷加伤";
    }else if(strcmp(string,"dendroBonus") == 0)
    {
        return "草加伤";
    }else if(strcmp(string,"rockBonus") == 0)
    {
        return "岩加伤";
    }
    else
    {
        printf("词条名解析失败:%s",string);
    }
}

bool is_percent(char *string)
{
    //判断词条是否为百分比类型
    //是百分比类型时返回True,否则返回False
    if(strcmp(string,"critical")==0 || strcmp(string,"criticalDamage")==0 ||
    strcmp(string,"cureEffect")==0)//暴击，爆伤，治疗加成
        return true;
    if(strcmp(string + strlen(string) - 10,"Percentage") == 0)//生命、攻击、防御百分比
        return true;
    if(strcmp(string + strlen(string) - 5,"Bonus") == 0)//元素加伤
        return true;
    return false;
}

void relic_print(relic *rlc)
{
    //显示圣遗物信息
    printf("%d星%s %s+%d\n",rlc->star,trans_setname(rlc->setname),trans_posi(rlc->position),rlc->level);
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
    //以缩略方式显示圣遗物信息
    printf("%d星%s %s+%d ",rlc->star,trans_setname(rlc->setname),trans_posi(rlc->position),rlc->level);
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
