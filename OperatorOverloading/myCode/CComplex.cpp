/*
 * CComplex.cpp
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#include "CComplex.h"
using namespace std;

CComplex::CComplex(float real, float imaginary)
{
	set(real, imaginary);
}

CComplex::~CComplex()
{
	// TODO Auto-generated destructor stub
}

CComplex::CComplex(const CComplex &c)
{
	m_real = c.m_real;
	m_imaginary = c.m_imaginary;
}

void CComplex::set(float real, float imaginary)
{
	if ((real <= -100) || (real >= 100))
	{
		real = 0;
	}
	if ((imaginary <= -100) || (imaginary >= 100))
	{
		imaginary = 0;
	}
	m_real = real;
	m_imaginary = imaginary;
}

float CComplex::abs()
{
	float realValue = std::abs(m_real);
	return realValue;
}

void CComplex::print()
{
	cout << this <<endl;
	cout << m_real << "+i" << m_imaginary <<endl;
}

//CComplex& CComplex::operator ++()
//{
//}
//
//CComplex CComplex::operator ++(int int1)
//{
//}
