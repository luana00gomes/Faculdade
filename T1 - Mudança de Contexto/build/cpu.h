#ifndef cpu_h
#define cpu_h

#include <ucontext.h>
#include <iostream>
#include "traits.h"

__BEGIN_API

class CPU
{
    public:

        class Context
        {
        private:
            static const unsigned int STACK_SIZE = Traits<CPU>::STACK_SIZE;
        public:
            Context() { _stack = 0; }
            
            //Definicao template Variadic para construtor que inicializa com instrução
            template<typename ... Tn>
            Context(void (* func)(Tn ...), Tn ... an){
            
            	getcontext(&_context);
            	_stack = new char[STACK_SIZE]; //malloc ->new em c++()
            	
		if(_stack){
 		_context.uc_link=0;
 		_context.uc_stack.ss_sp= _stack;
 		_context.uc_stack.ss_size=STACK_SIZE;
 		_context.uc_stack.ss_flags=0;
            	
		makecontext(&_context,(void (*)())func, sizeof...(Tn), an...);
		}else
		exit(-1);
            } 

            ~Context();

            void save();
            void load();

        private:            
            char *_stack;
        public:
            ucontext_t _context;
        };

    public:
        static void switch_context(Context *from, Context *to);

};



__END_API

#endif

