#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
int p1[2],p2[2],nbytes;
int childpid,i;
char string[100];
char recvbuff[100],sendbuff[100];
pipe(p1);
pipe(p2);
if((childpid=fork())==-1)
{
perror("fork");
exit(1);
}
if(childpid==0)
{
close(p1[1]);
close(p2[0]);
while(1)
{
nbytes=read(p1[0],recvbuff,sizeof(recvbuff));
for(i=0;i<nbytes;i++)
sendbuff[i]=toupper(recvbuff[i]);
write(p2[1],sendbuff,strlen(sendbuff));
}
exit(0);
}
else
{
close(p2[1]);
close(p1[0]);
printf("enter lines of text\n");
while(fgets(string,100,stdin)!=NULL)
{
write(p1[1],string,strlen(string)+1);
nbytes=read(p2[0],recvbuff,sizeof(recvbuff));
recvbuff[nbytes]='\0';
printf("from child server:received string:%s\n",recvbuff);
}
return(0);
}
}
