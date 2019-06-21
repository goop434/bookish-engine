#pragma once

template <typename T>
class DynArr
{
private:
	size_t numItems;
	size_t capacity;
	T** arr;
	void expand()
	{
		capacity *= 2;
		T** tempArr = new T*[capacity];

		for (size_t i = 0; i < numItems; i++)
		{
			tempArr[i] = arr[i];
		}
		delete[] arr;

		arr = tempArr;

		initialize(numItems);
	}

	void initialize(size_t from = 0)
	{
		for (size_t i = from; i < capacity; i++)
		{
			arr[i] = nullptr;
		}
	}

public:
	DynArr()
	{
		capacity = 10;
		numItems = 0;
		arr = new T*[capacity];
	}
	DynArr(size_t size)
	{
		capacity = size;
		numItems = 0;
		arr = new T*[capacity];
	}
	DynArr(const DynArr& obj)
	{
		capacity = obj.cap();
		numItems = obj.size();
		arr = new T*[capacity];

		for (size_t i = 0; i < numItems; i++)
		{
			arr[i] = new T(*obj.arr[i]);
		}

		initialize();
	}
	~DynArr()
	{
		for (size_t i = 0; i < numItems; i++)
		{
			delete arr[i];
		}
		delete[] arr;
	}

	//OPERATORS
	T& operator[] (const size_t index)
	{
		if (index < 0 || index >= numItems)
		{
			throw "OUT OF BOUNDS INDEXING OPERATOR";
		}

		return *arr[index];
	}

	void operator= (const DynArr& obj)
	{
		for (size_t i = 0; i < numItems; i++)
		{
			delete arr[i];
		}
		delete[] arr;

		capacity = obj.cap();
		numItems = obj.size();
		arr = new T*[capacity];

		for (size_t i = 0; i < numItems; i++)
		{
			arr[i] = new T(*obj.arr[i]);
		}
	}

	//ACCESSORS
	size_t cap() const { return capacity; }
	size_t size() const { return numItems; }
	bool empty() const
	{
		if (numItems > 0)
			return false;

		return true;
	}

	//FUNCTIONS
	void push(const T value)
	{
		if (numItems >= capacity)
		{
			expand();
		}
		arr[numItems++] = new T(value);
	}

	void remove(const size_t index, bool ordered = false)
	{
		if (index < 0 || index >= numItems)
		{
			throw "OUT OF BOUNDS REMOVE";
		}
		if (ordered)
		{
			delete arr[index];

			for (size_t i = index; i < numItems - 1; i++)
			{
				arr[i] = arr[i + 1];
			}
			arr[--numItems] = nullptr;
		}
		else
		{
			delete arr[index];
			arr[index] = arr[numItems - 1];
			arr[--numItems] = nullptr;
		}
	}

	void clear()
	{
		while (numItems > 0)
		{
			remove(numItems - 1);
		}
	}

};



