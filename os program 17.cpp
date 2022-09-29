#include<stdio.h>
#include<conio.h>

int main()
 {
  int page[20],frame[10][2],i=0,j,k=0,l=0,n,num,a,found,pf=0,x,min,ch;
  char c;
  FILE *fp;
  fp=fopen("fifo.txt","r");
   while(fscanf(fp,"%d%c",&a,&c)!=EOF)
      page[i++]=a;
      n=i;

while(1)
 {
   i=0,k=1,found=0;
   printf("\nEnter the frame size:");
       scanf("%d",&num);
   for(i=0;i<num;i++)
    {
       frame[i][0]=0;
       frame[i][1]=-1;
    }

   for(i=0;i<n;i++)
     {
       found=0;
      for(j=0;j<num;j++)
        if(page[i]==frame[j][1])
           {
      found=1;
                 x=j;
                 frame[x][0]=k++; 
           }
        if(found==0)
      {
                   min=n+1;
                   for(j=0;j<num;j++)
                      if(min>frame[j][0])
                        {
                           min=frame[j][0];
                           x=j;
                        }
                 frame[x][1]=page[i];
                 frame[x][0]=k++;
                 pf++; 
     }

    for(l=0;l<num;l++)
      {
       if(frame[l][1]==-1)
         printf("|  ");
      else
         printf("|%d ",frame[l][1]);
      }
    if(found==0)
       printf("Page Fault\n");
    else
        printf("No page fault\n");
      printf("\n\n");
  }
printf("\Total page faults=%d",pf);
pf=0;
printf("\nPress 1 to continue:");
    scanf("%d",&ch);
    
if(ch!=1)
  break;
}
 getch();
}

