/**
 *
 * \file SWC_InclineSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_InclineSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/21/2023 07:02 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_InclineSensor.h"


/**
 *
 * Runnable InclineSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppInclineSensor_GetPosition
 *
 */
#define SENSOR_POSITION_STEP_INVALID  -1
#define SENSOR_POSITION_STEP_0        0
#define SENSOR_POSITION_STEP_1        1
#define SENSOR_POSITION_STEP_2        2
#define SENSOR_POSITION_STEP_3        3

void InclineSensor_GetPosition(SensorPositionType* sensorPosition)
{
    Std_ReturnType status;
    IoPositionSensorReadingType sensorReading;

    /* Server Call Points */
    status = Rte_Call_rpIOGetIncline_IOGet(&sensorReading);

    if (status == E_OK)
    {
        if (sensorReading == 0)
        {
            *sensorPosition = SENSOR_POSITION_STEP_0;
        }
        else if (sensorReading > 0 && sensorReading <= 64)
        {
            *sensorPosition = SENSOR_POSITION_STEP_1;
        }
        else if (sensorReading > 64 && sensorReading <= 192)
        {
            *sensorPosition = SENSOR_POSITION_STEP_2;
        }
        else if (sensorReading > 192 && sensorReading <= 255)
        {
            *sensorPosition = SENSOR_POSITION_STEP_3;
        }
        else
        {
            // Handle out-of-range sensor reading
            *sensorPosition = SENSOR_POSITION_STEP_INVALID;
        }
    }
    else
    {
        // Handle error if necessary
        *sensorPosition = SENSOR_POSITION_STEP_INVALID;
    }
}


