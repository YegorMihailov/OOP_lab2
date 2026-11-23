#include "../include/my_string.h"
#include <cstring>
#include <utility>

String::String() : size_(0), capacity_(1) {
    data_ = new char[capacity_ + 1];
    data_[0] = '\0';
}

String::String(const char* str) {
    if (str) {
        size_ = std::strlen(str);
        capacity_ = size_ > 0 ? size_ : 1;
        data_ = new char[capacity_ + 1];
        std::strcpy(data_, str);
    } else {
        size_ = 0;
        capacity_ = 1;
        data_ = new char[capacity_ + 1];
        data_[0] = '\0';
    }
}

String::~String() noexcept {
    delete[] data_;
}

String::String(const String& other) : size_(other.size_), capacity_(other.capacity_) {
    data_ = new char[capacity_ + 1];
    std::strcpy(data_, other.data_);
}

String::String(String&& other) noexcept : data_(nullptr), size_(0), capacity_(0) {
    swap(other);
}

void String::swap(String& other) noexcept {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
}


String& String::operator=(String other) {
    swap(other);
    return *this;
}

void String::push_back(char c) {
    if (size_ == capacity_) {
        capacity_ *= 2;
        char* new_data = new char[capacity_ + 1];
        std::strcpy(new_data, data_);
        delete[] data_;
        data_ = new_data;
    }

    data_[size_] = c;
    size_++;
    data_[size_] = '\0';
}

void String::append(const char* str) {
    if (!str) return;
    
    size_t len = std::strlen(str);
    if (len == 0) return;

    if (size_ + len > capacity_) {
        while (size_ + len > capacity_) {
            capacity_ *= 2;
        }

        char* new_data = new char[capacity_ + 1];
        std::strcpy(new_data, data_);
        delete[] data_;
        data_ = new_data;
    }

    std::strcpy(data_ + size_, str);
    size_ += len;
}

void String::print(std::ostream& os) const {
    os << data_;
}

size_t String::find(const char* str) const {
    if (!str || size_ == 0) return -1;
    const char* pos = std::strstr(data_, str);

    if (pos) {
        return pos - data_;
    }

    return -1;
}

size_t String::count_char(char c) const {
    size_t count = 0;

    for (size_t i = 0; i < size_; i++) {
        if (data_[i] == c) {
            count++;
        }
    }

    return count;
}