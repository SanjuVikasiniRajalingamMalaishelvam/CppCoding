/*
 * CComplex.h
 *
 *  Created on: 11 Feb 2023
 *      Author: sanju
 */

#ifndef CCOMPLEX_H_
#define CCOMPLEX_H_


#include <iostream>
#include <string>
#include <cmath>

class CComplex
{
private:
	float m_real;
	float m_imaginary;
public:
	CComplex(float real = 0, float imaginary = 0);
	virtual ~CComplex();
	CComplex(CComplex const& c);
	void set(float real, float imaginary);
	float abs();
	void print();
	CComplex& operator++();
	CComplex operator++(int);
	friend CComplex& operator+(CComplex& lhs, float rhs);
	CComplex& operator+(CComplex& lhs);
	friend CComplex& operator-(CComplex& lhs, float rhs);
	CComplex& operator-(CComplex& lhs);
	friend CComplex& operator*(CComplex& lhs, float rhs);
	CComplex& operator*(CComplex& lhs);
	friend CComplex& operator/(CComplex& lhs, float rhs);
	CComplex& operator/(CComplex& lhs);
};

#endif /* CCOMPLEX_H_ */
