#include <cstddef>

namespace technikum
{
    class string
    {
    public:
        // can be increased if bigger sso buffer is desired
        static constexpr auto small_string_buffer_size = sizeof(const char*); 

        string();
        string(std::size_t reserve_capacity);
        string(const char * from_c_str);
        ~string();

        const char *c_str() const;
        std::size_t size() const;
        std::size_t capacity() const;
        void append(const string& other);
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

