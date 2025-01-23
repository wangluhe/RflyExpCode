/*
 * File: Exp4_AttitudeSystemCodeGen.h
 *
 * Code generated for Simulink model 'Exp4_AttitudeSystemCodeGen'.
 *
 * Model version                  : 10.0
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Jan 23 10:38:07 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Exp4_AttitudeSystemCodeGen_h_
#define RTW_HEADER_Exp4_AttitudeSystemCodeGen_h_
#ifndef Exp4_AttitudeSystemCodeGen_COMMON_INCLUDES_
#define Exp4_AttitudeSystemCodeGen_COMMON_INCLUDES_
#include <uORB/topics/input_rc.h>
#include <px4_platform_common/px4_config.h>
#include <px4_platform_common/tasks.h>
#include <px4_platform_common/posix.h>
#include <unistd.h>
#include <stdio.h>
#include <poll.h>
#include <string.h>
#include <px4_platform_common/defines.h>
#include <uORB/uORB.h>
#include <drivers/drv_hrt.h>
#include <drivers/drv_board_led.h>
#include <uORB/topics/led_control.h>
#include <stdlib.h>
#include <nuttx/config.h>
#include <nuttx/sched.h>
#include <systemlib/err.h>
#include <uORB/topics/actuator_outputs.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/vehicle_angular_velocity.h>
#include <uORB/topics/manual_control_setpoint.h>
#include "rtwtypes.h"
#endif                         /* Exp4_AttitudeSystemCodeGen_COMMON_INCLUDES_ */

#include "Exp4_AttitudeSystemCodeGen_types.h"
#include <stddef.h>
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

typedef struct pollfd pollfd_t;
typedef struct led_control_s led_control_s_t;
typedef struct actuator_outputs_s actuator_outputs_s_t;
typedef struct pollfd pollfd_t;
typedef struct manual_control_setpoint_s manual_control_setpoint_SL;

/* Block signals for system '<S9>/MATLAB Function1' */
typedef struct {
  real_T y;                            /* '<S9>/MATLAB Function1' */
} B_MATLABFunction1_Exp4_Attitu_T;

/* Block signals (default storage) */
typedef struct {
  manual_control_setpoint_SL NormalizedRCSignals;/* '<Root>/Normalized RC Signals' */
  real_T DigitalClock;                 /* '<Root>/Digital Clock' */
  real32_T q[4];                       /* '<Root>/vehicle_attitude1' */
  real32_T DataTypeConversion1[16];    /* '<Root>/Data Type Conversion1' */
  real_T y;                            /* '<S9>/MATLAB Function' */
  real_T Sum;                          /* '<S152>/Sum' */
  real_T Saturation_o;                 /* '<S150>/Saturation' */
  real_T Sum21;                        /* '<S8>/Sum21' */
  real_T Sum_n;                        /* '<S200>/Sum' */
  real_T Saturation;                   /* '<S198>/Saturation' */
  real_T Sum19;                        /* '<S8>/Sum19' */
  real_T Sum_l;                        /* '<S56>/Sum' */
  real_T Saturation_p;                 /* '<S54>/Saturation' */
  real_T Sum22;                        /* '<S8>/Sum22' */
  real_T Sum_c;                        /* '<S104>/Sum' */
  real_T Saturation_a;                 /* '<S102>/Saturation' */
  real_T Sum17;                        /* '<S8>/Sum17' */
  real_T Sum_i;                        /* '<S248>/Sum' */
  real_T Saturation_m;                 /* '<S246>/Saturation' */
  real_T rtb_Switch_idx_0;
  real_T rtb_Switch_idx_1;
  real32_T vehicle_attitude1_o1;       /* '<Root>/vehicle_attitude1' */
  real32_T vehicle_attitude1_o2;       /* '<Root>/vehicle_attitude1' */
  real32_T vehicle_attitude1_o3;       /* '<Root>/vehicle_attitude1' */
  RGBLED_MODE_ENUM Switch;             /* '<S3>/Switch' */
  RGBLED_COLOR_ENUM Switch1;           /* '<S3>/Switch1' */
  uint16_T input_rc1;                  /* '<Root>/input_rc1' */
  B_MATLABFunction1_Exp4_Attitu_T sf_MATLABFunction3;/* '<S9>/MATLAB Function3' */
  B_MATLABFunction1_Exp4_Attitu_T sf_MATLABFunction2;/* '<S9>/MATLAB Function2' */
  B_MATLABFunction1_Exp4_Attitu_T sf_MATLABFunction1;/* '<S9>/MATLAB Function1' */
} B_Exp4_AttitudeSystemCodeGen_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  actuator_outputs_s_t uORBWriteAdvanced_uorb_msg;/* '<Root>/uORB Write Advanced' */
  led_control_s_t RGB_LED_sl_led_control_s;/* '<Root>/RGB_LED' */
  pollfd_t input_rc1_input_rc_fd;      /* '<Root>/input_rc1' */
  pollfd_t vehicle_attitude1_angeuler_fd;/* '<Root>/vehicle_attitude1' */
  pollfd_t vehicle_attitude1_angrad_fd;/* '<Root>/vehicle_attitude1' */
  pollfd_t NormalizedRCSignals_uORB_fd;/* '<Root>/Normalized RC Signals' */
  real_T Integrator_DSTATE;            /* '<S143>/Integrator' */
  real_T Integrator_DSTATE_d;          /* '<S191>/Integrator' */
  real_T Integrator_DSTATE_a;          /* '<S47>/Integrator' */
  real_T Integrator_DSTATE_n;          /* '<S95>/Integrator' */
  real_T Integrator_DSTATE_nu;         /* '<S239>/Integrator' */
  orb_advert_t RGB_LED_orb_advert_t;   /* '<Root>/RGB_LED' */
  orb_advert_t uORBWriteAdvanced_uorb_advert;/* '<Root>/uORB Write Advanced' */
} DW_Exp4_AttitudeSystemCodeGen_T;

