#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>
#define SIZE 10
int *shm=0;
struct sembuff
{
int sem_num;
int sem_op;
int sem_fig;
};
int accessmem(int semid)
{
struct sembuff sop;
sop.sem_num=0;
sop.sem_op=1;
sop.sem_fig=0;
semop(semid,&sop,1);
(*shm)++;
printf("\t integer variable =%d",(*shm));
sop.sem_num=0;
sop.sem_op=1;
sop.sem_fig=0;
semop(semid,&sop,1);
(*shm)++;
}
int main()
{
int shmid;
int semid;
char *shm1;
shmid=shmget((key_t)10,sizeof(int),IPC_CREAT|0666);
shm1=shmat(shmid,(void *)0,0);
semid=semget((key_t)10,1,IPC_CREAT|0666);
printf("%d",shmid);
shm=(int *)shm1;
if(fork()==0)
{
int i=0;
while(i<5)
{
sleep(1);
printf("\n child process uses shared memory");
accessmem(semid);
i++;
}
}
else
{
int j=0;
while(j<5)
{
	sleep(1);
	printf("\n parent uses shared memory");
	accessmem(semid);
j++;
}
}
shmctl(shmid,IPC_RMID,0);
}
