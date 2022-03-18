#include<stdio.h>

struct str{
	char fruits[10];
};

int push(struct str color[],int n,int front,int rear){
	if(rear==n-1&&front==0){
		printf("Stack OverFlow(Full)\n");
	}
	else if(rear+1==front){
		printf("Stack OverFlow(Full)\n");
	}
	else{
		if(front==-1 && rear==-1){
		// condition to check queue is empty
        	front=0;
        	rear=0;
        	printf("Enter the value: ");
        	int temp;
        	char element[10];
			scanf("%d",&temp);
        	gets(color[rear].fruits);
			return -2;
    	}
		if(rear==n-1){
			rear=-1;
		}
		rear++;
		printf("Enter the value: ");
       	int temp;
       	char element[10];
		scanf("%d",&temp);
        gets(color[rear].fruits);
	}
	return rear;
}

int pop(int rear,int front,int n){
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

void display(struct str color[],int front,int rear,int n)  
{
    if(front==-1 && rear==-1)  
    {  
        printf("\n Queue is empty...\n");  
    }
    printf("\nElements in a Queue are: ");
    if(front==rear){
    	printf("%s ",color[rear].fruits);
	}
    else if(front<rear){
        while(rear>=front){
            printf("%s, ",color[front].fruits);
            front++;
        }
    }
    else if(front>rear){
        for(int i=front;i<=n-1;i++){
            printf("%s, ",color[i].fruits);
        }
        for(int i=0;i<=rear;i++){
            printf("%s, ",color[i].fruits);
        }
	}
    printf("\n");
}  

int main(){
	int front=-1,rear=-1,n;
	printf("Enter the size of Queue: ");
	scanf("%d",&n);
	struct str color[n];
	printf("How many initial elements are there?\n: ");
	int Ini_element;
	scanf("%d",&Ini_element);
	for(int i=0;i<Ini_element;i++){
		int temp;
		printf("Enter the color: ");
		scanf("%d",&temp);
		gets(color[i].fruits);
		front=0;
		rear++;
		printf("%s\n",color[i].fruits);
	}
	int choise;
	do{
		int Pu_Po;
		printf("Enter your choise\nPush - 1\nPop - 2\n: ");
		scanf("%d",&Pu_Po);
		if(Pu_Po==1){
			rear=push(color,n,front,rear);
			if(rear==-2){
				front=0;
				rear=0;
			}
			printf("\n\tThe front is: %d, The rear is: %d\n",front,rear);
			display(color,front,rear,n);
		}
		else if(Pu_Po==2){
			front=pop(rear,front,n);
			if(front==-2){
				front=-1;
				rear=-1;
			}
			printf("\n\tThe front is: %d, The rear is: %d\n",front,rear);			
			display(color,front,rear,n);
		}
		else{
			printf("!!Wrong Choise!!");
		}
		printf("Do you want to continue press 1:");
		scanf("%d",&choise);
	}while(choise==1);	
}
