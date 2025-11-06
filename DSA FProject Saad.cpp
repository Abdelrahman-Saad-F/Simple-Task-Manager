
#include <iostream>
using namespace std;

class Task_Manager {
	struct Node {
		string name;
		Node* next = nullptr;
		bool done = 0;
		int Pri = 0;
	};
	Node* Head;
	Node* Tail;
	int len;
public:
	Task_Manager() {
		Head = Tail = nullptr;
		len = 0;
	}
	~Task_Manager() {
		while (Head != nullptr) {
			Node* temp = Head;
			Head = Head->next;
			delete temp;
		}
	}
	bool isempty() {
		return len == 0;
	}
	bool isnotexist(int x) {
		return x > len || x <= 0;
	}

	void AddTask(string x, int y) {
		Node* New = new Node;
		New->name = x;
		New->next = nullptr;
		New->done = 0;
		New->Pri = y;
		if (isempty()) {
			Tail = Head = New;
		}
		else {
			Tail->next = New;
			Tail = New;
		}
		len++;
	}
	void ViewTasks() {
		if (isempty()) {
			cout << "There is no Tasks!" << endl;
		}
		else {
			Node* temp = Head;
			int x = 1;
			cout << endl;
			while (temp != nullptr) {
				if (temp->done) {
					cout << x << "- '" << temp->name << "' Priority-> " << temp->Pri << " ->COMPLETED[T]." << endl;
					temp = temp->next;
				}
				else {
					cout << x << "- '" << temp->name << "' Priority-> " << temp->Pri << " -> NOT COMPLETED[F]." << endl;
					temp = temp->next;
				}
				x++;
			}
		}
	}
	void Complete(int x) {
		if (isnotexist(x)) {
			cout << "Invalid Task number (Not Exist)!" << endl;
		}
		else {
			Node* temp = Head;
			for (int i = 0; i < x - 1; i++) {
				temp = temp->next;
			}
			if (temp->done) {
				cout << "The '" << temp->name << "' Task is Already COMPLETED[T]." << endl;
			}
			else {
				temp->done = 1;
				cout << "The '" << temp->name << "' Task is NOW COMPLETED[T]." << endl;
			}
		}
	}
	void CompAll() {
		Node* temp = Head;
		for (int i = 0; i < len; i++) {
			temp->done = 1;
			temp = temp->next;
		}
		cout << "All Tasks are COMPLETED[T]." << endl;
	}
	void Delete(int x) {
		if (isnotexist(x)) {
			cout << "Invalid Task number (Not Exist)!" << endl;
		}
		else {
			Node* temp = Head;
			if (x == 1) {
				temp = Head;
				Head = Head->next;
				delete temp;
				len--;
			}
			else {
				for (int i = 0; i < x - 2; i++) {
					temp = temp->next;
				}
				Node* del = temp->next;
				temp->next = temp->next->next;
				delete del;
				len--;
				cout << "Task number " << x << " is Deleted." << endl;
			}
		}
		
	}
	void Sort() {
		for (int i = 0; i < len - 1; i++) {
			Node* temp = Head;
			for (int j = 0; j < len - 1 - i; j++) {
				if (temp->Pri < temp->next->Pri) {
					string x = temp->name;
					temp->name = temp->next->name;
					temp->next->name = x;
					int y = temp->Pri;
					temp->Pri = temp->next->Pri;
					temp->next->Pri = y;
					bool z = temp->done;
					temp->done = temp->next->done;
					temp->next->done = z;
				}
				temp = temp->next;
			}

		}
	}
};



int main() {
	Task_Manager T;
	
	cout << "===== Hello,Mansoura Robotics <3 =====" << endl;
	cout << "====Sa3D====<Task Manager>====Sa3D====" << endl << endl;
	int ord, P, x;
	string n;
	cout << "Please choose the Order : " << endl;
	cout << "1- Add Task." << endl;
	cout << "2- Complete Specific Task." << endl;
	cout << "3- Complete All Tasks." << endl;
	cout << "4- View All Tasks." << endl;
	cout << "5- Sort & View Tasks." << endl;
	cout << "6- Delete Specific Task" << endl;
	cout << "7- Exit Program!" << endl;

	while (1) {
		cout << "\nEnter number of Order -> ";
		cin >> ord;
		switch (ord) {
		case 1:
			cout << "Please enter the Task -> ";
			cin >> n;
			cout << "Please enter the Task Priority(1 to 5)-> ";
			cin >> P;
			T.AddTask(n, P);
			break;

		case 2:
			cout << "Please enter the Task number you want to Complete-> ";
			cin >> x;
			T.Complete(x);
			break;

		case 3:
			T.CompAll();
			break;
		case 4:
			T.ViewTasks();
			break;
		case 5:
			T.Sort();
			T.ViewTasks();
			break;
		case 6:
			cout << "Please enter the Task number you want to delete-> ";
			cin >> x;
			T.Delete(x);
			break;
		case 7:
			cout << "\nThank you for using my Task Manager <3" << endl;
			return 0;
		default:
			cout << "Invalid Order!" << endl;
		}
	}
}

