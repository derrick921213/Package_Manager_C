
#ifndef __File_H__
#define __File_H__
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>

int PathExists(const char* path);
/** Check the file path exists 
 *
 * @param path the file path
 * @returns 1 => exits, 0 => not exists
 */

int DirectoryExists(const char* path);
void GetType(const char* filename,char* result);
int CreateDir(const char* dir);
int Delete(const char* filename);
#endif