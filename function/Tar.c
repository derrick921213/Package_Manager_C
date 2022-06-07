#include "../headers/Tar.h"

int Zip(char **src,char *dest,int N)
{
    char command[] = "tar -zcvf";
    char command1[4096] = {0};
    strcat(command1,command);
    strcat(command1, " ");
    strcat(command1,dest);
    for (int i = 0; i < N;i++){
        strcat(command1," ");
        strcat(command1, src[i]);
    }    
    system(command1);
    return 0;
}
int Unzip(char *dest)
{
    char command[] = "tar -zxvf";
    char command1[4096] = {0};
    strcat(command1, command);
    strcat(command1, " ");
    strcat(command1, dest);
    system(command1);
    return 0;
}