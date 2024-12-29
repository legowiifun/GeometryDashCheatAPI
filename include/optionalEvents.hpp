#pragma once
#ifndef LEGOWIIFUN_CHEAT_API_EVENTS
#define LEGOWIIFUN_CHEAT_API_EVENTS
// include necessary headers
#include <Geode/Geode.hpp>
#include<Geode/loader/Dispatch.hpp>
using namespace geode::prelude;

// declare dispatchEvents
using EventStartCheatAll = geode::DispatchEvent<>;
using EventStartCheatOne = geode::DispatchEvent<std::string>;
using EventEndCheatAll = geode::DispatchEvent<>;
using EventEndCheatOne = geode::DispatchEvent<std::string>;
using EventIsCheating = geode::DispatchEvent<bool*>;
using EventIsCheatingSpecific = geode::DispatchEvent<std::string, bool*>;

#endif