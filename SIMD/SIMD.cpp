#include <iostream>
#include <immintrin.h>

void mul8_scalar(float* ptr)
{
    for (int i = 0; i < 8; i++)
    {
        const float f = ptr[i];
        ptr[i] = f * f;
    }
}


void mul8_vectorized(float* ptr)
{
    __m256 f = _mm256_loadu_ps(ptr);
    f = _mm256_mul_ps(f, f);
    _mm256_storeu_ps(ptr, f);
}

int main()
{
    float arr[8] = { 0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f };
    mul8_vectorized(&arr[0]);
    return 0;
}

