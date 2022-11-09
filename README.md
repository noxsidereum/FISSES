# FileAccess Interface for Skyrim SE Scripts (FISSES) GOG Edition
**Original Creator: Terence Yao**

This is my fork of Terence Yao's FISSES 1.4.1 code, with a few simple changes to get it working with the current Skyrim GOG edition (GOG branch of SKSE 2.2.3 / Skyrim game version 1.6.659). Not sure if anyone is using this much now, but it's one of the few remaining mods in Lexy's guide that have not yet been gogified.

I sourced Terence's code from https://www.nexusmods.com/skyrimspecialedition/mods/13956?tab=files. Namely the file "FISSES DLL Source Code 2022-09-25" under the section "Miscellaneous Files". I understand that code was used for the most recent compiled mod, which is also listed on that page as "FileAccess Interface for Skyrim SE Scripts - FISSES (Anniversary Edition) BETA" (v1.4.1), with a description of "Re-build source code for SKSE64 Preliminary AE build 2.2.2. Compatible only with SkyrimSE.exe 1.6.640."

Terence Yao is, of course, the original creator of this mod and gets all the credit for it. I have not attempted to do major rewrites or bug fixes of the code - just to get it working with the GOG version of Skyrim.

To install:

  -  Download v1.4.1 of the mod (supporting Skyrim v1.6.640) from https://www.nexusmods.com/skyrimspecialedition/mods/13956?tab=files
  -  Install mod as usual, with Vortex or MO2 (or manually)
  -  Then replace fiss.dll in the mod folder with the one here (releases page - or compile it yourself from this code)

Extent of my testing:

  - Mod loads correctly with Skyrim 1.6.659 (GOG) and SKSE 2.2.3, as per SKSE logs
  - Mod correctly saves and restores MCM settings for "Timing is Everything SE - FISS version" (available under "Old Files" at https://www.nexusmods.com/skyrimspecialedition/mods/25464?tab=files). If you have enabled debug messages (DebugMsg=1) in SKSE/Plugins/fiss.ini, you will also see corresponding cfiss_beginLoad and cfiss_beginSave debug messages in "My Documents/My Games/Skyrim Special Edition GOG/SKSE/fisses.log"

-- noxsidereum, 9 nov 2022
