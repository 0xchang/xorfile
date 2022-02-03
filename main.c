#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#define N 1024*1024*10
#define M 50
#define min(a,b) ((a)<(b)?(a):(b))

int main(int argc,char * argv[])
{
    #if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
        printf("[+]Windows\n");
    #elif defined(__linux__)
        printf("[+]Linux\n");
    #else
        printf("[+]other os\n");
    #endif
    int begin,end;
    unsigned int i=0;
    unsigned int len1=0,len2=0;
    char filename1[M]={0};
    char filename2[M]={0};
    char filename3[]="xor.file";
    FILE *file1=NULL;
    FILE *file2=NULL;
    FILE *file3=NULL;
    unsigned char *buf1=NULL,*buf2=NULL,*buf3=NULL;
    begin=clock();
    if (argc == 3)
    {
        strcpy(filename1,argv[1]);
        strcpy(filename2,argv[2]);
    }
    else
    {
        printf("[+]Usage: %s  file1  file2\n[+]The size of a single file shall not exceed 10M\n",argv[0]);
        return 0;
    }
    file1=fopen(filename1,"rb"),file2=fopen(filename2,"rb"),file3=fopen(filename3,"wb");
    if(file1 == NULL &&file2==NULL&&file3==NULL)
    {
        perror("open failed!");
        exit(1);
    }
    buf1=(unsigned char *)malloc(N);
    buf2=(unsigned char *)malloc(N);
    buf3=(unsigned char *)malloc(N);
    len1=fread(buf1,1,N,file1);
    len2=fread(buf2,1,N,file2);
    printf("[+]Working!\n[+]%s size: %dbytes\n[+]%s size: %dbytes\n",filename1,len1,filename2,len2);
    for(i=0;i<min(len1,len2);i++){
        buf3[i]=buf1[i]^buf2[i];
    }
    fwrite(buf3,1,min(len1,len2),file3);
    fclose(file1),fclose(file2),fclose(file3);
    free(buf1),buf1=NULL;
    free(buf2),buf2=NULL;
    free(buf3),buf3=NULL;
    end=clock();
    printf("[+]Time: %dms\n[+]Out file: ./xor.file\n[+]File size:%d Bytes",end-begin,min(len1,len2));
    return 0;
}
