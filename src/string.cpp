#include <string.h> // defines memcpy_s
#include "technikumSTL/string.h"

#ifndef WIN32 
void memcpy_s(void * dest, int cap, const void * src, int len) { memcpy(dest, src, len); }
#endif

namespace technikum
{
    std::size_t custom_strlen(const char* c_str) 
    {
        std::size_t length = 0;
        while (*c_str != '\0') {
            ++length;
            ++c_str;
        }
        return length;
    }

    string::string()
    {
        alloc(small_string_buffer_size);
    }

    string::string(std::size_t reserve_capacity)
    {
        alloc(reserve_capacity);
    }

    string::string(const char * from_c_str)
    {
        std::size_t reserve_capacity = custom_strlen(from_c_str) + 1;

        alloc(reserve_capacity);

        void* copy_dest = 
            _capacity == small_string_buffer_size ?
            (void *)_small_string_buffer :
            (void *)_c_str;

        memcpy_s(
            copy_dest,
            _capacity,
            from_c_str,
            reserve_capacity);

        _len = reserve_capacity;
    }

    string::string(const string& other)
    {
        _len = other._len;
        _capacity = other._capacity;

        if (other._capacity == small_string_buffer_size)
        {
            memcpy_s(
                _small_string_buffer,
                small_string_buffer_size,
                other._small_string_buffer,
                other._len);
            return;
        }

        _c_str = new char[other._capacity];

        memcpy_s(
            _c_str,
            other._capacity,
            other._c_str,
            other._len);
    }

    string::string(string&& other)
    {
        _len = other._len;
        _capacity = other._capacity;

        if (other._capacity == small_string_buffer_size)
        {
            memcpy_s( 
                _small_string_buffer,
                small_string_buffer_size,
                other._small_string_buffer,
                other._len);
            return;
        }

        _c_str = other._c_str;

        other._small_string_buffer[0] = 0;
        other._len = 1;
        other._capacity = small_string_buffer_size;
    }
    
    string::~string()
    {
        if (_capacity != small_string_buffer_size)
        {
            delete[] _c_str;
        }
    }

    string& string::operator = (const string& other)
    {
        if (this == &other)
            return *this;

        reserve(other._capacity);

        if (other._capacity == small_string_buffer_size)
        {
            memcpy_s(
                _small_string_buffer,
                small_string_buffer_size,
                other._small_string_buffer,
                other._len);

            _len = other._len;

            return *this;
        }

        memcpy_s(
            _c_str,
            _capacity,
            other._c_str,
            other._len);

        _len = other._len;

        return *this;
    }

    string& string::operator = (string&& other)
    {
        if (this == &other)
            return *this;

        if (_capacity != small_string_buffer_size)
            delete[] _c_str;

        _len = other._len;
        _capacity = other._capacity;

        if (other._capacity == small_string_buffer_size)
        {
            memcpy_s(
                _small_string_buffer,
                small_string_buffer_size,
                other._small_string_buffer,
                other._len);
            return *this;
        }

        _c_str = other._c_str;

        other._small_string_buffer[0] = 0;
        other._len = 1;
        other._capacity = small_string_buffer_size;

        return *this;
    }

    string& string::operator += (const string& other)
    {
        append(other);
        return *this;
    }

    string& string::operator += (const char* other_c_str)
    {
        append(other_c_str);
        return *this;
    }

    string string::operator + (const string& other) const
    {
        auto new_string = *this;
        new_string.append(other);
        return new_string;
    }

    string string::operator + (const char* other_c_str) const
    {
        auto new_string = *this;
        new_string.append(other_c_str);
        return new_string;
    }

    string::operator const char* () const
    {
        return c_str();
    }

    const char* string::c_str() const
    {
        if (_capacity == small_string_buffer_size) 
            return _small_string_buffer;
        
        return _c_str;
    }

    std::size_t string::size() const
    {
        if (_len <= 0) return 0;
        return _len - 1;
    }

    std::size_t string::capacity() const
    {
        return _capacity;
    }

    void string::append(const string& other)
    {
        std::size_t target_capacity = _len + other._len - 1;

        if (target_capacity > small_string_buffer_size)
        {
            auto new_buffer = new char[target_capacity];

            memcpy_s(
                new_buffer,
                target_capacity,
                c_str(),
                _len - 1);

            memcpy_s(
                new_buffer + (_len - 1),
                target_capacity - (_len - 1),
                other.c_str(),
                other._len);

            if(_capacity != small_string_buffer_size)
                delete[] _c_str;
            _c_str = new_buffer;
            _capacity = target_capacity;
            _len = target_capacity;

            return;
        }

        memcpy_s(
            _small_string_buffer + (_len - 1),
            small_string_buffer_size - (_len - 1),
            other._small_string_buffer,
            other._len);
        
        _len = target_capacity;
    }

