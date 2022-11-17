#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

pthread_cond_t cond1;
pthread_cond_t cond2;

void *lock1(void* arg) {
	pthread_mutex_lock(&mutex1);
	pthread_cond_wait(&cond2, &mutex2);
	printf("Thread 1 has aquired one resource and waiting for the second one");
	pthread_mutex_unlock(&mutex1);

}

void *lock2(void* arg) {
	pthread_mutex_lock(&mutex2);
	pthread_cond_wait(&cond1, &mutex1);
	printf("Thread 2 has aquire resource 2 and waiting for first resource");
	pthread_mutex_unlock(&mutex2);
}

int main() {
	pthread_mutex_init(&mutex1, 0);
	pthread_mutex_init(&mutex2, 0);

	pthread_cond_init(&cond1, 0);
	pthread_cond_init(&cond2, 0);

	pthread_t thread1, thread2;
	pthread_create(&thread1, 0, lock1, 0);
	pthread_create(&thread2, 0, lock2, 0);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	pthread_mutex_destroy(&mutex1);
	pthread_mutex_destroy(&mutex2);
	pthread_cond_destroy(&cond1);
	pthread_cond_destroy(&cond2);
}
