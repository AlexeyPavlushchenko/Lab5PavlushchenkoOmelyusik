#include <iostream>
#include <cstring>
#include <cstdio>

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


int main(){
    cout << cycleComputing("max(min(6, 7), max(9, 2))") << endl;
    return 0;
}
