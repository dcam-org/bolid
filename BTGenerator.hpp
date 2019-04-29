#ifndef GN_HPP__ 
#define GN_HPP__


#include "BTBolide.hpp"
#include <pthread.h>


class BTGenerator {
public:
    BTBolideData* getData() {
        return &data_;
    }
    void setData(BTBolideData data) {
        data_ = data;
    }
    void generate();
    void run(int dt);

private:
    BTBolideData data_;
    int dt_;    //milliseconds
    bool running_;

};


#endif
