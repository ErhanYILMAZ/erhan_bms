/*********************************************************************************************************************
* DAVE APP Name : SDMMC_BLOCK       APP Version: 4.0.10
*
* NOTE:
* This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
*********************************************************************************************************************/

/**
 * @cond
 ***********************************************************************************************************************
 * Copyright (c) 2016, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes
 * with Infineon Technologies AG (dave@infineon.com).
 ***********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2016-01-20:
 *     - Initial version <br>
 *
 * 2016-02-05:
 *     - RTOS support added <br>
 *
 * 2016-04-05:
 *     - MISRA fixes.<br>
 *     - Bug fixes done for PR.<br>
 *
 * @endcond
 */

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/

#include "sdmmc_block.h"

/**********************************************************************************************************************
 * LOCAL ROUTINES
 **********************************************************************************************************************/

/* SDMMC_BLOCK configuration initialization */
static void SDMMC_BLOCK_0_Config_Init(void);


/**********************************************************************************************************************
 * EXTERNAL REFERENCES
 **********************************************************************************************************************/

extern SDMMC_BLOCK_MODE_STATUS_t
SDMMC_BLOCK_SD_ErrorInterruptHandler(SDMMC_BLOCK_t *const obj,
                                     uint16_t int_status);

extern SDMMC_BLOCK_MODE_STATUS_t
SDMMC_BLOCK_SD_NormalInterruptHandler(SDMMC_BLOCK_t *const obj,
                                      uint16_t int_status);


/**********************************************************************************************************************
 * GLOBAL VARIABLES
 **********************************************************************************************************************/

volatile uint16_t normal_int_status; /* Normal interrupt status */
volatile uint16_t err_int_status;    /* Error interrupt status */


/**********************************************************************************************************************
  * DATA STRUCTURES
 **********************************************************************************************************************/


/* SDMMC_BLOCK Data 0 pin config */
const SDMMC_BLOCK_GPIO_CONFIG_t SDMMC_BLOCK_0_DATA_0_PIN_CONFIG =
{
  .config = 
  {
    .mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
    .output_strength = XMC_GPIO_OUTPUT_STRENGTH_STRONG_MEDIUM_EDGE,
    .output_level = XMC_GPIO_OUTPUT_LEVEL_LOW,
  },
  .hw_control = XMC_GPIO_HWCTRL_PERIPHERAL1,
};

/* SDMMC_BLOCK Data 0 pin */
const SDMMC_BLOCK_PIN_CONFIG_t SDMMC_BLOCK_0_DATA_0 =
{
  .port = (XMC_GPIO_PORT_t *)PORT4_BASE,
  .pin  = (uint8_t)0,
  .config = &SDMMC_BLOCK_0_DATA_0_PIN_CONFIG
};


/* SDMMC_BLOCK Data 1 pin config */
const SDMMC_BLOCK_GPIO_CONFIG_t SDMMC_BLOCK_0_DATA_1_PIN_CONFIG =
{
  .config = 
  {
    .mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
    .output_strength = XMC_GPIO_OUTPUT_STRENGTH_STRONG_MEDIUM_EDGE,
    .output_level = XMC_GPIO_OUTPUT_LEVEL_LOW,
  },
  .hw_control = XMC_GPIO_HWCTRL_PERIPHERAL1,
};

/* SDMMC_BLOCK Data 1 pin */
const SDMMC_BLOCK_PIN_CONFIG_t SDMMC_BLOCK_0_DATA_1 =
{
  .port = (XMC_GPIO_PORT_t *)PORT1_BASE,
  .pin  = (uint8_t)6,
  .config = &SDMMC_BLOCK_0_DATA_1_PIN_CONFIG
};


/* SDMMC_BLOCK Data 2 pin config */
const SDMMC_BLOCK_GPIO_CONFIG_t SDMMC_BLOCK_0_DATA_2_PIN_CONFIG =
{
  .config = 
  {
    .mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
    .output_strength = XMC_GPIO_OUTPUT_STRENGTH_STRONG_MEDIUM_EDGE,
    .output_level = XMC_GPIO_OUTPUT_LEVEL_LOW,
  },
  .hw_control = XMC_GPIO_HWCTRL_PERIPHERAL1,
};

