#include <functional>
#include <algorithm>
#include <string>
#include <cstring>
#include <stdexcept>
#include <utility> // std::exchange
#include "PtrCStringVector.h"
using namespace std;


PtrCStringVector::PtrCStringVector()
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    size_=0;
    capacity_ = 0;
    data_ = null;
}

PtrCStringVector::PtrCStringVector(const PtrCStringVector &srcPtrCStringVector)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym

}

PtrCStringVector::~PtrCStringVector()
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym

}

PtrCStringVector &PtrCStringVector::operator=(const PtrCStringVector &source)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym

    return *this;
}

PtrCStringVector& PtrCStringVector::operator=(PtrCStringVector&& source)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym

    return *this;
}

void PtrCStringVector::push_back(const char *text2Add)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    if(size_=capacity_){
        reserve(capacity_+5);
    }
    data_[size_]=const_cast<char*>(text2Add);
    size_++;

}

PtrCStringVector PtrCStringVector::operator+(const PtrCStringVector &anotherVector) const
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    size_t new_size_ = size_ + anotherVector.size();
    PtrCStringVector new_tab;
    new_tab.reserve(new_size_);

    return {};
}

char *PtrCStringVector::operator[](size_t index)
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    if(index>=size_ || index<0){throw std::out_of_range("Index out of range");}
    return data_[index];
}
const char *PtrCStringVector::operator[](size_t index) const noexcept
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    if(index>=size_ || index<0){return "";}
    return data_[index];
}

PtrCStringVector PtrCStringVector::operator&(const PtrCStringVector &rhs) const
{
    /// @todo zaimplementuj, szczegoly w pliku naglowkowym
    return {};
}

void PtrCStringVector::free()
{
    /// @todo sugeruje zaimplementowac, szczegoly w pliku naglowkowym
    char* pom= data_[0];
    for(int i=0;i<size_;i++){
        delete[] data_[i];
    }
    delete[] data_;
    size_=0;
    capacity_=0;
}

void PtrCStringVector::copy(const PtrCStringVector& other)
{
    /// @todo sugeruje zaimplementowac, szczegoly w pliku naglowkowym
    free();
    reserve(other.capacity());
    for(int i=0;i<other.size();i++){
        data_[i]=const_cast<char*>(other[i]);
    }
    size_=other.size();
}
void PtrCStringVector::move(PtrCStringVector&& other)
{
    /// @todo sugeruje zaimplementowac, szczegoly w pliku naglowkowym

}

void PtrCStringVector::reserve(size_t new_capacity)
{
    /// @todo sugeruje zaimplementowac, szczegoly w pliku naglowkowym
    capacity_=new_capacity;
    char**pom = data_;
    delete[] data_;
    data_= new char*[capacity_];
    for(int i = 0; i<size_;i++){
        data_[i] = pom[i];
    }
}

