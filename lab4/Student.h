#ifndef Student_H_
#define Student_H_



//string wayfile = "C:\\Users\\aDani\\Music\\Sources.txt"; //No access rights for "Desktop" ???


namespace University {
	class Student {
	protected:
		string surandini;
		int group;
		int department;
		int course;
	public:
		int stcode;

		/*конструкторы*/
		Student();
		Student(string new_surandini, int new_group,
			int new_department, int new_course); 
		Student(string surandini);
		//Student(string, int, int, int);

		/*Getters*/
		virtual string GetInfoMarks()const = 0;
		int GetCourse() const { return this->course; }

		/*Methods*/
		virtual string Info() = 0;
		void ReplaceSt(int new_course);
		//virtual Student* NewCatSt(string) = 0;
		void ChangeGroup(int new_group);
		virtual Student& LoadSt(ifstream&)=0;
	};
}
#endif