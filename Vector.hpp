#include <algorithm>



template< typename T>
class Vec {
public:
    ~Vec();
    Vec() = default;
    Vec( Vec<T>& other);
    template< typename... Args>
    Vec( const Args... param);

    T& operator[] ( const size_t index);

    void operator<< ( const T param);
    void operator>> ( const T param);

    size_t get_len( void);
    size_t get_capacity( void);

    T* begin();
    T* end();

private:
    T* data;
    size_t length;
    size_t cap;

};

template< typename T>
Vec<T>::~Vec() {
    delete[] data;
} 

template< typename T>
Vec<T>::Vec( Vec<T>& other):
    data{ new T[ other.get_len()]},
    length{ other.get_len()},
    cap{ other.get_len() * 2}
{
    for ( size_t i=0; i < length; ++i) {
        data[i] = other[i];
    }
}

template< typename T>
template< typename... Args>
Vec<T>::Vec( const Args... param):
    data{ new T[ sizeof...(param) * 2] { std::move( param)... }},
    length{ sizeof...(param)},
    cap{ sizeof...(param) * 2}
{}

template< typename T>
T& Vec<T>::operator[] (const size_t index) {
    return data[index];
}

template< typename T>
size_t Vec<T>::get_len() {
    return length;
}

template< typename T>
size_t Vec<T>::get_capacity() {
    return cap;
} 

template< typename T>
T* Vec<T>::begin() {
    return data;
}

template< typename T>
T* Vec<T>::end() {
    return data + length;
}

template< typename T>
void Vec<T>::operator<< ( const T param) {
    
    if (length < cap) { 
        data[length] = param;
        length += 1;
        return;
    } 

    this->cap *= 1.5;

    T* tmp_ptr = new T[cap];
    T* tmp_ptr_delete = data;

    std::copy_n(data, length, tmp_ptr);
    tmp_ptr[length] = param;
    data = tmp_ptr;

    length += 1;
    
    delete[] tmp_ptr_delete;
}

template< typename T>
void Vec<T>::operator>>( const T param) {
    size_t index = 0;
    for ( ; index < length; ++index) {
        if (param == data[index]) {
            break;
        }
    }

    std::copy( data + index + 1, data + length, data + index);
    length -= 1;
}