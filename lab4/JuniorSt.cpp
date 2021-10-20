#include "LINK.h"

namespace University {

	JuniorSt::JuniorSt() : Student() {}

	JuniorSt::JuniorSt(string new_surandini, int new_group,
		int new_department, int new_course, mvector <int>& new_marks) : Student(new_surandini, new_group,
			new_department, new_course) {
		marks = new_marks;
	}

	string JuniorSt::GetInfoMarks()const {
		stringstream s;

		s << "Marks of last session ";

		for (int i = 0; i < marks.size(); i++) {
			s  << marks[i] << " ";
		}
		s << endl;
		return s.str();
	}

	string JuniorSt::Info() {
		stringstream s;
		s << 1 << " " << stcode << " " << surandini << " " << group << " " << department
			<< " " << course << " "<< marks.size() << " ";
		for (int i = 0; i < marks.size(); i++) {
			s << marks[i] << " ";
		}
		return s.str();
	}

	JuniorSt& JuniorSt::LoadSt(ifstream& src) {
		src >> stcode >> surandini >> group >> department >> course;
		int k;
		src >> k;
		for (int i = 0; i < k; i++) {
			src >> marks[i];
		}
		return *this;
	}
}