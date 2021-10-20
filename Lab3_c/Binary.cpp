#include "Binary.h"
#include <stdlib.h>
#include <algorithm>
#include <charconv>
#include <cstring>

void invert(char& c)
{
	c = c == '0' ? '1' : '0';
}

namespace Prog3c {
	std::ostream& operator <<(std::ostream& s, const Binary& b) {
		if (b.arr[0] == '\0')
			s << "Binary number not found..." << std::endl;
		else
			s << b.GetBin();
		return s;
	}

	std::istream& operator>>(std::istream& s, Binary& b) {
		s.read(b.arr, b.SZ);
		return s;
	}

	void Binary::NormolizeArr()
	{

		int j = 1;
		while (arr[j] == '0')
		{
			j++;
		}
		if (arr[j] == '\0')
		{
			j--;
			arr[0] = '0';
		}
		int i = 1;
		j--;
		for (; arr[i + j] != '\0'; i++)
		{
			arr[i] = arr[i + j];
		}
		arr[i] = '\0';
	}

	void Binary::SetDefaultArr() {
		//SZ = 7;
		arr = new char[6] {};
		for (int i = 0; i < SZ - 1; i++) {
			arr[i] = '0';
		}
	}

	Binary::Binary() {
		SetDefaultArr();
	}

	Binary::Binary(const long& num)
	{
		//SetDefaultArr();
		SZ = 1;
		char* tmp;
		//int SZ = def;
		while (abs(num) > pow(2, SZ)) {
			SZ ++;
		}
		if (abs(num) == pow(2, SZ-1))
			SZ+=2;
		//printf_s("%d\n", SZ);
		//SZ+=1;
		//int p = SZ;
		tmp = new char[SZ]{};
		arr = new char [SZ] {};

		auto [ptr, _] = std::to_chars(tmp, tmp + SZ, std::abs(num), 2);

		SetDefaultArr();

		const auto size = ptr - tmp;
		std::copy_n(tmp, size, arr + SZ - size);

		if (num < 0)
			arr[0] = '1';
	}

	Binary::Binary(const char* _arr)
	{
		if (IsCorrectArr(_arr))
		{
			bool sgn = true;
			if (_arr[0] == '-' || _arr[0] == '+')
			{
				if (_arr[0] == '-')
					sgn = false;

				_arr++;
			}

			const auto len = std::strlen(_arr);
			if (len != SZ) {
				SZ = 1;
				while (len > SZ) {
					SZ++;
				}
				SZ++;
			}

			if (((_arr[0] == '1') && sgn) || ((_arr[1] == '1') && (!sgn)))
				SZ++;
			arr = new char [SZ] {};

			SetDefaultArr();
			
			std::copy_n(_arr, len, arr + SZ - len);
			arr[0] = sgn ? '0' : '1';
			arr[SZ] = '\0';
		}
		else
		{
			SetDefaultArr();
		}
	}

	Binary::Binary(const Binary& other)
	{
		SetDefaultArr();
		auto len = std::strlen(other.arr);
		std::copy(arr, arr + len, other.arr);
	}

	Binary::Binary(Binary&& other) :
		arr(other.arr)
	{
		SZ = other.SZ;
		other.arr = nullptr;
	}

	bool Binary::IsCorrectArr(const char* _arr) {
		int i = 0;
		if (_arr[0] == '-' || _arr[0] == '+')
		{
			i = 1;
		}
		while (_arr[i] != '\0')
		{
			if (!(_arr[i] == '0' || _arr[i] == '1'))
			{
				return false;
			}
			i++;
		}
		return true;
	}

	std::string quest() {
		std::stringstream s;
		s << "How do u want to enter the number? " << std::endl;
		s << "[1] Regular number." << std::endl;
		s << "[2] Binary number." << std::endl;
		return	s.str();
	}

	Binary Binary::operator +(const Binary& arg)
	{
		int max = SZ < arg.SZ ? arg.SZ : SZ;
		
		//if (!(arr[1]) || !(arg.arr[1]))
			//max--;
		
		auto a = GetAdditionalCode(max);
		auto b = arg.GetAdditionalCode(max);

		//if (a.size() < b.size())
			//std::swap(a, b);

		std::string res(max, '\0');
		bool carry = false;
		for (int i = max - 1; i >= 0; i--)
		{
			res[i] = (a[i] - '0' + b[i] - '0' + (carry ? 1 : 0)) % 2 + '0';

			if ((a[i] == '1' && b[i] == '1') || (carry && (a[i] == '1' || b[i] == '1'))) {
				carry = true;
				res[i] = '0';
			}
			else
				carry = false;

			if (!i && (a[0] - '0' + b[0] - '0' + (carry ? 1 : 0)) % 2 != (res[0] - '0'))
				throw std::overflow_error("Overflow in addition");
		}
		res[max] = '\0';
		if (res[0] == '0')
			return res.c_str();

		Binary converted;
		converted.SetBinaryWithAdditionalCode(res.c_str());

		return converted;
	}

	void Binary::SetBinaryWithAdditionalCode(const char* _arr)
	{
		std::string str(_arr);

		bool carry = true;
		for (int i = str.length() - 1; carry; --i)
		{
			if (!carry)
				break;

			if (str[i] == '0')
				str[i] = '1';
			else
			{
				str[i] = '0';

				carry = false;
			}

			if (i == 1 && carry)
				throw std::overflow_error("Conversation from additional code overflow");
		}

		std::for_each(std::begin(str) + 1, std::end(str), &invert);

		std::copy(std::begin(str), std::end(str), arr);
	}

	Binary& Binary::operator=(const Binary& other) {
		if (this != &other)
			std::copy(arr, arr + SZ, other.arr);
		return *this;
	}

	Binary& Binary::operator=(Binary&& other) {
		arr = other.arr;
		SZ = other.SZ;
		other.arr = nullptr;
		return *this;
	}

	Binary& Binary::operator ++() {
		//Binary b = *this;
		//Binary c = Binary(1);
		*this = *this + Binary(1);
		return *this;
	}

	Binary& Binary::operator --() {
		*this = *this + Binary(-1);
		return *this;
	}

	string Binary::GetAdditionalCode(int max) const {
		std::string str(arr);
		std::string new_str(max, '\0');

		//std::string newstr();
		char* newstr;
		newstr = new char [max];
		//nstr = new char[max];
		
		int size = max - this->SZ;//то что надо заполнить нулями
		if (Sign()) {
			newstr[0] = '0';
			for (int i = 1; i < size; i++)
					newstr[i] = '0';
			for (int i = size, k = 0; i < max; i++, k++) {
				newstr[i] = str[k];
			} //while max: k=str.length()
			//newstr[max] = '\0';
			//newstr[max] = '\0';
			new_str = (const char*)newstr;
			new_str[max] = '\0';
			//new_str[max+1]='\0';

			return new_str;
		}

		std::for_each(std::begin(str) + 1, std::end(str), &invert);


		bool carry = true;
		for (int i = SZ; carry; --i)
		{
			if (!carry)
				break;

			if (str[i] == '0')
			{
				str[i] = '1';
				carry = false;
			}
			else
				str[i] = '0';

			if (i == 1 && carry)
				throw std::overflow_error("Conversation to additional code overflow");
		}

		newstr[0] = '1';
		for (int i = 1; i < size; i++)
			newstr[i] = '1';
		for (int i = size, k = 0; i < max; i++, k++) {
			newstr[i] = str[k];
		}

		new_str = (const char*)newstr;
		new_str[max] = '\0';
		
		return new_str;
	}
}