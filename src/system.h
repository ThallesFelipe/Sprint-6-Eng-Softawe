#ifndef SYSTEM_H
#define SYSTEM_H

#include <ostream>
#include <string>

using namespace std;

class System
{
public:
    /**
     * @brief Destroy the System object
     *
     */
    virtual ~System() {};

    /**
     * @brief Get the Id object
     *
     * @return string
     */
    virtual string getId() const = 0;

    /**
     * @brief Set the Id object
     *
     * @param id
     */
    virtual void setId(const string id) = 0;

    /**
     * @brief Get the Value object
     *
     * @return double
     */
    virtual double getValue() const = 0;

    /**
     * @brief Set the Value object
     *
     * @param value
     */
    virtual void setValue(double value = 0.0) = 0;
};

#endif // SYSTEM_H