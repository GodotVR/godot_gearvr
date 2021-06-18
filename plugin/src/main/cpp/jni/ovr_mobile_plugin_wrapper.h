/**
 * Created by Fredia Huya-Kouadio.
 */

#ifndef OVRMOBILE_OVR_MOBILE_PLUGIN_WRAPPER_H
#define OVRMOBILE_OVR_MOBILE_PLUGIN_WRAPPER_H

#include <jni.h>

namespace ovrmobile {

// Provide native access to the
// org.godotengine.plugin.vr.oculus.mobile.OvrMobilePlugin instance.
class OvrMobilePluginWrapper {
 public:
    static void initializeWrapper(JNIEnv *env, jobject ovr_mobile_plugin);

    static void uninitializeWrapper(JNIEnv *env);

    static void on_headset_mounted();

    static void on_headset_unmounted();

    static void on_input_focus_gained();

    static void on_input_focus_lost();

    static void on_enter_vr_mode();

    static void on_leave_vr_mode();

    static void on_pose_recentered();

 private:
    OvrMobilePluginWrapper();
    ~OvrMobilePluginWrapper();

    static jobject ovr_mobile_plugin_instance;
    static jmethodID on_headset_mounted_id;
    static jmethodID on_headset_unmounted_id;
    static jmethodID on_input_focus_gained_id;
    static jmethodID on_input_focus_lost_id;
    static jmethodID on_enter_vr_mode_id;
    static jmethodID on_leave_vr_mode_id;
    static jmethodID on_pose_recentered_id;
};

} // namespace ovrmobile

#endif // OVRMOBILE_OVR_MOBILE_PLUGIN_WRAPPER_H
