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
	if (pos >= 0 && pos <= str.m_size)
	{
		if (len != (pow(2, 32) - 1))
		{
			if (pos != str.m_size && (len <= str.m_size - pos))
			{
				this->m_size = len;
			}
			else if (len > (str.m_size - pos))
			{
				this->m_size = str.m_size - pos;
			}
			else if (pos == str.m_size)
			{
				this->m_size = 0;
			}
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
				this->m_pch[i] = str.m_pch[pos + i];
			}
			this->m_pch[this->m_size] = '\0';
		}
		else
		{
			if ((str.m_size - pos) <= DEFAULT_ADD_RESERVER_SIZE)
			{
				this->m_reserved_size = DEFAULT_ADD_RESERVER_SIZE + 1;
			}
			else
			{
				this->m_reserved_size = ((int)((str.m_size - pos) / (DEFAULT_ADD_RESERVER_SIZE + 1)))*(DEFAULT_ADD_RESERVER_SIZE + 1) + DEFAULT_ADD_RESERVER_SIZE + 1;
			}
			this->m_size = str.m_size - pos;
			this->m_pch = new char[this->m_reserved_size];
			for (int i = 0; i < this->m_size; i++)
			{
				this->m_pch[i] = str.m_pch[pos + i];
			}
			this->m_pch[this->m_size] = '\0';
		}
	}
	else
	{
		throw;
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
			p_chnew[n] = '\0';
			delete[] this->m_pch;
			this->m_pch = p_chnew;
		}
		this->m_size = n;
	}
	else if (n < this->m_size&&n >= 0)
	{
		this->m_pch[this->m_size] = 0;
		this->m_size = n;
		this->m_pch[this->m_size] = '\0';
	}
	else if (n < 0)
	{
		throw;
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
			p_chnew[n] = '\0';
			delete[] this->m_pch;
			this->m_pch = p_chnew;
		}
		this->m_size = n;
	}
	else if (n <= this->m_size&&n >= 0)
	{
		this->m_pch[this->m_size] = 0;
		this->m_size = n;
		this->m_pch[this->m_size] = '\0';
	}
	else if (n < 0)
	{
		throw;
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
		this->m_pch[this->m_size] = '\0';
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
		this->m_pch = NULL;
	}
}

bool MyString::empty() const
{
	return this->m_size == 0;
}

void MyString::shrink_to_fit()
{
	this->m_reserved_size = ((int)(this->m_size / (DEFAULT_ADD_RESERVER_SIZE + 1)))*(DEFAULT_ADD_RESERVER_SIZE + 1) + DEFAULT_ADD_RESERVER_SIZE + 1;
	char* m_pchnew = new char[this->m_reserved_size];
	for (int i = 0; i < this->m_size; i++)
	{
		m_pchnew[i] = this->m_pch[i];
	}
	m_pchnew[this->m_size] = '\0';
	delete[] this->m_pch;
	this->m_pch = m_pchnew;
}

char & MyString::operator[](size_t pos)
{
	if (pos >= 0 && pos <= this->m_size)
	{
		return this->m_pch[pos];
	}
	else
	{
		throw;
	}
}

const char & MyString::operator[](size_t pos) const
{
	if (pos >= 0 && pos <= this->m_size)
	{
		return this->m_pch[pos];
	}
	else
	{
		throw;
	}
}

char & MyString::at(size_t pos)
{
	if (pos >= 0 && pos < this->m_size)
	{
		return this->m_pch[pos];
	}
	else
	{
		throw;
	}
}

const char & MyString::at(size_t pos) const
{
	if (pos >= 0 && pos < this->m_size)
	{
		return this->m_pch[pos];
	}
	else
	{
		throw;
	}
}

char & MyString::back()
{
	if (!this->empty())
	{
		return this->m_pch[this->m_size - 1];
	}
	else
	{
		throw;
	}
}

const char & MyString::back() const
{
	if (!this->empty())
	{
		return this->m_pch[this->m_size - 1];
	}
	else
	{
		throw;
	}
}

char & MyString::front()
{
	if (!this->empty())
	{
		return this->m_pch[0];
	}
	else
	{
		throw;
	}
}

const char & MyString::front() const
{
	if (!this->empty())
	{
		return this->m_pch[0];
	}
	else
	{
		throw;
	}
}

MyString & MyString::operator+=(const MyString & str)
{
	if (str.m_size < (this->m_reserved_size - this->m_size))
	{
		for (int i = 0; i < str.m_size; i++)
		{
			this->m_pch[this->m_size + i] = str[i];
		}
		this->m_size += str.m_size;
		this->m_pch[this->m_size] = '\0';
	}
	else
	{
		int m_pch_size = this->m_size;
		this->resize(this->m_size + str.m_size);
		for (int i = 0; i < str.m_size; i++)
		{
			this->m_pch[m_pch_size + i] = str[i];
		}
		this->m_pch[this->m_size] = '\0';
	}
	return *this;
}

MyString & MyString::operator+=(const char * s)
{
	int str_size = lengthString(s);
	if (str_size < (this->m_reserved_size - this->m_size))
	{
		for (int i = 0; i < str_size; i++)
		{
			this->m_pch[this->m_size + i] = s[i];
		}
		this->m_size += str_size;
		this->m_pch[this->m_size] = '\0';
	}
	else
	{
		int m_pch_size = this->m_size;
		this->resize(this->m_size + str_size);
		for (int i = 0; i < str_size; i++)
		{
			this->m_pch[m_pch_size + i] = s[i];
		}
		this->m_pch[this->m_size] = '\0';
	}
	return *this;
}

