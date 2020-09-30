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
            Context() { _stack = 0; } //Construtor
            Context(void (* func)(Tn ...), Tn ... an); //Modelo 2 Construtor //implementar

            ~Context(); //Destrutor //implementar

            void save(); //implementar
            void load(); //implementar

        private:            
            char *_stack;
        public:
            ucontext_t _context; //tipo contexto da biblioteca ucontext.h
        };

    public:

        static void switch_context(Context *from, Context *to); //implementar, método da CPU

};

__END_API

#endif

