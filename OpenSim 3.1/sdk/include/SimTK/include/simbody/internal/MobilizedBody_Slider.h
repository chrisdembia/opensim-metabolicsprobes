#ifndef SimTK_SIMBODY_MOBILIZED_BODY_SLIDER_H_
#define SimTK_SIMBODY_MOBILIZED_BODY_SLIDER_H_

/* -------------------------------------------------------------------------- *
 *                               Simbody(tm)                                  *
 * -------------------------------------------------------------------------- *
 * This is part of the SimTK biosimulation toolkit originating from           *
 * Simbios, the NIH National Center for Physics-Based Simulation of           *
 * Biological Structures at Stanford, funded under the NIH Roadmap for        *
 * Medical Research, grant U54 GM072970. See https://simtk.org/home/simbody.  *
 *                                                                            *
 * Portions copyright (c) 2007-12 Stanford University and the Authors.        *
 * Authors: Michael Sherman                                                   *
 * Contributors: Paul Mitiguy, Peter Eastman                                  *
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

/** @file
Declares the MobilizedBody::Slider class. **/

#include "simbody/internal/MobilizedBody.h"

namespace SimTK {

/// One mobility -- translation along the common x axis of the
/// inboard and outboard mobilizer frames.
/// Synonym: Prismatic
class SimTK_SIMBODY_EXPORT MobilizedBody::Slider : public MobilizedBody {
public:
        // SPECIALIZED INTERFACE FOR SLIDER MOBILIZER

    // "Length" is just a nicer name for a sliding joint's lone generalized coordinate q.
    Slider& setDefaultLength(Real length) {return setDefaultQ(length);}
    Real getDefaultLength() const         {return getDefaultQ();}

        // Friendly, mobilizer-specific access to generalized coordinates and speeds.

    void setLength(State& s, Real length) {setQ(s, length);}
    Real getLength(const State& s) const {return getQ(s);}

    void setRate(State& s, Real rateInLengthPerTime) {setU(s, rateInLengthPerTime);}
    Real getRate(const State& s) const {return getU(s);}

    // Mobility forces are "u-like", that is, one per dof.
    Real getAppliedForce(const State& s, const Vector& mobilityForces) const {
        return getMyPartU(s,mobilityForces);
    }
    void applyForce(const State& s, Real force, Vector& mobilityForces) const {
        updMyPartU(s,mobilityForces) += force;
    }

        // STANDARDIZED MOBILIZED BODY INTERFACE

        // required constructors
    explicit Slider(Direction=Forward);
    Slider(MobilizedBody& parent, const Body&, Direction=Forward);
    Slider(MobilizedBody& parent, const Transform& inbFrame,
           const Body&,           const Transform& outbFrame, Direction=Forward);

        // access to generalized coordinates q and generalized speeds u
    Slider& setDefaultQ(Real);
    Real getDefaultQ() const;

    Real getQ(const State&) const;
    Real getQDot(const State&) const;
    Real getQDotDot(const State&) const;
    Real getU(const State&) const;
    Real getUDot(const State&) const;

    void setQ(State&, Real) const;
    void setU(State&, Real) const;

    Real getMyPartQ(const State&, const Vector& qlike) const;
    Real getMyPartU(const State&, const Vector& ulike) const;
   
    Real& updMyPartQ(const State&, Vector& qlike) const;
    Real& updMyPartU(const State&, Vector& ulike) const;

        // specialize return type for convenience
    Slider& addBodyDecoration(const Transform& X_BD, const DecorativeGeometry& g)
      { (void)MobilizedBody::addBodyDecoration(X_BD,g); return *this; }
    Slider& addOutboardDecoration(const Transform& X_MD,  const DecorativeGeometry& g)
      { (void)MobilizedBody::addOutboardDecoration(X_MD,g); return *this; }
    Slider& addInboardDecoration (const Transform& X_FD, const DecorativeGeometry& g)
      { (void)MobilizedBody::addInboardDecoration(X_FD,g); return *this; }
    Slider& setDefaultInboardFrame(const Transform& X_PF)
      { (void)MobilizedBody::setDefaultInboardFrame(X_PF); return *this; }
    Slider& setDefaultOutboardFrame(const Transform& X_BM)
      { (void)MobilizedBody::setDefaultOutboardFrame(X_BM); return *this; }

    /** @cond **/ // Don't let doxygen see this
    SimTK_INSERT_DERIVED_HANDLE_DECLARATIONS(Slider, SliderImpl, MobilizedBody);
    /** @endcond **/
};


} // namespace SimTK

#endif // SimTK_SIMBODY_MOBILIZED_BODY_SLIDER_H_



