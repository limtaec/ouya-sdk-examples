/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/*
 * This file contains the automatically generated loader-side
 * functions that form part of the extension.
 *
 * This file is awlays compiled into all loaders but compiles
 * to nothing if this extension is not enabled in the loader
 * at build time.
 */
#include "IwDebug.h"
#include "ODK_autodefs.h"
#include "s3eEdk.h"
#include "ODK.h"
//Declarations of Init and Term functions
extern s3eResult ODKInit();
extern void ODKTerminate();


// On platforms that use a seperate UI/OS thread we can autowrap functions
// here.   Note that we can't use the S3E_USE_OS_THREAD define since this
// code is oftern build standalone, outside the main loader build.
#if defined I3D_OS_IPHONE || defined I3D_OS_OSX || defined I3D_OS_LINUX || defined I3D_OS_WINDOWS

static void OuyaController_startOfFrame_wrap()
{
    IwTrace(ODK_VERBOSE, ("calling ODK func on main thread: OuyaController_startOfFrame"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)OuyaController_startOfFrame, 0);
}

static bool OuyaController_selectControllerByPlayer_wrap(int playerNum)
{
    IwTrace(ODK_VERBOSE, ("calling ODK func on main thread: OuyaController_selectControllerByPlayer"));
    return (bool)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)OuyaController_selectControllerByPlayer, 1, playerNum);
}

static bool OuyaController_selectControllerByDeviceID_wrap(int deviceID)
{
    IwTrace(ODK_VERBOSE, ("calling ODK func on main thread: OuyaController_selectControllerByDeviceID"));
    return (bool)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)OuyaController_selectControllerByDeviceID, 1, deviceID);
}

static int OuyaController_getAxisValue_wrap(int axis)
{
    IwTrace(ODK_VERBOSE, ("calling ODK func on main thread: OuyaController_getAxisValue"));
    return (int)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)OuyaController_getAxisValue, 1, axis);
}

static bool OuyaController_getButton_wrap(int button)
{
    IwTrace(ODK_VERBOSE, ("calling ODK func on main thread: OuyaController_getButton"));
    return (bool)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)OuyaController_getButton, 1, button);
}

static bool OuyaController_buttonPressedThisFrame_wrap(int button)
{
    IwTrace(ODK_VERBOSE, ("calling ODK func on main thread: OuyaController_buttonPressedThisFrame"));
    return (bool)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)OuyaController_buttonPressedThisFrame, 1, button);
}

static bool OuyaController_buttonReleasedThisFrame_wrap(int button)
{
    IwTrace(ODK_VERBOSE, ("calling ODK func on main thread: OuyaController_buttonReleasedThisFrame"));
    return (bool)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)OuyaController_buttonReleasedThisFrame, 1, button);
}

static bool OuyaController_buttonChangedThisFrame_wrap(int button)
{
    IwTrace(ODK_VERBOSE, ("calling ODK func on main thread: OuyaController_buttonChangedThisFrame"));
    return (bool)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)OuyaController_buttonChangedThisFrame, 1, button);
}

static int OuyaController_getPlayerNum_wrap()
{
    IwTrace(ODK_VERBOSE, ("calling ODK func on main thread: OuyaController_getPlayerNum"));
    return (int)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)OuyaController_getPlayerNum, 0);
}

static void OuyaPlugin_asyncSetDeveloperId_wrap(const char* developerId)
{
    IwTrace(ODK_VERBOSE, ("calling ODK func on main thread: OuyaPlugin_asyncSetDeveloperId"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)OuyaPlugin_asyncSetDeveloperId, 1, developerId);
}

#define OuyaController_startOfFrame OuyaController_startOfFrame_wrap
#define OuyaController_selectControllerByPlayer OuyaController_selectControllerByPlayer_wrap
#define OuyaController_selectControllerByDeviceID OuyaController_selectControllerByDeviceID_wrap
#define OuyaController_getAxisValue OuyaController_getAxisValue_wrap
#define OuyaController_getButton OuyaController_getButton_wrap
#define OuyaController_buttonPressedThisFrame OuyaController_buttonPressedThisFrame_wrap
#define OuyaController_buttonReleasedThisFrame OuyaController_buttonReleasedThisFrame_wrap
#define OuyaController_buttonChangedThisFrame OuyaController_buttonChangedThisFrame_wrap
#define OuyaController_getPlayerNum OuyaController_getPlayerNum_wrap
#define OuyaPlugin_asyncSetDeveloperId OuyaPlugin_asyncSetDeveloperId_wrap

#endif

void ODKRegisterExt()
{
    /* fill in the function pointer struct for this extension */
    void* funcPtrs[10];
    funcPtrs[0] = (void*)OuyaController_startOfFrame;
    funcPtrs[1] = (void*)OuyaController_selectControllerByPlayer;
    funcPtrs[2] = (void*)OuyaController_selectControllerByDeviceID;
    funcPtrs[3] = (void*)OuyaController_getAxisValue;
    funcPtrs[4] = (void*)OuyaController_getButton;
    funcPtrs[5] = (void*)OuyaController_buttonPressedThisFrame;
    funcPtrs[6] = (void*)OuyaController_buttonReleasedThisFrame;
    funcPtrs[7] = (void*)OuyaController_buttonChangedThisFrame;
    funcPtrs[8] = (void*)OuyaController_getPlayerNum;
    funcPtrs[9] = (void*)OuyaPlugin_asyncSetDeveloperId;

    /*
     * Flags that specify the extension's use of locking and stackswitching
     */
    int flags[10] = { 0 };

    /*
     * Register the extension
     */
    s3eEdkRegister("ODK", funcPtrs, sizeof(funcPtrs), flags, ODKInit, ODKTerminate, 0);
}

#if !defined S3E_BUILD_S3ELOADER

#if defined S3E_EDK_USE_STATIC_INIT_ARRAY
int ODKStaticInit()
{
    void** p = g_StaticInitArray;
    void* end = p + g_StaticArrayLen;
    while (*p) p++;
    if (p < end)
        *p = (void*)&ODKRegisterExt;
    return 0;
}

int g_ODKVal = ODKStaticInit();

#elif defined S3E_EDK_USE_DLLS
S3E_EXTERN_C S3E_DLL_EXPORT void RegisterExt()
{
    ODKRegisterExt();
}
#endif

#endif
