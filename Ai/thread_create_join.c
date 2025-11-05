#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<pthread.h>
void *thread_function(void *arg);
int i,j;
int main()
{
//declare
pthread_t a_thread;
pthread_create(&a_thread,NULL,thread_function,NULL);//create thread
pthread_join(a_thread,NULL);//main thread wait korbe
printf("inside main thread\n");
for(i=25;i<30;i++)

{
printf("%d\n",i);
sleep(1);


}}
void *thread_function(void *arg){
printf("inside thread\n");
for(i=5;i<10;i++)

{
printf("%d\n",i);
sleep(1);
}
}
