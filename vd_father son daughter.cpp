#include <iostream>
using namespace std;

class Father {
	public:
		virtual int area() {
			cout << "This is Father!" << endl;
		}
};

class Son: public Father {
	public:
		int area() {
			cout << "This is Son!" << endl;
		}
};

class Daughter: public Father {
	public:
		int area() {
			cout << "This is Daughter!" << endl;
		}
};

int main() {
	Father *fa;
	Son s;
	Daughter d;
	fa = &s;	fa->area();
	fa = &d;	fa->area();
	
}