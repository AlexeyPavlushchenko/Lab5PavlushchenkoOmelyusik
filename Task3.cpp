#include <string>
#include <stack>
#include <iostream> 
#include <cstring>
#include <cstdlib>

using namespace std;


string strDig = ".0123456789", strFunc = "+-/*";

double process(char temp[])
{
	stack <double> numbers;
	stack <char> functions;
	for (int i = 0; i < strlen(temp); i++)
	{
		if (i == 0 && temp[0] == '-')
		{
			numbers.push(-1);
			functions.push('*');
			i++;
		}
		if (!functions.empty() && functions.top() == '(' && temp[i] == '-')
		{
			numbers.push(-1);
			functions.push('*');
			i++;
		}
		if (strDig.find(temp[i]) != -1) {
			char sub[300] = "";
			int j = i;
			while (strDig.find(temp[i]) != -1)
			{
				sub[i - j] = temp[i];
				i++;
			}

			float n = atof(sub);
			numbers.push(n);
		}
		if (temp[i] == '(')
		{
			functions.push('(');
		}
		if (temp[i] == ')') {
			while (functions.top() != '(')
			{
				float a, b;
				a = numbers.top();
				numbers.pop();
				b = numbers.top();
				numbers.pop();
				if (functions.top() == '*') {
					numbers.push(a*b);
				}
				if (functions.top() == '/') {
					numbers.push(b / a);
				}
				if (functions.top() == '+') {
					numbers.push(a + b);
				}
				if (functions.top() == '-') {
					numbers.push(b - a);
				}
				functions.pop();
			}
			functions.pop();
			continue;
		}
		if (strFunc.find(temp[i]) != -1) {
			while (!functions.empty())
			{
				if ((functions.top() == '+' || functions.top() == '-') && (temp[i] == '*' || temp[i] == '/') || functions.top() == '(') {
					break;
				}
				float a, b;
				a = numbers.top();
				numbers.pop();
				b = numbers.top();
				numbers.pop();
				if (functions.top() == '*') {
					numbers.push(a*b);
				}
				if (functions.top() == '/') {
					numbers.push(b / a);
				}
				if (functions.top() == '+') {
					numbers.push(a + b);
				}
				if (functions.top() == '-') {
					numbers.push(b - a);
				}
				functions.pop();

			}
			functions.push(temp[i]);
		}
	}
	while (!functions.empty())
	{
		float a, b;
		a = numbers.top();
		numbers.pop();
		b = numbers.top();
		numbers.pop();
		if (functions.top() == '+') {
			numbers.push(a + b);
		}
		if (functions.top() == '-') {
			numbers.push(b - a);
		}
		if (functions.top() == '*') {
			numbers.push(a*b);
		}
		if (functions.top() == '/') {
			numbers.push(b / a);
		}
		functions.pop();
	}
	float res = numbers.top();
	numbers.pop();
	return res;


}

void test(char* input, int res)
{
	if (process(input) == res)
		cout << "OK" << endl;
	else
		cout << "Failed" << endl;
}

int main()
{
	test("(50/100+30/15)*40", 100);
        test("(5*14)-(543*32400+1000)/100-1351+325176", 147953);
        test("9435+1235792/8-100431+32/16", 63480);
        test("1123+(124+156)/(156-146)+124", 1275);
        test("921679+934436/(3566-3562)-328922/2*2", 826366);
        test("3269/(3487-3488)+389497-327561/(3+1-5/5)+12", 277053);
}
