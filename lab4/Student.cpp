#include "LINK.h"

namespace University {

		int code = 0;

		int CreateStcode() {
			int student_code = code;
			code++;
			return student_code;
		}
		Student::Student() {
			surandini = "StudentTest";
			course = 1;
			department = 42;
			group = 000;
			stcode = CreateStcode();
		}

		Student::Student(string new_surandini, int new_group,
			int new_department, int new_course) {
			surandini = new_surandini;
			group = new_group;
			course = new_course;
			department = new_department;
			stcode = CreateStcode();
		}

		Student::Student(string surandini) {
			this->surandini = surandini;
			group = 001;
			stcode = CreateStcode();
		}

		void Student::ReplaceSt(int new_course) {
			this->course = new_course;
		}

		void Student::ChangeGroup(int new_group) {
			//Student A = FindPerson(stcode);
			group = new_group;
		}
 }