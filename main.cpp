#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    if (argc != 2) {
        printf("Incorrect input");
        return 0;
    }
    int n = atoi(argv[1]);
    pid_t pid, ppid, chpid;
    chpid = fork();
    if (chpid == -1) {
        printf("Incorrect fork syscall\n");
    } else if (chpid == 0) {
        int ans = 1;
        for (int i = 2; i <= n; ++i) {
            ans *= i;
        }
        printf("Factorial %d\n", ans);
    } else {
        if (n == 0) {
            printf("Fibonacci %d\n", 0);
        }
        int fb1 = 0, fb2 = 1;
        for (int i = 1; i < n; ++i) {
            int tmp = fb1 + fb2;
            fb1 = fb2;
            fb2 = tmp;
        }
        printf("Fibonacci %d\n", fb2);
    }
    return 0;
}
