//
//  VidyoCameraControlCapabilities.h
//  VidyoClient
//
//  Created by Oleksandr Semeniuk on 5/27/19.
//  Copyright © 2019 Vidyo, Inc. All rights reserved.
//

#ifndef VIDYO_CAMERACONTROLCAPABILITIES_H_
#define VIDYO_CAMERACONTROLCAPABILITIES_H_

#include <Lmi/Utils/LmiTypes.h>
#include <Lmi/Utils/LmiAllocator.h>
#include <Lmi/Video/Common/LmiCameraControl.h>


LMI_BEGIN_EXTERN_C

/**
{type:
    {name: VidyoCameraControlDirection}
    {parent: VidyoCameraControlCapabilities}
    {description: The camera control direction.}
    {value: {name: VIDYO_CAMERACONTROLDIRECTION_PanLeft} {description: }}
    {value: {name: VIDYO_CAMERACONTROLDIRECTION_PanRight} {description: }}
    {value: {name: VIDYO_CAMERACONTROLDIRECTION_TiltUp} {description: }}
    {value: {name: VIDYO_CAMERACONTROLDIRECTION_TiltDown} {description: }}
    {value: {name: VIDYO_CAMERACONTROLDIRECTION_ZoomIn} {description: }}
    {value: {name: VIDYO_CAMERACONTROLDIRECTION_ZoomOut} {description: }}
}
*/
typedef enum {
    VIDYO_CAMERACONTROLDIRECTION_PanLeft,
    VIDYO_CAMERACONTROLDIRECTION_PanRight,
    VIDYO_CAMERACONTROLDIRECTION_TiltUp,
    VIDYO_CAMERACONTROLDIRECTION_TiltDown,
    VIDYO_CAMERACONTROLDIRECTION_ZoomIn,
    VIDYO_CAMERACONTROLDIRECTION_ZoomOut
} VidyoCameraControlDirection;

