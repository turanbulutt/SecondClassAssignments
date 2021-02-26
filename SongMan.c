//Ahmet Turan Bulut 2315174
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct Node{
    char id[81];
    char name[81];
    char genre[81];
    char album[81];
    char artist[81];
    char AlbumYear[81];
    char timeAdded[81];
    struct Node *next;
};
struct List {
    struct Node* head;
    struct Node* tail;
    int size;
};
typedef struct List *List;

List InitialiseSongs(){
    List myList=malloc(sizeof(List));
    struct Node *temp;
    temp=malloc(sizeof(struct Node));
    myList->head=temp;                  // BASIC INITIALISES FOR MY MAIN LIST
    myList->tail=temp;
    myList->size=0;
    FILE *filein;
    filein=fopen("SongMan.txt", "r");
    char c;
    int i=0;
    while ((c=fgetc(filein))!=EOF){                                 //BASICALLY I TAKE CHARACTER FROM FILE UNTIL EOF THEN UNTIL SEE ";" ADDING TO ID,NAME...
            i=0;
            temp->next=malloc(sizeof(struct Node));                 //AFTER EACH LINE ICREMENT SIZE +1. I USE DUMMY NODE FOR THIS LIST.
            temp=temp->next;
            temp->next=NULL;
            myList->tail=temp;
            while (c!=';'){
                temp->id[i]=c;
                c=fgetc(filein);
                i++;
            }
            temp->id[i] = '\0';
            i=0;
            c=fgetc(filein);
            while (c!=';'){
                temp->name[i]=c;
                c=fgetc(filein);
                i++;
            }
            temp->name[i] = '\0';
            i=0;
            c=fgetc(filein);
            while (c!=';'){
                temp->genre[i]=c;
                c=fgetc(filein);
                i++;
            }
            temp->genre[i] = '\0';
            i=0;
            c=fgetc(filein);
            while (c!=';'){
                temp->album[i]=c;
                c=fgetc(filein);
                i++;
            }
            temp->album[i] = '\0';
            i=0;
            c=fgetc(filein);
            while (c!=';'){
                temp->artist[i]=c;
                c=fgetc(filein);
                i++;
            }
            temp->artist[i] = '\0';
            i=0;
            c=fgetc(filein);
            while (c!=';'){
                temp->AlbumYear[i]=c;
                c=fgetc(filein);
                i++;
            }
            temp->AlbumYear[i] = '\0';
            i=0;
            c=fgetc(filein);
            while (c!=10 && c!=EOF){
                temp->timeAdded[i]=c;
                c=fgetc(filein);
                i++;
            }
            temp->timeAdded[i] = '\0';
            myList->size+=1;

    }
    fclose(filein);
    return myList;
};
List AddSong(struct Node *temp,List myList){
    myList->tail->next=malloc(sizeof(struct Node));             //FIRST I OPEN MEMORY SIZE FOR NEW NODE THEN PASS THAT NODE AFTER I COPY ALL INFORMATION BY ONE BY
    myList->tail=myList->tail->next;
    strcpy(myList->tail->name,temp->name);
    strcpy(myList->tail->genre,temp->genre);
    strcpy(myList->tail->album,temp->album);
    strcpy(myList->tail->artist,temp->artist);
    strcpy(myList->tail->AlbumYear,temp->AlbumYear);
    strcpy(myList->tail->timeAdded,temp->timeAdded);
    myList->size+=1;
    sprintf(myList->tail->id,"%d",(myList->size));
    return myList;
}
List DeleteSong (int id,List myList){
    struct Node *temp=myList->head->next,*temp2=myList->head->next;                     //I AM USING ID AS CHANGE MY STRING VARIABLE TO THE INTEGER
    int ID,count=0,time=1,n;
    if(id==atoi(myList->tail->id)){                                                     //IF USER WANT TO DELETE LAST NODE OF LIST I TAKE LAST NODE ANOTHER VARIABLE THAN  I CHANGE
        for(n=2;n<myList->size;n++)
            temp=temp->next;                                                            //MY TAIL TO BEFORE THAT NODE THAN I FREE THE NODE. ON THE OTHER HAND IT CHECKS IF THAT NODE EXIST OR NOT
        temp2=temp->next;
        free(temp2);
        temp->next=NULL;                                                                // THAN CONNECT BEFORE NODE TO NEXT NODE AFTER THESE I FREE THAT NODE. 3
        myList->tail=temp;
        myList->size--;
        printf("Song with ID %d has been deleted from your list!!!",id);
        return myList;
    }
    while(temp!=NULL){
        ID=atoi(temp->id);
        if(id==ID){
            count=time;
            break;
        }
        temp=temp->next;
        time++;
    }
    if(!count){
        printf("The unique id  not exist in the songs.\n");
        return myList;
        }
    for(n=2;n<count;n++)
        temp2=temp2->next;
    temp2->next=temp2->next->next;
    free(temp);
    myList->size--;
    printf("Song with ID %d has been deleted from your list!!!",id);
    return myList;

}
void PrintSongs(List myList){
    struct Node *temp=myList->head->next;
    printf("\nSongs in your database:\n-----------------------\n");
    while(temp!=NULL){
        printf("\nID:");
        puts(temp->id);
        printf("Song name:");
        puts(temp->name);
        printf("Song Genre:");
        puts(temp->genre);
        printf("Album Name:");
        puts(temp->album);
        printf("Artist Name:");
        puts(temp->artist);
        printf("Year:");
        puts(temp->AlbumYear);
        printf("Date And Time:");
        puts(temp->timeAdded);
        temp=temp->next;
    }
}
void SearchSongs(List myList){
    int choose;
    char *name,*artist,*genre;
    struct Node *temp=myList->head->next;
    printf("1.Search by song name\n2.Search by artist name\n3.Search by genre\nChoose the search style:");
    scanf("%d",&choose);
    switch(choose){
        case 1:
            fflush(stdin);
            printf("Please enter the name of the song that you want to search:");
            gets(name);
            while(temp!=NULL){
                if(!strcmp(temp->name,name)){
                    printf("ID:");
                    puts(temp->id);
                    printf("Song name:");
                    puts(temp->name);
                    printf("Song genre:");
                    puts(temp->genre);
                    printf("Album name:");
                    puts(temp->album);
                    printf("Artist name");
                    puts(temp->artist);
                    printf("Year:");
                    puts(temp->AlbumYear);
                    printf("Date And Time:");
                    puts(temp->timeAdded);
                }
                temp=temp->next;
            }
            break;
        case 2:
            fflush(stdin);
            printf("Please enter the artist name of the song that you want to search:");
            gets(name);
            printf("HERE");
            while(temp!=NULL){
                printf("HERE");
                if(!strcmp(temp->artist,name)){
                    printf("ID:");
                    puts(temp->id);
                    printf("Song name:");
                    puts(temp->name);
                    printf("Song genre:");
                    puts(temp->genre);
                    printf("Album name:");
                    puts(temp->album);
                    printf("Artist name");
                    puts(temp->artist);
                    printf("Year:");
                    puts(temp->AlbumYear);
                    printf("Date And Time:");
                    puts(temp->timeAdded);
                }
                temp=temp->next;
            }
            break;
        case 3:
            fflush(stdin);
            printf("Please enter the genre of the song that you want to search:");
            gets(genre);
            while(temp!=NULL){
                if(!strcmp(temp->genre,genre)){
                    printf("ID:");
                    puts(temp->id);
                    printf("Song name:");
                    puts(temp->name);
                    printf("Song genre:");
                    puts(temp->genre);
                    printf("Album name:");
                    puts(temp->album);
                    printf("Artist name");
                    puts(temp->artist);
                    printf("Year:");
                    puts(temp->AlbumYear);
                    printf("Date And Time:");
                    puts(temp->timeAdded);
                }
                temp=temp->next;
            }
            break;
        default:
            printf("You enter wrong key, please try again\n");
    }
}
void CreatePlayList(List myList,char *song1,char *song2,char *song3,int id){
    struct Node *temp=myList->head->next,*temp2=myList->head->next;
    int check1=0,check2=0,check3=0;
    while(temp!=NULL){
        if(!strcmp(song1,temp->name))
            check1=1;
        else if(!strcmp(song2,temp->name))
            check2=1;
        else if(!strcmp(song3,temp->name))
            check3=1;
        temp=temp->next;
    }
    if(check1==1 && check2==1 && check3==1){
        FILE *myFile;
        char ID,*playlist;
        sprintf(ID,"%d",id);
        strcpy(playlist,"PlayList-");
        strcat(playlist,ID);
        strcat(playlist,".txt");
        myFile=fopen(playlist,"w");
        while(temp2!=NULL){
            if(!strcmp(song1,temp2->name) || !strcmp(song2,temp2->name) || !strcmp(song3,temp2->name)){
                fputs(temp2->id,myFile);
                fputs(temp2->name,myFile);
                fputs(temp2->genre,myFile);
                fputs(temp2->album,myFile);
                fputs(temp2->artist,myFile);
                fputs(temp2->AlbumYear,myFile);
                fputs(temp2->timeAdded,myFile);
            }
            temp2=temp2->next;
        }
        fclose(myFile);
        printf("The playList has been created and stored in the file: PlayList-%d.txt!",id);
    }
    else
        printf("The playList cannot be created! Not all songs found!!!\n");
}

