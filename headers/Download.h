#ifndef __Download_H__
#define __Download_H__
#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
int Download(char *url, const char *outfilename);
#endif