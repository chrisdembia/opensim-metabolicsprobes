#ifndef _ControlConstant_h_
#define _ControlConstant_h_
/* -------------------------------------------------------------------------- *
 *                        OpenSim:  ControlConstant.h                         *
 * -------------------------------------------------------------------------- *
 * The OpenSim API is a toolkit for musculoskeletal modeling and simulation.  *
 * See http://opensim.stanford.edu and the NOTICE file for more information.  *
 * OpenSim is developed at Stanford University and supported by the US        *
 * National Institutes of Health (U54 GM072970, R24 HD065690) and by DARPA    *
 * through the Warrior Web program.                                           *
 *                                                                            *
 * Copyright (c) 2005-2012 Stanford University and the Authors                *
 * Author(s): Frank C. Anderson                                               *
 *                                                                            *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may    *
 * not use this file except in compliance with the License. You may obtain a  *
 * copy of the License at http://www.apache.org/licenses/LICENSE-2.0.         *
 *                                                                            *
 * Unless required by applicable law or agreed to in writing, software        *
 * distributed under the License is distributed on an "AS IS" BASIS,          *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
 * See the License for the specific language governing permissions and        *
 * limitations under the License.                                             *
 * -------------------------------------------------------------------------- */

/* Note: This code was originally developed by Realistic Dynamics Inc. 
 * Author: Frank C. Anderson 
 */


// INCLUDES
#include <OpenSim/Simulation/osimSimulationDLL.h>
#include <OpenSim/Common/Object.h>
#include "Control.h"


//=============================================================================
//=============================================================================
/**
 * A class that represents a constant control curve.  That is, the value
 * of the control curve is the same at any value of time.
 *
 * @author Frank C. Anderson
 * @version 1.0
 */
namespace OpenSim { 

class OSIMSIMULATION_API ControlConstant : public Control {
OpenSim_DECLARE_CONCRETE_OBJECT(ControlConstant, Control);

//=============================================================================
// MEMBER DATA
//=============================================================================
protected:
	// PROPERTIES
	/** Control value. */
	PropertyDbl _propX;

	// REFERENCES
	double &_x;

//=============================================================================
// METHODS
//=============================================================================
public:
	ControlConstant(double aX=0.0,const char *aName="UNKOWN");
	ControlConstant(const ControlConstant &aControl);
	virtual ~ControlConstant();

private:
	void setNull();
	void copyData(const ControlConstant &aControl);
protected:
	void setupProperties();
	

	//--------------------------------------------------------------------------
	// OPERATORS
	//--------------------------------------------------------------------------
public:
#ifndef SWIG
	ControlConstant& operator=(const ControlConstant &aControl);
#endif
	//--------------------------------------------------------------------------
	// GET AND SET
	//--------------------------------------------------------------------------
	// PARAMETERS
	// Number
	virtual int getNumParameters() const;
	// Min
	virtual void setParameterMin(int aI,double aMin);
	virtual double getParameterMin(int aI) const;
	// Max
	virtual void setParameterMax(int aI,double aMax);
	virtual double getParameterMax(int aI) const;
	// Time and Neighborhood
	virtual double getParameterTime(int aI) const;
	virtual void getParameterNeighborhood(int aI,double &rTLower,double &rTUpper) const;
	// List
	virtual int getParameterList(double aT,Array<int> &rList);
	virtual int getParameterList(double aT1,double aT2,Array<int> &rList);
	// Value
	virtual void setParameterValue(int aI,double aP);
	virtual double getParameterValue(int aI) const;
	// CONTROL VALUE
	virtual void setControlValue(double aT,double aX);
	virtual double getControlValue(double aT);
	virtual double getControlValueMin(double aT=0.0);
	virtual void setControlValueMin(double aT,double aX);
	virtual double getControlValueMax(double aT=0.0);
	virtual void setControlValueMax(double aT,double aX);

//=============================================================================
};	// END of class ControlConstant

}; //namespace
//=============================================================================
//=============================================================================

#endif // __ControlConstant_h__
