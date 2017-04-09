/**
 * CLASS UTILITY
 * containing detail about utility gift
 */
#include "gift.h"
class utility: public gift{
public:
	int utiility; //!< utility value of gift(out of 10)
	utility(int pr, int val, int ut) 
	{
		type = 3;
		price = pr;
		value = val;
		utiility = ut;
	}
};