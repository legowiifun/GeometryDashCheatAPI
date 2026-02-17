# CheatAPI

To use as a dependency, use `#include <legowiifun.cheatAPI/include/cheatAPI.hpp>`, and in mod.json, under dependencies, put 
```
	"legowiifun.cheat_api": {
		"version": ">=1.2.3",
		"required": true
	}
```

This provides several useful methods to interact with the mod.

Enum rulesets: 
- ROBTOP: Will levels verified with it get rated? Can it get you leaderboard banned?
- DEMONLIST: Based on https://pointercrate.com/demonlist/
- GDDL: Based on https://gdladder.com/
- MODMAKEROPINION: What is your opinion on it?
- AREDL: Based on https://aredl.net/
- PEMONLIST: based on https://pemonlist.com/

`bool cheatAPI.isCheating();` - Returns true if the player is cheating according to the ruleset designated in the mod settings, and false if they are not. </br>
`bool cheatAPI.isCheating(Ruleset rs);` - Returns true if the player is cheating according to the ruleset that is passed in, and false if they are not. </br>
`void cheatAPI.setCheat(Ruleset rs);` - Declares that if the player followed the given ruleset, they would be cheating. </br>
`void cheatAPI.setCheat();` - Declares that the player is cheating in all rulesets. Useful for mods like noclip, or speedhack that are obvious cheats.  </br>
`void cheatAPI.endCheat(Ruleset rs);` - Declares that according to the passed in ruleset, a cheat has been deactivated. </br>
`void cheatAPI.endCheat();` - Declares that a given cheat has been deactivated for all rulesets. </br>

You can also interact with this mod using an optional API. First, put this in mod.json: 
```
	"legowiifun.cheat_api": {
		"version": ">=1.2.3",
		"required": false
	}
```
Next, use `#include <legowiifun.cheat_api/include/cheatAPI.hpp>`

This provides equivilants to each of the methods listed above. These methods use string parameters instead of the Ruleset parameters, so to use them, use the equivilant strings to the ruleset names. eg. to use the robtop ruleset, pass in "ROBTOP"

`Result<bool> cheatAPIEvents::isCheatingSpecific()` - Returns true if the player is cheating according to the ruleset designated in the mod settings, and false if they are not. This will require using the unwrap method to get the boolean contained in it.</br>
`Result<bool> cheatAPIEvents::isCheatingGeneral(string str)` - Returns true if the player is cheating according to the ruleset that is passed in, and false if they are not. This will require using the unwrap method to get the boolean contained in it.</br>
`void cheatAPIEvents::setCheatingOne(string str);` - Declares that if the player followed the given ruleset, they would be cheating. </br>
`void cheatAPIEvents::setCheatingAll();` - Declares that the player is cheating in all rulesets. Useful for mods like noclip, or speedhack that are obvious cheats.  </br>
`void cheatAPIEvents::endCheatingOne(string str);` - Declares that according to the passed in ruleset, a cheat has been deactivated. </br>
`void cheatAPIEvents::endCheatingAll();` - Declares that a given cheat has been deactivated for all rulesets. </br>