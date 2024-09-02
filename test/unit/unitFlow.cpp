#include "unitFlow.h"

void unit_flow_constructor()
{
    System *system1 = new SystemHandle();
    System *system2 = new SystemHandle();

    // Exponential
    Flow *flowExp1 = new FlowHandle<FlowExponentialImplementation>();
    assert(flowExp1->getId() == "NULL");
    assert(flowExp1->getSource() == NULL);
    assert(flowExp1->getDestiny() == NULL);

    Flow *flowExp2 = new FlowHandle<FlowExponentialImplementation>("test", system1, system2);
    assert(flowExp2->getId() == "test");
    assert(flowExp2->getSource() == system1);
    assert(flowExp2->getDestiny() == system2);

    // Logistic
    Flow *flowLogist1 = new FlowHandle<FlowLogisticImplementation>();
    assert(flowLogist1->getId() == "NULL");
    assert(flowLogist1->getSource() == NULL);
    assert(flowLogist1->getDestiny() == NULL);

    Flow *flowLogist2 = new FlowHandle<FlowLogisticImplementation>("test", system1, system2);
    assert(flowLogist2->getId() == "test");
    assert(flowLogist2->getSource() == system1);
    assert(flowLogist2->getDestiny() == system2);

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowExp2;
    delete flowLogist1;
    delete flowLogist2;
};

void unit_flow_destructor() {};

void unit_flow_getId()
{
    System *system1 = new SystemHandle();
    System *system2 = new SystemHandle();

    // Exponential
    Flow *flowExp1 = new FlowHandle<FlowExponentialImplementation>("test", system1, system2);
    assert(flowExp1->getId() == "test");

    // Logistic
    Flow *flowLogist1 = new FlowHandle<FlowLogisticImplementation>("test", system1, system2);
    assert(flowLogist1->getId() == "test");

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowLogist1;
};

void unit_flow_setId()
{
    // Exponential
    Flow *flowExp1 = new FlowHandle<FlowExponentialImplementation>();
    flowExp1->setId("test");
    assert(flowExp1->getId() == "test");

    // Logistic
    Flow *flowLogist1 = new FlowHandle<FlowLogisticImplementation>();
    flowLogist1->setId("test");
    assert(flowLogist1->getId() == "test");

    delete flowExp1;
    delete flowLogist1;
};

void unit_flow_getSource()
{
    System *system1 = new SystemHandle();
    System *system2 = new SystemHandle();

    // Exponential
    Flow *flowExp1 = new FlowHandle<FlowExponentialImplementation>("test", system1, system2);
    assert(flowExp1->getSource() == system1);

    // Logistic
    Flow *flowLogist1 = new FlowHandle<FlowLogisticImplementation>("test", system1, system2);
    assert(flowLogist1->getSource() == system1);

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowLogist1;
};

void unit_flow_setSource()
{
    System *system1 = new SystemHandle();
    System *system2 = new SystemHandle();
    System *system3 = new SystemHandle();

    // Exponential
    Flow *flowExp1 = new FlowHandle<FlowExponentialImplementation>("test", system1, system2);
    flowExp1->setSource(system3);
    assert(flowExp1->getSource() == system3);

    // Logistic
    Flow *flowLogist1 = new FlowHandle<FlowLogisticImplementation>("test", system1, system2);
    flowLogist1->setSource(system3);
    assert(flowLogist1->getSource() == system3);

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowLogist1;
};

void unit_flow_getDestiny()
{
    System *system1 = new SystemHandle();
    System *system2 = new SystemHandle();

    // Exponential
    Flow *flowExp1 = new FlowHandle<FlowExponentialImplementation>("test", system1, system2);
    assert(flowExp1->getDestiny() == system2);

    // Logistic
    Flow *flowLogist1 = new FlowHandle<FlowLogisticImplementation>("test", system1, system2);
    assert(flowLogist1->getDestiny() == system2);

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowLogist1;
};

void unit_flow_setDestiny()
{
    System *system1 = new SystemHandle();
    System *system2 = new SystemHandle();
    System *system3 = new SystemHandle();

    // Exponential
    Flow *flowExp1 = new FlowHandle<FlowExponentialImplementation>("test", system1, system2);
    flowExp1->setDestiny(system3);
    assert(flowExp1->getDestiny() == system3);

    // Logistic
    Flow *flowLogist1 = new FlowHandle<FlowLogisticImplementation>("test", system1, system2);
    flowLogist1->setDestiny(system3);
    assert(flowLogist1->getDestiny() == system3);

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowLogist1;
};

void unit_flow_execute()
{
    System *system1 = new SystemHandle("", 100.00);
    System *system2 = new SystemHandle("", 0.0);
    Model *model = new ModelHandle();

    // Exponential
    Flow *flowExp1 = new FlowHandle<FlowExponentialImplementation>("test", system1, system2);
    model->add(system1);
    model->add(system2);
    model->add(flowExp1);

    model->execute(0, 100, 1);

    assert(abs(system1->getValue() - 36.6032) < 0.0001);
    assert(abs(system2->getValue() - 63.3968) < 0.0001);

    model->clear();

    // Logistic
    system1->setValue(100.0);
    system2->setValue(10.0);
    Flow *flowLogist1 = new FlowHandle<FlowLogisticImplementation>("test", system1, system2);
    model->add(system1);
    model->add(system2);
    model->add(flowLogist1);

    model->execute(0, 100, 1);

    assert(abs(system1->getValue() - 88.2167) < 0.0001f);
    assert(abs(system2->getValue() - 21.7834) < 0.0001f);

    model->clear();

    delete system1;
    delete system2;
    delete flowExp1;
    delete flowLogist1;
    delete model;
};

void run_unit_test_flow()
{
    unit_flow_constructor();
    unit_flow_destructor();
    unit_flow_getId();
    unit_flow_setId();
    unit_flow_getSource();
    unit_flow_setSource();
    unit_flow_getDestiny();
    unit_flow_setDestiny();
    unit_flow_execute();
};