#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define FORK_DEPTH 3

main() {
    int i, r;
    pid_t my_pid;

    // Get the process ID of the current process (parent)
    my_pid = getpid();

    // Loop to create child processes
    for (i = 1; i <= FORK_DEPTH; i++) {
        // Fork a new process
        r = fork();

        if (r > 0) {
            // In the parent process after successfully forking a child
            printf("Parent process %d forked child process %d\n", my_pid, r);
        } else if (r == 0) {
            // In the child process, so update my_pid
            my_pid = getpid();

            // Run /bin/echo if we are at the maximum depth, otherwise continue the loop
            if (i == FORK_DEPTH) {
                // Execute /bin/echo with "Hello World" argument
                r = execl("/bin/echo", "/bin/echo", "Hello World", NULL);

                // We never expect to get here, just bail out if execl fails
                exit(1);
            }
        } else { /* r < 0 */
            // Unexpected failure, just bail ungracefully
            exit(1);
        }
    }
}
