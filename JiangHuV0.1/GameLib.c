/******************************************
 * 文件名：Game.h
 * 描  述：实现GameLib.h中定义的操作
 * 创建人：
 * 日  期：2018-12-12
 * 版  本：0.1
******************************************/
#include "GameLib.h"

/*设置控制台窗口的标题*/
void SetTitle(char *title)
{
    SetConsoleTitle(title);
}

/*设置前景色和背景色*/
void SetColor(int foreColor, int backColor)
{
    HANDLE winHandle;   //句柄
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    //设置文字颜色
    SetConsoleTextAttribute(winHandle, foreColor + backColor * 0x10);
}

/*设置光标的位置*/
void SetPosition(int x, int y)
{
    HANDLE winHandle;   //句柄
    COORD pos ={x, y};
    winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(winHandle, pos);
}

/*清空X.Y信息区域*/
void Clear(int x, int y, int rowCount)
{
    SetPosition(x, y);
    int i,j;
    for(i = 0; i < rowCount; i++){
        SetPosition(x, y + i);
        for(j = 0; j < 76; j++){
            printf(" ");
        }
    }
}
