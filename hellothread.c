#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

void *five_count(void *arg) {
	int *thread_num = arg;
	for (int i = 0; i < 5; i++) {
		printf("thread %d: %d\n", *thread_num, i);
	}
	return NULL;
}

int main(void) {
	pthread_t t1, t2;

	int one = 1;
	int two = 2;

	printf("Launching threads\n");

	if (pthread_create(&t1, NULL, five_count, &one) < 0) {
		fprintf(stderr, "Error creating thread\n");
		exit(1);
	}
	if (pthread_create(&t2, NULL, five_count, &two) < 0) {
		fprintf(stderr, "Error creating thread\n");
		exit(1);
	}

	if (pthread_join(t1, NULL) != 0) {
		fprintf(stderr, "Error joining thread\n");
		exit(1);
	}

	if (pthread_join(t2, NULL) != 0) {
		fprintf(stderr, "Error joining thread\n");
		exit(1);
	}

	printf("Threads complete!\n");

	exit(0);
}
