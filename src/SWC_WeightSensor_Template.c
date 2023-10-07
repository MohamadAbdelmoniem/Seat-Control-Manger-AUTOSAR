/**
 *
 * \file SWC_WeightSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_WeightSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/21/2023 07:02 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_WeightSensor.h"


/**
 *
 * Runnable WeightSensor_GetWeight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppWeightSensor_GetWeight
 *
 */

void WeightSensor_GetWeight(IoWeightSensorReadingType* weight)
{
    Std_ReturnType status;
    IoWeightSensorReadingType sensorReading;

    /* Server Call Points */
    status = Rte_Call_rpIOGetWeight_IOGet(&sensorReading);

    if (status == E_OK)
    {
        // Convert sensor reading to weight (divide by 1000)
        *weight = sensorReading / 1000;
    }
    else
    {
        // Handle error if necessary
    }
}


