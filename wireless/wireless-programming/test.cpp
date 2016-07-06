#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/wireless.h>
#include <iostream>

using namespace std;

#define IW_INTERFACE "wlan0"
extern int errno;
struct iwreq wreq;

int main (void) {
    int i;
    int sockfd;
    memset(&wreq, 0, sizeof(struct iwreq));
    sprintf(wreq.ifr_name, IW_INTERFACE);

    /*create a socket to get info from ioctl*/
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        //fprintf(stderr, "Cannot open socket \n");
        //fprintf(stderr, "errno = %d \n", errno);
        //fprintf(stderr, "Error description is : %s\n",strerror(errno));
        perror("Cannot creat socket,error");
        exit(1);
    } else {
        printf("Socket opened successfully \n");
    }

    /*create a socket to get info from ioctl*/
    char buffer[32];
    memset(buffer, 0, 32);
    wreq.u.essid.pointer = buffer;//if not write these codes , the program maybe wrong.
    wreq.u.essid.length = 32;
    /*get ESSID from ioctl*/
    if (ioctl(sockfd,SIOCGIWESSID, &wreq) == -1) {
        perror("IOCTL SIOCGIWESSID Failed,error");
        exit(2);
    } else {
        printf("IOCTL SIOCGIWESSID Successfull\n");
    }

    /*get ESSID from ioctl*/
    /*output current connecting essid*/
    printf("%s\n",wreq.u.essid.pointer);
    /*output current connecting essid*/
    /*get AP info from ioctl*/
    if (ioctl(sockfd,SIOCGIWAP, &wreq) == -1) {
        perror("IOCTL SIOCGIWAP Failed,error");
        exit(2);
    } else {
        printf("IOCTL SIOCGIWAP Successfull\n");
    }
    /*get AP info from ioctl*/
    /* output current connecting AP MAC*/
    for (i = 0; i < 6; i++) {
        unsigned char *APaddr = (unsigned char *) wreq.u.ap_addr.sa_data;
        printf("%02x", (int) APaddr[i]);//mac[i] means 1 byte ,i.e. 8 bits.
        if (i != 5)
            printf("%c", ':');
         else
            printf("\n");
    }

    return 0;
}

