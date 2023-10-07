/**
 *
 * \file SWC_SideMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SideMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/21/2023 07:02 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_SideMotor.h"


/**
 *
 * Runnable RE_SideMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSWC_SideMotor_Move
 *
 */
void SlideMotor_Move(StepMotorStepType Step)
{
    Std_ReturnType status;

    if (Step == PLUS)
    {
        // Move the slide motor forward
        status = Rte_Call_rpIOSetSlide_IOSetForward();
    }
    else if (Step == MINUS)
    {
        // Move the slide motor in reverse
        status = Rte_Call_rpIOSetSlide_IOSetReverse();
    }
    else
    {
        // Handle invalid or unknown step value
        status = E_NOT_OK; // Or appropriate error handling
    }

    // Check the status and handle any errors if needed
    if (status != E_OK)
    {
        // Handle the error (e.g., log, set error flag, etc.)
    }
}


