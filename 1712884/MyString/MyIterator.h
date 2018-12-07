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


class StringIterator : public Iterator
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
	virtual void nNext(size_t n);
	virtual void Previous();
	virtual void nPrevious(size_t n);
	virtual bool IsDone();
	virtual char& CurrentItem();
	virtual size_t get_Current();
};

//------------------------------------------------------------------------------------------------------------------

/*const_MyStringIterator*/
class const_MyStringIterator : public StringIterator
{
public:
	const_MyStringIterator() : StringIterator() {};

	const_MyStringIterator(char* myString, long current = 0) : StringIterator(myString, current) {};

	const_MyStringIterator(const const_MyStringIterator& m_Iterator) : StringIterator(m_Iterator) {};

	const_MyStringIterator& operator=(const_MyStringIterator& Item)
	{
		StringIterator::StringIterator(Item);

		*this = Item;
		return *this;
	}

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

	const_MyStringIterator operator+(size_t n)
	{
		const_MyStringIterator tmp(*this);

		tmp.nNext(n);

		return tmp;
	}

	const_MyStringIterator operator-(size_t n)
	{
		const_MyStringIterator tmp(*this);

		tmp.nPrevious(n);

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

};


/*MyStringIterator*/
class MyStringIterator : public const_MyStringIterator
{
public:
	MyStringIterator() : const_MyStringIterator() {};

	MyStringIterator(char* myString, long current = 0) : const_MyStringIterator(myString, current) {};

	MyStringIterator(const MyStringIterator& m_Iterator) : const_MyStringIterator(m_Iterator) {}

	MyStringIterator& operator=(MyStringIterator& Item)
	{
		const_MyStringIterator::const_MyStringIterator(Item);

		*this = Item;
		return *this;
	}


	char& operator*()
	{
		if (IsDone())
		{
			throw;
		}
		return CurrentItem();
	}

};


//-------------------------------------------------------------------Reverse-------------------------------------------------------------------


/*const_Reverse_MyStringIterator*/
class const_Reverse_MyStringIterator : public StringIterator
{
public:
	const_Reverse_MyStringIterator() : StringIterator() {};

	const_Reverse_MyStringIterator(char* myString, long current) : StringIterator(myString, current) {};

	const_Reverse_MyStringIterator(const const_Reverse_MyStringIterator& m_Iterator) : StringIterator(m_Iterator) {};

	const_Reverse_MyStringIterator& operator=(const_Reverse_MyStringIterator& Item)
	{
		StringIterator::StringIterator(Item);

		*this = Item;
		return *this;
	}

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
		const_Reverse_MyStringIterator::Next();

		return *this;
	}


	const_Reverse_MyStringIterator operator--(int)
	{
		const_Reverse_MyStringIterator tmp(*this);

		operator--();

		return tmp;
	}


	const_Reverse_MyStringIterator operator+(size_t n)
	{
		const_Reverse_MyStringIterator tmp(*this);

		tmp.nPrevious(n);

		return tmp;
	}


	const_Reverse_MyStringIterator operator-(size_t n)
	{
		const_Reverse_MyStringIterator tmp(*this);

		tmp.nNext(n);

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
};


/*Reverse_MyStringIterator*/
class Reverse_MyStringIterator : public const_Reverse_MyStringIterator
{
public:
	Reverse_MyStringIterator() : const_Reverse_MyStringIterator() {};

	Reverse_MyStringIterator(char* myString, long current) : const_Reverse_MyStringIterator(myString, current) {};

	Reverse_MyStringIterator(const Reverse_MyStringIterator& m_Iterator) : const_Reverse_MyStringIterator(m_Iterator) {}

	Reverse_MyStringIterator& operator=(Reverse_MyStringIterator& Item)
	{
		const_Reverse_MyStringIterator::const_Reverse_MyStringIterator(Item);

		*this = Item;
		return *this;
	}


	char& operator*()
	{
		if (IsDone())
		{
			throw;
		}
		return CurrentItem();
	}

};


#endif // !__MYITERATOR_H__