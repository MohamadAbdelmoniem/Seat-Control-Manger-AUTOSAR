/**
 *
 * \file SWC_HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/21/2023 09:11 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_HMI.h"


/**
 *
 * Runnable RE_HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_HMI_MainFunction_100ms
 *
 */

void RE_HMI_MainFunction (void)
{
	Std_ReturnType status;
	MultiStateBtnType DE_HeightBtnState;
	MultiStateBtnType DE_InclineBtnState;
	MultiStateBtnType DE_SlideBtnState;
	uint8 DE_Height;
	uint8 DE_Incline;
	uint8 DE_Slide;

	/* Data Send Points */
	status = Rte_Write_ppSeatCtrlBtns_DE_HeightBtnState(DE_HeightBtnState);
	status = Rte_Write_ppSeatCtrlBtns_DE_InclineBtnState(DE_InclineBtnState);
	status = Rte_Write_ppSeatCtrlBtns_DE_SlideBtnState(DE_SlideBtnState);
	
	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlData_DE_Height(&DE_Height);
	status = Rte_Read_rpSeatCtrlData_DE_Incline(&DE_Incline);
	status = Rte_Read_rpSeatCtrlData_DE_Slide(&DE_Slide);
	
}


/**
 *
 * Runnable HMI_SeatModeChanged
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatModeBtn_SeatModeBtn
 *
 */

void HMI_SeatModeChanged(void)
{
    Std_ReturnType status;
    SeatModeBtnType SeatModeBtn;
    uint8 SeatCtrlMode;

    /* Data Receive Points */
    status = Rte_Read_rpSeatModeBtn_SeatModeBtn(&SeatModeBtn);

    /* Set SeatCtrlMode based on SeatModeBtn */
    if (status == E_OK)
    {
        if (SeatModeBtn == SEAT_MODE_BTN_MANUAL)
        {
            SeatCtrlMode = RTE_MODE_SeatCtrlMode_MANUAL;
        }
        else if (SeatModeBtn == SEAT_MODE_BTN_AUTO)
        {
            SeatCtrlMode = RTE_MODE_SeatCtrlMode_AUTO;
        }
        else
        {
            SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;
        }

        /* Mode Switch Points */
        status = Rte_Switch_ppSeatCtrlMode_SeatCtrlMode(SeatCtrlMode);
        if (status != E_OK)
        {
            // Handle mode switch error
        }
    }
    else
    {
        // Handle data receive error if needed
    }
}


