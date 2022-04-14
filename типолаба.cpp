#include <iostream>
#include<ctime>
using namespace std;

struct stack {
	int info;
	stack* next;
} *t;

stack* create(int in) {
	stack* t = new stack;
	t->info = in;
	t->next = NULL;
	return t;
}
void add(stack*& p, int in) {
	stack* t = new stack;
	t->info = in;
	t->next = p;
	p = t;
}
void show(stack* p) {
	t = p;
	bool exist = 0;

	while (t != NULL) {
		cout << " " << t->info << endl;
		t = t->next;
		exist++;
	}
	if (!exist) {
		cout << "There is no stack." << '\n';
	}
}
void del(stack*& p) {
	while (p != NULL) {
		t = p;
		p = p->next;
		delete t;
	}
}

int search_min(stack*& p) {
	int min = p ->info;																						
	t = p;
	while (t != NULL) {
		if (t->info >= min) {
			t = t->next;
		}
		else {
			min = t->info;
			t = t->next;
		}
	}
	
	return min;
}

stack* task(stack*& p, int min) {
	stack* n = new stack;				 					
	bool move = 0;
	while (p != NULL) {
		if (p->info != min)
		{
			
			t = p->next;
			if (move == 0)
			{
				p->next = NULL;
			} 
			else p->next = n;
			n = p;
			p = t;
			move++;
		}
		if (move == 0) {
			cout << "There are no elements to move!" << endl;
			n->info = 0;
			n->next = NULL;
			return n;
		}
		if (p->info == min)
			 return n;
	}
}
void sort_adress(stack*& p) {
	add(p, 100000);
	stack *current, *temp2;																			
	if (p->next->next == NULL) return;
	do {
		for (current = p; current->next->next != t; current = current->next)
			if (current->next->info > current->next->next->info) {
				temp2 = current->next->next;
				current->next->next = temp2->next;
				temp2->next = current->next;
				current->next = temp2;
			}
		t = current->next;
	} while (p->next->next != t);
	t = p->next;
	delete p;
	p = t;
}
void sort_inf(stack*& p) {
	stack* current;				
	int temp;
	do {
		for (current = p; current->next != t; current = current->next)
			if (current->info > current->next->info) {
				temp = current->info;
				current->info = current->next->info;
				current->next->info = temp;
			}
		t = current;
	} while (p->next != t);

}
int menu() {
	cout << "MENU" << endl;
	cout << "Choose actions from the list below.. " << endl;
		cout << "0. Exit" << '\n' << "1. Create" << '\n' << "2. Add" << '\n' 
			<< "3. Show" << '\n' << "4. Task" << '\n' << "5. Delete" << '\n'
			<<"6. Adress sort"<<'\n' << "7. Info sort" << '\n';
		int n;
		cin >> n;
		return n;
}
int main()
{
	
	stack* begin_p = new stack;

	bool work = 0, created = 0;

	while (!work) {
		switch (menu()) {
		case 1:
			if (created) {
				del(begin_p);
				cout << "Previous stack was deleted.\n";
			}
			srand(time(NULL));
			created++;
			begin_p = create(rand() % 50 - 10);
			for (int i = 0; i < 2; i++) {
				int n = rand() % 50 - 10;
				add(begin_p, n);
			}
			cout << "Stack created: " << '\n';
			show(begin_p);
			break;
			
		case 2:
			if (!created) {
				cout << "There is no stack!"<<'\n';
				break;
			}
			cout << "Write the element you want to add..." << '\n';
			int i;
			cin >> i;
			add(begin_p, i);
			cout << "Stack updated: " << '\n';
			show(begin_p);
			break;
		case 3: 
			if (!created) {
				cout << "There is no stack!" << '\n';
				break;
			}
			cout << "Stack: " << '\n';
			show(begin_p);
			break;
		case 4:
			if (!created) {
				cout << "There is no stack!" << '\n';
				break;
			}
			 cout << "Task completed: " << '\n';
			show(task(begin_p, search_min(begin_p)));
			break;
		case 5: 
			if (!created) {
				cout << "There is no stack!" << '\n';
				break;
			}
			del(begin_p);
			cout << "Stack was deleted." << '\n';
			break;
		case 6: 
			if (!created) {
				cout << "There is no stack!" << '\n';
				break;
			}
			cout << "Sorted stack: " << '\n';
			sort_adress(begin_p);
			show(begin_p);
			break;
		case 7: 
			if (!created) {
				cout << "There is no stack!" << '\n';
				break;
			}
			cout << "Sorted stack: " << '\n';
			sort_inf(begin_p);
			show(begin_p);
			break;
		case 0:
			work++;
			delete begin_p;
			cout << "Stack was deleted.\nWork with stack is over." << '\n';
		}
	}
}
