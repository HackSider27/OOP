#ifndef JuniorSt_H_
#define JuniorSt_H_



namespace University {
	class JuniorSt : public Student {
	private:
		mvector <int> marks;
	public:
		JuniorSt();
		JuniorSt(string, int, int, int, mvector <int>&);

		string GetInfoMarks()const override;
		string Info() override;
		JuniorSt& LoadSt(ifstream&) override;
		//SeniorSt NewCatSt(string) override;
	};
}
#endif
