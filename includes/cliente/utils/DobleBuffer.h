#ifndef __DOBLE_BUFFER_H__
#define __DOBLE_BUFFER_H__


#include <mutex>


template <typename T>
class DobleBuffer {
   public:
    DobleBuffer() {}
    ~DobleBuffer() {}

    DobleBuffer& operator=(const DobleBuffer& rhs) = delete;
    DobleBuffer(const DobleBuffer& rhs) = delete;
    

    DobleBuffer(DobleBuffer&& rhs){
        this->buff2_[this->actual_] = std::move(rhs.buff2_[rhs.actual_]);
        this->buff2_[!this->actual_] = std::move(rhs.buff2_[!rhs.actual_]);
    }

    DobleBuffer& operator=(DobleBuffer&& rhs){
        this->buff2_[this->actual_] = std::move(rhs.buff2_[rhs.actual_]);
        this->buff2_[!this->actual_] = std::move(rhs.buff2_[!rhs.actual_]);
        return *this;
    }


    void swap();
    void set(T& objeto);
    void get(T& objeto);


   private:
    T buff2_[2];
    int actual_{0};
    std::mutex mtx_;
};

template <typename T>
void DobleBuffer<T>::swap() {
    std::unique_lock<std::mutex> lock(mtx_);
    this->actual_ = !this->actual_;
}

template <typename T>
void DobleBuffer<T>::set(T& objeto) {
    std::unique_lock<std::mutex> lock(mtx_);
    this->buff2_[!this->actual_] = std::move(objeto);
}

template <typename T>
void DobleBuffer<T>::get(T& objeto) {
    std::unique_lock<std::mutex> lock(mtx_);
    objeto = std::move(this->buff2_[this->actual_]);
}


#endif
