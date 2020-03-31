#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
#define NTHREADS 2

time_t t;
int cells [150];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *Randomize(void *n){
	long index =  (long) n;
	//sleep(1);
	pid_t pid;
	long rnd;
	rnd = rand()%1500;
	if(cells[index]==0){
		cells[index] = rnd;
		pthread_mutex_lock(&lock);
	}else if(cells[index]==1){
		cells[index] = -1;
		pthread_mutex_lock(&lock);
	}

	//printf("%d\n",rnd);
}

int main(){
	srand((unsigned) time(&t));
	pthread_t threads[NTHREADS];
	long tcreated, i, rnd;
	for(i = 0; i <NTHREADS; i++){
		rnd = rand()%2;
		//printf("Creando al hilo %i\n", i);
		tcreated = pthread_create(&threads[i], NULL, Randomize, (void *)rnd);
		pthread_join(threads[i], NULL);
	}
	

	int j;
	for(  j = 0; j < 150; j++){
		printf("%d", cells[i]);
	}
	pthread_exit(NULL);
}
