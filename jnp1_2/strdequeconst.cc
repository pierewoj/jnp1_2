#include<iostream>
#include "cstrdequeconst"
#include "cstrdeque"

namespace jnp1{
	
	unsigned long emptystrdeque()
	{
		static unsigned long empty = jnp1::strdeque_new();
		return empty;
	}
}
