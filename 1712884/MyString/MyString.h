#ifndef __MYSTRING_H__
#define __MYSTRING_H__
#include <iostream>
using namespace std;

#define DEFAULT_ADD_RESERVER_SIZE 15

class MyString
{
private:
//	char m_ch;
	//char_traits<char> ch_t;
	//allocator<char> ch_a;
	//char& rch;
	//const char& c_rch;
	char *m_pch;
//	const char* c_pch;
//	random_access_iterator_tag y;
//	reverse_iterator<iterator> i;
//	reverse_iterator<iterator> q;
//
	//ptrdiff_t ptrdiff;
	size_t m_size;
	size_t m_reserved_size;

	static const size_t npos = -1;
public:
	//constructor
	MyString();  //default
	MyString(const MyString& str);  //copy
	MyString(const MyString& str, size_t pos, size_t len = npos);  //substring
	MyString(const char* s);  //from c-string
	MyString(const char* s, size_t n);  //from buffer
	MyString(size_t n, char c);  //fill
//	template<class InputIterator>
//	MyString(InputIterator first, InputIterator last);
	//MyString(initializer_list<char> il);  //initializer list             Chưa làm
	//MyString(MyString&& str) noexcept;  //move

	//destructor
	~MyString(); 

	//operator=
	MyString& operator=(const MyString& str);  //string
	MyString& operator=(const char* s);  //c-string
	MyString& operator=(char c);  //character


	//Capacity
	size_t size() const noexcept;
	size_t length() const noexcept;
	size_t max_size() const noexcept;
	void resize(size_t n);
	void resize(size_t n, char c);
	size_t capacity() const noexcept;
	void reserve(size_t n = 0);
	void clear() noexcept;
	bool empty() const;
	void shrink_to_fit();

	//Element access
	char& operator[](size_t pos);
	const char& operator[](size_t pos) const;
	char& at(size_t pos);
	const char& at(size_t pos) const;
	char& back();
	const char& back() const;
	char& front();
	const char& front() const;

	//Modifiers
	MyString& operator+=(const MyString& str);  //string(1)
	MyString& operator+=(const char* s);  //c-string(2)
	MyString& operator+=(char c);  //character(3)
	MyString& append(const MyString& str);  //string(1)
	MyString& append(const MyString& str, size_t subpos, size_t sublen = npos);  //substring(2)
	MyString& append(const char* s);  //c-string
	MyString& append(const char* s, size_t n);  //buffer(4)
	MyString& append(size_t n, char c);  //fill(5)
	//template<class InputIterator>
	//MyString& append(InputIterator first, InputIterator last);  //range(6)
	void push_back(char c);
	MyString& assign(const MyString& str);  //string(1)
	MyString& assign(const MyString& str, size_t subpos, size_t sublen = npos);  //substring(2)
	MyString& assign(const char* s);  //c-string(3)
	MyString& assign(const char* s, size_t n);  //buffer(4)
	MyString& assign(size_t n, char c);  //fill(5)
	//template<class InputIterator>
	//MyString& assign(InputIterator first, InputIterator last);  //range(6)

	friend ostream& operator<<(ostream& os, const MyString& str);
	friend istream& operator>>(istream& is, MyString& str);
};


//operator+
MyString operator+(const MyString& lhs, const MyString& rhs);  //
MyString operator+(MyString&& lhs, MyString&& rhs);  //
MyString operator+(MyString&& lhs, const MyString& rhs);  //          string
MyString operator+(const MyString& lhs, MyString&& rhs);  //

MyString operator+(const MyString& lhs, const char* rhs);  //
MyString operator+(MyString&& lhs, const char* rhs);  //
MyString operator+(const char* lhs, const MyString& rhs);  //           c-string
MyString operator+(const char* lhs, MyString&& rhs);  //

MyString operator+(const MyString& lhs, char rhs);  //
MyString operator+(MyString&& lhs, char rhs);  //
MyString operator+(char lhs, const MyString& rhs);  //            character
MyString operator+(char lhs, MyString&& rhs);  //
#endif // !__MYSTRING_H__
