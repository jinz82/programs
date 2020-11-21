/*EPI: Levenshtein Distance between 2 words.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c)
{

if ((a < b) && (a < c))
 return a;
else if ((b < c) && (b < a))
 return b; 
else
 return c;
}

int lev_dist(char a[],char b[], int i, int j)
{
 if (i < 0)
  return (j+1);
 else if (j < 0)
  return (i+1);

  if (a[i] == b[j])
   return lev_dist(a,b,(i-1),(j-1));
  else {
   int add = lev_dist(a,b,(i-1),j);
   int sub = lev_dist(a,b,i,(j-1));
   int rep = lev_dist(a,b,(i-1),(j-1));
   return(1 + min(add,sub,rep));  
  }
}


int main()
{
 int i;
 char *a = "bookangcal";
 char *b = "backingazalsim";

 printf("\nDistance = %d\n", lev_dist(a,b,strlen(a)-1,strlen(b)-1));

return 1;
}
