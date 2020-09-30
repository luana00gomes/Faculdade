#include "thread.h"

__BEGIN_API


int Thread::switch_context(Thread * prev, Thread * next){
	if(prev && next){
	_running = next;
	CPU::switch_context(prev->_context, next->_context);
	return 1;
	} 
	else return 0;
}
//Cuidar com ordem e significado

void Thread::thread_exit (int exit_code){
	db<Thread>(TRC) << "Thread::thread_exit(): tarefa " << this->id() << " sendo encerrada\n";
	
	delete _context;
//	delete _running;
}

int Thread::id(){
	return _id;
}


__END_API

