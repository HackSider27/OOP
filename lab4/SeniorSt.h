#ifndef SeniorSt_H_
#define SeniorSt_H_



namespace University {
	class SeniorSt : public Student {
	private:
		mvector<int> marks;
		string theme;
		string workplace;
		mvector <int> erwmarks;
	public:
		SeniorSt();
		SeniorSt(string, int, int, int, mvector <int>&, string, string, mvector <int>&);
		/*Setters*/
		SeniorSt& SetTheme(string new_theme) { theme = new_theme; return *this; }
		SeniorSt& SetWP(string new_workplace) { workplace = new_workplace; return *this; }

		/*Getters*/
		string GetWP() const { return this->workplace; }
		string GetTheme() const { return this->theme; }

		string GetInfoMarks()const override;
		string Info() override;
		SeniorSt& LoadSt(ifstream&) override;
		//Student* NewCatSt(string) override;
	};
}
#endif