#pragma once

#include <Geode/Geode.hpp>

#ifdef GEODE_IS_WINDOWS
	#ifdef LEGOWIIFUN_CHEAT_API_EXPORTING
		#define	CHEAT_API_DLL __declspec(dllexport)
	#else
		#define	CHEAT_API_DLL __declspec(dllimport)
	#endif
	#else
		#define	CHEAT_API_DLL __attribute__((visibility("default")))
#endif


/*
* ROBTOP: Will levels verified with it get rated? Can it get you leaderboard banned?
* DEMONLIST: Based on https://pointercrate.com/demonlist/
* GDDL: Based on gdladder.com
* MODMAKEROPINION: What is your opinion on it? 
* AREDL: Based on aredl.net
* PEMONLIST: based on pemonlist.com
*/
enum rulesets {
	ROBTOP, DEMONLIST, GDDL, MODMAKEROPINION, AREDL, PEMONLIST
};

class CHEAT_API_DLL cheatAPI {
	private: 


	static enum rulesets setSetting();
	public:
		static bool isCheating(rulesets r);
		static bool isCheating();
		static void setCheat(rulesets r);
		static void setCheat();
		static void endCheat(rulesets r);
		static void endCheat();
};