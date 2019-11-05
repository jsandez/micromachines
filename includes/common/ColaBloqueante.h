#ifndef _COLA_BLOQUEANTE_H_
#define _COLA_BLOQUEANTE_H_

#include <mutex>
#include <condition_variable>
#include <queue>

template <class T>
class ColaBloqueante {
private:
    std::mutex mtx_;
    std::queue<T> elementos_;
    std::condition_variable cond_;
    //FIXME: Cambiar a atomic
    bool detenida_;

    ColaBloqueante(ColaBloqueante&& otra) = delete;

    ColaBloqueante(const ColaBloqueante& otra) = delete;

    ColaBloqueante& operator=(const ColaBloqueante& otra) = delete;

    ColaBloqueante& operator=(ColaBloqueante&& otra) = delete;

    public:
    ColaBloqueante() :
        detenida_(false) {
    }

    ~ColaBloqueante() {
    }

    void put(T& unElemento) {
        std::lock_guard<std::mutex> lck(mtx_);
        elementos_.push(std::move(unElemento));
        cond_.notify_one();
    }
    
    bool get(T& unElemento) {
        std::unique_lock<std::mutex> lck(mtx_);
        cond_.wait(lck, [this]{return !elementos_.empty() || detenida_ ;});
        if (detenida_) {
            return false;
        }
        unElemento = std::move(elementos_.front());
        elementos_.pop();
        return true;
    }

    void detener() {
        detenida_ = true;
        cond_.notify_all();
    }
};

#endif
