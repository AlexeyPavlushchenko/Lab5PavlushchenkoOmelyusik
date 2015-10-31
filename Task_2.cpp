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

void cycleComputing (Formula * formula){
    while (isdigit(formula->head->key) == false || formula->head->next != NULL)
        calculation(formula);    
}


int main(){
    Formula * formula = new Formula;
    char fun[100];
    gets(fun);
    for (int i = 0; i < strlen(fun); i++) {
        push(fun[i], formula);
    }
    cycleComputing(formula);
    cout << formula->head->key << endl;
}