/**
{type:
    {name: VidyoCameraControlCapabilities}
    {parent: Device}
    {include: Lmi/VidyoClient/VidyoCameraControlCapabilities.h}
    {description: Represents the capability of a camera control.}
    {member:
        {name: panTiltHasRubberBand}
        {type: LmiBool}
        {description:}
    }
    {member:
        {name: panTiltHasContinuousMove}
        {type: LmiBool}
        {description:}
    }
    {member:
        {name: panTiltHasNudge}
        {type: LmiBool}
        {description:}
    }
    {member:
        {name: zoomHasRubberBand}
        {type: LmiBool}
        {description:}
    }
    {member:
        {name: zooomHasContinuousMove}
        {type: LmiBool}
        {description:}
    }
    {member:
        {name: zoomHasNudge}
        {type: LmiBool}
        {description:}
    }
    {member:
        {name: hasPhotoCapture}
        {type: LmiBool}
        {description:}
    }
}
*/
typedef struct {
    LmiBool panTiltHasRubberBand; // for future use
    LmiBool panTiltHasContinuousMove;
    LmiBool panTiltHasNudge;
    
    LmiBool zoomHasRubberBand; // for future use
    LmiBool zooomHasContinuousMove;
    LmiBool zoomHasNudge;
    
    LmiBool hasPhotoCapture;  // for future use
}  VidyoCameraControlCapabilities;

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesConstructDefault}
    {parent: VidyoCameraControlCapabilities}
    {description: Construct an VidyoCameraControlCapabilities object with default values.}
    {prototype: VidyoCameraControlCapabilities *VidyoCameraControlCapabilitiesConstructDefault(VidyoCameraControlCapabilities *caps, LmiAllocator *alloc)}
    {parameter: {name: caps} {description: The VidyoCameraControlCapabilities object to construct.}}
    {parameter: {name: alloc} {description: The allocator to use.}}
    {return: A pointer to a constructed object on success, or NULL on failure.}
}
*/
VidyoCameraControlCapabilities *VidyoCameraControlCapabilitiesConstructDefault(VidyoCameraControlCapabilities *caps, LmiAllocator *alloc);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesConstruct}
    {parent: VidyoCameraControlCapabilities}
    {description: Constructs an VidyoCameraControlCapabilities object with capabilities.}
    {prototype: VidyoCameraControlCapabilities *VidyoCameraControlCapabilitiesConstruct(VidyoCameraControlCapabilities *caps, LmiBool panTiltRubberBand, LmiBool panTiltMove, LmiBool panTiltNudge, LmiBool zoomRubberBand, LmiBool zoomMove, LmiBool zoomNudge, LmiBool photoCapture)}
    {parameter: {name: caps} {description: The VidyoCameraControlCapabilities object to construct.}}
    {parameter: {name: panTiltRubberBand} {description: Indicate that camera support PanTiltRubberBand control type.}}
    {parameter: {name: panTiltMove} {description: Indicate that camera support PanTiltContinuousMove control type.}}
    {parameter: {name: panTiltNudge} {description: Indicate that camera support PanTiltNudge control type.}}
    {parameter: {name: zoomRubberBand} {description: Indicate that camera support ZoomRubberBand control type.}}
    {parameter: {name: zoomMove} {description: Indicate that camera support ZoomContinuousMove control type.}}
    {parameter: {name: zoomNudge} {description: Indicate that camera support ZoomNudge control type.}}
    {parameter: {name: photoCapture} {description: Indicate that camera support PhotoCapture.}}
    {return: A pointer to a constructed object on success, or NULL on failure.}
}
*/
VidyoCameraControlCapabilities *VidyoCameraControlCapabilitiesConstruct(VidyoCameraControlCapabilities *caps, LmiBool panTiltRubberBand, LmiBool panTiltMove, LmiBool panTiltNudge, LmiBool zoomRubberBand, LmiBool zoomMove, LmiBool zoomNudge, LmiBool photoCapture);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesDestruct}
    {parent: VidyoCameraControlCapabilities}
    {description: Destructs an VidyoCameraControlCapabilities object.}
    {prototype: void VidyoCameraControlCapabilitiesDestruct(VidyoCameraControlCapabilities *caps)}
    {parameter: {name: caps} {description: The VidyoCameraControlCapabilities object to destruct.}}
}
*/
LMI_INLINE_DECLARATION void VidyoCameraControlCapabilitiesDestruct(VidyoCameraControlCapabilities *caps);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesAssign}
    {parent: VidyoCameraControlCapabilities}
    {description: Assigns one VidyoCameraControlCapabilities object the value of another.}
    {prototype: VidyoCameraControlCapabilities *VidyoCameraControlCapabilitiesAssign(VidyoCameraControlCapabilities *caps, const VidyoCameraControlCapabilities *other)}
    {parameter: {name: caps} {description: The VidyoCameraControlCapabilities object to assign to.}}
    {parameter: {name: other} {description: The VidyoCameraControlCapabilities object to make a copy of.}}
    {return: A pointer to the destination object on success, or NULL on failure.}
}
*/
LMI_INLINE_DECLARATION VidyoCameraControlCapabilities *VidyoCameraControlCapabilitiesAssign(VidyoCameraControlCapabilities *caps, const VidyoCameraControlCapabilities *other);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesEqual}
    {parent: VidyoCameraControlCapabilities}
    {description: #}
    {prototype: LmiBool VidyoCameraControlCapabilitiesEqual(const VidyoCameraControlCapabilities *caps, const VidyoCameraControlCapabilities *other)}
    {parameter: {name: caps} {description: #}}
    {parameter: {name: other} {description: #}}
    {return: LMI_TRUE it objects are equal, LMI_FALSE otherwise.}
}
*/
LmiBool VidyoCameraControlCapabilitiesEqual(const VidyoCameraControlCapabilities *caps, const VidyoCameraControlCapabilities *other);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesTranslateFromLmiControlCaps}
    {parent: VidyoCameraControlCapabilities}
    {description: Construct an VidyoCameraControlCapabilities from LmiCameraControlCapabilities.}
    {prototype: VidyoCameraControlCapabilities *VidyoCameraControlCapabilitiesTranslateFromLmiControlCaps(VidyoCameraControlCapabilities *caps, const LmiCameraControlCapabilities *lmiCaps)}
    {parameter: {name: caps} {description: The VidyoCameraControlCapabilities object to construct.}}
    {parameter: {name: lmiCaps} {description: The LmiCameraControlCapabilities object for initialization of VidyoCameraControlCapabilities object.}}
    {return: A pointer to a constructed object on success, or NULL on failure.}
}
*/
VidyoCameraControlCapabilities *VidyoCameraControlCapabilitiesTranslateFromLmiControlCaps(VidyoCameraControlCapabilities *caps, const LmiCameraControlCapabilities *lmiCaps);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesTranslateToLmiControlCaps}
    {parent: VidyoCameraControlCapabilities}
    {description: Construct an VidyoCameraControlCapabilities from LmiCameraControlCapabilities.}
    {prototype: void VidyoCameraControlCapabilitiesTranslateToLmiControlCaps(const VidyoCameraControlCapabilities *caps, LmiCameraControlCapabilities *lmiCaps)}
    {parameter: {name: caps} {description: The VidyoCameraControlCapabilities object to construct.}}
    {parameter: {name: lmiCaps} {description: The LmiCameraControlCapabilities object for initialization of VidyoCameraControlCapabilities object.}}
}
 */
