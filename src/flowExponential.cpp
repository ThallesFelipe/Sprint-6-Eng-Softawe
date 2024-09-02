#include "flowExponential.h"

FlowExponentialImplementation::FlowExponentialImplementation()
{
    id = "NULL";
    source = NULL;
    destiny = NULL;
};

FlowExponentialImplementation::FlowExponentialImplementation(FlowExponentialImplementation &obj)
{
    if (&obj == this)
        return;

    id = obj.getId();
    source = obj.getSource();
    destiny = obj.getDestiny();
};

FlowExponentialImplementation::FlowExponentialImplementation(const string id, System *source, System *destiny) : FlowImplementation(id, source, destiny) {};
FlowExponentialImplementation::~FlowExponentialImplementation() {};

float FlowExponentialImplementation::execute()
{
    return getSource()->getValue() * 0.01;
};