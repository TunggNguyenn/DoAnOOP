#include "MyString.h"

int lengthString(const char* s)
{
	int count = 0;
	while (s[count] != NULL)
	{
		count++;
	}
	return count;
}

/*Constructor*/
MyString::MyString()
{
	this->m_pch = new char[DEFAULT_ADD_RESERVER_SIZE + 1];
	this->m_size = 0;
	this->m_reserved_size = DEFAULT_ADD_RESERVER_SIZE + 1;
}

MyString::MyString(const MyString & str)
{
	if (str.m_size <= DEFAULT_ADD_RESERVER_SIZE)
	{
		this->m_size = str.m_size;
		this->m_reserved_size = DEFAULT_ADD_RESERVER_SIZE + 1;
	}
	else
	{
		this->m_size = str.m_size;
		this->m_reserved_size = ((int)(this->m_size / (DEFAULT_ADD_RESERVER_SIZE + 1)))*(DEFAULT_ADD_RESERVER_SIZE + 1) + DEFAULT_ADD_RESERVER_SIZE + 1;
	}
	m_pch = new char[this->m_reserved_size];
	for (int i = 0; i < this->m_size; i++)
	{
		this->m_pch[i] = str.m_pch[i];
	}
	this->m_pch[this->m_size] = '\0';
}

MyString::MyString(const MyString & str, size_t pos, size_t len)
{
	if (len != -1)
	{
		if (len <= DEFAULT_ADD_RESERVER_SIZE)
		{
			this->m_reserved_size = DEFAULT_ADD_RESERVER_SIZE + 1;
		}
		else
		{
			this->m_reserved_size = ((int)(len / (DEFAULT_ADD_RESERVER_SIZE + 1)))*(DEFAULT_ADD_RESERVER_SIZE + 1) + DEFAULT_ADD_RESERVER_SIZE + 1;
		}
		this->m_size = len;
		this->m_pch = new char[this->m_reserved_size];
		for (int i = 0; i < this->m_size; i++)
		{
			this->m_pch[i] = str.m_pch[pos + i];
		}
		this->m_pch[this->m_size] = '\0';
	}
	else
	{
		if (len <= DEFAULT_ADD_RESERVER_SIZE)
		{
			this->m_reserved_size = DEFAULT_ADD_RESERVER_SIZE + 1;
		}
		else
		{
			this->m_reserved_size = ((int)(len / (DEFAULT_ADD_RESERVER_SIZE + 1)))*(DEFAULT_ADD_RESERVER_SIZE + 1) + DEFAULT_ADD_RESERVER_SIZE + 1;
		}
		this->m_size = str.m_size - pos + 1;
		this->m_pch = new char[this->m_reserved_size];
		for (int i = 0; i < this->m_size; i++)
		{
			this->m_pch[i] = str.m_pch[pos + i];
		}
		this->m_pch[this->m_size] = '\0';
	}
}

MyString::MyString(const char * s)
{
	this->m_size = lengthString(s);
	if (this->m_size <= DEFAULT_ADD_RESERVER_SIZE)
	{
		this->m_reserved_size = DEFAULT_ADD_RESERVER_SIZE + 1;
	}
	else
	{
		this->m_reserved_size = ((int)(this->m_size / (DEFAULT_ADD_RESERVER_SIZE + 1)))*(DEFAULT_ADD_RESERVER_SIZE + 1) + DEFAULT_ADD_RESERVER_SIZE + 1;
	}
	this->m_pch = new char[this->m_reserved_size];
	for (int i = 0; i < this->m_size; i++)
	{
		this->m_pch[i] = s[i];
	}
	this->m_pch[this->m_size] = '\0';
}

MyString::MyString(const char * s, size_t n)
{
	this->m_size = n;
	if (this->m_size <= DEFAULT_ADD_RESERVER_SIZE)
	{
		this->m_reserved_size = DEFAULT_ADD_RESERVER_SIZE + 1;
	}
	else
	{
		this->m_reserved_size = ((int)(this->m_size / (DEFAULT_ADD_RESERVER_SIZE + 1)))*(DEFAULT_ADD_RESERVER_SIZE + 1) + DEFAULT_ADD_RESERVER_SIZE + 1;
	}
	this->m_pch = new char[this->m_reserved_size];
	for (int i = 0; i < this->m_size; i++)
	{
		this->m_pch[i] = s[i];
	}
	this->m_pch[this->m_size] = '\0';
}

MyString::MyString(size_t n, char c)
{
	this->m_size = n;
	if (this->m_size <= DEFAULT_ADD_RESERVER_SIZE)
	{
		this->m_reserved_size = DEFAULT_ADD_RESERVER_SIZE + 1;
	}
	else
	{
		this->m_reserved_size = ((int)(this->m_size / (DEFAULT_ADD_RESERVER_SIZE + 1)))*(DEFAULT_ADD_RESERVER_SIZE + 1) + DEFAULT_ADD_RESERVER_SIZE + 1;
	}
	this->m_pch = new char[this->m_reserved_size];
	for (int i = 0; i < this->m_size; i++)
	{
		this->m_pch[i] = c;
	}
	this->m_pch[this->m_size] = '\0';
}

