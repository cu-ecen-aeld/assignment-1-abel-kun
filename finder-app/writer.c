//////////////////
// @author: Arun Belamge
// @date  : 23-02-2025
/////////////////

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>

int main(int argc, char * argv[])
{
    openlog(NULL, 0, LOG_USER);
    if(argc != 3)
    {
        syslog(LOG_ERR, "Invalid number of arguments, expected 2 got %d\n", (argc-1));

        return 1;
    }
    else
    {
    int ftmp;
    char* write_str = argv[2];
    char* file_str = argv[1];
    size_t size = strlen(write_str);
    ftmp = open (file_str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(ftmp == -1)
    {
        syslog(LOG_ERR, "%s\n", strerror(errno));
        return 1;
    }
    else {
        syslog(LOG_DEBUG, "Writing %s to %s\n", write_str, file_str);
        write(ftmp, write_str, size);
        close(ftmp);
        return 0;
    }

    }
}
