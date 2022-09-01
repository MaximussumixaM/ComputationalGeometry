#ifndef CGCONTAINERS_H
#define CGCONTAINERS_H

//Поправить в соответствии
//https://codereview.stackexchange.com/questions/159592/vector-with-move-constructor-and-move-assignment-operator
namespace Containers_NS {

    template <class T>
    class  CGList
    {
    public:
        typedef T* iterator;

        CGList();
        CGList(unsigned int size);
        CGList(unsigned int size, const T& initial);
        CGList(const CGList<T>& v);
        virtual ~CGList();   

        unsigned int capacity() const;
        unsigned int size() const;
        bool empty() const;
        iterator begin();
        iterator end();
        T& front();
        T& back();
        void push_back(const T& value);
        void pop_back();
        void reserve(unsigned int capacity);
        void resize(unsigned int size);

        CGList<T>& operator=(const CGList<T>&);
        void clear();
       
        // Access elements, no bounds checking
        T& operator[](unsigned int i);

        // Access elements with bounds checking
        T& at(unsigned int n);
      
    private:
        unsigned int _size;
        unsigned int _capacity;
        T* buffer;
    };

    template<class T>
    CGList<T>::CGList()
    {
        _capacity = 0;
        _size = 0;
        buffer = 0;
    }

    template<class T>
    CGList<T>::CGList(const CGList<T>& v)
    {
        _size = v._size;
        _capacity = v._capacity;
        buffer = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            buffer[i] = v.buffer[i];
    }

    template<class T>
    CGList<T>::CGList(unsigned int size)
    {
        _capacity = size;
        _size = size;
        buffer = new T[size];
    }

    template<class T>
    CGList<T>::CGList(unsigned int size, const T& initial)
    {
        _size = size;
        _capacity = size;
        buffer = new T[size];
        for (unsigned int i = 0; i < size; i++)
            buffer[i] = initial;
    }

    template<class T>
    CGList<T>& CGList<T>::operator = (const CGList<T>& v)
    {
        delete[] buffer;
        _size = v._size;
        _capacity = v._capacity;
        buffer = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            buffer[i] = v.buffer[i];
        return *this;
    }

    template<class T>
    typename CGList<T>::iterator CGList<T>::begin()
    {
        return buffer;
    }

    template<class T>
    typename CGList<T>::iterator CGList<T>::end()
    {
        return buffer + size();
    }

    template<class T>
    T& CGList<T>::front()
    {
        return buffer[0];
    }

    template<class T>
    T& CGList<T>::back()
    {
        return buffer[_size - 1];
    }

    template<class T>
    void CGList<T>::push_back(const T& v)
    {
        if (_size >= _capacity)
            reserve(_capacity + 5);
        buffer[_size++] = v;
    }

    template<class T>
    void CGList<T>::pop_back()
    {
        _size--;
    }

    template<class T>
    void CGList<T>::reserve(unsigned int capacity)
    {
        if (buffer == 0)
        {
            _size = 0;
            _capacity = 0;
        }
        T* Newbuffer = new T[capacity];      
        unsigned int l_Size = capacity < _size ? capacity : _size;

        for (unsigned int i = 0; i < l_Size; i++)
            Newbuffer[i] = buffer[i];

        _capacity = capacity;
        delete[] buffer;
        buffer = Newbuffer;
    }

    template<class T>
    unsigned int CGList<T>::size()const//
    {
        return _size;
    }

    template<class T>
    void CGList<T>::resize(unsigned int size)
    {
        reserve(size);
        _size = size;
    }
  
    // Accessors
    template<class T>
    T& CGList<T>::at(unsigned int n)
    {
        
        if (n < 0 || _size <= n) throw std::exception("Index out of range");
        return buffer[n];
    }

    template<class T>
    T& CGList<T>::operator[](unsigned int i)
    {
        return buffer[i];
    }

    template<class T>
    unsigned int CGList<T>::capacity()const
    {
        return _capacity;
    }

    template<class T>
    CGList<T>::~CGList()
    {
        delete[] buffer;
    }

    template <class T>
    void CGList<T>::clear()
    {
        _capacity = 0;
        _size = 0;
        buffer = 0;
    }    
}

#endif //CGCONTAINERS_H