/* SDMMC_BLOCK Data 2 pin */
const SDMMC_BLOCK_PIN_CONFIG_t SDMMC_BLOCK_0_DATA_2 =
{
  .port = (XMC_GPIO_PORT_t *)PORT1_BASE,
  .pin  = (uint8_t)7,
  .config = &SDMMC_BLOCK_0_DATA_2_PIN_CONFIG
};


/* SDMMC_BLOCK Data 3 pin config */
const SDMMC_BLOCK_GPIO_CONFIG_t SDMMC_BLOCK_0_DATA_3_PIN_CONFIG =
{
  .config = 
  {
    .mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
    .output_strength = XMC_GPIO_OUTPUT_STRENGTH_STRONG_MEDIUM_EDGE,
    .output_level = XMC_GPIO_OUTPUT_LEVEL_LOW,
  },
  .hw_control = XMC_GPIO_HWCTRL_PERIPHERAL1,
};

/* SDMMC_BLOCK Data 3 pin */
const SDMMC_BLOCK_PIN_CONFIG_t SDMMC_BLOCK_0_DATA_3 =
{
  .port = (XMC_GPIO_PORT_t *)PORT4_BASE,
  .pin  = (uint8_t)1,
  .config = &SDMMC_BLOCK_0_DATA_3_PIN_CONFIG
};


/* SDMMC_BLOCK Command pin config */
const SDMMC_BLOCK_GPIO_CONFIG_t SDMMC_BLOCK_0_COMMAND_PIN_CONFIG =
{
  .config = 
  {
    .mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
    .output_strength = XMC_GPIO_OUTPUT_STRENGTH_STRONG_MEDIUM_EDGE,
    .output_level = XMC_GPIO_OUTPUT_LEVEL_LOW,
  },
  .hw_control = XMC_GPIO_HWCTRL_PERIPHERAL1,
};

/* SDMMC_BLOCK Command pin */
const SDMMC_BLOCK_PIN_CONFIG_t SDMMC_BLOCK_0_COMMAND =
{
  .port = (XMC_GPIO_PORT_t *)PORT3_BASE,
  .pin  = (uint8_t)5,
  .config = &SDMMC_BLOCK_0_COMMAND_PIN_CONFIG
};


/* SDMMC_BLOCK Clock pin config */
const SDMMC_BLOCK_GPIO_CONFIG_t SDMMC_BLOCK_0_CLK_PIN_CONFIG =
{
  .config = 
  {
    .mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
    .output_strength = XMC_GPIO_OUTPUT_STRENGTH_STRONG_MEDIUM_EDGE,
    .output_level = XMC_GPIO_OUTPUT_LEVEL_LOW,
  },
  .hw_control = XMC_GPIO_HWCTRL_PERIPHERAL1,
};

/* SDMMC_BLOCK Clock pin */
const SDMMC_BLOCK_PIN_CONFIG_t SDMMC_BLOCK_0_CLK =
{
  .port = (XMC_GPIO_PORT_t *)PORT3_BASE,
  .pin  = (uint8_t)6,
  .config = &SDMMC_BLOCK_0_CLK_PIN_CONFIG
};


/* SDMMC SD mode instance */
SDMMC_BLOCK_SD_t SDMMC_BLOCK_0_SD =
{
  .sdmmc = XMC_SDMMC, /* SDMMC instance */
  .int_priority = 63U, /* Node interrupt priority */
  .int_sub_priority = 0U, /* Node interrupt sub-priority */
  .mode_init_flag = false, /* Mode initialization false by default */
  .systimer = &SYSTIMER_0 /* SYSTIMER APP instance */
};

/* SDMMC_BLOCK APP instance */
SDMMC_BLOCK_t SDMMC_BLOCK_0 =
{
  .interface_mode = SDMMC_BLOCK_CARD_INTERFACE_SD, /* SD interface */
  .sdmmc_sd = &SDMMC_BLOCK_0_SD, /* SDMMC_SD instance */
  .rtos_mode = SDMMC_BLOCK_RTOS_MODE_DISABLED, /* RTOS mose is not used */

  #if SDMMC_BLOCK_RTOS_MODE_SELECT
  .cmsis_rtos = NULL, /* RTOS mose is not used */
  #endif /* SDMMC_BLOCK_RTOS_MODE_SELECT */

  .init_pins = SDMMC_BLOCK_0_Config_Init, /* true: Initialized; false: Uninitialized */
  .init_flag = false, /* true: Initialized; false: Uninitialized */
  .card_state = ((uint8_t)SDMMC_BLOCK_CARD_STATE_NOT_INITIALIZED |
                 (uint8_t)SDMMC_BLOCK_CARD_STATE_NO_CARD) /* Card state */
};

