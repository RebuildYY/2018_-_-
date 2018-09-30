#include "student.h"
#include <sstream>

Student::Student() {
}
Student::Student(const char * new_id) {
	Student();
	update_id(new_id);
}
Student::Student(const Student & s) {
	Student();
	update_id(s.id);
	update_birthday(s.birthday);
	update_number(s.number);
	update_name(s.name);
}
Student & Student::operator = (const Student &s) {
	update_id(s.id);
	update_birthday(s.birthday);
	update_number(s.number);
	update_name(s.name);
	return *this;//자기자신을 반환
}
bool Student::operator == (const Student & s) {
	if (name != s.name) { return false; }
	if (strcmp(birthday, s.birthday) != 0) { return false; }
	if (strcmp(number, s.number) != 0) { return false; }
	if (strcmp(id, s.id) != 0) { return false; }
	return true;
}
bool Student::operator != (const Student & s) {
	if (name == s.name) { return false; }
	if (strcmp(birthday, s.birthday) == 0) { return false; }
	if (strcmp(number, s.number) == 0) { return false; }
	if (strcmp(id, s.id) == 0) { return false; }
	return true;
}
istream & operator >> (istream & is, Student & s) {
	
	char str[100];
	char* temp;
	is.getline(str, 100);
	temp = strtok(str, "|");
	s.update_id(temp);

	temp = strtok(NULL, "|");
	s.update_name(temp);

	temp = strtok(NULL, "|");
	s.update_number(temp);

	temp = strtok(NULL, "\n");
	s.update_birthday(temp);
	
	return is;
}
ostream & operator << (ostream & os, Student & s) {
	char temp[15];
	strncpy(temp, s.id, 8);
	temp[8] = '\0';
	os << "ID : " << temp << endl;
	os << "NAME : " << s.name << endl;
	strncpy(temp, s.number, 13);
	temp[13] = '\0';
	os << "NUMBER : " << temp << endl;
	strncpy(temp, s.birthday, 10);
	temp[10] = '\0';
	os << "BIRTHDAY : " << temp << endl;
	return os;
}
