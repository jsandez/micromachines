#ifndef _COLA_H_
#define _COLA_H_

#include <queue>

template <class T>
class Cola {
private:
    std::queue<T> elementos_;

    Cola(Cola&& otra) = delete;

    Cola(const Cola& otra) = delete;

    Cola& operator=(const Cola& otra) = delete;

    Cola& operator=(Cola&& otra) = delete;

    public:
    Cola() {
    }

    ~Cola() {
    }

    void put(T& unElemento) {
        elementos_.push(std::move(unElemento));
    }
    
    bool get(T& unElemento) {
        if (elementos_.empty()) {
            return false;
        }
        unElemento = std::move(elementos_.front());
        elementos_.pop();
        return true;
    }
};

#endif
