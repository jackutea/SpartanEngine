#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct FileInfo {
    char name[64];
    char dir[128];
} FileInfo;

void FileInfo_Write(FileInfo *info, const char *name, const char *dir) {
    strcpy(info->name, name);
    strcpy(info->dir, dir);
}

int GetAllFiles(char *dirPath, char *ext, FileInfo files[], int *fileCount) {

    // 打开目录
    DIR *dir = opendir(dirPath);
    if (dir == NULL) {
        return -1;
    }

    struct dirent *entry;
    do {
        entry = readdir(dir);
        if (entry == NULL) {
            continue;
        }

        // 如果是符合 ext 的文件
        if (strstr(entry->d_name, ext) != NULL) {
            // printf("file: %s\r\n", entry->d_name);
            FileInfo_Write(&files[*fileCount], entry->d_name, dirPath);
            (*fileCount) += 1;
        } else if (strcmp(entry->d_name, ".") > 0 && strcmp(entry->d_name, "..") > 0) {
            // printf("dir: %s\r\n", entry->d_name);
            char subDir[128];
            sprintf(subDir, "%s/%s", dirPath, entry->d_name);
            GetAllFiles(subDir, ext, files, fileCount);
        }
    } while (entry != NULL);

    closedir(dir);

    return 0;
}

// .c -> .o
int CompileC2O(char *compiler, char *ext, char *srcDir, char *buildDir) {

    FileInfo *files = (FileInfo *)malloc(1024 * sizeof(FileInfo));
    int fileCount = 0;
    int res = GetAllFiles(srcDir, ext, files, &fileCount);

    for (int i = 0; i < fileCount; i++) {
        char cmd[512];
        FileInfo file = files[i];
        sprintf(cmd, "%s -c %s/%s -o %s/%s.o", compiler, file.dir, file.name, buildDir, file.name);
        system(cmd);
    }

    free(files);

    return 0;
}

// usage: prebuild.exe gcc .cpp ./src/ ./build/
int main(int argc, char *argv[]) {

    char *compiler = argv[1];
    char *ext = argv[2];
    char *srcDir = argv[3];
    char *buildDir = argv[4];

    // argv[1] 是源目录, 要找到它的*.c文件
    // argv[2] 是目标目录, 把.o文件放到这里

    CompileC2O(compiler, ext, srcDir, buildDir);
    printf("Build All %s to %s.o\r\n", srcDir, buildDir);

    // then: gcc -o build.exe build/*.o
    return 0;
}