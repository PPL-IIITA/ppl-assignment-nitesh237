/**
 * CLASS COUPLE
 * containing detail about couple
 */
#ifndef COUPLE.H_INCLUDED
#define COUPLE.H_INCLUDED
#include<stdio.h>
#include "boy.h"
#include "miser.h"
#include "generous.h"
#include "geek.h"
#include "choosy.h"
#include "normal.h"
#include "desparate.h"
#include "girl.h"
#include "gift.h"
class couple {
public:
	boy b; //!< Stores details of boy
	girl g; //!<Stores details of girl
	double happ; //!<Stores Happiness of Couple
	int cmp; //!<Stores Compatibilty of Couple
	int giftcost; //!< Stores total cost of gift exchanged during relationship
	int giftvalue; //!< Stores total value of gift exchanged during relationship
	int bk; //!< Stores the number of items in the basket
	gift basket[1000]; //!< The gift basket containing all the details of gifts
	/** @brief Initialises boy and girl in couple.
 	*
	* @param b1 object containing details of boy
 	* @param g1 object containing details of girl
	 */
	void commit(boy b1, girl g1); 
	void happiness(); //!< calculates the happiness of couple and stores it in happ
	void compatiblity(); //!< calculates the compatibility of couple and stores it in cmp
	
	couple() {			//! Initialises giftcost, giftvalue and bk to 0	
		giftcost = 0;
		giftvalue = 0;
		bk = 0;
	}
};
#endif