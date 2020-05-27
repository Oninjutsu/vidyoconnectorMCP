#ifndef VIDYO_VIRTUALVIDEOSOURCE_H_
#define VIDYO_VIRTUALVIDEOSOURCE_H_

#include <Lmi/Utils/LmiTypes.h>
#include <Lmi/Utils/LmiVector.h>
#include <Lmi/Utils/LmiList.h>
#include <Lmi/Os/LmiSharedPtr.h>



LMI_BEGIN_EXTERN_C

struct VidyoVirtualVideoSourceImpl_;
typedef struct VidyoVirtualVideoSourceImpl_ VidyoVirtualVideoSourceImpl;
Declare_LmiSharedPtr(VidyoVirtualVideoSourceImpl)
Declare_LmiSharedPtrWrapper(VidyoVirtualVideoSource, VidyoVirtualVideoSourceImpl)
Declare_LmiWeakPtrWrapper(VidyoVirtualVideoSourceHandle, VidyoVirtualVideoSource, VidyoVirtualVideoSourceImpl)
Declare_LmiVector(VidyoVirtualVideoSource)
Declare_LmiList(VidyoVirtualVideoSource)

/**
{type reference-counted="yes":
	{name: VidyoVirtualVideoSource}
	{parent: Device}
	{include: Lmi/VidyoClient/VidyoVirtualVideoSource.h}
	{description: This object represents a virtual video source on the local endpoint. }
    {member:
        {name: type}
        {type: VidyoVirtualVideoSourceType}
        {description: Type of the virtual video source.}
    }
	{member:
		{name: id}
		{type: LmiString}
		{description: Unique ID.}
	}
	{member:
		{name: name}
		{type: LmiString}
		{description: Name of the virtual video source.}
	}
}
*/

/**
{type visibility="private":
	{name: VidyoVirtualVideoSourceHandle}
	{parent: VidyoVirtualVideoSource}
	{description: Weak reference to VidyoVirtualVideoSource object.}
}
*/

/**
{type:
    {name: VidyoVirtualVideoSourceType}
    {parent: VidyoVirtualVideoSource}
    {description: Type of the virtual video source.}
    {value: {name: VIDYO_VIRTUALVIDEOSOURCETYPE_SHARE} {description: The type of virtual video source is a share.}}
    {value: {name: VIDYO_VIRTUALVIDEOSOURCETYPE_CAMERA} {description: The type of virtual video source is a camera.}}
}
*/
typedef enum
{
    VIDYO_VIRTUALVIDEOSOURCETYPE_SHARE,
    VIDYO_VIRTUALVIDEOSOURCETYPE_CAMERA
} VidyoVirtualVideoSourceType;

LMI_END_EXTERN_C

#include "VidyoMediaFormats.h"
#include "VidyoVideoFrame.h"
#include "VidyoLocalRenderer.h"
#include "VidyoRemoteRenderer.h"
#include "VidyoEndpoint.h"

LMI_BEGIN_EXTERN_C

/**
{callback:
	{name: VidyoVirtualVideoSourceStartCallback}
	{parent: VidyoVirtualVideoSource}
	{description: A callback invoked to notify that video source started after reconfiguration.}
	{prototype: void (*VidyoVirtualVideoSourceStartCallback)(const VidyoVirtualVideoSource* s, LmiTime frameInterval, VidyoMediaFormat mediaFormat, LmiVoidPtr userData)}
	{parameter:
		{name: s}
		{description: The VidyoVirtualVideoSource object. }
	}
	{parameter:
		{name: frameInterval}
		{description: The interval in nanoseconds between consecutive frames. }
	}
	{parameter:
		{name: mediaFormat}
		{description: The media format of video source}
	}
	{parameter:
		{name: userData}
		{description: Pointer to user data.}
	}
}
*/
typedef void(*VidyoVirtualVideoSourceStartCallback)(const VidyoVirtualVideoSource* s, LmiTime frameInterval, VidyoMediaFormat mediaFormat, LmiVoidPtr userData);

