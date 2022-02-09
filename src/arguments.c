#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "../include/arguments.h"


unsigned int n=0;
unsigned short int min=0,max=0;
char file_name1[255]={0}, file_name2[255]={0}, file_name3[255]={0};


void error()
{
    printf("You hava an error!\n");
    printf("file1=%s,file2=%s,file3=%s\n",file_name1,file_name2,file_name3);
    printf("\ntry 'xorfile -h' for more information\n");
    exit(1);
}
void usage()
{
    printf("\nUsage:\n"
           "  xorfile -i1 file1 -i2 file2 [-min|-max|-n number] [-o file]\n"
           "  The size of a single file shall not exceed 10M\n\n"
           "Global Options:\n"
           "  -h,--help             Show help.\n"
           "  -V,--version          Show version and exit.\n"
           "  -min                   The number of bytes of XOR is the smaller number of bytes in the two files.\n"
           "  -max                   The number of bytes of XOR is the larger number of bytes in the two files.\n"
           "  -n number              The XOR operation is performed according to the specified number of bytes.\n"
           "  -i1 <file>             The first input file.\n"
           "  -i2 <file>             The second input file.\n"
           "  -o,--output <file>     Specify local output file\n\n");
    exit(0);
}
int para(const int argc,const char * argv[])
{
    unsigned int i=0;
    if(argc==1) usage();
    for(i=1;i<argc;i++)
    {
        if(strcmp("-h",argv[i])==0||strcmp("--help",argv[i])==0) usage();
        else if(strcmp("-V",argv[i])==0||strcmp("--version",argv[i])==0) printf("%s\n",VERSION),exit(0);
        else if(strcmp("-n",argv[i])==0) n=atoi(argv[++i]);
        else if(strcmp("-i1",argv[i])==0)
        {
            ++i<argc?i:error();
            strcpy(file_name1,argv[i]);
        }
        else if(strcmp("-i2",argv[i])==0)
        {
            ++i<argc?i:error();
            strcpy(file_name2,argv[i]);
        }
        else if(strcmp("-o",argv[i])==0||strcmp("--output",argv[i])==0)
        {
            ++i<argc?i:error();
            strcpy(file_name3,argv[i]);
        }
        else if(strcmp("-min",argv[i])==0&&max==0)
        {
            min=1;
        }
        else if(strcmp("-max",argv[i])==0&&min==0)
        {
            max=1;
        }
        else
        {
            printf("\nunknown option: %s\n",argv[i]);
            usage();
        }
    }
    if(file_name1==NULL||file_name2==NULL) error();
    if(file_name3[0]=='\0') strcpy(file_name3,FILE3);
    fflush(stdin);
    return 0;
}


