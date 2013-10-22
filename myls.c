#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

int main(int argc, char * argv[])
{
    DIR *dp;
    struct dirent * dirp;

    if(argc != 2)
    {
        printf("Useage: myls directory name.");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        return -2;
    }

    printf("%-40s%8s\n", "file or dir name", "inode number");
    while( (dirp = readdir(dp)) != NULL)
    {
        printf("%-40s%d\n", dirp->d_name, (int)dirp->d_ino);
    }

    close(dp);
    
    return 0;
}
