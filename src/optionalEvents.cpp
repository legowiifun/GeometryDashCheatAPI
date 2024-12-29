#include <Geode/Geode.hpp>
#include <Geode/loader/Event.hpp>
#include "../include/cheatAPI.hpp"
#include "../include/optionalEvents.hpp"


using namespace geode::prelude;

// set up filters
template <class>
struct ToFilterImpl;

template <class... Args>
struct ToFilterImpl<geode::DispatchEvent<Args...>> {
	using type = geode::DispatchFilter <Args...>;
};

template <class T>
using ToFilter = typename ToFilterImpl<T>::type;


// declare dispatchEvents
$execute{
	// start cheating on all rulesets
	new EventListener(+[]() {
		// log::debug("recieved start all cheats event!");
		cheatAPI::setCheat();
		return ListenerResult::Stop;
	}, ToFilter<EventStartCheatAll>("legowiifun.cheat_api/startCheatAll"));
	// start cheating on one ruleset: determined by the input string
	new EventListener(+[](std::string str) {
		// log::debug("recieved start one cheat event: {}!",str);
		if(str=="ROBTOP") {
			cheatAPI::setCheat(ROBTOP);
		}
		else if (str == "DEMONLIST") {
			cheatAPI::setCheat(DEMONLIST);
		}
		else if (str == "GDDL") {
			cheatAPI::setCheat(GDDL);
		}
		else if (str == "MODMAKEROPINION") {
			cheatAPI::setCheat(MODMAKEROPINION);
		}
		else if (str == "AREDL") {
			cheatAPI::setCheat(AREDL);
		}
		else if (str == "PEMONLIST") {
			cheatAPI::setCheat(PEMONLIST);
		}
		else {
			cheatAPI::setCheat();
		}
		return ListenerResult::Stop;
		}, ToFilter<EventStartCheatOne>("legowiifun.cheat_api/startCheatOne"));
	// end cheating on all rulesets
	new EventListener(+[]() {
		// log::debug("recieved end all cheats event!");
		cheatAPI::endCheat();
		return ListenerResult::Stop;
		}, ToFilter<EventEndCheatAll>("legowiifun.cheat_api/endCheatAll"));

	// end cheating on one ruleset: determined by the input string
	new EventListener(+[](std::string str) {
		// log::debug("recieved end one cheat event: {}!",str);
		if (str == "ROBTOP") {
			cheatAPI::endCheat(ROBTOP);
		}
		else if (str == "DEMONLIST") {
			cheatAPI::endCheat(DEMONLIST);
		}
		else if (str == "GDDL") {
			cheatAPI::endCheat(GDDL);
		}
		else if (str == "MODMAKEROPINION") {
			cheatAPI::endCheat(MODMAKEROPINION);
		}
		else if (str == "AREDL") {
			cheatAPI::endCheat(AREDL);
		}
		else if (str == "PEMONLIST") {
			cheatAPI::endCheat(PEMONLIST);
		}
		else {
			cheatAPI::endCheat();
		}
		return ListenerResult::Stop;
		}, ToFilter<EventEndCheatOne>("legowiifun.cheat_api/endCheatOne"));

	// set the input boolean to whether the player is currently cheating: based on the ruleset in the settings
	new EventListener(+[](bool* b) {
		// log::debug("recieved is cheating event!");
		*b = cheatAPI::isCheating();
		return ListenerResult::Stop;
		}, ToFilter<EventIsCheating>("legowiifun.cheat_api/isCheating"));

	// set the input boolean to whether the player is currently cheating: based on the input string
	new EventListener(+[](std::string str, bool* b) {
		// log::debug("recieved is specific cheat event: {}!",str);
		if (str == "ROBTOP") {
			*b = cheatAPI::isCheating(ROBTOP);
		}
		else if (str == "DEMONLIST") {
			*b = cheatAPI::isCheating(DEMONLIST);
		}
		else if (str == "GDDL") {
			*b = cheatAPI::isCheating(GDDL);
		}
		else if (str == "MODMAKEROPINION") {
			*b = cheatAPI::isCheating(MODMAKEROPINION);
		}
		else if (str == "AREDL") {
			*b = cheatAPI::isCheating(AREDL);
		}
		else if (str == "PEMONLIST") {
			*b = cheatAPI::isCheating(PEMONLIST);
		}
		else {
			*b = cheatAPI::isCheating();
		}
		return ListenerResult::Stop;
		}, ToFilter<EventIsCheatingSpecific>("legowiifun.cheat_api/isCheatingSpecific"));
}