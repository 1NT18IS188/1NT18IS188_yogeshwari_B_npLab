#include<stdio.h>
long int frame1[20];
long int frame2[20];
int n;
void compare(){
int c=0;
int i;
for( i=0;i<n;i++)
	{
		if(frame1[i]==frame2[i])
		{
			c++;
		}
		else
		{
			printf("bytes are received in wrong order");
		}
	}
	if(c==n)
	{
		printf("\n bytes are recived in correct order");
	}
}
void node2_receiver(long int frame[n])
{
	int j;
	printf("\n the  below  are the recieved frames ");
	for(j=0;j<n;j++)
	{frame2[j]=frame[j];
		printf("\n  received frame %d is %d ",j+1,frame[j]);
	}
	compare();
}
void node1_sender(long int frame[n]){
	int i;
	int n1;
	int t_bytes=0;
	for(i=0;i<n;i++)
	{
		int b=0;
		int count=0;
		n1=frame[i];
		while(n1!=0)
		{
		    count++;
			n1=n1/10;
			
		}
		
		printf("\nNumber of bytes in frame %d is %d",i+1,count);
		t_bytes+=count;	
	}
	printf("\n The total number of bytes is %d",t_bytes);
	node2_receiver(frame);
}

void main(){
	int i;
	
	printf("Enter the number of frames ");
	scanf("%d",&n);
	printf("please input the pattern for each frame");
	for(i=0;i<n;i++)
	{   
		scanf("%ld",&frame1[i]);
	}
	for(i=0;i<n;i++)
	{   
		printf("%ld",frame1[i]);
	}
	node1_sender(frame1);	
}
