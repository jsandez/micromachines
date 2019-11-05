#ifndef _COLA_PROTEGIDA_H_
#define _COLA_PROTEGIDA_H_

#include <mutex>
#include <queue>

template <class T>
class ColaProtegida {
private:
    std::mutex mtx_;
    std::queue<T> elementos_;

    ColaProtegida(ColaProtegida&& otra) = delete;

    ColaProtegida(const ColaProtegida& otra) = delete;

    ColaProtegida& operator=(const ColaProtegida& otra) = delete;

    ColaProtegida& operator=(ColaProtegida&& otra) = delete;

    public:
    ColaProtegida() {
    }

    ~ColaProtegida() {
    }

    void put(T& unElemento) {
        std::lock_guard<std::mutex> lck(mtx_);
        elementos_.push(std::move(unElemento));
    }
    
    bool get(T& unElemento) {
        std::unique_lock<std::mutex> lck(mtx_);
        if (elementos_.empty()) {
            return false;
        }
        unElemento = std::move(elementos_.front());
        elementos_.pop();
        return true;
    }
};

#endif
