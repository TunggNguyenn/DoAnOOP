#ifndef __MYSTRING_H__
#define __MYSTRING_H__
#include "MyIterator.h"

#define DEFAULT_ADD_RESERVER_SIZE 15


class MyString
{
private:
	char *m_pch;
	size_t m_size;
	size_t m_reserved_size;

public:
	/*Member constants*/
	static const size_t npos = -1;

	/*Member functions*/
	//constructor
	MyString();  //default
	MyString(const MyString& str);  //copy
	MyString(const MyString& str, size_t pos, size_t len = npos);  //substring
	MyString(const char* s);  //from c-string
	MyString(const char* s, size_t n);  //from buffer
	MyString(size_t n, char c);  //fill
//	template<class InputIterator>
//	MyString(InputIterator first, InputIterator last);
	//MyString(initializer_list<char> il);  //initializer list            
	MyString(MyString&& str) noexcept;  //move

	//destructor
	~MyString(); 

	//operator=
	MyString& operator=(const MyString& str);  //string
	MyString& operator=(const char* s);  //c-string
	MyString& operator=(char c);  //character
	//MyString& operator= (initializer_list<char> il);  //initializer list (4)	
	MyString& operator=(MyString&& str) noexcept;  //move (5)	


	//Iterator
	MyStringIterator begin() noexcept;  //
	const_MyStringIterator begin() const noexcept;  //
	MyStringIterator end() noexcept;  //
	const_MyStringIterator end() const noexcept;  //
	Reverse_MyStringIterator rbegin() noexcept;
	const_Reverse_MyStringIterator rbegin() const noexcept;  //
	Reverse_MyStringIterator rend() noexcept;
	const_Reverse_MyStringIterator rend() const noexcept;
	const_MyStringIterator cbegin() const noexcept;  //
	const_MyStringIterator cend() const noexcept;  //
	const_Reverse_MyStringIterator crbegin() const noexcept;  //
	const_Reverse_MyStringIterator crend() const noexcept;  //


	//Capacity
	size_t size() const noexcept;  //
	size_t length() const noexcept;  //
	size_t max_size() const noexcept;  //
	void resize(size_t n);  //
	void resize(size_t n, char c);  //
	size_t capacity() const noexcept;  //
	void reserve(size_t n = 0);  //
	void clear() noexcept;  //
	bool empty() const;  //
	void shrink_to_fit();  //



	//Element access
	char& operator[](size_t pos);  //
	const char& operator[](size_t pos) const;  //
	char& at(size_t pos);  //
	const char& at(size_t pos) const;  //
	char& back();  //
	const char& back() const;  //
	char& front();  //
	const char& front() const;  //

