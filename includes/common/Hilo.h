#ifndef _THREAD_H_
#define _THREAD_H_

#include <thread>

class Hilo {
    private:
    std::thread hilo_;
 
    public:
    Hilo();
    
    void start();

    virtual void run() = 0;

    virtual void join();

    virtual ~Hilo() {}

    Hilo(const Hilo&) = delete;

    Hilo& operator=(const Hilo&) = delete;

    Hilo(Hilo&& other);

    Hilo& operator=(Hilo&& other);
};

#endif
