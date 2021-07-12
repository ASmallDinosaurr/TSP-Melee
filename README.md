# TSP Melee
This is a mod for ArmA that adds the ability to use melee. It works with weapons like rifles and pistols as well as with your fists. Furthermore, there are also various  melee weapons included such as knives and axes.

## Usage
This mod functions by defining a new mode that weapons can be used in called the melee mode. By default, double tapping F will put your player into melee mode and doing it again will exit it. Melee mode can be toggled for all rifles/pistols as well as various melee weapons. With no weapon equipped, going into melee mode will bring up your fists. You cannot go into melee mode with most rocket launchers. 

Once in melee mode your mouse controls what actions you can do:  
- **Left Click** - Main attack  
- **Right Click** - Secondary attack  
- **Pressing Scroll Wheel** - Block  
- **Rolling Scroll Wheel** - Kick  

## Requirements/Compatibility
- [CBA_A3](https://github.com/CBATeam/CBA_A3)
- [ACE3](https://github.com/acemod/ACE3) (Optional)
- TSP Breach (Optional, enables door kicking)

## Configuration
### CBA Settings:
- **Enable Melee** - Enables/Disables melee mode activation.  
- **Enable Knife Moveset** - Enables custom movesets for knives where the player holds it at his side  
- **Knife Moveset Polling Rate** - How often the code checks for animation changes (seconds). Faster = smoother but less perfomant.  

### CBA Controls:
- **Melee (Double Tap)[Unnassigned]** - When double tapped and held down you will go into melee mode, releasing the key exits melee mode.  
- **Melee (Toggle)[Unnassigned]** - When pressed you will go into melee mode, doing it again exits melee mode.  
- **Melee (Double Tap, Toggle)[F]** - When double tapped you will go into melee mode, doing it again exits melee mode.  

## How to Compile
The folders can be packed into .pbo files using ArmA3Tools' Addon Builder.

## Creating your own Melee Weapons
You can easily define your own melee weapons/attachments by inheriting some of the base weapons that come with the mod:
- tsp_meleeWeapon_fists  
- tsp_meleeWeapon_rifle  
- tsp_meleeWeapon_pistol  
- tsp_meleeWeapon_knifeUp  
- tsp_meleeWeapon_knifeDown  
- tsp_meleeWeapon_axe  
- tsp_meleeWeapon_bipod (for bayonets)  
- tsp_meleeWeapon_pointer (for bayonets)  

If you want to completely customize your melee weapon, this can be done by adding some config values to the weapon's class. Below is the configuration for a knife.
```c++
class CfgWeapons {
	class myMeleeWeapon {
		class meleeInfo {
			moveset = 1;  //-- Enable custom moveset (0 - false, 1 - true)
			movesetRest = "knife";  //-- What moveset to use when not in melee mode
			movesetReady = "default";  //-- What moveset to use when in melee mode
			class ready {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_knifeReadyUp"};  //-- Animation played in ready state in melee mode
				};
			};
			class block {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_knifeBlock"};  //-- What animation/gesture to play when blocking {"Gesture"/"Animation", "gesture/anim classname"}
					timing[] = {0, 0, 1.2};  //-- Time to swing, time to impact, total duration (only total duration matters for blocking)
					blockableDamage[] = {  //-- Types of damage that can be blocked
						{"punch", 0.8, "tsp_melee\snd\impact1.ogg"},  //-- {"punch"/"stab", effectiveness value (0-1), sound to play on blocking}
						{"stab", 0.5, "tsp_melee\snd\slice1.ogg"}
					};
				};                     
			};
			class main {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_knifeSlashUp"};  //-- Animation played when doing main attack {"Gesture"/"Animation", "gesture/anim classname"}
					damage[] = {"stab", {0.4, 0.5, 0.6}, 1};  //-- {Damage type, effectiveness (random value chosen)(0-1), knockout chance(0-1)}
					damageEnviroment[] = {0.6, 0.05, 0, 0, 0};  //-- Damage used for breaking glass and breacking with tsp_breach {glass, civil doors, military doors, reinforced doors, walls}(0-1)
					reach = 1.5;  //-- How far the weapon can reach (meters)
					angle = 70;  //-- Arc of how wide weapon spread is/how wide the swing is (degrees)
					timing[] = {0.1, 0.4, 0.5};  //-- Time to swing, time to impact, total duration
					soundSwing[] = {"tsp_melee\snd\swing1.ogg"};  //-- Sound played on swing
					soundImpact[] = {"tsp_melee\snd\stab1.ogg","tsp_melee\snd\stab2.ogg"};  //-- Sound played on impact
					soundKnockout[] = {"tsp_melee\snd\stab3.ogg"};  //-- Sound played on knocking opponent unconscious
				};
			};
			class alt {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_knifeStabUp"};
					damage[] = {"stab", {0.6, 0.7, 0.8}, 1};
					damageEnviroment[] = {0.6, 0.05, 0, 0, 0};
					reach = 1.5;
					angle = 60;
					timing[] = {0.3, 0.5, 0.6};
					soundSwing[] = {"tsp_melee\snd\swing1.ogg"};
					soundImpact[] = {"tsp_melee\snd\stab1.ogg","tsp_melee\snd\stab2.ogg"};
					soundKnockout[] = {"tsp_melee\snd\stab3.ogg"};
				};
			};
			class kick {
				class v1 {
					animation[] = {"Animation", "tsp_melee_knifeKick"};
					damage[] = {"punch", {0.3, 0.4, 0.5}, 0.5};
					damageEnviroment[] = {1, 0.75, 0.1, 0.05, 0};
					reach = 2;
					angle = 50;
					timing[] = {0, 0.25, 0.6};
					soundSwing[] = {"tsp_melee\snd\swing1.ogg"};
					soundImpact[] = {"tsp_melee\snd\impact1.ogg"};
					soundKnockout[] = {"tsp_melee\snd\knockout1.ogg"};
				};
			};
		};
    };
};
