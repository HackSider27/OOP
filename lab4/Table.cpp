#include "LINK.h"

namespace University {
	void Table::LoadTab() {
		ifstream src;

		src.exceptions(ifstream::failbit);
		src.open("C:\\Users\\aDani\\Music\\Sources.txt");

		if (!src)
			return;

		int buf;
		int help;
		int i = 2;

		while (!src.eof()) {

			int k = 2;
			src >> buf;
			if (buf == 1) {
				Student* J= new JuniorSt();
				(*J).LoadSt(src);
				int help = J->stcode;
				table.insert(pair<int, Student*>(help, J));
			}

			else if (buf == 2) {
				Student* S = new SeniorSt();
				(*S).LoadSt(src);
				int help = S->stcode;
				table.insert(pair<int, Student*>(help, S));
			}

			else if (buf == 3) {
				Student* G = new GraduateSt();
				(*G).LoadSt(src);
				int help = G->stcode;
				table.insert(pair<int, Student*>(help, G));
					
			}
		}
	}

	void Table::SaveTab() {
		ofstream src;

		src.exceptions(ifstream::failbit);
		src.open("C:\\Users\\aDani\\Music\\Sources.txt");

		try {
			src.is_open();
		}
		catch (ofstream::failure& ex) {
			cout << ex.code() << endl;
			cout << "File error open" << endl;
		}

		stringstream s;
		map <int, Student*> ::iterator it = table.begin();
		for (int i = 0; it != table.end(); it++, i++) {
			s << it->first << " " << it->second->Info() << endl;
		}
		src << s.str();
		//src << code;
		src.close();
	}

	Table& Table::AddNewSt(JuniorSt* A) {
		table.insert(pair<int, JuniorSt*>(A->stcode, A));
		return *this;
	}

	Table& Table::AddNewSt(SeniorSt* A) {
		table.insert(pair<int, SeniorSt*>(A->stcode, A));
		return *this;
	}

	Table& Table::AddNewSt(GraduateSt* A) {
		table.insert(pair<int, GraduateSt*>(A->stcode, A));
		return *this;
	}

	Student* Table::FindStudent(int stcode) {
		//Student* cur;
		map<int, Student*> :: iterator A;
		A = table.find(stcode);

		return A->second;
	}

	Table& Table::ReplaceStudent(int size, int new_course) {
		Student* A = FindStudent(size);

		(*A).ReplaceSt(new_course);
		return *this;
	}

	string Table::GetCateg(int stcode) {
		Student* A = FindStudent(stcode);
		if (A->GetCourse())
			return "Junior";
		else if (A->GetCourse() == 2 || A->GetCourse() == 3)
			return "Senior";
		else if (A->GetCourse() == 4)
			return "Graduate";
		else throw exception("Error Student");
	}

	Table& Table::DelSt(int stcode) {
		table.erase(table.find(stcode));
		return *this;
	}
	
	string Table::CheckAllTable(){
		stringstream s;
		map <int, Student*> ::iterator it = table.begin();
		for (int i = 0; it != table.end(); it++, i++) {  // выводим их
			s << i << ") Student code " << it->first
			<< ", Current Student " << it->second->Info() << endl;
		}
		return s.str();
	}

}