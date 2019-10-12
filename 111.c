#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
main()
{
int p[2],pid;
char buff[10]="hello";
char buff1[10],buff2[20];
pipe(p);
pid=fork();
if(pid==-1)
{
perror("fork area");
}
if(pid==0)
{
write(p[1],buff,sizeof(buff));
sleep(2);
read(p[0],buff2,sizeof(buff2));
printf("child read as string %s",buff2);
}
else
{
sleep(1);
read(p[0],buff1,sizeof(buff1));
printf("child process read as string %s",buff1);
strcpy(buff1,"hai");
write(p[1],buff1,sizeof(buff2));
}
}