MyString & MyString::operator+=(char c)
{
	if (1 < (this->m_reserved_size - this->m_size))
	{
		this->m_pch[this->m_size] = c;
		this->m_size++;
		this->m_pch[this->m_size] = '\0';
	}
	else
	{
		this->resize(this->m_size + 1);
		this->m_pch[this->m_size - 1] = c;
		this->m_pch[this->m_size] = '\0';
	}
	return *this;
}

MyString & MyString::append(const MyString & str)
{
	return this->operator+=(str);
}

MyString & MyString::append(const MyString & str, size_t subpos, size_t sublen)
{
	if (subpos <= str.m_size)
	{
		char *m_pch_append;
		if ((sublen != (pow(2, 32) - 1)) && sublen >= 0 && (sublen <= (str.m_size - subpos)))
		{
			m_pch_append = new char[sublen + 1];
			for (int i = 0; i < sublen; i++)
			{
				m_pch_append[i] = str[subpos + i];
			}
			m_pch_append[sublen] = '\0';
		}
		else
		{
			m_pch_append = new char[str.m_size - subpos + 1];
			for (int i = 0; i < str.m_size - subpos + 1; i++)
			{
				m_pch_append[i] = str[subpos + i];
			}
			m_pch_append[str.m_size - subpos] = '\0';
		}
		this->operator+=(m_pch_append);
		if (m_pch_append != NULL)
		{
			delete[] m_pch_append;
		}
		return *this;
	}
	else
	{
		throw;
	}
}

MyString & MyString::append(const char * s)
{
	return this->operator+=(s);
}

MyString & MyString::append(const char * s, size_t n)
{
	if (n > 0)
	{
		char *m_pch_append = new char[n + 1];
		for (int i = 0; i < lengthString(s); i++)
		{
			m_pch_append[i] = s[i];
		}
		m_pch_append[n] = '\0';
		this->operator+=(m_pch_append);
		if (m_pch_append != NULL)
		{
			delete[] m_pch_append;
		}
		return *this;
	}
	else if (n < 0)
	{
		throw;
	}
	else
	{
		return *this;
	}
}

MyString & MyString::append(size_t n, char c)
{
	if (n > 0)
	{
		char *m_pch_append = new char[n + 1];
		for (int i = 0; i < n; i++)
		{
			m_pch_append[i] = c;
		}
		m_pch_append[n] = '\0';
		this->operator+=(m_pch_append);
		if (m_pch_append != NULL)
		{
			delete[] m_pch_append;
		}
		return *this;
	}
	else if (n < 0)
	{
		throw;
	}
	else
	{
		return *this;
	}
}

void MyString::push_back(char c)
{
	this->operator+=(c);
}

MyString & MyString::assign(const MyString & str)
{
	if (this->m_size == 0)
	{
		return this->append(str);
	}
	else
	{
		this->m_pch[this->m_size] = 0;
		this->m_size = 0;
		return this->append(str);
	}
}

MyString & MyString::assign(const MyString & str, size_t subpos, size_t sublen)
{
	if (this->m_size == 0)
	{
		return this->append(str, subpos, sublen);
	}
	else
	{
		this->m_pch[this->m_size] = 0;
		this->m_size = 0;
		return this->append(str, subpos, sublen);
	}
}

MyString & MyString::assign(const char * s)
{
	if (this->m_size == 0)
	{
		return this->append(s);
	}
	else
	{
		this->m_pch[this->m_size] = 0;
		this->m_size = 0;
		return this->append(s);
	}
}

MyString & MyString::assign(const char * s, size_t n)
{
	if (this->m_size == 0)
	{
		return this->append(s, n);
	}
	else
	{
		this->m_pch[this->m_size] = 0;
		this->m_size = 0;
		return this->append(s, n);
	}
}

MyString & MyString::assign(size_t n, char c)
{
	if (this->m_size == 0)
	{
		return this->append(n, c);
	}
	else
	{
		this->m_pch[this->m_size] = 0;
		this->m_size = 0;
		return this->append(n, c);
	}
}

MyString & MyString::insert(size_t pos, const MyString & str)
{
	if (pos <= this->m_size)
	{
		MyString MyString_Insert(*this, pos);
		this->m_pch[this->m_size] = 0;
		this->m_size = pos;
		this->append(str);
		this->append(MyString_Insert);
		return *this;
	}
	else
	{
		throw;
	}
}

MyString & MyString::insert(size_t pos, const MyString & str, size_t subpos, size_t sublen)
{
	if (pos <= this->m_size)
	{
		MyString MyString_Insert(*this, pos);
		this->m_pch[this->m_size] = 0;
		this->m_size = pos;
		this->append(str, subpos, sublen);
		this->append(MyString_Insert);
		return *this;
	}
	else
	{
		throw;
	}
}

MyString & MyString::insert(size_t pos, const char * s)
{
	if (pos <= this->m_size)
	{
		MyString MyString_Insert(*this, pos);
		this->m_pch[this->m_size] = 0;
		this->m_size = pos;
		this->append(s);
		this->append(MyString_Insert);
		return *this;
	}
	else
	{
		throw;
	}
}

MyString & MyString::insert(size_t pos, const char * s, size_t n)
{
	if (pos <= this->m_size)
	{
		MyString MyString_Insert(*this, pos);
		this->m_pch[this->m_size] = 0;
		this->m_size = pos;
		this->append(s, n);
		this->append(MyString_Insert);
		return *this;
	}
	else
	{
		throw;
	}
}

MyString & MyString::insert(size_t pos, size_t n, char c)
{
	if (pos <= this->m_size)
	{
		MyString MyString_Insert(*this, pos);
		this->m_pch[this->m_size] = 0;
		this->m_size = pos;
		this->append(n, c);
		this->append(MyString_Insert);
		return *this;
	}
	else
	{
		throw;
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