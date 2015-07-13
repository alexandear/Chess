#pragma once

#include <initializer_list>
#include <stdexcept>

#include <QPair>

class Coordinate
{
public:
    explicit Coordinate(const QPair<int, int>& t_pair)
        : m_data(t_pair)
    {
    }

    Coordinate(std::initializer_list<int> l)
    {
        if (l.size() != 2)
            throw std::invalid_argument("initializer list should contain "
                                        "only two elements");
        m_data.first = *l.begin();
        m_data.second = *(l.begin() + 1);
    }

    int rank() const { return m_data.first; }
    void setRank(int t_rank) { m_data.first = t_rank; }
    int file() const { return m_data.second; }
    void setFile(int t_file) { m_data.second = t_file; }

private:
    QPair<int, int> m_data;
};
