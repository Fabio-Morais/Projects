#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define len 200

int valid(char name[len])
{
    char *token, s[2]=".";

    token=strtok(name, s);
    token = strtok(NULL, s);
    if(token==NULL)
        strcat(name, ".txt");
    else
        if(strcmp(token, "txt"))
            return 0;
    return 1;
}


int file_read(char name[len], char name_count[len])
{
    int validation, counter=0;
    char word[len];
    validation=valid(name);

    if(validation!=1)
        return -1;

    FILE *file=fopen(name, "r");
    if(file==NULL)
        return -2;
    while(fscanf(file, "%s", word)!=EOF)
        if(!strcmp(word, name_count))
            counter++;
    fclose(file);
    return counter;
}


int main()
{
    int validation;
    char name[len], name_count[len];
    for(;;)
    {
    printf("Enter the file name\n");
    scanf("%s", name);
    printf("Enter the name you want to count\n");
    scanf("%s", name_count);
    validation=file_read(name, name_count);
    if(validation==-2)
       printf("\7file dont exists\n\n");
    else
        printf("\n*the word %s was found %d times*\n\n\n", name_count, validation);
    system("pause");
    system("cls");
    }




    return 0;
}
