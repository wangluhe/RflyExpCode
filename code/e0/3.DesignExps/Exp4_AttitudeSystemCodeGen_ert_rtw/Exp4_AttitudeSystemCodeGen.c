/*
 * File: Exp4_AttitudeSystemCodeGen.c
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

#include "Exp4_AttitudeSystemCodeGen.h"
#include "rtwtypes.h"
#include "Exp4_AttitudeSystemCodeGen_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "Exp4_AttitudeSystemCodeGen_types.h"
#include "rt_defines.h"

/* Block signals (default storage) */
B_Exp4_AttitudeSystemCodeGen_T Exp4_AttitudeSystemCodeGen_B;

/* Block states (default storage) */
DW_Exp4_AttitudeSystemCodeGen_T Exp4_AttitudeSystemCodeGen_DW;

/* Real-time model */
static RT_MODEL_Exp4_AttitudeSystemC_T Exp4_AttitudeSystemCodeGen_M_;
RT_MODEL_Exp4_AttitudeSystemC_T *const Exp4_AttitudeSystemCodeGen_M =
  &Exp4_AttitudeSystemCodeGen_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Exp4_AttitudeSystemCodeGen_M->Timing.TaskCounters.TID[1])++;
  if ((Exp4_AttitudeSystemCodeGen_M->Timing.TaskCounters.TID[1]) > 249) {/* Sample time: [1.0s, 0.0s] */
    Exp4_AttitudeSystemCodeGen_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S9>/MATLAB Function1'
 *    '<S9>/MATLAB Function2'
 *    '<S9>/MATLAB Function3'
 */
void Exp4_AttitudeSy_MATLABFunction1(real_T rtu_u,
  B_MATLABFunction1_Exp4_Attitu_T *localB)
{
  real_T u;
  u = rtu_u;

  /* MATLAB Function 'Subsystem1/InputConditioning/MATLAB Function1': '<S257>:1' */
  /* '<S257>:1:3' */
  /* '<S257>:1:4' */
  /* '<S257>:1:5' */
  /* '<S257>:1:6' */
  if (rtu_u < 1100.0) {
    /* '<S257>:1:8' */
    /* '<S257>:1:9' */
    u = 1100.0;
  } else if (rtu_u > 1900.0) {
    /* '<S257>:1:10' */
    /* '<S257>:1:11' */
    u = 1900.0;
  }

  if (u > 1540.0) {
    /* '<S257>:1:14' */
    /* '<S257>:1:15' */
    localB->y = u;
  } else if (u < 1460.0) {
    /* '<S257>:1:16' */
    /* '<S257>:1:17' */
    localB->y = u;
  } else {
    /* '<S257>:1:19' */
    localB->y = 1500.0;
  }
}

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  int32_T u0_0;
  int32_T u1_0;
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    if (u0 > 0.0F) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0F) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = (real32_T)atan2((real32_T)u0_0, (real32_T)u1_0);
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = (real32_T)atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void Exp4_AttitudeSystemCodeGen_step(void)
{
  real_T rtb_Switch_idx_2;
  real_T rtb_Switch_idx_3;
  real_T u0;
  int32_T i;
  real32_T rtb_phi;
  real32_T theta;
  real32_T tmp;
  uint16_T rtb_DataTypeConversion6;
  boolean_T rtb_Compare;

  /* S-Function (sfun_px4_input_rc): '<Root>/input_rc1' */
  {
    bool updated;
    orb_check(Exp4_AttitudeSystemCodeGen_DW.input_rc1_input_rc_fd.fd, &updated);
    if (updated) {
      struct input_rc_s pwm_inputs;

      /* copy input_rc raw data into local buffer (uint16)*/
      orb_copy(ORB_ID(input_rc),
               Exp4_AttitudeSystemCodeGen_DW.input_rc1_input_rc_fd.fd,
               &pwm_inputs);
      Exp4_AttitudeSystemCodeGen_B.input_rc1 = pwm_inputs.values[4];
    }
  }

  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  Constant: '<S10>/Constant'
   *  DataTypeConversion: '<S4>/Conversion6'
   */
  rtb_Compare = (Exp4_AttitudeSystemCodeGen_B.input_rc1 >= 1500);

  /* RateTransition: '<Root>/Rate Transition' */
  if (Exp4_AttitudeSystemCodeGen_M->Timing.TaskCounters.TID[1] == 0) {
    /* Switch: '<S3>/Switch' incorporates:
     *  Switch: '<S3>/Switch1'
     */
    if (rtb_Compare) {
      /* Switch: '<S3>/Switch' incorporates:
       *  Constant: '<S3>/Constant'
       */
      Exp4_AttitudeSystemCodeGen_B.Switch = SL_MODE_BLINK_FAST;

      /* Switch: '<S3>/Switch1' incorporates:
       *  Constant: '<S3>/Constant3'
       */
      Exp4_AttitudeSystemCodeGen_B.Switch1 = SL_COLOR_RED;
    } else {
      /* Switch: '<S3>/Switch' incorporates:
       *  Constant: '<S3>/Constant1'
       */
      Exp4_AttitudeSystemCodeGen_B.Switch = SL_MODE_BREATHE;

      /* Switch: '<S3>/Switch1' incorporates:
       *  Constant: '<S3>/Constant2'
       */
      Exp4_AttitudeSystemCodeGen_B.Switch1 = SL_COLOR_GREEN;
    }

    /* End of Switch: '<S3>/Switch' */

    /* S-Function (sfun_px4_rgbled): '<Root>/RGB_LED' */
    Exp4_AttitudeSystemCodeGen_DW.RGB_LED_sl_led_control_s.mode =
      Exp4_AttitudeSystemCodeGen_B.Switch;
    Exp4_AttitudeSystemCodeGen_DW.RGB_LED_sl_led_control_s.color =
      Exp4_AttitudeSystemCodeGen_B.Switch1;
    Exp4_AttitudeSystemCodeGen_DW.RGB_LED_sl_led_control_s.num_blinks = 0;
    Exp4_AttitudeSystemCodeGen_DW.RGB_LED_sl_led_control_s.priority = 0;
    Exp4_AttitudeSystemCodeGen_DW.RGB_LED_sl_led_control_s.timestamp =
      hrt_absolute_time();
    orb_publish(ORB_ID(led_control),
                Exp4_AttitudeSystemCodeGen_DW.RGB_LED_orb_advert_t ,
                &Exp4_AttitudeSystemCodeGen_DW.RGB_LED_sl_led_control_s);
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* S-Function (sfun_px4_uorb_write): '<Root>/uORB Write Advanced' */
  {
    //struct actuator_outputs_s InputStruct;
    //memset( &InputStruct, 0, sizeof(InputStruct));

    /* assign input parameters to struct */
    Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_msg.timestamp = (double)
      Exp4_AttitudeSystemCodeGen_B.DigitalClock;
    Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_msg.output[0] =
      Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[0];
    Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_msg.output[1] =
      Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[1];
    Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_msg.output[2] =
      Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[2];
    Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_msg.output[3] =
      Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[3];
    Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_msg.output[4] =
      Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[4];
    Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_msg.output[5] =
      Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[5];
    Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_msg.output[6] =
      Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[6];
    Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_msg.output[7] =
      Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[7];
    Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_msg.output[8] =
      Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[8];
    Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_msg.output[9] =
      Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[9];
    Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_msg.output[10] =
      Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[10];
    Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_msg.output[11] =
      Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[11];
    Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_msg.output[12] =
      Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[12];
    Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_msg.output[13] =
      Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[13];
    Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_msg.output[14] =
      Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[14];
    Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_msg.output[15] =
      Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[15];

    /* Publish data for subscribers */
    orb_publish(ORB_ID(actuator_outputs_rfly),
                Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_advert,
                &Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_msg);
  }

  /* S-Function (sfun_px4_vehicle_attitude): '<Root>/vehicle_attitude1' */
  {
    bool updated;
    orb_check(Exp4_AttitudeSystemCodeGen_DW.vehicle_attitude1_angrad_fd.fd,
              &updated);
    if (updated) {
      struct vehicle_angular_velocity_s raw;
      orb_copy(ORB_ID(vehicle_angular_velocity),
               Exp4_AttitudeSystemCodeGen_DW.vehicle_attitude1_angrad_fd.fd,
               &raw);

      /* read out the Roll rate value */
      Exp4_AttitudeSystemCodeGen_B.vehicle_attitude1_o1 = raw.xyz[0];// phi rate

      /* read out the Pitch rate value */
      Exp4_AttitudeSystemCodeGen_B.vehicle_attitude1_o2 = raw.xyz[1];// theta rate

      /* read out the Yaw rate value */
      Exp4_AttitudeSystemCodeGen_B.vehicle_attitude1_o3 = raw.xyz[2];// psi rate
    }

    orb_check(Exp4_AttitudeSystemCodeGen_DW.vehicle_attitude1_angeuler_fd.fd,
              &updated);
    if (updated) {
      struct vehicle_attitude_s raw;
      orb_copy(ORB_ID(vehicle_attitude),
               Exp4_AttitudeSystemCodeGen_DW.vehicle_attitude1_angeuler_fd.fd,
               &raw);

      /* read out the Quaternion values */
      Exp4_AttitudeSystemCodeGen_B.q[0] = raw.q[0];
      Exp4_AttitudeSystemCodeGen_B.q[1] = raw.q[1];
      Exp4_AttitudeSystemCodeGen_B.q[2] = raw.q[2];
      Exp4_AttitudeSystemCodeGen_B.q[3] = raw.q[3];
    }
  }

  /* MATLAB Function: '<Root>/quat2eul' */
  /* MATLAB Function 'quat2eul': '<S5>:1' */
  /* '<S5>:1:12' */
  /* '<S5>:1:13' */
  /* '<S5>:1:14' */
  /* '<S5>:1:15' */
  /* '<S5>:1:17' */
  /* '<S5>:1:18' */
  /* '<S5>:1:19' */
  /* '<S5>:1:20' */
  /* '<S5>:1:22' */
  /* '<S5>:1:25' */
  /* '<S5>:1:27' */
  /* '<S5>:1:28' */
  /* '<S5>:1:30' */
  /* '<S5>:1:31' */
  /* '<S5>:1:32' */
  /* '<S5>:1:33' */
  /* '<S5>:1:36' */
  theta = (real32_T)asin(-((Exp4_AttitudeSystemCodeGen_B.q[1] *
    Exp4_AttitudeSystemCodeGen_B.q[3] - Exp4_AttitudeSystemCodeGen_B.q[0] *
    Exp4_AttitudeSystemCodeGen_B.q[2]) * 2.0F));
  if ((real32_T)fabs(theta - 1.57079637F) < 0.001) {
    /* '<S5>:1:37' */
    /* '<S5>:1:38' */
    rtb_phi = 0.0F;

    /* '<S5>:1:39' */
  } else if ((real32_T)fabs(theta + 1.57079637F) < 0.001) {
    /* '<S5>:1:40' */
    /* '<S5>:1:41' */
    rtb_phi = 0.0F;

    /* '<S5>:1:42' */
  } else {
    /* '<S5>:1:44' */
    rtb_phi = rt_atan2f_snf((Exp4_AttitudeSystemCodeGen_B.q[0] *
      Exp4_AttitudeSystemCodeGen_B.q[1] + Exp4_AttitudeSystemCodeGen_B.q[2] *
      Exp4_AttitudeSystemCodeGen_B.q[3]) * 2.0F,
      ((Exp4_AttitudeSystemCodeGen_B.q[0] * Exp4_AttitudeSystemCodeGen_B.q[0] -
        Exp4_AttitudeSystemCodeGen_B.q[1] * Exp4_AttitudeSystemCodeGen_B.q[1]) -
       Exp4_AttitudeSystemCodeGen_B.q[2] * Exp4_AttitudeSystemCodeGen_B.q[2]) +
      Exp4_AttitudeSystemCodeGen_B.q[3] * Exp4_AttitudeSystemCodeGen_B.q[3]);

    /* '<S5>:1:45' */
  }

  /* S-Function (sfun_px4_uorb_read_topic): '<Root>/Normalized RC Signals' */
  {
    //interval val: 1
    bool updated;
    orb_check(Exp4_AttitudeSystemCodeGen_DW.NormalizedRCSignals_uORB_fd.fd,
              &updated);
    if (updated) {
      /* obtained uorb data */
      /* copy sensors raw data into local buffer */
      orb_copy(ORB_ID(manual_control_setpoint),
               Exp4_AttitudeSystemCodeGen_DW.NormalizedRCSignals_uORB_fd.fd,
               &Exp4_AttitudeSystemCodeGen_B.NormalizedRCSignals);
    }
  }

  /* DataTypeConversion: '<S1>/Data Type Conversion3' incorporates:
   *  Fcn: '<S1>/Fcn2'
   */
  tmp = (real32_T)floor(Exp4_AttitudeSystemCodeGen_B.NormalizedRCSignals.y *
                        400.0F + 1500.0F);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  rtb_DataTypeConversion6 = (uint16_T)(tmp < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(uint16_T)tmp);

  /* End of DataTypeConversion: '<S1>/Data Type Conversion3' */

  /* MATLAB Function: '<S9>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S4>/Conversion2'
   */
  Exp4_AttitudeSystemCodeGen_B.y = rtb_DataTypeConversion6;

  /* MATLAB Function 'Subsystem1/InputConditioning/MATLAB Function': '<S256>:1' */
  /* '<S256>:1:3' */
  /* '<S256>:1:4' */
  /* '<S256>:1:5' */
  /* '<S256>:1:6' */
  if (rtb_DataTypeConversion6 < 1100) {
    /* '<S256>:1:8' */
    /* '<S256>:1:9' */
    Exp4_AttitudeSystemCodeGen_B.y = 1100.0;
  } else if (rtb_DataTypeConversion6 > 1900) {
    /* '<S256>:1:10' */
    /* '<S256>:1:11' */
    Exp4_AttitudeSystemCodeGen_B.y = 1900.0;
  }

  if ((!(Exp4_AttitudeSystemCodeGen_B.y > 1540.0)) &&
      (!(Exp4_AttitudeSystemCodeGen_B.y < 1460.0))) {
    /* '<S256>:1:19' */
    Exp4_AttitudeSystemCodeGen_B.y = 1500.0;
  } else {
    /* '<S256>:1:14' */
    /* '<S256>:1:15' */
    /* '<S256>:1:16' */
    /* '<S256>:1:17' */
  }

  /* End of MATLAB Function: '<S9>/MATLAB Function' */

  /* Gain: '<S9>/Gain1' incorporates:
   *  Fcn: '<S9>/Fcn2'
   */
  u0 = (Exp4_AttitudeSystemCodeGen_B.y - 1500.0) / 400.0 * 0.5;

  /* Saturate: '<S9>/Saturation9' */
  if (u0 > 1.0) {
    u0 = 1.0;
  } else if (u0 < -1.0) {
    u0 = -1.0;
  }

  /* End of Saturate: '<S9>/Saturation9' */

  /* Sum: '<S8>/Sum18' */
  Exp4_AttitudeSystemCodeGen_B.y = u0 - rtb_phi;

  /* Sum: '<S152>/Sum' incorporates:
   *  DiscreteIntegrator: '<S143>/Integrator'
   *  Gain: '<S148>/Proportional Gain'
   */
  Exp4_AttitudeSystemCodeGen_B.Sum = 0.5251155209314009 *
    Exp4_AttitudeSystemCodeGen_B.y +
    Exp4_AttitudeSystemCodeGen_DW.Integrator_DSTATE;

  /* Saturate: '<S150>/Saturation' */
  if (Exp4_AttitudeSystemCodeGen_B.Sum > 1.0) {
    Exp4_AttitudeSystemCodeGen_B.Saturation_o = 1.0;
  } else if (Exp4_AttitudeSystemCodeGen_B.Sum < -1.0) {
    Exp4_AttitudeSystemCodeGen_B.Saturation_o = -1.0;
  } else {
    Exp4_AttitudeSystemCodeGen_B.Saturation_o = Exp4_AttitudeSystemCodeGen_B.Sum;
  }

  /* End of Saturate: '<S150>/Saturation' */

  /* Sum: '<S8>/Sum21' incorporates:
   *  Gain: '<S8>/1 // rads_max'
   */
  Exp4_AttitudeSystemCodeGen_B.Sum21 = Exp4_AttitudeSystemCodeGen_B.Saturation_o
    - 0.333333343F * Exp4_AttitudeSystemCodeGen_B.vehicle_attitude1_o1;

  /* Sum: '<S200>/Sum' incorporates:
   *  DiscreteIntegrator: '<S191>/Integrator'
   *  Gain: '<S196>/Proportional Gain'
   */
  Exp4_AttitudeSystemCodeGen_B.Sum_n = 1.0961153046948584 *
    Exp4_AttitudeSystemCodeGen_B.Sum21 +
    Exp4_AttitudeSystemCodeGen_DW.Integrator_DSTATE_d;

  /* Saturate: '<S198>/Saturation' */
  if (Exp4_AttitudeSystemCodeGen_B.Sum_n > 1.0) {
    Exp4_AttitudeSystemCodeGen_B.Saturation = 1.0;
  } else if (Exp4_AttitudeSystemCodeGen_B.Sum_n < -1.0) {
    Exp4_AttitudeSystemCodeGen_B.Saturation = -1.0;
  } else {
    Exp4_AttitudeSystemCodeGen_B.Saturation = Exp4_AttitudeSystemCodeGen_B.Sum_n;
  }

  /* End of Saturate: '<S198>/Saturation' */

  /* DataTypeConversion: '<S1>/Data Type Conversion4' incorporates:
   *  Fcn: '<S1>/Fcn1'
   *  Gain: '<S1>/Gain'
   */
  tmp = (real32_T)floor(-Exp4_AttitudeSystemCodeGen_B.NormalizedRCSignals.x *
                        400.0F + 1500.0F);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* MATLAB Function: '<S9>/MATLAB Function2' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion4'
   *  DataTypeConversion: '<S4>/Conversion3'
   */
  Exp4_AttitudeSy_MATLABFunction1((real_T)(tmp < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp),
    &Exp4_AttitudeSystemCodeGen_B.sf_MATLABFunction2);

  /* Gain: '<S9>/Gain3' incorporates:
   *  Fcn: '<S9>/Fcn5'
   */
  u0 = (Exp4_AttitudeSystemCodeGen_B.sf_MATLABFunction2.y - 1500.0) / 400.0 *
    0.5;

  /* Saturate: '<S9>/Saturation8' */
  if (u0 > 1.0) {
    u0 = 1.0;
  } else if (u0 < -1.0) {
    u0 = -1.0;
  }

  /* End of Saturate: '<S9>/Saturation8' */

  /* Sum: '<S8>/Sum19' incorporates:
   *  MATLAB Function: '<Root>/quat2eul'
   */
  Exp4_AttitudeSystemCodeGen_B.Sum19 = u0 - theta;

  /* Sum: '<S56>/Sum' incorporates:
   *  DiscreteIntegrator: '<S47>/Integrator'
   *  Gain: '<S52>/Proportional Gain'
   */
  Exp4_AttitudeSystemCodeGen_B.Sum_l = 0.5251155209314009 *
    Exp4_AttitudeSystemCodeGen_B.Sum19 +
    Exp4_AttitudeSystemCodeGen_DW.Integrator_DSTATE_a;

  /* Saturate: '<S54>/Saturation' */
  if (Exp4_AttitudeSystemCodeGen_B.Sum_l > 1.0) {
    Exp4_AttitudeSystemCodeGen_B.Saturation_p = 1.0;
  } else if (Exp4_AttitudeSystemCodeGen_B.Sum_l < -1.0) {
    Exp4_AttitudeSystemCodeGen_B.Saturation_p = -1.0;
  } else {
    Exp4_AttitudeSystemCodeGen_B.Saturation_p =
      Exp4_AttitudeSystemCodeGen_B.Sum_l;
  }

  /* End of Saturate: '<S54>/Saturation' */

  /* Sum: '<S8>/Sum22' incorporates:
   *  Gain: '<S8>/1 // rads_max'
   */
  Exp4_AttitudeSystemCodeGen_B.Sum22 = Exp4_AttitudeSystemCodeGen_B.Saturation_p
    - 0.333333343F * Exp4_AttitudeSystemCodeGen_B.vehicle_attitude1_o2;

  /* Sum: '<S104>/Sum' incorporates:
   *  DiscreteIntegrator: '<S95>/Integrator'
   *  Gain: '<S100>/Proportional Gain'
   */
  Exp4_AttitudeSystemCodeGen_B.Sum_c = 1.0961153046948584 *
    Exp4_AttitudeSystemCodeGen_B.Sum22 +
    Exp4_AttitudeSystemCodeGen_DW.Integrator_DSTATE_n;

  /* Saturate: '<S102>/Saturation' */
  if (Exp4_AttitudeSystemCodeGen_B.Sum_c > 1.0) {
    Exp4_AttitudeSystemCodeGen_B.Saturation_a = 1.0;
  } else if (Exp4_AttitudeSystemCodeGen_B.Sum_c < -1.0) {
    Exp4_AttitudeSystemCodeGen_B.Saturation_a = -1.0;
  } else {
    Exp4_AttitudeSystemCodeGen_B.Saturation_a =
      Exp4_AttitudeSystemCodeGen_B.Sum_c;
  }

  /* End of Saturate: '<S102>/Saturation' */

  /* DataTypeConversion: '<S1>/Data Type Conversion5' incorporates:
   *  Fcn: '<S1>/Fcn3'
   */
  tmp = (real32_T)floor(Exp4_AttitudeSystemCodeGen_B.NormalizedRCSignals.r *
                        400.0F + 1500.0F);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* MATLAB Function: '<S9>/MATLAB Function1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion5'
   *  DataTypeConversion: '<S4>/Conversion5'
   */
  Exp4_AttitudeSy_MATLABFunction1((real_T)(tmp < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp),
    &Exp4_AttitudeSystemCodeGen_B.sf_MATLABFunction1);

  /* Gain: '<S9>/Gain4' incorporates:
   *  Fcn: '<S9>/Fcn7'
   */
  u0 = (Exp4_AttitudeSystemCodeGen_B.sf_MATLABFunction1.y - 1500.0) / 400.0 *
    0.5;

  /* Saturate: '<S9>/Saturation7' */
  if (u0 > 1.0) {
    u0 = 1.0;
  } else if (u0 < -1.0) {
    u0 = -1.0;
  }

  /* End of Saturate: '<S9>/Saturation7' */

  /* Sum: '<S8>/Sum17' */
  Exp4_AttitudeSystemCodeGen_B.Sum17 = u0 -
    Exp4_AttitudeSystemCodeGen_B.vehicle_attitude1_o3;

  /* Sum: '<S248>/Sum' incorporates:
   *  DiscreteIntegrator: '<S239>/Integrator'
   *  Gain: '<S244>/Proportional Gain'
   */
  Exp4_AttitudeSystemCodeGen_B.Sum_i = 2.1922306093897168 *
    Exp4_AttitudeSystemCodeGen_B.Sum17 +
    Exp4_AttitudeSystemCodeGen_DW.Integrator_DSTATE_nu;

  /* Saturate: '<S246>/Saturation' */
  if (Exp4_AttitudeSystemCodeGen_B.Sum_i > 1.0) {
    Exp4_AttitudeSystemCodeGen_B.Saturation_m = 1.0;
  } else if (Exp4_AttitudeSystemCodeGen_B.Sum_i < -1.0) {
    Exp4_AttitudeSystemCodeGen_B.Saturation_m = -1.0;
  } else {
    Exp4_AttitudeSystemCodeGen_B.Saturation_m =
      Exp4_AttitudeSystemCodeGen_B.Sum_i;
  }

  /* End of Saturate: '<S246>/Saturation' */

  /* DataTypeConversion: '<S1>/Data Type Conversion6' incorporates:
   *  Fcn: '<S1>/Fcn4'
   */
  tmp = (real32_T)floor(Exp4_AttitudeSystemCodeGen_B.NormalizedRCSignals.z *
                        800.0F + 1100.0F);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* MATLAB Function: '<S9>/MATLAB Function3' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion6'
   *  DataTypeConversion: '<S4>/Conversion4'
   */
  Exp4_AttitudeSy_MATLABFunction1((real_T)(tmp < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp),
    &Exp4_AttitudeSystemCodeGen_B.sf_MATLABFunction3);

  /* Switch: '<S4>/Switch' incorporates:
   *  Constant: '<S4>/Constant3'
   */
  if (rtb_Compare) {
    /* Saturate: '<S4>/Output_Limits1' incorporates:
     *  Gain: '<S4>/Gain'
     */
    Exp4_AttitudeSystemCodeGen_B.rtb_Switch_idx_0 = 0.1 *
      Exp4_AttitudeSystemCodeGen_B.Saturation;

    /* Saturate: '<S4>/Output_Limits2' incorporates:
     *  Gain: '<S4>/Gain1'
     */
    Exp4_AttitudeSystemCodeGen_B.rtb_Switch_idx_1 = 0.1 *
      Exp4_AttitudeSystemCodeGen_B.Saturation_a;

    /* Saturate: '<S4>/Output_Limits3' incorporates:
     *  Gain: '<S4>/Gain2'
     */
    rtb_Switch_idx_2 = 0.1 * Exp4_AttitudeSystemCodeGen_B.Saturation_m;

    /* Fcn: '<S9>/Fcn6' */
    rtb_Switch_idx_3 = (Exp4_AttitudeSystemCodeGen_B.sf_MATLABFunction3.y -
                        1100.0) / 800.0;

    /* Saturate: '<S9>/Saturation10' */
    if (rtb_Switch_idx_3 > 1.0) {
      /* Saturate: '<S4>/Output_Limits4' */
      rtb_Switch_idx_3 = 1.0;
    } else if (rtb_Switch_idx_3 < 0.0) {
      /* Saturate: '<S4>/Output_Limits4' */
      rtb_Switch_idx_3 = 0.0;
    }

    /* End of Saturate: '<S9>/Saturation10' */
  } else {
    Exp4_AttitudeSystemCodeGen_B.rtb_Switch_idx_0 = 0.0;
    Exp4_AttitudeSystemCodeGen_B.rtb_Switch_idx_1 = 0.0;
    rtb_Switch_idx_2 = 0.0;
    rtb_Switch_idx_3 = 0.0;
  }

  /* End of Switch: '<S4>/Switch' */

  /* MATLAB Function: '<S2>/pwm_out2' */
  /* MATLAB Function 'Mixer/pwm_out2': '<S6>:1' */
  /* '<S6>:1:3' */
  /* '<S6>:1:15' */
  /* '<S6>:1:16' */
  /* '<S6>:1:17' */
  /* '<S6>:1:18' */
  u0 = (((Exp4_AttitudeSystemCodeGen_B.rtb_Switch_idx_1 + rtb_Switch_idx_3) -
         Exp4_AttitudeSystemCodeGen_B.rtb_Switch_idx_0) + rtb_Switch_idx_2) *
    1000.0 + 1000.0;

  /* Saturate: '<S2>/Output_Limits2' */
  if (u0 > 2000.0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[0] = 2000.0F;
  } else if (u0 < 1000.0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[0] = 1000.0F;
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[0] = (real32_T)u0;
  }

  /* MATLAB Function: '<S2>/pwm_out2' */
  u0 = (((rtb_Switch_idx_3 - Exp4_AttitudeSystemCodeGen_B.rtb_Switch_idx_1) +
         Exp4_AttitudeSystemCodeGen_B.rtb_Switch_idx_0) + rtb_Switch_idx_2) *
    1000.0 + 1000.0;

  /* Saturate: '<S2>/Output_Limits2' */
  if (u0 > 2000.0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[1] = 2000.0F;
  } else if (u0 < 1000.0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[1] = 1000.0F;
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[1] = (real32_T)u0;
  }

  /* MATLAB Function: '<S2>/pwm_out2' */
  u0 = (((Exp4_AttitudeSystemCodeGen_B.rtb_Switch_idx_0 + rtb_Switch_idx_3) +
         Exp4_AttitudeSystemCodeGen_B.rtb_Switch_idx_1) - rtb_Switch_idx_2) *
    1000.0 + 1000.0;

  /* Saturate: '<S2>/Output_Limits2' */
  if (u0 > 2000.0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[2] = 2000.0F;
  } else if (u0 < 1000.0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[2] = 1000.0F;
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[2] = (real32_T)u0;
  }

  /* MATLAB Function: '<S2>/pwm_out2' */
  u0 = (((rtb_Switch_idx_3 - Exp4_AttitudeSystemCodeGen_B.rtb_Switch_idx_0) -
         Exp4_AttitudeSystemCodeGen_B.rtb_Switch_idx_1) - rtb_Switch_idx_2) *
    1000.0 + 1000.0;

  /* Saturate: '<S2>/Output_Limits2' */
  if (u0 > 2000.0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[3] = 2000.0F;
  } else if (u0 < 1000.0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[3] = 1000.0F;
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[3] = (real32_T)u0;
  }

  for (i = 0; i < 12; i++) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    Exp4_AttitudeSystemCodeGen_B.DataTypeConversion1[i + 4] = 0.0F;
  }

  /* DigitalClock: '<Root>/Digital Clock' */
  Exp4_AttitudeSystemCodeGen_B.DigitalClock =
    ((Exp4_AttitudeSystemCodeGen_M->Timing.clockTick0) * 0.004);

  /* Update for DiscreteIntegrator: '<S143>/Integrator' incorporates:
   *  Gain: '<S140>/Integral Gain'
   *  Sum: '<S136>/SumI2'
   *  Sum: '<S136>/SumI4'
   */
  Exp4_AttitudeSystemCodeGen_DW.Integrator_DSTATE +=
    ((Exp4_AttitudeSystemCodeGen_B.Saturation_o -
      Exp4_AttitudeSystemCodeGen_B.Sum) + 0.046025266632626835 *
     Exp4_AttitudeSystemCodeGen_B.y) * 0.004;

  /* Update for DiscreteIntegrator: '<S191>/Integrator' incorporates:
   *  Gain: '<S188>/Integral Gain'
   *  Sum: '<S184>/SumI2'
   *  Sum: '<S184>/SumI4'
   */
  Exp4_AttitudeSystemCodeGen_DW.Integrator_DSTATE_d +=
    ((Exp4_AttitudeSystemCodeGen_B.Saturation -
      Exp4_AttitudeSystemCodeGen_B.Sum_n) + 0.38361558320806755 *
     Exp4_AttitudeSystemCodeGen_B.Sum21) * 0.004;

  /* Update for DiscreteIntegrator: '<S47>/Integrator' incorporates:
   *  Gain: '<S44>/Integral Gain'
   *  Sum: '<S40>/SumI2'
   *  Sum: '<S40>/SumI4'
   */
  Exp4_AttitudeSystemCodeGen_DW.Integrator_DSTATE_a +=
    ((Exp4_AttitudeSystemCodeGen_B.Saturation_p -
      Exp4_AttitudeSystemCodeGen_B.Sum_l) + 0.046025266632626835 *
     Exp4_AttitudeSystemCodeGen_B.Sum19) * 0.004;

  /* Update for DiscreteIntegrator: '<S95>/Integrator' incorporates:
   *  Gain: '<S92>/Integral Gain'
   *  Sum: '<S88>/SumI2'
   *  Sum: '<S88>/SumI4'
   */
  Exp4_AttitudeSystemCodeGen_DW.Integrator_DSTATE_n +=
    ((Exp4_AttitudeSystemCodeGen_B.Saturation_a -
      Exp4_AttitudeSystemCodeGen_B.Sum_c) + 0.38361558320806755 *
     Exp4_AttitudeSystemCodeGen_B.Sum22) * 0.004;

  /* Update for DiscreteIntegrator: '<S239>/Integrator' incorporates:
   *  Gain: '<S236>/Integral Gain'
   *  Sum: '<S232>/SumI2'
   *  Sum: '<S232>/SumI4'
   */
  Exp4_AttitudeSystemCodeGen_DW.Integrator_DSTATE_nu +=
    ((Exp4_AttitudeSystemCodeGen_B.Saturation_m -
      Exp4_AttitudeSystemCodeGen_B.Sum_i) + 0.76723116641613509 *
     Exp4_AttitudeSystemCodeGen_B.Sum17) * 0.004;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.004, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Exp4_AttitudeSystemCodeGen_M->Timing.clockTick0++;
  rate_scheduler();
}

