#include "LINK.h"

namespace University {

	GraduateSt::GraduateSt() : Student() {}

	GraduateSt::GraduateSt(string new_surandini, int new_group,
		int new_department, int new_course, string new_theme,
		string new_workplace, mvector <int>& new_leadermarks) : Student(new_surandini, new_group,
			new_department, new_course) {
		theme = new_theme;
		workplace = new_workplace;
		leadermarks = new_leadermarks;
	}

	string GraduateSt::GetInfoMarks()const{
		stringstream s;

		s << "Leadermarks: ";
		for (int i = 0; i < leadermarks.size(); i++) {
			s << leadermarks[i] << " ";
		}
		s << endl;
		return s.str();
	}

	string GraduateSt::Info() {
		stringstream s;

		s << 3 << " " << stcode << " " << surandini << " "
			<< group << " " << department << " " << course
			<< " " << theme << " " << workplace << " " << leadermarks.size() << " ";
		for (int i = 0; i < leadermarks.size(); i++) {
			s << leadermarks[i] << " ";
		}
		return s.str();
	}

	GraduateSt& GraduateSt::LoadSt(ifstream& src){
		src >> stcode >> surandini >> group >> department >> course >> theme >> workplace;
		int k;
		src >> k;
		for (int i = 0; i < k; i++) {
			src >> leadermarks[i];
		}
		return *this;
	}
}  