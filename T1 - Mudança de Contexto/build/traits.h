#ifndef traits_h
#define traits_h

//Não alterar as 3 declarações abaixo

#define __BEGIN_API             namespace SOLUTION {
#define __END_API               }
#define __USING_API             using namespace SOLUTION;

__BEGIN_API

#include <ucontext.h>

class CPU; //declaração das classes criadas nos trabalhos devem ser colocadas aqui

//declaração da classe Traits
template<typename T>
struct Traits {
};

template<> struct Traits<CPU>
{
    static const unsigned int STACK_SIZE = 64000;
    //Adicionado aqui a declaração do tamanho da Pilha
};

__END_API

#endif

/*
PARA FACILITAR LEITURA DO CÓDIGO:

Tasks 		-> 	threads
process stack 	->	the stack used by the process during its execution
program counter -> 	stores the address of the next instruction to be executed
signal mask 	->	used to store the information about those signals it will block


BIBLIOTECA UCONTEXT.H
struct ucontext_t
{
    ucontext_t *uc_link; 	//ponteiro para o próximo contexto a ser executado
    sigset_t uc_sigmask;    	//signal mask
    stack_t uc_stack;         	//
    mcontext_t uc_mcontext; 	//stores the registers values in it, used by the system
};

 typedef struct {
               void  *ss_sp;     //ponteiro para o endereço de memória
               int    ss_flags;  //
               size_t ss_size;   //tamanho inteiro de memória alocada no ptr ss_sp. Ambos devem possuir mesmo valor
           } stack_t;
           
*Funções principais
int getcontext(ucontext_t *ucp); 
This function gets the context of the currently executing context. It returns 0 on success and -1 on failure.

int setcontext(const ucontext_t *ucp);
This is used to set the context of the calling process to the context pointed to by ucp. 

void makecontext(ucontext_t *ucp, void (*func)(), int argc, ...);
Every context should have a function to execute. Attaching a function to a context can be done by using this function call.
The arguments are the pointer to the context to which you want to attach a function, the pointer to the function, the third argument is the number of arguments you want to pass to the function.


int swapcontext(ucontext_t *restrict oucp, const ucontext_t *restrict ucp);
When the above function is called it stores the current context into ucp and transfers the control to the context pointed to by ucp. Thus, it avoids the overhead of calling two functions.



Leitura feita até o fim do primeiro código. <http://nitish712.blogspot.com/2012/10/thread-library-using-context-switching.html>

*/

