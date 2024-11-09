/*3. Write a program that compiles above multi-ﬁle project. It runs commands "gcc -c circle.c", "gcc -c square.c", "gcc -c rectangle.c", "gcc -c main.c"
concurrently.
parent
|- child1 (gcc -c circle.c)
|- child2 (gcc -c square.c)
|- child3 (gcc -c rectangle.c)
|- child4 (gcc -c main.c)
wait for all child and check exit status. If all exit status 0 (success), then link
|- child5 (gcc -o program.out circle.o square.o rectangle.o main.o)
wait for child and check exit status. If all exit status 0 (success), then run it.
|- child6 (./program.out)
wait for child and check exit status. Then print child exit status.
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int circle, square, rectangle, main_proc, program, output;
    int s, s1, s2, s3, s4, s5;

    circle = fork();
    if (circle == 0) {
        execlp("gcc", "gcc", "-c", "circle.c", NULL);
        _exit(0);
    }
    square = fork();
    if (square == 0) {
        execlp("gcc", "gcc", "-c", "square.c", NULL);
        _exit(0);
    }
    rectangle = fork();
    if (rectangle == 0) {
        execlp("gcc", "gcc", "-c", "rectangle.c", NULL);
        _exit(0);
    }
    main_proc = fork();
    if (main_proc == 0) {
        execlp("gcc", "gcc", "-c", "main.c", NULL);
        _exit(0);
    }
    waitpid(circle, &s, 0);
    waitpid(square, &s1, 0);
    waitpid(rectangle, &s2, 0);
    waitpid(main_proc, &s3, 0);
    if (WEXITSTATUS(s) == 0 && WEXITSTATUS(s1) == 0 && WEXITSTATUS(s2) == 0 && WEXITSTATUS(s3) == 0) {
        program = fork();
        if (program == 0) {
            execlp("gcc", "gcc", "-o", "program.out", "circle.o", "square.o", "rectangle.o", "main.o", NULL);
            _exit(0);
        }
        waitpid(program, &s4, 0);
        if (WEXITSTATUS(s4) == 0) {
            output = fork();
            if (output == 0) {
                execl("./program.out", "program.out", NULL);
                _exit(0);
            }
            waitpid(output, &s5, 0);
        } else {
            printf("Linking failed with exit status: %d\n", WEXITSTATUS(s4));
        }
    } else {
        printf("Compilation failed\n");
    }
    printf("Child1 exit status: %d\n", WEXITSTATUS(s));
    printf("Child2 exit status: %d\n", WEXITSTATUS(s1));
    printf("Child3 exit status: %d\n", WEXITSTATUS(s2));
    printf("Child4 exit status: %d\n", WEXITSTATUS(s3));
    printf("Child5 exit status: %d\n", WEXITSTATUS(s4));
    printf("Child6 exit status: %d\n", WEXITSTATUS(s5));
    return 0;
}

