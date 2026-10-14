#include "report.h"
#include "analysis.h"
#include "grid.h"
#include <iomanip>
#include <iostream>
void print_report(const Station* stations, const double* temps, int rows, int cols) {
    std::cout << "=== Weather Station Report ===\n";
    for (int row = 0; row < rows; ++row) {
        double average = 0.0;
        if (station_average(temps, rows, cols, row, average)) {
            std::cout << std::left << std::setw(15) << stations[row].name
                      << std::right << std::fixed << std::setprecision(0)
                      << stations[row].elevation_ft << " ft   avg  "
                      << std::setprecision(2) << average << " F\n";
        }
    }
    int row = 0;
    int col = 0;
    if (find_hottest(temps, rows, cols, row, col)) {
        std::cout << "Hottest reading: " << std::fixed << std::setprecision(1)
                  << temps[grid_index(row, col, cols)] << " F at "
                  << stations[row].name << " (day " << col + 1 << ")\n";
    }
}
