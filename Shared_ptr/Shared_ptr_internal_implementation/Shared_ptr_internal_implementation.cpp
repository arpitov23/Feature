// Shared_ptr_internal_implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
 
template <typename T>
class sharedptr
{
private:
    T* res;

   // int counter; - error - it is per object (each object has it's own counter) -  cannot have static member variable in template class
	
   // static int counter;- error - it is per class but we want count per resource
  
    int* counter; // counter for the number of objects pointing to the same resource
    
    void incrementalcounter() // increment the counter
	{
        if (counter) {
            (*counter)++; // both are pointing to same , so increment the counter
        }
	}

    void decrementalcounter() // decrement the counter
    {
        if (counter) {
            (*counter)--;

            if ((*counter) == 0) // if no object is pointing to the resource
            {
                if (res) {
                    delete res;
                    delete counter;
                    res = nullptr;
                    counter = nullptr;
                }
            }
        }
    }



public:

    sharedptr(T* ptr = nullptr) : res(ptr), counter(new int(1))    // ptr = nullptr - called default constructor 
    {
        cout << "default constructor and parameterized called" << endl;
    }

    // copy constructor - deep copy

    sharedptr<T>(const sharedptr<T>& ptr)
    {
        res = ptr.res;
        counter = ptr.counter;
        incrementalcounter(); // increment the counter
    }

    // move constructor - shallow copy

    sharedptr<T>(sharedptr<T>&& ptr)
    {
        res = ptr.res;
        counter = ptr.counter;
        ptr.res = nullptr;
        ptr.counter = nullptr;

    }

    // copy assignment operator - deep copy

    sharedptr<T>& operator= (const sharedptr<T>& ptr)
    {
        if (this != &ptr) // self assignment 
        {
            decrementalcounter(); // decrement the counter - ptr3 = ptr2 : ptr3 is trying to  point to some other resource, so ptr3 will leave it own resource and point to ptr2 resource SO WE HAVE to decrement the count of ptr3 resource and increase the count of ptr2 resource

            res = ptr.res;
            counter = ptr.counter; // both are pointing to same resource, so increment the counter
            incrementalcounter(); // increment the counteR
        }
        return *this;
    }

    // move assignment operator - shallow copy

    sharedptr<T>& operator= (sharedptr<T>&& ptr)
    {
        if (this != &ptr) // self assignment 
        {
			decrementalcounter(); // decrement the counter - ptr3 = ptr2 : ptr3 is trying to  point to some other resource, so ptr3 will leave it own resource and point to ptr2 resource SO WE HAVE to decrement the count of ptr3 resource and increase the count of ptr2 resource

			res = ptr.res;
			counter = ptr.counter; // both are pointing to same resource, so increment the counter
			ptr.res = nullptr;
			ptr.counter = nullptr;
		}
        return *this;
    }

    void reset(T* ptr = nullptr)
    {
        decrementalcounter(); // decrement the counter - leaving the object what is pointing to and pointing to new object 
        res = ptr;
        counter = new int(1); // new resource, so counter is 1 - only one object is pointing to the resource
    }

    int get_count()
    {
        if (counter)
        {
            return (*counter);
        }
        return -1;
    }

    T* operator->()
    {
		return res;
	}

    T& operator*()
    {
		return *res;
	}

    T* get()
    {
        return res;
    }

    ~sharedptr()
    {
        cout << "destructor called" << endl;
		decrementalcounter(); // decrement the counter not delete , once we are out of scope or deleting it (so will not say delete) , because the actual sharedptr will be on stack, so they will be deleted when they are out of scope - whatever this object is pointing the resource to it should decrement the count , not delete it , because they might be pointed out by someone else . that's why we called decremenatcount() - it will take care of everything like - if the count become zero or last pointer so it will delete automatically delete all the resources.
       
	}
};

int main()
{
    std::cout << "\n----------------  Shared_ptr internal implementation ----------------\n\n";

    sharedptr<int> ptr1; // default constructor
    sharedptr<int> ptr2(new int(10)); // parameterized constructor
    sharedptr<int> ptr3(ptr2); // copy constructor
    ptr3 = ptr2; // copy assignment operator
    sharedptr<int> ptr4(std::move(ptr1)); // move constructor
    ptr2 = std::move(ptr3); // move assignment operator

    ptr1.reset(); // reset
    ptr1.reset(new int(5)); // reset

    cout << (*ptr1) <<endl; // implementing * operator

   // ptr1->func(); // implementing -> operator - give compile error - this will work with class object or user-defined object

    ptr1.get(); // raw pointer

    ptr1.get_count(); // no of object pointing to the same resource

    //destructor will be called automatically when the object goes out of scope

    return 0;
}

