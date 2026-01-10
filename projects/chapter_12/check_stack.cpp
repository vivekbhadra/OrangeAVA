#include <iostream>
#include <pthread.h>
#include <iomanip>

int main()
{
    pthread_attr_t attr;
    size_t stacksize;

    if (pthread_attr_init(&attr) != 0)
    {
        std::cerr << "Failed to initialise thread attributes.\n";
        return 1;
    }

    if (pthread_attr_getstacksize(&attr, &stacksize) == 0)
    {
        double stack_mb = static_cast<double>(stacksize) / (1024 * 1024);

        std::cout << "Default thread stack size: " << stacksize << " bytes ("
                  << std::fixed << std::setprecision(2) << stack_mb << " MB)\n";
    }
    else
    {
        std::cerr << "Failed to get stack size.\n";
    }

    pthread_attr_destroy(&attr);
    return 0;
}

