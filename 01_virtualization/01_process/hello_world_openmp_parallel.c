#include <stdio.h>
#include <omp.h>

int main() {
	int num_threads, id_thread;

	/* Fork team of threads with private var id_thread */
#pragma omp parallel private(id_thread)
	{
		id_thread = omp_get_thread_num();
		printf("Hello World from thread %d\n", id_thread);
		/* Only master thread does this */
		if (id_thread == 0) {
			num_threads = omp_get_num_threads();
			printf("There are %d threads in total\n", num_threads);
		}
	}	// All threads join master thread and terminate
}
