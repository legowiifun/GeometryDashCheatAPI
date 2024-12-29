# CheatAPI

To use as a dependency, use `#include <legowiifun.cheatAPI/include/cheatAPI.hpp>`, and in mod.json, place `"dependencies": [{"id":legowiifun.cheat_api","version":">=1.1.0","importance":"required"}]`

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

You can also interact with this mod using dispatch events. This does not require having the mod as a dependency. To use these, first include `#include <Geode/loader/Dispatch.hpp`
Then, you can use dispatchEvents to communicate with the API. 

`DispatchEvent<>("legowiifun.cheat_api/startCheatAll").post();` - Declares that the player is cheating in all rulesets. Useful for mods like noclip, or speedhack that are obvious cheats.  </br>
`DispatchEvent<std::string>("legowiifun.cheat_api/startCheatOne", string).post();` - Declares that if the player followed the given ruleset, they would be cheating. Rulesets are determined by inputing the string matching the enums above: (eg. "MODMAKEROPINION") </br>
`DispatchEvent<>("legowiifun.cheat_api/endCheatAll").post();` - Declares that a given cheat has been deactivated for all rulesets. </br>
`DispatchEvent<std::string>("legowiifun.cheat_api/endCheatOne", string).post();` - Declares that according to the passed in ruleset, a cheat has been deactivated. Rulesets are determined by inputing the string matching the enums above: (eg. "MODMAKEROPINION")</br>
`DispatchEvent<bool*>("legowiifun.cheat_api/isCheating", bool*).post();`  - Sets the input boolean to true if the player is cheating according to the ruleset designated in the mod settings, and false if they are not. </br>
`DispatchEvent<std::string, bool*>("legowiifun.cheat_api/isCheatingSpecific", string, bool*).post();` - Sets the input boolean to true if the player is cheating according to the ruleset that is passed in, and false if they are not. Rulesets are determined by inputing the string matching the enums above: (eg. "MODMAKEROPINION")</br>