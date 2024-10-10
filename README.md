# CheatAPI

To use, use `#include <legowiifun.cheatAPI/include/cheatAPI.hpp>`

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
