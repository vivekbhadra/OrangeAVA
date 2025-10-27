// sensor_calibrator_foreach.cpp
// Demonstrates using a functor with std::for_each to process and print calibrated sensor readings.

#include <algorithm>
#include <iostream>
#include <vector>

// Define a functor for sensor calibration
struct SensorCalibrator
{
    double calibrationFactor;

    // Constructor to set the calibration factor
    SensorCalibrator(double factor) : calibrationFactor(factor)
    {
    }

    // Overloaded function call operator to perform calibration
    double operator()(double rawValue) const
    {
        return rawValue * calibrationFactor - 273.15;
    }
};

int main()
{
    // Raw sensor readings (simulated)
    std::vector<double> rawReadings = { 546.3, 548.1, 547.2, 549.0 };

    // Create a functor object with a specific calibration factor
    SensorCalibrator calibrator(0.5);

    std::cout << "Raw Sensor Readings: ";
    for (double val : rawReadings)
        std::cout << val << " ";
    std::cout << '\n';

    std::cout << "Calibrated Readings (Celsius): ";

    // Use std::for_each with the functor to print calibrated values
    std::for_each(rawReadings.begin(), rawReadings.end(),
                  [&calibrator](double raw) { std::cout << calibrator(raw) << " "; });

    std::cout << '\n';
    return 0;
}
