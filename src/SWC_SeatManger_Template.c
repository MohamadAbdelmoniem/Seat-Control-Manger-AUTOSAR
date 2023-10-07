/**
 *
 * \file SWC_SeatManger_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SeatManger
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/21/2023 04:28 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_SeatManger.h"

#define SENSOR_POSITION_STEP_0 0
#define SENSOR_POSITION_STEP_1 1
#define SENSOR_POSITION_STEP_2 2
#define SENSOR_POSITION_STEP_3 3


/**
 *
 * Runnable RE_SeatManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_SeatManager_AutoHeight_200ms
 *
 */
void RE_SeatManager_AutoHeight(void)
{
    Std_ReturnType status;
    StepMotorStepType Step;
    SensorPositionType position;
    SensorWeightType weight;

    /* Server Call Points */
    status = Rte_Call_rpWeightSensor_GetWeight(&weight);
    status = Rte_Call_rpHeightSensor_GetPosition(&position);

    if (weight > 100)
    {
        /* Set Increment/decrement Height until sensor position = SENSOR_POSITION_STEP_3 */
        while (position != SENSOR_POSITION_STEP_3)
        {
            status = Rte_Call_rpHeightMotor_Move(Step);
            status = Rte_Call_rpHeightSensor_GetPosition(&position);
        }
    }
    else if (weight >= 80 && weight <= 100)
    {
        /* Set Increment/decrement Height until sensor position = SENSOR_POSITION_STEP_2 */
        while (position != SENSOR_POSITION_STEP_2)
        {
            status = Rte_Call_rpHeightMotor_Move(Step);
            status = Rte_Call_rpHeightSensor_GetPosition(&position);
        }
    }
    else if (weight >= 60 && weight < 80)
    {
        /* Set Increment/decrement Height until sensor position = SENSOR_POSITION_STEP_1 */
        while (position != SENSOR_POSITION_STEP_1)
        {
            status = Rte_Call_rpHeightMotor_Move(Step);
            status = Rte_Call_rpHeightSensor_GetPosition(&position);
        }
    }
    else
    {
        /* Set Increment/decrement Height until sensor position = SENSOR_POSITION_STEP_0 */
        while (position != SENSOR_POSITION_STEP_0)
        {
            status = Rte_Call_rpHeightMotor_Move(Step);
            status = Rte_Call_rpHeightSensor_GetPosition(&position);
        }
    }
}

/**
 *
 * Runnable RE_SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_SeatManager_AutoIncline_200ms
 *
 */

void RE_SeatManager_AutoIncline(void)
{
    Std_ReturnType status;
    StepMotorStepType Step;
    SensorPositionType position;
    SensorWeightType weight;

    /* Server Call Points */
    status = Rte_Call_rpWeightSensor_GetWeight(&weight);
    status = Rte_Call_rpInclineSensor_GetPosition(&position);

    if (weight > 100)
    {
        /* Set Increment/decrement Incline until sensor position = SENSOR_POSITION_STEP_3 */
        while (position != SENSOR_POSITION_STEP_3)
        {
            status = Rte_Call_rpInclineMotor_Move(Step);
            status = Rte_Call_rpInclineSensor_GetPosition(&position);
        }
    }
    else if (weight >= 80 && weight <= 100)
    {
        /* Set Increment/decrement Incline until sensor position = SENSOR_POSITION_STEP_2 */
        while (position != SENSOR_POSITION_STEP_2)
        {
            status = Rte_Call_rpInclineMotor_Move(Step);
            status = Rte_Call_rpInclineSensor_GetPosition(&position);
        }
    }
    else if (weight >= 60 && weight < 80)
    {
        /* Set Increment/decrement Incline until sensor position = SENSOR_POSITION_STEP_1 */
        while (position != SENSOR_POSITION_STEP_1)
        {
            status = Rte_Call_rpInclineMotor_Move(Step);
            status = Rte_Call_rpInclineSensor_GetPosition(&position);
        }
    }
    else
    {
        /* Set Increment/decrement Incline until sensor position = SENSOR_POSITION_STEP_0 */
        while (position != SENSOR_POSITION_STEP_0)
        {
            status = Rte_Call_rpInclineMotor_Move(Step);
            status = Rte_Call_rpInclineSensor_GetPosition(&position);
        }
    }
}