int main(){
   List mylist;
   time_t rawtime;
    struct tm * timeinfo;
   struct Node *temp,*temp2;
   temp=malloc(sizeof(struct Node));
   mylist=InitialiseSongs();
   int n=0,choose=0,id=1;
   char *song1,*song2,*song3;
   while(choose!=6){
        fflush(stdin);
        printf("\n-----MENU-----\n1.Add Song\n2.Delete Song\n3.Print Songs\n4.Search Songs\n5.Create PlayList\n6.Exit\nEnter command:");
        scanf("%d",&choose);
        fflush(stdin);
        switch(choose){
    case 1:
        printf("Enter the name of the song:");
        gets(temp->name);
        printf("Enter the genre of the song:");
        gets(temp->genre);
        printf("Enter the album name of the song:");
        gets(temp->album);
        printf("Enter the artist name of the song:");
        gets(temp->artist);
        printf("Enter the release date of the song:");
        gets(temp->AlbumYear);
        printf("Enter the album name of the song:");
        gets(temp->album);
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        strcpy(temp->timeAdded,asctime(timeinfo));
        temp->next=NULL;
        mylist=AddSong(temp,mylist);
        break;
    case 2:
        printf("enter unique id:");
        int id;
        scanf("%d",&id);
        mylist=DeleteSong(id,mylist);
        break;
    case 3:
        puts(mylist->head->next->id);
        PrintSongs(mylist);
        break;
    case 4:
        SearchSongs(mylist);
        break;
    case 5:
        printf("Enter the names of songs for your playlist:\nEnter (1) song name:");
        gets(song1);
        printf("Enter (2) song name:");
        gets(song2);
        printf("Enter (3) song name:");
        gets(song3);
        CreatePlayList(mylist,song1,song2,song3,id);
        }


   }
   FILE *myFile=fopen("SongMan.txt","w");
   temp2=mylist->head->next;
   while(temp2!=NULL){
        fputs(temp2->id,myFile);
        fprintf(myFile,";");
        fputs(temp2->name,myFile);
        fprintf(myFile,";");
        fputs(temp2->genre,myFile);
        fprintf(myFile,";");
        fputs(temp2->album,myFile);
        fprintf(myFile,";");
        fputs(temp2->artist,myFile);
        fprintf(myFile,";");
        fputs(temp2->AlbumYear,myFile);
        fprintf(myFile,";");
        fputs(temp2->timeAdded,myFile);
        fprintf(myFile,"\n");
        temp2=temp2->next;
   }
   printf("The SonMan.txt file has been updated successfully!! \nGoodbye");

   return 0;
}
