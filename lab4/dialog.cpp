#include"dialog.h"

void AddNewStudent(Table& a) {
	bool flag = true;
	string new_surandini;
	int new_group;
	int new_department;
	int new_course;
	mvector<int> marks_v;
	do {
		std::cout << "Enter new_surandini: ";
		std::cin >> new_surandini;
		std::cout << "Enter new_group: ";
		std::cin >> new_group;
		std::cout << "Enter new_course: ";
		std::cin >> new_course;
		std::cout << "Enter new_department: ";
		std::cin >> new_department;
		if (!std::cin.good())
		{
			std::cin.ignore(INT_MAX);
			std::cin.clear();
			flag = false;
		}
	} while (new_group <= 0 || new_department <= 0 || new_course < 0 || new_course >= 5 || !flag);
	if (new_course == 1) {
		int size;
		do {
			std::cout << "Enter amount of marks: ";
			std::cin >> size;
			if (!std::cin.good())
			{
				std::cin.ignore(INT_MAX);
				std::cin.clear();
				flag = false;
			}
		} while (size < 0 || size >5 || !flag);
		for (int i = 0; i < size; i++) {
			int marks;
			do {
				std::cout << "Enter a mark: ";
				std::cin >> marks;
				if (!std::cin.good())
				{
					std::cin.ignore(INT_MAX);
					std::cin.clear();
					flag = false;
				}
			} while (marks < 2 || marks>5 || !flag);
			marks_v.push_back(marks);
		}
		a.AddNewSt(new JuniorSt(new_surandini, new_group, new_department, new_course, marks_v));
	}
	else if (new_course == 2 || new_course == 3) {
		int size;
		string new_workplace;
		string new_theme;
		do {
			std::cout << "Enter amount of marks: ";
			std::cin >> size;
			if (!std::cin.good())
			{
				std::cin.ignore(INT_MAX);
				std::cin.clear();
				flag = false;
			}
		} while (size < 0 || size >4 || !flag);
		for (int i = 0; i < size; i++) {
			int marks;
			do {
				std::cout << "Enter marks: ";
				std::cin >> marks;
				if (!std::cin.good())
				{
					std::cin.ignore(INT_MAX);
					std::cin.clear();
					flag = false;
				}
			} while (marks < 2 || marks>5 || !flag);
			marks_v.push_back(marks);
		}
		do {
			std::cout << "Enter workplace: ";
			std::cin >> new_workplace;
			std::cout << "Enter new_theme: ";
			std::cin >> new_theme;
			if (!std::cin.good())
			{
				std::cin.ignore(INT_MAX);
				std::cin.clear();
				flag = false;
			}
		} while (!flag);
		do {
			std::cout << "Enter amount of erwmarks: ";
			std::cin >> size;
			if (!std::cin.good())
			{
				std::cin.ignore(INT_MAX);
				std::cin.clear();
				flag = false;
			}
		} while (size < 0 || size >2 || !flag);
		mvector<int> erwmarks;
		for (int i = 0; i < size; i++) {
			int marks;
			do {
				std::cout << "Enter marks: ";
				std::cin >> marks;
				if (!std::cin.good())
				{
					std::cin.ignore(INT_MAX);
					std::cin.clear();
					flag = false;
				}
			} while (marks < 2 || marks>5 || !flag);
			erwmarks.push_back(marks);
		}
		a.AddNewSt(new SeniorSt(new_surandini, new_group, new_department, new_course, marks_v, new_theme, new_workplace, erwmarks));
	}
	else
	{
		int size;
		string new_workplace;
		string new_theme;
		do {
			std::cout << "Enter amount of marks: ";
			std::cin >> size;
			if (!std::cin.good())
			{
				std::cin.ignore(INT_MAX);
				std::cin.clear();
				flag = false;
			}
		} while (size < 0 || size >3 || !flag);
		for (int i = 0; i < size; i++) {
			int marks;
			do {
				std::cout << "Enter marks: ";
				std::cin >> marks;
				if (!std::cin.good())
				{
					std::cin.ignore(INT_MAX);
					std::cin.clear();
					flag = false;
				}
			} while (marks < 2 || marks>5 || !flag);
			marks_v.push_back(marks);
		}
		do {
			std::cout << "Enter workplace: ";
			std::cin >> new_workplace;
			std::cout << "Enter new_theme: ";
			std::cin >> new_theme;
			if (!std::cin.good())
			{
				std::cin.ignore(INT_MAX);
				std::cin.clear();
				flag = false;
			}
		} while (!flag);
		a.AddNewSt(new GraduateSt(new_surandini, new_group, new_department, new_course, new_theme, new_workplace, marks_v));
	}
}

void DeleteStudent(Table& a)
{
	bool flag = true;
	int size;
	do {
		std::cout << "Enter student code: ";
		std::cin >> size;
		if (!std::cin.good())
		{
			std::cin.ignore(INT_MAX);
			std::cin.clear();
			flag = false;
		}
	} while (size < 0 || !flag);
	a.DelSt(size);
}

void TransportStudent(Table& a)
{
	bool flag = true;
	int size;
	int new_course;
	do {
		std::cout << "Enter student code: ";
		std::cin >> size;
		std::cout << "Enter new_course: ";
		std::cin >> new_course;
		if (!std::cin.good())
		{
			std::cin.ignore(INT_MAX);
			std::cin.clear();
			flag = false;
		}
	} while (size < 0 || !flag);
	a.ReplaceStudent(size, new_course); 
}

void CheckAll(Table& a) {
	cout<< a.CheckAllTable();
}