#include <stdio.h> 
#include <stdlib.h>
int main( void )
{
    FILE *fp,*tf;
    int file_size;
    char *str;
    
    fp = fopen("F:\\documents\\My Clippings.txt" , "r");
   	if(fp==NULL)
   	{
  		printf("open F:\\documents\\My Clippings.txt failed.");
   		exit(-1);
    }
    
		 
    fseek( fp , 0 , SEEK_END );
    file_size = ftell(fp);
    fseek( fp , 0 , SEEK_SET);
   
    if((str=(char*)malloc(file_size*sizeof(char)))==NULL)
    {
    	printf("memory alloction failed.");
		exit(-1);	
    }
    
	if(!(fread(str,sizeof(char), file_size, fp)))
	{
		puts("read file failed");
		exit(-1);
	}
	
    printf("%s\n",str);
    
    tf=fopen("D:\\kindleClippings.txt","w+");
    if(tf==NULL)
    {
    	puts("open or create file in D:\\kindleClippings.txt failed.");
    	exit(-1);
    }
    if(fprintf(tf,str))
    {
    	
     	printf("export successfully.\ncheck it in D:\\kindleClippings.txt");    	
    }
	fclose(fp);
    return 0;
}
