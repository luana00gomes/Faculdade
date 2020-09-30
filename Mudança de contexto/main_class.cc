#include "main_class.h"

__BEGIN_API

//Cria objetos da classe contexto, que será usado na classe main, e seta valor nulo.
CPU::Context *Main::ContextMain = 0;  
CPU::Context *Main::ping = 0;
CPU::Context *Main::pong = 0;

//strings de nomes
std::string Main::ping_name;
std::string Main::pong_name;

__END_API
