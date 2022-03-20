#include <stdio.h>
#include <stdlib.h>
#include "xor.h"
#include "getopt.h"

unsigned int mysize(unsigned int len1,unsigned int len2)
{
    if(n>0) return n;
    else if(max==1) return len1>len2?len1:len2;
    return len1<=len2?len1:len2;
}

unsigned int xor_file()
{
    FILE *file1=NULL,*file2=NULL,*file3=NULL;
    unsigned int len1,len2,i,file_size,small,large;
    unsigned char *buf1=NULL,*buf2=NULL,*buf3=NULL;
    len1=file_len(file_name1),len2=file_len(file_name2);
    if(len1<=len2) small=len1,large=len2;
    else small=len2,large=len1;
    file1=fopen(file_name1,"rb");file2=fopen(file_name2,"rb");
    if(file1 == NULL &&file2==NULL)
    {
        perror("File open failed!");
        exit(1);
    }
    file_size=mysize(len1,len2);
    printf("\nWorking!\nThe size of this file is %d bytes.",file_size);
    buf1=(unsigned char *)malloc(file_size);buf2=(unsigned char *)malloc(file_size);buf3=(unsigned char *)malloc(file_size);
    if(buf1==NULL||buf2==NULL||buf3==NULL)
    {
        printf("error!");
        exit(1);
    }
    fread(buf1,1,file_size,file1),fread(buf2,1,file_size,file2);
    fclose(file1),fclose(file2);
    free(file1),free(file2);
    for(i=0;i<min_num(file_size,small);i++)
    {
        buf3[i]=buf1[i]^buf2[i];
    }
    if(file_size>small&&file_size<=large)
    {
        if(small==len1) for(;i<file_size;i++) buf3[i]=buf2[i];
        else for(;i<file_size;i++) buf3[i]=buf1[i];
    }
    else if (file_size > large)
    {
        if(small==len1) for(;i<large;i++) buf3[i]=buf2[i];
        else for(;i<large;i++) buf3[i]=buf1[i];
        for(;i<file_size;i++) buf3[i]=0x0;
    }
    file3=fopen(file_name3,"wb");
    if(file3==NULL)
    {
        perror("File open failed!");
        exit(1);
    }
    fwrite(buf3,sizeof(unsigned char),file_size,file3);
    fclose(file3);
    free(file3);
    free(buf1),free(buf2),free(buf3);
    buf1=NULL,buf2=NULL,buf3=NULL,file1=NULL,file2=NULL,file3=NULL;
    return file_size;
}

unsigned int file_len(char * filename)
{
    unsigned int i =0;
    FILE * p=NULL;
    p=fopen(filename,"rb");
    if(p==NULL)
    {
        printf("File open failed!\n");
        exit(1);
    }
    fseek(p,0,SEEK_END);
    i=ftell(p);
    fclose(p);
    p=NULL;
    return i;
}
