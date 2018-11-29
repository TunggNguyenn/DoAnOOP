#include "MyIterator.h"



MyIterator::MyIterator()
{
	this->m_it_pch = NULL;
}

MyIterator::MyIterator(char * s) : m_it_pch(s)
{
}

MyIterator::MyIterator(const MyIterator & m_it_s) : m_it_pch(m_it_s.m_it_pch)
{
}


MyIterator & MyIterator::operator++()
{
	++this->m_it_pch;
	return *this;
}

MyIterator MyIterator::operator++(int)
{
	MyIterator temp = *this;
	this->operator++();
	return temp;
}

bool MyIterator::operator==(const MyIterator & m_it_s) const
{
	return this->m_it_pch == m_it_s.m_it_pch;
}

bool MyIterator::operator!=(const MyIterator & m_it_s) const
{
	return this->m_it_pch != m_it_s.m_it_pch;
}

char& MyIterator::operator*()
{
	return *this->m_it_pch;
}


const_MyIterator::const_MyIterator()
{
	this->m_it_pch = NULL;
}

const_MyIterator::const_MyIterator(char * s) : m_it_pch(s)
{
}

const_MyIterator::const_MyIterator(const const_MyIterator & m_it_s) : m_it_pch(m_it_s.m_it_pch)
{
}

const_MyIterator & const_MyIterator::operator++()
{
	++this->m_it_pch;
	return *this;
}

const_MyIterator const_MyIterator::operator++(int)
{
	const_MyIterator temp = *this;
	this->operator++();
	return temp;
}

bool const_MyIterator::operator==(const const_MyIterator & m_it_s) const
{
	return this->m_it_pch == m_it_s.m_it_pch;
}

bool const_MyIterator::operator!=(const const_MyIterator & m_it_s) const
{
	return this->m_it_pch != m_it_s.m_it_pch;
}

char const_MyIterator::operator*()
{
	return *this->m_it_pch;
}


