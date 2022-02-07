#ifndef ARGUMENTS_H_INCLUDED
#define ARGUMENTS_H_INCLUDED
#define VERSION "xorfile version 1.0.1"
#define min_num(a,b) ((a)<=(b)?(a):(b))

extern unsigned int n;                             //自定义需要异或的字节数，为0则不以此为标准
extern unsigned short int min,max;
extern char * file_name1,* file_name2,* file_name3;

void error();
void usage();
int para(const int argc,const char * argv[]);


#endif // ARGUMENTS_H_INCLUDED

