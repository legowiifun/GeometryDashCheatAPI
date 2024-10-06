/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include "../include/cheatAPI.hpp"

/**
 * Brings cocos2d and all Geode namespaces to the current scope.
 */
using namespace geode::prelude;

enum rulesets cheatAPI::setSetting() {
	int setting = Mod::get()->getSettingValue<int64_t>("ruleset");
	return (static_cast<enum rulesets>(setting));
}

bool cheatAPI::isCheating(enum rulesets r) {
	switch (r) {
	case ROBTOP:
		return (activeCheatRobtop > 1);
		break;
	case MODMAKEROPINION:
		return (activeCheatModMakerOpinion > 1);
		break;
	case DEMONLIST:
		return (activeCheatDemonlist > 1);
		break;
	case GDDL:
		return (activeCheatGDDL > 1);
		break;
	case AREDL:
		return (activeCheatAREDL > 1);
		break;
	default:
		return false;
	} 
}

bool cheatAPI::isCheating() {
	return isCheating(setSetting());
}

void cheatAPI::setCheat(enum rulesets r) {
	switch (r) {
	case ROBTOP:
		activeCheatRobtop++;
		break;
	case MODMAKEROPINION:
		activeCheatModMakerOpinion++;
		break;
	case DEMONLIST:
		activeCheatDemonlist++;
		break;
	case GDDL:
		activeCheatGDDL++;
		break;
	case AREDL:
		activeCheatAREDL++;
		break;
	}
}
void cheatAPI::setCheat() {
	for (int i = 0; i < 5; i++) {
		setCheat(static_cast<enum rulesets>(i));
	}
}
void cheatAPI::endCheat(enum rulesets r) {
	switch (r) {
	case ROBTOP:
		activeCheatRobtop--;
		break;
	case MODMAKEROPINION:
		activeCheatModMakerOpinion--;
		break;
	case DEMONLIST:
		activeCheatDemonlist--;
		break;
	case GDDL:
		activeCheatGDDL--;
		break;
	case AREDL:
		activeCheatAREDL--;
		break;
	}
}
void cheatAPI::endCheat() {
	for (int i = 0; i < 5; i++) {
		endCheat(static_cast<enum rulesets>(i));
	}
}