/**
{callback:
	{name: VidyoVirtualVideoSourceReconfigureCallback}
	{parent: VidyoVirtualVideoSource}
	{description: A callback invoked if configuration changed.}
	{prototype: void (*VidyoVirtualVideoSourceReconfigureCallback)(const VidyoVirtualVideoSource* s, LmiTime frameInterval, const VidyoMediaFormat mediaFormat, LmiVoidPtr userData)}
	{parameter:
		{name: s}
		{description: The VidyoVirtualVideoSource object. }
	}
	{parameter:
		{name: frameInterval}
		{description: The interval in nanoseconds between consecutive frames. }
	}
	{parameter:
		{name: mediaFormat}
        {description: The media format of video source}
	}
	{parameter:
		{name: userData}
		{description: Pointer to user data.}
	}
}
*/
typedef void(*VidyoVirtualVideoSourceReconfigureCallback)(const VidyoVirtualVideoSource* s, LmiTime frameInterval, const VidyoMediaFormat mediaFormat, LmiVoidPtr userData);

/**
{callback:
	{name: VidyoVirtualVideoSourceStopCallback}
	{parent: VidyoVirtualVideoSource}
	{description: A callback invoked to notify that video source stoped after reconfiguration.}
	{prototype: void (*VidyoVirtualVideoSourceStopCallback)(const VidyoVirtualVideoSource* s, LmiVoidPtr userData)}
	{parameter:
		{name: s}
        {description: The VidyoVirtualVideoSource object. }
	}
	{parameter:
		{name: userData}
		{description: Pointer to user data.}
	}
}
*/
typedef void(*VidyoVirtualVideoSourceStopCallback)(const VidyoVirtualVideoSource* s, LmiVoidPtr userData);

/**
{callback:
    {name: VidyoVirtualVideoSourceExternalMediaBufferReleaseCallback}
    {parent: VidyoVirtualVideoSource}
    {description: A callback invoked to notify application that VidyoClient is done with the buffer that holds raw video frame. This buffer is the same one that was passed to VidyoClient via function VidyoVirtualVideoSourceSendFrameWithExternalData.}
    {prototype: void (*VidyoVirtualVideoSourceExternalMediaBufferReleaseCallback)(const VidyoVirtualVideoSource* s, LmiUint8* buffer, LmiSizeT size, LmiVoidPtr userData)}
    {parameter:
        {name: s}
        {description: The VidyoVirtualVideoSource object. }
    }
    {parameter:
        {name: buffer}
        {description: The application allocated buffer that holds raw video frame, and was feeded to VidyoClient via VidyoVirtualVideoSourceSendFrameWithExternalData.}
    }
    {parameter:
        {name: size}
        {description: The size of the buffer.}
    }
    {parameter:
        {name: userData}
        {description: Pointer to user data.}
    }
 }
 */
typedef void(*VidyoVirtualVideoSourceExternalMediaBufferReleaseCallback)(const VidyoVirtualVideoSource* s,  LmiUint8* buffer, LmiSizeT size, LmiVoidPtr userData);

/**
{function:
	{name: VidyoVirtualVideoSourceConstruct}
	{parent: VidyoVirtualVideoSource}
	{description: Constructs a virtual video source.}
	{prototype: VidyoVirtualVideoSource* VidyoVirtualVideoSourceConstruct(VidyoVirtualVideoSource* s, VidyoEndpoint *endpoint, VidyoVirtualVideoSourceType type, LmiString *id, LmiString *name, LmiAllocator* alloc)}
	{parameter:
		{name: s}
		{description: The VidyoVirtualVideoSource object. }
	}
    {parameter:
        {name: endpoint}
        {description: The VidyoEndpoint object. }
    }
    {parameter:
        {name: type}
        {description: Type of the virtual video source.}
    }
	{parameter:
		{name: id}
		{description: Unique ID.}
	}
	{parameter:
		{name: name}
		{description: Name of the virtual video source.}
	}
	{parameter:
		{name: alloc}
		{description: The allocator used to allocate the buffer.}
	}
	{return: Returns a pointer to a constructed object on success, or NULL on failure.}
}
*/

