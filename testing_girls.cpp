#include<iostream>
#include<stdlib.h>
using namespace std;
/**@detail
 * Testing utility for randomly generatng details of all gifts
 */
int main()
{
	srand(time(NULL));
	freopen("girls.txt", "w", stdout);
	/*char **gname;
	gname = (char **)malloc(10*sizeof(char *));
  	for(int i=0;i<10;i++)
    {
      gname[i]=(char *)malloc((6)*sizeof(char));
      for(int j=0;j<5;j++)
	  gname[i][j]=(rand()%26)+65;
      gname[i][5]='\0';
    }*/
  string gname[] ={"EMMA", "KAREN", "VANESSA", "CLAIRE", "GAO", "RACHEL", "DONA", "JESSICA", "LILLY", "SCOTTY"};
 	int gattract[10], gintel[10], gmaintain[10], greq[10], gtype[10], gchoice[10];
 	for(int i = 0; i < 10; i++) {
 		gattract[i] = (rand()%51) + 1;
 		gintel[i] = (rand()%51) + 1;
 		gmaintain[i] = (rand()%3001) + 1;
 		gtype[i] = (rand()%3) + 1;
    gchoice[i] = (rand()%3) + 1;
 	}  
    printf("10\n");
    for(int i = 0; i < 10; i++) {
        cout<<gname[i]<<" ";
        printf("%d %d %d %d %d\n", gattract[i], gintel[i], gmaintain[i], gtype[i], gchoice[i]); 
    }
}