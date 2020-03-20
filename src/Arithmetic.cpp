#include "Arithemtic.h"

Arithmetic::Arithmetic()
{
    total = 0;
};

void Arithmetic::add(int32_t num)
{
    total += num;
};

void Arithmetic::sub(int32_t num)
{
    total -= num;
};

void Arithmetic::mul(int32_t num)
{
    total *= num;
};

void Arithmetic::div(int32_t num)
{
    total /= num;
};

int32_t Arithmetic::getTotal()
{
    auto temp = total;
    total = 0;
    return temp;
};
