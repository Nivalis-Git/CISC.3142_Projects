/* Student Information
  Shterenberg, Simon
  Project 2
*/


#include <iostream>
#include <string>
#include <stack>
#include <math.h>
#include <algorithm>

#include "prefix.h"


//enum class Operation { add, sub, mlt, div, exp, sqrt, convert_toFraction};


struct Calculator
{
	//Operation op;
	double eval {};
	
	// evaluate prefix expression
	void evaluate(std::string expr)
	{
		std::string postfix = infix_to_postfix(expr);
		printf("Postfix: %s\n", postfix.c_str());
		
		
		std::string prefix = infix_to_prefix(expr);
		printf("Prefix: %s\n", prefix.c_str());
		
		eval = evaluate_prefix( infix_to_prefix(expr) );
	}
};
