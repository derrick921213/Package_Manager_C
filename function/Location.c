#include <unistd.h>
#include <stdio.h>
int main()
{
    chdir("/tmp");
    printf("current working directory: %s\n", getcwd(NULL, 0));
}