/*
 * stack_.h
 *
 *  Created on: Apr 20, 2020
 *      Author: student
 */

#ifndef STACK__H_
#define STACK__H_

#ifndef STACK_H_
#define STACK_H_

#include <iostream>

using namespace std;
const int MAX_SIZE =50;

//typedef int stackElemType;
class stack_ {
public:
	stack_();

	bool isEMPTY();
	bool push(int item);
	bool pop(int& item);
	void print();
	void print_rev();
	int  GETtop();

    ~stack_();


private:
    int top;
	int items[MAX_SIZE];


};


#endif



#endif /* STACK__H_ */
