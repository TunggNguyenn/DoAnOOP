#ifndef __MYITERATOR_H__
#define __MYITERATOR_H__
#include <iostream>
using namespace std;


class MyIterator
{
private:
	char *m_it_pch;
public:
	MyIterator();
	MyIterator(char *s);
	MyIterator(const MyIterator& m_it_s);
	MyIterator& operator++();
	MyIterator operator++(int);
	bool operator==(const MyIterator& m_it_s) const;
	bool operator!=(const MyIterator& m_it_s) const;
	MyIterator& operator=(char c);
	char& operator*();
};




class const_MyIterator
{
private:
	char *m_it_pch;
public:
	const_MyIterator();
	const_MyIterator(char *s);
	const_MyIterator(const const_MyIterator& m_it_s);
	const_MyIterator& operator++();
	const_MyIterator operator++(int);
	bool operator==(const const_MyIterator& m_it_s) const;
	bool operator!=(const const_MyIterator& m_it_s) const;
	char operator*();
};



#endif // !__MYITERATOR_H__
