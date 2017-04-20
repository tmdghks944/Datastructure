#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

struct node {
	int elem;
	node* next = NULL;
};

class Linkedlist {
public:
	void insertnode(int x);
	void deletenode();
	int headnode();
	void printnode();
private:
	node* head=NULL;
	int size = 0;
};

void Linkedlist::insertnode(int x) {
	node* newnode = new node;
	newnode->elem = x;
	if (size == 0) {
		head = newnode;
	}
	else {
		newnode->next = head;
		head = newnode;
	}
	size++;
}

void Linkedlist::deletenode() {
	if (size == 0) {
		cout << "������ϴ�" << endl;
	}
	else if (size == 1) {
		delete(head);
		head = NULL;
	}
	else {
		node* targetnode = head;
		head = targetnode->next;
		delete(targetnode);
	}
	size--;
}

int Linkedlist::headnode() {
	if(head!=NULL)	{
		return head->elem;
	}
	else {
		return 0;
	}
}

void Linkedlist::printnode() {
	node* curPos = head;
	while (curPos != NULL) {
		printf("%d ", curPos->elem);
		curPos = curPos->next;
	}
}

int main() {
	Linkedlist list;
	int order;
	while (1) {
		cout << "1 : ����, 2 : ����, 3 : ����� 4: ������ 5 : ������" << endl;
		cin >> order;
		if (order == 1) {
			int num;
			cout << "���� ������ �Է��ϼ��� : ";
			cin >> num;
			list.insertnode(num);
		}
		else if (order == 2) {
			list.deletenode();
		}
		else if (order == 3) {
			cout << "������� ����  " << list.headnode() << " �Դϴ�." << endl;
		}
		else if (order == 4) {
			list.printnode();
			cout << endl;
		}
		else if (order == 5) {
			break;
		}
	}
	return 0;
}