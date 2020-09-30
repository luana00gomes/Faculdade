#include "cpu.h"
#include <iostream>

__BEGIN_API

void CPU::Context::save()

{
	setcontext(&_context);
}

void CPU::Context::load()
{
	getcontext(&_context);
	
}

CPU::Context::~Context()
{	
	if (_stack) delete _stack;
}

void CPU::switch_context(Context *from, Context *to)
{
     	swapcontext(&(from->_context), &(to->_context));
}


__END_API
