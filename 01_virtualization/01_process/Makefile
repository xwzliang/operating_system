export OMP_NUM_THREADS=16
# If OMP_NUM_THREADS not specified, there are 8 threads by default on my machine
hw_out = hello_world_openmp_parallel.out
hw_c = hello_world_openmp_parallel.c

$(hw_out): $(hw_c)
	gcc -fopenmp -o $@ $(hw_c)

run1: $(hw_out)
	./$(hw_out)
## Output example: (Not deterministic)
# Hello World from thread 4
# Hello World from thread 9
# Hello World from thread 12
# Hello World from thread 1
# Hello World from thread 6
# Hello World from thread 7
# Hello World from thread 2
# Hello World from thread 10
# Hello World from thread 3
# Hello World from thread 5
# Hello World from thread 8
# Hello World from thread 14
# Hello World from thread 11
# Hello World from thread 15
# Hello World from thread 13
# Hello World from thread 0
# There are 16 threads in total

pid_out = pid.out
pid_c = process_id.c
$(pid_out): $(pid_c)
	gcc -o $@ $(pid_c)

run2: $(pid_out)
	./$(pid_out)

fork_out = fork.out
fork_c = fork_process.c
$(fork_out): $(fork_c)
	gcc -o $@ $(fork_c)

run3: $(fork_out)
	./$(fork_out)

signal_out = signals.out
signal_c = signals.c
$(signal_out): $(signal_c)
	gcc -o $@ $(signal_c)
