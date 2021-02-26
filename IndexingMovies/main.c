//AHMET TURAN BULUT 2315174
#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

AVLTree readData(char *name){
    AVLTree myTree=NULL;
    FILE *infile;
    infile=fopen(name, "r");
    int lineCount=1;
    if(infile==NULL){
        printf("Couldn't assign a pointer for the file.");
    }
    else{
        char endCheck;
        while (fscanf(infile, "%c", &endCheck) != -1)
            {
                if (endCheck == 10)
                    lineCount++;
            }
        }
    fclose(infile);
    infile=fopen(name,"r");
    if(infile==NULL){
        printf("Couldn't assign a pointer for the file.");
    }
    char buffer;
    do{
        buffer=fgetc(infile);
    }while(buffer!=10);
    char *token;
    int i=0;
    while(i<lineCount-1){
        char *line=malloc(sizeof(char)*256);
        fgets(line,256,infile);
        line[strlen(line)-1]='\0';
        AVLTree temp=malloc(sizeof(AVLTree));
        temp->details=malloc(sizeof(struct movie));
        temp->details->IMBDID=malloc(sizeof(char)*200);
        temp->details->Link=malloc(sizeof(char)*200);
        temp->details->title=malloc(sizeof(char)*200);
        temp->left=temp->right=NULL;
        temp->details->next=NULL;
        printf("HEREE");
        token=strtok(line,",");
        strcpy(temp->details->title,token);
        puts(temp->details->title);
        token=strtok(NULL,",");
        temp->details->year=atoi(token);
        token=strtok(NULL,",");
        strcpy(temp->details->IMBDID,token);
        puts(temp->details->IMBDID);
        token=strtok(NULL,",");
        strcpy(temp->details->Link,token);
        puts(temp->details->Link);
        myTree=InsertMovie(temp,myTree);
        free(temp);
        free(line);
        free(token);
        i++;
    }
    return myTree;
}
int main()
{
    AVLTree movies;
    movies=readData("movies.txt");
    int op=0;
    char key[81];
    printf(">>>Welcome to Movie Analysis at IMDB<<< ");
    while(op!=4)
    {
        printf("\n--Menu--\n1. Display the full index of movies\n2. Display the movies where their title contains a specific keyword\n3. Display the year with maximum number of movies\n4. Exit\n");
        printf("Option: ");
        scanf("%d",&op);
        fflush(stdin);
        switch(op)
        {
            case 1:
                DisplayTree(movies);
                break;
            case 2:
                printf("\nEnter a key word to search: ");
                scanf("%s",&key);
                //display_movies_keyword(movies,key);
                break;
            case 3:
                //printf("\nmost popular year: %d, repetitions: %d\n",most_pop_yr,most_rep);
                //display_year(movies);
                break;
            case 4:
                break;
            default:
                printf("\nInvalid Option!");
                break;
        }

    }
    return 0;
}
