#ifndef Binary_H_
#define Binary_H_

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace Prog3b {
	class Binary {
	private:
		static const int SZ = 15;
		char arr[SZ];
		void NormolizeArr();
		void SetDefaultArr();
	public:
		Binary();
		Binary(const long& num);
		Binary(const char* _arr);
		//Binary(const Binary& other);
		//Binary(Binary&& other);

		bool IsCorrectArr(const char* _digits);
		//~Binary() { delete[]arr; }
		string GetBin() const { return string(arr); }
		string GetAdditionalCode() const;
		Binary& operator +(const Binary& arg);
		void SetBinaryWithAdditionalCode(const char* _arr);

		//Binary& operator=(const Binary& other);
		//Binary& operator=(Binary&& other);

		Binary& operator --();
		Binary& operator ++(); //? ??????????? ?? ?????? ???? int ++a
		int Sign()const;

		//friend std::ostream& operator <<(std::ostream& s, const Binary& bi);
		friend std::ostream& operator <<(std::ostream& s, const Binary&);
		friend std::istream& operator >>(std::istream& s, Binary&);
	};
	std::string quest();
}
#endif