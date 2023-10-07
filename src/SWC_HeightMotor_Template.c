/**
 *
 * \file SWC_HeightMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HeightMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/21/2023 07:01 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_HeightMotor.h"


/**
 *
 * Runnable RE_HeightMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHeightMotor_Move
 *
 */

void HeightMotor_Move(StepMotorStepType Step)
{
    Std_ReturnType status;

    if (Step == PLUS)
    {
        // Move the height motor forward
        status = Rte_Call_rpIOSetHeight_IOSetForward();
    }
    else if (Step == MINUS)
    {
        // Move the height motor in reverse
        status = Rte_Call_rpIOSetHeight_IOSetReverse();
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

