//
// Created by fhuya on 9/24/2020.
//

#include "ovr_display.h"
#include "api_common.h"

namespace ovrmobile {
OvrDisplay::OvrDisplay() {}

OvrDisplay::~OvrDisplay() {}

void OvrDisplay::_init() {}

void OvrDisplay::_register_methods() {
//    register_method("set_display_refresh_rate", &OvrDisplay::set_display_refresh_rate);
//    register_method("get_supported_display_refresh_rates",
//                    &OvrDisplay::get_supported_display_refresh_rates);
}

std::vector<float> get_supported_display_refresh_rates(OvrMobileSession *session) {
    return check_session_initialized<std::vector<float>>(
            session,
            [&]() {
                const int refresh_rates_count = vrapi_GetSystemPropertyInt(
                        session->get_ovr_java(),
                        VRAPI_SYS_PROP_NUM_SUPPORTED_DISPLAY_REFRESH_RATES);
                std::vector<float> supported_refresh_rates(refresh_rates_count, 0.0F);
                vrapi_GetSystemPropertyFloatArray(session->get_ovr_java(),
                                                  VRAPI_SYS_PROP_SUPPORTED_DISPLAY_REFRESH_RATES,
                                                  supported_refresh_rates.data(),
                                                  refresh_rates_count);

                return supported_refresh_rates;
            },
            []() { return std::vector<float>(); });
}

bool set_display_refresh_rate(OvrMobileSession *session, float refresh_rate) {
    return check_session_initialized<bool>(
            session,
            [&]() {
                return vrapi_SetDisplayRefreshRate(session->get_ovr_mobile_context(),
                                                   refresh_rate) == ovrSuccess;
            },
            []() { return false; });
}
} // namespace ovrmobile
