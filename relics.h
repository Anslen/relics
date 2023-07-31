typedef struct tag
{
    char[20] name;
    float value;
} tag;

typedef struct relic
{
    char[30] setname;
    tag main_tag;
    tag[4] normal_tags;
    int level;
    int star;
} relic;