/* Model initialize function */
void Exp4_AttitudeSystemCodeGen_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Exp4_AttitudeSystemCodeGen_M, 0,
                sizeof(RT_MODEL_Exp4_AttitudeSystemC_T));

  /* block I/O */
  (void) memset(((void *) &Exp4_AttitudeSystemCodeGen_B), 0,
                sizeof(B_Exp4_AttitudeSystemCodeGen_T));

  {
    Exp4_AttitudeSystemCodeGen_B.Switch = SL_MODE_OFF;
    Exp4_AttitudeSystemCodeGen_B.Switch1 = SL_COLOR_OFF;
  }

  /* states (dwork) */
  (void) memset((void *)&Exp4_AttitudeSystemCodeGen_DW, 0,
                sizeof(DW_Exp4_AttitudeSystemCodeGen_T));

  /* Start for S-Function (sfun_px4_input_rc): '<Root>/input_rc1' */
  {
    /* S-Function Block: <Root>/input_rc1 */
    /* subscribe to PWM RC input topic */
    int fd = orb_subscribe(ORB_ID(input_rc));
    Exp4_AttitudeSystemCodeGen_DW.input_rc1_input_rc_fd.fd = fd;
    Exp4_AttitudeSystemCodeGen_DW.input_rc1_input_rc_fd.events = POLLIN;
    orb_set_interval(fd, 1);
    PX4_INFO("* Subscribed to input_rc topic (fd = %d)*\n", fd);
  }

  /* Start for S-Function (sfun_px4_rgbled): '<Root>/RGB_LED' */
  {
    // enable RGBLED, set intitial mode and color
    // more devices will be 1, 2, etc
    Exp4_AttitudeSystemCodeGen_DW.RGB_LED_sl_led_control_s.led_mask = 0xff;
    Exp4_AttitudeSystemCodeGen_DW.RGB_LED_sl_led_control_s.mode = SL_MODE_OFF;
    Exp4_AttitudeSystemCodeGen_DW.RGB_LED_sl_led_control_s.priority = 0;
    Exp4_AttitudeSystemCodeGen_DW.RGB_LED_sl_led_control_s.timestamp =
      hrt_absolute_time();
    Exp4_AttitudeSystemCodeGen_DW.RGB_LED_orb_advert_t = orb_advertise_queue
      (ORB_ID(led_control),
       &Exp4_AttitudeSystemCodeGen_DW.RGB_LED_sl_led_control_s, 8);
  }

  /* Start for S-Function (sfun_px4_uorb_write): '<Root>/uORB Write Advanced' */
  {
    /* S-Function Block: <Root>/uORB Write Advanced */
    /* Initializing topic: actuator_outputs */
    struct actuator_outputs_s initialize_topic;
    memset( &initialize_topic, 0, sizeof(initialize_topic));
    Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_advert = orb_advertise
      (ORB_ID(actuator_outputs_rfly), &initialize_topic);
    if (Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_advert != 0) {
      PX4_INFO("Started advertising actuator_outputs_rfly");
    }
  }

  /* Start for S-Function (sfun_px4_vehicle_attitude): '<Root>/vehicle_attitude1' */
  {
    /* S-Function Block: <Root>/vehicle_attitude1 */
    /* subscribe to PWM RC input topic */
    int fd = orb_subscribe(ORB_ID(vehicle_attitude));
    Exp4_AttitudeSystemCodeGen_DW.vehicle_attitude1_angeuler_fd.fd = fd;
    Exp4_AttitudeSystemCodeGen_DW.vehicle_attitude1_angeuler_fd.events = POLLIN;
    orb_set_interval(fd, 1);
    PX4_INFO("* Subscribed to vehicle_attitude topic (fd = %d)*\n", fd);
  }

  {
    /* S-Function Block: <Root>/vehicle_attitude1 */
    /* subscribe to vehicle_angular_velocity topic */
    int fd1 = orb_subscribe(ORB_ID(vehicle_angular_velocity));
    Exp4_AttitudeSystemCodeGen_DW.vehicle_attitude1_angrad_fd.fd = fd1;
    Exp4_AttitudeSystemCodeGen_DW.vehicle_attitude1_angrad_fd.events = POLLIN;
    orb_set_interval(fd1, 1);
    PX4_INFO("* Subscribed to vehicle_angular_velocity topic (fd = %d)*\n", fd1);
  }

  /* Start for S-Function (sfun_px4_uorb_read_topic): '<Root>/Normalized RC Signals' */
  {
    /* S-Function Block: <Root>/Normalized RC Signals */
    /* subscribe to manual_control_setpoint topic */
    int fd = orb_subscribe(ORB_ID(manual_control_setpoint));
    Exp4_AttitudeSystemCodeGen_DW.NormalizedRCSignals_uORB_fd.fd = fd;
    Exp4_AttitudeSystemCodeGen_DW.NormalizedRCSignals_uORB_fd.events = POLLIN;
    orb_set_interval(fd, 1);
    PX4_INFO("* Subscribed to topic: manual_control_setpoint (fd = %d)*\n", fd);
  }
}

