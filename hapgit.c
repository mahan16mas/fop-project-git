//int int int
// #define _XOPEN_SOURCE
// #define __USE_XOPEN
// #define  _GNU_SOURCE
// #define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <stdint.h>
#define existance_error printf("Hapgit has not been initialized yet!\n")
#define MAX_FILE_NAME 500
#define MAX_COMMAND 100
#define MAX_MES_NAME 100 
#define MAX_HASH 1024
#define MAX_ADD 1024
#define debug system("pwd")
int check_alias(char* alias);

int last_branch_id(char* branch);
int chek_if_check();
void run_branch(char* naem);
void checkout(char* from);
void undo();
void status();
void where_are_we(char* addres);
int if_exist(char* addres);
void git();
void global_name(char* nameof);
void global_email(char* nameof);
void local_name(char* nameof);
void local_email(char* nameof);
void add(char* name, char* folder);
void reset(char* name, char* addres);
void get_hash(char* hash, char* name);
void add_to_staging(char* name, char* string);
void add_n();
void reset(char* name, char* folder);
void remove_line(char* text_name,int khat);
void redo();
void mkdfolder(char* add);
void remove_non_dir();
int exist(char* addres);
int compare_times(char* first, char* last);
void local_alias(char* alias, char* instead);
void glob_alias(char* alias, char* instead);
void grep(char* file, char* word, int flag);
void diff(char* file1,int start1, int finish1, char* file2, int start2, int finish2, char* show1, char* show2);
void todo_check(char* answer, char* file_path);
int if_cpp(char* file_path);
void format_check(char* answer, char* file_path);
void file_size_check(char* answer, char* file_path);
void char_limit(char* answer, char* file_path);
void balance_braces(char* answer, char* file_path);
void eof_blank_space(char* answer, char* file_path);

void eof_blank_space(char* answer, char* file_path)
{
    int length = strlen(file_path);
    if(strcmp(file_path + length - 2, ".c") && strcmp(file_path + length - 4, ".cpp") && strcmp(file_path + length - 4, ".txt"))
    {
        char ans[1024] = "SKIPPED";
        strcpy(answer, ans);
        return;
    }
    FILE *file;
    char ch;

    // Open the file in read mode
    file = fopen(file_path, "r");

    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    // Move the file pointer to the end of the file
    fseek(file, -1, SEEK_END);

    // Read the last character
    ch = fgetc(file);

    // printf("The final character of the file is: %c\n", ch);
    if(ch == ' ' || ch == '\n' || ch == '\r' || ch == '\f' || ch == '\v')
    {
        char ans[1024] = "FAILED";
        strcpy(answer, ans);
        return;
    }
    char ans[1024] = "PASSED";
        strcpy(answer, ans);
        return;
    // Close the file
    fclose(file);
}
void balance_braces(char* answer, char* file_path)
{
    int brac_bac = 0, brac_for = 0, kro_bac = 0, kro_for = 0, par_bac = 0, par_for = 0;
    if(if_cpp(file_path) == 0)
    {
        char ans[1024] = "SKIPPED";
        strcpy(answer, ans);
        return;
    }
    FILE* file = fopen(file_path, "r");
    int count = 0;
    char c;
    while((c = fgetc(file)) != EOF)
    {
        // count++;
        // printf("c:%c", c);
        if(c == '[')
        {
            brac_bac++;
        }
        if(c == ']')
        {
            brac_for++;
        }
        if(c == '}')
        {
            kro_for++;
        }
        if(c == '{')
        {
            kro_bac++;
        }
        if(c == '(')
        {
            par_bac++;
        }
        if(c == ')')
        {
            par_for++;
        }
    }
    if(par_for == par_bac && kro_bac == kro_for && brac_bac == brac_for)
    {
        // printf("%d %d %d %d", par_bac, par_for, kro_for, kro_bac);
        // printf("%d", count);
        char ans[1024] = "PASSED";
        strcpy(answer, ans);
        return;
    }
    char ans[1024] = "FAILED";
    strcpy(answer, ans);
    return;
}
void char_limit(char* answer, char* file_path)
{
    int count = 0;
    int length = strlen(file_path);
    if(strcmp(file_path + length - 2, ".c") && strcmp(file_path + length - 4, ".cpp") && strcmp(file_path + length - 4, ".txt"))
    {
        char ans[1024] = "SKIPPED";
        strcpy(answer, ans);
        return;
    }
    FILE* file = fopen(file_path, "r");
    char c;
    while(fgetc(file) != EOF)
    {
        count++;
    }
    if(count > 20000)
    {
        char ans[1024] = "FAILED";
        strcpy(answer, ans);
        return;
    }
    char ans[1024] = "PASSED";
        strcpy(answer, ans);
        return;
}

