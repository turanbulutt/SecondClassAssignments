//AHMET TURAN BULUT 2315174
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
struct movie{
    char *title;
    int year;
    char *IMBDID;
    char *Link;
    struct movie *next;
};
typedef struct Node *AVLTree;
struct Node
{
        struct movie *details;
        AVLTree left;
        AVLTree right;
        int height;
};
AVLTree CreateTree(void);
AVLTree MakeEmptyTree(AVLTree);
AVLTree InsertMovie(struct movie*,AVLTree);
AVLTree SingleRotateWithLeft(AVLTree);
AVLTree SingleRotateWithRight(AVLTree);
AVLTree DoubleRotateWithLeft(AVLTree);
AVLTree DoubleRotateWithRight(AVLTree);
void DisplayTree(AVLTree);
void DisplayTreeStructure(AVLTree, int);
int AVLTreeHeight(AVLTree);
int Max(int, int);


AVLTree CreateTree(void)
{
        return NULL;
}

AVLTree MakeEmptyTree(AVLTree t)
{
        if (t != NULL)
        {
                MakeEmptyTree(t->left);
                MakeEmptyTree(t->right);
                free(t);
        }
        return NULL;
}

AVLTree InsertMovie(struct movie * node, AVLTree t)
{
        printf("qasdas");
        if (t == NULL)
        {
                printf("ANAN MAL\n");
                t=malloc(sizeof(AVLTree));
                if (t == NULL)
                        printf("Out of memory space!!!\n");
                else
                {
                    printf("baban");
                    t->details=malloc(sizeof(struct movie*));
                    t->details->IMBDID=malloc(sizeof(char)*200);
                    t->details->Link=malloc(sizeof(char)*200);
                    t->details->title=malloc(sizeof(char)*200);
                    strcpy(t->details->title,node->title);
                    printf("\nbacin");
                    t->details->year=node->year;
                    printf("\nbacin");
                    strcpy(t->details->IMBDID,node->IMBDID);
                    printf("\nbacin");
                    strcpy(t->details->Link,node->Link);
                    printf("\nbacin");
                    t->height = 0;
                    t->left = t->right=t->details->next = NULL;

                }
        }
        else if (strcmp(node->title,t->details->title)>0)
        {
                t->left = InsertMovie(node, t->left);
                if (AVLTreeHeight(t->left) - AVLTreeHeight(t->right) == 2)
                if (strcmp(node->title,t->left->details->title)<0)
                        t = SingleRotateWithLeft(t);
                else
                        t = DoubleRotateWithLeft(t);
        }
        else if (strcmp(node->title,t->details->title)<0)
        {
                t->right = InsertMovie(node, t->right);
                if (AVLTreeHeight(t->right) - AVLTreeHeight(t->left) == 2)
                if (strcasecmp(node->title,t->right->details->title)>0)
                        t = SingleRotateWithRight(t);
                else
                        t = DoubleRotateWithRight(t);
        }
        else{
            if(t->details->next==NULL)
            {
                t->details->next=malloc(sizeof(AVLTree));
                t->details->next->IMBDID=malloc(sizeof(char)*81);
                t->details->next->Link=malloc(sizeof(char)*256);
                t->details->next->year=malloc(sizeof(char)*5);
                strcpy(t->details->next->title,node->title);
                t->details->next=node->year;
                strcpy(t->details->next->IMBDID,node->IMBDID);
                strcpy(t->details->next->Link,node->Link);
                t->details->next->next=NULL;
            }
            else
            {
               struct movie *temp=t->details->next;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp=malloc(sizeof(AVLTree));
                temp->IMBDID=malloc(sizeof(char)*81);
                temp->Link=malloc(sizeof(char)*256);
                temp->title=malloc(sizeof(char)*81);
                temp->year=malloc(sizeof(char)*5);
                strcpy(temp->title,node->title);
                strcpy(temp->year,node->year);
                strcpy(temp->IMBDID,node->IMBDID);
                strcpy(temp->Link,node->Link);
                temp->next=NULL;
            }

        }
        t->height = Max(AVLTreeHeight(t->left), AVLTreeHeight(t->right)) + 1;

        return t;
}

void DisplayTree(AVLTree t)
{
        if (t != NULL)
        {
                DisplayTree(t->left);
                printf("%d\n", t->details->title);
                DisplayTree(t->right);
        }
}

int AVLTreeHeight(AVLTree t)
{
        if (t == NULL)
                return -1;
        else
                return t->height;
}

AVLTree SingleRotateWithLeft(AVLTree k2)
{
    AVLTree k1;
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = Max(AVLTreeHeight(k2->left),AVLTreeHeight(k2->right))+1;
    k1->height = Max(AVLTreeHeight(k1->left),AVLTreeHeight(k2->right))+1;
    return k1;

}

AVLTree SingleRotateWithRight(AVLTree k1)
{
    AVLTree k2;
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = Max(AVLTreeHeight(k1->left),AVLTreeHeight(k1->right))+1;
    k2->height = Max(AVLTreeHeight(k2->left),AVLTreeHeight(k1->right))+1;
    return k2;

}

AVLTree DoubleRotateWithLeft(AVLTree k3)
{
    k3->left = SingleRotateWithRight(k3->left);
    k3=SingleRotateWithLeft(k3);
    return k3;
}

AVLTree DoubleRotateWithRight(AVLTree k3)
{
    k3->right = SingleRotateWithLeft(k3->right);
    k3=SingleRotateWithRight(k3);
    return k3;
}

int Max(int x, int y)
{
        if (x >= y)
                return x;
        else
                return y;
}
