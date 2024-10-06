# CheatAPI

To use, use #include <legowiifun.cheatAPI/include/isCheating.hpp>

enum rulesets: 
ROBTOP: Will levels verified with it get rated? Can it get you leaderboard banned? What does Robtop Think?
MODMAKEROPINION: What is your opinion on it? 

bool cheatAPI.isCheating(); returns true if the player is cheating according to the ruleset designated in the mod settings, and false if they are not
bool cheatAPI.isCheating(Ruleset rs); returns true if the player is cheating according to the ruleset that is passed in, and false if they are not
void cheatAPI.setCheat(Ruleset rs); declares that if the player followed the given ruleset, they would be cheating
void cheatAPI.setCheat(); declares that the player is cheating in all rulesets. Useful for mods like noclip, or speedhack that are obvious cheats
void cheatAPI.endCheat(Ruleset rs); declares that according to the passed in ruleset, a cheat has been deactivated. 
void cheatAPI.endCheat(); declares that a given cheat has been deactivated for all rulesets. 