#include "LINK.h"

namespace University {

	SeniorSt::SeniorSt() : Student() {}

	SeniorSt::SeniorSt(string new_surandini, int new_group,
		int new_department, int new_course, mvector <int>& new_marks,
		string new_theme, string new_workplace, mvector <int>& new_erwmarks) : Student(new_surandini, new_group,
			new_department, new_course) {
		marks = new_marks;
		theme = new_theme;
		workplace = new_workplace;
		erwmarks = new_erwmarks;
	}

	string SeniorSt::GetInfoMarks()const {
		stringstream s;

		s << "Marks of last session ";

		for (int i = 0; i < marks.size(); i++) {
			s << marks[i] << " ";
		}
		s << endl;

		for (int i = 0; i < erwmarks.size(); i++) {
			if (!i) {
				s << "Leader mark: " << erwmarks[i]<<" ";
			}
			if (i) {
				s << "Ñommission mark: " << erwmarks[i];
			}
		}
		s << endl;
		return s.str();
	}

	string SeniorSt::Info() {
		stringstream s;
		s << 2 << " " << stcode << " " << surandini << " " << group << " " << department << " " << course
			<< " " << workplace << " " << theme << " " << erwmarks[0] << " " << erwmarks[1]
			<< " " << marks.size() << " ";
		for (int i = 0; i < marks.size(); i++) {
			s << marks[i] << " ";
		}
		return s.str();
	}

	SeniorSt& SeniorSt::LoadSt(ifstream& src) {
		src >> stcode >> surandini >> group >> department >> course >> workplace >> theme;
		int l;
		src >> l;
		erwmarks.push_back(l);
		src >> l;
		erwmarks.push_back(l);
		int k;
		src >> k;
		for (int i = 0; i < k; i++) {
			src >> marks[i];
		}
		return *this;
	}
}