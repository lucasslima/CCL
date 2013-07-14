/*
 * CCL.h
 *
 *  Created on: 29/05/2013
 *      Author: lucas
 */

#ifndef CCL_H_
#define CCL_H_

#include <pthread.h>
#include "ticket.hpp"
#include <map>

using std::map;

class CCL {
public:
	CCL();
	template<class F> void execute(F&) ;
	template<class F,class A> Ticket execute(F&,A&) ;
	template<class F> friend void * call (void * context);
	template<class F> friend void * call_void (void * context);
	void Register();
	void global_join();
	virtual ~CCL();
private:
	void ** user_function;
	void ** function_arguments;
	pthread_t * ccl_thread;
	map <Ticket, void**> results;
	int available_threads;
	unsigned current_thread; 	//Controle do thread atual
	unsigned function_counter;
};

class Carrier{
public:
	CCL * context;
	int function_pos;
};


#include "CCLFacade.cpp"
#endif /* CCL_H_ */
