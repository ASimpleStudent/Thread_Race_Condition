//============================================================================
// Name        : AAAdeleteme.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

//starting balance
int bal =0;

void withdraw(int amt){

	//when you see delays like this in the code with comments like
	//"wait for deposit to occur first" or "wait for system stabalization"
	//be very suspicious of the code quality since this often means the
	//original developer has no idea how to coordinate thread activities
	//hint (use condition variables- coming soon)
	this_thread::sleep_for(chrono::milliseconds(500));

	if (bal>amt){
		cout<<"approved!"<<endl;
		bal -=amt;
	}
	else
		cout<<"denied!";

	//longrunning local calculation
}
void deposit(int amt){
	//simulated work
//	this_thread::sleep_for(chrono::milliseconds(100));
	bal +=amt;
	cout<<"deposit made!";
}
int main() {

	//which one of these 3 threads start first? (YOU CANNOT TELL! NEVER ASSUMME!)
	thread t1(withdraw, 40);
	thread t2(withdraw, 25);
	thread t3(deposit, 100);

	//does it matter which order you join threads? NO, as long as you join them all
	t1.join();
	t2.join();
	t3.join();

	return 0;
}
