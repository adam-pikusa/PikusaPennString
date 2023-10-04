#ifndef TECHNIKUM_STRING_H
#define TECHNIKUM_STRING_H

#include <cstddef>

namespace technikum
{
    class string
    {
    public:
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