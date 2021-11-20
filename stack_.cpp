/*
 * stack_.cpp
 *
 *  Created on: Apr 20, 2020
 *      Author: student
 */

#include "stack_.h"


stack_:: stack_()
{
	top=-1;
}

stack_:: ~stack_()
{



	//delete [] items;

}

bool stack_:: isEMPTY()   //true if empty
{
	if(top == -1)
		return true;
	else
		return false;

}

bool stack_:: push(int item)               //true if push done
{
	if (top >= MAX_SIZE-1)
		{
			return false;
		}
		else
		{
			top++;
			items[top] = item;
			return true;
		}


}

bool stack_:: pop(int& item)
{
		if (isEMPTY())
			return false;
		else {
			item = items[top];
			top--;
		}
}

void stack_:: print()
{

		for (int i = 0; i <= top; i++)
		{
			cout << items[i] ;
		}

		//cout << endl;

}

void stack_:: print_rev()
{

		for (int i = top; i >= 0; i--)
		{
			cout << items[i] ;
		}

		//cout << endl;

}


int stack_:: GETtop()
{
	int item;

	item = items[top];

	return item;
}




















