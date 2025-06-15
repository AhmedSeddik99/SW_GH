______________________________________________________________ 
____________________________ Lab1 ____________________________ 
______________________________________________________________

1- SWAP : 3 Version (pass by value, pass by address,  pass by ref)


2- Complex Struct/Class:

	- member data: real , img
	- member functions: setters & getters
	- Standalone functions:
		Complex Add(Complex C1, Complex C2);  
		Complex Subtract(Complex C1, Complex C2);  
		void print(Complex C);   // C = 5+3i

	- try to re-write Add function to be member function:
		Complex Add(Complex C);  

	- try to write any member function outside class using scope resolution ::
 
	
3- Check different cases of print:

	real = 5, img = 3  // C1 = 5+3i

	real = 5, img = -3  // C1 = 5 + -3i   ==> C1 = 5-3i

	real = 5, img = 0  // C1 = 5 + 0i   ==> C1 = 5

	real = 0, img = 3  // C1 = 0 + 3i   ==> C1 = 3i

	real = 0, img = 0  // C1 = 0 + 0i   ==> C1 = 0

----------------------------------------------------------------------------------------------------------------------------------------------------



______________________________________________________________ 
____________________________ Lab2 ____________________________ 
______________________________________________________________

1- class complex:
=================
	- member variables(real, img)
	- constructors(default, parameterized)
	- setters & getters
	- member functions: "Addcomplex, subComplex, PrintComplex"  (use scope operator "::")
	- destructor

try this main, count No of constructors vs No of destructors:

void main()
{
	Complex C1(3,4), C2(5), C3;
	C3 = C1.Addcopmlex(C2);
}


2- Function Overloading:
========================
class myTestClass
{
	// Function Add: Add 2 integer numbers:  int Add(int, int)
	// Function Add: Add 3 integer numbers:  int Add(int, int, int)
    // Function Add: Add 3 characters  // concatenate them: void Add(char c1, char c2, char c3)
	// Function Add: Add 2 Strings  // concatenate them: void Add(char* str1, char* str2)
}


3- Stack (LIFO):
================

Class Stack
{
	int[] Stk, Tos, Size;

	int Peak()
	{ ... }

	Stack Reverse() 				//return new stack "with reversed internal array of original stack"
	{ ... }

	void PrintStack()
	{ ... }
}

main()
{
	Stack S1(5);
	
	S1.Push(10);
	S1.Push(20);
	S1.Push(30);

	cout<< S1.Peak(); //30
	cout<< S1.Peak(); //30

	cout<< S1.Pop(); //30
	cout<< S1.Pop(); //20

	Stack S2(5);
	
	S2.Push(3);
	S2.Push(4);
	S2.Push(5);
	S2.Push(6);

	cout << S2.Reverse().Pop(); 	
}


4- Queue (FIFO): (2 Options "Circular & Shifting")
================  
	- int* Q, Head, Tail 
	- constructors (Parameterless & Parameterized)
	- destructor	
	- IsFull()
	- IsEmpty()
	- int DeQueue() 
	- void EnQueue(int)  

----------------------------------------------------------------------------------------------------------------------------------------------------



______________________________________________________________ 
____________________________ Lab3 ____________________________ 
______________________________________________________________


1- Complex Class:
	- constructors (Parameterless & Parameterized) //Complex C1(2,3), C2(4), C3;
	- destructor

	- use "this"
	- use "::" scope operator
	- Copy Constructor
	- call member function "Add" (with Cpy Ctor/ without Cpy Ctor) 
	
	- trace each approach to see no objects created or destructed each time  

	main()
	{
		Complex C1(3,4), C2(5), C3;
    		C3 = C1.Add(C2);
	}


2- Stack Class (Dynamically Allocated) "LIFO":
	- int* Stk, Tos, Size 
	- constructors (Parameterless & Parameterized)
	- destructor	
	- IsFull() , IsEmpty()
	- int Pop()
	- void Push(int)

	- use "this"
	- Copy Constructor
	- void viewContent(Stack S); //Friend function
	- Stack Reverse() //Member function
		
	- trace each approach to see number of objects created or destructed each time 
 			
	main()
	{
///************* Copy Ctor Case(1): Pass by value to function ********************
/*
    Stack S1;

    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);

    viewContent(S1);

    cout<<"Num = "<<S1.pop()<<endl;
    cout<<"Num = "<<S1.pop()<<endl;
*/

///************* Copy Ctor Case(2): Return by value from function ********************
/*
    Stack S1;

    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);

    //Stack SS = S1.Reverse();
    //cout<SS.pop();

    cout<<S1.Reverse().pop();
*/
///************* Copy Ctor Case(3): Create obj in terms of another obj "Explicitly" ********************
/*
    Stack S1;

    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);

    Stack S3 ( S1 );

    for(int i=0; i<10; i++)
    S3.pop();


    for(int i=0; i<10; i++)
        S3.push(-1);

    cout<<"Num = "<<S1.pop()<<endl;
    cout<<"Num = "<<S1.pop()<<endl;

*/
	}

----------------------------------------------------------------------------------------------------------------------------------------------------



______________________________________________________________ 
____________________________ Lab4 ____________________________ 
______________________________________________________________

1- Implement Function Sum with "Default Arguments"

int SUM ( int x, int y, int z);  //try it with all possible default valuesW


2- Overload the following Operators for Complex and Stack classes:

class Complex
==============
C3 = C1 - C2;

C3 = 7 - C2;

C3 = C2 - 7;

C1-=C2;

C2=--C1;

C2 = C1--; 

