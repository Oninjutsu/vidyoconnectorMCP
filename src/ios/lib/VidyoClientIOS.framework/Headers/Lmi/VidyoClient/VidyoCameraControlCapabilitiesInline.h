//
//  VidyoCameraControlCapabilitiesInline.h
//  VidyoClient
//
//  Created by Oleksandr Semeniuk on 5/27/19.
//  Copyright © 2019 Vidyo, Inc. All rights reserved.
//

LMI_INLINE void VidyoCameraControlCapabilitiesDestruct(VidyoCameraControlCapabilities *caps)
{
    
}

LMI_INLINE VidyoCameraControlCapabilities *VidyoCameraControlCapabilitiesAssign(VidyoCameraControlCapabilities *caps, const VidyoCameraControlCapabilities *other)
{
    *caps = *other;
    return caps;
}

LMI_INLINE void VidyoCameraControlCapabilitiesSetPanTiltRubberBand(VidyoCameraControlCapabilities *caps, LmiBool enable)
{
    caps->panTiltHasRubberBand = enable;
}

LMI_INLINE void VidyoCameraControlCapabilitiesSetPanTiltContinuousMove(VidyoCameraControlCapabilities *caps, LmiBool enable)
{
    caps->panTiltHasContinuousMove = enable;
}

LMI_INLINE void VidyoCameraControlCapabilitiesSetPanTiltNudge(VidyoCameraControlCapabilities *caps, LmiBool enable)
{
    caps->panTiltHasNudge = enable;
}

LMI_INLINE void VidyoCameraControlCapabilitiesSetZoomRubberBand(VidyoCameraControlCapabilities *caps, LmiBool enable)
{
    caps->zoomHasRubberBand = enable;
}

LMI_INLINE void VidyoCameraControlCapabilitiesSetZoomContinuousMove(VidyoCameraControlCapabilities *caps, LmiBool enable)
{
    caps->zooomHasContinuousMove = enable;
}

LMI_INLINE void VidyoCameraControlCapabilitiesSetZoomNudge(VidyoCameraControlCapabilities *caps, LmiBool enable)
{
    caps->zoomHasNudge = enable;
}

LMI_INLINE void VidyoCameraControlCapabilitiesSetPhotoCapture(VidyoCameraControlCapabilities *caps, LmiBool enable)
{
    caps->hasPhotoCapture = enable;
}

LMI_INLINE LmiBool VidyoCameraControlCapabilitiesHasPanTiltRubberBand(const VidyoCameraControlCapabilities *caps)
{
    return caps->panTiltHasRubberBand;
}

LMI_INLINE LmiBool VidyoCameraControlCapabilitiesHasPanTiltContinuousMove(const VidyoCameraControlCapabilities *caps)
{
    return caps->panTiltHasContinuousMove;
}

LMI_INLINE LmiBool VidyoCameraControlCapabilitiesHasPanTiltNudge(const VidyoCameraControlCapabilities *caps)
{
    return caps->panTiltHasNudge;
}

LMI_INLINE LmiBool VidyoCameraControlCapabilitiesHasZoomRubberBand(const VidyoCameraControlCapabilities *caps)
{
    return caps->zoomHasRubberBand;
}

LMI_INLINE LmiBool VidyoCameraControlCapabilitiesHasZoomContinuousMove(const VidyoCameraControlCapabilities *caps)
{
    return caps->zooomHasContinuousMove;
}

LMI_INLINE LmiBool VidyoCameraControlCapabilitiesHasZoomNudge(const VidyoCameraControlCapabilities *caps)
{
    return caps->zoomHasNudge;
}

LMI_INLINE LmiBool VidyoCameraControlCapabilitiesHasPhotoCapture(const VidyoCameraControlCapabilities *caps)
{
    return caps->hasPhotoCapture;
}

LMI_INLINE LmiBool VidyoCameraControlCapabilitiesHasPanTilt(const VidyoCameraControlCapabilities *caps)
{
    return caps->panTiltHasContinuousMove || caps->panTiltHasNudge;
}

LMI_INLINE LmiBool VidyoCameraControlCapabilitiesHasZoom(const VidyoCameraControlCapabilities *caps)
{
    return caps->zooomHasContinuousMove || caps->zoomHasNudge;
}

LMI_INLINE LmiBool VidyoCameraControlCapabilitiesHasAny(const VidyoCameraControlCapabilities *caps)
{
    return VidyoCameraControlCapabilitiesHasPanTilt(caps) || VidyoCameraControlCapabilitiesHasZoom(caps) || caps->hasPhotoCapture;
}
