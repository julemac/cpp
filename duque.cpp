#include <iostream>
#include <algorithm> // std::sort, std::find, std::copy
#include <iterator> // std::distance, std::advance, std::back_inserter
#include <limits>   // std::numeric_limits<size_t>::max()
#include <numeric>  // std::accumulate()

using namespace std;

#include "containerWrapper.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif

IContainerWrapper::~IContainerWrapper() = default;

void sort() {
    
}

size_t DequeWrapper::find(const value_type& element) const{
    DequeWrapper::value_type val = impl_.at(0);
    int i=0;
    while(val != element)
    {
        i++;
    }
    return i;
}

DequeWrapper::value_type DequeWrapper::pop_front(){
    value_type val=impl_.at(0);
    impl_.pop_front();
    return val;
}

DequeWrapper::value_type DequeWrapper::count() const {
    value_type suma=0;
    for(int i=0;i<impl_.size();i++)
    {
        suma+=impl_.at(i);
    }
    return suma;
}
