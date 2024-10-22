#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <time.h>
#include <unistd.h>

int main() {
    // Get and print the hostname
    char hostname[1024];
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("Hostname: %s\n", hostname);
    } else {
        perror("gethostname");
    }

    // Get and print the OS name
    struct utsname system_info;
    if (uname(&system_info) == 0) {
        printf("OS Name: %s\n", system_info.sysname);
    } else {
        perror("uname");
    }

    // Get and print the current date and time
    time_t current_time;
    time(&current_time);
    printf("Current Date and Time: %s", ctime(&current_time));

    return 0;
}
