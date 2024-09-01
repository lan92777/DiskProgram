#!/bin/bash

START=1
STOP=1


case $1 in
	start)
		START=1
		STOP=0
		;;
	stop)
		START=0
		STOP=1
		;;
	*)
		STOP=1
		START=1
		;;
esac

# **********************杀死cgi进程****************
if [ "$STOP" -eq 1 ];then
    # 登录
    kill -9 $(ps aux | grep "./bin_cgi/login" | grep -v grep | awk '{print $2}') > /dev/null 2>&1

	echo "CGI程序已经关闭"
fi

# **********************启动cgi进程***************
if [ "$START" -eq 1 ];then
    # 登录
    echo -n "登录："
    spawn-fcgi -a 127.0.0.1 -p 10000 -f ./bin_cgi/login
	echo  "CGI程序已经启动"
fi

