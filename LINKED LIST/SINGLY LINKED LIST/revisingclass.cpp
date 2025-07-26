#include <iostream>
using namespace std;
class Student {
public:
    string name;
    int rno;
    float marks;
    Student(string name, int rno, float marks) {
        this->name = name;
        this->rno = rno;
        this->marks = marks;
    }
};
void change(Student* s) {
    s->name = "Harsh";
}
int main() {
    Student* s = new Student("Shanidhya Kumar", 44, 92.6);
    cout << s->name << endl << s->rno << endl << s->marks << endl;
    change(s);
    cout << s->name << endl << s->rno << endl << s->marks << endl;
    return 0;
}
