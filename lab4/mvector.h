#pragma once
#include <new>
#include <iterator>
#ifndef MVECTOR_H
#define MVECTOR_H

namespace University {

	template <class T>
	class VecIterator : public std::iterator<std::random_access_iterator_tag, T> {
	private:
		T* cur;
	public:
		VecIterator(T* c) : cur(c) {}

		bool operator =(VecIterator<T> it);

		bool operator ==(const VecIterator<T> it) const;

		bool operator !=(const VecIterator<T> it) const;

		VecIterator<T>& operator ++();

		VecIterator<T> operator ++(int);

		VecIterator<T>& operator --();//pfiks

		VecIterator<T> operator --(int);

		T& operator *();

		T* operator ->();

		VecIterator<T>& operator +=(int n);

		VecIterator<T> operator +(int n);

		VecIterator<T>& operator -=(int n);

		VecIterator<T> operator -(int n);

		int operator -(VecIterator<T> it);

		T& operator [](int n);

		bool operator <(VecIterator<T> it);

		bool operator >(VecIterator<T> it);

		bool operator <=(VecIterator<T> it);

		bool operator >=(VecIterator<T> it);
	};
	template <class T>
	VecIterator<T>& VecIterator<T>::operator++() {
		++cur;
		return *this;
	}

	template <class T>
	VecIterator<T> VecIterator<T>::operator++(int) {
		VecIterator<T> tmp = cur;
		++cur;
		return tmp;
	}

	template <class T>
	VecIterator<T>& VecIterator<T>::operator --() {
		--cur;
		return *this;
	}

	template <class T>
	VecIterator<T> VecIterator<T>::operator --(int) {
		VecIterator<T> tmp = cur;
		--cur;
		return tmp;
	}

	template <class T>
	T& VecIterator<T>::operator *() {
		return *cur;
	}

	template <class T>
	T* VecIterator<T>::operator ->() {
		return cur;
	}

	template <class T>
	bool VecIterator<T>::operator ==(const VecIterator<T> it) const {
		return cur == it.cur;
	}

	template <class T>
	bool VecIterator<T>::operator !=(const VecIterator<T> it) const {
		return cur != it.cur;
	}

	template <class T>
	VecIterator<T>& VecIterator<T>::operator +=(int n) {
		if (n > 0) {
			while (n > 0) {
				n--;
				++(*this);
			}
		}
		else {
			while (n < 0) {
				n++;
				--(*this);
			}
		}
		return(*this);
	}

	template <class T>
	VecIterator<T> VecIterator<T>::operator +(int n) {
		VecIterator<T> tmp = *this;
		return tmp += n;
	}

	template <class T>
	VecIterator<T>& VecIterator<T>::operator -=(int n) {
		return (*this += -n);
	}

	template <class T>
	VecIterator<T> VecIterator<T>::operator -(int n) {
		VecIterator<T> tmp = *this;
		return tmp -= n;
	}

	template <class T>
	int VecIterator<T>::operator -(VecIterator<T> it) {
		int counter = 0;
		if (cur <= it.cur) {
			while ((*this - counter) != it) counter--;
		}
		else {
			while ((*this - counter) != it) counter++;
		}
		return counter;
	}

	template <class T>
	T& VecIterator<T>::operator [](int n) {
		return (*(*this + n));
	}

	template <class T>
	bool VecIterator<T>::operator <(VecIterator<T> it) {
		if (it - *this > 0) return true;
		else return false;
	}

	template <class T>
	bool VecIterator<T>::operator >(VecIterator<T> it) {
		return it < *this;
	}

	template <class T>
	bool VecIterator<T>::operator <=(VecIterator<T> it) {
		return !(*this > it);
	}

	template <class T>
	bool VecIterator<T>::operator >=(VecIterator<T> it) {
		return !(*this < it);
	}

	template <class T>
	bool VecIterator<T>::operator =(VecIterator<T> it) {
		cur = it.cur;
		return true;
	}
	template <class T>
	class mvector {
	private:
		int vsize;
		T* vec;
	public:
		mvector(int s = 0);

		void push_back(T element);
		void push(T element);

		T& operator [](int pos) const;

		int size() const;

		void reset(int n = 0);

		bool empty()const;

		typedef VecIterator<T> iterator;

		iterator begin() {
			return iterator(this->vec);
		}
		iterator end() {
			return iterator(this->vec + this->vsize);
		}

		mvector<T>& erase(iterator i) {
			iterator check = begin();
			int count = 0;
			while (i != check) {
				++check;
				++count;
			}
			T* tmp = new T[vsize-1];
			int j = 0;
			for (int k = 0; k < vsize; k++) {
				if (k != count)
				{
					tmp[j] = vec[k];
					j++;
				}

			}
			delete[] vec;
			vec = tmp;
			vsize--;
			return *this;
		}
		mvector<T>& clear() {
			vsize = 0;
			delete[] vec;
			vec = nullptr;
			return *this;
		}
		~mvector();


	};

	//Realese

	template <class T>
	void mvector<T>::reset(int n) {
		if (n < 0) {
			throw std::invalid_argument("Number of items can't be negative");
		}
		if (vsize > 0) delete[] vec;
		try {
			vec = new T[n];
			vsize = n;
		}
		catch (std::bad_alloc& ba) {
			throw ba;
		}
	}

	template <class T>
	mvector<T>::mvector(int s) {
		vsize = s;
		if (s != 0) vec = new T[s];
		else vec = nullptr;
	}

	template <class T>
	void mvector<T>::push_back(T element) {
		T* tmp = new T[vsize + 1];
		for (int i = 0; i < vsize; i++) {
			tmp[i] = vec[i];
		}
		tmp[vsize] = element;
		delete[] vec;
		vec = tmp;
		vsize++;
	}
	template <class T>
	void mvector<T>::push(T element) {
		T* tmp = new T[vsize + 1];
		for (int i = 1; i < vsize; i++) {
			tmp[i] = vec[i-1];
		}
		tmp[0] = element;
		delete[] vec;
		vec = tmp;
		vsize++;
	}
	template <class T>
	bool mvector<T>::empty() const {
		if (vsize > 0)
			return false;
		return true;
	}
	template <class T>
	T& mvector<T>::operator [](int pos) const {
		if (pos < 0 || pos >= vsize)
			throw std::invalid_argument("Invalid index");
		return vec[pos];
	}

	template <class T>
	int mvector<T>::size() const {
		return vsize;
	}

	template <class T>
	mvector<T>::~mvector() {
	 delete[] vec;
	}


}

#endif MVECTOR_H