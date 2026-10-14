#ifndef REPORT_H
#define REPORT_H
#include "station.h"
/** @brief Prints station averages and the hottest reading.
 * @param stations Station metadata.
 * @param temps Flat temperature grid.
 * @param rows Number of stations.
 * @param cols Number of days.
 */
void print_report(const Station* stations, const double* temps, int rows, int cols);
#endif
