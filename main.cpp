#include "stack_.h"
#include<string>
#include<string.h>

static stack_ temps,op1d,op2d,resd,op1f,op2f,resf ;

bool valid_input(string s , int& op_pos, char& op);
bool get_point(string s,int& f1, int& f2, int& point1, int& point2, int op_pos);
void fill_stack(string s,int f1, int f2, int point1, int point2, int op_pos );
int add_zeros_in_fraction(int f1, int f2, int point1, int point2, int op_pos, int l);


int main(int argc , char ** argv)
{
	string s= argv[1];  int l=s.length();

	int op_pos=0; char op;
	bool design_flag=valid_input( s, op_pos, op );
	if(design_flag == 0)
		return 0;

	int f1=0,f2=0;    //if f1,f2==0   integer  else  float
	int point1=op_pos;
	int point2=l;
	bool point_flag=get_point(s,f1,f2, point1,point2 ,op_pos  );
	if(point_flag == 0)
		return 0;

	fill_stack( s, f1,  f2,  point1,  point2,  op_pos );
	int fraction_dig=add_zeros_in_fraction( f1,  f2,  point1,  point2,  op_pos, l);

	//////////////
	switch(op)
	{
		case '+':
		{
			int carry=0;
			int num1, num2,temp2,temp,car,car1=5,car2=5;
			bool j,k,o;
			/////////float sum
			if(f1==1 || f2==1)
			{
			for(int i=0; i<fraction_dig ;i++)
			{
				//cout<<"mo ";
				j=op1f.pop(num1);
				k=op2f.pop(num2);
				temp=num1+num2+carry;
				temp2=temp-10;
				if(temp2<0)
				{

					o=resf.push(temp);
					carry=0;
				}
				else
				{

					o=resf.push(temp2);
					carry=1;
				}

			}

			}


			//resf.print();

			while(  (!op2d.isEMPTY()) && ( !op1d.isEMPTY() )  )
			{
				j=op1d.pop(num1);
				k=op2d.pop(num2);

				temp=num1+num2+carry;
				temp2=temp-10;
				if(temp2<0)
				{

					o=resd.push(temp);
					carry=0;
				}
				else
				{

					o=resd.push(temp2);
					carry=1;
				}


			}
		/*	if(carry==1)
			{
				o=resd.push(carry);

			}*/

			car=carry;

			while(  !op2d.isEMPTY())
			{
				car1=0;
				k=op2d.pop(num2);
				temp=num2+carry;
				temp2=temp-10;
				if(temp2<0)
				{

					o=resd.push(temp);
					carry=0;
				}
				else
				{

					o=resd.push(temp2);
					carry=1;
				}


			}

			/*if(carry==1)
			{
				o=resd.push(carry);

			}*/

			while(  !op1d.isEMPTY())
			{
				car2=0;
				k=op1d.pop(num1);
				temp=num1+car;
				temp2=temp-10;
				if(temp2<0)
				{

					o=resd.push(temp);
					car=0;
				}
				else
				{

					o=resd.push(temp2);
					car=1;
				}


			}

			if( car1!=0 && car2!=0 )
			{
				if(carry==1)
				{
				o=resd.push(carry);

				}

			}
			else if(car1==0 && car2!=0)
			{
				if(carry==1)
				{
				o=resd.push(carry);

				}

			}
			else if(car1!=0 && car2==0 )
			{
				if(car==1)
				{
				o=resd.push(car);

				}

			}





			/*if(car==1)
			{
				o=resd.push(carry);

			}*/

			int sum=0;
			while(! resd.isEMPTY() )
			{
				int nu;
				bool k,f;
				f=resd.pop(nu);
				o=temps.push(nu);
				sum+=nu;
			}

			//cout<<"Result= ";
			if(sum==0)
			{
				int y=0;
			//	bool o=temps.push(y);
				if(f1==0 && f2==0 )
				{
					cout<<'0';

				}
				else
				{
					cout<<"0.";  resf.print_rev();
				}


			}
			else
			{
				if(f1==0 && f2==0 )
				{
					//cout<<'0';
					temps.print();
				}
				else
				{
					temps.print(); cout<<'.';  resf.print_rev();
				}




			}




			cout<<endl;














		break;
		}
		case '-':
		{

			int carry=0;
			int num1, num2, temp;
			bool j,k,o;
			/////////float sub
			if(f1==1 || f2==1)
			{
			for(int i=0; i<fraction_dig ;i++)
			{
				//cout<<"mo ";
				j=op1f.pop(num1);
				k=op2f.pop(num2);

				if(num1> num2)
				{

					temp=num1-num2-carry;
					o=resf.push(temp);
					carry=0;
				}
				else if(num1== num2)
				{
					if(carry==1)
					{
					temp=num1-num2+10-carry;
					o=resf.push(temp);
					carry=1;
					}
					else
					{
						temp=num1-num2-carry;
						o=resf.push(temp);
						carry=0;

					}

				}
				else
				{

					temp=num1+10-num2-carry;
					o=resf.push(temp);
					carry=1;
				}

			}
			}
			//resf.print();
			while(! op2d.isEMPTY() )
			{
				j=op1d.pop(num1);
				k=op2d.pop(num2);
				if(num1> num2)
				{

					temp=num1-num2-carry;
					o=resd.push(temp);
					carry=0;
				}
				else if(num1== num2)
				{
					if(carry==1)
					{
						temp=num1-num2+10-carry;
						o=resd.push(temp);
						carry=1;
					}
					else
					{
						temp=num1-num2-carry;
						o=resd.push(temp);
						carry=0;

					}

				}
				else
				{

					temp=num1+10-num2-carry;
					o=resd.push(temp);
					carry=1;
				}

			}

			while(! op1d.isEMPTY() )
			{
				j=op1d.pop(num1);
				if(carry==1)
				{
					if(num1 != 0)
					{
					temp=num1-carry;
					o=resd.push(temp);
					carry=0;
					}
					else
					{
						temp=num1+10-carry;
						o=resd.push(temp);
						carry=1;
					}


				}
				else
				{
					o=resd.push(num1);

				}


			}


			int c=0;
			for(int i=0; c==0; i++)
			{
				int m,n; bool f;
				n=resd.GETtop();
			    if(n==0)
				{
					f=resd.pop(m);

				}
				else
					c=1;
			}



			int sum=0;
			while(! resd.isEMPTY() )
			{
				int nu;
				bool k,f;
				f=resd.pop(nu);
				o=temps.push(nu);
				sum+=nu;
			}


			//cout<<"Result= ";
			if(sum==0)
			{
				int y=0;
			//	bool o=temps.push(y);
				if(f1==0 && f2==0 )
				{
					cout<<'0';

				}
				else
				{
					cout<<"0.";  resf.print_rev();
				}


			}
			else
			{
				if(f1==0 && f2==0 )
				{
					//cout<<'0';
					temps.print();
				}
				else
				{
					temps.print(); cout<<'.';  resf.print_rev();
				}




			}

			cout<<endl;


		break;
		}
		default:
		{
			cout<<"Invalid input";
			break;
		}

	}














return 0;
}


