#pragma once
#include "stdint.h"

class Arithmetic
{
public:
    Arithmetic();
    void add(int32_t num);
    void sub(int32_t num);
    void mul(int32_t num);
    void div(int32_t num);
    int32_t getTotal();

private:
    int32_t total;
};
