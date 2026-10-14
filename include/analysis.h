#ifndef ANALYSIS_H
#define ANALYSIS_H
/** @brief Computes one station's average.
 * @param temps Flat temperature grid.
 * @param rows Number of stations.
 * @param cols Number of days.
 * @param station Station index.
 * @param average Output, unchanged on failure.
 * @return Whether the request is valid.
 */
bool station_average(const double* temps, int rows, int cols, int station, double& average);
/** @brief Computes one day's average.
 * @param temps Flat temperature grid.
 * @param rows Number of stations.
 * @param cols Number of days.
 * @param day Day index.
 * @param average Output, unchanged on failure.
 * @return Whether the request is valid.
 */
bool day_average(const double* temps, int rows, int cols, int day, double& average);
/** @brief Locates the first maximum in row-major order.
 * @param temps Flat temperature grid.
 * @param rows Number of stations.
 * @param cols Number of days.
 * @param hot_row Output row, unchanged on failure.
 * @param hot_col Output column, unchanged on failure.
 * @return Whether the grid is nonempty.
 */
bool find_hottest(const double* temps, int rows, int cols, int& hot_row, int& hot_col);
/** @brief Counts readings strictly greater than a threshold.
 * @param temps Flat temperature grid.
 * @param rows Number of stations.
 * @param cols Number of days.
 * @param threshold Exclusive lower bound.
 * @return Number of readings above the threshold.
 */
int count_above(const double* temps, int rows, int cols, double threshold);
#endif
