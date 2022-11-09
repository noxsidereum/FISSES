
#include "skse64/PluginAPI.h"
#include "skse64_common/skse_version.h"
#include "FissesPlugin.h"

#include <shlobj.h>

#ifndef PLUGIN_NAME
#define PLUGIN_NAME "fisses"
#endif

#ifndef PLUGIN_AUTHOR
#define PLUGIN_AUTHOR "TerenceYao"
#endif

#ifndef PLUGIN_SUPPORT_EMAIL
#define PLUGIN_SUPPORT_EMAIL "JustPmMe@NexusMods"
#endif

#ifndef PLUGIN_VERSION
#define PLUGIN_VERSION 141
#endif

static IDebugLog	gLog;
static PluginHandle g_pluginHandle = kPluginHandle_Invalid;
static SKSEPapyrusInterface *g_papyrus = NULL;

extern "C" {
	__declspec(dllexport) SKSEPluginVersionData SKSEPlugin_Version =
	{
		SKSEPluginVersionData::kVersion,

		PLUGIN_VERSION,
		PLUGIN_NAME,

		PLUGIN_AUTHOR,
		PLUGIN_SUPPORT_EMAIL,

		0,	// not version independent (extended field)
		0,	// not version independent
		{ RUNTIME_VERSION_1_6_659_GOG, 0 },	// compatible version

		0,	// works with any version of the script extender. you probably do not need to put anything here
	};
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// DLL exports

extern "C"
{
	// Called by SKSE to learn about this plugin and check that it's safe to load it
	__declspec(dllexport) bool SKSEPlugin_Query(const SKSEInterface *skse, PluginInfo *info)
	{
		// populate info structure
		info->infoVersion =	PluginInfo::kInfoVersion;
		info->name =		PLUGIN_NAME;
		info->version =		PLUGIN_VERSION;
		
		if (skse->isEditor)
		{
			_MESSAGE("loaded in editor, marking as incompatible");
			return false;
		}
		// ### do not do anything else in this callback
		// ### only fill out PluginInfo and return true/false

		// supported runtime version
		return true;
	}
	
	// Called by SKSE to load this plugin
	__declspec(dllexport) bool SKSEPlugin_Load(const SKSEInterface *skse)
	{
		char szBuff[256];
		LPCTSTR lpFileName = "Data\\SKSE\\Plugins\\fiss.ini";
		DWORD nLen = GetPrivateProfileString("FISS", "DebugMsg", "0", szBuff, sizeof(szBuff), lpFileName);
		int RecordDebug = atoi(szBuff);

		gLog.OpenRelative(CSIDL_MYDOCUMENTS, "\\My Games\\Skyrim Special Edition GOG\\SKSE\\fisses.log");

		_MESSAGE("FISS Plugin load");

		if (RecordDebug) {
			gLog.SetLogLevel(IDebugLog::kLevel_DebugMessage);
			_MESSAGE("FISS Plugin debug messages on");
		}
		else {
			gLog.SetLogLevel(IDebugLog::kLevel_Message);
			_MESSAGE("FISS Plugin debug messages off");
		}
		gLog.SetPrintLevel(IDebugLog::kLevel_Error);

		_DMESSAGE(PLUGIN_NAME);

		// store plugin handle so we can identify ourselves later
		g_pluginHandle = skse->GetPluginHandle();

		g_papyrus = (SKSEPapyrusInterface *)skse->QueryInterface(kInterface_Papyrus);
		
		//Check if the function registration was a success...
		if (g_papyrus->Register(FissesPlugin::RegisterFuncs))
			_MESSAGE("Register Succeeded");

		return true;
	}
};