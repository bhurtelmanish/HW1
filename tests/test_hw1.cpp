#include <gtest/gtest.h>
#include "grid.h"
#include "analysis.h"
#include "station.h"
TEST(GridIndex, FlatPositions) {
    EXPECT_EQ(grid_index(2, 3, 7), 17);
    EXPECT_EQ(grid_index(0, 0, 7), 0);
    EXPECT_EQ(grid_index(1, 0, 7), 7);
}
TEST(InBounds, BoundaryCases) {
    EXPECT_TRUE(in_bounds(0, 0, 2, 3));
    EXPECT_TRUE(in_bounds(1, 2, 2, 3));
    EXPECT_FALSE(in_bounds(2, 2, 2, 3));
    EXPECT_FALSE(in_bounds(1, 3, 2, 3));
    EXPECT_FALSE(in_bounds(-1, 0, 2, 3));
    EXPECT_FALSE(in_bounds(0, -1, 2, 3));
    EXPECT_FALSE(in_bounds(0, 0, 0, 3));
}
TEST(StationAverage, ValidAndInvalid) {
    const double temps[] = {10, 20, 30, 40, 50, 60};
    double avg = 999;
    EXPECT_TRUE(station_average(temps, 2, 3, 1, avg));
    EXPECT_DOUBLE_EQ(avg, 50.0);
    EXPECT_FALSE(station_average(temps, 2, 3, 2, avg));
    EXPECT_DOUBLE_EQ(avg, 50.0);
    EXPECT_FALSE(station_average(temps, 2, 0, 0, avg));
    EXPECT_DOUBLE_EQ(avg, 50.0);
    EXPECT_FALSE(station_average(temps, 2, 3, -1, avg));
}
TEST(DayAverage, ValidAndInvalid) {
    const double temps[] = {10, 20, 30, 40, 50, 60};
    double avg = 999;
    EXPECT_TRUE(day_average(temps, 2, 3, 2, avg));
    EXPECT_DOUBLE_EQ(avg, 45.0);
    EXPECT_FALSE(day_average(temps, 2, 3, 3, avg));
    EXPECT_DOUBLE_EQ(avg, 45.0);
    EXPECT_FALSE(day_average(temps, 0, 3, 0, avg));
    EXPECT_DOUBLE_EQ(avg, 45.0);
}
TEST(FindHottest, MaximumTieAndEmpty) {
    const double temps[] = {99, 20, 30, 99};
    int row = -1;
    int col = -1;
    EXPECT_TRUE(find_hottest(temps, 2, 2, row, col));
    EXPECT_EQ(row, 0);
    EXPECT_EQ(col, 0);
    row = 7;
    col = 8;
    EXPECT_FALSE(find_hottest(temps, 0, 2, row, col));
    EXPECT_EQ(row, 7);
    EXPECT_EQ(col, 8);
}
TEST(CountAbove, StrictAndEmpty) {
    const double temps[] = {90, 95, 96, 97, 95, 99};
    EXPECT_EQ(count_above(temps, 2, 3, 95), 3);
    EXPECT_EQ(count_above(temps, 2, 3, 100), 0);
    EXPECT_EQ(count_above(temps, 0, 3, 95), 0);
}
TEST(FindStation, ExactMatchAndMissing) {
    const Station stations[] = {{"Denton", 642}, {"Waco", 470}};
    const Station* result = find_station(stations, 2, "Waco");
    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->name, "Waco");
    EXPECT_DOUBLE_EQ(result->elevation_ft, 470);
    EXPECT_EQ(find_station(stations, 2, "waco"), nullptr);
    EXPECT_EQ(find_station(stations, 2, "Austin"), nullptr);
    EXPECT_EQ(find_station(stations, 0, "Waco"), nullptr);
}
