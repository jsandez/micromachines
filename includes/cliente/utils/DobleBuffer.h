#ifndef __DOBLE_BUFFER_H__
#define __DOBLE_BUFFER_H__


#include <mutex>

template <typename T>
class DobleBuffer {
private:
    T datos[2];
    int actual{0};
    std::mutex mutex;

public:
    DobleBuffer() {}
    ~DobleBuffer() {}

    void swap();
    void set(const T& instance);
    T get();
};

template <typename T>
void DobleBuffer<T>::swap() {
    std::unique_lock<std::mutex> lock(this->mutex);
    this->actual = !this->actual;
}

template <typename T>
void DobleBuffer<T>::set(const T& instance) {
    std::unique_lock<std::mutex> lock(this->mutex);
    this->datos[!this->actual] = instance;
}

template <typename T>
T DobleBuffer<T>::get() {
    std::unique_lock<std::mutex> lock(this->mutex);
    return this->datos[this->actual];
}

#endif
