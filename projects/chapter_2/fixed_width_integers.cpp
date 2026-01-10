// fixed_width_integers.cpp
#include <iostream>
#include <cstdint>

int main()
{
    std::uint16_t sensor_reading = 500;          // 16-bit unsigned integer
    std::int32_t distance_mm = 100000;           // 32-bit signed integer
    std::uint64_t file_size_bytes = 8000000000ULL; // 64-bit unsigned integer

    std::cout << "Size of uint16_t: " << sizeof(sensor_reading) << " bytes\n";
    std::cout << "Size of int32_t: " << sizeof(distance_mm) << " bytes\n";
    std::cout << "Size of uint64_t: " << sizeof(file_size_bytes) << " bytes\n";

    return 0;
}