void file_size_check(char* answer, char* file_path)
{
    FILE *file;
    long size;
    file = fopen(file_path, "rb");
    if (file == NULL) {
        return;
    }
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fclose(file);
    if(size > 5000000)
    {
        char ans[1024] = "FAILED";
        strcpy(answer, ans);
        return;
    }
    char ans[1024] = "PASSED";
    strcpy(answer, ans);
    return;
}
void format_check(char* answer, char* file_path)
{
    int length = strlen(file_path);
    if(!strcmp(file_path + length - 4, ".MP3") || !strcmp(file_path + length - 4, ".MP4") || !strcmp(file_path + length - 4, ".PDF") || !strcmp(file_path + length - 5, ".DOCX") || !strcmp(file_path + length - 5, ".XLSX") || !strcmp(file_path + length - 5, ".JPEG") || !strcmp(file_path + length - 4, ".PNG"))
    {
        char ans[1024] = "PASSED";
        strcpy(answer, ans);
        return;
    }
    char ans[1024] = "FAILED";
    strcpy(answer, ans);
    return;
}
int if_cpp(char* file_path)
{
    char name[1024];
    int flag = 1;
    for (int i = strlen(file_path) - 1; i >= 0; i--)
    {
        if(file_path[i] == '/')
        {
            strcpy(name, &file_path[i + 1]);
            flag = 0;
            break;
        }
    }
    if(flag)
    {
        strcpy(name, file_path);
    }
    // printf("%s\n", name);
    // return;
    int length = strlen(name);
    // printf("%s", name + length - 4);
    if(!strcmp(".cpp", name + length - 4) || !strcmp(".c", name + length - 2))
    {
        return 1;
    }
    return 0;
}
//}
void todo_check(char* answer, char* file_path)
{
    if(if_cpp(file_path) == 0)
    {
        char ans[1024] = "SKIPPED";
        strcpy(answer, ans);
        return;
    }
    FILE* file = fopen(file_path, "r");
    if(file == NULL) return;
    char line[1024];
    while(fgets(line, sizeof(line), file))
    {
        if(strstr(line, "//"))
        {
            int place = (int)(strstr(line, "//") - line);
            if(strstr(place + line, "TODO"))
            {
                char ans[1024] = "FAILED";
                strcpy(answer, ans);
                return;
            }
        }
    }
    rewind(file);
    int if_comment = 0;
    while (fgets(line, sizeof(line), file))
    {
        int place = 0, sec_place = 0, third_place = 110000000;
        if(strstr(line, "/*"))
        {
            place = (int)(strstr(line, "/*") - line);
            if_comment = 1;
        }
        if(strstr(line, "*/"))
        {
            third_place = (int)(strstr(line, "*/") - line);
            
        }
        if(strstr(line, "TODO") && if_comment)
        {
            sec_place = (int)(strstr(line, "TODO") - line);
            if((place == 0 || sec_place > place) && sec_place < third_place)
            {
                char ans[1024] = "FAILED";
                strcpy(answer, ans);
                return;
            }
        }
        if(strstr(line, "*/"))
        {
            // third_place = (int)(strstr(line, "*/") - line);
            if_comment = 0;   
        }
    }
    
    // printf("lps");
    char ans[1024] = "PASSED";
    strcpy(answer, ans);
    return;
}
void diff(char* file1,int start1, int finish1, char* file2, int start2, int finish2, char* show1, char* show2)
{
    FILE* first = fopen(file1, "r");
    FILE* second = fopen(file2, "r");

    char first_line[1024], second_line[1024];
    for (int i = 0; i < start1; i++)
    {
        fgets(first_line, 1024, first);
    }
    for (int i = 0; i < start2; i++)
    {
        fgets(second_line, 1024,  second);
    }
    
    int line1 = start1;
    int line2 = start2;
    int flag = 0;
    while (fgets(first_line, 1024, first))
    {
        if(line1 == finish1 || line2 == finish2)
        {
            return;
        }
        line1++;
        flag = 0;
        for (int i = 0; i < strlen(first_line) - 1; i++)
        {
            if(first_line[i] != '\0' &&  first_line[i] != '\n' && first_line[i] != ' ' && first_line[i] != '\t' && first_line[i] != '\v' && first_line[i] != '\f' && first_line[i] != '\r')
            {
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            flag = 0;
            while(fgets(second_line, sizeof(second_line), second))
            {
                line2++;
                for (int i = 0; i < strlen(second_line); i++)
                {
                    if(second_line[i] != '\0' &&  second_line[i] != '\n' && second_line[i] != ' ' && second_line[i] != '\t' && second_line[i] != '\v' && second_line[i] != '\f' && second_line[i] != '\r')
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag)
                {
                    if(strcmp(first_line, second_line))
                    {
                        printf("«««««\n");
                        // printf("«»");
                        printf("%s-%d\n", show1, line1);
                        printf("\033[34m%s\033[0m", first_line);
                        if(first_line[strlen(first_line) - 1] != '\n')
                        {
                            printf("\n");
                        }
                        printf("%s-%d\n",  show2, line2);
                        printf("\033[31m%s\033[0m",  second_line);
                        if(second_line[strlen(second_line) - 1] != '\n')
                        {
                            printf("\n");
                        }
                        printf("»»»»»\n");
                    }

                    break;
                }
                else continue;
            }
        }
        else continue;
        // line++;
    }
    
}
void grep(char* file, char* word, int flag)
{
    FILE* f = fopen(file, "r");
    char line[1024];
    int which_line = 1;
    while (fgets(line, 1024, f)) 
    {
        int line_print = 1;
        int idx = 0, place = 0, length = strlen(word), allow = 0;
        while(strstr(line + place, word))
        {
            if(line_print && flag)
            {
                line_print = 0;
                printf("%d ",  which_line);
            }
            allow = 1;
            place = (int)(strstr(line + place, word) - line) + length;
            for (int i = idx; i < place; i++)
            {
                if(i == place - length)
                    printf("\033[32m");
                printf("%c",line[i]);
            }
            printf("\033[0m");
            idx = place;
        }
        if(allow)
        {
            for (int i = idx; i < strlen(line); i++)
            {
                printf("%c", line[i]);
            }
            
        }
        which_line++;
    }
}
int check_alias(char* alias)
{
    // printf("%s", alias);
    char token[100][1024];
    char delimiter[100] = " \n";
    char tokenized[1024];
    strcpy(tokenized, alias);
    int i = 0;
    char* t;
    t = strtok(tokenized, delimiter);
    // strcpy(token[0], t);
    while(t)
    {
        strcpy(token[i], t);
        t = strtok(NULL,  delimiter);
        i++;
    }
    // for (int j = 0;j  < i; j++)
    // {
    //     printf("%s a", token[j]);
    // }
    if(i < 2)
    {
        return 0;
    }
    if(strcmp(token[0], "hapgit"))
    {
        return 0;
    }
    if(!strcmp(token[1], "add") || !strcmp(token[1], "reset") || !strcmp(token[1], "config") || !strcmp(token[1], "status") || !strcmp(token[1], "commit") || !strcmp(token[1], "checkout") || !strcmp(token[1], "set") || !strcmp(token[1], "remove") || !strcmp(token[1], "log") || !strcmp(token[1], "replace") || !strcmp(token[1], "add") || !strcmp(token[1], "branch"))
    return 1;
    return 0;
}
void local_alias(char * alias, char *instead)
{
    char add[1024];
    if_exist(add);
    chdir(add);
    if(check_alias(instead) == 0)
    {
        printf("invalid alias command\n");
        return;
    }
    // printf("%s", instead);
    FILE* file = fopen("alias", "a");
    char realal[1024];
    strcpy(realal, alias +  6);
    fprintf(file, "%s %s\n", realal, instead);
    fclose(file);

}
void glob_alias(char * alias, char *instead)
{
    // char add[1024];
    // if_exist(add);
    if(check_alias(instead) == 0)
    {
        printf("invalid alias command\n");
        return;
    }
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    chdir("/home/mahan/hapgit/");
    // system("pwd");
    // printf("%s", instead);
    FILE* file = fopen("alias", "a");
    char realal[1024];
    strcpy(realal, alias +  6);
    fprintf(file, "%s %s\n", realal, instead);
    fclose(file);
    chdir(cwd);
}
int last_branch_id(char* branch)
{
    char add[1024];
    char cur[1024];
    getcwd(cur, sizeof(cur));

    if_exist(add);
    chdir(add);
    chdir("branches");
    chdir(branch);
    for (int i = 1000; i >= 0 ; i--)
    {
        DIR* dir = opendir(".");
        struct dirent* entry;
        while(entry = readdir(dir))
        {
            char id[100];
            sprintf(id, "%d", i);
            if(!strcmp(id,  entry->d_name))
            {
                chdir(cur);
                return i;
            }
        }
    }
    chdir(cur);
    return 0;
}
int chek_if_check()
{
    char add[1024];
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    chdir(add);
    FILE* f = fopen("staged_files.txt", "r");
    char line[1024];
    int size = 0;
    while(fgets(line, sizeof(line), f))
    {
        size++;
    }
    chdir(cwd);
    if(size)
    {
        return 0;
    }
    return 1;
}
void checkout(char* from)
{
    char cur[1024];
    getcwd(cur, sizeof(cur));
    char add[1024];
    if_exist(add);
    chdir(add);
    char to[1024];
    chdir("..");
    getcwd(to, sizeof(to));
    DIR* dir = opendir(".");
    struct dirent* entry;
    while(entry = readdir(dir))
    {
        if(!strcmp(".", entry->d_name) || !strcmp("..", entry->d_name))
            continue;
        remove(entry->d_name);
    }
    closedir(dir);
    chdir(from);
    dir = opendir(".");
    while(entry = readdir(dir))
    {
        if(!strcmp(".", entry->d_name) || !strcmp("..", entry->d_name) || !strcmp("commited.txt", entry->d_name))
            continue;
        char command[1024] = "cp ";
        if(entry->d_type == 4)
        {
            strcat(command, "-r ");
        }
        strcat(command, entry->d_name);
        strcat(command, " ");
        strcat(command, to);
        system(command);

    }
    chdir(cur);
}
void run_branch(char* name)
{
    char addres[1024];
    if_exist(addres);
    chdir(addres);
    char curr_branch[1024];

    FILE* read = fopen("current_branch.txt", "r");
    fscanf(read, "%s", curr_branch);
    char id[10];
    fclose(read);
    read = fopen("current_commit.txt", "r");
    fscanf(read, "%s", id);
    char new_branch[1024];
    strcpy(new_branch, addres);
    strcat(new_branch, "/branches/");
    char last_branch[1024];
    strcpy(last_branch, new_branch);

    chdir(new_branch);
    // strcat(new_branch, name);
    strcat(last_branch, curr_branch );
    strcat(last_branch, "/");
    strcat(last_branch, id);
    mkdir(name, 0777);
    strcat(new_branch, name);
    char command[1024] = "cp -r ";
    strcat(command, last_branch);
    strcat(command, " ");
    strcat(command, new_branch);
    system(command);
    chdir(addres);
    // FILE* commit = fopen("list_of_branches")

}
int compare_times(char* first, char* last)
{
    int y1, y2;
    int m1, m2;
    int d1, d2;
    int  h1, min1, h2, min2;
    sscanf(first,"%d/%d/%d %d:%d", &y1, &m1, &d1, &h1, &min1);
    sscanf(last,"%d/%d/%d %d:%d", &y2, &m2, &d2, &h2, &min2);
    // printf("%d %d %d %d %d\n",  y1, m1, d1, h1, min1);
        // printf("%d %d %d %d %d\n",  y2, m2, d2, h2, min2);
    if(y1 > y2)
    {
        return 1;
    }
    if(y2 > y1)
    {
        return -1;
    }
    if(m1 > m2)
    {
        return 1;
    }
    if(m2 > m1)
    {
        return -1;
    }
    if(d1 > d2)
    {
        return 1;
    }
    if(d2 > d1)
    {
        return -1;
    }
    // printf("h1:%d h2:%d", h1, h2);
    if(h1 > h2)
    {
        return 1;
    }
    if(h2 > h1)
    {
        return -1;
    }
    if(min1 > min2)
    {
        return 1;
    }
    if(min2 > min1)
    {
        return -1;
    }
    return -1;
} 
int exist(char* addres)
{
    char folder[MAX_ADD] = ".";
    char current[MAX_ADD];
    char name[MAX_FILE_NAME];
    getcwd(current, sizeof(current));
    for (int i = strlen(addres) - 1; i >= 0; i--)
    {
        if(addres[i] == '/')
            {
                    // printf("folder: %s\nname: %s\n", folder, name);
                for (int j = 0; j < i; j++)
                {
                    folder[j] = addres[j];
                }
                folder[i] = '\0';
                strcpy(name, addres + i + 1);
                if(chdir(folder) != 0)
                {
                    // system("pwd");
                    // printf("wrong address!\n");e
                    return 0;
                }
                break;
            }
    }
    DIR* dir = opendir(".");
    struct dirent* entry;
    while(entry = readdir(dir))
    {
        if(!strcmp(entry->d_name, name) && entry->d_type != 4)
        {
            chdir(current);
            return 1;
        }
    }
    chdir(current);
    return 0;
}   
void remove_non_dir()
{
    // system("pwd");
    DIR* dir = opendir(".");
    struct dirent* entry;
    while(entry = readdir(dir))
    {
        if(entry->d_type == 4 && strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..") && strcmp(entry->d_name, ".hapgit"))
        {
            chdir(entry->d_name);
            remove_non_dir();
            chdir("..");
        }
        else 
        if(entry->d_type != 4)
        {
            remove(entry->d_name);
        }
    }
}
void mkdfolder(char* add)
{
    char hapgit[1024];
    if_exist(hapgit);
    chdir(hapgit);
    chdir("..");
    DIR* dir = opendir(".");
    struct dirent* entry;
    while (entry = readdir(dir))
    {
        if(entry->d_type == 4 && strcmp(entry->d_name, ".")  && strcmp(entry->d_name, "..") && strcmp(entry->d_name, ".hapgit"))
        {
            char command[1024] = "cp -r ";
            strcat(command, entry->d_name);
            strcat(command, " ");
            strcat(command, add);
            // printf("command: %s\n", command);
            system(command);
        }
    }
    chdir(add);
    closedir(dir);
    remove_non_dir();
    
}
void commit(char* message)
{
    //cp
    // system("pwd");
    // exist
    int id;
    char addres[MAX_ADD], current[1024];
    if_exist(addres);
    chdir(addres);
    int if_can_commit;
    FILE* allowd = fopen("commit_allowed.txt", "r");
    fscanf(allowd, "%d", &if_can_commit);
    if(if_can_commit < 1)
    {
        printf("You can't commit now!\n");
        return;
    }
    getcwd(current, sizeof(current));
    char last_commit[1024];

    char current_cum[1024];
    strcpy(last_commit, addres);
    strcpy(current_cum, addres);
    strcat(current_cum, "/current_commit.txt");
    strcat(last_commit, "/last_commit.txt");
    // printf("l commit:%s\n", last_commit);
    FILE* com_id = fopen(last_commit, "r");
    fscanf(com_id, "%d", &id);
    fclose(com_id);
    FILE* curr = fopen(last_commit, "w");
    fprintf(curr, "%d", id + 1);
    FILE* ff = fopen(current_cum, "w");
    fprintf(ff, "%d", id + 1);
    char com_folder[1024];
    strcpy(com_folder, addres);
    strcat(com_folder, "/branches/");
    char cur_branch[MAX_FILE_NAME];
    FILE* curber = fopen("current_branch.txt", "r");
    fgets(cur_branch, sizeof(cur_branch), curber);
    if(cur_branch[strlen(cur_branch) - 1] == '\n')
        cur_branch[strlen(cur_branch) - 1] = '\0';
    strcat(com_folder, cur_branch);
    // printf("com fol\t%s\n", com_folder);
    // strcat(com_folder, "/");
    chdir(com_folder);
    // system("pwd");
    char place_and_id[1024];
    strcpy(place_and_id, com_folder);
    strcat(place_and_id, "/");

    char name[10];
    sprintf(name, "%d", id + 1);
    strcat(place_and_id,  name);
    mkdir(name, 0777);
    int flag = 0;
    char last[1024];
    char reallast[1024];
    FILE* cpy;
        char commit_last_commit[1024];
    if(id > 0)
    {
        sprintf(last, "%d", id);
        realpath(last, reallast);
        flag = 1;
        strcpy(commit_last_commit, reallast);
        strcat(commit_last_commit, "/commited.txt");
        // printf("last commit:\t%s\n", commit_last_commit);
        cpy = fopen(commit_last_commit, "r");
    }
    char path[MAX_ADD];
    realpath(name, path);
    mkdfolder(path);
    
    chdir(path);
    // system("pwd");
    FILE* file = fopen("commited.txt", "w");
    if(flag)
    {
        char line3[1024];
        while (fgets(line3, 1024, cpy))
        {
            fprintf(file, "%s", line3);
        }
        fclose(cpy);
        
    }
    fclose(file);
    char laststaged[1024];
    strcpy(laststaged, addres);
    strcat(laststaged, "/staged_files.txt");
    // printf("last staged:%s\n", laststaged);
    FILE* staged = fopen(laststaged, "r");
    char line[1024];
        if(flag){
    while (fgets(line, 1024, staged))
    {
        // printf("kps");
        int i = 0;
        char line2[1024];
        char where[1024] = "commited.txt";
        FILE* read = fopen(where, "r");
        char name[1024];
        char hash[1024];
        sscanf(line, "%s %s\n", name, hash);
        while(fgets(line2, sizeof(line2), read))
        {
            char name2[1024];
            char h[1024];
            sscanf(line2, "%s %s\n", name2, h);
            if(!strcmp(name2, name))
            {
                remove_line(where, i);
                // fclose(file);
                // file = fopen(where, "a");
                break;
            }
            i++;
        }
        // fprintf(file, "%s", line);

    }
        }
    rewind(staged);
    file = fopen("commited.txt", "a");
    char line4[1024];
    int number_of_commited = 0;
    while(fgets(line4, sizeof(line4), staged))
    {
        
        fprintf(file, "%s", line4);
        number_of_commited++;
        
    }
    fclose(staged);
    FILE* fucked_up = fopen(laststaged, "w");
    fclose(fucked_up);
    fclose(file);
    FILE* rd = fopen("commited.txt", "r");
    char line10[MAX_ADD];
    rewind(rd);
    // system("pwd");
    // printf("lso");
    int i = 0;
    while(fgets(line10, sizeof(line10), rd))
    {
    // printf("ki\n");
        char nam[MAX_ADD];
        char has[MAX_HASH];
        sscanf(line10, "%s %s\n", nam, has);
        if(exist(nam))
        {
            char hapgit[MAX_ADD];
            strcpy(hapgit, addres);
            int length = strlen(hapgit);
            char commit_id[MAX_ADD];
            // printf("addres: %s\n", addres);
            strcpy(commit_id, addres);
            char idd[MAX_ADD];
            sprintf(idd, "%d", id + 1);
            strcat(commit_id, "/branches/");
            strcat(commit_id, cur_branch);
            strcat(commit_id, "/");
            strcat(commit_id, idd);
            // printf("commit_id:%s\n", commit_id);
            int place = (int)(strstr(hapgit, ".hapgit") - hapgit);
            for (int i = place - 1; i < length; i++)
            {
                *(hapgit + i) = '\0';
            }
            strcat(commit_id, nam + strlen(hapgit));
            for (int i = strlen(commit_id) - 1; i >= 0; i--)
            {
                if(commit_id[i] == '/')
                {
                    for (int j = i; i < strlen(commit_id); j++)
                    {
                        commit_id[j] = '\0';
                    }
                    break;
                }
            }
            char sys[1024] = "cp ";
            strcat(sys, nam);
            strcat(sys," ");
            strcat(sys, commit_id);
            system(sys);
            // printf("%s %s\n", commit_id, nam);
            
        }
        else remove_line("commited.txt", i);
        i++;
    }
    chdir(addres);
    FILE* write = fopen("temp.txt", "w");
    char author[MAX_MES_NAME];
    FILE* name_txt = fopen("name.txt", "r");
    fscanf(name_txt, "%s", author);
    fclose(name_txt);
    time_t rawtime;
     time_t now = time(NULL);
    struct tm *ptm = localtime(&now);

    char buf[256];
    strftime(buf, sizeof(buf), "%Y/%m/%d %H:%M", ptm);
    // printf("%s\n", buf);
    // printf("Current time: %s", asctime(localTime));
    char branch[100];
    FILE* branches = fopen("current_branch.txt", "r");
    fscanf(branches, "%s", branch);
    FILE* list_of_cums = fopen("list_of_commits.txt", "r");
    fprintf(write, "commit id: %d\tauthor: %s\tbranch: %s\tnumber of files commited: %d\tmessage: %s\ttime commited: %s\n", id + 1, author, branch, number_of_commited, message, buf);
    printf("commit id: %d\tmessage: \"%s\"\ttime commited: %s\n", id + 1, message, buf);
    fclose(write);
    write = fopen("temp.txt", "a");
    char liin[MAX_ADD];
    while(fgets(liin, sizeof(liin), list_of_cums))
    {
        // printf("liin: %s\n", liin);
        fprintf(write, "%s", liin);
    }
    fclose(write);
    fclose(list_of_cums);
    remove("list_of_commits.txt");
    rename("temp.txt", "list_of_commits.txt");
    FILE* when = fopen("place_and_id", "a");
    fprintf(when, "%s %d\n",  place_and_id, id + 1);
    chdir(current);

}
/// //
void status()
{
    char addres[1024];
    if_exist(addres);
    chdir(addres);
    int idd;
    char branch[1024], id[100];
    FILE* brache = fopen("current_branch.txt", "r");
    fscanf(brache, "%s", branch);
    fclose(brache);
    FILE* last = fopen("current_commit.txt", "r");
    fscanf(last, "%d", &idd);
    sprintf(id, "%d", idd);
    // printf("%s", id);
    FILE* read_tracked = fopen("tracked.txt", "r");
    FILE* staged = fopen("staged_files.txt", "r");
    fclose(last);
    if(idd > 0)
    {
        chdir("branches");
        chdir(branch);
        chdir(id);
        // system("pwd");
        char line[1024];
        while(fgets(line, sizeof(line), read_tracked))
        {
            FILE* f = fopen("commited.txt", "r");
            char trackname[1024];
            char hash[1024];
            sscanf(line, "%s %s\n", trackname ,hash );
            char condition = ' ';
            char line2[1024];
            int flag = 1;
            // char line2[1024];
            while(fgets(line2, sizeof(line2), f))
            {
                char name2[1024], hash2[1024];
                sscanf(line2,"%s %s\n" ,name2, hash2);
                if(!strcmp(name2, trackname))
                {
                    flag = 0;
                    char path[MAX_ADD];
                    realpath(name2, path);
                    if(exist(path))
                    {
                        char realhash[MAX_ADD];
                        get_hash(realhash, path);
                        if(!strcmp(realhash, hash2))
                        {
                            break;
                        }
                        else condition = 'M';
                    }
                    else
                    {
                        condition = 'D';
                    }
                    break;
                }
            }
            if(flag)
            {
                if(exist(trackname))
                    condition = 'A';
            }
            if(condition == ' ')
            {
                continue;
            }
            flag = 1;
            char if_staged = '-';
            // printf("%s %c\n",trackname, condition);
            char line3[1024];
            while ((fgets(line3, sizeof(line3), staged)))
            {
                char name3[1024], hash3[1024];
                sscanf(line3, "%s %s\n", name3, hash3);
                if(!strcmp(name3, trackname))
                {
                    if(!strcmp(hash, hash3))
                        if_staged = '+';
                    break;
                }
            }
            rewind(staged);
            char simple_name[1024];
            // int place;
            char copy_add[1024];
            strcpy(copy_add, addres);
            for (int i = strlen(copy_add) - 1; i >= 0; i--)
            {
                if(copy_add[i] == '/')
                {
                    for (int j = i + 1; j < strlen(copy_add); j++)
                    {
                        copy_add[j] = '\0';
                    }
                    break;
                    
                }
            }
            strcpy(simple_name, trackname + strlen(copy_add));

            
            printf("%s: %c%c\n", simple_name, if_staged, condition);
        }
    }
    else
    {
        char line[1024];
        while ((fgets(line, sizeof(line), read_tracked)))
        {
            char trackname[1024], hash[1024];
            sscanf(line, "%s %s\n", trackname, hash);
            char line2[1024];
            char id_staged = '-';
            char condition = ' ';
            int flag = 0;
            int is_add = 1;
            while(fgets(line2, sizeof(line2), staged))
            {
                char name2[1024], hash2[1024];
                sscanf(line2, "%s %s\n", name2, hash2);
                if(!strcmp(name2, trackname))
                {
                    
                    is_add = 0;
                    if(exist(trackname)){
                    char realhash[1024];
                    char path[1024];

                    realpath(name2, path);
                    get_hash(realhash, path);
                    if(!strcmp(hash2, hash))
                    {
                    id_staged = '+';   
                    flag = 1;
                    break;
                    }
                    else if(exist(trackname))
                    {
                        condition = 'M';
                    }
                    }
                    else condition = 'D';
                    // else condition = 'D';


                    break;
                }
            }
            rewind(staged);
            if(flag)
            {
                continue;;
            }
            if(is_add)
            {
                if(exist(trackname))
                {
                    condition = 'A';
                }
                else continue;
            }
            char simple_name[1024];
            // int place;
            char copy_add[1024];
            strcpy(copy_add, addres);
            for (int i = strlen(copy_add) - 1; i >= 0; i--)
            {
                if(copy_add[i] == '/')
                {
                    for (int j = i + 1; j < strlen(copy_add); j++)
                    {
                        copy_add[j] = '\0';
                    }
                    break;
                    
                }
            }
            strcpy(simple_name, trackname + strlen(copy_add));

            
            printf("%s: %c%c\n", simple_name, id_staged, condition);
        }
        
    }
}
void reset(char* name, char* folder)
{
    static int all = 0;
    char current[1024];
    getcwd(current, sizeof(current));
    char where[1024];
    if(if_exist(where))
    {
        strcat(where, "/staged_files.txt");
        for (int i = strlen(name) - 1; i >= 0; i--)
        {
            if(name[i] == '/')
            {
                for (int j = 0; j < i; j++)
                {
                    folder[j] = name[j];
                }
                folder[i] = '\0';
                strcpy(name, name + i + 1);
                if(chdir(folder) != 0)
                {
                    printf("wrong address!\n");
                    return;
                }
                break;

            }
        }
        DIR* dir = opendir(".");
        struct dirent* entry;
        while(entry = readdir(dir))
        {
            if(all == 0)
            {
                if(!strcmp(name, entry->d_name))
                {
                    if(entry->d_type == 4)
                    {
                        all = 1;
                        chdir(entry->d_name);
                        reset("", ".");
                        all = 0;
                        chdir("..");
                    }
                    else 
                    {
                        FILE* file = fopen(where, "r");
                        char line[MAX_ADD];
                        char hash[MAX_HASH];
                        char path[MAX_ADD];
                        realpath(name, path);
                        char namestage[MAX_ADD];
                        int i = 0;
                        while (fgets(line, sizeof(line), file))
                        {
                            sscanf(line, "%s %s\n", namestage, hash);
                            if(!strcmp(path, namestage))
                            {
                                remove_line(where, i);
                                
                            }
                            i++;
                        }
                        fclose(file);
                    }
                    chdir(current);
                    return;
                }
            }
            else
            {
                if(entry->d_type == 4)
                {
                    if(strcmp(entry->d_name, ".") && strcmp(entry->d_name, ".."))
                    {
                        all = 1;
                        chdir(entry->d_name);
                        reset("", ".");
                        chdir("..");
                    }
                }
                else 
                {
                    FILE* file = fopen(where, "r");
                    char line[MAX_ADD];
                    char hash[MAX_HASH];
                    char path[MAX_ADD];
                    realpath(entry->d_name, path);
                    char namestage[MAX_ADD];
                    int i = 0;
                    while (fgets(line, sizeof(line), file))
                    {
                        sscanf(line, "%s %s\n", namestage, hash);
                        if(!strcmp(path, namestage))
                        {
                            remove_line(where, i);
                            
                        }
                        i++;
                    }
                    fclose(file);
                }
            }
        }
    }
    chdir(current);
}
void undo()
{
    char addres[MAX_ADD];
    if_exist(addres);
    char staged[MAX_ADD];
    strcpy(staged, addres);
    strcat(addres, "/last_staged.txt");
    strcat(staged, "/staged_files.txt");
    FILE* last = fopen(addres, "r");
    char line[MAX_ADD];
    // int i = 0;
    // printf("lps");
    while(fgets(line, sizeof(line), last))
    {
        char path[MAX_ADD];
        char hash[MAX_HASH];
        sscanf(line, "%s %s\n", path, hash);
        FILE* st = fopen(staged, "r");
        char line2[MAX_ADD];
        int i = 0;
        while(fgets(line2, sizeof(line2), st))
        {
            char hs[MAX_HASH];
            char name[MAX_ADD];
            sscanf(line2, "%s %s\n", name, hs);
            // printf("name:%s path:%s\n", name, path);
            if(!strcmp(name, path))
            {
                // printf("%d", i);
                remove_line(staged, i);
                break;
            }
            i++;
        }
        fclose(st);
    }
    fclose(last);
    FILE* fuck = fopen(addres, "w");
}
void redo()
{
    char addres[MAX_ADD];
    char tra[MAX_ADD];
    if_exist(addres);
    strcpy(tra, addres);
    strcat(tra, "/tracked.txt");
    strcat(addres, "/staged_files.txt");
    // printf("%s\n", addres);
    FILE* st = fopen(addres, "r");
    char line[MAX_ADD];
            // printf("kos");
    int i = 0;
    while(fgets(line, sizeof(line), st))
    {
        char path[MAX_ADD];
        char hash[MAX_HASH];
        char real_hash[MAX_HASH];
        sscanf(line, "%s %s\n", path, hash);
        get_hash(real_hash, path);
        if(strcmp(hash, real_hash))
        {
            // fclose(st);
            remove_line(addres, i);
            // st = fopen(addres, "r");
            FILE* write = fopen(addres, "a");
            fprintf(write, "%s %s\n", path, real_hash);
            fclose(write);
        }
        i++;
    }
    fclose(st);
    FILE* trac = fopen(tra, "r");
    char line1[1024];
    int j = 0;
    while(fgets(line1, sizeof(line1), trac))
    {
        char path[MAX_ADD];
        char hash[MAX_HASH];
        char real_hash[MAX_HASH];
        sscanf(line1, "%s %s\n", path, hash);
        get_hash(real_hash, path);
        if(strcmp(hash, real_hash))
        {
            // fclose(st);
            remove_line(tra, j);
            // st = fopen(addres, "r");
            FILE* write = fopen(tra, "a");
            fprintf(write, "%s %s\n", path, real_hash);
            fclose(write);
        }
        j++;
    }
}
void remove_line(char* text_name, int khat)
{
    FILE* file = fopen(text_name, "r");
    char str[1024];
    // strcpy(str, text_name);
    // printf("text: %s\n", text_name);
    for (int i = strlen(text_name) - 1; i >= 0; i--)
    {
        if(text_name[i] == '/')
        {
            for (int j = 0; j <= i; j++)
            {
                str[j] = text_name[j];
            }
            
            
        break;
        }
    }
    strcat(str, "please_dont.txt");
    // printf("str: %s\n", str);
    FILE* copy = fopen(str, "w");
    int i = 0;
    char line[1024];

    while (fgets(line, sizeof(line), file))
    {
        // printf("%s", line);
        if(i == khat)
        {
            i++;
            continue;
        }
        fprintf(copy, "%s", line);
        i++;
    }
    fclose(file);
    fclose(copy);
    remove(text_name);
    rename(str, text_name);
}
void add_n()
{
    char where[1024];
    if(if_exist(where))
    {
        strcat(where, "/staged_files.txt");
        DIR* dir = opendir(".");
        struct dirent* entry;
        while(entry = readdir(dir))
        {
            if(entry->d_type != 4)
            {
                int flag = 1;
                printf("%s: ", entry->d_name);
                char path[1024], hash[1024];
                realpath(entry->d_name, path);
                FILE* file = fopen(where, "r");
                char line[1024], name[MAX_FILE_NAME], has[MAX_HASH];
                get_hash(hash, path);
                while(fgets(line, sizeof(line), file))
                {
                    sscanf(line, "%s %s\n", name, has);
                    if(!strcmp(has, hash), !strcmp(name, path))
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                {
                    printf("un");
                }
                printf("staged\n");
            }
        }
        closedir(dir);
    }
    else existance_error;
    return;
}
void get_hash(char* hash, char *name)
{
    char command[100] = "md5sum ";
    system("touch hash.txt");
    strcat(command, name);
    strcat(command, " > hash.txt");
    system(command);
    char add[1024];
    FILE* file = fopen("hash.txt", "r");
    fscanf(file, "%s %s", hash, add);
    fclose(file);
    system("rm hash.txt");

}
void add(char* name, char* folder)
{
    static int all = 0;
    char current[1024];
    getcwd(current, sizeof(current));
    char where[1024];
    char traked[1024];
    char last[1024];
    if(if_exist(where))
    {
        strcpy(last, where);
        strcpy(traked, where);
        strcat(last, "/last_staged.txt");
        strcat(traked, "/tracked.txt");
        strcat(where, "/staged_files.txt");
        
        for (int i = strlen(name) - 1; i >= 0; i--)
        {
            if(name[i] == '/')
            {
                // if(i == strlen(name - 1))
                // {
                    
                // }
                    // printf("folder: %s\nname: %s\n", folder, name);
                for (int j = 0; j < i; j++)
                {
                    folder[j] = name[j];
                }
                folder[i] = '\0';
                strcpy(name, name + i + 1);
                if(chdir(folder) != 0)
                {
                    // system("pwd");
                    printf("wrong address!\n");
                    return;
                }
                break;
            }
        }
        DIR* dir = opendir(".");
        struct dirent* entry;
        while(entry = readdir(dir))
        {
            if(all == 0)
            {
                if(!strcmp(entry->d_name, name))
                {
                    if(entry->d_type == 4)
                    {
                        all = 1;
                        chdir(entry->d_name);
                        add("", ".");
                        all = 0;
                        chdir("..");
                    }
                    else
                    {
                        int flag = 1;
                        char name2[MAX_ADD];
                        char hash[MAX_HASH];
                        realpath(entry->d_name, name2);
                        get_hash(hash, name2);
                        FILE* read = fopen(where, "r");
                        FILE* trak = fopen(traked, "r");
                        char line[2024];
                        int i = 0;
                        while(fgets(line, sizeof(line), read))
                        {
                            char path[1024];
                            char h[MAX_HASH];
                            sscanf(line, "%s %s\n", path, h);
                            if(!strcmp(path, name2) && !strcmp(hash, h))
                            {
                                flag = 0;
                    
                            }
                            else if(!strcmp(path, name2))
                            {
                                fclose(read);
                                remove_line(where, i);
                                break;
                                // read = fopen(where, "r");
                            }
                            i++;
                        }
                        i = 0;
                        char line1[1024];
                        while(fgets(line1, sizeof(line1), trak))
                        {
                            char path[1024];
                            char h[MAX_HASH];
                            sscanf(line1, "%s %s\n", path, h);
                            if(!strcmp(path, name2) && strcmp(hash, h) != 0)
                            {
                                // printf("kos");
                                fclose(trak);
                                remove_line(traked, i);
                                break;
                            }
                            
                            i++;
                        }
                        // fclose(read);
                        if(flag){
                         FILE* add = fopen(where, "a");
                        FILE* tracked = fopen(traked, "a");
                        fprintf(tracked, "%s %s\n", name2, hash);
                        fclose(tracked);
                        FILE* lstage = fopen(last, "a");
                        fprintf(lstage, "%s %s\n", name2, hash);
                        fclose(lstage);
                        fprintf(add, "%s %s\n", name2, hash);
                        fclose(add);
                        }
                    }
                    chdir(current);
                    return;
                }
            }
            else
            {
                if(entry->d_type == 4 && strcmp(entry->d_name, ".") && strcmp(entry->d_name, ".."))
                {
                    all = 1;
                    chdir(entry->d_name);
                    add("", ".");
                        chdir("..");
                }
                else if(entry->d_type != 4)
                {
                    int flag = 1;
                    char hash[MAX_HASH];
                    char addr[1024] = {0};
                    realpath(entry->d_name, addr);
                    get_hash(hash, addr);
                    FILE* read = fopen(where, "r");
                    FILE* trak = fopen(traked, "r");
                        char line[2024];
                        int i = 0;
                        while(fgets(line, sizeof(line), read))
                        {
                            char path[1024];
                            char h[MAX_HASH];
                            sscanf(line, "%s %s\n", path, h);
                            if(!strcmp(path, addr) && !strcmp(hash, h))
                            {
                                flag = 0;
                            }
                            else if(!strcmp(path, addr))
                            {
                                fclose(read);
                                remove_line(where, i);
                                break;
                                // read = fopen(where, "r");
                            }
                            i++;
                        }
                        i = 0;
                        while(fgets(line, sizeof(line), trak))
                        {
                            char path[1024];
                            char h[MAX_HASH];
                            sscanf(line, "%s %s\n", path, h);
                            if(!strcmp(path, addr) && strcmp(hash, h))
                            {
                                fclose(trak);
                                remove_line(traked, i);
                                break;
                                // read = fopen(where, "r");
                            }
                            i++;
                        }
                        // fclose(read);
                        if(flag){
                    FILE* add = fopen(where, "a");
                    
                    fprintf(add, "%s %s\n", addr, hash);
                    fclose(add);
                    FILE* tracked = fopen(traked, "a");
                        fprintf(tracked, "%s %s\n", addr, hash);
                        fclose(tracked);
                        FILE* lstage = fopen(last, "a");
                        fprintf(lstage, "%s %s\n", addr, hash);
                        fclose(lstage);
                        }
                }
            }
        }
    }
    if(all == 0)
    {
        printf("%s doesn't exist\n", name);
    }
    chdir(current);
    return;
}

void where_are_we(char* addres)
{
    system("touch pwd.txt");
    system("pwd > pwd.txt");
    FILE* pwd = fopen("pwd.txt", "r");
    fgets(addres, 1000, pwd);
    addres[strlen(addres) - 1] = '\0';
}
int if_exist(char* addres)
{
    char current[1024];
    getcwd(current, sizeof(current));
    while(1)
    {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        DIR* dir = opendir(".");
        struct dirent* entry;
        if(strcmp(cwd, "/") == 0)
        {
            chdir(current);
            closedir(dir);
            return 0;
            break;
        }
        while(entry = readdir(dir))
        {
            if(!strcmp(entry->d_name, ".hapgit"))
            {
                closedir(dir);
                chdir(".hapgit");
                getcwd(addres, 1024);
                chdir(current);
                // printf("%s\n", addres);
                return 1;

            }
        }
        chdir("..");
    }
}
void git()
{
    char *current_place = (char*)calloc(1024, sizeof(char));
    getcwd(current_place, 1024);
    // where_are_we(current_place);
    char string[1024];
    if(if_exist(string))
    {
        printf("Repository already exists\n");
    }
    else
    { 
        chdir(current_place);
        mkdir(".hapgit", 0777);
        chdir(".hapgit");
        //directories:
        system("touch staged_files.txt");
        system("touch tracked.txt");
        system("touch last_staged.txt");
        // mkdir("commits", 0777);
        char name_tt[MAX_ADD] = "/home/mahan/hapgit/name.txt";
        if(exist(name_tt))
        {
            FILE* nametxt = fopen(name_tt, "r");
            char globname[MAX_FILE_NAME];
            fscanf(nametxt, "%s", globname);
            FILE* locname = fopen("name.txt", "w");
            fprintf(locname, "%s", globname);
            fclose(locname);
        }
        char email_tt[MAX_ADD] = "/home/mahan/hapgit/email.txt";
        if(exist(email_tt))
        {
            FILE* emailtxt = fopen(email_tt, "r");
            char globemail[MAX_FILE_NAME];
            fscanf(emailtxt, "%s", globemail);
            FILE* locemail = fopen("email.txt", "w");
            fprintf(locemail, "%s", globemail);
            fclose(locemail);
        }
        FILE* com = fopen("last_commit.txt", "w");
        fprintf(com, "0");
        fclose(com);
        FILE* branch = fopen("branches.txt", "w");
        fprintf(branch, "master\n");
        FILE* c_brach = fopen("current_branch.txt", "w");
        fprintf(c_brach, "master");
        fclose(branch);
        fclose(c_brach);
        FILE* list_of_commits = fopen("list_of_commits.txt", "w");
        fclose(list_of_commits);
        FILE* current_cum = fopen("current_commit.txt", "w");
        FILE* if_can_commit = fopen("commit_allowed.txt", "w");
        FILE* alias = fopen("alias", "w");
        fclose(alias);
        fprintf(if_can_commit, "%d", 1);
        fclose(if_can_commit);
        fprintf(current_cum, "0");
        FILE* hook_list = fopen("hook_list", "w");
        fprintf(hook_list, "todo-check\nformat-check\nbalance-braces\nfile-size-check\ncharacter-limit\neof-blank-space\n");
        fclose(hook_list);
        hook_list = fopen("applied_hooks", "w");
        fclose(hook_list);
        mkdir("branches", 0777);
        chdir("branches");
        mkdir("master", 0777);
        chdir("..");
        FILE* k = fopen("place_and_id", "w");
        fclose(k);
        k = fopen("show_tag", "w");
        fclose(k);
        k = fopen("tag_history", "w");
        fclose(k);
        //
        char current[MAX_ADD];
        getcwd(current, sizeof(current));
        chdir("/home/mahan/hapgit");
        FILE* addresses = fopen("addres.txt", "a");
        fprintf(addresses, "%s/.hapgit\n", current_place);
        




        chdir(current);
        printf("Initialized successfully!\n");
    }        
}
void global_name(char* nameof)
{
    char* current_addres = (char*)malloc(100 * sizeof(char));
    where_are_we(current_addres);
    chdir("/home/mahan/hapgit");
    FILE* f = fopen("name.txt", "w");
    fprintf(f, "%s", nameof);
    fclose(f);
    char path[100];
    int how = 0;
    FILE* addresses = fopen("addres.txt", "r");
    while(fgets(path, 100, addresses))
    {
        path[strlen(path) - 1] = '\0';
        char command[MAX_COMMAND] = "cp name.txt ";
        strcat(command, path);
        system(command);

    }

}
void global_email(char* nameof)
{
    char* current_addres = (char*)malloc(100 * sizeof(char));
    where_are_we(current_addres);
    chdir("/home/mahan/hapgit");
    FILE* f = fopen("email.txt", "w");
    fprintf(f, "%s", nameof);
    fclose(f);
    char path[100];
    int how = 0;
    FILE* addresses = fopen("addres.txt", "r");
    while(fgets(path, 100, addresses))
    {
        path[strlen(path) - 1] = '\0';
        char command[MAX_COMMAND] = "cp email.txt ";
        strcat(command, path);
        system(command);
    }
}
void local_name(char* nameof)
{
    chdir(".hapgit");
    FILE* name = fopen("name.txt", "w");
    fprintf(name, "%s", nameof);
}
void local_email(char* nameof)
{
    chdir(".hapgit");
    FILE* email = fopen("email.txt", "w");
    fprintf(email, "%s", nameof);
}
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("invalid command\n");
    }
    
    if(!strcmp(argv[1], "init"))
    {
        git();
    }
    else if(!strcmp(argv[1], "config"))
    {

        if(!strcmp(argv[2], "user.name"))
        {
            local_name(argv[3]);
        }
        else if(!strcmp(argv[2], "user.email"))
        {
            local_email(argv[3]);
        }
        else if(!strncmp(argv[2], "alias.", 6))
        {
            local_alias(argv[2], argv[3]);
        }
        else if(!strcmp(argv[2], "-global"))
        {
            if(!strcmp(argv[3], "user.name"))
            {
                global_name(argv[4]);
            }
            if(!strcmp(argv[3], "user.email"))
            {
                global_email(argv[4]);
            }
            if(!strncmp(argv[3], "alias.", 6))
            {
                glob_alias(argv[3], argv[4]);
                // local_alias(argv[2], argv[3]);
            }
        }
    }
    else if(!strcmp(argv[1], "add"))
    {

        char folder[1024] = ".";
        char string[1024];
        if(if_exist(string)){
            if(strcmp(argv[2], "-n") && strcmp(argv[2], "-redo")){
        char ad[1024];
        strcpy(ad, string);
        strcat(ad, "/last_staged.txt");
        FILE* file = fopen(ad, "w");
        fclose(file);
            }
       if(!strcmp("-f", argv[2]))
        {
            for (int i = 3; i < argc; i++){
                add(argv[i], folder);
            }
            
        }
        else if(!strcmp("-n", argv[2]))
        {
            add_n();
        } 
        else if(!strcmp(argv[2], "-redo"))
        {
            redo();
        } 
        else {
        for (int i = 2; i < argc; i++)
        {
            add(argv[i], folder);
        }
        // system("pwd");
        
    }
        }
        else printf("Hapgit has not been initialized yet!\n");
    }
        
    else if(!strcmp(argv[1], "reset"))
    {
        char folder[1024] = ".";
        char string[50];
        if(if_exist(string)){
            if(!strcmp(argv[2], "-undo"))
            {
                undo();
            }
            else
        if(!strcmp(argv[2], "-f"))
        {
            for (int i = 3; i < argc; i++)
            {
                reset(argv[i], folder);                
            }
            
        }
        else 
        {
            for (int i = 2; i < argc; i++)
            {
                reset(argv[i], folder);
            }
            
        }
        }
        else existance_error;
    }
    else if(!strcmp(argv[1], "status"))
    {
        char string[MAX_ADD];
        if(if_exist(string))
        {
            status();
        }
        else existance_error;
    }
    else if(!strcmp(argv[1], "commit"))
    {
        char string[MAX_ADD];
        if(if_exist(string)){
        if(!strcmp(argv[2], "-m"))
        {
            if(argc == 4)
            {
                if(strlen(argv[3]) > 72)
                {
                    printf("Your commit message is too long!\n");
                }
                else commit(argv[3]);
            }
            else if(argc < 4)
            {
                printf("Enter a commit message\n");
            }
            else{
                    printf("Put your message between \"\"\n");
            }
        }
        else if(!strcmp(argv[2], "-s"))
        {
            chdir(string);
            char path[MAX_ADD];
            realpath(argv[3], path);
            if(exist(path))
            {
                FILE* shortc = fopen(path, "r");
                char mess[MAX_MES_NAME];
                // fscanf(shortc, "%s", mess);
                fgets(mess, sizeof(mess), shortc);
                if(mess[strlen(mess) - 1] == '\n')
                {
                    mess[strlen(mess) - 1] = 0;
                }
                commit(mess);
            }
            else printf("You have to set the shortcut first!\n"); 
        }
        }
        else existance_error;
    }
    else if(!strcmp(argv[1], "log"))
    {
        char string[MAX_ADD];
        if(if_exist(string))
        {
            chdir(string);
        FILE* file = fopen("list_of_commits.txt", "r");
        if(argc == 2)
        {
            char line[MAX_ADD];
            while(fgets(line, sizeof(line), file))
            {
                printf("%s", line);
            }
        }
        else if(strcmp(argv[2],"-n") == 0)
        {
            int i = 0;
            int number;
            sscanf(argv[3], "%d", &number);
            char line[MAX_ADD];
            while(fgets(line, sizeof(line), file))
            {
                if(i == number)
                    break;
                printf("%s", line);
                i++;
            }
        }
        else if(strcmp(argv[2], "-branch") == 0)
        {
            char line[MAX_ADD];
            int flag = 0;
            while(fgets(line, sizeof(line), file))
            {
                char mess[80], date[200], branch[100],  author[100];
                int id , number_of_commited;
                sscanf(line, "commit id: %d\tauthor: %s\tbranch: %s\tnumber of files commited: %d\tmessage: %s\ttime commited: %s", &id, author, branch, &number_of_commited, mess, date);
                if(!strcmp(argv[3], branch))
                {
                printf("%s", line);
                flag = 1;
                }
            }
            if(flag == 0)
            {
                printf("Branch doesn't exist\n");
            }
        }
        else if(!strcmp(argv[2], "-since"))
        {
            char line[MAX_ADD];
            char sice_time[1024];
            strcpy(sice_time, argv[3]);
            strcat(sice_time, " ");
            strcat(sice_time, argv[4]);
            
            while(fgets(line, sizeof(line), file))
            {
                int flag = 0;
                char mess[100], date[300], branch[100],  author[100];
                int id , number_of_commited;
                sscanf(line, "commit id: %d\tauthor: %s\tbranch: %s\tnumber of files commited: %d\tmessage: %s\ttime commited: %[^\n]s", &id, author, branch, &number_of_commited, mess, date);
                if(compare_times(date, sice_time) > 0)
                {
                    printf("%s", line);
                }

            }
        }
        else if(!strcmp(argv[2], "-before"))
        {
            char line[MAX_ADD];
            char sice_time[1024];
            strcpy(sice_time, argv[3]);
            strcat(sice_time, " ");
            strcat(sice_time, argv[4]);
            
            while(fgets(line, sizeof(line), file))
            {
                int flag = 0;
                char mess[100], date[300], branch[100],  author[100];
                int id , number_of_commited;
                sscanf(line, "commit id: %d\tauthor: %s\tbranch: %s\tnumber of files commited: %d\tmessage: %s\ttime commited: %[^\n]s", &id, author, branch, &number_of_commited, mess, date);
                if(compare_times(date, sice_time) < 0)
                {
                    printf("%s", line);
                }

            }
        }
        else if(!strcmp(argv[2], "-search"))
        {
            char line[MAX_ADD];
            while(fgets(line, sizeof(line), file))
            {
                int flag = 0;
                char mess[100], date[200], branch[100],  author[100];
                int id , number_of_commited;
                sscanf(line, "commit id: %d\tauthor: %s\tbranch: %s\tnumber of files commited: %d\tmessage: %[^\t]s\ttime commited: %s", &id, author, branch, &number_of_commited, mess, date);
                // printf("mess: %s\n", mess);
                for(int i = 3; i < argc; i++)
                {
                    // char word[200] = " ";
                    // strcat(word, argv[i]);
                    // strcat(word, "");
                    // char temp_word[200];
                    
                    if(strstr(mess, argv[i]))
                    {

                        printf("%s", line);
                        break;
                    }
                }
            }
        }
        else if(!strcmp(argv[2], "-author"))
        {
            char line[MAX_ADD];
            int flag = 0;
            while(fgets(line, sizeof(line), file))
            {
                char mess[80], date[200], branch[100],  author[100];
                int id , number_of_commited;
                sscanf(line, "commit id: %d\tauthor: %s\tbranch: %s\tnumber of files commited: %d\tmessage: %s\ttime commited: %s", &id, author, branch, &number_of_commited, mess, date);
                if(!strcmp(argv[3], author))
                {
                printf("%s", line);
                flag = 1;
                }
            }
        }
    }
        else existance_error;
    }
    else if(!strcmp(argv[1], "branch"))
    {
        char string[1024];
        if(if_exist(string))
        {
            char current[1024];
            getcwd(current, sizeof(current));
            chdir(string);
            FILE *file = fopen("branches.txt", "r");
            if(argc == 2){
            char line[1024];
            while (fgets(line, sizeof(line), file))
            {
                printf("%s", line);
            }
            

            }
            else
            {
            char line[1024];
            int flag = 1;
            while (fgets(line, sizeof(line), file))
            {
                if(line[strlen(line) - 1] == '\n')
                    line[strlen(line) - 1] = '\0';
                if(!strcmp(argv[2], line))
                {
                    flag = 0;
                    fclose(file);
                    printf("Branch exists\n");
                    break;
                }
            }
            if(flag)
            {
                FILE* f = fopen("branches.txt", "a");
                fprintf(f, "%s\n", argv[2]);
                run_branch(argv[2]);
            }
            }
        
        }
        else existance_error;
    }
    else if(!strcmp(argv[1], "set"))
    {
        char string[MAX_ADD];
        if(if_exist(string))
        {
        if(argc < 6)
        {
            printf("Enter a shortcut!\n");
        }
        else {
            chdir(string);
            FILE* shortcut = fopen(argv[5], "w");
            fprintf(shortcut, "%s", argv[3]);
            fclose(shortcut);
        }
        }
        else existance_error;
    }
    else if(!strcmp(argv[1], "replace"))
    {
        char string[MAX_ADD];
        if(if_exist(string))
        {
        if(argc < 6)
        {
            printf("Enter a shortcut!\n");
        }
        else {
            chdir(string);
            char path[MAX_ADD];
            realpath(argv[5], path);
            if(exist(path)){
            FILE* shortcut = fopen(argv[5], "w");
            fprintf(shortcut, "%s", argv[3]);
            fclose(shortcut);
            }
            else printf("You have to set the shortcut first!\n" );
        }
        }
        else existance_error;
    }
    else if(!strcmp(argv[1], "remove"))
    {
        char string[MAX_ADD];
        if(if_exist(string))
        {
            chdir(string);
            char path[1024];
            realpath(argv[3], path);
            if(exist(path)){
            remove(argv[3]);
            }
            else printf("You have to set the shortcut first!\n");
        
        }
        else existance_error;
    }
    else if(!strcmp(argv[1], "checkout"))
    {
        if(argc < 3)
        {
            printf("invallid command!\n");
        }
        else 
        {

            char addres[1024];
            if(if_exist(addres))
            {
                chdir(addres);
                if(!strcmp(argv[2], "HEAD"))
                {
                    // printf("kk");
                    FILE* write = fopen("commit_allowed.txt", "w");
                    fprintf(write, "%d", 1);
                    char from[1024];
                    strcpy(from, addres);
                    strcat(from, "/branches/");
                    FILE* id = fopen("current_commit.txt", "r");
                    char idd[100];
                    fscanf(id, "%s", idd);
                    fclose(id);
                    id = fopen("current_branch.txt", "r");
                    char branch[1024];
                    fscanf(id, "%s", branch);
                    strcat(from, branch);
                    strcat(from, "/");
                    strcat(from, idd);
                    checkout(from);
                    return 0;
                }
                chdir(addres);
                // printf("ls");
                if(!chek_if_check())
                {
                    printf("You can't checkout without commiting changes\n");
                    // return 0;
                }
                FILE* read = fopen("branches.txt", "r");
                char line[1024];
                while(fgets(line, sizeof(line), read))
                {
                    if(line[strlen(line) - 1] == '\n')
                    {
                        line[strlen(line) - 1] = '\0';
                    }
                    if(!strcmp(line, argv[2]))
                    {
                        // printf("kos");
                        FILE* write = fopen("current_branch.txt", "w");
                        fprintf(write, "%s", line);
                        fclose(write);
                        int id = last_branch_id(argv[2]);
                        write = fopen("current_commit.txt", "w");
                        fprintf(write, "%d", id);
                        chdir("branches");
                        chdir(argv[2]);

                        char idd[1024];
                        sprintf(idd, "%d", id);
                        chdir(idd);
                        char add[1024];
                        getcwd(add, sizeof(add));
                        checkout(add);
                        // printf("%s", add);
                        // printf("%d", id);
                        chdir(addres);
                        FILE* writed = fopen("commit_allowed.txt", "w");
                    fprintf(writed, "%d", 1);
                        return 0;
                    }

                }
                fclose(read);
                chdir(addres);
                FILE* file = fopen("place_and_id", "r");
                char line2[1024];
                while(fgets(line2, sizeof(line2), file))
                {
                    char add[1024], id[1024];
                    sscanf(line2, "%s %s\n", add, id);
                    // printf("id:%s\n", id);
                    if(!strcmp(id,  argv[2]))
                    {
                        checkout(add);
                        rewind(file);
                        FILE* write = fopen("commit_allowed.txt", "w");
                        fprintf(write, "%d", 0);
                    return 0;
                    }
                }
            }
            else existance_error;
        }
    }
    
    else if(!strcmp(argv[1], "revert"))
    {
        char add[1024];
        if(if_exist(add))
        {
            chdir(add);
            if(!strcmp(argv[2], "-n"))
            {
                FILE* search = fopen("place_and_id", "r");
                char line[1024];
                while (fgets(line, 1024, search))
                {
                    char from[1024], id[100];
                    sscanf(line, "%s %s\n", from, id);
                    if(!strcmp(argv[3], id))
                    {
                        checkout(from);
                        return 0;
                    }
                }
                
            }
        
            else
            {
                chdir(add);
                char checkout_add[1024];
                if(!strncmp("HEAD", argv[argc - 1], 4))
                {
                // printf("kos");

                    int number;
                    sscanf(argv[argc - 1], "HEAD-%d", &number);
                    FILE* cur = fopen("current_commit.txt", "r");
                    int id;
                    fscanf(cur, "%d", &id);
                    id -= number;
                    rewind(cur);
                    fclose(cur);
                    char idd[100];
                    sprintf(idd, "%d", id);
                    // printf("idd:%s\n", idd);
                     FILE *f = fopen("place_and_id", "r");
                    char line[1024];
                    while(fgets(line, 1024, f))
                    {
                        char place[1024], idf[100];
                        sscanf(line, "%s %s\n", place, idf);
                        // printf("idf: %s\n", idf);
                        if(!strcmp(idf, idd))
                        {
                            strcpy(checkout_add, place);
                            break;
                            // printf("lps");
                        }
                    }
                    fclose(f);
                }
                else 
                {
                    FILE *f = fopen("place_and_id", "r");
                    char line[1024];
                    while(fgets(line, 1024, f))
                    {
                        char place[1024], id[100];
                        sscanf(line, "%s %s\n", place, id);
                        if(!strcmp(id, argv[argc - 1]))
                        {
                            strcpy(checkout_add, place);
                            break;
                        }
                    }
                    fclose(f);
                }
                checkout(checkout_add);
                int current_id;
                FILE* curid = fopen("last_commit.txt", "r");
                fscanf(curid,"%d",&current_id);

                // system("pwd");
                // printf("cad:%s\n", checkout_add);
                fclose(curid);
                curid = fopen("current_commit.txt", "w");

                fprintf(curid, "%d", current_id + 1);
                fclose(curid);
                curid = fopen("last_commit.txt", "w");

                fprintf(curid, "%d", current_id + 1);
                fclose(curid);
                char mess[1024];
                FILE* file = fopen("list_of_commits.txt", "r");
                if(argc > 3)
                {
                    strcpy(mess, argv[3]);
                }

                else
                {
                    char line[1024];
                    while(fgets(line, 1024, file))
                    {
                        char message[100], date[200], branch[100],  author[100];
                        int ild , number_of_commited;
                        sscanf(line, "commit id: %d\tauthor: %s\tbranch: %s\tnumber of files commited: %d\tmessage: %[^\t]s\ttime commited: %s", &ild, author, branch, &number_of_commited, message, date);
                        if(current_id == ild)
                        {
                            strcpy(mess, message);
                            break;
                        }
                    }
                    rewind(file);
                }
                // system("pwd");
                rewind(file);
                FILE* write = fopen("temp.txt", "w");
                char author[MAX_MES_NAME];
                FILE* name_txt = fopen("name.txt", "r");
                fscanf(name_txt, "%s", author);
                fclose(name_txt);
                time_t rawtime;
                time_t now = time(NULL);
                struct tm *ptm = localtime(&now);
                char buf[256];
                strftime(buf, sizeof(buf), "%Y/%m/%d %H:%M", ptm);
                char branch[100];
                FILE* branches = fopen("current_branch.txt", "r");
                fscanf(branches, "%s", branch);
                FILE* list_of_cums = fopen("list_of_commits.txt", "r");
                fprintf(write, "commit id: %d\tauthor: %s\tbranch: %s\tnumber of files commited: %d\tmessage: %s\ttime commited: %s\n", current_id + 1, author, branch, 0, mess, buf);
                printf("commit id: %d\tmessage: \"%s\"\ttime commited: %s\n", current_id + 1, mess, buf);
                fclose(write);
                write = fopen("temp.txt", "a");
                char liin[MAX_ADD];
                while(fgets(liin, sizeof(liin), list_of_cums))
                {
                    fprintf(write, "%s", liin);
                }
                fclose(write);
                fclose(list_of_cums);
                remove("list_of_commits.txt");
                rename("temp.txt", "list_of_commits.txt");
                char to[1024];
                strcpy(to, add);
                strcat(to, "/branches/");
                strcat(to, branch);
                strcat(to, "/");
                char final_id[100];
                sprintf(final_id, "%d", current_id + 1);
                strcat(to, final_id);
                chdir(add);
                FILE* when = fopen("place_and_id", "a");
                fprintf(when,"%s %s\n" ,to, final_id);
                fclose(when);
                chdir("branches");
                chdir(branch);
                mkdir(final_id, 0777);
                chdir(checkout_add);
                DIR* dir = opendir(".");
                struct dirent* entry;
                while (entry = readdir(dir))
                {
                    char command[1000] = "cp ";
                    if(strcmp(entry->d_name, ".") && strcmp(entry->d_name, ".."))
                    {
                        if(entry->d_type == 4)
                        {
                            strcat(command, "-r ");
                        }
                        strcat(command, entry->d_name);
                        strcat(command, " ");
                        strcat(command, to);
                        // system("pwd");
                        // printf("cum:\t%s\n", command);
                        system(command);
                    }
                }
                

            }
        }
        else existance_error;
    }
    else if(!strcmp(argv[1], "grep"))
    {
        char string[1024];
        if(if_exist(string) == 0)
        {
            existance_error;
            return 0;
        }
        int if_line  = 0;
        if(!strcmp(argv[argc - 1], "-n"))
            if_line = 1;
            if(argc > 6)
            {
        if(!strcmp(argv[6], "-c"))
        {
            char add[1024];
            strcpy(add, string);
            strcat(add, "/place_and_id");
            FILE* file = fopen(add, "r");
            char line[1024];
            while(fgets(line, 1024, file))
            {
                char place[1024], id[100];
                sscanf(line, "%s %s\n", place, id);
                if(!strcmp(argv[7], id))
                {
                    chdir(place);
                    // printf("%s\n", place);
                    // system("pwd");
                    // return 0;
                    break;
                }
            }
        }
            }
            grep(argv[3], argv[5], if_line);
            // char path[1024];
            // realpath(argv[3], path);
            // printf("path:%s\n", path);
    }
    else if(!strcmp(argv[1], "tag"))
    {
        // debug;
        char addres[1024];
        if(!if_exist(addres))
        {
            existance_error;
            return 0;
        }
        chdir(addres);
        if(argc == 2)
        {
            char tag[100][1024];
            FILE* read = fopen("show_tag", "r");
            int size = 0;
            while(fgets(tag[size], 1024, read))
            {
                size++;
            }
            for (int i = 0; i < size; i++)
            {
                for(int j = 0; j < size - 1; j++)
                {
                    if(strcmp(tag[j], tag[j + 1]) > 0)
                    {
                        char temp[1024];
                        strcpy(temp, tag[j]);
                        strcpy(tag[j], tag[j + 1]);
                        strcpy(tag[j + 1], temp);
                    }
                }
            }
            for (int i = 0; i < size; i++)
            {
                printf("%s", tag[i]);
            }
            return 0;
            
        }
        else if(!strcmp(argv[2], "show"))
        {
            FILE* show = fopen("tag_history", "r");
            char line[1024];
            while (fgets(line, sizeof(line), show))
            {
                // printf("line:%s", line);
                char tag[1024], commit[100], author[100], date[100], email[100], mess[100];
                if(strstr(line, "Message"))
                {
                    char date1[1024], date2[1024];
                    sscanf(line, "tag: %s commit: %s author: %s Date: %s %s Message:%[^\n]s", tag, commit, author, date1, date2, mess);
                    if(strcmp(tag, argv[3]))
                    {
                        continue;
                    }
                    printf("tag: %s\ncommit: %s\nauthor: %s\nDate: %s %s\nMessage:%s\n",  tag, commit, author, date1, date2, mess);
                    break;
                }
                else
                {
                    sscanf(line, "tag: %s commit: %s author: %s Date: %[^\n]s", tag, commit, author, date);
                    if(strcmp(tag, argv[3]))
                    {
                        continue;
                    }
                    printf("tag: %s\ncommit: %s\nauthor: %s\nDate: %s\n",  tag, commit, author, date);
                    break;
                }
            }
            

            return 0;
        }
        int overwrite = 0;
        int overwrited = 0;
        if(!strcmp(argv[argc - 1], "-f"))
        {
            overwrite = 1;
            

        }
        int i = 0;
        FILE* read = fopen("tag_history", "r");
        char line[1024];
        while (fgets(line, sizeof(line), read))
        {
            char tag[1024], commit[100], author[100], date[100], email[100], mess[100];
            sscanf(line, "tag: %s commit: %s author: %s<%s> Date: %s Message: %s\n", tag, commit, author,email, date, mess);
            if(!strcmp(tag, argv[3]))
            {
                if(overwrite)
                {
                    char relpath[1024], name[1000] = "tag_history";
                    // realpath(name, relpath);
                    remove_line(name, i);
                    overwrited = 1;
                    break;
                }
                else   
                {
                    printf("The tag exist.\n");
                    return 0;
                }
            }
            i++;
        }
        fclose(read);
        int mess = 0;
        char current_id[100], branch[1024], message[1024];
        if(!strcmp(argv[4], "-m"))
        {
            mess = 1;
            strcpy(message, argv[5]);
        }
        if(!strcmp(argv[argc - 3], "-c") || !strcmp(argv[argc - 2], "-c"))
        {
            if(!strcmp(argv[argc - 3], "-c"))
                strcpy(current_id,  argv[argc - 2]);
            else             
                strcpy(current_id,  argv[argc - 1]);
        }
        else
        {
            FILE* id = fopen("current_commit.txt", "r");
            fscanf(id, "%s", current_id);
            fclose(id);
        }
        char name[100], email[100];
        FILE* username = fopen("name.txt", "r");
        fscanf(username, "%s", name);
        fclose(username);
        username = fopen("email.txt", "r");
        fscanf(username, "%s", email);
        fclose(username);
        FILE* history = fopen("tag_history", "a");
        if(mess == 0)
        {
            time_t rawtime;
            time_t now = time(NULL);
            struct tm *ptm = localtime(&now);
            char buf[256];
            strftime(buf, sizeof(buf), "%Y/%m/%d %H:%M", ptm);
            fprintf(history, "tag: %s commit: %s author: %s<%s> Date: %s\n",  argv[3], current_id, name, email, buf);
        }
        else
        {
            time_t rawtime;
            time_t now = time(NULL);
            struct tm *ptm = localtime(&now);
            char buf[256];
            strftime(buf, sizeof(buf), "%Y/%m/%d %H:%M", ptm);
            fprintf(history, "tag: %s commit: %s author: %s<%s> Date: %s Message: %s\n",  argv[3], current_id, name, email, buf, message);
        }
        fclose(history);
        if(overwrited == 0)
        {
            history = fopen("show_tag", "a");
            fprintf(history, "%s\n", argv[3]);
        }
    }
    else if(!strcmp(argv[1], "diff"))
    {
        if(!strcmp(argv[2], "-f"))
        {
            // printf("ls");
            int start1 = 0;
            int finish1 = 10000000;
            int start2 = 0, finish2 = 1000000;
            if(!strcmp(argv[argc - 2], "-line2"))
            {
                int temp1, temp2;
                sscanf(argv[argc - 1], "%d-%d", &temp1, &temp2);
                start2 = temp1;
                finish2 = temp2;
                
            }
            if(!strcmp(argv[argc - 2], "-line1"))
            {
                int temp1, temp2;
                sscanf(argv[argc - 1], "%d-%d", &temp1, &temp2);
                start1 = temp1;
                finish1 = temp2;
            }
            if(!strcmp(argv[argc - 4], "-line1"))
            {
                int temp1, temp2;
                sscanf(argv[argc - 3], "%d-%d", &temp1, &temp2);
                start1 = temp1;
                finish1 = temp2;
            }
            // printf("%s %s %s", argv[3], argv[4],)
            diff(argv[3],start1, finish1, argv[4], start2, finish2, argv[3], argv[4]);
        }
        else
        {
            char line[1024];
            char addres[1024];
            if(if_exist(addres))
            {
                chdir(addres);
                char first[1024], second[1024];
                FILE* file = fopen("place_and_id", "r");
                while((fgets(line, sizeof(line), file)))
                {
                    char place[1024], id[100];
                    sscanf(line, "%s %s\n", place, id);
                    if(!strcmp(argv[3], id))
                    {
                        strcpy(first, place);
                        rewind(file);
                        break;
                    }
                }
                while((fgets(line, sizeof(line), file)))
                {
                    char place[1024], id[100];
                    sscanf(line, "%s %s\n", place, id);
                    if(!strcmp(argv[4], id))
                    {
                        strcpy(second, place);
                        rewind(file);
                        break;
                    }
                }
                fclose(file);
                chdir(first);
                // system("pwd");
                FILE* first_file = fopen("commited.txt", "r");
                chdir(second);
                FILE* second_file = fopen("commited.txt", "r");
                // fclose(second_file);
                // fclose(first_file);
                char line1[1024];
                char add_plus[1024];
                strcpy(add_plus, addres);
                for (int i = strlen(add_plus) - 1; i >= 0; i--)
                {
                    if(add_plus[i] == '/')
                    {
                        for (int j = i; j < strlen(add_plus); j++)
                        {
                            add_plus[j] = '\0';
                        }
                        break;
                    }
                }
                // printf("%s\n", add_plus);
                
                while (fgets(line1, sizeof(line1), first_file))
                {
                    char name[1024], hash[1024];
                    sscanf(line1,  "%s %s\n", name, hash);
                    char line2[1024];
                    while(fgets(line2, sizeof(line2), second_file))
                    {
                        char name2[1024], hash2[1024];
                        sscanf(line2,  "%s %s\n", name2, hash2);
                        if(!strcmp(name2, name))
                        {
                            char first_place[1024], second_place[1024];
                            strcpy(first_place, first);
                            strcpy(second_place, second);
                            // strcat(second_place, "/");
                            // strcat(first_place, "/");
                            strcat(first_place, name + strlen(add_plus));
                            strcat(second_place, name2 + strlen(add_plus));
                            // printf("second_line:%s  first_line:%s\n", first_place, second_place);
                            char show1[1024];
                            strcpy(show1, argv[3]);
                            strcat(show1, "|");
                            strcat(show1, name + strlen(add_plus) + 1);
                            char show2[1024];
                            strcpy(show2, argv[4]);
                            strcat(show2, "|");
                            strcat(show2, name + strlen(add_plus) + 1);
                            diff(first_place, 0, 100000, second_place, 0, 10000, show1, show2);
                        }
                    }
                    rewind(second_file);
                }
                
            }
            else existance_error;
        }
    }
    else if(!strcmp(argv[1], "pre-commit"))
    {
        char string[1024];
        if(if_exist(string))
        {
            chdir(string);
            char add[1024];
            strcpy(add, string);
            for (int i = strlen(add) - 1; i >= 0; i--)
            {
                if(add[i] == '/')
                {
                    add[i] = '\0';

                    break;
                }
            }
            
            if(argc == 2)
            {
                chdir(string);
                FILE* stage = fopen("staged_files.txt", "r");
                char line[1024];
                while (fgets(line, 1024, stage))
                {
                    char name[1024], hash[1024];
                    sscanf(line, "%s %s\n", name, hash);
                    FILE* file = fopen("applied_hooks", "r");
                    char line2[1024];
                    printf("%s:\n", name + strlen(add) + 1);
                    while (fgets(line2, sizeof(line2), file))
                    {
                        char answer[1024];
                        if(line2[strlen(line2) - 1] == '\n')
                            line2[strlen(line2) - 1] = '\0';
                        if(!strcmp(line2, "todo-check"))
                        {
                            todo_check(answer, name);
                            printf("\033[31m%s..................................%s\n\033[0m", "todo-check", answer);
                        }
                        if(!strcmp(line2, "format-check"))
                        {
                            format_check(answer, name);
                            printf("\033[32m%s..................................%s\n\033[0m", "format-check", answer);
                        }
                        if(!strcmp(line2, "balance-braces"))
                        {
                            balance_braces(answer, name);
                            printf("\033[35m%s..................................%s\n\033[0m", "balance-braces", answer);
                        }
                        if(!strcmp(line2, "character-limit"))
                        {
                            char_limit(answer, name);
                            printf("\033[34m%s..................................%s\n\033[0m", "character-limit", answer);
                        }
                        if(!strcmp(line2, "file-size-check"))
                        {
                            file_size_check(answer, name);
                            printf("\033[33m%s..................................%s\n\033[0m", "file-size-check", answer);
                        }
                        if(!strcmp(line2, "eof-blank-space"))
                        {
                            eof_blank_space(answer, name);
                            printf("\033[36m%s..................................%s\n\033[0m", "eof-blank-space", answer);
                        }
                    }
                    
                }
                
            }
            else if(!strcmp(argv[2], "hooks"))
            {
                FILE* file = fopen("hook_list", "r");
                if (file == NULL) return -1;
                char line[1024];
                while(fgets(line, sizeof(line), file))
                {
                    printf("%s", line);
                }
                return 0;
            }
            else if(!strcmp(argv[2], "applied"))
            {
                FILE* file = fopen("applied_hooks", "r");
                if (file == NULL) return -1;
                char line[1024];
                while(fgets(line, sizeof(line), file))
                {
                    printf("%s", line);
                }
                return 0;
            }
            else if(!strcmp(argv[2], "add"))
            {
                FILE* file = fopen("applied_hooks", "a");
                fprintf(file, "%s\n", argv[4]);
            }
            else if(!strcmp("remove", argv[2]))
            {
                FILE* file = fopen("applied_hooks", "r");
                if(file == NULL) return 1;
                char line[1024];
                int i = 0;
                char hook[1024] = "applied_hooks";
                while (fgets(line, 1024, file))
                {
                    if(line[strlen(line) - 1] == '\n')
                        line[strlen(line) - 1] = '\0';
                    if(!strcmp(argv[4], line))
                    {
                        remove_line(hook, i);
                        // break;
                    }
                    i++;
                }
                return 0;
            }
            
        }

    }
    else
    {
        char add[1024];
        if(argc < 2)
        {
            return 0;
        }
        if(if_exist(add))
        {
            char alias[1024];
            strcpy(alias, add);
            strcat(alias, "/alias");
            FILE* file = fopen(alias, "r");
            char line[1024];
            while(fgets(line, 1024, file))
            {
                // printf("%s", line);
                char alias[1024], command[1024];
                sscanf(line, "%s %[^\n]s\n", alias, command);
                if(!strcmp(argv[1], alias))
                {
                    system(command);
                    return 0;
                }
            }
            fclose(file);
            file = fopen("/home/mahan/hapgit/alias", "r");
             while(fgets(line, 1024, file))
            {
                // printf("%s", line);
                char alias[1024], command[1024];
                sscanf(line, "%s %[^\n]s\n", alias, command);
                if(!strcmp(argv[1], alias))
                {
                    system(command);
                    return 0;
                }
            }
        }
    }
}
//int  df asfdj;afdsjasf int afs;ajf int afs int
   
