#include <stdio.h>
#include <string.h>
#include <ctype.h>
int n, m = 0, p, i = 0, j = 0;
char productionsArray[10][10], followArray[10];

void follow(char c);
void first(char c);
int main()
{
  int i, z;
  char c, ch;
  printf("Enter the no. of Productions: ");
  scanf("%d", &n);
  printf("Enter the Productions (epsilon=$): \n");
  for (i = 0; i < n; i++)
  {
    scanf("%s%c", productionsArray[i], &ch);
  }
  do
  {
    m = 0;
    printf("Enter the element whose FOLLOW is to be found: ");
    scanf("%c", &c);
    follow(c);
    printf("FOLLOW(%c)= { ", c);
    for (i = 0; i < m; i++)
    {
      printf(" %c", followArray[i]);
    }
    printf(" }\n");
    printf("Do you want to continue (0/1)? ");
    scanf("%d%c", &z, &ch);
  } while (z == 1);
}
void follow(char c)
{
  if (productionsArray[0][0] == c)
    followArray[m++] = '$';
  for (i = 0; i < n; i++)
  {
    for (j = 2; j < strlen(productionsArray[i]); j++)
    {
      if (productionsArray[i][j] == c)
      {
        if (productionsArray[i][j + 1] != '\0')
          first(productionsArray[i][j + 1]);
        if (productionsArray[i][j + 1] == '\0' && c != productionsArray[i][0])
          follow(productionsArray[i][0]);
      }
    }
  }
}
void first(char c)
{
  int k;
  if ((islower(c)))
    followArray[m++] = c;
  for (k = 0; k < n; k++)
  {
    if (productionsArray[k][0] == c)
    {
      if (productionsArray[k][2] == '$')
      {
        follow(productionsArray[i][0]);
      }
      else if (islower(productionsArray[k][2]))
      {
        followArray[m++] = productionsArray[k][2];
      }
      else
        first(productionsArray[k][2]);
    }
  }
}