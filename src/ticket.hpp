/*
 * ticket.hpp
 *
 *  Created on: 02/07/2013
 *      Author: hpc
 */

#ifndef TICKET_HPP_
#define TICKET_HPP_
#include <string>

using std::string;


class Ticket{
public:
	~Ticket();
	Ticket();
	Ticket(string);
	Ticket(char*);
	const string getID() const;
	bool setId(string);
	friend class CCL;
	friend class Ticket_compare;
private:
	string ID;
};
class Ticket_compare{
public:
  bool operator() (Ticket t1,Ticket t2){
    int t = t1.ID.compare(t2.ID);
    if (t > 0)
      return true;
    else
      return false;
  }
};

const string Ticket::getID() const{
  return ID;
}
Ticket::Ticket(){
	ID.clear();
}

Ticket::Ticket(string id){
	ID = id;
}
Ticket::Ticket(char * id){
	if (!id)
		ID.clear();
	else
		ID = id;
}
Ticket::~Ticket(){
	ID.clear();
}
#endif /* TICKET_HPP_ */