/* Real-time Model Data Structure */
struct tag_RTM_Exp4_AttitudeSystemCo_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_Exp4_AttitudeSystemCodeGen_T Exp4_AttitudeSystemCodeGen_B;

/* Block states (default storage) */
extern DW_Exp4_AttitudeSystemCodeGen_T Exp4_AttitudeSystemCodeGen_DW;

/* Model entry point functions */
extern void Exp4_AttitudeSystemCodeGen_initialize(void);
extern void Exp4_AttitudeSystemCodeGen_step(void);
extern void Exp4_AttitudeSystemCodeGen_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Exp4_AttitudeSystemC_T *const Exp4_AttitudeSystemCodeGen_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Exp4_AttitudeSystemCodeGen'
 * '<S1>'   : 'Exp4_AttitudeSystemCodeGen/MapToPWMs'
 * '<S2>'   : 'Exp4_AttitudeSystemCodeGen/Mixer'
 * '<S3>'   : 'Exp4_AttitudeSystemCodeGen/RGB_Mode_Subsystem'
 * '<S4>'   : 'Exp4_AttitudeSystemCodeGen/Subsystem1'
 * '<S5>'   : 'Exp4_AttitudeSystemCodeGen/quat2eul'
 * '<S6>'   : 'Exp4_AttitudeSystemCodeGen/Mixer/pwm_out2'
 * '<S7>'   : 'Exp4_AttitudeSystemCodeGen/Subsystem1/ARMINGControl'
 * '<S8>'   : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl'
 * '<S9>'   : 'Exp4_AttitudeSystemCodeGen/Subsystem1/InputConditioning'
 * '<S10>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/ARMINGControl/Compare To Constant3'
 * '<S11>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude'
 * '<S12>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate'
 * '<S13>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude'
 * '<S14>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate'
 * '<S15>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate'
 * '<S16>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Anti-windup'
 * '<S17>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/D Gain'
 * '<S18>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Filter'
 * '<S19>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Filter ICs'
 * '<S20>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/I Gain'
 * '<S21>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Ideal P Gain'
 * '<S22>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Ideal P Gain Fdbk'
 * '<S23>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Integrator'
 * '<S24>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Integrator ICs'
 * '<S25>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/N Copy'
 * '<S26>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/N Gain'
 * '<S27>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/P Copy'
 * '<S28>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Parallel P Gain'
 * '<S29>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Reset Signal'
 * '<S30>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Saturation'
 * '<S31>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Saturation Fdbk'
 * '<S32>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Sum'
 * '<S33>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Sum Fdbk'
 * '<S34>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Tracking Mode'
 * '<S35>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Tracking Mode Sum'
 * '<S36>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Tsamp - Integral'
 * '<S37>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Tsamp - Ngain'
 * '<S38>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/postSat Signal'
 * '<S39>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/preSat Signal'
 * '<S40>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Anti-windup/Back Calculation'
 * '<S41>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/D Gain/Disabled'
 * '<S42>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Filter/Disabled'
 * '<S43>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Filter ICs/Disabled'
 * '<S44>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/I Gain/Internal Parameters'
 * '<S45>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Ideal P Gain/Passthrough'
 * '<S46>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Ideal P Gain Fdbk/Disabled'
 * '<S47>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Integrator/Discrete'
 * '<S48>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Integrator ICs/Internal IC'
 * '<S49>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/N Copy/Disabled wSignal Specification'
 * '<S50>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/N Gain/Disabled'
 * '<S51>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/P Copy/Disabled'
 * '<S52>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Parallel P Gain/Internal Parameters'
 * '<S53>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Reset Signal/Disabled'
 * '<S54>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Saturation/Enabled'
 * '<S55>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Saturation Fdbk/Disabled'
 * '<S56>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Sum/Sum_PI'
 * '<S57>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Sum Fdbk/Disabled'
 * '<S58>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Tracking Mode/Disabled'
 * '<S59>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Tracking Mode Sum/Passthrough'
 * '<S60>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Tsamp - Integral/Passthrough'
 * '<S61>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/Tsamp - Ngain/Passthrough'
 * '<S62>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/postSat Signal/Forward_Path'
 * '<S63>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_attitude/preSat Signal/Forward_Path'
 * '<S64>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Anti-windup'
 * '<S65>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/D Gain'
 * '<S66>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Filter'
 * '<S67>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Filter ICs'
 * '<S68>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/I Gain'
 * '<S69>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Ideal P Gain'
 * '<S70>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Ideal P Gain Fdbk'
 * '<S71>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Integrator'
 * '<S72>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Integrator ICs'
 * '<S73>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/N Copy'
 * '<S74>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/N Gain'
 * '<S75>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/P Copy'
 * '<S76>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Parallel P Gain'
 * '<S77>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Reset Signal'
 * '<S78>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Saturation'
 * '<S79>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Saturation Fdbk'
 * '<S80>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Sum'
 * '<S81>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Sum Fdbk'
 * '<S82>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Tracking Mode'
 * '<S83>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Tracking Mode Sum'
 * '<S84>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Tsamp - Integral'
 * '<S85>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Tsamp - Ngain'
 * '<S86>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/postSat Signal'
 * '<S87>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/preSat Signal'
 * '<S88>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Anti-windup/Back Calculation'
 * '<S89>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/D Gain/Disabled'
 * '<S90>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Filter/Disabled'
 * '<S91>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Filter ICs/Disabled'
 * '<S92>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/I Gain/Internal Parameters'
 * '<S93>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Ideal P Gain/Passthrough'
 * '<S94>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Ideal P Gain Fdbk/Disabled'
 * '<S95>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Integrator/Discrete'
 * '<S96>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Integrator ICs/Internal IC'
 * '<S97>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/N Copy/Disabled wSignal Specification'
 * '<S98>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/N Gain/Disabled'
 * '<S99>'  : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/P Copy/Disabled'
 * '<S100>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Parallel P Gain/Internal Parameters'
 * '<S101>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Reset Signal/Disabled'
 * '<S102>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Saturation/Enabled'
 * '<S103>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Saturation Fdbk/Disabled'
 * '<S104>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Sum/Sum_PI'
 * '<S105>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Sum Fdbk/Disabled'
 * '<S106>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Tracking Mode/Disabled'
 * '<S107>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Tracking Mode Sum/Passthrough'
 * '<S108>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Tsamp - Integral/Passthrough'
 * '<S109>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/Tsamp - Ngain/Passthrough'
 * '<S110>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/postSat Signal/Forward_Path'
 * '<S111>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/pitch_rate/preSat Signal/Forward_Path'
 * '<S112>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Anti-windup'
 * '<S113>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/D Gain'
 * '<S114>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Filter'
 * '<S115>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Filter ICs'
 * '<S116>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/I Gain'
 * '<S117>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Ideal P Gain'
 * '<S118>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Ideal P Gain Fdbk'
 * '<S119>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Integrator'
 * '<S120>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Integrator ICs'
 * '<S121>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/N Copy'
 * '<S122>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/N Gain'
 * '<S123>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/P Copy'
 * '<S124>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Parallel P Gain'
 * '<S125>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Reset Signal'
 * '<S126>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Saturation'
 * '<S127>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Saturation Fdbk'
 * '<S128>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Sum'
 * '<S129>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Sum Fdbk'
 * '<S130>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Tracking Mode'
 * '<S131>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Tracking Mode Sum'
 * '<S132>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Tsamp - Integral'
 * '<S133>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Tsamp - Ngain'
 * '<S134>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/postSat Signal'
 * '<S135>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/preSat Signal'
 * '<S136>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Anti-windup/Back Calculation'
 * '<S137>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/D Gain/Disabled'
 * '<S138>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Filter/Disabled'
 * '<S139>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Filter ICs/Disabled'
 * '<S140>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/I Gain/Internal Parameters'
 * '<S141>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Ideal P Gain/Passthrough'
 * '<S142>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Ideal P Gain Fdbk/Disabled'
 * '<S143>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Integrator/Discrete'
 * '<S144>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Integrator ICs/Internal IC'
 * '<S145>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/N Copy/Disabled wSignal Specification'
 * '<S146>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/N Gain/Disabled'
 * '<S147>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/P Copy/Disabled'
 * '<S148>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Parallel P Gain/Internal Parameters'
 * '<S149>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Reset Signal/Disabled'
 * '<S150>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Saturation/Enabled'
 * '<S151>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Saturation Fdbk/Disabled'
 * '<S152>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Sum/Sum_PI'
 * '<S153>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Sum Fdbk/Disabled'
 * '<S154>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Tracking Mode/Disabled'
 * '<S155>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Tracking Mode Sum/Passthrough'
 * '<S156>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Tsamp - Integral/Passthrough'
 * '<S157>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/Tsamp - Ngain/Passthrough'
 * '<S158>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/postSat Signal/Forward_Path'
 * '<S159>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_attitude/preSat Signal/Forward_Path'
 * '<S160>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Anti-windup'
 * '<S161>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/D Gain'
 * '<S162>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Filter'
 * '<S163>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Filter ICs'
 * '<S164>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/I Gain'
 * '<S165>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Ideal P Gain'
 * '<S166>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Ideal P Gain Fdbk'
 * '<S167>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Integrator'
 * '<S168>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Integrator ICs'
 * '<S169>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/N Copy'
 * '<S170>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/N Gain'
 * '<S171>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/P Copy'
 * '<S172>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Parallel P Gain'
 * '<S173>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Reset Signal'
 * '<S174>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Saturation'
 * '<S175>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Saturation Fdbk'
 * '<S176>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Sum'
 * '<S177>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Sum Fdbk'
 * '<S178>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Tracking Mode'
 * '<S179>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Tracking Mode Sum'
 * '<S180>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Tsamp - Integral'
 * '<S181>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Tsamp - Ngain'
 * '<S182>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/postSat Signal'
 * '<S183>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/preSat Signal'
 * '<S184>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Anti-windup/Back Calculation'
 * '<S185>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/D Gain/Disabled'
 * '<S186>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Filter/Disabled'
 * '<S187>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Filter ICs/Disabled'
 * '<S188>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/I Gain/Internal Parameters'
 * '<S189>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Ideal P Gain/Passthrough'
 * '<S190>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Ideal P Gain Fdbk/Disabled'
 * '<S191>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Integrator/Discrete'
 * '<S192>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Integrator ICs/Internal IC'
 * '<S193>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/N Copy/Disabled wSignal Specification'
 * '<S194>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/N Gain/Disabled'
 * '<S195>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/P Copy/Disabled'
 * '<S196>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Parallel P Gain/Internal Parameters'
 * '<S197>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Reset Signal/Disabled'
 * '<S198>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Saturation/Enabled'
 * '<S199>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Saturation Fdbk/Disabled'
 * '<S200>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Sum/Sum_PI'
 * '<S201>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Sum Fdbk/Disabled'
 * '<S202>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Tracking Mode/Disabled'
 * '<S203>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Tracking Mode Sum/Passthrough'
 * '<S204>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Tsamp - Integral/Passthrough'
 * '<S205>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/Tsamp - Ngain/Passthrough'
 * '<S206>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/postSat Signal/Forward_Path'
 * '<S207>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/roll_rate/preSat Signal/Forward_Path'
 * '<S208>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Anti-windup'
 * '<S209>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/D Gain'
 * '<S210>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Filter'
 * '<S211>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Filter ICs'
 * '<S212>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/I Gain'
 * '<S213>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Ideal P Gain'
 * '<S214>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Ideal P Gain Fdbk'
 * '<S215>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Integrator'
 * '<S216>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Integrator ICs'
 * '<S217>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/N Copy'
 * '<S218>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/N Gain'
 * '<S219>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/P Copy'
 * '<S220>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Parallel P Gain'
 * '<S221>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Reset Signal'
 * '<S222>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Saturation'
 * '<S223>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Saturation Fdbk'
 * '<S224>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Sum'
 * '<S225>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Sum Fdbk'
 * '<S226>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Tracking Mode'
 * '<S227>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Tracking Mode Sum'
 * '<S228>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Tsamp - Integral'
 * '<S229>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Tsamp - Ngain'
 * '<S230>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/postSat Signal'
 * '<S231>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/preSat Signal'
 * '<S232>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Anti-windup/Back Calculation'
 * '<S233>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/D Gain/Disabled'
 * '<S234>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Filter/Disabled'
 * '<S235>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Filter ICs/Disabled'
 * '<S236>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/I Gain/Internal Parameters'
 * '<S237>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Ideal P Gain/Passthrough'
 * '<S238>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Ideal P Gain Fdbk/Disabled'
 * '<S239>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Integrator/Discrete'
 * '<S240>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Integrator ICs/Internal IC'
 * '<S241>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/N Copy/Disabled wSignal Specification'
 * '<S242>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/N Gain/Disabled'
 * '<S243>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/P Copy/Disabled'
 * '<S244>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Parallel P Gain/Internal Parameters'
 * '<S245>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Reset Signal/Disabled'
 * '<S246>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Saturation/Enabled'
 * '<S247>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Saturation Fdbk/Disabled'
 * '<S248>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Sum/Sum_PI'
 * '<S249>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Sum Fdbk/Disabled'
 * '<S250>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Tracking Mode/Disabled'
 * '<S251>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Tracking Mode Sum/Passthrough'
 * '<S252>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Tsamp - Integral/Passthrough'
 * '<S253>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/Tsamp - Ngain/Passthrough'
 * '<S254>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/postSat Signal/Forward_Path'
 * '<S255>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/AttitudeControl/yaw_rate/preSat Signal/Forward_Path'
 * '<S256>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/InputConditioning/MATLAB Function'
 * '<S257>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/InputConditioning/MATLAB Function1'
 * '<S258>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/InputConditioning/MATLAB Function2'
 * '<S259>' : 'Exp4_AttitudeSystemCodeGen/Subsystem1/InputConditioning/MATLAB Function3'
 */
#endif                            /* RTW_HEADER_Exp4_AttitudeSystemCodeGen_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
