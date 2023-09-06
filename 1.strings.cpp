#include <cstddef>
#include <iostream>
#include <cstring>

class mystring {
    char* data_;
    size_t size_;
    size_t capacity_;
public:
    
    mystring() {
        size_ = 0;
        capacity_ = 4;
        data_ = new char[1];
        data_[0] = '\0';
    };

    mystring(mystring& x) {
        this->size_ = x.size_;
        this->capacity_ = x.capacity_;
        for (unsigned i=0; i<size_+1; i++) {
          this->data_[i] = x.get()[i];
        }
    }

    mystring(const char * s)     
    {
        size_ = std::strlen(s);
        capacity_ = size_*2;
        data_ = new char[size_+1];
        std::strcpy(data_, s);            
    }

    mystring operator=(const char * s)
    {
        delete [] data_;
        size_ = std::strlen(s);
        capacity_ = size_*2;
        data_ = new char[size_+1];
        std::strcpy(data_, s);
        return *this;
}
    
    const char* get(){
       return data_;
    } 

    ~mystring() {
        delete []data_;
    }
};

template<typename CharT, typename Traits, typename Alloc>
bool operator==(const std::basic_string<CharT, Traits, Alloc>& lhs, const std::basic_string<CharT, Traits, Alloc>& rhs) {
    return lhs.compare(rhs) == 0;
}

template<typename CharT, typename Traits, typename Alloc>
bool operator==(const CharT* lhs, const std::basic_string<CharT, Traits, Alloc>& rhs) {
    return rhs.compare(lhs) == 0;
}

template<typename CharT, typename Traits, typename Alloc>
bool operator==(const std::basic_string<CharT, Traits, Alloc>& lhs, const CharT* rhs) {
    return lhs.compare(rhs) == 0;
}



int main() {
    mystring a = "Hello,";
    mystring b = "World!";

    std::cout << a.get() << b.get();
    return 0;
}