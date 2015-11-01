#include <iostream>

using namespace std;

struct Node
{
	char value;
	Node* next;
};

bool answer;
Node* head = new Node;

void pop(Node* &head)
{
	if (head->next == NULL)
			head->value = 0;
		else
			head = head->next;
}

void push(Node* &head, char a)
{
	if (head->value == 0)
		head->value = a;
	else
	{
		Node* temp = new Node;
		temp->value = a;
		temp->next = head;
		head = temp;
	}
}

bool check(char* input)
{
	answer = true;
	head->value = 0;
	head->next = NULL;
	for (int i = 0; i < strlen(input) && answer; i++)
	{
		if (strchr("([{}])", input[i]) != NULL)
		{
			if ((input[i] - head->value) <= 2 && (input[i] - head->value)>0)
				pop(head);
			else if (strchr("}])", input[i]) != NULL)
				answer = false;
			else
				push(head, input[i]);
		}
	}
	if (head->value != 0) answer = false;
	return answer;
}

int main()
{

}