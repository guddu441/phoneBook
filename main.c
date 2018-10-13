#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct n Node;
struct n
{
    char name[21];
    char mobileNumber[21];
    Node *next;
};


Node *createNode(char *n, char *mob)
{
    Node *new1=malloc(sizeof(Node));
    strcpy(new1->name,n);
    strcpy(new1->mobileNumber,mob);
    new1->next=NULL;
    return new1;

}
Node *insertContact(Node *h, char *n, char *mob)
{
    Node *t=createNode(n,mob);
    Node *cur=h,*pre=NULL;
    if(h==NULL)
        return t;
    else
    {
       while(cur!=NULL)
       {
           if(strcmpi(n,cur->name)==-1 && cur==h)
           {
               t->next=h;
               return t;
           }
           else if(strcmpi(n,cur->name)==-1)
           {
               pre->next=t;
               t->next=cur;
               return h;
           }
           pre=cur;
           cur=cur->next;
       }
       pre->next=t;
       return h;
    }
}

Node *searchContact(Node *h, char *n)
{
    while(h!=NULL)
    {
        if(strcmpi(n,h->name)==0)
        {
            return h;
        }
        h=h->next;
    }
    return NULL;
}

Node *deleteContact(Node *h, char *n)
{
    Node *cur=h, *pre=NULL;
    if(h==NULL)
        return NULL;
    while(cur!=NULL)
    {
        if(strcmpi(n,h->name)==0 && cur==h)
        {
            h=h->next;
            free(cur);
            return h;
        }
        else if(strcmpi(n,h->name)==0)
        {
            pre->next=cur->next;
            free(cur);
            return h;
        }
        pre=cur;
        cur=cur->next;
    }
    return h;
}

int printList(Node *h)
{
    int sr=1;
    printf("\n\nPHONEBOOK:");
    if(h==NULL)
    {
        printf("\n\t\t\tEmpty!!\n");
        return 0;
    }
    while(h!=NULL){
        printf("\n%4d %20s %20s", sr, h->name, h->mobileNumber);
        sr++;
        h=h->next;
    }
    return 0;
}

int showMenuAndGetChoice()
{
    int choice;
    printf("\n\nMENU");
    printf("\n1. Add Contact");
    printf("\n2. Search Contact");
    printf("\n3. Delete Contact");
    printf("\n4. Print List");
    printf("\n5. Exit");
    printf("\n\nYour Choice: ");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    int ch,ret;
    Node *h=NULL, *t;
    char name[21], mob[21];
    while(1){
        ch = showMenuAndGetChoice();
        switch(ch)
        {
        case 1:
            printf("Enter a Name: ");
            scanf("%s", name);
            printf("Enter Mobile Number: ");
            scanf("%s", mob);
            h = insertContact(h, name, mob);
            break;
        case 2:
            printf("Enter a Name: ");
            scanf("%s", name);
            t = searchContact(h, name);
            if(t!=NULL)
                printf("FOUND: %s, %s\n", t->name, t->mobileNumber);
            else
                printf("NOT FOUND\n");
            break;
        case 3:
            printf("Enter a Name: ");
            scanf("%s", name);
            h = deleteContact(h, name);
            break;
        case 4:
            ret=printList(h);
            break;
        case 5:
            return 0;
        default:
            printf("\nBAD CHOICE! TRY AGAIN!");
            break;
        }
    }
    return 0;
}
