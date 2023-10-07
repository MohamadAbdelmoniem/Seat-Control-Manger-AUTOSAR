/**
 *
 * \file SWC_InclineMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_InclineMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/21/2023 07:02 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_InclineMotor.h"


/**
 *
 * Runnable RE_InclineMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSWC_InclineMotor_Move
 *
 */

void InclineMotor_Move(StepMotorStepType Step)
{
    Std_ReturnType status;

    if (Step == PLUS)
    {
        // Move the incline motor forward
        status = Rte_Call_rpIOSetIncline_IOSetForward();
    }
    else if (Step == MINUS)
    {
        // Move the incline motor in reverse
        status = Rte_Call_rpIOSetIncline_IOSetReverse();
    }
    else
    {
        // Handle invalid or unknown step value
        status = E_NOT_OK; // Or appropriate error handling
    }

    // Check the status and handle any errors if needed
    if (status != E_OK)
    {
        // Handle the error
    }
}

