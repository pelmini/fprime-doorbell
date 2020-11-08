// ======================================================================
// \title  BodySensorComponentImpl.hpp
// \author pelmini
// \brief  hpp file for BodySensor component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef BodySensor_HPP
#define BodySensor_HPP

#include "DoorBell/BodySensor/BodySensorComponentAc.hpp"

namespace DoorBell {

  class BodySensorComponentImpl :
    public BodySensorComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object BodySensor
      //!
      BodySensorComponentImpl(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object BodySensor
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object BodySensor
      //!
      ~BodySensorComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for schedIn
      //!
      void schedIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );

      //! Implementation for Sensor_Sensitivity command handler
      //!
      void Sensor_Sensitivity_cmdHandler(
              const FwOpcodeType opCode, /*!< The opcode*/
              const U32 cmdSeq, /*!< The command sequence number*/
              U32 Sensitivity_Lvl
      );

      unsigned int sensitivity_lvl;
      unsigned int count;
      unsigned int bodyCount;


    };

} // end namespace DoorBell

#endif
