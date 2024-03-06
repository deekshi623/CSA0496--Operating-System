#include <stdio.h>
#include <sys/stat.h>

int main() {
    const char *file_path = "/path/to/your/file.txt";
    mode_t permissions = S_IRUSR | S_IWUSR | S_IXUSR |  
                          S_IRGRP | S_IWGRP | S_IXGRP |  
                          S_IROTH | S_IWOTH | S_IXOTH;   

    if (chmod(file_path, permissions) == 0) {
        printf("File permissions set successfully.\n");
    } else {
        perror("Error setting file permissions");
    }

    return 0;
}