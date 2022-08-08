//#pragma once

#ifndef CGCONTAINERS_H
#define CGCONTAINERS_H
//https://ru.stackoverflow.com/questions/536546/%D0%A1%D1%81%D1%8B%D0%BB%D0%BA%D0%B0-%D0%BD%D0%B0-%D0%BD%D0%B5%D1%80%D0%B0%D0%B7%D1%80%D0%B5%D1%88%D0%B5%D0%BD%D0%BD%D1%8B%D0%B9-%D0%B2%D0%BD%D0%B5%D1%88%D0%BD%D0%B8%D0%B9-%D1%81%D0%B8%D0%BC%D0%B2%D0%BE%D0%BB-%D0%B2%D0%BE%D0%B7%D0%BC%D0%BE%D0%B6%D0%BD%D1%8B%D0%B5-%D0%BF%D1%80%D0%B8%D1%87%D0%B8%D0%BD%D1%8B
//Ќеправильна€ реализаци€ шаблонного кода.
//Ќапример, реализаци€ шаблонного кода помещена в* .cpp файл,
//хот€ она должна находитьс€ полностью в подключаемом* .h файле.
//Ёто требуетс€ по той причине, что компил€тор обрабатывает 
//каждый модуль независимо, и в момент инстанцировани€ 
//шаблона(подстановки конкретного типа) код его реализации должен быть
//виден.ѕри этом если возможные типы шаблона известны заранее,
//можно произвести инстанцирование сразу р€дом с телом шаблона и 
//не предоставл€ть его наружу в исходном коде заголовочного файла.

//наследование от std::vector - плохо, там нет виртуального деструктора, 
//поэтому свой
namespace Containers_NS {

    struct out_of_range
    {

    };

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
        //~CGList();

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

        //T& operator[](unsigned int index);
        CGList<T>& operator=(const CGList<T>&);
        void clear();
       
        // Access elements, no bounds checking
        T& operator[](unsigned int i);

        // Access elements, no bounds checking
        //const T& operator[](unsigned int i) const;
        // Access elements with bounds checking
        T& at(unsigned int n);
        // Access elements with bounds checking for constant Vectors.
        //const T& at(unsigned int n) const;
    public:
        unsigned int my_size;
        unsigned int my_capacity;
        T* buffer;
    };


    template<class T>
    CGList<T>::CGList()
    {
        my_capacity = 0;
        my_size = 0;
        buffer = 0;
    }

    template<class T>
    CGList<T>::CGList(const CGList<T>& v)
    {
        my_size = v.my_size;
        my_capacity = v.my_capacity;
        buffer = new T[my_size];
        for (unsigned int i = 0; i < my_size; i++)
            buffer[i] = v.buffer[i];
    }

    template<class T>
    CGList<T>::CGList(unsigned int size)
    {
        my_capacity = size;
        my_size = size;
        buffer = new T[size];
    }

    template<class T>
    CGList<T>::CGList(unsigned int size, const T& initial)
    {
        my_size = size;
        my_capacity = size;
        buffer = new T[size];
        for (unsigned int i = 0; i < size; i++)
            buffer[i] = initial;
        //T();
    }

    template<class T>
    CGList<T>& CGList<T>::operator = (const CGList<T>& v)
    {
        delete[] buffer;
        my_size = v.my_size;
        my_capacity = v.my_capacity;
        buffer = new T[my_size];
        for (unsigned int i = 0; i < my_size; i++)
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
        return buffer[my_size - 1];
    }

    template<class T>
    void CGList<T>::push_back(const T& v)
    {
        if (my_size >= my_capacity)
            reserve(my_capacity + 5);
        buffer[my_size++] = v;
    }

    template<class T>
    void CGList<T>::pop_back()
    {
        my_size--;
    }

    template<class T>
    void CGList<T>::reserve(unsigned int capacity)
    {
        if (buffer == 0)
        {
            my_size = 0;
            my_capacity = 0;
        }
        T* Newbuffer = new T[capacity];
        //assert(Newbuffer);
        unsigned int l_Size = capacity < my_size ? capacity : my_size;
        //copy (buffer, buffer + l_Size, Newbuffer);

        for (unsigned int i = 0; i < l_Size; i++)
            Newbuffer[i] = buffer[i];

        my_capacity = capacity;
        delete[] buffer;
        buffer = Newbuffer;
    }

    template<class T>
    unsigned int CGList<T>::size()const//
    {
        return my_size;
    }

    template<class T>
    void CGList<T>::resize(unsigned int size)
    {
        reserve(size);
        my_size = size;
    }

    /*template<class T>
    T& CGList<T>::operator[](unsigned int index)
    {
        return buffer[index];
    }*/

    // Accessors
    template<class T>
    T& CGList<T>::at(unsigned int n)
    {
        if (n < 0 || my_size <= n) throw out_of_range();
        return buffer[n];
    }

    /*template<class T>
    const T& CGList<T>::at(unsigned int n) const
    {
        if (n < 0 || my_size <= n) throw out_of_range();
        return buffer[n];
    }*/

    template<class T>
    T& CGList<T>::operator[](unsigned int i)
    {
        return buffer[i];
    }

    /* template<class T>
     const T& CGList<T>::operator[](unsigned int i) const
     {
         return buffer[i];
     }*/

    template<class T>
    unsigned int CGList<T>::capacity()const
    {
        return my_capacity;
    }

    template<class T>
    CGList<T>::~CGList()
    {
        delete[] buffer;
    }
    template <class T>
    void CGList<T>::clear()
    {
        my_capacity = 0;
        my_size = 0;
        buffer = 0;
    }

    
}

#endif
