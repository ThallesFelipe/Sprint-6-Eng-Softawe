#ifndef FLOWEXPONENTIAL_H
#define FLOWEXPONENTIAL_H

#include "flowImplementation.h"

class FlowExponentialImplementation : public FlowImplementation
{
public:
    /**
     * @brief Construct a new Flow Exponential Implementation object
     *
     */
    FlowExponentialImplementation();

    /**
     * @brief Construct a new Flow Exponential Implementation object
     *
     * @param obj
     */
    FlowExponentialImplementation(FlowExponentialImplementation &obj);

    /**
     * @brief Construct a new Flow Exponential Implementation object
     *
     * @param id
     * @param source
     * @param destiny
     */
    FlowExponentialImplementation(const string id, System *source, System *destiny);

    /**
     * @brief Destroy the Flow Exponential Implementation object
     *
     */
    virtual ~FlowExponentialImplementation();

    /**
     * @brief
     *
     * @return float
     */
    virtual float execute();
};

#endif // FLOWEXPONENTIAL_H