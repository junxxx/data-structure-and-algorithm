#ifndef _COMMON_HEADER_FILE_H
#define _COMMON_HEADER_FILE_H
#endif
#ifndef OK 
#define OK 1
#endif
#ifndef ERROR
#define ERROR 0
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#define MAXSIZE 1024
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int get_integer(char *);

int is_prime(int);

void FatalError(char *);

void Error(char *);

int NextPrime(int prime);
