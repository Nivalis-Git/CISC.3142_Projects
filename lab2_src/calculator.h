/* Student Information
  Shterenberg, Simon
  Project 2
*/


#include <iostream>

#include "prefix.h"


enum class Operation { add, sub, mlt, div, exp, sqrt, convert_toFraction};


struct Calculator
{
	Operation op;
	double eval {};
	
	// evaluate prefix expression
	void evaluate(std::string expr)
	{
		eval = evaluate_prefix( infix_to_prefix(expr) );
	}
};
