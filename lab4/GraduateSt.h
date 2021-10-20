#ifndef GraduateSt_H_
#define GraduateSt_H_


namespace University {
	class GraduateSt : public Student {
	private:
		string theme;
		string workplace;
		mvector<int> leadermarks;
	public:
		GraduateSt();
		GraduateSt(string, int, int, int, string, string, mvector <int>&);
		/*Setters*/
		GraduateSt& SetWP(string new_workplace) { workplace = new_workplace; return *this; }
		GraduateSt& SetTheme(string new_theme) { theme = new_theme; return *this; }

		/*Getters*/
		string GetWP() const { return this->workplace; }
		string GetTheme() const { return this->theme; }

		string GetInfoMarks()const override;
		string Info() override;
		GraduateSt& LoadSt(ifstream&) override;
		//Student* NewCatSt(string) override;
	};
}
#endif
