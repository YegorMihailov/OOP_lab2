#define STRING_H
#include <cstddef>
#include <iostream>

class String {
private:
    char* data_;
    size_t size_;
    size_t capacity_;

public:
    String();
    String(const char* str);

    
    ~String() noexcept;
    String(const String& other);
    String(String&& other) noexcept;
    String& operator=(String other);

    void swap(String& other) noexcept;

    void push_back(char c);
    void append(const char* str);

    
    void print(std::ostream& os) const;
    size_t find(const char* str) const;

    size_t size() const { return size_; };
    size_t capacity() const { return capacity_; };
    const char* c_str() const { return data_; };

    size_t count_char(char c) const;
};