#include <iostream>
using namespace std;

class ListNode {
	public:
		int value;
		ListNode *next;
		ListNode(int x) : value(x), next(nullptr) {}
};

ListNode* rotateRight(ListNode* head, int k) {
	int length = 1; 
	ListNode *tail = head;
	while (tail->next) {   // get length
		length++;
		tail = tail->next;
	}

	int tempK = k % length;
	if (tempK == 0) {
		return head; 
	}

	ListNode *current = head;
	for (int i = 1; i < length - tempK; i++) {
		current = current->next;
	}

	tail->next = head;
	head = current->next;
	current->next = nullptr;

	return head;
}

void printList(ListNode* head) {
	while (head) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}

int main() {
	ListNode* List = new ListNode(1);
	List->next = new ListNode(2);
	List->next->next = new ListNode(3);
	List->next->next->next = new ListNode(4);
	List->next->next->next->next = new ListNode(5);

	int k1 = 2;
	ListNode* result1 = rotateRight(List, k1);
	printList(result1);

	ListNode* List2 = new ListNode(0);
	List2->next = new ListNode(1);
	List2->next->next = new ListNode(2);

	int k2 = 4;
	ListNode* result2 = rotateRight(List2, k2);
	printList(result2);

	return 0;
}

