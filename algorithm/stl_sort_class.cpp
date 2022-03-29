#include <iostream>
#include <algorithm>

using namespace std;

class Student {
	public:
		string name;
		int score;
		Student(string name, int score) {
			this->name = name;
			this->score = score;
		}
		// The sorting criteria is "Order with a small score".
		bool operator <(Student &student) {
			return this->score < student.score;
		} 
};

int main(void) {
	
	// Object array 
	Student students[] = {
		Student("rabbit", 90),
		Student("dog", 93),
		Student("cat", 97),
		Student("horse", 87),
		Student("sheep", 92)
	};
	
	// Sort
	sort(students, students + 5);
	
	// Output
	for (int i = 0; i < 5; i++) {
		cout << students[i].name << ' ';
	} 
}

