#ifndef GAMELIB_H_INCLUDED
#define GAMELIB_H_INCLUDED
/******************************************
 * 文件名：Game.h
 * 描  述：定义游戏中常用的系统操作
 * 创建人：
 * 日  期：2018-12-12
 * 版  本：0.1
******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/*设置控制台窗口的标题*/
void SetTitle(char *title);

/*设置前景色和背景色*/
void SetColor(int foreColor, int backColor);

/*设置光标的位置*/
void SetPosition(int x, int y);

/*清空X.Y信息区域*/
void Clear(int x, int y, int rowCount);


#endif // GAMELIB_H_INCLUDED
