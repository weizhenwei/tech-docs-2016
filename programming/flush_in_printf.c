#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // setbuf will make printf immediately.
    // setbuf(stdout, NULL);
    
    // by default, stdout is line buffered, 
    // so, what will cause printf flush buffer?
    // 1. call fflush() directly;
    // 2. the content put in buffer containing '\n';
    // 3. buffer is full;
    // 4. get data from buffer, such as call scanf.
    // 3. when program exit;

    printf("Hello, world1");
    sleep(1);
    printf("Hello, world2");
    sleep(1);
    printf("Hello, world3");
    sleep(1);
    printf("Hello, world4");
    sleep(1);
    printf("Hello, world5\n");
    sleep(1);
    printf("Hello, world6");
    fflush(stdout);
    sleep(1);
    printf("Hello, world7");
    sleep(1);
    printf("Hello, world8");
    sleep(1);
    printf("Hello, world9");
    sleep(1);
    printf("Hello, world10");
    sleep(1);
    printf("Hello, world11");
    
    return 0;
}

