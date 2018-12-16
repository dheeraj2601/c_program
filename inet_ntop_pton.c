#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
    struct in_addr addr;
    char abc[INET_ADDRSTRLEN];

    if (argc != 2) {
        fprintf(stderr, "%s <dotted-address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (inet_pton(AF_INET, argv[1], &addr) == 0) {
        fprintf(stderr, "Invalid address\n");
        exit(EXIT_FAILURE);
    }

    inet_ntop(AF_INET, &addr, abc, sizeof(abc));

    printf("%d\n", addr);
    printf("%s\n", abc);
    exit(EXIT_SUCCESS);
}





#if 0

int
main(int argc, char *argv[])
{
    struct in_addr addr;
    char *abc;

    if (inet_aton(argv[1], &addr) == 0) {
        fprintf(stderr, "Invalid address\n");
        exit(EXIT_FAILURE);
    }

    abc = inet_ntoa(addr);

    printf("%s\n", inet_ntoa(addr));
    printf("%s\n", abc);
    exit(EXIT_SUCCESS);
}

#endif
