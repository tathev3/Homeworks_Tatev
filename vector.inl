#include <cstdlib> 
#include <new>     
#include <stdexcept>  

template <typename T>
Vector<T>::Vector() : data(nullptr), size_(0), capacity_(0) {}

template <typename T>
Vector<T>::~Vector() {
    for (size_t i = 0; i < size_; ++i) {
        data[i].~T();
    }
    free(data);
}

template <typename T>
void Vector<T>::push_back(const T& elem) {
    if (size_ == capacity_) {
        size_t newCapacity = capacity_ == 0 ? 1 : 2 * capacity_;
        T* newData = static_cast<T*>(malloc(newCapacity * sizeof(T)));
        if (!newData) throw std::bad_alloc(); 

        for (size_t i = 0; i < size_; ++i) {
            new (&newData[i]) T(std::move(data[i]));
            data[i].~T(); 
        }
        free(data);
        data = newData;
        capacity_ = newCapacity;
    }
    new (&data[size_]) T(elem);
    size_++;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= size_) throw std::out_of_range("Index out of range");
    return data[index];
}

template <typename T>
size_t Vector<T>::size() const {
    return size_;
}

template <typename T>
size_t Vector<T>::capacity() const {
    return capacity_;
}

template <typename T>
void Vector<T>::pop_back() {
    if (size_ > 0) {
        --size_;
        data[size_].~T();
    }
}

template <typename T>
T* Vector<T>::erase(size_t pos) {
    if (pos >= size_) { 
        throw std::out_of_range("Index out of range");
    }

    data[pos].~T(); 
    for (size_t i = pos; i < size_ - 1; i++) {
        new (&data[i]) T(std::move(data[i + 1]));
        data[i + 1].~T();
    }
    --size_;
    return &data[pos];
}




//template <typename T>
//const T& Vector<T>::operator[](size_t index) const {
    //return data[index];
//}
