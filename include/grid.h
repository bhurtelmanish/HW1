#ifndef GRID_H
#define GRID_H
/** @brief Converts row and column to a flat index.
 * @param row Zero-based row.
 * @param col Zero-based column.
 * @param cols Number of columns.
 * @return Flat index without bounds checking.
 */
int grid_index(int row, int col, int cols);
/** @brief Checks grid coordinates.
 * @param row Candidate row.
 * @param col Candidate column.
 * @param rows Number of rows.
 * @param cols Number of columns.
 * @return Whether the coordinates are in bounds.
 */
bool in_bounds(int row, int col, int rows, int cols);
#endif
