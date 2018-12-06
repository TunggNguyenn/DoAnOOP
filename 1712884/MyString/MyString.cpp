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

MyString::MyString(MyString && str) noexcept
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

MyString & MyString::operator=(MyString && str) noexcept
{
	MyString MyString_assign(str);
	return MyString_assign;
}

MyStringIterator MyString::begin() noexcept
{
	return MyStringIterator(this->m_pch);
}

MyStringIterator MyString::end() noexcept
{
	return MyStringIterator(this->m_pch, this->size());
}

Reverse_MyStringIterator MyString::rbegin() noexcept
{
	return Reverse_MyStringIterator(this->m_pch, this->size() - 1);
}

Reverse_MyStringIterator MyString::rend() noexcept
{
	return Reverse_MyStringIterator(this->m_pch, -1);
}

const_MyStringIterator MyString::cbegin() const noexcept
{
	return const_MyStringIterator(this->m_pch);
}

const_MyStringIterator MyString::cend() const noexcept
{
	return const_MyStringIterator(this->m_pch, this->size());
}

const_Reverse_MyStringIterator MyString::crbegin() const noexcept
{
	return const_Reverse_MyStringIterator(this->m_pch, this->size() - 1);
}

const_Reverse_MyStringIterator MyString::crend() const noexcept
{
	return const_Reverse_MyStringIterator(this->m_pch, -1);
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

MyString & MyString::assign(MyString && str) noexcept
{
	MyString MyString_assign(str);
	return MyString_assign;
}

MyString & MyString::insert(size_t pos, const MyString & str)
{
	if (pos >= 0 && pos <= this->m_size)
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
	if (pos >= 0 && pos <= this->m_size)
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
	if (pos >= 0 && pos <= this->m_size)
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
	if (pos >= 0 && pos <= this->m_size)
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
	if (pos >= 0 && pos <= this->m_size)
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

MyStringIterator MyString::insert(const_MyStringIterator p, size_t n, char c)
{
	this->insert(p.get_Current(), n, c);
	return MyStringIterator(this->m_pch, p.get_Current());
}

MyStringIterator MyString::insert(const_MyStringIterator p, char c)
{
	this->insert(p.get_Current(), 1, c);
	return MyStringIterator(this->m_pch, p.get_Current());
}



MyString & MyString::erase(size_t pos, size_t len)
{
	if (pos >= 0 && pos <= this->m_size)
	{
		if (len == (pow(2, 32) - 1) || len >= (this->m_size - pos))
		{
			this->m_pch[this->m_size] = 0;
			this->m_size = pos;
			this->m_pch[this->m_size] = '\0';
		}
		else
		{
			this->m_pch[this->m_size] = 0;
			for (auto i = 0; i < this->m_size - (len + pos); i++)
			{
				this->m_pch[pos + i] = this->m_pch[pos + len + i];
			}
			this->m_size = this->m_size - len;
			this->m_pch[this->m_size] = '\0';
		}
		return *this;
	}
	else
	{
		throw;
	}
}

MyStringIterator MyString::erase(const_MyStringIterator p)
{
	this->erase(p.get_Current(), 1);
	return MyStringIterator(this->m_pch, p.get_Current());
}

MyStringIterator MyString::erase(const_MyStringIterator first, const_MyStringIterator last)
{
	this->erase(first.get_Current(), last.get_Current()-first.get_Current());
	return MyStringIterator(this->m_pch, first.get_Current());
}

MyString & MyString::replace(size_t pos, size_t len, const MyString & str)
{
	this->erase(pos, len);
	this->insert(pos, str);
	return *this;
}

MyString & MyString::replace(size_t pos, size_t len, const MyString & str, size_t subpos, size_t sublen)
{
	this->erase(pos, len);
	this->insert(pos, str, subpos, sublen);
	return *this;
}

MyString & MyString::replace(size_t pos, size_t len, const char * s)
{
	this->erase(pos, len);
	this->insert(pos, s);
	return *this;
}

MyString & MyString::replace(size_t pos, size_t len, const char * s, size_t n)
{
	this->erase(pos, len);
	this->insert(pos, s, n);
	return *this;
}

MyString & MyString::replace(size_t pos, size_t len, size_t n, char c)
{
	this->erase(pos, len);
	this->insert(pos, n, c);
	return *this;
}

void MyString::swap(MyString & str)
{
	char *m_pch_temp = this->m_pch;
	size_t m_size_temp = this->m_size;
	size_t m_reserved_size_temp = this->m_reserved_size;

	this->m_pch = str.m_pch;
	this->m_size = str.m_size;
	this->m_reserved_size = str.m_reserved_size;

	str.m_pch = m_pch_temp;
	str.m_size = m_size_temp;
	str.m_reserved_size = m_reserved_size_temp;
}

void MyString::pop_back()
{
	if(!this->empty())
	{
		this->m_pch[this->m_size] = 0;
		this->m_size--;
		this->m_pch[this->m_size] = '\0';
	}
	else
	{
		throw;
	}
}

const char * MyString::c_str() const noexcept
{
	return this->m_pch;
}

const char * MyString::data() const noexcept
{
	return this->m_pch;
}

size_t MyString::copy(char * s, size_t len, size_t pos) const
{
	if (pos <= this->m_size)
	{
		int length;
		if (pos + len >= this->m_size)
		{
			length = this->m_size - pos;
		}
		else
		{
			length = len;
		}

		for (auto i = 0; i < length; i++)
		{
			s[i] = this->m_pch[pos + i];
		}
		return length;
	}
	else
	{
		throw;
	}
}

size_t MyString::find(const MyString & str, size_t pos) const noexcept
{
	if (pos >= 0 && (pos <= this->size() - str.size()))
	{
		int count = 0;
		for (auto i = 0; i <= this->size() - str.size() - pos; i++)
		{
			if (str[count] == this->m_pch[pos + i])
			{
				count++;
				for (auto j = i + 1; j < this->size() - pos; j++)
				{
					if (str[count] == this->m_pch[pos + j])
					{
						count++;
					}
					else
					{
						break;
					}
				}
				if (count == str.m_size)
				{
					return pos + i;
				}
				else
				{
					count = 0;
				}
			}
		}
		return npos;
	}
	else
	{
		return npos;
	}
}

size_t MyString::find(const char * s, size_t pos) const
{
	MyString MyString_find(s);
	return this->find(MyString_find, pos);
}

size_t MyString::find(const char * s, size_t pos, size_t n) const
{
	if (lengthString(s) >= n)
	{
		MyString MyString_find(s, n);
		return this->find(MyString_find, pos);
	}
	else
	{
		return npos;
	}
}

size_t MyString::find(char c, size_t pos) const noexcept
{
	if (pos >= 0 && pos < this->size())
	{
		for (auto i = pos; i < this->size(); i++)
		{
			if (this->m_pch[i] == c)
			{
				return i;
			}
		}
		return npos;
	}
	else
	{
		return npos;
	}
}

size_t MyString::rfind(const MyString & str, size_t pos) const noexcept
{
	if (pos >= this->size())
	{
		pos = this->size() - 1;
	}
	int count = 0;
	int tempt = -1;
	for (int i = 0; i <= pos; i++)
	{
		if (str[count] == this->m_pch[i])
		{
			count++;
			for (int j = i + 1; j <= pos; j++)
			{
				if (str[count] == this->m_pch[j])
				{
					count++;
				}
				else
				{
					break;
				}
			}
			if (count == str.size())
			{
				tempt = i;
			}
			count = 0;

		}
	}
	if (tempt != -1)
	{
		return tempt;
	}
	else
	{
		return npos;
	}
}

size_t MyString::rfind(const char * s, size_t pos) const
{
	MyString MyString_rfind(s);
	return this->rfind(MyString_rfind, pos);
}

size_t MyString::rfind(const char * s, size_t pos, size_t n) const
{
	if (lengthString(s) >= n)
	{
		MyString MyString_rfind(s, n);
		return this->rfind(MyString_rfind, pos);
	}
	else
	{
		return npos;
	}
}

size_t MyString::rfind(char c, size_t pos) const noexcept
{
	if (pos >= this->size())
	{
		pos = this->size() - 1;
	}
	int tempt = -1;
	for (auto i = 0; i <= pos; i++)
	{
		if (this->m_pch[i] == c)
		{
			tempt = i;
		}
	}
	if (tempt != -1)
	{
		return tempt;
	}
	else
	{
		return npos;
	}
}

size_t MyString::find_first_of(const MyString & str, size_t pos) const
{
	if (pos < this->size())
	{
		for (int i = pos; i < this->size(); i++)
		{
			for (int j = 0; j < str.size(); j++)
			{
				if (this->m_pch[i] == str[j])
				{
					return i; break;
				}
			}
		}
		return npos;
	}
	else
	{
		return npos;
	}
}

size_t MyString::find_first_of(const char * s, size_t pos) const
{
	MyString MyString_find_first_of(s);
	return this->find_first_of(MyString_find_first_of, pos);
}

size_t MyString::find_first_of(const char * s, size_t pos, size_t n) const
{
	if (lengthString(s) >= n)
	{
		MyString MyString_find_first_of(s, n);
		return this->find_first_of(MyString_find_first_of, pos);
	}
	else
	{
		return npos;
	}
}

size_t MyString::find_first_of(char c, size_t pos) const noexcept
{
	if (pos >= 0 && pos < this->size())
	{
		for (auto i = pos; i < this->size(); i++)
		{
			if (this->m_pch[i] == c)
			{
				return i;
			}
		}
		return npos;
	}
	else
	{
		return npos;
	}
}

size_t MyString::find_last_of(const MyString & str, size_t pos) const noexcept
{
	if (pos >= this->size())
	{
		pos = this->size() - 1;
	}
	int tempt = -1;
	for (int i = 0; i <= pos; i++)
	{
		for (int j = 0; j < str.size(); j++)
		{
			if (this->m_pch[i] == str[j])
			{
				tempt = i; break;
			}
		}
	}
	if (tempt != -1)
	{
		return tempt;
	}
	else
	{
		return npos;
	}
}

size_t MyString::find_last_of(const char * s, size_t pos) const
{
	MyString MyString_find_last_of(s);
	return this->find_last_of(MyString_find_last_of, pos);
}

size_t MyString::find_last_of(const char * s, size_t pos, size_t n) const
{
	if (lengthString(s) >= n)
	{
		MyString MyString_find_last_of(s, n);
		return this->find_last_of(MyString_find_last_of, pos);
	}
	else
	{
		return npos;
	}
}

size_t MyString::find_last_of(char c, size_t pos) const noexcept
{
	if (pos >= this->size())
	{
		pos = this->size() - 1;
	}
	int tempt = -1;
	for (auto i = 0; i <= pos; i++)
	{
		if (this->m_pch[i] == c)
		{
			tempt = i;
		}
	}
	if (tempt != -1)
	{
		return tempt;
	}
	else
	{
		return npos;
	}
}

size_t MyString::find_first_not_of(const MyString & str, size_t pos) const noexcept
{
	if (pos < this->size())
	{
		int count = 0;
		for (int i = pos; i < this->size(); i++)
		{
			for (int j = 0; j < str.size(); j++)
			{
				if (this->m_pch[i] != str[j])
				{
					count++;
				}
				else
				{
					break;
				}
			}

			if (count == str.size())
			{
				return i;
			}
			else
			{
				count = 0;
			}
		}
		return npos;
	}
	else
	{
		return npos;
	}
}

size_t MyString::find_first_not_of(const char * s, size_t pos) const
{
	MyString MyString_find_first_not_of(s);
	return this->find_first_not_of(MyString_find_first_not_of, pos);
}

size_t MyString::find_first_not_of(const char * s, size_t pos, size_t n) const
{
	if (lengthString(s) >= n)
	{
		MyString MyString_find_first_not_of(s, n);
		return this->find_first_not_of(MyString_find_first_not_of, pos);
	}
	else
	{
		return npos;
	}
}

size_t MyString::find_first_not_of(char c, size_t pos) const noexcept
{
	if (pos >= 0 && pos < this->size())
	{
		for (auto i = pos; i < this->size(); i++)
		{
			if (this->m_pch[i] != c)
			{
				return i;
			}
		}
		return npos;
	}
	else
	{
		return npos;
	}
}

size_t MyString::find_last_not_of(const MyString & str, size_t pos) const noexcept
{
	if (pos >= this->size())
	{
		pos = this->size() - 1;
	}
	int tempt = -1;
	int count = 0;
	for (int i = 0; i <= pos; i++)
	{
		for (int j = 0; j < str.size(); j++)
		{
			if (this->m_pch[i] != str[j])
			{
				count++;
			}
			else
			{
				break;
			}
		}
		if (count == str.size())
		{
			tempt = i;
		}
		count = 0;
	}
	if (tempt != -1)
	{
		return tempt;
	}
	else
	{
		return npos;
	}
}

size_t MyString::find_last_not_of(const char * s, size_t pos) const
{
	MyString MyString_find_last_not_of(s);
	return this->find_last_not_of(MyString_find_last_not_of, pos);
}

size_t MyString::find_last_not_of(const char * s, size_t pos, size_t n) const
{
	if (lengthString(s) >= n)
	{
		MyString MyString_find_last_not_of(s, n);
		return this->find_last_not_of(MyString_find_last_not_of, pos);
	}
	else
	{
		return npos;
	}
}

size_t MyString::find_last_not_of(char c, size_t pos) const noexcept
{
	if (pos >= this->size())
	{
		pos = this->size() - 1;
	}
	int tempt = -1;
	for (auto i = 0; i <= pos; i++)
	{
		if (this->m_pch[i] != c)
		{
			tempt = i;
		}
	}
	if (tempt != -1)
	{
		return tempt;
	}
	else
	{
		return npos;
	}
}

MyString MyString::substr(size_t pos, size_t len) const
{
	return MyString(*this, pos, len);
}

int MyString::compare(const MyString & str) const noexcept
{
	int temp_length = this->size() < str.size() ? this->size() : str.size();
	for (int i = 0; i < temp_length; i++)
	{
		if (this->m_pch[i] < str[i])
		{
			return -1;
		}
		else if (this->m_pch[i] > str[i])
		{
			return 1;
		}
	}

	if (this->size() < str.size())
	{
		return -1;
	}
	else if (this->size() > str.size())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int MyString::compare(size_t pos, size_t len, const MyString & str) const
{
	MyString MyString_compare(*this, pos, len);
	return MyString_compare.compare(str);
}

int MyString::compare(size_t pos, size_t len, const MyString & str, size_t subpos, size_t sublen) const
{
	MyString MyString_compare(*this, pos, len);
	MyString subMyString_compare(str, subpos, sublen);
	
	return MyString_compare.compare(subMyString_compare);
}

int MyString::compare(const char * s) const
{
	int temp_length = this->size() < lengthString(s) ? this->size() : lengthString(s);
	for (int i = 0; i < temp_length; i++)
	{
		if (this->m_pch[i] < s[i])
		{
			return -1;
		}
		else if (this->m_pch[i] > s[i])
		{
			return 1;
		}
	}

	if (this->size() < lengthString(s))
	{
		return -1;
	}
	else if (this->size() > lengthString(s))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int MyString::compare(size_t pos, size_t len, const char * s) const
{
	MyString MyString_compare(s);

	return this->compare(pos, len, MyString_compare);
}

int MyString::compare(size_t pos, size_t len, const char * s, size_t n) const
{
	MyString MyString_compare(s, n);

	return this->compare(pos, len, MyString_compare);
}








//----------------------------------------------------------Hàm----------------------------------------
MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString MyString_temp(lhs);
	MyString_temp.append(rhs);

	return MyString_temp;
}

MyString operator+(MyString && lhs, MyString && rhs)
{
	MyString MyString_temp(lhs);
	MyString_temp.append(MyString(rhs));

	return MyString_temp;
}

MyString operator+(MyString && lhs, const MyString & rhs)
{
	MyString MyString_temp(lhs);
	MyString_temp.append(rhs);

	return MyString_temp;
}

MyString operator+(const MyString & lhs, MyString && rhs)
{
	MyString MyString_temp(lhs);
	MyString_temp.append(MyString(rhs));

	return MyString_temp;
}

MyString operator+(const MyString & lhs, const char * rhs)
{
	MyString MyString_temp(lhs);
	MyString_temp.append(rhs);

	return MyString_temp;
}

MyString operator+(MyString && lhs, const char * rhs)
{
	MyString MyString_temp(lhs);
	MyString_temp.append(rhs);

	return MyString_temp;
}

MyString operator+(const char * lhs, const MyString & rhs)
{
	MyString MyString_temp(lhs);
	MyString_temp.append(rhs);

	return MyString_temp;
}

MyString operator+(const char * lhs, MyString && rhs)
{
	MyString MyString_temp(lhs);
	MyString_temp.append(MyString(rhs));

	return MyString_temp;
}

MyString operator+(const MyString & lhs, char rhs)
{
	MyString MyString_temp(lhs);
	MyString_temp.append(1, rhs);

	return MyString_temp;
}

MyString operator+(MyString && lhs, char rhs)
{
	MyString MyString_temp(lhs);
	MyString_temp.append(1, rhs);

	return MyString_temp;
}

MyString operator+(char lhs, const MyString & rhs)
{
	MyString MyString_temp(1, lhs);
	MyString_temp.append(rhs);

	return MyString_temp;
}

MyString operator+(char lhs, MyString && rhs)
{
	MyString MyString_temp(1, lhs);
	MyString_temp.append(MyString(rhs));

	return MyString_temp;
}

bool operator==(const MyString & lhs, const MyString & rhs) noexcept
{
	if (lhs.compare(rhs) == 0)
	{
		return true;
	}
	return false;
}

bool operator==(const char * lhs, const MyString & rhs)
{
	if (rhs.compare(lhs) == 0)
	{
		return true;
	}
	return false;
}

bool operator==(const MyString & lhs, const char * rhs)
{
	if (lhs.compare(rhs) == 0)
	{
		return true;
	}
	return false;
}

bool operator!=(const MyString & lhs, const MyString & rhs) noexcept
{
	if (lhs.compare(rhs) != 0)
	{
		return true;
	}
	return false;
}

bool operator!=(const char * lhs, const MyString & rhs)
{
	if (rhs.compare(lhs) != 0)
	{
		return true;
	}
	return false;
}

bool operator!=(const MyString & lhs, const char * rhs)
{
	if (lhs.compare(rhs) != 0)
	{
		return true;
	}
	return false;
}

bool operator<(const MyString & lhs, const MyString & rhs) noexcept
{
	if (lhs.compare(rhs) < 0)
	{
		return true;
	}
	return false;
}

bool operator<(const char * lhs, const MyString & rhs)
{
	if (rhs.compare(lhs) > 0)
	{
		return true;
	}
	return false;
}

bool operator<(const MyString & lhs, const char * rhs)
{
	if (lhs.compare(rhs) < 0)
	{
		return true;
	}
	return false;
}

bool operator<=(const MyString & lhs, const MyString & rhs) noexcept
{
	if (lhs.compare(rhs) <= 0)
	{
		return true;
	}
	return false;
}

bool operator<=(const char * lhs, const MyString & rhs)
{
	if (rhs.compare(lhs) >= 0)
	{
		return true;
	}
	return false;
}

bool operator<=(const MyString & lhs, const char * rhs)
{
	if (lhs.compare(rhs) <= 0)
	{
		return true;
	}
	return false;
}

bool operator>(const MyString & lhs, const MyString & rhs) noexcept
{
	if (lhs.compare(rhs) > 0)
	{
		return true;
	}
	return false;
}

bool operator>(const char * lhs, const string & rhs)
{
	if (rhs.compare(lhs) < 0)
	{
		return true;
	}
	return false;
}

bool operator>(const MyString & lhs, const char * rhs)
{
	if (lhs.compare(rhs) > 0)
	{
		return true;
	}
	return false;
}

bool operator>=(const MyString & lhs, const MyString & rhs) noexcept
{
	if (lhs.compare(rhs) >= 0)
	{
		return true;
	}
	return false;
}

bool operator>=(const char * lhs, const MyString & rhs)
{
	if (rhs.compare(lhs) <= 0)
	{
		return true;
	}
	return false;
}

bool operator>=(const MyString & lhs, const char * rhs)
{
	if (lhs.compare(rhs) >= 0)
	{
		return true;
	}
	return false;
}



//ostream& operator<<(ostream& os, const MyString& str)
//{
//	for (int i = 0; i < str.m_size; i++)
//	{
//		os << str.m_pch[i];
//	}
//	return os;
//}

//istream& operator>>(istream& is, MyString& str)
//{
//	is >> str;
//	return is;
//}

void swap(MyString & x, MyString & y)
{
	x.swap(y);
}

istream & operator>>(istream & is, MyString & str)
{
	char* c_str = new char[256];
	is >> c_str;

	str.assign(c_str);

	return is;
}

ostream & operator<<(ostream & os, const MyString & str)
{
	for (int i = 0; i < str.size(); i++)
	{
		os << str[i];
	}
	return os;
}

istream & getline(istream & is, MyString & str, char delim)
{
	char* c_str = new char[256];
	is.get(c_str, 256, delim);

	str.append(c_str);

	return is;
}

istream & getline(istream & is, MyString & str)
{
	char* c_str = new char[256];
	is.get(c_str, 256);

	str.append(c_str);

	return is;
}


