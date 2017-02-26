#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
/**@detail
 * Testing utility for randomly generatng details of all girls
 */
int main()
{
  srand(time(NULL));
  freopen("gift_store.txt", "w", stdout);

  int price[30], value[30], luxury[30], difficulty[30], utility[30], type[30];
  for(int i = 0; i < 30; i++) {
    type[i] = (rand()%3) + 1;
    price[i] = (rand()%1001) + 1;
    value[i] = rand()%11;
    if(type[i] == 1) {
      luxury[i] = 0;
      difficulty[i] = 0;
      utility[i] = 0;
    } else if(type[i] == 2) {
      luxury[i] = (rand()%11)+1;
      difficulty[i] = (rand()%11)+1;
      utility[i] = 0;
    } else {
      luxury[i] = 0;
      difficulty[i] = 0;
      utility[i] = (rand()%11)+1;
    }
  } 
  sort(price, price + 30);
  printf("30\n");
  for(int i = 0; i < 30; i++) {
    if(type[i] == 1) {
      printf("%d %d %d\n", type[i], price[i], value[i]);
    } else if(type[i] == 2) {
      printf("%d %d %d %d %d\n", type[i], price[i], value[i], luxury[i], difficulty[i]); 
    } else {
      printf("%d %d %d %d\n", type[i], price[i], value[i], utility[i]);
    }
  }
}