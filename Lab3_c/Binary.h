#ifndef Binary_H_
#define Binary_H_

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

namespace Prog3c {
	class Binary {
	private:
		int SZ;
		char* arr;
		void NormolizeArr();
		void SetDefaultArr();
	public:
		Binary();
		Binary(const long& num);
		Binary(const char* _arr);
		Binary(const Binary& other);
		Binary(Binary&& other);

		bool IsCorrectArr(const char* _digits);
		~Binary() { delete[]arr; }
		string GetBin() const { return string(arr); }
		string GetAdditionalCode(int max) const;
		void SetBinaryWithAdditionalCode(const char* _arr);

		Binary operator +(const Binary& arg);
		Binary& operator=(const Binary& other);
		Binary& operator=(Binary&& other);
		int GetSZ() { return this->SZ; }

		Binary& operator ++(); //у префиксного не должно быть int (++a)
		Binary& operator --();
		int Sign()const{ return arr[0] == '0'; }

		//friend std::ostream& operator <<(std::ostream& s, const Binary& bi);
		friend std::ostream& operator <<(std::ostream& s, const Binary&);
		friend std::istream& operator >>(std::istream& s, Binary&);
	};
	std::string quest();
}
#endif