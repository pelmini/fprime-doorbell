// ======================================================================
// \title  LightComponentImpl.hpp
// \author pelmini
// \brief  hpp file for Light component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef Light_HPP
#define Light_HPP

#include "DoorBell/Light/LightComponentAc.hpp"

namespace DoorBell {

  class LightComponentImpl :
    public LightComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object Light
      //!
      LightComponentImpl(
          const char *const compName /*!< The component name*/
      );

      //! Initialize object Light
      //!
      void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object Light
      //!
      ~LightComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for ON_OFF
      //!
      void ON_OFF_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          bool TurnOn /*!< LED turns on or off based on bool value*/
      );


    };

} // end namespace DoorBell

#endif
