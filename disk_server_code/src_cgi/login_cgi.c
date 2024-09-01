/*
 *@file login_cgi.c
 *@brief 登陆后台cgi程序
 *@author lan
 *@versio 1.0
 *@date 2024.9.1
 */

//cgi程序头文件
#include "fcgi_config.h"
#include "fcgi_stdio.h"
//输入输出头文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//程序使用配置头文件
#include "make_log.h"
#include "util_cgi.h"
#include <time.h>
//读取数据库所需要的头文件
#include "deal_mysql.h"
#include "redis_op.h"
//格式化数据所需要的头文件
#include "cJSON"
#include "cfg.h"
//加密所需要的头文件
#include "des.h"
#include "base64.h"
#include "md5.h"




int main()
{
	//堵塞等待用户连接
	while(FCFI_Accept()>=0)
	{
		//接受的含数据长度的字符串数据
		char *contenLength = getenv("CONTENT_LENGTH");
		int len;
		//token变量设置
		char token[128]={0};
		//告诉浏览器什么类型
		printf("Content-type:text/html\r\n\r\n");
		//将字符串数据转变为整数
		if( contenLength ==NULL )
		{
			Len=0;
		}
		else
		{
			len=atoi(contentLength);
		}
		//根据获取的用户信息进行判断
		if(len <=0)
		{
			printf("NO data from standard input.<p>\n");
			//*LOG日志信息	
		}
		else
		{
			//从web服务器里读取内容
			char buf[4*1024]={0};
			int ret=0;
			ret=fread(buf,1,len,stdin);
			if(ret==0)
			{
				//*LOG日志信息
				continue;
			}
			//*LOG日志信息
			
			//获取登陆用户的信息
			char user[512]={0};
			char pwd[512]={0};
			//*将信息从容器里获取
			//*LOG日志信息
			//*判断登陆成功与否
			//登陆成功，生成token
			if(ret==0)
			{
			;
			}
			//返回前端登陆信息
			if(ret == 0)
			{
			
				;
			}
			else
			{
					;
			}
		
		}
	
	}






}
