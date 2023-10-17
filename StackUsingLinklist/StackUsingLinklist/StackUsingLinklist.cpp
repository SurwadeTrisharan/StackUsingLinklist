#include<iostream>
using namespace std;
#define MAX 5
int stack[MAX];

struct node
{
	int info;
	node* link;
};
node* top = 0;

void push(int x)
{
	node* p;
	p = new node;
	p->info = x;
	p->link = NULL;
	if (top == NULL)
	{
		top = p;
	}
	else
	{
		p->link = top;
		top = p;
	}
}

int pop()
{
	int x;
	node* p;
	if (top == NULL)
	{
		cout << "Stack is empty "<<endl;
		return -1;
	}
	p = top;
	x = top->info;
	top = top->link;
	delete p;
	return x;
}

int peek()
{
	int x;
	node* p;
	if (top == NULL)
	{
		cout << "Stack is empty "<<endl;
		return -1;
	}
	x = top->info;
	return x;
}

void display()
{
	node* t;
	if (top == NULL)
	{
		cout << "Stack is empty";
	}
	else
	{
		t = top;
		while (t != NULL)
		{
			cout << " " << t->info;
			t = t->link;
		}
		return;
	}
	
}

int main()
{
	int choice, value;
	do
	{
		cout << "\nEnter 1.Push 2.Pop 3.Peek 4.Display  5.exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:cout << "Enter the value to push" << endl;
			cin >> value;
			push(value);
			break;
		case 2:value = pop();
			cout << "The value poped is" << value << endl;
			break;
		case 3:value = peek();
			cout << "The value peeked is" << value << endl;
			break;
		case 4:display();
			break;
		default:cout << "Exiting";
			choice = 5;
		}
	} while (choice != 5);
}