/**
 *
 * Runnable RE_SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_SeatManager_AutoSlide_200ms
 *
 */

void RE_SeatManager_AutoSlide(void)
{
    Std_ReturnType status;
    StepMotorStepType Step;
    SensorPositionType position;
    SensorWeightType weight;

    /* Server Call Points */
    status = Rte_Call_rpWeightSensor_GetWeight(&weight);
    status = Rte_Call_rpSlideSensor_GetPosition(&position);

    if (weight > 100)
    {
        /* Set Increment/decrement Slide until sensor position = SENSOR_POSITION_STEP_3 */
        while (position != SENSOR_POSITION_STEP_3)
        {
            status = Rte_Call_rpSlideMotor_Move(Step);
            status = Rte_Call_rpSlideSensor_GetPosition(&position);
        }
    }
    else if (weight >= 80 && weight <= 100)
    {
        /* Set Increment/decrement Slide until sensor position = SENSOR_POSITION_STEP_2 */
        while (position != SENSOR_POSITION_STEP_2)
        {
            status = Rte_Call_rpSlideMotor_Move(Step);
            status = Rte_Call_rpSlideSensor_GetPosition(&position);
        }
    }
    else if (weight >= 60 && weight < 80)
    {
        /* Set Increment/decrement Slide until sensor position = SENSOR_POSITION_STEP_1 */
        while (position != SENSOR_POSITION_STEP_1)
        {
            status = Rte_Call_rpSlideMotor_Move(Step);
            status = Rte_Call_rpSlideSensor_GetPosition(&position);
        }
    }
    else
    {
        /* Set Increment/decrement Slide until sensor position = SENSOR_POSITION_STEP_0 */
        while (position != SENSOR_POSITION_STEP_0)
        {
            status = Rte_Call_rpSlideMotor_Move(Step);
            status = Rte_Call_rpSlideSensor_GetPosition(&position);
        }
    }
}

/**
 *
 * Runnable RE_SeatManger_SetHeigh
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_HeightBtnState
 *
 */

void RE_SeatManger_SetHeigh(void)
{
    Std_ReturnType status;
    MultiStateBtnType DE_HeightBtnState;
    StepMotorStepType Step;

    /* Data Receive Points */
    status = Rte_Read_rpSeatCtrlBtns_DE_HeightBtnState(&DE_HeightBtnState);

    /* Check button state and call the appropriate motor function */
    if (DE_HeightBtnState == MULTI_STATE_BTN_MINUS)
    {
        status = Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS);
    }
    else if (DE_HeightBtnState == MULTI_STATE_BTN_PLUS)
    {
        status = Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);
    }
}


/**
 *
 * Runnable RE_SeatManger_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_InclineBtnState
 *
 */

void RE_SeatManger_SetIncline(void)
{
    Std_ReturnType status;
    MultiStateBtnType DE_InclineBtnState;
    StepMotorStepType Step;

    /* Data Receive Points */
    status = Rte_Read_rpSeatCtrlBtns_DE_InclineBtnState(&DE_InclineBtnState);

    /* Check button state and call the appropriate motor function */
    if (DE_InclineBtnState == MULTI_STATE_BTN_MINUS)
    {
        status = Rte_Call_rpInclineMotor_Move(MOTOR_STEP_MINUS);
    }
    else if (DE_InclineBtnState == MULTI_STATE_BTN_PLUS)
    {
        status = Rte_Call_rpInclineMotor_Move(MOTOR_STEP_PLUS);
    }
}


/**
 *
 * Runnable RE_SeatManger_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_SlideBtnState
 *
 */

void RE_SeatManger_SetSlide(void)
{
    Std_ReturnType status;
    MultiStateBtnType DE_SlideBtnState;
    StepMotorStepType Step;

    /* Data Receive Points */
    status = Rte_Read_rpSeatCtrlBtns_DE_SlideBtnState(&DE_SlideBtnState);

    /* Check button state and call the appropriate motor function */
    if (DE_SlideBtnState == MULTI_STATE_BTN_MINUS)
    {
        status = Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS);
    }
    else if (DE_SlideBtnState == MULTI_STATE_BTN_PLUS)
    {
        status = Rte_Call_rpSlideMotor_Move(MOTOR_STEP_PLUS);
    }
}