VidyoVirtualVideoSource* VidyoVirtualVideoSourceConstruct(VidyoVirtualVideoSource* s, VidyoEndpoint *endpoint, VidyoVirtualVideoSourceType type, LmiString *id, LmiString *name, LmiAllocator* alloc);

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualVideoSourceConstructCopy}
	{parent: VidyoVirtualVideoSource}
	{description: Constructs a VidyoVirtualVideoSource object as a copy of another.}
	{prototype: VidyoVirtualVideoSource *VidyoVirtualVideoSourceConstructCopy(VidyoVirtualVideoSource *obj, const VidyoVirtualVideoSource *other)}
	{parameter: {name: obj} {description: The VidyoVirtualVideoSource object to construct.}}
	{parameter: {name: other} {description: The call object to make a copy of.}}
	{return: A pointer to a constructed object on success, or NULL on failure.}
}
*/

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualVideoSourceDestruct}
	{parent: VidyoVirtualVideoSource}
	{description: Destructs an VidyoVirtualVideoSource object.}
	{prototype: void VidyoVirtualVideoSourceDestruct(VidyoVirtualVideoSource *obj)}
	{parameter: {name: obj} {description: The VidyoVirtualVideoSource object to destruct.}}
}
*/

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualVideoSourceAssign}
	{parent: VidyoVirtualVideoSource}
	{description: Assigns one VidyoVirtualVideoSource object the value of another. }
	{prototype: VidyoVirtualVideoSource *VidyoVirtualVideoSourceAssign(VidyoVirtualVideoSource *obj, const VidyoVirtualVideoSource *other)}
	{parameter: {name: obj} {description: The VidyoVirtualVideoSource object.}}
	{parameter: {name: other} {description: The call object to make a copy of.}}
	{return: A pointer to the destination object on success, or NULL on failure.}
}
*/

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualVideoSourceOnFrame}
	{parent: VidyoVirtualVideoSource}
	{description: }
	{prototype: void VidyoVirtualVideoSourceOnFrame(VidyoVirtualVideoSource *s, const VidyoVideoFrame *videoFrame, VidyoMediaFormat mediaFormat)}
	{parameter:{name: s}{description: }}
	{parameter:{name: videoFrame}{description: }}
	{parameter:{name: mediaFormat}{description: The media format of video frame}}
}
*/
void VidyoVirtualVideoSourceOnFrame(VidyoVirtualVideoSource *s, const VidyoVideoFrame *videoFrame, VidyoMediaFormat mediaFormat);

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualVideoSourceGetName}
	{parent: VidyoVirtualVideoSource}
	{description: Gets the name of the video source.}
	{prototype: const LmiString* VidyoVirtualVideoSourceGetName(const VidyoVirtualVideoSource* s)}
	{parameter:	{name: s}	{description: The VidyoVirtualVideoSource object. }}
	{return: Name of the video source.}
}
*/
const LmiString* VidyoVirtualVideoSourceGetName(const VidyoVirtualVideoSource* s);

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualVideoSourceGetId}
	{parent: VidyoVirtualVideoSource}
	{description: Gets the unique ID of the video source.}
	{prototype: const LmiString* VidyoVirtualVideoSourceGetId(const VidyoVirtualVideoSource* s)}
	{parameter:	{name: s} {description: The VidyoVirtualVideoSource object. }}
	{return: Unique ID of the video source.}
}
*/
const LmiString* VidyoVirtualVideoSourceGetId(const VidyoVirtualVideoSource* s);

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualVideoSourceGetPreviewLabel}
	{parent: VidyoVirtualVideoSource}
	{description: Gets the preview label of the video source. }
	{prototype: const LmiString* VidyoVirtualVideoSourceGetPreviewLabel(const VidyoVirtualVideoSource* s)}
	{parameter:	{name: s} {description: The VidyoVirtualVideoSource object.}}
	{return: Display name of the video source.}
}
*/
const LmiString* VidyoVirtualVideoSourceGetPreviewLabel(const VidyoVirtualVideoSource* s);

