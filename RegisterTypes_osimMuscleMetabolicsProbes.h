#ifndef _RegisterTypes_OsimMuscleMetabolicsProbes_h_
#define _RegisterTypes_OsimMuscleMetabolicsProbes_h_
/* -------------------------------------------------------------------------- *
 *              OpenSim:  RegisterTypes_osimMuscleMetabolicsProbes.h          *
 * -------------------------------------------------------------------------- *
 * The OpenSim API is a toolkit for musculoskeletal modeling and simulation.  *
 * See http://opensim.stanford.edu and the NOTICE file for more information.  *
 * OpenSim is developed at Stanford University and supported by the US        *
 * National Institutes of Health (U54 GM072970, R24 HD065690) and by DARPA    *
 * through the Warrior Web program.                                           *
 *                                                                            *
 * Copyright (c) 2005-2013 Stanford University and the Authors                *
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

#include "osimMuscleMetabolicsProbesDLL.h"

extern "C" {

OSIMMUSCLEMETABOLICSPROBES_API void RegisterTypes_osimMuscleMetabolicsProbes(); 

}

class dllObjectInstantiator 
{ 
public: 
        dllObjectInstantiator(); 
private: 
        void registerDllClasses(); 
}; 
    

#endif // _RegisterTypes_OsimMuscleMetabolicsProbes_h_


