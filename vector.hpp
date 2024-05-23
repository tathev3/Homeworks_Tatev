// vector.hpp
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstdlib> 

template <typename T>
class Vector {
   private:
      size_t size_;
      size_t capacity_;
      T* data;

   public:
      Vector();
      ~Vector();
      void push_back(const T& elem);
      T& operator[](size_t index);
      size_t size() const;
      size_t capacity() const;
      void pop_back();
      T* erase(size_t pos);

      T* begin() { return data; }
      T* end() { return data + size_; }
    
      //const T& operator[](size_t index) const;
};



#include "vector.inl" 

#endif 