bool valid_input(string s , int& op_pos, char& op)
{
	int l=s.length();  bool m=true;
	int flag1=0;  int flag2=0;
	///  only num and . + - valid
	for(int i=0; i< l ;i++)
	{
		if(! ((s[i]>='0' && s[i]<='9') || (s[i]=='.' )   || s[i]=='+' || s[i]=='-' ))
		{
			cout<<"Invalid input"<<endl;
			return 0;
		}

	}
	///  only one + or - valid
	for(int i=0; i< l;i++)
	{
		if (flag1== 2)
		{
			cout<<"Invalid input"<<endl;
			return 0;
		}
		if( s[i]=='+' || s[i]=='-' )
		{
			flag1++;
		}
	}
	///// get the + or - position
	for(int i=0; i< l;i++)
	{
		if( s[i]=='+' || s[i]=='-' )
		{
			op_pos=i;
			op=s[i];
		}

	}
	//////// only one . in first num valid
	for(int i=0; i< op_pos;i++)
	{
		if (flag2== 2)
		{
			cout<<"Invalid input"<<endl;
			return 0;
		}
		if( s[i]=='.'  )
			flag2++;

	}
	///////// only one . in second num valid
	flag2=0;
	for(int i=op_pos+1 ; i< l;i++)
	{
		if (flag2== 2)
		{
			cout<<"Invalid input"<<endl;
			return 0;
		}
		if( s[i]=='.'  )
			flag2++;

	}


return m;
}
///////////////////////////////////////////////////////////////////////////////////
bool get_point(string s,int& f1, int& f2, int& point1, int& point2 , int op_pos)
{
	bool m =true;
	int l=s.length();
	for(int i=0; i< op_pos;i++)
	{
		if( s[i]=='.'  )
		{
			f1=1;
			point1=i;
			break;
		}

	}
	for(int i=op_pos+1; i< l;i++)
	{
		if( s[i]=='.'  )
		{
			f2=1;
			point2=i;
			break;
		}

	}

	if( point1==0 || op_pos-point1 ==1 || point2-op_pos ==1 || point2==l-1 )
	{
		cout<<"Invalid input"<<endl;
		return 0;

	}




return m;
}
////////////////////////////////////////////////////////////////////////////////////
void fill_stack(string s,int f1, int f2, int point1, int point2, int op_pos )
{
	int l=s.length();
	/// fill the int part of 1st num
	bool net=false;
	for(int i=0 ; i<point1  ;i++)
	{
		if(net==false)
		{
			if(s[i]== '0')
			{
				continue;
			}
			else
				net=true;
		}

		bool f;

		f=op1d.push( s[i]-48 );
		if(! f)
		{
			i--;
		}

	}
	if(net==false)
	{
		int u=0;
		bool f=op1d.push(u);
	}
	/// chect to fill fraction part of 1st num
	if(f1==1)
	{
		for(int i=point1+1 ; i<op_pos  ;i++)
		{
			bool f;
			f=op1f.push( s[i]-48 );
			if(! f)
			{
				i--;
			}

		}
	}
	else
	{
		bool f;  int y=0;
		f=op1f.push( y );
		if(! f)
		{
			f=op1f.push( y );
		}

	}
	////////////fill int of 2nd num
	bool net2=0;
	for(int i=op_pos+1 ; i<point2  ;i++)
	{
		if(net2==0)
		{
			if(s[i]=='0')
			{
				continue;
			}
			else
				net2=1;
		}


		bool f;
		f=op2d.push( s[i]-48 );
		if(! f)
		{
			i--;
		}

	}
	if(net2==false)
	{
		int u=0;
		bool f=op2d.push(u);
	}

	/////// check if fraction exists in num 2 and fill it
	if(f2==1)
	{
		for(int i=point2+1 ; i<l  ;i++)
		{
			bool f;
			f=op2f.push( s[i]-48 );
			if(! f)
			{
				i--;
			}

		}
	}
	else
	{
		bool f;  int y=0;
		f=op2f.push( y );
		if(! f)
		{
			f=op2f.push( y );
		}

	}

}
/////////////////////////////////////////////////////////////////////////////////////////

int add_zeros_in_fraction(int f1, int f2, int point1, int point2, int op_pos, int l)
{
		int m;   int n;   //m->f2   n->f1
	int x;     int fl_dig;
	if(f1==1 &&f2==1)
	{

		m= l-1-point2;
		n=op_pos-1-point1 ;
	}
	else if(f1==0 &&f2==1)
	{
		m= l-1-point2;
		n=1;
	}
	else if(f1==1 &&f2==0)
	{
		m=1;
		n=op_pos-1-point1 ;
	}
	else if(f1==0 &&f2==0)
	{
		m=0;
		n=0;
	}
	if(m > n)
	{
		fl_dig=m;
		  x=m-n;
		for(int i=1; i<=x ;i++)
		{
			int y=0;
			op1f.push(y);
		}

	}
	else if(m < n)
	{
		fl_dig=n;
		 x=n-m;
		for(int i=1; i<=x ;i++)
		{
			int y=0;
			op2f.push(y);
		}

	}
	else
	{
		fl_dig=n;
	}


return fl_dig;
}

/////////////////////////////////////////////////////////////////////////////////////