/**
{function apigroup="connector,simple":
    {name: VidyoVirtualVideoSourceGetType}
    {parent: VidyoVirtualVideoSource}
    {description: Gets the type of the video source. }
    {prototype: VidyoVirtualVideoSourceType VidyoVirtualVideoSourceGetType(const VidyoVirtualVideoSource* s)}
    {parameter:
        {name: s}
        {description: The VidyoVirtualVideoSource object.}}
    {return: Type of the video source.}
}
*/
VidyoVirtualVideoSourceType VidyoVirtualVideoSourceGetType(const VidyoVirtualVideoSource* s);

/**
{function apigroup="connector,simple":
    {name: VidyoVirtualVideoSourceGetCurrentEncodeFrameInterval}
    {parent: VidyoVirtualVideoSource}
    {description: Gets the current encode frame interval of the video source. }
    {prototype: LmiTime VidyoVirtualVideoSourceGetCurrentEncodeFrameInterval(const VidyoVirtualVideoSource* s)}
    {parameter:
        {name: s}
        {description: The VidyoVirtualVideoSource object.}}
    {return: Encode frame interval of the video source in ns.}
}
*/
LmiTime VidyoVirtualVideoSourceGetCurrentEncodeFrameInterval(const VidyoVirtualVideoSource* s);

/**
{function apigroup="connector,simple":
    {name: VidyoVirtualVideoSourceGetMediaType}
    {parent: VidyoVirtualVideoSource}
    {description: Gets the media format of the video source. }
    {prototype: VidyoMediaFormat VidyoVirtualVideoSourceGetMediaType(const VidyoVirtualVideoSource* s)}
    {parameter:
        {name: s}
        {description: The VidyoVirtualVideoSource object.}}
    {return: Media format of the video source.}
}
*/
VidyoMediaFormat VidyoVirtualVideoSourceGetMediaType(const VidyoVirtualVideoSource* s);

/**
{function apigroup="connector,simple":
    {name: VidyoVirtualVideoSourceIsSelected}
    {parent: VidyoVirtualVideoSource}
    {description: Check if source added to the remote renderer. }
    {prototype: LmiBool VidyoVirtualVideoSourceIsSelected(VidyoVirtualVideoSource* s)}
    {parameter:
        {name: s}
        {description: The VidyoVirtualVideoSource object.}}
    {return: TRUE is source is added to the remote renderer, FALSE otherwise}
}
*/
LmiBool VidyoVirtualVideoSourceIsSelected(VidyoVirtualVideoSource* s);

/**
{function apigroup="connector,simple":
    {name: VidyoVirtualVideoSourceIsPreviewOn}
    {parent: VidyoVirtualVideoSource}
    {description: Check if source added to the local renderer. }
    {prototype: LmiBool VidyoVirtualVideoSourceIsPreviewOn(VidyoVirtualVideoSource* s)}
    {parameter:
        {name: s}
        {description: The VidyoVirtualVideoSource object.}}
    {return: TRUE is source is added to the local renderer, FALSE otherwise}
}
*/
LmiBool VidyoVirtualVideoSourceIsPreviewOn(VidyoVirtualVideoSource* s);

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualVideoSourceSetPreviewLabel}
	{parent: VidyoVirtualVideoSource}
	{description: Set the preview label of the video source. }
	{prototype: LmiBool VidyoVirtualVideoSourceSetPreviewLabel(VidyoVirtualVideoSource* s, const LmiString* previewLabel)}
	{parameter:	{name: s} {description: The VidyoVirtualVideoSource object.}}
	{parameter: {name: previewLabel} {description: Display name to set on the video source.}}
	{return: LMI_TRUE on success, LMI_FALSE otherwise.}
}
*/
LmiBool VidyoVirtualVideoSourceSetPreviewLabel(VidyoVirtualVideoSource* s, const LmiString* previewLabel);

