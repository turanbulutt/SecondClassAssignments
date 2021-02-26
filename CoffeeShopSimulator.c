//AHMET TURAN BULUT 2315174
#include <stdio.h>
#include <stdlib.h>
int TIME=1;
struct Node{
    int customerType;
    int ArrivalTime;
    int ServiceTime;
    int ServiceStartTime;
    int RobotID;
    int Coffee;
    int CoffeeSize;
    struct Node *next;
};
struct List{
    struct Node *head;
    struct Node *tail;
    int length;
};
struct List * CreateList(int size){
    struct List *l=malloc(sizeof(struct List));
    if(l==NULL)
        printf("Error while malloc the list!");
    else{
        l->head=malloc(sizeof(struct Node));
        if(l->head==NULL)
            return NULL;
        l->tail=l->head;
        l->length=0;
        return l;
    }
    return 0;
}

struct List*  InsertList(struct List *l,int customerType,int ArrivalTime,int ServiceTime,int ServiceStartTime, int RobotID,int Coffee,int CoffeeSize){
    struct Node *temp=l->head;
    struct Node *newnode;
    newnode=malloc(sizeof(struct Node));
    newnode->ArrivalTime=ArrivalTime;
    newnode->Coffee=Coffee;
    newnode->CoffeeSize=CoffeeSize;
    newnode->customerType=customerType;
    newnode->next=NULL;
    newnode->RobotID=RobotID;
    newnode->ServiceStartTime=ServiceStartTime;
    newnode->ServiceTime=ServiceTime;
    if(l->length==0){
        temp->next=newnode;
        l->tail=newnode;
        l->length++;
    }
    else{
        int count=1;
        while(count<=l->length){
            if(newnode->ArrivalTime<temp->next->ArrivalTime){
                newnode->next=temp->next;
                temp->next=newnode;
                l->length++;
                break;
            }
            else if(temp->next->next==NULL){
                temp->next->next=newnode;
                l->tail=newnode;
                l->length++;
                break;
            }
            temp=temp->next;
            count++;
        }
    }
    return l;
}
void DisplayList(struct List * l,int noCustomers, int noRobots)
{
        struct Node *p=l->head->next;
        float waitingTime=0.0;
        int s1=0,s2=0,s3=0,s4=0,c1=0,c2=0,c3=0,c4=0,max=0;
        printf("Customer Type--Arrival Time--Service Time--Service Start Time--RobotID--Coffee--Coffee Size\n");
        while(p!=NULL){
            if(p->customerType==1)
                printf("Silver\t\t ");
            else if(p->customerType==2)
                printf("Gold\t\t ");
            else
                printf("Platinum\t ");
            printf("%d \t\t%d \t\t%d \t\t%d\t",p->ArrivalTime,p->ServiceTime,p->ServiceStartTime,p->RobotID);
            if(p->Coffee==1){
                printf("Espresso ");
                c1++;
            }
            else if(p->Coffee==2){
                printf("Latte\t ");
                c2++;
            }
            else if(p->Coffee==3){
                printf("Cappuccino ");
                c3++;
            }
            else{
                printf("Americano ");
                c4++;
            }
            if(p->CoffeeSize==1){
                printf("\tShort\n");
                s1++;
            }
            else if(p->CoffeeSize==2){
                printf("\tTall\n");
                s2++;
            }
            else if(p->CoffeeSize==3){
                printf("\tGrande\n");
                s3++;
            }
            else{
                printf("\tVenti\n");
                s4++;
            }
            waitingTime=p->ServiceStartTime-p->ArrivalTime;
            if(max<(p->ServiceStartTime-p->ArrivalTime))
                max=p->ServiceStartTime-p->ArrivalTime;
            p=p->next;
        }
        printf("%d customer served by %d number of robot in %d minute\n",noCustomers,noRobots,TIME);
        printf("Average time that in the queue is %f\n",waitingTime/noCustomers);
        printf("Maximum waiting time is %d\n",max);
        if( c1>=c2 && c1>=c3 && c1>=c4)
            printf("Most popular coffee is Espresso\n");
        else if( c2>=c1 && c2>=c3 && c2>=c4)
            printf("Most popular coffee is Latte\n");
        else if( c3>=c1 && c3>=c2 && c3>=c4)
            printf("Most popular coffee is Cappucino\n");
        else if( c4>=c1 && c4>=c2 && c4>=c3)
            printf("Most popular coffee is Amrericano\n");
        if( s1>=s2 && s1>=s3 && s1>=s4)
            printf("Most popular size is Short\n");
        else if( s2>=s1 && s2>=s3 && s2>=s4)
            printf("Most popular size is Tall\n");
        else if( s3>=s1 && s3>=s2 && s3>=s4)
            printf("Most popular size is Grande\n");
        else if( s4>=s1 && s4>=s2 && s4>=s3)
            printf("Most popular size is Venti\n");

}
struct List* initialiseSimulator(struct List *l,int NoRobot, int NoCustomers){
    int *robots;
    struct Node **RobotsForNodes,*temp;
    struct List *newlist,*Queue;
    newlist=CreateList(NoCustomers);
    Queue=CreateList(NoCustomers);
    robots=malloc(NoRobot*sizeof(int));
    RobotsForNodes=malloc(NoRobot*sizeof(struct Node));
    int i;
    for(i=0;i<NoRobot;i++)
        robots[i]=0;
    int nextTime=1;
    i=0;
    int notavaliableRobots=0;
    while(i<NoCustomers){
        int a;
        for(a=0;a<NoRobot;a++){
            if(robots[a]==TIME){
                InsertList(newlist,RobotsForNodes[a]->customerType,RobotsForNodes[a]->ArrivalTime,RobotsForNodes[a]->ServiceTime,RobotsForNodes[a]->ServiceStartTime,RobotsForNodes[a]->RobotID,RobotsForNodes[a]->Coffee,RobotsForNodes[a]->CoffeeSize);
                i++;
                notavaliableRobots--;
                robots[a]=0;
            }
        }
        if(l->head->next!=NULL &&TIME==l->head->next->ArrivalTime ){
            temp=l->head->next;
            l->head->next=l->head->next->next;
            InsertList(Queue,temp->customerType,temp->ArrivalTime,temp->ServiceTime,temp->ServiceStartTime,temp->RobotID,temp->Coffee,temp->CoffeeSize);
        }
        if(notavaliableRobots!=NoRobot &&Queue->length!=0){
            for(a=0;a<NoRobot;a++){
                if(robots[a]==0){
                    RobotsForNodes[a]=Queue->head->next;
                    Queue->head->next=Queue->head->next->next;
                    Queue->length--;
                    notavaliableRobots++;
                    RobotsForNodes[a]->RobotID=a+1;
                    RobotsForNodes[a]->ServiceStartTime=TIME;
                    robots[a]=RobotsForNodes[a]->ServiceStartTime+RobotsForNodes[a]->ServiceTime;
                    break;
                }
            }
        }
        int min=999;
        for(a=0;a<NoRobot;a++){
            if(robots[a]>0){
                if(l->head->next==NULL && min>robots[a]){
                    min=robots[a];
                    nextTime=robots[a];
                    }
                else if(min>robots[a] && robots[a]<=l->head->next->ArrivalTime){
                    nextTime=robots[a];
                    min=robots[a];
                    }
            }
        }
        if(TIME==nextTime && i!=NoCustomers)
            nextTime=l->head->next->ArrivalTime;
        TIME=nextTime;
    }
    return newlist;
}

int main(int argc, char ** argv)
{
    if(argc==5){
        int NoCustomers=atoi(argv[1]),NoRobots=atoi(argv[2]),maxArrivalTime=atoi(argv[3]),maxServiceTime=atoi(argv[4]);
        int customerType,ArrivalTime,ServiceTime,ServiceStartTime,RobotID,Coffee,CoffeeSize;
        srand(time(0));
        struct List *myList;
        myList=CreateList(NoCustomers);
        int i;
        for(i=0;i<NoCustomers;i++){
            customerType=rand()%3+1;
            ArrivalTime=rand()%maxArrivalTime+1;
            ServiceTime=rand()%maxServiceTime+1;
            ServiceStartTime=0;
            RobotID=0;
            Coffee=rand()%4+1;
            CoffeeSize=rand()%4+1;
            myList=InsertList(myList,customerType,ArrivalTime,ServiceTime,ServiceStartTime,RobotID,Coffee,CoffeeSize);
        }
        myList=initialiseSimulator(myList,NoRobots,NoCustomers);
        DisplayList(myList,NoCustomers,NoRobots);
    }
    else
        printf("You entered wrong number of variable try again!");

    return 0;
}
