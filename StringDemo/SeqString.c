#include "SeqString.h"

/** 初始化堆字符串 */
void InitString_HeapString(HString * str){
    str->ch = NULL;
    str->length = 0;
}

/** 为串str赋值，值为字符串常量chars */
Status StrAssign_HeapString(HString * str, char * chars){
    int len = strlen(chars);
    if(!len){
        return ERROR;
    }
    //初始化字符串
    InitString_HeapString(str);
    str->ch = (char *)malloc(len * sizeof(char));
    //如果出现错误，返回内存溢出并退出
    if(!str->ch){
        exit(OVERFLOW);
    }
    for(int i = 0; i < len; i++){
        str->ch[i] = chars[i];
    }
    str->length = len;

    return OK;
}

/** 打印堆字符串 */
void PrintHeapString(HString * str){
    if(!str->ch || str->length == 0){
        printf("String is empty.\n");
    }
    for(int i = 0; i < str->length; i++){
        printf("%c", str->ch[i]);
    }
    printf("\n");
}

/** 将串srcStr中的内容复制到串destStr中 */
Status StrCopy_HeapString(HString * destStr, HString * srcStr){
    InitString_HeapString(destStr);
    if(IsEmpty_HeapString(srcStr)){
        printf("Src string is Empty.\n");
        return ERROR;
    }
    destStr->ch = (char *)malloc(sizeof(char) * srcStr->length);
    if(!destStr->ch) exit(OVERFLOW);
    for(int i = 0; i < srcStr->length; i++) {
        destStr->ch[i] = srcStr->ch[i];
    }
    destStr->length = srcStr->length;
    return OK;
}

/** 判断串是否为空 */
Status IsEmpty_HeapString(HString * str){
    if(str->length == 0 || !str->ch){
        return TRUE;
    }
    return FALSE;
}

/** 比较两个堆字符的大小，相等返回0，1<2返回负数，1>2返回正数 */
Status StrCompare_HeapString(HString * str1, HString * str2){
    for(int i = 0; i < str1->length && i < str2->length; i++){
        //遇到不同的字符就比较ASCII码
        if(str1->ch[i] != str2->ch[i]){
            return str1->ch[i] - str2->ch[i];
        }
    }
    //字符都相等，就比较长度
    return str1->length - str2->length;
}

/** 连接串 */
Status Concat_HeapString(HString * destStr, HString * str1, HString * str2){
    InitString_HeapString(destStr);
    destStr->length = str1->length + str2->length;
    destStr->ch = (char *)malloc(sizeof(char) * destStr->length);
    if(!destStr->ch) exit(OVERFLOW);
    //复制第一个串
    for(int i = 0; i < str1->length; i++){
        destStr->ch[i] = str1->ch[i];
    }
    //复制第二个串
    for(int i = 0; i < str2->length; i++){
        destStr->ch[str1->length + i] = str2->ch[i];
    }
    return OK;
}

/** 截取串，从pos处截取len长度的串 */
Status SubString_HeapString(HString * destStr, HString * str, int pos, int len){
    InitString_HeapString(destStr);
    if(IsEmpty_HeapString(str)){
        return ERROR;
    }
    if(pos < 1|| pos > str->length || len < 0 || pos + len - 1 > str->length){
        return ERROR;
    }
    destStr->ch = (char *)malloc(len * sizeof(char));
    if(!destStr->ch) exit(OVERFLOW);
    for(int i = 0; i < len; i++){
        destStr->ch[i] = str->ch[pos - 1 + i];
    }
    destStr->length = len;
    return OK;
}

/** 返回从pos位置开始的子串child在父串parent中的位置 */
int Index_HeapString(HString * parent, HString * child, int pos){
    if(pos < 0 || pos > parent->length) return 0;
    HString * subStr = (HString *)malloc(sizeof(HString));
    InitString_HeapString(subStr);
    int i = pos;
    while(i + child->length - 1 <= parent->length){
        //截取字符串
        SubString_HeapString(subStr, parent, i, child->length);
        if(StrCompare_HeapString(subStr, child) != EQ){
            i++;
        }else{
            return i;
        }
    }
    free(subStr);
    return 0;
}

/** 从pos位置处删除长度len的子串 */
Status StrDelete_HeapString(HString * str, int pos, int len){
    if(IsEmpty_HeapString(str)) return ERROR;
    if(pos < 1 || pos + len - 1 > str->length || len < 1){
        return ERROR;
    }
    for(int i = pos - 1; i + len < str->length; i++){
        str->ch[i] = str->ch[i + len];
    }
    str->length -= len;
    //缩小分配的空间
    str->ch = (char *)realloc(str->ch, str->length * sizeof(char));
    return OK;
}

/** 向指定位置插入串 */
Status StrInsert_HeapString(HString * str, int pos, HString * insertStr){
    if(pos < 1 || pos > str->length + 1){
        return ERROR;
    }
    if(IsEmpty_HeapString(str)) return ERROR;
    //重新分配空间
    str->ch = (char *)realloc(str->ch, (str->length + insertStr->length) * sizeof(char));
    if(!str->ch) exit(OVERFLOW);
    for(int i = str->length - 1; i >= pos - 1; i--){
        str->ch[i + insertStr->length] = str->ch[i];
    }
    //插入每个字符
    for(int i = 0; i < insertStr->length; i++){
        str->ch[pos - 1 + i] = insertStr->ch[i];
    }
    str->length += insertStr->length;
    return OK;
}

/** 将串str中的oldstr替换成newStr */
Status Replace_HeapString(HString * str, HString oldStr, HString newStr){
    if(IsEmpty_HeapString(str)) return ERROR;
    //从第一个位置查找到oldStr的位置
    int pos = Index_HeapString(str, &oldStr, 1);
    //printf("%s\t%d\n", oldStr.ch, pos);
    while(pos != 0){
        StrDelete_HeapString(str, pos, oldStr.length);
        StrInsert_HeapString(str, pos, &newStr);
        //继续查找下一个重复替换项
        pos += newStr.length;
        pos = Index_HeapString(str, &oldStr, pos);
    }
    return OK;
}

/** 清空堆字符串 */
Status ClearString_HeapString(HString * str){
    if(str->ch){
        free(str->ch);
        str->ch = NULL;
    }
    str->length = 0;
    return OK;
}

/** 使用BF算法返回子串在主串中的位置 */
int BfCompare(HString * parent, HString * child, int pos){
    int i = pos;
    int j = 1;
    while(i <= parent->length && j <= child->length){
        if(parent->ch[i - 1] == child->ch[j - 1]){
            i++;
            j++;
        }else{
            i = i - j + 2;
            j = 1;
        }
    }
    if(j > child->length){
        return i - child->length;
    }
    return 0;
}

/** KMP算法返回next数组（部分匹配表） */
void Get_Next(HString child, int * next){
    int i = 0;
    int j = -1;
    next[0] = -1;
    while(i < child.length){
        if(j == -1 || child.ch[i] == child.ch[j]){
            ++i;
            ++j;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
}

/** 使用KMP算法返回子串在主串中的位置 */
int KMPCompare(HString * parent, HString * child, int pos){
    int next[255];          //用来存放部分匹配值
    Get_Next(*child, next); //首先处理子串，计算出部分匹配值
    int i = pos - 1;
    int j = 0;
    while(i < parent->length && j < child->length){
        if(j == -1 || parent->ch[i] == child->ch[j]){
            ++i;
            ++j;
        }else{
            j = next[j];
        }
    }
    if(j == child->length){
        return (i + 1) - j;
    }
    return 0;
}