/**********************************************************************************************************************
 * FUNCTION DEFINITIONS
 **********************************************************************************************************************/

/* SDMMC SD interrupt handler */
void SDMMC0_0_IRQHandler(void)
{
  normal_int_status = SDMMC_BLOCK_0.sdmmc_sd->sdmmc->INT_STATUS_NORM;
  err_int_status = SDMMC_BLOCK_0.sdmmc_sd->sdmmc->INT_STATUS_ERR;

  if (normal_int_status & SDMMC_INT_STATUS_NORM_ERR_INT_Msk)
  {
    SDMMC_BLOCK_SD_ErrorInterruptHandler(&SDMMC_BLOCK_0, err_int_status);
  }

  if (normal_int_status & SDMMC_BLOCK_NORMAL_INT_STATUS_BITS)
  {
    SDMMC_BLOCK_SD_NormalInterruptHandler(&SDMMC_BLOCK_0, normal_int_status);
  }
}

/*
 * Configuration initialization:
 * For pins and other mode specific settings
 */
static void SDMMC_BLOCK_0_Config_Init(void)
{
  /* Enable delay on command and data lines */
  XMC_SDMMC_EnableDelayCmdDatLines();

  /* Set the delay value chosen in the APP user interface */
  XMC_SDMMC_SetDelay(SDMMC_BLOCK_SD_NUM_DELAY_ELEMENTS);

  XMC_GPIO_Init(SDMMC_BLOCK_0_COMMAND.port,
                SDMMC_BLOCK_0_COMMAND.pin,
                &SDMMC_BLOCK_0_COMMAND.config->config);
  XMC_GPIO_SetHardwareControl(SDMMC_BLOCK_0_COMMAND.port,
                              SDMMC_BLOCK_0_COMMAND.pin,
                              SDMMC_BLOCK_0_COMMAND.config->hw_control);

  XMC_GPIO_Init(SDMMC_BLOCK_0_CLK.port,
                SDMMC_BLOCK_0_CLK.pin,
                &SDMMC_BLOCK_0_CLK.config->config);
  XMC_GPIO_SetHardwareControl(SDMMC_BLOCK_0_CLK.port,
                              SDMMC_BLOCK_0_CLK.pin,
                              SDMMC_BLOCK_0_CLK.config->hw_control);

  XMC_GPIO_Init(SDMMC_BLOCK_0_DATA_0.port,
                SDMMC_BLOCK_0_DATA_0.pin,
                &SDMMC_BLOCK_0_DATA_0.config->config);
  XMC_GPIO_SetHardwareControl(SDMMC_BLOCK_0_DATA_0.port,
                              SDMMC_BLOCK_0_DATA_0.pin,
                              SDMMC_BLOCK_0_DATA_0.config->hw_control);

  XMC_GPIO_Init(SDMMC_BLOCK_0_DATA_1.port,
                SDMMC_BLOCK_0_DATA_1.pin,
                &SDMMC_BLOCK_0_DATA_1.config->config);
  XMC_GPIO_SetHardwareControl(SDMMC_BLOCK_0_DATA_1.port,
                              SDMMC_BLOCK_0_DATA_1.pin,
                              SDMMC_BLOCK_0_DATA_1.config->hw_control);
  
  XMC_GPIO_Init(SDMMC_BLOCK_0_DATA_2.port,
                SDMMC_BLOCK_0_DATA_2.pin,
                &SDMMC_BLOCK_0_DATA_2.config->config);
  XMC_GPIO_SetHardwareControl(SDMMC_BLOCK_0_DATA_2.port,
                              SDMMC_BLOCK_0_DATA_2.pin,
                              SDMMC_BLOCK_0_DATA_2.config->hw_control);

  XMC_GPIO_Init(SDMMC_BLOCK_0_DATA_3.port,
                SDMMC_BLOCK_0_DATA_3.pin,
                &SDMMC_BLOCK_0_DATA_3.config->config);
  XMC_GPIO_SetHardwareControl(SDMMC_BLOCK_0_DATA_3.port,
                              SDMMC_BLOCK_0_DATA_3.pin,
                              SDMMC_BLOCK_0_DATA_3.config->hw_control);
}
