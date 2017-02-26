/**
 * CLASS MATCHING
 * contains details of al the boys, girls and couples
 */
#include<iostream>
#include<stdlib.h>
#include "matching.h"
using namespace std;
matching::matching()
{
	ct = 0;
	FILE *fp1, *fp2;
	fp1 = fopen("boys.txt", "r");
	fp2 = fopen("girls.txt", "r");
	int n;
	fscanf(fp1,"%d", &n);
	//boy b[20];
	//cout<<n<<endl;
	for(int i = 0; i < n; i++) {
		boy temp;
		fscanf(fp1,"%s %d %d %d %d %d", temp.name, &temp.attract, &temp.intel, &temp.budget, &temp.attr_req, &temp.type);
		b[i] = temp;
	}
	/*for(int i = 0; i < n; i++) {
		cout<<b[i].name<<" "<<b[i].attract<<" "<<b[i].intel<<" "<<b[i].budget<<" "<<b[i].attr_req<<" "<<b[i].type<<" "<<b[i].commited<<endl;
	}
	cout<<endl;*/
	int m;
	fscanf(fp2,"%d", &m);
	//girl g[10];
	for(int i = 0; i < m; i++) {
		girl temp;
		fscanf(fp2,"%s %d %d %d %d %d", temp.name, &temp.attract, &temp.intel, &temp.maintainance, &temp.type, &temp.choice);
		g[i] = temp;
	}
	/*for(int i = 0; i < m; i++) {
		cout<<g[i].name<<" "<<g[i].attract<<" "<<g[i].intel<<" "<<g[i].maintainance<<" "<<g[i].req<<" "<<g[i].type<<" "<<g[i].choice<<" "<<g[i].commited<<endl;
	}*/
	//couple c[10];
	for(int i = 0; i < m; i++) {
		int id = -1;
		boy max = b[0];
		for(int j = 0; j < n; j++) {
			if(b[j].budget < g[i].maintainance || g[i].attract < b[j].attr_req || b[i].commited == true) {
				continue;
			}
			if(g[i].choice == 1) {
				if(max.attract < b[j].attract) {
					max = b[j];
					id = j;
				}
			} else if(g[i].choice == 2) {
				if(max.budget < b[j].budget) {
					max = b[j];
					id = j;
				}
			} else {
				if(max.intel < b[j].intel) {
					max = b[j];
					id = j;
				}
			}
		}
		if(id != -1 && b[id].commited == false) {
			//printf("%s %s\n",max.name, g[i].name);
			c[ct++].commit(max, g[i]);
			//cout<<"$"<<id<<" "<<i<<endl;
			b[id].commited = true;
			g[i].commited = true;
		}
	}
}
void matching::gifting()
{
	FILE *fp1;
	fp1 = fopen("gift_store.txt","r");
	int n;
	gift store[30];
	fscanf(fp1,"%d", &n);
	for(int i = 0; i < n; i++) {
		fscanf(fp1, "%d", &store[i].type);
		if(store[i].type == 1) {
			fscanf(fp1, "%d %d", &store[i].e.price, &store[i].e.value);
		} else if(store[i].type == 2) {
			fscanf(fp1,"%d %d %d %d", &store[i].l.price, &store[i].l.value, &store[i].l.luxury, &store[i].l.difficulty);
		} else {
			fscanf(fp1,"%d %d %d", &store[i].u.price, &store[i].u.value, &store[i].u.utility);
		}
	}
	for(int i = 0; i < ct; i++) {
		c[i].bk = 0;
		//int flag = 0;
		c[i].basket[c[i].bk++] = store[0];
		if(store[0].type == 1) {
			c[i].giftcost += store[0].e.price;
			c[i].giftvalue += store[0].e.value;
		} else if(store[0].type == 2) {
			c[i].giftcost += store[0].l.price;
			c[i].giftvalue += store[0].l.value;
		} else {
			c[i].giftcost += store[0].u.price;
			c[i].giftvalue += store[0].u.value;
		}
		if(c[i].b.type == 1 || c[i].b.type == 3) {
			for(int j = 1; j < n; j++) {
				if(c[i].giftcost < c[i].g.maintainance) {
					c[i].basket[c[i].bk++] = store[j];
					if(store[j].type == 1) {
						c[i].giftcost += store[j].e.price;
						c[i].giftvalue += store[j].e.value;
					} else if(store[j].type == 2) {
						c[i].giftcost += store[j].l.price;
						c[i].giftvalue += store[j].l.value;
					} else {
						c[i].giftcost += store[j].u.price;
						c[i].giftvalue += store[j].u.value;
					}
				} 
			}
			if(c[i].b.budget < c[i].giftcost) {
				c[i].b.budget = c[i].giftcost;
			}
		} else {
			for(int j = 1; j < n; j++) {
				if(c[i].giftcost < c[i].g.maintainance) {
					c[i].basket[c[i].bk++] = store[j];
					if(store[j].type == 1) {
						c[i].giftcost += store[j].e.price;
						c[i].giftvalue += store[j].e.value;
					} else if(store[j].type == 2) {
						c[i].giftcost += store[j].l.price;
						c[i].giftvalue += store[j].l.value;
					} else {
						c[i].giftcost += store[j].u.price;
						c[i].giftvalue += store[j].u.value;
					}
					continue;
				}
				if(c[i].giftcost > c[i].b.budget) {
					c[i].b.budget = c[i].giftcost;
					break;
				} else {
					if(store[j].type == 1) {
						if(c[i].giftcost + store[j].e.price <= c[i].b.budget) {
							c[i].basket[c[i].bk++] = store[j];
							c[i].giftcost += store[j].e.price;
							c[i].giftvalue += store[j].e.value;
						} else {
							break;
						}
					} else if(store[j].type == 2) {
						if(c[i].giftcost + store[j].l.price <= c[i].b.budget) {
							c[i].basket[c[i].bk++] = store[j];
							c[i].giftcost += store[j].l.price;
							c[i].giftvalue += store[j].l.value;
						} else {
							break;
						}
					} else {
						if(c[i].giftcost + store[j].u.price <= c[i].b.budget) {
							c[i].basket[c[i].bk++] = store[j];
							c[i].giftcost += store[j].u.price;
							c[i].giftvalue += store[j].u.value;
						} else {
							break;
						}
					}
				}
			}
		} 
	}
}
void matching::sorting()
{
	srand(time(NULL));
	couple temp;
	for(int i = 0; i < ct-1; i++) {
		for(int j = 0; j < ct-i-1; j++) {
			if(c[j].happ < c[j+1].happ) {
				temp = c[j+1];
				c[j+1] = c[j];
				c[j] = temp;
			}
		}
	}
	int k = ((rand()%(ct+1)) + 1);
	cout<<"HAPPIEST "<<k<<" COUPLES-"<<endl<<endl;
	for(int i = 0; i < k; i++) {
		cout<<i<<" "<<c[i].b.name<<" "<<c[i].g.name<<endl;
		cout<<"HAPPINESS- "<<c[i].happ<<endl;
		cout<<"COMPATIBILITY- "<<c[i].cmp<<endl;
	
	}
	cout<<endl<<"COMPATIBLE "<<k<<" COUPLES-"<<endl<<endl;
	for(int i = 0; i < ct-1; i++) {
		for(int j = 0; j < ct-i-1; j++) {
			if(c[j].cmp < c[j+1].cmp) {
				temp = c[j+1];
				c[j+1] = c[j];
				c[j] = temp;
			}
		}
	}
	for(int i = 0; i < ct; i++) {
		cout<<i<<" "<<c[i].b.name<<" "<<c[i].g.name<<endl;
		cout<<"HAPPINESS- "<<c[i].happ<<endl;
		cout<<"COMPATIBILITY- "<<c[i].cmp<<endl;
	
	}
}