#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node;
typedef struct Node *PNode;
struct Node
{
    char word[16];
    PNode link;
};
typedef struct Node *LinkList;
typedef LinkList *PLinkList;

LinkList Dictionary(void)//生成一个链表，用于储存字典内容
{
    PNode head,p,q;
    head = (PNode)malloc(sizeof(struct Node));
    p = head;
    head->link = NULL;
    char str[16];
    while (1)
    {
        scanf ("%s", str);
        if (strcmp(str,"#") == 0)//还没有到结束符
        {
            break;
        }
        q = (PNode)malloc(sizeof(struct Node));
        strcpy(q->word, str);
        p->link = q;
        q->link = NULL;
        p = q;
    }
    return head;
}

int Find (PLinkList plist, char* str)//是否能在字典中找到完全匹配的，如果找到，则返回1，找不到返回0
{
    PNode p;
    p = *plist;
    while (p->link != NULL)
    {
        p=p->link;
        if (strcmp(str, p->word) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void CLosely_Equal (PLinkList plist, char* str)//在字典中找到相似的单词
{
    int i,count,j;
    PNode p;
    p = *plist;
    printf("%s:", str);
    while (p->link != NULL)
    {
        p=p->link;
        if (strlen(p->word) == strlen(str))//如果字符串长度相等，则只可能是有替换的情况
        {
            count = 0;
            for (i=0;i<strlen(str);i++)
            {
                if (str[i] == p->word[i]) count++;
            }
            if (count == strlen(str)-1)//如果只有一个不一样，则相似
            {
                printf(" %s", p->word);
            }
        }
        else if (strlen(p->word) == strlen(str)+1)//如果字典中的词汇长度比待查找的多一位
        {
            count = 0;
            i=0;
            j=0;
            while(i<strlen(p->word)&&j<strlen(str))
            {
                if (p->word[i] == str[j])
                {
                    i++;
                    j++;
                    count++;
                }
                else//如果不等，跳过这一位继续比较
                {
                    i++;
                }
            }
            if (count == strlen(str))//如果待查找的所有字符都有匹配，说明是删减的情况
            {
                printf (" %s", p->word);
            }
        }
        else if (strlen(p->word)+1 == strlen(str))//如果待查找的字符串长度比字典字符串多一位
        {
            count = 0;
            i=0;
            j=0;
            while(i<strlen(p->word)&&j<strlen(str))
            {
                if (p->word[i] == str[j])
                {
                    i++;
                    j++;
                    count++;
                }
                else
                {
                    j++;
                }
            }
            if (count == strlen(p->word))//如果字典字符串中的每个字符都能在待查找的词汇中找到对应，则说明是增添的情况
            {
                printf(" %s", p->word);
            }
        }
    }
    printf("\n");
}

int main (void)
{
    LinkList DIC,BOO;
    DIC = Dictionary();
    BOO = Dictionary();//输入

    PNode p;
    p = BOO;
    while (p->link != NULL)
    {
        p=p->link;//挨个判断是否为完全相等，相似，不相似的情况
        if (Find(&DIC, p->word) == 1)
        {
            printf("%s is correct\n", p->word);
        }
        else
        {
            CLosely_Equal(&DIC, p->word);
        }
    }
    /*
    PNode p;
    p = BOO;
    p=p->link;
    p=p->link;
    p=p->link;
    p=p->link;
    p=p->link;
    p=p->link;
    p=p->link;
    CLosely_Equal(&DIC, p->word);
    */
    /*
    PNode p;
    p = BOO;
    while (p->link != NULL)
    {
        p=p->link;
        printf ("%d\n", Find(&DIC, p->word));
    }
    */
    /*
    LinkList DIC,p;
    DIC = Dictionary();
    p = DIC;
    while(p->link != NULL)
    {
        p=p->link;
        printf("%s\n", p->word);
    }
    */

    return 0;
}