/**
{function apigroup="connector,simple" visibility="private":
	{name: VidyoVirtualVideoSourceSetUserData}
	{parent: VidyoVirtualVideoSource}
	{description: }
	{prototype: void VidyoVirtualVideoSourceSetUserData(VidyoVirtualVideoSource* s, LmiVoidPtr userData)}
	{parameter: {name: s} {description: The VidyoVirtualVideoSource object. }}
	{parameter: {name: userData} {description: }}
}
*/
void VidyoVirtualVideoSourceSetUserData(VidyoVirtualVideoSource* s, LmiVoidPtr userData);

/**
{function apigroup="connector,simple" visibility="private":
	{name: VidyoVirtualVideoSourceGetUserData}
	{parent: VidyoVirtualVideoSource}
	{description: }
	{prototype: LmiVoidPtr VidyoVirtualVideoSourceGetUserData(const VidyoVirtualVideoSource* s)}
	{parameter: {name: s} {description: The VidyoVirtualVideoSource object. }}
	{return: }
}
*/
LmiVoidPtr VidyoVirtualVideoSourceGetUserData(const VidyoVirtualVideoSource* s);

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualVideoSourceSetBoundsConstraints}
	{parent: VidyoVirtualVideoSource}
	{description: Set a maximum width and height for the encoded stream and frame interval bounds. The stream size will be scaled down to fit the maxWidth/maxHeight if the capture is larger than either of those dimensions.}
	{prototype: LmiBool VidyoVirtualVideoSourceSetBoundsConstraints(VidyoVirtualVideoSource* s, LmiTime maxFrameInterval, LmiTime minFrameInterval, LmiUint maxWidth, LmiUint minWidth, LmiUint maxHeight, LmiUint minHeight)}
	{parameter: {name: s} {description: The VidyoVirtualVideoSource object.}}
	{parameter: {name: maxFrameInterval} {description: Maximum time between frames in ns. This is a hint to the resource manager for how it decides to allocate internal resources (cpu,mem,etc)}}
	{parameter: {name: minFrameInterval} {description: Minimum time between frames in ns. This is a hint to the resource manager for how it decides to allocate internal resources (cpu,mem,etc)}}
	{parameter: {name: maxWidth} {description: Maximum width of the encoded stream. If the captured stream width is larger than this max the stream will be scaled before sending to fit}}
	{parameter: {name: minWidth} {description: Unused}}
	{parameter: {name: maxHeight} {description: Maximum height of the encoded stream. If the captured stream height is larger than this max the stream will be scaled before sending to fit}}
	{parameter: {name: minHeight} {description: Unused}}
	{return: LMI_TRUE on success, LMI_FALSE on failure.}
}
*/
LmiBool VidyoVirtualVideoSourceSetBoundsConstraints(VidyoVirtualVideoSource* s, LmiTime maxFrameInterval, LmiTime minFrameInterval, LmiUint maxWidth, LmiUint minWidth, LmiUint maxHeight, LmiUint minHeight);

