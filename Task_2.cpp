#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Formula {
    char key;
    Formula * next, * head;
};

void push(char key, Formula *& formula) {
    Formula * temp = new Formula;
    temp->key = key;
    temp->next = formula->head;
    formula->head = temp;
}

void calculation(Formula * formula) {
    int result;
    int figure1, figure2;
    while (isdigit(formula->head->key) == false)
        formula->head = formula->head->next;
    figure1 = (int) formula->head->key - 48;
    formula->head = formula->head->next;
    formula->head = formula->head->next;
    formula->head = formula->head->next;
    while (isdigit(formula->head->key) == false)
        calculation (formula);
    figure2 = (int) formula->head->key - 48;
    formula->head = formula->head->next;
    formula->head = formula->head->next;
    if (formula->head->key == 'n')
        result = min(figure2, figure1);
    else
        result = max(figure2, figure1);
    formula->head = formula->head->next;
    formula->head = formula->head->next;
    formula->head = formula->head->next;
    char fig = (char) result + 48;
    push(fig, formula);
}

// Нужная функция, в стеке остается лишь искомое число
// Тестить эту фунцкию

char cycleComputing (char * str){
    Formula * formula = new Formula;
    for (int i = 0; i < strlen(str); i++)
        push(str[i], formula);
    while (isdigit(formula->head->key) == false || formula->head->next != NULL)
        calculation(formula);
    return formula->head->key;
}

void test(char * input, int answer)
{
	if (cycleComputing(input) == answer)
		cout << "OK" << endl;
	else cout << "Failed" << endl;
}

int main(){
	test("max(min(6, 7), max(9, 2))", 9);
	test("max(min(6, max(min(8, 12),5), max(9, 2))", 9);
	test("max(max(6, 7), max(9, 2))", 9);
	test("max(max(max(max(max(87,65),56),54,),43), 32)", 87);
	test("max(3,4)", 4);
	test("10", 10);
	system("Pause");
	return 0;
}
