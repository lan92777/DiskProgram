#!/bin/bash


#将需要的nginx配置文件拷贝到nginx.conf的默认目录下
echo
echo ============Copy nginx.conf=================
sudo mv /usr/local/nginx/conf/nginx.conf /usr/local/nginx/conf/nginx.conf.old
sudo cp ./nginx.conf /usr/local/nginx/conf


#关闭再开启fastdfs程序
echo
echo =================fastdfs===================
./fastdfs.sh stop
./fastdfs.sh start


#关闭再启动fastcgi程序
echo
echo ================fastcgi==================
./fcgi.sh  stop
./fcgi.sh  start


#关闭再启动nginx
echo
echo ================nginx===================
./nginx.sh stop
./nginx.sh start



#关闭再启动redis
echo
echo ================redis====================
./redis.sh stop
./redis.sh start
