//
//  Prototype.cpp
//
// (c) 2020 Carlos Oliveira
//   This code is part of the book
//   "Options and Derivatives Programming in C++20: Algorithms and Programming Techniques for the Financial Industry 2nd Edition"
//    by Carlos Oliveira, Apress, 2020.
// For more information, visit http://coliveira.net


#include "Prototype.hpp"

Prototype *Prototype::s_prototype = nullptr;


Prototype::Prototype()
{
}

Prototype::Prototype(const Prototype &p)
: m_var1(p.m_var1)
{
}

Prototype::~Prototype()
{

}

void Prototype::setVar1(int v)
{
    m_var1 = v;
}

const Prototype &Prototype::getPrototype()
{
    if (!s_prototype)
    {
        s_prototype = new Prototype();
    }
    return *s_prototype;
}

Prototype &Prototype::operator=(const Prototype &p)
{
    if (this != &p)
    {
        m_var1 = p.m_var1;
    }
    return *this;
}

Prototype *Prototype::clone() const
{
    Prototype *a = new Prototype(*this);
    return a;
}


void usePrototype()
{
    const Prototype &p = Prototype::getPrototype();

    Prototype *pnew =  p.clone();
    pnew->setVar1(22);

    Prototype *pn2 = pnew->clone();
    pn2->setVar1(43);

    delete pnew;
    delete pn2;
}


