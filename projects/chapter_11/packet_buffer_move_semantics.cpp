// packet_buffer_move_semantics.cpp
// Demonstrates move semantics with a PacketBuffer class that manages dynamic memory.
// This example includes constructors, destructors, and copy/move assignment operators.
// It shows how resources are transferred efficiently using move semantics.
#include <cstring>
#include <iostream>

class PacketBuffer
{
    char *data; // Dynamic array for packet data
    size_t size;

  public:
    // Constructor
    PacketBuffer(size_t n) : data(new char[n]), size(n)
    {
        std::cout << "Allocated buffer of size " << size << "\n";
    }

    // Copy constructor
    PacketBuffer(const PacketBuffer &other) : data(new char[other.size]), size(other.size)
    {
        std::memcpy(data, other.data, size);
        std::cout << "Copied buffer of size " << size << "\n";
    }

    // Move constructor
    PacketBuffer(PacketBuffer &&other) noexcept : data(other.data), size(other.size)
    {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Moved buffer of size " << size << "\n";
    }

    // Copy assignment operator
    PacketBuffer &operator=(const PacketBuffer &other)
    {
        if (this != &other)
        {
            delete[] data;
            data = new char[other.size];
            size = other.size;
            std::memcpy(data, other.data, size);
            std::cout << "Copy-assigned buffer of size " << size << "\n";
        }
        return *this;
    }

    // Move assignment operator
    PacketBuffer &operator=(PacketBuffer &&other) noexcept
    {
        if (this != &other)
        {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
            std::cout << "Move-assigned buffer of size " << size << "\n";
        }
        return *this;
    }

    // Destructor
    ~PacketBuffer()
    {
        delete[] data;
        std::cout << "Deallocated buffer of size " << size << "\n";
    }

    size_t getSize() const
    {
        return size;
    }
};

int main()
{
    PacketBuffer buffer1(1024);                                 // Allocate buffer
    PacketBuffer buffer2 = buffer1;                             // Copy constructor
    PacketBuffer buffer3 = std::move(buffer1);                  // Move constructor
    std::cout << "buffer1 size: " << buffer1.getSize() << "\n"; // Moved-from state
    std::cout << "buffer3 size: " << buffer3.getSize() << "\n";

    PacketBuffer buffer4(512);
    buffer4 = buffer2;                                          // Copy assignment
    buffer4 = std::move(buffer3);                               // Move assignment
    std::cout << "buffer3 size: " << buffer3.getSize() << "\n"; // Moved-from state
    std::cout << "buffer4 size: " << buffer4.getSize() << "\n";
    return 0;
}