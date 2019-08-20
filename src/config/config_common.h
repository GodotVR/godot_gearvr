////////////////////////////////////////////////////////////////
// Common helpers for the config classes implemented in this folder
// to expose part of Oculus VrAPI.h via GDScript classes

#ifndef OVRMOBILE_CONFIG_COMMON_H
#define OVRMOBILE_CONFIG_COMMON_H

#include "../ovr_mobile_session.h"
#include "../common.h"

typedef struct ovr_config_data_struct {
	ovrmobile::OvrMobileSession *ovr_mobile_session;
} ovr_config_data_struct;

/*
    to avoid code duplication and have consistent error handling this define is used in each function to check 
    for use data and instance in each function the inner _codeblock_ contains the actual implementation and 
    needs to set the variabl 'ret' correctly on success
*/
#undef CHECK_OVR
#define CHECK_OVR(_codeblock_) \
	godot_variant ret; \
	 if (p_user_data != NULL) { \
		ovr_config_data_struct *ovr_tracking_space_data = (ovr_config_data_struct *) p_user_data; \
		if (ovr_tracking_space_data->ovr_mobile_session != NULL) { \
			ovrMobile* ovr = ovr_tracking_space_data->ovr_mobile_session->get_ovr_mobile_context(); \
			_codeblock_ \
		} \
	 } \
	 return ret;

#endif
