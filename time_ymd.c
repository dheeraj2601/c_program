
//How to print time in format: 2009‐08‐10 18:17:54.811

#include <stdio.h>
#include <time.h>

int main()
{
    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);

    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    puts(buffer);

    return 0;
}

// You can convert between time_t and struct tm with mktime and localtime.