/* Model terminate function */
void Exp4_AttitudeSystemCodeGen_terminate(void)
{
  /* Terminate for S-Function (sfun_px4_input_rc): '<Root>/input_rc1' */

  /* Close uORB service used in the S-Function Block: <Root>/input_rc1 */
  close(Exp4_AttitudeSystemCodeGen_DW.input_rc1_input_rc_fd.fd);

  /* Terminate for S-Function (sfun_px4_rgbled): '<Root>/RGB_LED' */

  /* Turn off LED */
  Exp4_AttitudeSystemCodeGen_DW.RGB_LED_sl_led_control_s.led_mask = 0xff;
  Exp4_AttitudeSystemCodeGen_DW.RGB_LED_sl_led_control_s.mode = SL_MODE_OFF;
  Exp4_AttitudeSystemCodeGen_DW.RGB_LED_sl_led_control_s.priority = 0;
  Exp4_AttitudeSystemCodeGen_DW.RGB_LED_sl_led_control_s.timestamp =
    hrt_absolute_time();
  Exp4_AttitudeSystemCodeGen_DW.RGB_LED_orb_advert_t = orb_advertise_queue
    (ORB_ID(led_control),
     &Exp4_AttitudeSystemCodeGen_DW.RGB_LED_sl_led_control_s, 8);

  /* Close uORB service used in the S-Function Block: <Root>/RGB_LED */
  orb_unadvertise(Exp4_AttitudeSystemCodeGen_DW.RGB_LED_orb_advert_t);

  /* Terminate for S-Function (sfun_px4_uorb_write): '<Root>/uORB Write Advanced' */

  /* Close uORB service used in the S-Function Block: <Root>/uORB Write Advanced */
  orb_unadvertise(Exp4_AttitudeSystemCodeGen_DW.uORBWriteAdvanced_uorb_advert);

  /* Terminate for S-Function (sfun_px4_vehicle_attitude): '<Root>/vehicle_attitude1' */

  /* Close uORB service used in the S-Function Block: <Root>/vehicle_attitude1 */
  close(Exp4_AttitudeSystemCodeGen_DW.vehicle_attitude1_angeuler_fd.fd);

  /* Close uORB service used in the S-Function Block: <Root>/vehicle_attitude1 */
  close(Exp4_AttitudeSystemCodeGen_DW.vehicle_attitude1_angrad_fd.fd);

  /* Terminate for S-Function (sfun_px4_uorb_read_topic): '<Root>/Normalized RC Signals' */

  /* Close uORB service used in the S-Function Block: <Root>/Normalized RC Signals */
  close(Exp4_AttitudeSystemCodeGen_DW.NormalizedRCSignals_uORB_fd.fd);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
