// ======================================================================
// \title  LightComponentImpl.cpp
// \author pelmini
// \brief  cpp file for Light component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#include <Arduino.h>
#include <DoorBell/Light/LightComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace DoorBell {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  LightComponentImpl ::
    LightComponentImpl(
        const char *const compName
    ) :
      LightComponentBase(compName)
  {

  }

  void LightComponentImpl ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {
    LightComponentBase::init(instance);
    pinMode(6, OUTPUT);
  }

  LightComponentImpl ::
    ~LightComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void LightComponentImpl ::
    ON_OFF_handler
    (
        const NATIVE_INT_TYPE portNum,
        bool TurnOn
        )
  {
      if(TurnOn)
      {
         digitalWrite(6, HIGH);
      }
      else
      {
        digitalWrite(6, LOW);
      }

  }

} // end namespace DoorBell
