/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#define GEODE_DEFINE_EVENT_EXPORTS
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
geode::Result<bool> cheatAPIEvents::isCheatingOne(std::string str) {
	if (str == "ROBTOP") {
		return geode::Ok(cheatAPI::isCheating(ROBTOP));
	}
	else if (str == "DEMONLIST") {
		return geode::Ok(cheatAPI::isCheating(DEMONLIST));
	}
	else if (str == "GDDL") {
		return geode::Ok(cheatAPI::isCheating(GDDL));
	}
	else if (str == "MODMAKEROPINION") {
		return geode::Ok(cheatAPI::isCheating(MODMAKEROPINION));
	}
	else if (str == "AREDL") {
		return geode::Ok(cheatAPI::isCheating(AREDL));
	}
	else if (str == "PEMONLIST") {
		return geode::Ok(cheatAPI::isCheating(PEMONLIST));
	}
	else {
		return geode::Ok(cheatAPI::isCheating());
	}
}
geode::Result<bool> cheatAPIEvents::isCheatingSpecific() {
	return geode::Ok(cheatAPI::isCheating());
}
geode::Result<void> cheatAPIEvents::setCheatingOne(std::string str) {
	if (str == "ROBTOP") {
		cheatAPI::setCheat(ROBTOP);
		return geode::Ok();
	}
	else if (str == "DEMONLIST") {
		cheatAPI::setCheat(DEMONLIST);
		return geode::Ok();
	}
	else if (str == "GDDL") {
		cheatAPI::setCheat(GDDL);
		return geode::Ok();
	}
	else if (str == "MODMAKEROPINION") {
		cheatAPI::setCheat(MODMAKEROPINION);
		return geode::Ok();
	}
	else if (str == "AREDL") {
		cheatAPI::setCheat(AREDL);
		return geode::Ok();
	}
	else if (str == "PEMONLIST") {
		cheatAPI::setCheat(PEMONLIST);
		return geode::Ok();
	}
	else {
		cheatAPI::setCheat();
		return geode::Ok();
	}
}
geode::Result<void> cheatAPIEvents::setCheatingAll() {
	cheatAPI::setCheat();
	return geode::Ok();
}
geode::Result<void> cheatAPIEvents::endCheatingOne(std::string str) {
	if (str == "ROBTOP") {
		cheatAPI::endCheat(ROBTOP);
		return geode::Ok();
	}
	else if (str == "DEMONLIST") {
		cheatAPI::endCheat(DEMONLIST);
		return geode::Ok();
	}
	else if (str == "GDDL") {
		cheatAPI::endCheat(GDDL);
		return geode::Ok();
	}
	else if (str == "MODMAKEROPINION") {
		cheatAPI::endCheat(MODMAKEROPINION);
		return geode::Ok();
	}
	else if (str == "AREDL") {
		cheatAPI::endCheat(AREDL);
		return geode::Ok();
	}
	else if (str == "PEMONLIST") {
		cheatAPI::endCheat(PEMONLIST);
		return geode::Ok();
	}
	else {
		cheatAPI::endCheat();
		return geode::Ok();
	}
}
geode::Result<void> cheatAPIEvents::endCheatingAll() {
	cheatAPI::endCheat();
	return geode::Ok();
}