/*Destructor*/
MyString::~MyString()
{
	if (this->m_pch != NULL)
	{
		delete[] m_pch;
	}
}

/*Assignment*/
MyString & MyString::operator=(const MyString & str)
{
	this->m_size = str.m_size;
	this->m_pch = new char[this->m_size + 1];
	for (int i = 0; i < this->m_size; i++)
	{
		this->m_pch[i] = str.m_pch[i];
	}
	this->m_pch[this->m_size] = '\0';

	return *this;
}

MyString & MyString::operator=(const char * s)
{
	this->m_size = lengthString(s);
	this->m_pch = new char[this->m_size + 1];
	for (int i = 0; i < this->m_size; i++)
	{
		this->m_pch[i] = s[i];
	}
	this->m_pch[this->m_size] = '\0';
	return *this;
}

MyString & MyString::operator=(char c)
{
	this->m_size = 1;
	this->m_pch = new char[2];
	this->m_pch[0] = c;
	this->m_pch[1] = '\0';
	return *this;
}

/*Capacity*/
size_t MyString::size() const noexcept
{
	return this->m_size;
}

size_t MyString::length() const noexcept
{
	return this->m_size;
}

size_t MyString::max_size() const noexcept
{
	return pow(2, 31) - 1;
}

void MyString::resize(size_t n)
{
	if (n > this->m_size)
	{
		if (n < this->m_reserved_size)
		{
			for (int i = this->m_size; i < n; i++)
			{
				this->m_pch[i] = 0;
			}
			this->m_pch[n] = '\0';
		}
		else
		{

			this->m_reserved_size = ((int)(n / (DEFAULT_ADD_RESERVER_SIZE + 1)))*(DEFAULT_ADD_RESERVER_SIZE + 1) + DEFAULT_ADD_RESERVER_SIZE + 1;
			char *p_chnew = new char[m_reserved_size];
			for (int i = 0; i < this->m_size; i++)
			{
				p_chnew[i] = this->m_pch[i];
			}
			for (int i = this->m_size; i < n; i++)
			{
				p_chnew[i] = 0;
			}
			p_chnew[n] = '\n';
			delete[] this->m_pch;
			this->m_pch = p_chnew;
		}
		this->m_size = n;
	}
	else if (n < this->m_size)
	{
		this->m_pch[this->m_size] = 0;
		this->m_size = n;
		this->m_pch[this->m_size] = '\0';
	}
}

void MyString::resize(size_t n, char c)
{
	if (n > this->m_size)
	{
		if (n < this->m_reserved_size)
		{
			for (int i = this->m_size; i < n; i++)
			{
				this->m_pch[i] = c;
			}
			this->m_pch[n] = '\0';
		}
		else
		{

			this->m_reserved_size = ((int)(n / (DEFAULT_ADD_RESERVER_SIZE + 1)))*(DEFAULT_ADD_RESERVER_SIZE + 1) + DEFAULT_ADD_RESERVER_SIZE + 1;
			char *p_chnew = new char[m_reserved_size];
			for (int i = 0; i < this->m_size; i++)
			{
				p_chnew[i] = this->m_pch[i];
			}
			for (int i = this->m_size; i < n; i++)
			{
				p_chnew[i] = c;
			}
			p_chnew[n] = '\n';
			delete[] this->m_pch;
			this->m_pch = p_chnew;
		}
		this->m_size = n;
	}
	else
	{
		this->m_pch[this->m_size] = 0;
		this->m_size = n;
		this->m_pch[this->m_size] = '\0';
	}
}

size_t MyString::capacity() const noexcept
{
	return this->m_reserved_size - 1;
}

void MyString::reserve(size_t n)
{
	if (n >= this->m_reserved_size)
	{
		this->m_reserved_size = this->m_reserved_size = ((int)(n / (DEFAULT_ADD_RESERVER_SIZE + 1)))*(DEFAULT_ADD_RESERVER_SIZE + 1) + DEFAULT_ADD_RESERVER_SIZE + 1;
		char* m_pchnew = new char[this->m_reserved_size];
		for (int i = 0; i < this->m_size; i++)
		{
			m_pchnew[i] = this->m_pch[i];
		}
		this->m_pch[this->m_size] = '\n';
		delete[] this->m_pch;
		this->m_pch = m_pchnew;
	}
	else
	{
		return;
	}
}

void MyString::clear() noexcept
{
	if (this->m_pch != NULL)
	{
		this->m_size = 0;
		delete[] this->m_pch;
	}
}






/////////////////////////Hàm
MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString temp;

	return temp;
}



ostream& operator<<(ostream& os, const MyString& str)
{
	for (int i = 0; i < str.m_size; i++)
	{
		os << str.m_pch[i];
	}
	return os;
}

istream& operator>>(istream& is, MyString& str)
{
	is >> str;
	return is;
}