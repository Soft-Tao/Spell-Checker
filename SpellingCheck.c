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

LinkList Dictionary(void)
{
    PNode head,p,q;
    head = (PNode)malloc(sizeof(struct Node));
    p = head;
    head->link = NULL;
    char str[16];
    while (1)
    {
        scanf ("%s", str);
        if (strcmp(str,"#") == 0)
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

int Find (PLinkList plist, char* str)
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

void CLosely_Equal (PLinkList plist, char* str)
{
    int i,count,j;
    PNode p;
    p = *plist;
    printf("%s:", str);
    while (p->link != NULL)
    {
        p=p->link;
        if (strlen(p->word) == strlen(str))
        {
            count = 0;
            for (i=0;i<strlen(str);i++)
            {
                if (str[i] == p->word[i]) count++;
            }
            if (count == strlen(str)-1)
            {
                printf(" %s", p->word);
            }
        }
        else if (strlen(p->word) == strlen(str)+1)
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
                    i++;
                }
            }
            if (count == strlen(str))
            {
                printf (" %s", p->word);
            }
        }
        else if (strlen(p->word)+1 == strlen(str))
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
            if (count == strlen(p->word))
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
    BOO = Dictionary();

    PNode p;
    p = BOO;
    while (p->link != NULL)
    {
        p=p->link;
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