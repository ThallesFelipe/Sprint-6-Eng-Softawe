#ifndef FLOW_H
#define FLOW_H

#include <iostream>
#include <string>

#include "system.h"

using namespace std;

class Flow
{
public:
    /**
     * @brief Destroy the Flow object
     *
     */
    virtual ~Flow() {};

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
     * @brief Get the Source object
     *
     * @return System*
     */
    virtual System *getSource() const = 0;

    /**
     * @brief Set the Source object
     *
     * @param source
     */
    virtual void setSource(System *source) = 0;

    /**
     * @brief Get the Destiny object
     *
     * @return System*
     */
    virtual System *getDestiny() const = 0;

    /**
     * @brief Set the Destiny object
     *
     * @param destiny
     */
    virtual void setDestiny(System *destiny) = 0;

    /**
     * @brief
     *
     * @return float
     */
    virtual float execute() = 0;
};

#endif // FLOW_H