/**
{function:
	{name: VidyoVirtualVideoSourceSetDiscreteConstraints}
	{parent: VidyoVirtualVideoSource}
	{description: Set the stream characteristics, causing the stream to be reconfigured. This is an override which allows teh application to control the stream reconfiguration. After calling SetDiscreteConstraints the stream will not longer be reconfigured unless SetDiscreteConstraints again or SetBoundsConstraints is used.}
	{prototype: LmiBool VidyoVirtualVideoSourceSetDiscreteConstraints(VidyoVirtualVideoSource* s, LmiTime maxFrameInterval, LmiTime minFrameInterval, LmiUint width, LmiUint height)}
	{parameter: {name: s} {description: The VidyoVirtualVideoSource object.}}
	{parameter: {name: maxFrameInterval} {description: Maximum time between frames in ns. This is a hint to the resource manager for how it decides to allocate internal resources (cpu,mem,etc).}}
	{parameter: {name: minFrameInterval} {description: Minimum time between frames in ns. This is a hint to the resource manager for how it decides to allocate internal resources (cpu,mem,etc)}}
	{parameter: {name: width} {description: The width of the stream after the stream is reconfigured.}}
	{parameter: {name: height} {description: The height of the stream after the stream is reconfigured.}}
	{return: LMI_TRUE on success, LMI_FALSE on failure.}
}
*/
LmiBool VidyoVirtualVideoSourceSetDiscreteConstraints(VidyoVirtualVideoSource* s, LmiTime maxFrameInterval, LmiTime minFrameInterval, LmiUint width, LmiUint height);

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualVideoSourceSetMinFrameInterval}
	{parent: VidyoVirtualVideoSource}
	{description: Sets the maximum frame interval that will be used to scrapte the video source}
	{prototype: LmiBool VidyoVirtualVideoSourceSetMinFrameInterval(VidyoVirtualVideoSource* s, LmiTime frameInterval)}
	{parameter: {name: s} {description: The VidyoVirtualVideoSource object. }}
	{parameter: {name: frameInterval} {description: The interval in nanoseconds between consecutive frames. Default is 333333333 which is 3 frames per second. }}
	{return: LMI_TRUE on success, LMI_FALSE otherwise.}
	{note: To set 3 frames per seconds use 1000000000/3 as the value.}
}
*/
LmiBool VidyoVirtualVideoSourceSetMinFrameInterval(VidyoVirtualVideoSource* s, LmiTime frameInterval);

/**
{function apigroup="connector,simple,beta":
	{name: VidyoVirtualVideoSourceSetLowLatencyProfile}
	{parent: VidyoVirtualVideoSource}
	{description: Sets the low latency profile of the video source which treats the stream as a regular video source. This prioritizes latency over quality.}
	{prototype: LmiBool VidyoVirtualVideoSourceSetLowLatencyProfile(VidyoVirtualVideoSource* s, LmiBool profile)}
	{parameter: {name: s} {description: The VidyoVirtualVideoSource object. }}
	{parameter: {name: profile} {description: Low latency profile toggle. Default is LMI_FALSE. }}
	{return: LMI_TRUE on success, LMI_FALSE otherwise.}
}
*/
LmiBool VidyoVirtualVideoSourceSetLowLatencyProfile(VidyoVirtualVideoSource* s, LmiBool profile);


