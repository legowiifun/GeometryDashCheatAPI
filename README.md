# CheatAPI

![Mod Version](https://api.geode-sdk.org/v1/mods/legowiifun.cheat_api/status_badge?stat=version)
![Downloads](https://api.geode-sdk.org/v1/mods/legowiifun.cheat_api/status_badge?stat=downloads)
![GD Version](https://api.geode-sdk.org/v1/mods/legowiifun.cheat_api/status_badge?stat=gd_version)
![Geode Version](https://api.geode-sdk.org/v1/mods/legowiifun.cheat_api/status_badge?stat=geode_version)

> [!NOTE]
> **This mod does not modify Geometry Dash on its own.** If you *do* want to modify it, download a mod menu.

> [!NOTE]
> This mod is only useful to mod-to-mod communication (more useful to developers).

## Using this mod in yours
### Normal usage
To use as a dependency, use `#include <legowiifun.cheatAPI/include/cheatAPI.hpp>`, and, in `mod.json`, under dependencies, put 
```
	"legowiifun.cheat_api": {
		"version": ">=1.2.3",
		"required": true
	}
```

### Optional API usage
You can also interact with this mod using an optional API. First, put this in `mod.json`: 
```
	"legowiifun.cheat_api": {
		"version": ">=1.2.3",
		"required": false
	}
```
Next, use `#include <legowiifun.cheat_api/include/cheatAPI.hpp>`.

This provides equivalents for each of the methods listed in the "Normal" section below. These methods use string parameters instead of the Ruleset parameters, so to use them, use the equivalent strings to the ruleset names. (Ex.: To use the RobTop ruleset, pass in `"ROBTOP"`.)

## Valid ruleset names
This is the list of valid rulesets currently in the mod settings and passable to the methods:

Ruleset name as string in code | In-game ruleset setting label | Definition / Source
--- | --- | ---
`"ROBTOP"` | Robtop | Will RobTop rate levels verified with the current game modifications? Can they get you leaderboard-banned?
`"DEMONLIST"` | Pointercrate | https://pointercrate.com/guidelines/eligibility
`"GDDL"` | Geometry Dash Levels List | There isn't a link for this, but their rules are probably different from other GD-related websites.
`"MODMAKEROPINION"` | Mod Makers Opinion | What is my opinion?
`"AREDL"` | All Rated Extreme Demons List | https://aredl.net/guidelines
`"PEMONLIST"` | pemonlist.com | https://pemonlist.com/rules

## Mod methods
### Normal

Returned value type | Method usage format | Function
--- | --- | ---
`bool` | `cheatAPI.isCheating();` | Returns `true` if the player is cheating according to the ruleset designated in the mod settings, and `false` if they aren't.
`bool` | `cheatAPI.isCheating(Ruleset rs);` | Returns `true` if the player is cheating according to the ruleset that is passed in, and `false` if they aren't.
none / `void` | `cheatAPI.setCheat(Ruleset rs);` | Declares that, according to the ruleset passed as the `rs` variable, the player is now cheating.
none / `void` | `cheatAPI.setCheat();` | Declares that the player is now cheating in all rulesets. Useful for obvious cheats like noclip, speedhack, etc.
none / `void` | `cheatAPI.endCheat(Ruleset rs);` | Declares that, according to the ruleset passed as the `rs` variable, the player is no longer cheating.
none / `void` | `cheatAPI.endCheat();` | Declares that the player is now cheating for all rulesets.

### Optional API

Returned value type | Method usage format | Function
--- | --- | ---
`Result<bool>` | `cheatAPIEvents::isCheatingSpecific()` | Returns `true` if the player is cheating according to the ruleset designated in the mod settings, and `false` if they aren't. This will require using the `unwrap` method to get the returned value.
`Result<bool>` | `cheatAPIEvents::isCheatingGeneral(string str)` | Returns `true` if the player is cheating according to the ruleset that is passed in, and `false` if they aren't. This will require using the `unwrap` method to get the returned value.
none / `void` | `cheatAPIEvents::setCheatingOne(string str);` | Declares that, according to the ruleset passed as the `str` variable, the player is now cheating.
none / `void` | `cheatAPIEvents::setCheatingAll();` | Declares that the player is now cheating in all rulesets. Useful for obvious cheats like noclip, speedhack, etc.
none / `void` | `cheatAPIEvents::endCheatingOne(string str);` | Declares that, according to the ruleset passed as the `str` variable, the player is no longer cheating.
none / `void` | `cheatAPIEvents::endCheatingAll();` | Declares that the player is no longer cheating for all rulesets.
