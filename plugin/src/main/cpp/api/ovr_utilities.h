////////////////////////////////////////////////////////////////////////////////////////////////
// Vrapi utility functions

#ifndef OVR_UTILITIES_H
#define OVR_UTILITIES_H

#include "ovr_mobile_session.h"
#include <core/String.hpp>
#include <gen/Node.hpp>
#include <gen/Spatial.hpp>

namespace ovrmobile {

// uses the internal left and right view matrix to compute the IPD. Returns a float
float get_ipd(OvrMobileSession *session);

// Sets the color multiplier for the default layer used by the VrAPI compositor
bool set_default_layer_color_scale(OvrMobileSession *session,
                                   float red,
                                   float green,
                                   float blue,
                                   float alpha);

ovrVector3f get_controller_angular_velocity(OvrMobileSession *session, int controller_id);
ovrVector3f get_controller_linear_velocity(OvrMobileSession *session, int controller_id);
ovrVector3f get_controller_angular_acceleration(OvrMobileSession *session, int controller_id);
ovrVector3f get_controller_linear_acceleration(OvrMobileSession *session, int controller_id);

ovrVector3f get_head_angular_velocity(OvrMobileSession *session);
ovrVector3f get_head_linear_velocity(OvrMobileSession *session);
ovrVector3f get_head_angular_acceleration(OvrMobileSession *session);
ovrVector3f get_head_linear_acceleration(OvrMobileSession *session);

} // namespace ovrmobile

#endif // OVR_UTILITIES_H
