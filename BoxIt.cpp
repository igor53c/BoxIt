#include<iostream>

using namespace std;
//Implement the class Box  
class Box {
	//l,b,h are integers representing the dimensions of the box
private:
	int l;
	int b;
	int h;
	// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);
public:
	Box() {
		l = 0;
		b = 0;
		h = 0;
	}
	Box(int a1, int a2, int a3) {
		l = a1;
		b = a2;
		h = a3;
	}
	Box(Box& box) {
		l = box.getLength();
		b = box.getBreadth();
		h = box.getHeight();
	}
	// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box
	int getLength() {
		return l;
	}
	int getBreadth() {
		return b;
	}
	int getHeight() {
		return h;
	}
	long long CalculateVolume() {
		long long retValue = (long long)l * (long long)b *
			(long long)h;

		return retValue;
	}
	//Overload operator < as specified
//bool operator<(Box& b)
	bool operator<(Box& b) {
		if (getLength() < b.getLength())
			return true;
		if (getLength() == b.getLength() && getBreadth() < b.getBreadth())
			return true;
		if (getLength() == b.getLength() && getBreadth() == b.getBreadth() && 
			getHeight() < b.getHeight())
			return true;

		return false;
	}

	//Overload operator << as specified
	//ostream& operator<<(ostream& out, Box& B)
	friend auto operator<<(std::ostream& os, Box const& m) -> std::ostream& {
		return os << m.l << " " << m.b << " " << m.h;
	}
};


void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	check2();
}