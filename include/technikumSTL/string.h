#ifndef TECHNIKUM_STRING_H
#define TECHNIKUM_STRING_H

#include <iterator> 
#include <cstddef>

namespace technikum
{
    class string
    {
    public:
        template<typename T>
        class Iterator
        {
        public:
            using difference_type = std::ptrdiff_t;
            using element_type = T;
            using pointer = element_type*;
            using reference = element_type&;
        public:
            Iterator() {}
            Iterator(pointer ptr) : _ptr(ptr) {}
            auto& operator++() { ++_ptr; return *this; }
            auto& operator--() { --_ptr; return *this; }
            auto operator++(int) {
                auto temp = *this;
                ++_ptr;
                return temp;
            }
            auto operator--(int) {
                auto temp = *this;
                --_ptr;
                return temp;
            }
            reference operator*() { return *_ptr; }
            auto* operator->() { return _ptr; }
            bool operator==(const Iterator& a) { return _ptr == a._ptr; }
            bool operator!=(const Iterator& a) { return _ptr != a._ptr; }
        private:
            T* _ptr;
        };

        // can be increased if bigger sso buffer is desired
        static constexpr auto small_string_buffer_size = sizeof(char*); 

        string();
        string(std::size_t reserve_capacity);
        string(const char* from_c_str);
        string(const string& other);
        string(string&& other);
        ~string();

        string& operator = (const string& other);
        string& operator = (string&& other);

        string& operator += (const string& other);
        string& operator += (const char* other_c_str);
        string operator + (const string& other) const;
        string operator + (const char* other_c_str) const;

        operator const char* () const;

        const char *c_str() const;
        std::size_t size() const;
        std::size_t capacity() const;
        void append(const string& other);
        void append(const char* other_c_str);
        void reserve(std::size_t reserve);

        auto begin()
        {
            char* ptr = _capacity == small_string_buffer_size ? _small_string_buffer : _c_str;
            return Iterator(ptr);
        }

        auto end()
        {
            char* ptr = _capacity == small_string_buffer_size ? _small_string_buffer : _c_str;
            return Iterator(ptr + _len - 2);
        }

        auto cbegin() const
        {
            const char* ptr = _capacity == small_string_buffer_size ? _small_string_buffer : _c_str;
            return Iterator(ptr);
        }

        auto cend() const
        {
            const char* ptr = _capacity == small_string_buffer_size ? _small_string_buffer : _c_str;
            return Iterator(ptr + _len - 2);
        }

    private:
        std::size_t _capacity = 0;
        std::size_t _len = 0; // including null terminator

        union
        {
            char* _c_str;
            char _small_string_buffer[small_string_buffer_size];
        };

        void alloc(std::size_t reserve_capacity);
    };
}

#endif