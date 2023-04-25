/**
 * @file ParkingBill.cpp
 * @brief Given two strings representing times of entry and exit from a car
 * parking lot, find the cost of the ticket according to the given billing
 * rules.
 *
 * https://app.codility.com/programmers/trainings/5/parking_bill/
 */
#include <cmath>
#include <string>

int solution(std::string& E, std::string& L)
{
    int e_hours = std::stoi(E.substr(0, 2));
    int e_minutes = std::stoi(E.substr(3, 2));
    int l_hours = std::stoi(L.substr(0, 2));
    int l_minutes = std::stoi(L.substr(3, 2));

    int duration = ((l_hours * 60) + l_minutes) - ((e_hours * 60) + e_minutes);

    uint32_t cost{2};
    if (duration > 0)
    {
        cost += 3;
        duration -= 60;
    }

    cost += std::ceil(static_cast<double>(duration) / 60) * 4;
    return cost;
}
