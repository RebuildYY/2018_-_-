#include "student.h"
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream ifs("listOfStudent.txt");
	if (ifs.fail()) {
		cout << "File Open erro!" << endl;
		return -1;
	}

	int n;
	ifs >> n;
	ifs.ignore(numeric_limits<streamsize>::max(), '\n');

	vector <Student> s_list;
	
	for (int i = 0; i < n; i++) {
		Student s;
		ifs >> s;
		cout << s;
		s_list.push_back(s);
	}
	
	Student s1 = s_list[0];
	Student s2 = s_list[1];

	if (s1 == s1) cout << "'==' works well!" << endl;
	if (s1 != s2) cout << "'!=' works well!" << endl;

	Student s3;
	s3 = s1;

	cout << s3;
	cout << "'=' works well!" << endl;

	return 0;
}