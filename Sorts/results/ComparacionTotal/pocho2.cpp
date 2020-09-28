#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define MAX_LEN 10

struct region{
    int len;
    char buf[MAX_LEN];
};

int main()
{    
    struct region* rptr[MAX_LEN];
    int fd;
    fd = shm_open("/myregion",O_CREAT| O_RDWR, S_IRUSR | S_IWUSR);


    if(fd == -1){
        printf("shared memory failed\n");
		exit(-1);
    }
    if(ftruncate(fd,sizeof(struct region)) == -1){
        printf("shared memory failed\n");
        exit(-1);
    }
    for(int i = 0; i< MAX_LEN ; i++){
        rptr[i] = mmap(NULL,sizeof(struct region), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    }
    for(int i = 0; i< MAX_LEN ; i++){
        if (rptr[i] == MAP_FAILED) {
            printf("Map failed\n");
            return -1;
        }
    }

    //struct region buffer[MAX_LEN];
    int in = 0;
    int out = MAX_LEN-1;
    struct region next_producer;
    
   // while (1)
   // {   
        pid_t pid;
        pid = fork();
        
        if (pid < 0) { /* error occurred */
            fprintf(stderr, "Fork Failed");
            return 1;
        }
        else if (pid == 0) {
            time_t iTotal_seconds = time(0);
            struct tm *ptm = localtime((const time_t *) & iTotal_seconds);
            char tiempo[8];
            strftime(tiempo, 100, "%H:%M:%S", ptm);

            next_producer.len = getpid();
            strcpy(next_producer.buf,tiempo);
            
            while (((in+1) % MAX_LEN) ==  out)
            {
                //printf("hola"); 
            }
            memcpy(rptr[in], &next_producer, sizeof next_producer);

            printf("P(%d): Creando Proceso %d [%s]\n",getppid(),getpid(),tiempo);
            //printf("HORAP P(%d): Creando Proceso %d HORAH\n",getppid(),getpid());
            
            printf("Enviando mensage [%d] ,\n", rptr[in]->len);
            printf("Enviando mensage [%s] y durmiendo\n", rptr[in]->buf);
            
            in = (in + 1) % MAX_LEN;
            sleep(5);
            
            
        }
        else { /* parent process */
        /* parent will wait for the child to complete */
            //printf("HORA %d",getpid());
            time_t iTotal_seconds = time(0);
            struct tm *ptm = localtime((const time_t *) & iTotal_seconds);
            char tiempo[8];
            strftime(tiempo, 100, "%H:%M:%S", ptm);
            printf("[%s] ",tiempo);
            sleep(10);
            //wait(NULL);
            //printf("Child Complete\n
        }
    
	return 0;
}
