#---------------元素定义----------------
#使用的编译器
CC=gcc
#预处理参数
CPPLFAGS=-I./include                 \
		 -I/usr/include/fastdfs      \
		 -I/usr/include/fastcoomon   \
		 -I/usr/local/include/hiredis/\
		 -I/usr/include/mysql/       

#设置生成链接文件时的编译器模式
CFLAGS=-Wall

#链接使需要的动态库
LIBS=-lfdfsclient   \
	 -lfastcommon   \
	 -lhiredis      \
	 -lfcgi         \
	 -lm            \
	 -lmysqlclient


#设置目录路径
COMMON_PATH=common
TEST_PATH=test
CGI_BIN_PATH=bin_cgi
CGI_SRC_PATH=src_cgi

#设置最终文件的路径
login=$(CGI_BIN_PATH)/login
register=$(CGI_BIN_PATH)/register
md5=$(CGI_BIN_PATH)/md5


#目标-用于清理文件
target=$(login)    \
       $(register) \
	   $(md5) 


#------------------操作-----------------
$(login):   $(CGI_SRC_PATH)/login_cgi.o \
            $(COMMON_PATH)/make_log.o  \
            $(COMMON_PATH)/cJSON.o \
            $(COMMON_PATH)/deal_mysql.o \
            $(COMMON_PATH)/redis_op.o  \
            $(COMMON_PATH)/cfg.o \
            $(COMMON_PATH)/util_cgi.o \
            $(COMMON_PATH)/des.o \
            $(COMMON_PATH)/base64.o \
            $(COMMON_PATH)/md5.o
	$(CC) $^ -o $@ $(LIBS)

$(register):    $(CGI_SRC_PATH)/reg_cgi.o \
                $(COMMON_PATH)/make_log.o  \
                $(COMMON_PATH)/util_cgi.o \
                $(COMMON_PATH)/cJSON.o \
                $(COMMON_PATH)/deal_mysql.o \
                $(COMMON_PATH)/redis_op.o  \
                $(COMMON_PATH)/cfg.o
	$(CC) $^ -o $@ $(LIBS)
$(md5):     $(CGI_SRC_PATH)/md5_cgi.o \
            $(COMMON_PATH)/make_log.o  \
            $(COMMON_PATH)/util_cgi.o \
            $(COMMON_PATH)/cJSON.o \
            $(COMMON_PATH)/deal_mysql.o \
            $(COMMON_PATH)/redis_op.o  \
            $(COMMON_PATH)/cfg.o
	$(CC) $^ -o $@ $(LIBS)

#-----------------规则-----------------
###################

#.o文件生成(用于生成链接文件)
%.o: %.c
	$(CC) -c $< -o $@ $(CPPLFAGS) $(CFLAGS)


#项目清理
clean:
	-rm -rf *.o $(target)  $(CGI_SRC_PATH)/*.o $(COMMON_PATH)/*.o

#防止伪文件
.PHONY:clean ALL


###################




























































