	//Modifiers
	MyString& operator+=(const MyString& str);  //string(1)
	MyString& operator+=(const char* s);  //c-string(2)
	MyString& operator+=(char c);  //character(3)
	//string& operator+= (initializer_list<char> il);  //initializer list (4)
	MyString& append(const MyString& str);  //string(1)
	MyString& append(const MyString& str, size_t subpos, size_t sublen = npos);  //substring(2)
	MyString& append(const char* s);  //c-string(3)
	MyString& append(const char* s, size_t n);  //buffer(4)
	MyString& append(size_t n, char c);  //fill(5)
	//template<class InputIterator>
	//MyString& append(InputIterator first, InputIterator last);  //range(6)
	//MyString& append(initializer_list<char> il);  //initializer list(7)
	void push_back(char c);  //
	MyString& assign(const MyString& str);  //string(1)
	MyString& assign(const MyString& str, size_t subpos, size_t sublen = npos);  //substring(2)
	MyString& assign(const char* s);  //c-string(3)
	MyString& assign(const char* s, size_t n);  //buffer(4)
	MyString& assign(size_t n, char c);  //fill(5)
	//template<class InputIterator>
	//MyString& assign(InputIterator first, InputIterator last);  //range(6)
	MyString& assign(MyString&& str) noexcept;  //move (8)	
	MyString& insert(size_t pos, const MyString& str);  //string (1)	
	MyString& insert(size_t pos, const MyString& str, size_t subpos, size_t sublen = npos);  //substring(2)
	MyString& insert(size_t pos, const char* s);  //c-string (3)	
	MyString& insert(size_t pos, const char* s, size_t n);  //buffer (4)	
	MyString& insert(size_t pos, size_t n, char c);  //
	MyStringIterator insert(const_MyStringIterator p, size_t n, char c);  //fill (5)	
	MyStringIterator insert(const_MyStringIterator p, char c);  //single character (6)
	//template <class InputIterator>  //
	//void insert(iterator p, InputIterator first, InputIterator last);  //range (7)
	//MyString& insert(const_iterator p, initializer_list<char> il);  //initializer list (8)
	MyString& erase(size_t pos = 0, size_t len = npos);  //sequence(1)
	MyStringIterator erase(const_MyStringIterator p);  //character(2)
	MyStringIterator erase(const_MyStringIterator first, const_MyStringIterator last);  //range
	MyString& replace(size_t pos, size_t len, const MyString& str);  //
	MyString& replace(const_MyStringIterator i1, const_MyStringIterator i2, const MyString& str);  //string (1)
	MyString& replace(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen = npos);  //substring (2)
	MyString& replace(size_t pos, size_t len, const char* s);  //
	MyString& replace(const_MyStringIterator i1, const_MyStringIterator i2, const char* s);  //c-string (3)
	MyString& replace(size_t pos, size_t len, const char* s, size_t n);  //
	MyString& replace(const_MyStringIterator i1, const_MyStringIterator i2, const char* s, size_t n);  //buffer (4)
	MyString& replace(size_t pos, size_t len, size_t n, char c);  //
	MyString& replace(const_MyStringIterator i1, const_MyStringIterator i2, size_t n, char c);  //fill (5)	
	//template <class InputIterator>
	//MyString& replace(const_iterator i1, const_iterator i2, InputIterator first, InputIterator last);  //range (6)
	//MyString& replace(const_iterator i1, const_iterator i2, initializer_list<char> il);  //initializer list (7)
	void swap(MyString& str);
	void pop_back();

	//String operations
	const char* c_str() const noexcept;
	const char* data() const noexcept;
	//allocator_type get_allocator() const noexcept;
	size_t copy(char*s, size_t len, size_t pos = 0) const;
	size_t find(const MyString& str, size_t pos = 0) const noexcept;  //string(1)
	size_t find(const char* s, size_t pos = 0) const;  //c-string(2)
	size_t find(const char* s, size_t pos, size_t n) const;  //buffer(3)
	size_t find(char c, size_t pos = 0) const noexcept;  //character(4)
	size_t rfind(const MyString& str, size_t pos = npos) const noexcept;  //string (1)
	size_t rfind(const char* s, size_t pos = npos) const;  //c-string (2)	
	size_t rfind(const char* s, size_t pos, size_t n) const;  //buffer (3)
	size_t rfind(char c, size_t pos = npos) const noexcept;  //character (4)
	size_t find_first_of(const MyString& str, size_t pos = 0) const;  //string (1)	
	size_t find_first_of(const char* s, size_t pos = 0) const;  //c-string (2)
	size_t find_first_of(const char* s, size_t pos, size_t n) const;  //buffer (3)
	size_t find_first_of(char c, size_t pos = 0) const noexcept;  //character (4)
	size_t find_last_of(const MyString& str, size_t pos = npos) const noexcept;  //string (1)	
	size_t find_last_of(const char* s, size_t pos = npos) const;  //c-string (2)	
	size_t find_last_of(const char* s, size_t pos, size_t n) const;  //buffer (3)	
	size_t find_last_of(char c, size_t pos = npos) const noexcept;  //character (4)	
	size_t find_first_not_of(const MyString& str, size_t pos = 0) const noexcept;  //string (1)
	size_t find_first_not_of(const char* s, size_t pos = 0) const;  //c-string (2)	
	size_t find_first_not_of(const char* s, size_t pos, size_t n) const;  //buffer (3)
	size_t find_first_not_of(char c, size_t pos = 0) const noexcept;  //character (4)	
	size_t find_last_not_of(const MyString& str, size_t pos = npos) const noexcept;  //string (1)
	size_t find_last_not_of(const char* s, size_t pos = npos) const;  //c-string (2)	
	size_t find_last_not_of(const char* s, size_t pos, size_t n) const;  //buffer (3)	
	size_t find_last_not_of(char c, size_t pos = npos) const noexcept;  //character (4)	
	MyString substr(size_t pos = 0, size_t len = npos) const;
	int compare(const MyString& str) const noexcept;  //string (1)	
	int compare(size_t pos, size_t len, const MyString& str) const;  //
	int compare(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen = npos) const;  //substrings (2)
	int compare(const char* s) const;  //
	int compare(size_t pos, size_t len, const char* s) const;  //c-string (3)
	int compare(size_t pos, size_t len, const char* s, size_t n) const;  //buffer (4)	

};