    void string::append(const char* other_c_str)
    {
        auto other_len = custom_strlen(other_c_str) + 1;

        std::size_t target_capacity = _len + other_len - 1;

        if (target_capacity > small_string_buffer_size)
        {
            auto new_buffer = new char[target_capacity];

            memcpy_s(
                new_buffer,
                target_capacity,
                c_str(),
                _len - 1);

            memcpy_s(
                new_buffer + (_len - 1),
                target_capacity - (_len - 1),
                other_c_str,
                other_len);

            if(_capacity != small_string_buffer_size)
                delete[] _c_str;
            _c_str = new_buffer;
            _capacity = target_capacity;
            _len = target_capacity;

            return;
        }

        memcpy_s(
            _small_string_buffer + (_len - 1),
            small_string_buffer_size - (_len - 1),
            other_c_str,
            other_len);
        
        _len = target_capacity;
    }

    void string::alloc(std::size_t reserve_capacity)
    {
        if (reserve_capacity > small_string_buffer_size)
        {
            auto new_buffer = new char[reserve_capacity];
            new_buffer[0] = 0;

            _c_str = new_buffer;
            _capacity = reserve_capacity;
            _len = 1;
            return;
        }

        _small_string_buffer[0] = 0;
        _capacity = small_string_buffer_size;
        _len = 1;
    }

    void string::reserve(std::size_t reserve_capacity)
    {
        std::size_t current_capacity = _capacity;

        if (current_capacity <= reserve_capacity) 
        {
            //reserve bigger
            if (reserve_capacity > small_string_buffer_size)
            {
                auto new_buffer = new char[reserve_capacity];

                memcpy_s(
                    new_buffer,
                    reserve_capacity,
                    c_str(),
                    _len);

                if (_capacity != small_string_buffer_size)
                    delete[] _c_str;

                _c_str = new_buffer;
                _capacity = reserve_capacity;
                return;
            }
            else
            {
                memcpy_s(
                    (void*)_small_string_buffer,
                    small_string_buffer_size,
                    c_str(),
                    reserve_capacity - 1);

                if (_capacity != small_string_buffer_size)
                    delete[] _c_str;
                _small_string_buffer[reserve_capacity - 1] = '\0';
                _capacity = small_string_buffer_size;
                _len = reserve_capacity;
                return;
            }
        }
        else 
        {
            //reserve smaller
            if (reserve_capacity > small_string_buffer_size)
            {
                auto new_buffer = new char[reserve_capacity];

                memcpy_s(
                    new_buffer,
                    reserve_capacity,
                    c_str(),
                    reserve_capacity - 1);

                if (_capacity != small_string_buffer_size)
                    delete[] _c_str;

                _c_str = new_buffer;
                _c_str[reserve_capacity - 1] = '\0';
                _capacity = reserve_capacity;
                if (_len > reserve_capacity)
                    _len = reserve_capacity;
                return;
            }
            else 
            {
                memcpy_s(
                    (void*)_small_string_buffer,
                    small_string_buffer_size,
                    c_str(),
                    reserve_capacity - 1);

                _small_string_buffer[reserve_capacity - 1] = '\0';
                _capacity = small_string_buffer_size;
                if(_len > reserve_capacity)
                    _len = reserve_capacity;
                return;
            }
        }
    }

    template<typename T>
    string::Iterator<T>& string::Iterator<T>::operator++()
    {
        ++_ptr;
        return *this;
    }

    template<typename T>
    string::Iterator<T> string::Iterator<T>::operator++(int)
    {
        string::Iterator temp = *this;
        ++_ptr;
        return temp;
    }

    template<typename T>
    string::Iterator<T>& string::Iterator<T>::operator--()
    {
        --_ptr;
        return *this;
    }

    template<typename T>
    string::Iterator<T> string::Iterator<T>::operator--(int)
    {
        string::Iterator temp = *this;
        --_ptr;
        return temp;
    }

    template<typename T>
    string::Iterator<T> string::begin() const
    {
        auto ptr = _capacity == small_string_buffer_size ? _small_string_buffer : _c_str;
        return string::Iterator(ptr);
    }

    template<typename T>
    string::Iterator<T> string::end() const
    {
        auto ptr = _capacity == small_string_buffer_size ? _small_string_buffer : _c_str;
        return string::Iterator(ptr + _len - 2 );
    }

    template<typename T>
    T& string::Iterator<T>::operator*()
    {
        return *_ptr;
    }

    template<typename T>
    T* string::Iterator<T>::operator->()
    {
        return _ptr;
    }

    template<typename T>
    bool string::Iterator<T>::operator==(const string::Iterator<T>& a)
    {
        return _ptr == a._ptr;
    }
    
    template<typename T>
    bool string::Iterator<T>::operator!= (const string::Iterator<T>& a)
    {
        return _ptr != a._ptr;
    };
}