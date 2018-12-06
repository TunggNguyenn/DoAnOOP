#ifndef __MYITERATOR_H__
#define __MYITERATOR_H__
#include <iostream>
using namespace std;

class Iterator
{
protected:
	//Iterator();
public:
	virtual void First() = 0;
	virtual void Last() = 0;
	virtual void Next() = 0;
	virtual void Previous() = 0;
	virtual bool IsDone() = 0;
	virtual char& CurrentItem() = 0;
};

class Aggregrate
{
public:
	//	virtual Iterator<T>* createIterator() = 0;
	//	virtual T getCurrent(int n) = 0;
	virtual void setCurrent(char Item) = 0;
	//	virtual size_t getSize() = 0;
};


class StringAggregrate : public Aggregrate
{
private:
	//char* _myString;
	//long _current;
	Iterator* m_Iterator;
public:
	StringAggregrate() : Aggregrate() {};
	StringAggregrate(Iterator* myIterator) : Aggregrate(), m_Iterator(myIterator) {};
	void setCurrent(char Item)
	{
		//this->_myString[_current] = Item;
		//m_Iterator->CurrentItem() = Item;
		m_Iterator->CurrentItem() = Item;
	}
};


//
class StringIterator : public Iterator, public StringAggregrate
{
private:
	char* _myString;
	long _current;
public:
	StringIterator();
	StringIterator(char* myString, long current = 0);
	StringIterator& operator=(StringIterator& stringIterator);
	virtual void First();
	virtual void Last();
	virtual void Next();
	virtual void Previous();
	virtual bool IsDone();
	virtual char& CurrentItem();
	virtual size_t get_Current();
};



class MyStringIterator : public StringIterator
{
public:
	MyStringIterator() : StringIterator() {};

	MyStringIterator(char* myString, long current = 0) : StringIterator(myString, current) {};

	MyStringIterator(const MyStringIterator& m_Iterator) : StringIterator(m_Iterator) {}

	MyStringIterator& operator++()
	{
		StringIterator::Next();
		return *this;
	}


	MyStringIterator operator++(int)
	{
		MyStringIterator tmp(*this);
		operator++();
		return tmp;
	}

	MyStringIterator& operator--()
	{
		StringIterator::Previous();
		return *this;
	}


	MyStringIterator operator--(int)
	{
		MyStringIterator tmp(*this);
		operator--();
		return tmp;
	}



	bool operator==(MyStringIterator rhs)
	{
		return CurrentItem() == rhs.CurrentItem();
	}

	bool operator!=(MyStringIterator rhs)
	{
		return CurrentItem() != rhs.CurrentItem();
	}

	char& operator*()
	{
		if (IsDone())
		{
			throw;
		}
		return CurrentItem();
	}
	MyStringIterator& operator=(MyStringIterator& Item)
	{
		StringIterator::StringIterator(Item);

		*this = Item;
		return *this;
	}
};

//
class const_MyStringIterator : public StringIterator
{
public:
	const_MyStringIterator() : StringIterator() {};

	const_MyStringIterator(char* myString, long current = 0) : StringIterator(myString, current) {};

	const_MyStringIterator(const const_MyStringIterator& m_Iterator) : StringIterator(m_Iterator) {}

	const_MyStringIterator& operator++()
	{
		const_MyStringIterator::Next();
		return *this;
	}

	const_MyStringIterator operator++(int)
	{
		const_MyStringIterator tmp(*this);
		operator++();
		return tmp;
	}


	const_MyStringIterator& operator--()
	{
		const_MyStringIterator::Previous();
		return *this;
	}


	const_MyStringIterator operator--(int)
	{
		const_MyStringIterator tmp(*this);
		operator--();
		return tmp;
	}

	bool operator==(const_MyStringIterator rhs)
	{
		return CurrentItem() == rhs.CurrentItem();
	}

	bool operator!=(const_MyStringIterator rhs)
	{
		return CurrentItem() != rhs.CurrentItem();
	}

	char operator*()
	{
		if (IsDone())
		{
			throw;
		}
		return CurrentItem();
	}
	const_MyStringIterator& operator=(const_MyStringIterator& Item)
	{
		StringIterator::StringIterator(Item);

		*this = Item;
		return *this;
	}
};


class Reverse_MyStringIterator : public StringIterator
{
public:
	Reverse_MyStringIterator() : StringIterator() {};

	Reverse_MyStringIterator(char* myString, long current) : StringIterator(myString, current) {};

	Reverse_MyStringIterator(const Reverse_MyStringIterator& m_Iterator) : StringIterator(m_Iterator) {}

	Reverse_MyStringIterator& operator++()
	{
		StringIterator::Previous();
		return *this;
	}

	Reverse_MyStringIterator operator++(int)
	{
		Reverse_MyStringIterator tmp(*this);
		operator++();
		return tmp;
	}

	Reverse_MyStringIterator& operator--()
	{
		Reverse_MyStringIterator::Previous();
		return *this;
	}


	Reverse_MyStringIterator operator--(int)
	{
		Reverse_MyStringIterator tmp(*this);
		operator--();
		return tmp;
	}

	bool operator==(Reverse_MyStringIterator rhs)
	{
		return CurrentItem() == rhs.CurrentItem();
	}

	bool operator!=(Reverse_MyStringIterator rhs)
	{
		return CurrentItem() != rhs.CurrentItem();
	}

	char& operator*()
	{
		if (IsDone())
		{
			throw;
		}
		return CurrentItem();
	}
	Reverse_MyStringIterator& operator=(Reverse_MyStringIterator& Item)
	{
		StringIterator::StringIterator(Item);

		*this = Item;
		return *this;
	}
};

class const_Reverse_MyStringIterator : public StringIterator
{
public:
	const_Reverse_MyStringIterator() : StringIterator() {};

	const_Reverse_MyStringIterator(char* myString, long current) : StringIterator(myString, current) {};

	const_Reverse_MyStringIterator(const const_Reverse_MyStringIterator& m_Iterator) : StringIterator(m_Iterator) {}

	const_Reverse_MyStringIterator& operator++()
	{
		StringIterator::Previous();
		return *this;
	}

	const_Reverse_MyStringIterator operator++(int)
	{
		const_Reverse_MyStringIterator tmp(*this);
		operator++();
		return tmp;
	}

	const_Reverse_MyStringIterator& operator--()
	{
		const_Reverse_MyStringIterator::Previous();
		return *this;
	}


	const_Reverse_MyStringIterator operator--(int)
	{
		const_Reverse_MyStringIterator tmp(*this);
		operator--();
		return tmp;
	}

	bool operator==(const_Reverse_MyStringIterator rhs)
	{
		return CurrentItem() == rhs.CurrentItem();
	}

	bool operator!=(const_Reverse_MyStringIterator rhs)
	{
		return CurrentItem() != rhs.CurrentItem();
	}

	char operator*()
	{
		if (IsDone())
		{
			throw;
		}
		return CurrentItem();
	}
	const_Reverse_MyStringIterator& operator=(const_Reverse_MyStringIterator& Item)
	{
		StringIterator::StringIterator(Item);

		*this = Item;
		return *this;
	}
};





#endif // !__MYITERATOR_H__