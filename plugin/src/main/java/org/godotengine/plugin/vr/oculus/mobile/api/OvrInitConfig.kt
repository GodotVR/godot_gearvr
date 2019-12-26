/**
 * Used to access and setup the init parameters for the plugin.
 *
 * The methods defined in this class must be invoked prior to initializing the Oculus mobile plugin.
 */
@file:JvmName("OvrInitConfig")

package org.godotengine.plugin.vr.oculus.mobile.api

import kotlinx.coroutines.withContext
import org.godotengine.plugin.vr.oculus.mobile.OvrMobilePlugin

/**
 * Set the factor by which to multiply the recommended render target size for the app.
 */
suspend fun OvrMobilePlugin.setRenderTargetSizeMultiplier(multiplier: Double) =
    withContext(this.glDispatcher) {
        nativeSetRenderTargetSizeMultiplier(multiplier)
    }

private external fun nativeSetRenderTargetSizeMultiplier(multiplier: Double): Boolean