#include <stdio.h>
#include <string.h>

int commentLineOrNot(char *line)
{
    if ((line[0] == '/' && line[1] == '/') ||
        ((line[0] == '/' && line[1] == '*') &&
         (line[strlen(line) - 1] == '/') && (line[strlen(line) - 2] == '*')))
    {
        return 1;
    }
    return 0;
}

int main()
{
    char line[100];
    printf("Enter a line:- ");
    scanf("%s", line);

    if (commentLineOrNot(line))
    {
        printf("It is a comment line\n");
    }
    else
    {
        printf("It is not a comment line\n");
    }
}