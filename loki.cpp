#include<stdio.h>
int main()
{
int n,p[50],minimum,k=1,time_b=0;
int b[20],temp,a[30],waittime[50],turntime[50],turnavg=0,sum=0;
float avg_w=0,avg_t=0,sum_t=0,sum_w=0;
printf("\n Enter the Number of processes :");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
printf("/t Enter the process number");
scanf("%d",&p[i]);

printf("\tEnter the burst time of %d process :",i+1);
scanf(" %d",&b[i]);
printf("\tEnter the arrival time of %d process :",i+1);
scanf(" %d",&a[i]);
}
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if(a[i]<a[j])
{
temp=p[j];
p[j]=p[i];
p[i]=temp;
temp=a[j];
a[j]=a[i];
a[i]=temp;
temp=b[j];
b[j]=b[i];
b[i]=temp;
}
}
}
for(int j=0;j<n;j++)
{
time_b=time_b+b[j];
minimum=b[k];
for(int i=k;i<n;i++)
{
if (time_b>=a[i] &&b[i]<minimum)
{
temp=p[k];
p[k]=p[i];
p[i]=temp;
temp=a[k];
a[k]=a[i];
a[i]=temp;
temp=b[k];
b[k]=b[i];
b[i]=temp;
}
}
k++;
}
waittime[0]=0;
for(int i=1;i<n;i++)
{
sum=sum+b[i-1];
waittime[i]=sum-a[i];
sum_w=sum_w+waittime[i];
}
avg_w=(sum_w/n);
for(int i=0;i<n;i++)
{
turnavg=turnavg+b[i];
turntime[i]=turnavg-a[i];
sum_t=sum_t+turntime[i];
}
avg_w=(sum_t/n);
printf("\n RESULT:-");
printf("\nProcess\t Burst\t Arrival\t Waiting\t Turn-around" );
for(int i=0;i<n;i++)
{
printf("\n p%d\t %d\t %d\t\t %d\t\t\t%d",p[i],b[i],a[i],waittime[i],turntime[i]);
}
printf("\n\nAVERAGE WAITING TIME : %f",avg_w);
printf("\nAVERAGE TURN AROUND TIME : %f",avg_t);
return 0;
}

