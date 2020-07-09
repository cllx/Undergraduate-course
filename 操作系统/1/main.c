#include <unistd.h>
#include <stdio.h>
int main()
{
        pid_t pid; //pid_t ∆‰ µ «int
        pid = getpid();
        printf("the current program's pid is %d\n",pid);
        while(1);
        return 0;
}
