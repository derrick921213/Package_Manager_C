#include "../headers/File.h"
int PathExists(const char* path) {
    struct stat info;
    if (stat(path, &info) == 0) return 1 ;else return 0;
}

int DirectoryExists(const char* path) {
    struct stat info;
    return stat(path, &info) == 0 && (info.st_mode & S_IFDIR);
}

void GetType(const char* filename,char* result){
    struct stat stat_buf;
    if (lstat(filename, &stat_buf) != 0) {
        strcpy(result,"ERROR");
    }
    if (S_ISDIR(stat_buf.st_mode) != 0) {
        strcpy(result,"DIR");
    } 
    else if (S_ISREG(stat_buf.st_mode) != 0) {
        strcpy(result,"FILE");
    } 
    else {
        strcpy(result,"ERROR");
    }
}

int CreateDir(const char* dir) {
    int ret = mkdir(dir, 0777);
    if (ret != 0) {
        return -1;
    }
    return 0;
}

int Delete(const char* filename) {
    if (PathExists(filename) != 1) {
        return 0;
    }
    char result[15];
    GetType(filename, &result[0]);
    
    if (strcmp(result,"ERROR") == 0) {
        return -1;
    }
    if (strcmp(result,"FILE") == 0) {
        if (remove(filename) != 0) {
            return -1;
        }
        return 0;
    }
    if (strcmp(result,"DIR") == 0) {
        if (remove(filename) != 0) {
            return -1;
        }
        return 0;
    }
  return -1;
}