/**
{function apigroup="connector,simple":
	{name: VidyoVirtualVideoSourceClearConstraints}
	{parent: VidyoVirtualVideoSource}
	{description: }
	{prototype: void VidyoVirtualVideoSourceClearConstraints(VidyoVirtualVideoSource* s)}
	{parameter:	{name: s} {description: }}
}
*/
void VidyoVirtualVideoSourceClearConstraints(VidyoVirtualVideoSource* s);

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualVideoSourceAddToRemoteRenderer}
	{parent: VidyoVirtualVideoSource}
	{description: }
	{prototype: LmiBool VidyoVirtualVideoSourceAddToRemoteRenderer(VidyoVirtualVideoSource* s, const VidyoRemoteRenderer* remoteRenderer)}
	{parameter:	{name: s}{description: The VidyoVirtualVideoSource object. }}
	{parameter: {name: remoteRenderer} {description: }}
	{return: }
}
*/
LmiBool VidyoVirtualVideoSourceAddToRemoteRenderer(VidyoVirtualVideoSource* s, const VidyoRemoteRenderer* remoteRenderer);

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualVideoSourceRemoveFromRemoteRenderer}
	{parent: VidyoVirtualVideoSource}
	{description: }
	{prototype: LmiBool VidyoVirtualVideoSourceRemoveFromRemoteRenderer(VidyoVirtualVideoSource* s, const VidyoRemoteRenderer* remoteRenderer)}
	{parameter: {name: s} {description: The VidyoVirtualVideoSource object. }}
	{parameter: {name: remoteRenderer} {description: }}
	{return: }
}
*/
LmiBool VidyoVirtualVideoSourceRemoveFromRemoteRenderer(VidyoVirtualVideoSource* s, const VidyoRemoteRenderer* remoteRenderer);

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualVideoSourceAddToLocalRenderer}
	{parent: VidyoVirtualVideoSource}
	{description: }
	{prototype: LmiVoidPtr VidyoVirtualVideoSourceAddToLocalRenderer(VidyoVirtualVideoSource* s, const VidyoLocalRenderer* renderer)}
	{parameter: {name: s} {description: The VidyoVirtualVideoSource object. }}
	{parameter: {name: renderer} {description: }}
	{return: }
}
*/
LmiVoidPtr VidyoVirtualVideoSourceAddToLocalRenderer(VidyoVirtualVideoSource* s, const VidyoLocalRenderer* renderer);

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualVideoSourceRemoveFromLocalRenderer}
	{parent: VidyoVirtualVideoSource}
	{description: }
	{prototype: LmiBool VidyoVirtualVideoSourceRemoveFromLocalRenderer(VidyoVirtualVideoSource* s, const VidyoLocalRenderer* renderer)}
	{parameter: {name: s} {description: The VidyoVirtualVideoSource object. }}
	{parameter: {name: renderer} {description: }}
	{return: }
}
*/
LmiBool VidyoVirtualVideoSourceRemoveFromLocalRenderer(VidyoVirtualVideoSource* s, const VidyoLocalRenderer* renderer);

/**
{function apigroup="connector,simple":
	{name: VidyoVirtualVideoSourceSetStreamParametersInLocalRenderer}
	{parent: VidyoVirtualVideoSource}
	{description: }
	{prototype: LmiBool VidyoVirtualVideoSourceSetStreamParametersInLocalRenderer(VidyoVirtualVideoSource *s, const VidyoLocalRenderer *localRenderer, LmiUint width, LmiUint height, LmiTime frameInterval)}
	{parameter: {name: s} {description: The VidyoVirtualVideoSource object. }}
	{parameter: {name: localRenderer} {description: }}
	{parameter: {name: width} {description: }}
	{parameter: {name: height} {description: }}
	{parameter: {name: frameInterval} {description: The interval in nanoseconds between consecutive frames. }}
	{return: }
}
*/
LmiBool VidyoVirtualVideoSourceSetStreamParametersInLocalRenderer(VidyoVirtualVideoSource *s, const VidyoLocalRenderer *localRenderer, LmiUint width, LmiUint height, LmiTime frameInterval);

/**
{function visibility="private":
	{name: VidyoVirtualVideoSourceConstructFromDevice}
	{parent: VidyoVirtualVideoSource}
	{description: }
	{prototype: VidyoVirtualVideoSource *VidyoVirtualVideoSourceConstructFromDevice(VidyoVirtualVideoSource* virtualVideoSource, const VidyoDevice *device, LmiAllocator* alloc)}
	{parameter:	{name: virtualVideoSource}	{description: }}
	{parameter: {name: device} {description: }}
	{parameter: {name: alloc} {description: }}
	{return: }
}
*/
VidyoVirtualVideoSource *VidyoVirtualVideoSourceConstructFromDevice(VidyoVirtualVideoSource* virtualVideoSource, const VidyoDevice *device, LmiAllocator* alloc);

