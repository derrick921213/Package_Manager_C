#include "./headers/Main.h"
int main(int argc,char* args[]){
    printf("%d\n",argc);
    for (int i=0;i<argc;i++){
        printf("%s\n",args[i]);
    }
    // Json("./tmp/test.json","r");
    // Download("http://localhost/aaa.txt","./tmp/bbb.txt");

    char *src[] = {"./tmp/"};
    char *name = "TEST.tgz";
    // Zip(src, name, sizeof(src) / sizeof(src[0]));
    Unzip(name);
    return 0;
}
void TMP(void){
    int test = PathExists("./tmp/main.o");
    int test1 = DirectoryExists("headers");
    char test2[10];
    char test3[10];
    GetType("TEST.txt",&test2[0]);
    GetType("headers",&test3[0]);
    printf("%d %d %s %s",test,test1,test2,test3);
    CreateDir("TEST");
    Delete("TEST");
}