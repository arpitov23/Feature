// String_class_imp_without_lib_fun.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>

using namespace std;

class MyString_class
{
private : 
	char* str;
	int len;
public:
	//Helper function to calculate the length of string
	int calc_len(const char* s)
	{
		int i_length = 0;
		while (s[i_length] != '\0')
		{
			i_length++;
		}
		return i_length;
	}
	// Helper function to copy the string
	void copy_string(char *destination , const char* source)
	{
		int len = 0;
		while (source[len] != '\0')
		{
			destination[len] = source[len];
			len++;
		}
		destination[len] = '\0';
		
	}

	//Helper function to concatenate the string

	void concatenate_string(char* dest, const char* src)
	{
		int len = 0;
		while (dest[len] != '\0')
		{
			len++;
		}
		int len_j = 0;
		while (src[len_j] != '\0')
		{
			dest[len] = src[len_j];
			len++;
			len_j++;
		}
		dest[len] = '\0';
	}

	
		//default constructor
		MyString_class()
		{
			str = NULL;
			len = 0;
		}
		//parameterized constructor
		MyString_class(const char* s)
		{
			if (s == nullptr)
			{
				str = new char[1];
				str[0] = '\0';
				len = 0;
			}
			else {
				len = calc_len(s);
				str = new char[len + 1];
				concatenate_string(str, s);
			}
		}
		//copy constructor
		MyString_class(const MyString_class& source)
		{
			len = source.len;
			str = new char[len + 1];
			copy_string(str, source.str);
		}

		//Move constructor
		MyString_class(MyString_class&& source)
		{
			len = source.len;
			str = source.str;
			source.len = 0;
			source.str = nullptr;

		}
		// Assignment operator
		MyString_class& operator=(const MyString_class& source)
		{
			if (this == &source)
			{
				return *this;
			}
			delete[] str;
			len = source.len;
			str = new char[len + 1];
			copy_string(str, source.str);
			return *this;
		}

		//Move assignment operator
		MyString_class& operator=(MyString_class&& source)
		{
			if (this == &source)
			{
				return *this;
			}
			delete[] str;
			len = source.len;
			str = source.str;
			source.len = 0;
			source.str = nullptr;
			return *this;
		}

		// destructor
		~MyString_class()
		{
			delete[] str;
		}

		// display function
		void display() 
		{
			std::cout << str << endl;
		}

		// length function
		int length()
		{
			return len;
		}

		//append function 
		MyString_class& append(const MyString_class& source)
		{
			char* tmo = new char[len + source.len + 1];
			copy_string(tmo, str);

			concatenate_string(tmo, source.str);
			delete[] str;
			str = tmo;
			len = len + source.len;
			return *this;

		}

		// push_back function 
		void push_back(char ch)
		{
			char* tmo = new char[len + 2];
			copy_string(tmo, str);
			tmo[len] = ch;
			tmo[len + 1] = '\0';
			delete[] str;
			str = tmo;
			len++;
		}
		
		// pop_back function
		void pop_back()
		{
			if (len == 0)
			{
				return;
			}
			char* tmo = new char[len];
			for (int i = 0; i < len - 1; i++)
			{
				tmo[i] = str[i];
			}
			tmo[len - 1] = '\0';
			delete[] str;
			str = tmo;
			len--;
		}

		// swap function 
		void swap_string(MyString_class& source)
		{
					char* tmo = str;
					str = source.str;
					source.str = tmo;

					int tmo_len = len;
					len = source.len;
					source.len = tmo_len;
		}
		//operator overloading
		MyString_class& operator+(const MyString_class& source)
		{
			return append(source);
		}

		//assignment operator overloading
		MyString_class& operator+=(const MyString_class& source)
		{
			return append(source);
		}
		
};

int main()
{
	MyString_class str1;
	MyString_class str2 = "Arpit";
	MyString_class str3 = str2;
	MyString_class obj;
	int len = obj.calc_len("arpitsharma");
	std::cout << len << endl;
	MyString_class str4{ std::move(str2) };
	str4.display();
	cout << "====="<<endl;
	str4.push_back('!');
	str4.display();
    std::cout << "Hello World!\n";
	str3.pop_back();
	str3.display();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
