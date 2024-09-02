#ifndef UNITFLOW_H
#define UNITFLOW_H

#include <iostream>
#include <cmath>
#include <cstring>
#include <assert.h>

#include "../../src/flow.h"
#include "../../src/flowExponential.h"
#include "../../src/flowLogistic.h"
#include "../../src/systemImplementation.h"
#include "../../src/system.h"
#include "../../src/model.h"
#include "../../src/modelImplementation.h"

/**
 *@brief This function run the unit test of the flow
 */
void run_unit_test_flow();

/**
 *@brief This function does the unit test of the constructor
 */
void unit_flow_constructor();

/**
 *@brief This function does the unit test of the destructor
 */
void unit_flow_destructor();

/**
 *@brief This function does the unit test of the getId
 */
void unit_flow_getId();

/**
 *@brief This function does the unit test of the setId
 */
void unit_flow_setId();

/**
 *@brief This function does the unit test of the getSource
 */
void unit_flow_getSource();

/**
 *@brief This function does the unit test of the setSource
 */
void unit_flow_setSource();

/**
 *@brief This function does the unit test of the getDestiny
 */
void unit_flow_getDestiny();

/**
 *@brief This function does the unit test of the setDestiny
 */
void unit_flow_setDestiny();

/**
 *@brief This function does the unit test of the execute
 */
void unit_flow_execute();

#endif // UNITFLOW_H