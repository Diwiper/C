#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node* previous;
    struct Node* next;
} List;

List *BegL=NULL, *EndL=NULL, *P_prev=NULL, *P=NULL;
int i=1;

void Fill_list()
{
    P=(List*)malloc(sizeof(List));
    P->key=i%3;
    P->next=NULL;
    P->previous=EndL;
    if(BegL==NULL)
    {
        BegL=P;
        EndL=P;
    }
    else
    {
        EndL->next=P;
        EndL=P;
    }
    P=P->next;
    i++;
}

void Show()
{
    printf("\nList items: ");
    P=BegL;
    while(P!=NULL)
    {
        printf("%d ", P->key);
        P=P->next;
    }

}

void Result()
{
    int Result=1;
    P=BegL;
    P_prev=EndL;
    while(P->next!=NULL)
    {
        Result*=P->key + P->next->key + 2*P_prev->key;
        P=P->next;
        P_prev=P_prev->previous;
    }
    printf("\nResult: %d", Result);
}

int Remove()
{
    if(BegL==NULL)
        return 0;
    if(BegL->next==NULL)
    {
        free(BegL);
        BegL=NULL;
        EndL=NULL;
        return 0;
    }
    else
    {
        P=EndL;
        EndL=EndL->previous;
        EndL->next=NULL;
        free(P);
        return 1;
    }
}
int main()
{
    const int n=3;
    printf("n=%d", n);
    for(int i=0; i<n; i++)
        Fill_list(n);
    if(BegL!=NULL)
        Show();

    if(n>=2)
        Result();
    else
        printf("\nThere are not enough items in the list to perform the calculation\n");

while(Remove());
     if(BegL!=NULL)
        Show();
    return 0;
}
