#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd1;

    // FIFO file path
    char * myfifo = "/tmp/myfifo";

    mkfifo(myfifo, 0666);

    char str1[80], str2[80];
    
    while (1)
    {
        // First open in read only and read
        fd1 = open(myfifo,O_RDONLY);
        read(fd1, str1, 80);

        // Print the read string and close
        printf("\n\n%s\n\n", str1);
        //close(fd1);

        // Now open in write mode and write
        // string taken from user.
        fd1 = open(myfifo,O_WRONLY);

		printf("Enter a message: ");
        fgets(str2, 80, stdin);
        
        strcat(str2, "from process 2");
        write(fd1, str2, strlen(str2)+1);
        close(fd1);
    }
    return 0;
}