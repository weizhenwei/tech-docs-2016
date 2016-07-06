#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ifaddrs.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/wireless.h>


bool check_wireless(int fd, const char* ifname, char* protocol) {
    struct iwreq wreq;
    memset(&wreq, 0, sizeof(wreq));
    strncpy(wreq.ifr_name, ifname, IFNAMSIZ);

    if (ioctl(fd, SIOCGIWNAME, &wreq) == -1) {
        perror("IOCTL SIOCGIWNAME");
        return false;
    }

    if (protocol)
        strncpy(protocol, wreq.u.name, IFNAMSIZ);

    return true;
}

void get_wireless_info(int fd, const char *ifname) {
    struct iwreq wreq;
    memset(&wreq, 0, sizeof(wreq));
    strncpy(wreq.ifr_name, ifname, IFNAMSIZ);
    // struct iw_statistics wstats;
    // memset(&wstats, 0, sizeof(wstats));
    // wreq.u.data.pointer = &wstats;
    // wreq.u.data.length = sizeof(wstats);

    // struct iw_scan_req scanopt;
    char buffer[32];
    wreq.u.data.pointer = buffer;
    wreq.u.data.flags = 0;
    wreq.u.data.length = sizeof(buffer);

    // if (ioctl(fd, SIOCGIWSTATS, &wreq) == -1) {
    if (ioctl(fd, SIOCGIWSCAN, &wreq) == -1) {
        perror("IOCTL SIOCGIWSCAN");
        return;
    }

    printf("%d\n", wreq.u.data.length);
}


int main(int argc, char const *argv[]) {
  struct ifaddrs *ifaddr, *ifa;

  if (getifaddrs(&ifaddr) == -1) {
    perror("getifaddrs");
    return -1;
  }

  int fd = -1;
  if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
      freeifaddrs(ifaddr);
      perror("create socket");
      return -1;
  }


  /* Walk through linked list, maintaining head pointer so we
     can free list later */
  for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
    char protocol[IFNAMSIZ]  = {0};

    if (ifa->ifa_addr == NULL ||
        ifa->ifa_addr->sa_family != AF_PACKET) continue;

    if (check_wireless(fd, ifa->ifa_name, protocol)) {
      printf("%s : %s\n", ifa->ifa_name, protocol);
      get_wireless_info(fd, ifa->ifa_name);
    }
  }

  freeifaddrs(ifaddr);
  close(fd);
  return 0;
}

