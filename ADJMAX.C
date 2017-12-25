#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>
#define PF printf
#define SF scanf
void insedge();
void deledge();
void dis();
void create();
int n;
int adj[100][100];
void main()
{
int ch,i;
  while(1)
  {
   clrscr();
  // PF(".............................SINGLY LINKED LIST.........................");
   PF("\nPRESS 1:    CREATE\nPRESS 2:     INSERT EDGE\nPRESS 3:     DELETE EDGE\nPRESS 4:    DISPLAY\nPRESS 0:     EXIT");
   PF("\nENTER YOUR CHOICE:");
   SF("%d",&ch);
   switch(ch)
   {
     case 0:exit(0);
     case 1:create();   break;

     case 2:insedge();       break;
     case 3:deledge();    break;
     case 4:dis();    break;
     default:PF("\nWrong Choice");
   }
     getch();
  }
 }
void create()
{
 int i,s,d,j;

 PF("\nENTER NO. OF VERTICES:");
 SF("%d",&n);
  for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
    adj[i][j]=0;
  }
 }

 for(i=1;i<=n*(n-1);i++)
 {
   PF("\nENTER EDGE(-1 -1 TO TERMINATE)");
   SF("%d%d",&s,&d);

   if(s==-1 && d==-1)
    break;
  else if(s>=n || d>=n || s<0 ||d<0)
   {
    PF("\nINVALID EGDE");
    i--;
   }
   else
    adj[s][d]=1;
 }
}
void insedge()
{
 int s,d;
 PF("\nENTER EDGE TO BE INSERTED");
 SF("%d%d",&s,&d);
 if(s<0 || s>=n)
 {
   PF("\nSOURCE VERTEX DOESNT FOUND");
   return;
 }
 if(d<0 || d>=n)
 {
    PF("\nDEST VERTEX DOESNT FOUND");
   return;
 }
 adj[s][d]=1;
}
void deledge()
{
 int s,d;
 PF("\nENTER EDGE TO BE DELETED:");
 SF("%d%d",&s,&d);
 if(s<0 || s>=n || d>=n ||d<0)
 {
  PF("\nEDGE DOESNT EXIST");
  return;
 }
 adj[s][d]=0;
}
void dis()
{
 int i,j;
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   PF("%4d",adj[i][j]);
  }
  PF("\n");
 }
}