C1 == C2

C1 != C2

C1 > C2,  C1 >= C2,

C1 < C2, C1 <= C2,  

(int) C1

cout<< C1['R']


Class Stack:
============
static int counter  
static int getCounter()



operator= //S1 = S2;

operator+ //S3 = S1 + S2; //Append 

// cout<< S1[i];
// S1[i] = X; 


3- Class date:
	Write "date class":
		- Constructors
		- printDate()  // Day/Moth/Year

	
	apply operator overloading for:
	
	int operator-(date);			//diff = d2 - d3;
	date operator+(int);			//d1 = d2 + 10;
	date operator++(); //Prefix		//d1= ++d2;
	date operator++(int); //Postfix		//d1= d2++;
	void operator=(date); 		 	//d1 = d2;

	bool operator==(date);			//if(d1==d2);

	operator int(); //casting operator	//int x= (int)d1;
	// Note: No return type for the casting operator,
	// because it automatically returns the type you are casting to.

	int operator [] (char ch);		//int day=d1['d'];  //int month=d1['m'];  //int year=d1['y'];


4- re-write The same "Complex class" from previous assignment, with applying operator overloading for:
	
	operator<<    //cout << c1;

	operator>>    //cin >> c1;

----------------------------------------------------------------------------------------------------------------------------------------------------



______________________________________________________________ 
____________________________ Lab5 ____________________________ 
______________________________________________________________

1- Apply Templates on Swap Function , Stack Class

void main()
{
    int a=3, b = 5;
    Swap<int>(a,b);
    cout<<"\nAfter Swap: "<<a<<", "<<b<<endl;

    char Ch1='Z', Ch2='O';
    Swap<char>(Ch1, Ch2);
    cout<<"\nAfter Swap: "<<Ch1<<", "<<Ch2<<endl;

    Complex C1(5), C2(2,7);
    Swap<Complex>(C1, C2);
	
    cout<<"\nComplex1 After Swap: "<<endl;
    C1.Print();
    cout<<"\nComplex2 After Swap: "<<endl;
    C2.Print();

    Stack<int> S;
    S.push(10);
    S.push(20);
    cout<< S.pop();    

    Stack<char> S2(3);
    S2.push('A');
    S2.push('B');
    S2.push('C');
    cout<< S2.pop();    
    
    Stack<Complex> S3(4);
    S3.push(C1);
    S3.push(C2);
    Complex C = S3.pop();
    C.Print();
}

2- Base/Drived classes:

class Parent
	- private members x
	- protected member y
	- constructors & destructor
	- setters & getters
	- function sum (return summation of x and y)

class Child
	- private members z
	- constructors & destructor
	- setters & getters
	- override function sum in Child to add functionality to the Parent sum function:
	(return summation of x and y and z)
	
class GrandChild
	- private members m
	- constructors & destructor
	- setters & getters
	- override function sum in GrandChild to add functionality to the Child sum function:
	(return summation of x and y and z and m)

3- Class Shape:

class Shape
	- private members dim1, dim2
	- constructors & destructor
	- setters & getters
	- function CalcArea(return 0)	

	- then we have to create 4 derived classes (Rectangle, Square, Circle, Triangle) 
	  in which they inherit from Shape base class.
	- override function CalcArea in these derived classes to calculate area according to each shape

----------------------------------------------------------------------------------------------------------------------------------------------------



______________________________________________________________ 
____________________________ Lab6 ____________________________ 
______________________________________________________________

1- in "Shape" example, do changes required to overcome "Square & Circle Problems of setting different dim values":
	- try "protected inheritance", 

2- Composition/Aggregation Example: Point, Rect, Circle, Line + drawing graphics.
	- each class should have: attributes, constructors, setters & getters, Draw()

----------------------------------------------------------------------------------------------------------------------------------------------------



______________________________________________________________ 
____________________________ Lab7 ____________________________ 
______________________________________________________________

1-
- Composition Example: Point, Rect, Circle, Line + drawing graphics.
	- each class should have: attributes, constructors, setters, Draw()
 
- Aggregation Example: Picture, Point, Rect, Circle, Line + graphics.
	- class Picture should have: attributes, constructors, setters, Paint()
	- set color in (Rect, Circle, Line) before drawing.

2- Late binding --> "Base-Drived-Derived_2" example (Multi-Level inheritance), try the following:
	- create pointer from base points to object from drived "call drived function using base pointer"
	- use "virtual" keyword, then try again to see what is the difference

3- in "Shape" example, do changes required to:
	- prevent anyone from creating object of shape class "make it abstract, 
	- try using "pure virtual function: CalcArea()"

----------------------------------------------------------------------------------------------------------------------------------------------------



______________________________________________________________ 
____________________________ Lab8 ____________________________ 
______________________________________________________________

1- in "GeoShape" example, do changes required to:
	- prevent anyone from creating object of shape class "make it abstract, using pure virtual function"
	- make another function called "sumOfAllShapesArea", that takes Array of 4 shapes and return sum of these shapes areas.



2- Continue the Picture Example:
      - Write new class Shape with variable color + setters and getters.. Rect, Circle, and Line to Inherit from it.
      - in class Shape Make function "Draw( )", a pure virtual function, then make necessary changes to other classes.
      - Simplify the Picture class, so as to only be constructed by an array of Shapes (array of pointers to Shape), 
	then use the pointer of base class to call the Draw( ) function of Circle, Rect, and Line.



3- Try to navigate through "String" built-in class and try some of its functions

----------------------------------------------------------------------------------------------------------------------------------------------------