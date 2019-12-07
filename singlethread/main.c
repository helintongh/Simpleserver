#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "epoll_server.h"
//指令必须为a.out port path
int main(int argc, const char* argv[])
{
    if(argc < 3)//传入参数不足
    {
        printf("eg: ./a.out port path\n");
        exit(1);
    }

    // 端口,字符串变整型
    int port = atoi(argv[1]);
    // 修改进程的工作目录, 方便后续操作
    int ret = chdir(argv[2]);
    if(ret == -1)
    {
        perror("chdir error");
        exit(1);
    }
    
    // 启动epoll模型 
    epoll_run(port);

    return 0;
}
