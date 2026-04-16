/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#define GEODE_DEFINE_EVENT_EXPORTS
#include "../include/cheatAPI.hpp"
#include <unordered_map>

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
/*static int activeCheatRobtop;
static int activeCheatDemonlist;
static int activeCheatGDDL;
static int activeCheatModMakerOpinion;
static int activeCheatAREDL;
static int activeCheatPemonlist;*/
static std::unordered_map<std::string, int> activeCheats;

std::string enumToString(rulesets r) {
	switch (r) {
		case ROBTOP:
			return "ROBTOP";
			break;
		case MODMAKEROPINION:
			return "MODMAKEROPINION";
			break;
		case DEMONLIST:
			return "DEMONLIST";
			break;
		case GDDL:
			return "GDDL";
			break;
		case AREDL:
			return "AREDL";
			break;
		case PEMONLIST:
			return "PEMONLIST";
			break;
		default:
			return "";
	} 
}

bool cheatAPI::isCheating(rulesets r) {
	return activeCheats[enumToString(r)]>0;
}

bool cheatAPI::isCheating() {
	return isCheating(setSetting());
}

void cheatAPI::setCheat(rulesets r) {
	activeCheats[enumToString(r)]++;
}
void cheatAPI::setCheat() {
	for (std::pair pair: activeCheats) {
		pair.second++;
	}
}
void cheatAPI::endCheat(rulesets r) {
	activeCheats[enumToString(r)]--;
}
void cheatAPI::endCheat() {
	for (std::pair pair: activeCheats) {
		pair.second--;
	}
}
bool cheatAPIEvents::isCheatingSpecific(std::string str) {
	return activeCheats.at(str)>0;
}
bool cheatAPIEvents::isCheatingGeneral() {
	return cheatAPI::isCheating();
}
void cheatAPIEvents::setCheatingOne(std::string str) {
	activeCheats[str]++;
}
void cheatAPIEvents::setCheatingAll() {
	cheatAPI::setCheat();
}
void cheatAPIEvents::endCheatingOne(std::string str) {
	activeCheats[str]--;
}
void cheatAPIEvents::endCheatingAll() {
	cheatAPI::endCheat();
}

$on_mod(Loaded) {
	activeCheats["ROBTOP"]=0;
	activeCheats["MODMAKEROPINION"]=0;
	activeCheats["DEMONLIST"]=0;
	activeCheats["GDDL"]=0;
	activeCheats["AREDL"]=0;
	activeCheats["PEMONLIST"]=0;
}