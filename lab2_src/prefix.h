/* Student Information
  Shterenberg, Simon
  Project 2
*/


#include <string>
#include <stack>
#include <math.h>
#include <algorithm>


double evaluate_prefix(std::string expr);
std::string infix_to_prefix(std::string infix);
std::string infix_to_postfix(std::string infix);
int getPriority(char c);
