/* Student Information
  Shterenberg, Simon
  Project 2
*/


#include "prefix.h"


double evaluate_prefix(std::string expr)
{
		std::stack<double> stack;
		int size = expr.size();
		
		for (int j = size-1; j >= 0; j--)
		{
		
			// i. skip delimiter
			if (expr[j] == ' ')
			{
				continue;
			}
			
			// ii. combine the digits in a number into a single value
			if ( isdigit(expr[j]) )
			{
				double whole = 0.0, frac = 0.0;
				
				int i = j;
				while ( j < size && isdigit(expr[j]) )
				{
					j--;
				}
				
				// a. calculate the fractional part
				if (expr[j]=='.')
				{
					for (int k = j+1; k <= i; k++)
					{
						frac += double(expr[k] - '0') / pow(10, (k-j));
					}
					
					// repeat prior while loop to reach past the last digit in the whole part
					j--;  // move past decimal
					i = j;
					while ( j < size && isdigit(expr[j]) )
					{
						j--;
					}
				}
				
				// b. calculate the integer part
				j++;  // move back to the leftmost digit of the number (<[][][][] --> []<[][][])
				for (int k = j; k <= i; k++)
				{
					whole = whole * 10 + double(expr[k] - '0');
				}
				
				stack.push(whole+frac);
			}
			
			// iii. operator found
			else
			{
				double o1 = stack.top();
				stack.pop();
				double o2 = stack.top();
				stack.pop();
			
				switch (expr[j])
				{
					case '+':
						stack.push(o1 + o2);
						break;
					case '-':
						stack.push(o1 - o2);
						break;
					case '*':
						stack.push(o1 * o2);
						break;
					case '/':
						stack.push(o1 / o2);
						break;
					case '^':
						stack.push( pow(o1, o2) );
						break;
				}
			}
		
		}
		
		return stack.top();
}




// infix to prefix
std::string infix_to_prefix(std::string infix)
{
		int size = infix.size();
		
		reverse(infix.begin(), infix.end());
		
		for (int i = 0; i < size; i++)
		{
			
			if (infix[i] == '(')
			{
				infix[i] = ')';
				i++;
			}
			else if (infix[i] == ')')
			{
				infix[i] = '(';
				i++;
			}
			
		}
		
		std::string prefix = infix_to_postfix(infix);
		reverse(prefix.begin(), prefix.end());
		return prefix;
}




// infix to postfix
std::string infix_to_postfix(std::string infix)
{
		infix = '(' + infix + ')';
		int size = infix.size();
		std::stack<char> stack;
		std::string postfix;
		
		// I. Push the characters into the stack in postfix order
		for (int i = 0; i < size; i++)
		{
			// i. If an operand, append it to output
			if ( isdigit(infix[i]) )
			{
				postfix += infix[i];
			}
			
			// ii. If ‘(‘, push it to stack
			else if (infix[i] == '(')
			{
				stack.push('(');
			}
			
			// iii. If ‘)’, pop from stack and append to output until ‘(‘ is encountered
			else if (infix[i] == ')')
			{
				while (stack.top() != '(')
				{
					postfix += " ";
					postfix += stack.top();
					stack.pop();
				}
				stack.pop();  // pop '(' from stack
			}
			
			// iv. Operator found
			else if ( ispunct(stack.top()) )
			{
				postfix += " "; // append whitespace to allow numbers with multiple digits
				
				if(infix[i] == '^')
				{
					while ( getPriority(infix[i]) <= getPriority(stack.top()) )
					{
						postfix += stack.top();
						stack.pop();
					}
				} else {
					while ( getPriority(infix[i]) < getPriority(stack.top()) )
					{
						postfix += stack.top();
						postfix += " ";
						stack.pop();
					}
				}
				
				stack.push(infix[i]);  // push current operator on stack
			}
			
			/*// v. ignore whitespace
			else if ( isspace(infix[i]) )
			{
				continue;
			}*/
			
			// v. invalid character found
			else
			{
			}
		}
		
		// II. Append remaining characters
		while(!stack.empty())
		{
			postfix += stack.top();
			stack.pop();
		}
		
		// III. Return the postfix expression
		return postfix;
}




// define priority of arithmetic operations
int getPriority(char c)
{
		switch (c)
		{
			case '+' : case '-' :
				return 1;
			case '*' : case '/' :
				return 2;
			case '^':
				return 3;
			default:
				return 0;
		}
}
