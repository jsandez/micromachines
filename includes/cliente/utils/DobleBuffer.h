#ifndef __DOBLE_BUFFER_H__
#define __DOBLE_BUFFER_H__


#include <mutex>

template <typename T>
class DobleBuffer {
private:
    T datos_[2];
    int actual_{0};
    bool valido_{false};
    std::mutex mutex_;

public:
    DobleBuffer() {}
    ~DobleBuffer() {}

    void swap();
    void set(const T& instance);
    bool get(T& destino);
};

template <typename T>
void DobleBuffer<T>::swap() {
    std::unique_lock<std::mutex> lock(mutex_);
    actual_ = !actual_;
}

template <typename T>
void DobleBuffer<T>::set(const T& instance) {
    std::unique_lock<std::mutex> lock(mutex_);
    datos_[!actual_] = instance;
    valido_ = true;
}

template <typename T>
bool DobleBuffer<T>::get(T& destino) {
    std::unique_lock<std::mutex> lock(mutex_);
    if (!valido_) {
        return false;
    }
    destino = datos_[actual_];
    return true;
}

#endif
