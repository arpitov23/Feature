// unique_ptr_internal_implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template <typename T>
class uniqueptr_impl
{
private:
    T* res;  // it will same size as pointer size.

public:
    uniqueptr_impl(T* a = nullptr) : res(a)
    {
        cout <<"constructor called" << endl;
    }

    // copy constructor - we have to give compiler error if we try to copy the unique pointer. -  uniqueptr_impl<int> ptr2(ptr1); 

    uniqueptr_impl(const uniqueptr_impl<T>& ptr) = delete; // delete keyword is used to give compiler error if we try to copy the unique pointer. Compiler will not write anything for copy constructor.
    
    // copy assignment operator - we have to give compiler error if we try to copy the unique pointer. - uniqueptr_impl<int> ptr3 = ptr1; ptr4 = ptr3;

    uniqueptr_impl<T>& operator=(const uniqueptr_impl<T>& ptr) = delete; // delete keyword is used to give compiler error if we try to copy the unique pointer. Compiler will not write anything for copy assignment operator.

    // move copy constructor -     uniqueptr_impl<int> ptr3 = std::move(ptr1); // move copy constructor is called here.

    uniqueptr_impl(uniqueptr_impl<T>&& ptr)
    {
        cout << "move copy constructor called" << endl;
		res = ptr.res; // res is pointing to ptr.res - ownership is transferred to ptr.res. ptr1 res move to ptr
		ptr.res = nullptr; // ptr.res is pointing to nullptr - ownership is transferred to ptr.res. ptr1 res move to ptr
    }

    // move assignment operator - ptr4 = std::move(ptr3); // move assignment operator is called here.

    uniqueptr_impl& operator=(uniqueptr_impl<T>&& ptr)
    {
        cout << "move assignment operator called" << endl;

        if (this != &ptr) // check if both are not same - ptr4 = ptr4
        {
            if (res)
            {
				delete res; // if res is pointing to some memory then delete it.
			}
			res = ptr.res; // res is pointing to ptr.res - ownership is transferred to ptr.res. ptr1 res move to ptr
			ptr.res = nullptr; // ptr.res is pointing to nullptr - ownership is transferred to ptr.res. ptr1 res move to ptr
		}
		return *this;
	}
			
    // -> operator overloading - if you have some user-defined class then call an function of class

    T* operator->() // when you put an -> it will actually return a raw pointer itself - so that you can call a function of class.
    {
		return res; // return the pointer.
	}
   
    T& operator* () // * operator - means we have to provide a value which is pointed by that operator
    {
        return *res;
    }

    T* get()
    {
        return res;
    }

    void reset(T* ptr = nullptr)
    {
        if (res)
        {
            delete res;
        }
        res = ptr;
    }

    // destructor

    ~uniqueptr_impl()
    {
        cout <<"destructor called" << endl;
        if (res)
        {
			delete res;
            res = nullptr;
		}
	}

};

int main()
{
    std::cout << "\n------------- Internal Implementation of unique_ptr! -------------\n\n";
    uniqueptr_impl<int> ptr1(new int(2));

    // below two line will give compile error because we have deleted copy constructor 
    
   // uniqueptr_impl<int> ptr2(ptr1); // compile error - here we are assigning ptr1 to ptr2, unique means to say it's an exclusive ownership but here ownership comes to 2 pointer ptr2 and ptr1, so it's not unique anymore.
   // uniqueptr_impl<int> ptr3 = ptr1; // compile error - same as above - copy constructor is called here.

    uniqueptr_impl<int> ptr4(new int(100));

    // below line will give compile error because we have deleted copy assignment operator

   // ptr4 = ptr3; // compile error - same as above - assignment operator is called here.
    uniqueptr_impl<int> ptr3 = std::move(ptr1); // move copy constructor is called here.
    ptr4 = std::move(ptr3); // move assignment operator is called here.

   // ptr1->func(); // if you have some user-defined class then call an function of class  - Then to implement this we need to overload -> operator.
    
    // below line will give an runtime error because we have moved the ownership of ptr1 to ptr3 (in line no 108)
    cout << *(ptr4) << endl; //  implement this we need to overload * operator.



    ptr1.get(); // implement this we need to  get() function.
    ptr1.reset(new int(30)); 

    // destructor 

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
