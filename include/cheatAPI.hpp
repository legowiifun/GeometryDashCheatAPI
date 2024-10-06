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

/**
 * Brings cocos2d and all Geode namespaces to the current scope.
 */
using namespace geode::prelude;
/*
* ROBTOP: Will levels verified with it get rated? Can it get you leaderboard banned? What does Robtop Think?
* MODMAKEROPINION: What is your opinion on it? 
* 
*/
enum rulesets {
	ROBTOP, DEMONLIST, GDDL, MODMAKEROPINION, AREDL
};

class CHEAT_API_DLL cheatAPI {
	private: 
	static enum rulesets rs;
	static int activeCheatRobtop;
	static int activeCheatDemonlist;
	static int activeCheatGDDL;
	static int activeCheatModMakerOpinion;
	static int activeCheatAREDL;

	static enum rulesets setSetting();
	public:
		static bool isCheating(enum rulesets r);
		static bool isCheating();
		static void setCheat(enum rulesets r);
		static void setCheat();
		static void endCheat(enum rulesets r);
		static void endCheat();
};

//static class antiCheat CheatAPI;