/**
{function visibility="private":
	{name: VidyoVirtualVideoSourceGetStats}
	{parent: VidyoVirtualVideoSource}
	{description: .}
	{prototype: LmiBool VidyoVirtualVideoSourceGetStats(VidyoVirtualVideoSource *videoSource, VidyoLocalVideoSourceStats *stats)}
	{parameter: {name: videoSource} {description: The local video source object to extract stats.}}
	{parameter: {name: stats} {description: The stats object to fill.}}
	{return: LMI_TRUE on success.}
}
*/
LmiBool VidyoVirtualVideoSourceGetStats(VidyoVirtualVideoSource *videoSource, VidyoLocalVideoSourceStats *stats);

/**
{function:
    {name: VidyoVirtualVideoSourceRegisterEventListener}
    {parent: VidyoVirtualVideoSource}
    {description: Constructs a virtual video source.}
    {prototype: LmiBool VidyoVirtualVideoSourceRegisterEventListener(VidyoVirtualVideoSource *s, VidyoVirtualVideoSourceStartCallback onStart, VidyoVirtualVideoSourceReconfigureCallback onReconfigure, VidyoVirtualVideoSourceStopCallback onStop, VidyoVirtualVideoSourceExternalMediaBufferReleaseCallback onBufferRelease)}
    {parameter:
        {name: s}
        {description: The VidyoVirtualVideoSource object. }
    }
    {parameter:
        {name: onStart}
        {description: A callback invoked to notify that video source started after reconfiguration.}
    }
    {parameter:
        {name: onReconfigure}
        {description: A callback invoked if configuration changed.}
    }
    {parameter:
        {name: onStop}
        {description: A callback invoked to notify that video source stoped after reconfiguration.}
    }
    {parameter:
        {name: onBufferRelease}
        {description: Callback that is triggered each time when VidyoClient is done with an application allocated buffer that holds raw video frame.}
    }
    {return: Returns a pointer to a constructed object on success, or NULL on failure.}
}
*/
LmiBool VidyoVirtualVideoSourceRegisterEventListener(VidyoVirtualVideoSource *s, VidyoVirtualVideoSourceStartCallback onStart, VidyoVirtualVideoSourceReconfigureCallback onReconfigure, VidyoVirtualVideoSourceStopCallback onStop, VidyoVirtualVideoSourceExternalMediaBufferReleaseCallback onBufferRelease);

/**
{function apigroup="connector,simple":
    {name: VidyoVirtualVideoSourceSendFrameWithExternalData}
    {parent: VidyoVirtualVideoSource}
    {description: }
    {prototype: LmiBool VidyoVirtualVideoSourceSendFrameWithExternalData(VidyoVirtualVideoSource *s, const VidyoMediaFormat format, LmiUint8* buffer, LmiSizeT size, LmiSizeT width, LmiSizeT height)}
    {parameter:{name: s}{description: The VidyoVirtualVideoSource object.}}
    {parameter:{name: format}{description: The media format of the video frame.}}
    {parameter:{name: buffer}{description: A pointer to externally allocated memory that holds the pixel data.}}
    {parameter:{name: size}{description: The size, in bytes, of the frame data.}}
    {parameter:{name: width}{description: The width of the video media frame in pixels.}}
    {parameter:{name: height}{description: The height of the video media frame in pixels.}}
    {return: Returns LMI_TRUE success, or LMI_FALSE on failure.}
}
*/
LmiBool VidyoVirtualVideoSourceSendFrameWithExternalData(VidyoVirtualVideoSource *s, const VidyoMediaFormat format, LmiUint8* buffer, LmiSizeT size, LmiSizeT width, LmiSizeT height);

LMI_END_EXTERN_C

#if LMI_INLINE_NEED_HEADER_FILE_DEFINITIONS
#include "VidyoVirtualVideoSourceInline.h"
#endif

#endif /*VIDYO_VIRTUALVIDEOSOURCE_H_*/
