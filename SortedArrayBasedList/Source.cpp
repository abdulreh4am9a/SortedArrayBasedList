#include"list.h"
struct student {
	int id;
	string name;
	bool operator==(const student& s) const {
		return id == s.id;
	}
	bool operator<(const student& s) const {
		return id < s.id;
	}
	bool operator>(const student& s) const {
		return id > s.id;
	}
	friend ostream& operator<<(const ostream& os, const student& s);
};
ostream& operator<<(ostream& os, const student& s) {
	os << "Id : " << s.id << endl;
	os << "Name : " << s.name << endl;
	return os;
}
template<typename T>
void display(list<T>& u) {
	u.reset();
	while (!u.is_last()) {
		cout << u.get_next() << " ";
	}
	cout << endl;
}
int main() {
	list<char> u;
	u.insert('E');
	u.insert('B');
	u.insert('A');
	u.insert('D');
	display<char>(u);
	u.update('B', 'C');
	display<char>(u);
	u.erase('C');
	display<char>(u);
	list<student>s;
	student s1, s2, s3, s4;
	s1.id = 3;
	s1.name = "Ali";
	s2.id = 2;
	s2.name = "Bushra";
	s3.id = 1;
	s3.name = "Faisal";
	s4.id = 2;
	s.insert(s1);
	s.insert(s2);
	s.insert(s3);
	if (s.find(s4)) {
		cout << "Id : " << s4.id << endl;
		cout << "Name : " << s4.name << endl;
	}
	else {
		cout << s4.id << " not found" << endl;
	}
	display<student>(s);
	/*s.reset();
	while (!s.is_last()) {
		s4 = s.get_next();
		cout << "Id : " << s4.id << endl;
		cout << "Name : " << s4.name << endl;
	}*/
	return 0;
}