#include "Game.h"
#include "GameLib.h"
#define SEP "------------------------------------------------------------------------------"
#define COL 78      //游戏界面的宽度
#define MARGIN_X 20 //左边距
#define GAMENAME "江湖世界"
#define INFO_START_Y 12
#define MAINMENU_START_Y 20
#define MAP_START_Y 3
#define MAP_END_Y 11

X = 0;
Y = 0;



Prop propArray[] = {
    {1, "破旧的尚方宝剑", 1, 5, 5000, Weapon, .minAttakc=1, .maxAttakc=4, "传说中的天子剑，具备一定的观赏价值，没啥攻击力。"},
    {2, "布衣", 2, 5, 5000, Armor, .minDefence=2, .maxDefence=6, "寻常人家的衣物。"},
    {3, "牛肉干", 3, 5, 5000, Con, .minPower=300, .maxPower=500, "纯正黄牛肉，嘎嘣脆。"},

};

Map mapArray[8][8] = {
    {
        {1, "天山", 1, {0,0}, "这里充满了西域文化！这里充满了西域文化！这里充满了西域文化！这里充满了西域文化！这里充满了西域文化！这里充满了西域文化！这里充满了西域文化！这里充满了西域文化！这里充满了西域文化！这里充满了西域文化！这里充满了西域文化！这里充满了西域文化！这里充满了西域文化！这里充满了西域文化！这里充满了西域文化！"},
        {2, "蒙古", 1, {0,0}, "天苍苍，野茫茫，风吹草低见牛羊。"},
        {3, "京城", 1, {0,0}, "繁华的街道，各种吆喝声。"},
        {4, "泰山", 1, {0,0}, "这里充满了西域文化！"},
        {5, "嵩山", 1, {0,0}, "这里充满了西域文化！"},
        {6, "五台山", 1, {0,0}, "这里充满了西域文化！"},
        {7, "苗疆", 1, {0,0}, "这里充满了西域文化！"},
        {8, "蓬莱岛", 1, {0,0}, "这里充满了西域文化！"},
    },
    {
        {9, "迷宫", 1, {0,0}, "这里充满了西域文化！"},
        {10, "西城", 1, {0,0}, "这里充满了西域文化！"},
        {11, "快活林", 1, {0,0}, "这里充满了西域文化！"},
        {12, "二龙山", 1, {0,0}, "这里充满了西域文化！"},
        {13, "九华山", 1, {0,0}, "这里充满了西域文化！"},
        {14, "霹雳堂", 1, {0,0}, "这里充满了西域文化！"},
        {15, "神剑山庄", 1, {0,0}, "这里充满了西域文化！"},
        {16, "恶人谷", 1, {0,0}, "这里充满了西域文化！"},
    },
    {
        {17, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {18, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {19, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {20, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {21, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {22, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {23, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {24, "测试", 1, {0,0}, "这里充满了西域文化！"},
    },
    {
        {25, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {26, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {27, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {28, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {29, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {30, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {31, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {32, "测试", 1, {0,0}, "这里充满了西域文化！"},
    },
    {
        {33, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {34, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {35, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {36, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {37, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {38, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {39, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {40, "测试", 1, {0,0}, "这里充满了西域文化！"},
    },
    {
        {33, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {34, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {35, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {36, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {37, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {38, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {39, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {40, "测试", 1, {0,0}, "这里充满了西域文化！"},
    },
    {
        {49, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {50, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {51, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {52, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {53, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {54, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {55, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {56, "测试", 1, {0,0}, "这里充满了西域文化！"},
    },
    {
        {57, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {58, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {59, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {60, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {61, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {62, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {63, "测试", 1, {0,0}, "这里充满了西域文化！"},
        {64, "测试", 1, {0,0}, "这里充满了西域文化！"},
    },
};

Player players[] = {
    {111, "李白", "123", 100, 3, 1, 10000, 5000, 900000, 1000000, .coord.X=1, .coord.Y=2},
};

Player *currPlayer;
void Init()     //初始化数据
{
    currPlayer = &players[0];
    currPlayer->Weapon = propArray[0];
    currPlayer->Armor = propArray[1];
}

/*
void Show()    //显示数据
{
    int propCount = sizeof(propArray) / sizeof(Prop);
    int i,j;
    for(i = 0; i < propCount; i++){
        printf("%d\t%s\t%.0f\n",propArray[i].id,propArray[i].name,propArray[i].price);
        switch(propArray[i].type){
        case Weapon:
            printf("最小攻击力：%d\t最大攻击力：%d\n",propArray[i].minAttakc,propArray[i].maxAttakc);
            break;
        case Armor:
            printf("最小防御力：%d\t最大防御力：%d\n",propArray[i].minDefence,propArray[i].maxDefence);
            break;
        case Con:
            printf("最少加：%d\t最大加：%d\n",propArray[i].minPower,propArray[i].maxPower);
            break;
        }
    }
    printf("--------------------------------------------------------------------------\n");
    for(i = 0; i < 8; i++){
        printf("|");
        for(j = 0; j < 8; j++){
            printf(" %-8s",mapArray[i][j].name);
        }mapArray[i][j].name
        printf("|\n");
    }
}
*/


void ShowWelcome()     //显示欢迎信息
{
    SetPosition(MARGIN_X, 0);
    printf("%s\n",SEP);
    SetPosition(MARGIN_X, 1);
    printf("|");
    SetPosition(MARGIN_X + 30, 1);
    printf("欢迎来到%s。",GAMENAME);
    SetPosition(MARGIN_X + 77, 1);
    printf("|\n");
    SetPosition(MARGIN_X, 2);
    printf("%s\n",SEP);
}


void ShowMap()         //显示地图
{
    int i, j;
    for(i = 0; i < 8; i++){
        SetPosition(MARGIN_X, i + MAP_START_Y);
        printf("|");
        for(j = 0; j < 8; j++){
            if(i == Y && j == X){
                //更改地图名称的颜色和背景色
                SetColor(7 ,0);
            }
            printf(" %-8s",mapArray[i][j].name);
            //颜色变回
            SetColor(11, 0);
        }
        printf("%-4s|"," ");
    }
    SetPosition(MARGIN_X, MAP_END_Y);
    printf(SEP);
    ShowMapInfo();
}

void ShowMapInfo()     //显示地图信息
{
    Clear(MARGIN_X + 1, INFO_START_Y, 7);
    SetPosition(MARGIN_X + 25, INFO_START_Y);
    printf("显示地图信息:");
    //printf("%s",mapArray[Y][X].desc);
    char * desc = mapArray[Y][X].desc;
    int descLen = strlen(desc);
    int i;
    //int rowLen = INFO_START_Y + 1;
    SetPosition(MARGIN_X + 5, INFO_START_Y + 1);
    for(i = 0; i < descLen; i++){

        if(i > 0 && i % 65 == 0){
            SetPosition(MARGIN_X + 5, INFO_START_Y + 1 + i / 65);
        }
        printf("%c", desc[i]);
    }
}

void ShowInfomation()  //显示下方的游戏信息
{
    SetPosition(MARGIN_X, INFO_START_Y);
    for(int i = 0; i < 7; i++){
        SetPosition(MARGIN_X, INFO_START_Y + i);
        printf("|");
        SetPosition(MARGIN_X + 77, INFO_START_Y + i);
        printf("|");
    }
    SetPosition(MARGIN_X, INFO_START_Y + 7);
    printf(SEP);
}
void ShowMainMenu()    //显示主菜单
{
    SetPosition(MARGIN_X, MAINMENU_START_Y);
    printf("游戏菜单：");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 1);
    printf("1、自我欣赏");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 2);
    printf("2、寻找怪物");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 3);
    printf("3、返回门派");
    SetPosition(MARGIN_X, MAINMENU_START_Y + 4);
    printf("4、购买装备");
}
/*处理游戏主菜单*/
void ProcessMainMenu(char key)
{
    switch(key){
        case '1'://自我欣赏
            ShowPlayerInfo();
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
    }
}
/*在信息界面显示玩家个人资料*/
void ShowPlayerInfo()
{
    Clear(MARGIN_X + 1, INFO_START_Y, 7);
    SetPosition(MARGIN_X + 25, INFO_START_Y);
    printf("大侠《%s》的个人资料:", currPlayer->name);
    SetPosition(MARGIN_X + 10, INFO_START_Y + 1);
    printf("等级：%d\t经验值：%d\t血量：%d\t内力值：%d", currPlayer->level, currPlayer->exp, currPlayer->hp, currPlayer->mp);
    SetPosition(MARGIN_X + 10, INFO_START_Y + 2);
    printf("武器：%s\t防具：%s", currPlayer->Weapon.name, currPlayer->Armor.name);
}
