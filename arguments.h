#ifndef ARGUMENTS_H_INCLUDED
#define ARGUMENTS_H_INCLUDED
#define VERSION "xorfile version 1.0.1"
#define min_num(a,b) ((a)<=(b)?(a):(b))

extern unsigned int n;                             //�Զ�����Ҫ�����ֽ�����Ϊ0���Դ�Ϊ��׼
extern unsigned short int min,max;
extern char * file_name1,* file_name2,* file_name3;

void error();
void usage();
int para(const int argc,const char * argv[]);


#endif // ARGUMENTS_H_INCLUDED

