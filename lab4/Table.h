#ifndef Table_H_
#define Table_H_
namespace University {
	class Table {
	private:
		map<int, Student*> table;
	public:
		void LoadTab();
		void SaveTab();
		Table& AddNewSt(JuniorSt*);
		Table& AddNewSt(SeniorSt*);
		Table& AddNewSt(GraduateSt*);
		Student* FindStudent(int stcode);
		Table& ReplaceStudent(int size, int new_course);
		string GetCateg(int stcode);
		Table& DelSt(int stcode);
		string CheckAllTable();
	};
}
#endif