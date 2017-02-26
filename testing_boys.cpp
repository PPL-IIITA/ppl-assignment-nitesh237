#include<iostream>
#include<stdlib.h>
using namespace std;
/**@detail
 * Testing utility for randomly generatng details of all boys
 */

int main()
{
	srand(time(NULL));
	freopen("boys.txt", "w", stdout);
	//char **bname;
	/*bname = (char **)malloc(20*sizeof(char *));
  	for(int i=0;i<20;i++)
    {
      bname[i]=(char *)malloc((6)*sizeof(char));
      for(int j=0;j<5;j++)
	  bname[i][j]=(rand()%26)+65;
      bname[i][5]='\0';
    }*/
  string bname[] = {"MATT", "JOHN", "TYRIAN", "TRAVIS", "MIKE", "HARVEY", "LOUIS", "TONNY", "SAM", "HARRY", "ROHN", "DANIEL", "FOGGY", "JAMES", "BEN", "EDWARD", "BRUCE", "HODOR", "WILL", "PETER"};
 	int battract[20], bintel[20], bbudget[20], batt_req[20], btype[20]; 
 	for(int i = 0; i < 20; i++) {
 		battract[i] = (rand()%51) + 1;
 		bintel[i] = (rand()%51) + 1;
 		bbudget[i] = (rand()%5001) + 1;
 		batt_req[i] = (rand()%51) + 1;
 		btype[i] = (rand()%3) + 1;
 	} 
 	printf("20\n");
 	for(int i = 0; i < 20; i++) {
    cout<<bname[i]<<" ";
 		printf("%d %d %d %d %d \n",battract[i], bintel[i], bbudget[i], batt_req[i], btype[i]); 
 	}
}