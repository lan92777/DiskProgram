#include"fcgi_config.h"
#include"fcgi_stdio.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define LOGIN_LOG_MODULE "cgi"
#define LOGIN_LOG_PROC   "login"


int main()
{
	//堵塞等待用户的连接
    while(FCGI_Accept()>=0)
    {
		//从nginx发送的环境变量以获得数据的长度
		char *contentLength=getenv("CONTENT_LENGTH");
  		//设置数据长度定义
        int len;
		//token验证的定义
		char token[128]={0};
		//告诉nginx处理格式
		printf("Content-type:text/html\r\n\r\n");
		//对数据长度进行处理
		if(contentLength==NULL)
		{
			len=0;
		}
		else
		{
			len=atoi(contentLength);
		}
		//对数据长度进行判断
		if(len<=0)
		{
			printf("No data from standard input\n");

			
		}
		else
		{
			;
		}

	}
	return 0;
	
}