/*Non-member function overloads*/
//operator+
MyString operator+ (const MyString& lhs, const MyString& rhs);  //
MyString operator+ (MyString&&      lhs, MyString&&      rhs);  //
MyString operator+ (MyString&&      lhs, const MyString& rhs);  //
MyString operator+ (const MyString& lhs, MyString&&      rhs);  //string (1)

MyString operator+ (const MyString& lhs, const char*   rhs);  //
MyString operator+ (MyString&&      lhs, const char*   rhs);  //
MyString operator+ (const char*   lhs, const MyString& rhs);  //
MyString operator+ (const char*   lhs, MyString&&      rhs);  //c-string (2)


MyString operator+ (const MyString& lhs, char          rhs);  //
MyString operator+ (MyString&&      lhs, char          rhs);  //
MyString operator+ (char          lhs, const MyString& rhs);  //
MyString operator+ (char          lhs, MyString&&      rhs);  //character (3)

//relational operators
bool operator== (const MyString& lhs, const MyString& rhs) noexcept;  //
bool operator== (const char*   lhs, const MyString& rhs);  //
bool operator== (const MyString& lhs, const char*   rhs);  //(1)

bool operator!= (const MyString& lhs, const MyString& rhs) noexcept;  //
bool operator!= (const char*   lhs, const MyString& rhs);  //
bool operator!= (const MyString& lhs, const char*   rhs);  //(2)

bool operator<  (const MyString& lhs, const MyString& rhs) noexcept;  //
bool operator<  (const char*   lhs, const MyString& rhs);  //
bool operator<  (const MyString& lhs, const char*   rhs);  //(3)

bool operator<= (const MyString& lhs, const MyString& rhs) noexcept;  //
bool operator<= (const char*   lhs, const MyString& rhs);  //
bool operator<= (const MyString& lhs, const char*   rhs);  //(4)

bool operator>  (const MyString& lhs, const MyString& rhs) noexcept;  //
bool operator>  (const char*   lhs, const string& rhs);  //
bool operator>  (const MyString& lhs, const char*   rhs);  //((5)

bool operator>= (const MyString& lhs, const MyString& rhs) noexcept;  //
bool operator>= (const char*   lhs, const MyString& rhs);  //
bool operator>= (const MyString& lhs, const char*   rhs);  //(6)


//swap
void swap(MyString& x, MyString& y);


//operator>>
istream& operator>>(istream& is, MyString& str);  //

//operator<<
ostream& operator<< (ostream& os, const MyString& str);

//getline
istream& getline(istream& is, MyString& str, char delim);  //
istream& getline(istream&& is, MyString& str, char delim);  //(1)
istream& getline(istream& is, MyString& str);  //
istream& getline(istream&& is, MyString& str);  //(2)



#endif // !__MYSTRING_H__
