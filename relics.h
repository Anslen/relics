typedef struct tag
{
    char name[20];
    float value;
} tag;

typedef struct relic
{
    char setname[30];
    char position[10];
    tag main_tag;
    tag normal_tags[4];
    int level;
    int star;
} relic;
