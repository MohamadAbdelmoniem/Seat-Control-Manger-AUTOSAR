/**
 *
 * \file SWC_IoHwAbs_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_IoHwAbs
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/21/2023 07:02 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_IoHwAbs.h"


/**
 *
 * Runnable IoHwAbs_ECUGet_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetHeight_IOGet
 *
 */
 #include "Dio.h" // Include DIO module header
#include "Adc.h" // Include ADC module header

/**
 * Constants for DIO Channels
 * Replace these with actual channel definitions for your hardware
 */
#define DIO_HEIGHT_FORWARD_CHANNEL 0
#define DIO_HEIGHT_REVERSE_CHANNEL 1
#define DIO_INCLINE_FORWARD_CHANNEL 2
#define DIO_INCLINE_REVERSE_CHANNEL 3
#define DIO_SLIDE_FORWARD_CHANNEL 4
#define DIO_SLIDE_REVERSE_CHANNEL 5

/**
 * Constants for ADC Channels
 * Replace these with actual channel definitions for your hardware
 */
#define ADC_HEIGHT_SENSOR_CHANNEL 0
#define ADC_INCLINE_SENSOR_CHANNEL 1
#define ADC_SLIDE_SENSOR_CHANNEL 2
#define ADC_WEIGHT_SENSOR_CHANNEL 3


void IoHwAbs_ECUGet_Height(IoPositionSensorReadingType* position)
{
    Std_ReturnType status;
    Adc_ValueGroupType adcResult;

    // Read the height sensor using ADC
    status = Adc_ReadGroup(ADC_HEIGHT_SENSOR_CHANNEL, &adcResult);

    if (status == E_OK)
    {
        // Convert ADC result to position (if needed) and update position parameter
        *position = (IoPositionSensorReadingType)adcResult;
    }
    else
    {
        // Handle ADC read error
    }
}



/**
 *
 * Runnable IoHwAbs_ECUGet_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetIncline_IOGet
 *
 */

void IoHwAbs_ECUGet_Incline(IoPositionSensorReadingType* position)
{
    Std_ReturnType status;
    Adc_ValueGroupType adcResult;

    // Read the incline sensor using ADC
    status = ReadAdcChannel(ADC_INCLINE_SENSOR_CHANNEL, &adcResult);

    if (status == E_OK)
    {
        // Convert ADC result to position (if needed) and update position parameter
        *position = (IoPositionSensorReadingType)adcResult;
    }
    else
    {
        // Handle ADC read error
    }
}



/**
 *
 * Runnable IoHwAbs_ECUGet_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetSlide_IOGet
 *
 */

void IoHwAbs_ECUGet_Slide(IoPositionSensorReadingType* position)
{
    Std_ReturnType status;
    Adc_ValueGroupType adcResult;

    // Read the slide sensor using ADC
    status = ReadAdcChannel(ADC_SLIDE_SENSOR_CHANNEL, &adcResult);

    if (status == E_OK)
    {
        // Convert ADC result to position (if needed) and update position parameter
        *position = (IoPositionSensorReadingType)adcResult;
    }
    else
    {
        // Handle ADC read error
    }
}


/**
 *
 * Runnable IoHwAbs_ECUGet_Weight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetWeight_IOGet
 *
 */

void IoHwAbs_ECUGet_Weight(IoWeightSensorReadingType* weight)
{
    Std_ReturnType status;
    Adc_ValueGroupType adcResult;

    // Read the weight sensor using ADC
    status = ReadAdcChannel(ADC_WEIGHT_SENSOR_CHANNEL, &adcResult);

    if (status == E_OK)
    {
        // Convert ADC result to weight (if needed) and update weight parameter
        *weight = (IoWeightSensorReadingType)adcResult;
    }
    else
    {
        // Handle ADC read error
    }
}




/**
 *
 * Runnable IoHwAbs_ECUSetForward_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Height (void)
{
	SetDioForward(DIO_HEIGHT_FORWARD_CHANNEL);
	Std_ReturnType status;

}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetIncline_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Incline (void)
{
	SetDioForward(DIO_INCLINE_FORWARD_CHANNEL);
	Std_ReturnType status;

}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Slide (void)
{
	SetDioForward(DIO_SLIDE_FORWARD_CHANNEL);
	Std_ReturnType status;

}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Height (void)
{
	SetDioReverse(DIO_HEIGHT_REVERSE_CHANNEL);
	Std_ReturnType status;

}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetIncline_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Incline (void)
{
	SetDioReverse(DIO_INCLINE_REVERSE_CHANNEL);
	Std_ReturnType status;

}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Slide (void)
{
	SetDioReverse(DIO_SLIDE_REVERSE_CHANNEL);
	Std_ReturnType status;

}

/**
 * Function to set DIO channel to forward direction
 */
void SetDioForward(uint8_t channel)
{
    Dio_SetChannelDirection(channel, DIO_DIRECTION_FORWARD);
}

/**
 * Function to set DIO channel to reverse direction
 * 
 */
void SetDioReverse(uint8_t channel)
{
    Dio_SetChannelDirection(channel, DIO_DIRECTION_REVERSE);
}


