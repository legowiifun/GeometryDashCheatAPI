/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include "../include/cheatAPI.hpp"

enum rulesets cheatAPI::setSetting() {
	auto setting = geode::prelude::Mod::get()->getSettingValue<std::string>("ruleset");
	if (setting == "Robtop") {
		return rulesets::ROBTOP;
	}
	else if (setting == "Pointercrate") {
		return rulesets::DEMONLIST;
	}
	else if (setting == "Geometry Dash Demon Ladder") {
		return rulesets::GDDL;
	}
	else if (setting == "Mod Makers Opinion") {
		return rulesets::MODMAKEROPINION;
	}
	else if (setting == "All Rated Extreme Demons List") {
		return rulesets::AREDL;
	}
	else {
		return rulesets::PEMONLIST;
	}
}

static enum rulesets rs;
static int activeCheatRobtop;
static int activeCheatDemonlist;
static int activeCheatGDDL;
static int activeCheatModMakerOpinion;
static int activeCheatAREDL;
static int activeCheatPemonlist;


bool cheatAPI::isCheating(rulesets r) {
	switch (r) {
	case ROBTOP:
		return (activeCheatRobtop > 0);
		break;
	case MODMAKEROPINION:
		return (activeCheatModMakerOpinion > 0);
		break;
	case DEMONLIST:
		return (activeCheatDemonlist > 0);
		break;
	case GDDL:
		return (activeCheatGDDL > 0);
		break;
	case AREDL:
		return (activeCheatAREDL > 0);
		break;
	case PEMONLIST:
		return (activeCheatPemonlist > 0);
		break;
	default:
		return false;
	} 
}

bool cheatAPI::isCheating() {
	return isCheating(setSetting());
}

void cheatAPI::setCheat(rulesets r) {
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
	case PEMONLIST:
		activeCheatPemonlist++;
		break;
	}
}
void cheatAPI::setCheat() {
	for (int i = 0; i < 6; i++) {
		setCheat(static_cast<rulesets>(i));
	}
}
void cheatAPI::endCheat(rulesets r) {
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
	case PEMONLIST:
		activeCheatPemonlist--;
		break;
	}
}
void cheatAPI::endCheat() {
	for (int i = 0; i < 6; i++) {
		endCheat(static_cast<rulesets>(i));
	}
}