#include<stdio.h>
int push(int Queue[],int n,int front,int rear){
	if(rear==n-1&&front==0){
		printf("Stack OverFlow(Full)\n");
	}
	else if(rear+1==front){
		printf("Stack OverFlow(Full)\n");
	}
	else{
		int element;
		if(front==-1 && rear==-1){
		// condition to check queue is empty
        	front=0;
        	rear=0;
        	printf("Enter the value: ");
			scanf("%d",&element);
			Queue[rear]=element;
			return -2;
    	}
		printf("Enter the value: ");
		scanf("%d",&element);
		if(rear==n-1){
			rear=-1;
		}
		rear++;
		Queue[rear]=element;
	}
	return rear;
}

int pop(int Queue[],int rear,int front,int n){
	if(front==-1&&rear==-1){
		printf("Stack UnderFlow(Empty)\n");
	}
	else{
		if(front==rear){
			return -2;
		}
		if(front==n-1){
			front=-1;
		}
		front++;
	}
	return front;
}

void display(int queue[],int front,int rear,int n)  
{
    if(front==-1 && rear==-1)  
    {  
        printf("\n Queue is empty...\n");  
    }
    printf("\nElements in a Queue are: ");
    if(front==rear){
    	printf("%d",queue[rear]);
	}
    else if(front<rear){
        while(rear>=front){
            printf("%d,", queue[front]);
            front++;
        }
    }
    else if(front>rear){
        for(int i=front;i<=n-1;i++){
            printf("%d,", queue[i]);
        }
        for(int i=0;i<=rear;i++){
            printf("%d,", queue[i]);
        }
	}
    printf("\n");
}  

int main(){
	int front=-1,rear=-1,n;
	printf("Enter the size of Queue: ");
	scanf("%d",&n);
	int Queue[n];
	printf("How many initial elements are there?\n: ");
	int Ini_element;
	scanf("%d",&Ini_element);
	for(int i=0;i<Ini_element;i++){
		scanf("%d",&Queue[i]);
		front=0;
		rear++;
	}
	int choise;
	do{
		int Pu_Po;
		printf("Enter your choise\nPush - 1\nPop - 2\n: ");
		scanf("%d",&Pu_Po);
		if(Pu_Po==1){
			rear=push(Queue,n,front,rear);
			if(rear==-2){
				front=0;
				rear=0;
			}
			printf("\n\tThe front is: %d, The rear is: %d\n",front,rear);
			display(Queue,front,rear,n);
		}
		else if(Pu_Po==2){
			front=pop(Queue,rear,front,n);
			if(front==-2){
				front=-1;
				rear=-1;
			}
			printf("\n\tThe front is: %d, The rear is: %d\n",front,rear);			
			display(Queue,front,rear,n);
		}
		else{
			printf("!!Wrong Choise!!");
		}
		printf("Do you want to continue press 1:");
		scanf("%d",&choise);
	}while(choise==1);	
}
