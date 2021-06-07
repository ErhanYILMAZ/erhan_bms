/**
 * @file global_can.h
 * @date 2015-06-30
 *
 * NOTE:
 * This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
 *
 * @cond
 ***********************************************************************************************************************
 * GLOBAL_CAN v4.0.12 - Configures global resources of MultiCAN module.
 *
 * Copyright (c) 2015, Infineon Technologies AG
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
 * 2015-02-16:
 *     - Initial version<br>
 *
 * 2015-06-18:
 *     - LLD version check is removed.<br>
 *     - Version check added for XMCLib dependency.<br>
 *
 * 2015-06-30:
 *     - GLOBAL_CAN_Enable() and GLOBAL_CAN_Disable() APIs are removed.<br>
 *
 * @endcond
 *
 */

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/

#ifndef GLOBAL_CAN_H
#define GLOBAL_CAN_H

#include <xmc_can.h>
#include "global_can_conf.h"
#include <DAVE_Common.h>

/**********************************************************************************************************************
 * MACROS
 **********************************************************************************************************************/

#if (!((XMC_LIB_MAJOR_VERSION == 2U) && \
       (XMC_LIB_MINOR_VERSION >= 0U) && \
       (XMC_LIB_PATCH_VERSION >= 0U)))
#error "GLOBAL_CAN requires XMC Peripheral Library v2.0.0 or higher"
#endif

/**********************************************************************************************************************
 * ENUMS
 **********************************************************************************************************************/
/**
 * @ingroup GLOBAL_CAN_enumerations
 * @{
 */

/**
 *  enum to describe the possible status values, returned by GLOBAL_CAN APIs.
 */
typedef enum GLOBAL_CAN_STATUS
{
  GLOBAL_CAN_STATUS_SUCCESS = 0,  /**< APP success state */
  GLOBAL_CAN_STATUS_FAILURE       /**< Returned when error occurred */
} GLOBAL_CAN_STATUS_t;

/**
 * @}
 */

/**********************************************************************************************************************
* DATA STRUCTURES
**********************************************************************************************************************/

/**
 * @ingroup GLOBAL_CAN_datastructures
 * @{
 */

/**
 *  @brief Initialization data structure for GLOBAL_CAN APP
 */
typedef struct GLOBAL_CAN
{
  uint32_t can_frequency;
  XMC_CAN_t* canglobal_ptr;
  uint8_t can_clock_src;
  bool init_status;
}GLOBAL_CAN_t;

/**
 * @}
 */

/***********************************************************************************************************************
* API Prototypes
**********************************************************************************************************************/
/* Support for C++ codebase */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup GLOBAL_CAN_apidoc
 * @{
 */

/**
 * @brief Function to read the GLOBAL_CAN APP version.
 *
 * @return DAVE_APP_VERSION_t Structure that contains the members,
 *         major, minor and patch values.
 *
 * \par<b>Description:</b><br>
 * The function can be used to check application software compatibility with a
 * specific version of the APP.
 *
 * Example Usage:
 * @code
 *   #include <DAVE.h>         //Declarations from DAVE Code Generation (includes SFR declaration)
 *
 *   int main(void)
 *   {
 *     DAVE_STATUS_t init_status;
 *     DAVE_APP_VERSION_t can_version;
 *     init_status = DAVE_Init();
 *     if (init_status == DAVE_STATUS_SUCCESS)
 *     {
 *       can_version = GLOBAL_CAN_GetAppVersion();
 *       if ((can_version.major == 4U) &&
 *          (can_version.minor == 0U))
 *       {
 *         // Application code
 *       }
 *       else
 *       {
 *         // Probably, not the right version.
 *       }
 *     }
 *     while(1U) //more code here
 *     {
 *     }
 *      return (1);
 *  }
 *  @endcode
 */
DAVE_APP_VERSION_t GLOBAL_CAN_GetAppVersion(void);

/**
 * @brief Function to initialize the CAN clock configuration for the required CAN peripheral frequency.
 * @param handle of type GLOBAL_CAN_t is a pointer pointing to APP data structure.
 * @return status of type GLOBAL_CAN_STATUS_t.
 *
 * \par<b>Description:</b><br>
 *
 * Details of function:
 * This function enables the CAN module and sets the CAN module clock frequency.<br>
 *
 * Example Usage:
 * @code
 *   #include <DAVE.h>         //Declarations from DAVE Code Generation (includes SFR declaration)
 *
 *   int main(void)
 *   {
 *     GLOBAL_CAN_STATUS_t global_can_status;
 *     GLOBAL_CAN_t *global_can_handle = &GLOBAL_CAN_0;
 *
 *     global_can_status = GLOBAL_CAN_Init(global_can_handle);
 *     if (global_can_handle->init_status == true && global_can_status == GLOBAL_CAN_STATUS_SUCCESS)
 *     {
 *       // Initialize the can node
 *
 *       // Application code
 *     }
 *     else
 *     {
 *      XMC_DEBUG("main: Application initialization failed");
 *      while(1U)
 *      {
 *      }
 *     }
 *      return (1);
 *  }
 *  @endcode
 */
GLOBAL_CAN_STATUS_t GLOBAL_CAN_Init(GLOBAL_CAN_t *handle);


/**
 * @}
 */

#include"global_can_extern.h"

/* Support for C++ codebase */
#ifdef __cplusplus
}
#endif   

#endif /* End of GLOBAL_CAN_H */

