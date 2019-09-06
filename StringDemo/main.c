#include <stdio.h>
#include <stdlib.h>
#include "SeqString.h"

void TestSeqString();
void TestBF();

int main()
{
    //TestSeqString();
    TestBF();
    return 0;
}

void TestBF(){
    HString ps;
    HString cs;
    StrAssign_HeapString(&ps, "abcabdabdabeaac");
    StrAssign_HeapString(&cs, "abe");
    printf("BF Index:%d\n", BfCompare(&ps, &cs, 1));
    printf("KMP Index:%d\n", KMPCompare(&ps, &cs, 1));
}

void TestSeqString(){
    HString * str = (HString *)malloc(sizeof(HString));
    HString * str1 = (HString *)malloc(sizeof(HString));
    HString * str2 = (HString *)malloc(sizeof(HString));
    HString * str3 = (HString *)malloc(sizeof(HString));
    HString str4;
    HString str5;


    StrAssign_HeapString(str, "Show Test String.");
    PrintHeapString(str);
    printf("Copy string:\n");
    StrCopy_HeapString(str1, str);
    PrintHeapString(str1);
    printf("Than string:\n");
    StrAssign_HeapString(str1, "Test");
    printf("%d\n", StrCompare_HeapString(str, str1));
    PrintHeapString(str1);
    printf("Connect string:\n");
    Concat_HeapString(str2, str, str1);
    PrintHeapString(str2);
    printf("After sub string3:\n");
    SubString_HeapString(str3, str, 6, 5);
    PrintHeapString(str3);
    printf("Str`s 3 index of str: %d\n", Index_HeapString(str, str3, 2));
    printf("Delete sub string:\n");
    StrDelete_HeapString(str, 6, 4);
    PrintHeapString(str);
    printf("Insert string:\n");
    StrInsert_HeapString(str, 5, str1);
    PrintHeapString(str);
    printf("Replace string:\n");
    StrAssign_HeapString(&str4, "S");
    StrAssign_HeapString(&str5, "123");
    Replace_HeapString(str, str4, str5);
    PrintHeapString(str);
    printf("Clear string:\n");
    ClearString_HeapString(str);
    printf("%d\n", str->length);

    free(str);
    free(str1);
    free(str2);
}
