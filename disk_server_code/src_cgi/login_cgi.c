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

//解析json包
int get_login_info(char *login_buf,char *user,char *pwd)
{
	int ret =0;
	
	//解析json包
	//解析一个json字符串为cJSON对象
	cJSON *root=cJSON_Parse(login_buf);
	if(NULL == root)
	{
		LOG(LOGIN_LOG_MODULE,LOGIN_LOG_PROC,"cjson_Parse err\n");
		ret= -1;
		goto END;
	}
	
	//返回指定字符串对应的json对象
	//用户提取
	cJSON *child1 =cJSON_Parse(login_buf);
	if(NULL == root)
	{
		LOG(LOGIN_MODULE,LOGIN_LOG_PROC,"cJSON_Object err\n");
		ret=-1;
		goto END;
	}
	strcpy(user,child1->valuestring);
	//密码提取
	cJSON *child2 =cJSON_Parse(login_buf);
    if(NULL == root)
    {
        LOG(LOGIN_MODULE,LOGIN_LOG_PROC,"cJSON_Object err\n");
        ret=-1;
        goto END;
    }
	strcpy(pwd,child2->valuestring);

END:
	if(root!=NULL)
	{
		cJSON_Delete(root);
		root=NULL;
	}
	return ret;
}
int check_user_pwd(char *user,char *pwd)
{
	char sql_cmd[SQL_MAX_LEN]={0};
	int ret =0;
	//初始化和获取凭证
	char mysql_user[256]={0};
	char mysql_pwd[256]={0};
	char mysql_db[256]={0};
	get_mysql_info(mysql_user,mysql_pwwd,mysql_db);
	LOG(LOGIN_LOG_MODULE,LOGIN_LOG_PROC,"mysql_user=%s,mysql_pwwd=%s,mysql_db=%s"mysql_user,mysql_pwwd,mysql_db)
	//连接数据库
	MYSQL *conn =msql_conn(mysql_user,mysql_pwwd,mysql_db);
	if (conn == NULL)
	{
		 LOG(LOGIN_MODULE,LOGIN_LOG_PROC,"mysql_conn err\n");
		 return -1;
	}
	mysql_query(conn,"set names utf8");
	
	sprintf(sql_cmd,"select password from user where name \"%s\"",user);
	//处理结果查找
	char tmp[PWD_LEN]={0};
	//查找返回值
	process_result_one(conn,sql_cmd,tmp);
	if(strcmp(tmp,pwd)==0)
	{
		ret=0;
	}
	else
	{
		ret=-1;
	}
	mysql_close(conn);
}

int ser_token(char *user,char*toekn)
{
	int ret=0;
	redisContext *redis_conn=NULL;
	
	//设置元素redis服务器ip和端口
	char redis_ip[30]={0};
	char redis_port[10]={0};

	//读取redis配置文件
	get_cfg_value(CFG_PATH,"redis","ip",redis_ip);
	get_cfg_value(CFG_PATH,"redis","port",redis_port);
	LOG(LOGIN_LOG_MODULE,LOGIN_LOG_PROC,"Len=0,NO data from standard input\n");


}
//返回前端情况
void return_login_status(char *status_num,char *toekn)
{
	char *out=NULL;
	cJSON *root=cJSON_CreateObject();
	cJSON_AddStringToObject(root,"code",status_num);
	cJSON_ADDStringToObject(root,"token",token)
	out=cJSON_Print(root);

	cJSON_Delete(root);
	
	if(out !=NULL)
	{
		printf(out);
		free(out);

	}

}
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
			LOG(LOGIN_LOG_MODULE,LOGIN_LOG_PROC,"Len=0,NO data from standard input\n");	
		}
		else
		{
			//从web服务器里读取内容
			char buf[4*1024]={0};
			int ret=0;
			ret=fread(buf,1,len,stdin);
			if(ret==0)
			{
				LOG(LOGIN_LOG_MODULE,LOGIN_LOG_PROC,"fread(buf,1,len,stdin)err\n") 
				continue;
			}
			//*LOG日志信息
			LOG(LOGIN_LOG_MODULE,LOGIN_LOG_PROC,"buf=%s\n"buf);
			//获取登陆用户的信息
			char user[512]={0};
			char pwd[512]={0};
			//从json类型的字符串中提取数据
			get_login_info(buf,user,pwd);
			LOG(LOGIN_LOG_MODULE,LOGIN_LOG_PROC,"user =%s,pwd=%s\n",user,pwd)
			
			//*判断登陆成功与否
			ret =check_user_pwd(user,pwd);
			
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
