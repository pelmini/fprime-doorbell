// ======================================================================
// \title  BodySensorComponentImpl.cpp
// \author pelmini
// \brief  cpp file for BodySensor component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <DoorBell/BodySensor/BodySensorComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include <Arduino.h>

namespace DoorBell {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  BodySensorComponentImpl ::
    BodySensorComponentImpl(
        const char *const compName
    ) :
      BodySensorComponentBase(compName)
  {
    count = 0;
    bodyCount = 0;
    sensitivity_lvl = 150;
  }

  void BodySensorComponentImpl ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    BodySensorComponentBase::init(instance);
  }

  BodySensorComponentImpl ::
    ~BodySensorComponentImpl(void)
  {
  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void BodySensorComponentImpl ::
    schedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    int val = 0;
    val = analogRead(A6);

    if(val > sensitivity_lvl && count == 0)
    {
      log_ACTIVITY_HI_BodySensor_ON();
      ON_OFF_out(0, true);
      count = 30;
    }
    else if(count == 1)
    {
      log_ACTIVITY_HI_BodySensor_OFF();
      ON_OFF_out(0,false);
      bodyCount++;
      tlmWrite_BodySensor_Counter(bodyCount);
      count--;
    }
    /*
     * Stop condition
     * */
    else if(count == 0)
    {
      count = 0;
    }
    else
    {
      count--;
    }
  }
    void BodySensorComponentImpl ::
    Sensor_Sensitivity_cmdHandler(
            const FwOpcodeType opCode,
            const U32 cmdSeq,
            U32 Sensitivity_Lvl
    )
    {
        sensitivity_lvl = Sensitivity_Lvl;
        this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
    }

} // end namespace DoorBell
