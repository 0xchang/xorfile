// version: 1.0.1
// time: 2022/2/7
// author: 0xchang
#include <stdio.h>
#include<stdlib.h>
#include <time.h>

#include "arguments.h"
#include "xor.h"

int main(const int argc,const char * argv[])
{
    int begin,end;
    unsigned int size_n;
    begin=clock();
    para(argc,argv);
    size_n=xor_file();
    end=clock();
    printf("Time: %dms\nOut file: %s\nFile size:%d Bytes\n",end-begin,file_name3,size_n);
    return 0;
}
