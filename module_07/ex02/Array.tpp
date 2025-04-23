#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array() : arr(NULL) , n(0)
{
}

template <typename T>
Array<T>::Array(unsigned int _n) : n(_n)
{
    arr = new T[_n];
}

/////////////  copy constructor and assignment operator ////

template <typename T>
Array<T>::Array(const Array& obj) : arr(NULL), n(obj.n)
{
	if (this->n > 0)
	{
		this->arr = new T[n];
		for (unsigned int i = 0; i < n; i++)
			this->arr[i] = obj.arr[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& obj)
{
	if (this != &obj)
	{
		delete[] arr;
		n = obj.n;
		arr = (n > 0) ? new T[n] : NULL;
		for (unsigned int i = 0; i < n; i++)
			arr[i] = obj.arr[i];
	}
	return *this;
}


template <typename T>
Array<T>::~Array()
{
    delete[] arr;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return(this->n);
}

template <typename T>
T &Array<T>::operator[](const unsigned int i)
{
    if (i >= this->n)
        throw std::exception();
    return this->arr[i];
}

#endif