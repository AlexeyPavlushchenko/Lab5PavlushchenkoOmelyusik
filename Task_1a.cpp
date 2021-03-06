#include <iostream>
#include <cstring>

using namespace std;

bool braces(char stack1[]) {
    char stack2[100] = {'\0'};
    bool truth = true;
    int size = 0;
    int key = strlen(stack1) - 1;
    while (truth == true && key >= 0) {
        if (stack1[key] == ')') {
            stack2[size] = '(';
            size++;
            key--;
        }
        if (stack1[key] == ']') {
            stack2[size] = '[';
            size++;
            key--;
        }
        if (stack1[key] == '}') {
            stack2[size] = '{';
            size++;
            key--;
        }
        if (stack1[key] == '{' && stack2[size - 1] == '{') {
            stack2[size - 1] = '\0';
            size--;
            key--;
        }
        if (stack1[key] == '(' && stack2[size - 1] == '(') {
            stack2[size - 1] = '\0';
            size--;
            key--;
        }
        if (stack1[key] == '[' && stack2[size - 1] == '[') {
            stack2[size - 1] = '\0';
            size--;
            key--;
        }
        if ((stack1[key] == '[' && stack2[size - 1] != '[') || (stack1[key] == '(' && stack2[size - 1] != '(') || (stack1[key] == '{' && stack2[size - 1] != '{'))
            truth = false;

    }

    if (size == 0 && truth == true)
        truth = true;
    else
        truth = false;
    return truth;
}

void test(char input[], bool answer)
{
	if (braces(input) == answer)
		cout << "OK" << endl;
	else cout << "Failed" << endl;
}

int main()
{
	test("{}((())){}[]", true);
	test("{[[]]}(())",true);
	test("({{[}}}){(})", false);
	test(")(()){}", false);
	test("{}{}{}{})", false);
	system("Pause");
}
