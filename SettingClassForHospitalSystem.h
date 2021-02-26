#include<iostream>
using namespace std;
template<class T>
class Set
{
private:
	int maxSize;
	T* arr;
	int size;
public:
	Set()
	{
		maxSize = 10;
		size = 0;
		arr = new T[maxSize];
	}
	Set(int number)
	{
		maxSize = number;
		size = 0;
		arr = new T[maxSize];
	}
	Set(Set& oldArr)
	{
		this->maxSize = oldArr.maxSize;
		this->size = oldArr.size;
		this->arr = new T[this->maxSize];
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = oldArr.arr[i];
		}
	}
	~Set()
	{
		delete[] arr;
	}
	void AddElement(T newItem)
	{
		int check = 1;
		for (int i = 0; i < this->size; i++)
		{
			if (this->arr[i] == newItem)
			{
				check = 0;
			}
		}
		if (check && this->size != this->maxSize)
		{
			this->arr[this->size] = newItem;
			this->size++;
		}
		else if (this->maxSize == this->size)
		{
			cout << "List is full\n" << endl;
		}
		else
		{
			cout << "This type already in the list\n" << endl;
		}
	}
	int RemoveElement(T deletingItem)
	{
		int k;
		for (int i = 0; i < this->size; i++)
		{
			if (this->arr[i] == deletingItem)
			{
				if (i + 1 == this->size)
				{
					this->arr[i] = NULL;
				}
				else
				{
					for (int j = i; j < this->size - 1; j++)
					{
						this->arr[j] = this->arr[j + 1];
						k = j;
					}
					this->arr[k + 1] = NULL;
				}
				this->size--;
				return 1;
			}
		}
		return 0;
	}
	void PrintSet()
	{
		for (int i = 0; i < this->size; i++)
		{
			cout << i + 1 << ". element " << this->arr[i] << endl;
		}
	}
	Set operator+(Set& param)
	{
		cout << "OPERATOR + CALLED!" << endl;
		int i;
		if (this->size >= param.size)
		{
			i = this->size;
		}
		else
		{
			i = param.size;
		}
		Set<T> unions(i);
		for (int i = 0; i < unions.maxSize; i++)
		{
			if (i >= this->size)
			{
				unions.AddElement(param.arr[i]);
			}
			else if (i >= param.size)
			{
				unions.AddElement(this->arr[i]);
			}
			else
			{
				unions.AddElement(this->arr[i] + param.arr[i]);
			}
		}
		return unions;
	}
	Set operator-(Set<T>& param)
	{
		cout << "OPERATOR - CALLED!" << endl;
		int i;
		if (this->size >= param.size)
		{
			i = this->size;
		}
		else
		{
			i = param.size;
		}
		Set* unions = new Set(i);
		for (int i = 0; i < unions->maxSize; i++)
		{
			if (i >= this->size)
			{
				unions->AddElement(param.arr[i]);
			}
			else if (i >= param.size)
			{
				unions->AddElement(this->arr[i]);
			}
			else
			{
				unions->AddElement(this->arr[i] - param.arr[i]);
			}
		}
		return *unions;
	}
	int operator==(Set& param)
	{
		cout << "OPERATOR == CALLED!" << endl;
		int check;
		if (this->size != param.size)
		{
			return 0;
		}
		for (int i = 0; i < this->size; i++)
		{
			check = 0;
			for (int j = 0; j < this->size; j++)
			{
				if (this->arr[i] == param.arr[j])
				{
					check = 1;
				}
			}
			if (!check)
			{
				return 0;
			}
		}
		return 1;
	}
	int operator!=(Set& param)
	{
		cout << "OPERATOR != CALLED!" << endl;
		int check;
		if (this->size != param.size)
		{
			return 1;
		}
		for (int i = 0; i < this->size; i++)
		{
			check = 0;
			for (int j = 0; j < this->size; j++)
			{
				if (this->arr[i] == param.arr[j])
				{
					check = 1;
				}
			}
			if (!check)
			{
				return 1;
			}
		}
		return 0;
	}
	void operator=(Set& param)
	{
		cout << "OPERATOR = CALLED!" << endl;
		if (this->size != param.size)
		{
			delete[] this->arr;
			this->size = param.size;
			this->maxSize = param.maxSize;
			this->arr = new T[param.maxSize];
		}
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = param.arr[i];
		}
	}
	Set operator+=(Set& param)
	{
		cout << "OPERATOR += CALLED!" << endl;
		(*this) = (*this) + (param);
		return *this;
	}
	int operator<(Set& param)
	{
		cout << "OPERATOR < CALLED!" << endl;
		int check;
		if (this->size > param.size)
		{
			return 0;
		}
		else
		{
			for (int i = 0; i < this->size; i++)
			{
				check = 0;
				for (int j = 0; j < param.size; j++)
				{
					if (this->arr[i] == param.arr[j])
					{
						check = 1;
					}
				}
				if (!check)
				{
					return 0;
				}
			}
			return 1;
		}
	}
	friend ostream& operator<<(ostream& os, Set mySet)
	{
		cout << "OPERATOR << CALLED!" << endl;
		for (int i = 0; i < mySet.size; i++)
		{
			os << i + 1 << ". element " << mySet.arr[i] << endl;
		}
		return os;
	}
	friend istream& operator>>(istream& is, Set<T>& mySet)
	{
		cout << "OPERATOR >> CALLED!\nFill the set with cin" << endl;
		T item;
		while (mySet.size < mySet.maxSize)
		{
			cout << "Enter the " << mySet.size + 1 << ". element";
			cin >> item;
			mySet.AddElement(item);
		}
		return is;
	}
};