void VidyoCameraControlCapabilitiesTranslateToLmiControlCaps(const VidyoCameraControlCapabilities *caps, LmiCameraControlCapabilities *lmiCaps);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesSetPanTiltRubberBand}
    {parent: VidyoCameraControlCapabilities}
    {description: #}
    {prototype: void VidyoCameraControlCapabilitiesSetPanTiltRubberBand(VidyoCameraControlCapabilities *caps, LmiBool enable)}
    {parameter: {name: caps} {description: #}}
    {parameter: {name: enable} {description: #}}
}
*/
LMI_INLINE_DECLARATION void VidyoCameraControlCapabilitiesSetPanTiltRubberBand(VidyoCameraControlCapabilities *caps, LmiBool enable);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesSetPanTiltContinuousMove}
    {parent: VidyoCameraControlCapabilities}
    {description: #}
    {prototype: void VidyoCameraControlCapabilitiesSetPanTiltContinuousMove(VidyoCameraControlCapabilities *caps, LmiBool enable)}
    {parameter: {name: caps} {description: #}}
    {parameter: {name: enable} {description: #}}
}
*/
LMI_INLINE_DECLARATION void VidyoCameraControlCapabilitiesSetPanTiltContinuousMove(VidyoCameraControlCapabilities *caps, LmiBool enable);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesSetPanTiltNudge}
    {parent: VidyoCameraControlCapabilities}
    {description: #}
    {prototype: void VidyoCameraControlCapabilitiesSetPanTiltNudge(VidyoCameraControlCapabilities *caps, LmiBool enable)}
    {parameter: {name: caps} {description: #}}
    {parameter: {name: enable} {description: #}}
}
*/
LMI_INLINE_DECLARATION void VidyoCameraControlCapabilitiesSetPanTiltNudge(VidyoCameraControlCapabilities *caps, LmiBool enable);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesSetZoomRubberBand}
    {parent: VidyoCameraControlCapabilities}
    {description: #}
    {prototype: void VidyoCameraControlCapabilitiesSetZoomRubberBand(VidyoCameraControlCapabilities *caps, LmiBool enable)}
    {parameter: {name: caps} {description: #}}
    {parameter: {name: enable} {description: #}}
}
*/
LMI_INLINE_DECLARATION void VidyoCameraControlCapabilitiesSetZoomRubberBand(VidyoCameraControlCapabilities *caps, LmiBool enable);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesSetZoomContinuousMove}
    {parent: VidyoCameraControlCapabilities}
    {description: #}
    {prototype: void VidyoCameraControlCapabilitiesSetZoomContinuousMove(VidyoCameraControlCapabilities *caps, LmiBool enable)}
    {parameter: {name: caps} {description: #}}
    {parameter: {name: enable} {description: #}}
}
*/
LMI_INLINE_DECLARATION void VidyoCameraControlCapabilitiesSetZoomContinuousMove(VidyoCameraControlCapabilities *caps, LmiBool enable);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesSetZoomNudge}
    {parent: VidyoCameraControlCapabilities}
    {description: #}
    {prototype: void VidyoCameraControlCapabilitiesSetZoomNudge(VidyoCameraControlCapabilities *caps, LmiBool enable)}
    {parameter: {name: caps} {description: #}}
    {parameter: {name: enable} {description: #}}
}
*/
LMI_INLINE_DECLARATION void VidyoCameraControlCapabilitiesSetZoomNudge(VidyoCameraControlCapabilities *caps, LmiBool enable);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesSetPhotoCapture}
    {parent: VidyoCameraControlCapabilities}
    {description: #}
    {prototype: void VidyoCameraControlCapabilitiesSetPhotoCapture(VidyoCameraControlCapabilities *caps, LmiBool enable)}
    {parameter: {name: caps} {description: #}}
    {parameter: {name: enable} {description: #}}
}
*/
LMI_INLINE_DECLARATION void VidyoCameraControlCapabilitiesSetPhotoCapture(VidyoCameraControlCapabilities *caps, LmiBool enable);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesClear}
    {parent: VidyoCameraControlCapabilities}
    {description: #}
    {prototype: void VidyoCameraControlCapabilitiesClear(VidyoCameraControlCapabilities *caps)}
    {parameter: {name: caps} {description: #}}
}
*/
void VidyoCameraControlCapabilitiesClear(VidyoCameraControlCapabilities *caps);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesHasPanTiltRubberBand}
    {parent: VidyoCameraControlCapabilities}
    {description: #}
    {prototype: LmiBool VidyoCameraControlCapabilitiesHasPanTiltRubberBand(const VidyoCameraControlCapabilities *caps)}
    {parameter: {name: caps} {description: #}}
    {return: #}
}
*/
LMI_INLINE_DECLARATION LmiBool VidyoCameraControlCapabilitiesHasPanTiltRubberBand(const VidyoCameraControlCapabilities *caps);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesHasPanTiltContinuousMove}
    {parent: VidyoCameraControlCapabilities}
    {description: #}
    {prototype: LmiBool VidyoCameraControlCapabilitiesHasPanTiltContinuousMove(const VidyoCameraControlCapabilities *caps)}
    {parameter: {name: caps} {description: #}}
    {return: #}
}
*/
LMI_INLINE_DECLARATION LmiBool VidyoCameraControlCapabilitiesHasPanTiltContinuousMove(const VidyoCameraControlCapabilities *caps);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesHasPanTiltNudge}
    {parent: VidyoCameraControlCapabilities}
    {description: #}
    {prototype: LmiBool VidyoCameraControlCapabilitiesHasPanTiltNudge(const VidyoCameraControlCapabilities *caps)}
    {parameter: {name: caps} {description: #}}
    {return: #}
}
*/
LMI_INLINE_DECLARATION LmiBool VidyoCameraControlCapabilitiesHasPanTiltNudge(const VidyoCameraControlCapabilities *caps);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesHasZoomRubberBand}
    {parent: VidyoCameraControlCapabilities}
    {description: #}
    {prototype: LmiBool VidyoCameraControlCapabilitiesHasZoomRubberBand(const VidyoCameraControlCapabilities *caps)}
    {parameter: {name: caps} {description: #}}
    {return: #}
}
*/
LMI_INLINE_DECLARATION LmiBool VidyoCameraControlCapabilitiesHasZoomRubberBand(const VidyoCameraControlCapabilities *caps);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesHasZoomContinuousMove}
    {parent: VidyoCameraControlCapabilities}
    {description: #}
    {prototype: LmiBool VidyoCameraControlCapabilitiesHasZoomContinuousMove(const VidyoCameraControlCapabilities *caps)}
    {parameter: {name: caps} {description: #}}
    {return: #}
}
*/
LMI_INLINE_DECLARATION LmiBool VidyoCameraControlCapabilitiesHasZoomContinuousMove(const VidyoCameraControlCapabilities *caps);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesHasZoomNudge}
    {parent: VidyoCameraControlCapabilities}
    {description: #}
    {prototype: LmiBool VidyoCameraControlCapabilitiesHasZoomNudge(const VidyoCameraControlCapabilities *caps)}
    {parameter: {name: caps} {description: #}}
    {return: #}
}
*/
LMI_INLINE_DECLARATION LmiBool VidyoCameraControlCapabilitiesHasZoomNudge(const VidyoCameraControlCapabilities *caps);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesHasPhotoCapture}
    {parent: VidyoCameraControlCapabilities}
    {description: #}
    {prototype: LmiBool VidyoCameraControlCapabilitiesHasPhotoCapture(const VidyoCameraControlCapabilities *caps)}
    {parameter: {name: caps} {description: #}}
    {return: #}
}
*/
LMI_INLINE_DECLARATION LmiBool VidyoCameraControlCapabilitiesHasPhotoCapture(const VidyoCameraControlCapabilities *caps);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesHasPanTilt}
    {parent: VidyoCameraControlCapabilities}
    {description: #}
    {prototype: LmiBool VidyoCameraControlCapabilitiesHasPanTilt(const VidyoCameraControlCapabilities *caps)}
    {parameter: {name: caps} {description: #}}
    {return: #}
}
*/
LMI_INLINE_DECLARATION LmiBool VidyoCameraControlCapabilitiesHasPanTilt(const VidyoCameraControlCapabilities *caps);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesHasZoom}
    {parent: VidyoCameraControlCapabilities}
    {description: #}
    {prototype: LmiBool VidyoCameraControlCapabilitiesHasZoom(const VidyoCameraControlCapabilities *caps)}
    {parameter: {name: caps} {description: #}}
    {return: #}
}
*/
LMI_INLINE_DECLARATION LmiBool VidyoCameraControlCapabilitiesHasZoom(const VidyoCameraControlCapabilities *caps);

/**
{function visibility="private":
    {name: VidyoCameraControlCapabilitiesHasAny}
    {parent: VidyoCameraControlCapabilities}
    {description: #}
    {prototype: LmiBool VidyoCameraControlCapabilitiesHasAny(const VidyoCameraControlCapabilities *caps)}
    {parameter: {name: caps} {description: #}}
    {return: #}
}
*/
LMI_INLINE_DECLARATION LmiBool VidyoCameraControlCapabilitiesHasAny(const VidyoCameraControlCapabilities *caps);

LMI_END_EXTERN_C

#if LMI_INLINE_NEED_HEADER_FILE_DEFINITIONS
#include "VidyoCameraControlCapabilitiesInline.h"
#endif

#endif /* VIDYO_CAMERACONTROLCAPABILITIES_H_ */
