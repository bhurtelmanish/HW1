#ifndef STATION_H
#define STATION_H
#include <string>
struct Station { std::string name; double elevation_ft; };
/** @brief Finds the first station matching a name.
 * @param stations Pointer to the station array.
 * @param count Number of stations.
 * @param name Exact, case-sensitive name to find.
 * @return Pointer to the first match or nullptr.
 */
const Station* find_station(const Station* stations, int count, const std::string& name);
#endif
