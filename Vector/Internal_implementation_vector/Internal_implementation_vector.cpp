// Internal_implementation_vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template <typename T>
class Vector
{
    T* arr;
    int capacity;
    int size;
public:

    // define constructor with no size and capacity 
    Vector()
    {
        arr = new T[1];
		capacity = 1; // can give 0 also 
		size = 0;
    }

     // define constructor with size and capacity
    Vector(int num)
    {
       arr = new T[num];
       capacity = num;
       size = 0;
    }

    void new_allocation()
    {
		T* temp = new T[2 * capacity];
        for (int i = 0; i < capacity; i++)
        {
			temp[i] = arr[i];
		}
		delete[] arr;
		capacity *= 2;
		arr = temp;
	}

    // pushback() mechanism - if size < capacity then push the element at the end of the array
    // pushback() mechanism - if size >= capacity then allocate new array with double the size of the previous array

    void pushback(T element )
    {
        if (size == capacity)
        {
            new_allocation();
        }
        arr[size] = element;
        size++;
    }
    void popback()
    {
        if (size == capacity)
        {
			cout << "No element to pop" << endl;
		}
        else
        {
			size--;
		}
	}

    // [] operator overloading
    T& operator[](int index)
    {
        if (index < 0 || index >= size)
        {
             return arr[index];
        }
    }
    T get(int index)
    {
        if (index < 0 || index >= size)
        {
			cout << "Index out of range" << endl;
		}
        else
        {
            cout << arr[index] << endl;
			return arr[index];
		}
	}
    void insert(int index, T element)
    {
        if (index < 0 || index >= size)
        {
			cout << "Index out of range" << endl;
		}
        else
        {
            if (size == capacity)
            {
				new_allocation();
			}
            for (int i = size - 1; i >= index; i--)
            {
				arr[i + 1] = arr[i];
			}
			arr[index] = element;
			size++;
		}
	}
    void remove(int index)
    {
        if (index < 0 || index >= size)
        {
			cout << "Index out of range" << endl;
		}
        else
        {
            for (int i = index; i < size - 1; i++)
            {
				arr[i] = arr[i + 1];
			}
			size--;
		}
	}
    int sizeofvector()
    {
		return size;
	}
    int capacityofvector()
    {
		return capacity;
	}
    void print()
    {
        for (int i = 0; i < size; i++)
        {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};
int main()
{
    std::cout << "Hello World!\n";

    // constructor 
    // vector<int> v; // not defined size and capacity
    // vector<int> v(5); // defined size and capacity

    // pushback() mechanism - 1,2,3,4,5,0.0,0,0,0

    Vector<int> v;
    v.pushback(1);
    v.pushback(2);
    v.pushback(3);
    v.pushback(4);
    
    v.popback();
    v.print();

    v.insert(1, 5);
    v.print();

    v.get(1);
    v.print();

    v.remove(1);
    v.print();

    v.remove(-4);
    v.print();

    v.capacityofvector();
    v.print();

}

