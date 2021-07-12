class CfgPatches {
	class tsp_melee {
		requiredAddons[] = {"cba_common", "tsp_common"};
		units[] = {};
	};
};

//-- FUNCTIONS
class CfgFunctions {
	class tsp_melee {
		class functions {
			class preInit {file = "\tsp_melee\preInit.sqf"; preInit = true;};
			class postInit {file = "\tsp_melee\postInit.sqf"; postInit = true;};
		};
	};
};

//-- WEAPONS
class CfgWeapons {
	//-- Non melee weapons
	class tsp_meleeWeapon_fists {
		class meleeInfo {
			class ready {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_fistReady"};
				};
			};
			class block {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_fistBlock"};
					timing[] = {0, 0, 1.2};
					blockableDamage[] = {
						{"punch", 0.8, "tsp_melee\snd\impact1.ogg"},
						{"stab", 0.25, "tsp_melee\snd\stab1.ogg"}
					};
				};                     
			};
			class main {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_fistPunchLeft"};
					damage[] = {"punch", {0.1, 0.15, 0.2}, 0.5};  //-- Type, quantity, knockout chance
					damageEnviroment[] = {0.35, 0.05, 0, 0, 0};
					reach = 1.5;
					angle = 75;
					timing[] = {0, 0.25, 0.32};  //-- Time to swing, time to impact, total duration
					soundSwing[] = {"tsp_melee\snd\swing1.ogg"};
					soundImpact[] = {"tsp_melee\snd\impact1.ogg"};
					soundKnockout[] = {"tsp_melee\snd\knockout1.ogg"};
				};
			};
			class alt {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_fistPunchRight"};
					damage[] = {"punch", {0.1, 0.15, 0.2}, 0.5};
					damageEnviroment[] = {0.35, 0.05, 0, 0, 0};
					reach = 1.5;
					angle = 75;
					timing[] = {0, 0.25, 0.32};
					soundSwing[] = {"tsp_melee\snd\swing1.ogg"};
					soundImpact[] = {"tsp_melee\snd\impact1.ogg"};
					soundKnockout[] = {"tsp_melee\snd\knockout1.ogg"};
				};
			};
			class kick {
				class v1 {
					animation[] = {"Animation", "tsp_melee_fistKick"};
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
	class tsp_meleeWeapon_rifle {
		class meleeInfo {
			class ready {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_rifleReady"};
				};
			};
			class block {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_rifleBlock"};
					timing[] = {0, 0, 1.3};
					blockableDamage[] = {
						{"punch", 0.9, "tsp_melee\snd\impact1.ogg"},
						{"stab", 0.7, "tsp_melee\snd\slice1.ogg"}
					};
				};                     
			};
			class main {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_rifleButt"};
					damage[] = {"punch", {0.2, 0.3, 0.4}, 1};
					damageEnviroment[] = {0.9, 0.1, 0.05, 0, 0};
					reach = 2;
					angle = 70;
					timing[] = {0.3, 0.6, 1};
					soundSwing[] = {"tsp_melee\snd\swing1.ogg"};
					soundImpact[] = {"tsp_melee\snd\impact1.ogg"};
					soundKnockout[] = {"tsp_melee\snd\knockout1.ogg"};
				};
			};
			class alt {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_rifleJab"};
					damage[] = {"punch", {0.2, 0.3, 0.4}, 0.1};
					damageEnviroment[] = {1, 0.05, 0, 0, 0};
					reach = 2.5;
					angle = 40;
					timing[] = {0.05, 0.1, 0.5};
					soundSwing[] = {"tsp_melee\snd\swing1.ogg"};
					soundImpact[] = {"tsp_melee\snd\impact1.ogg"};
					soundKnockout[] = {"tsp_melee\snd\knockout1.ogg"};
				};
			};
			class kick {
				class v1 {
					animation[] = {"Animation", "tsp_melee_rifleKick"};
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
	class tsp_meleeWeapon_pistol {
		class meleeInfo {
			class ready {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_pistolReady"};
				};
			};
			class block {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_pistolBlock"};
					timing[] = {0, 0, 1.2};
					blockableDamage[] = {
						{"punch", 0.8, "tsp_melee\snd\impact1.ogg"},
						{"stab", 0.25, "tsp_melee\snd\slice1.ogg"}
					};
				};                     
			};
			class main {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_pistolWhip"};
					damage[] = {"punch", {0.2, 0.3, 0.4}, 1};  //-- Type, quantity, knockout chance
					damageEnviroment[] = {0.6, 0.1, 0.05, 0, 0};
					reach = 1.5;
					angle = 70;
					timing[] = {0.2, 0.25, 0.5};  //-- Time to swing, time to impact, total duration
					soundSwing[] = {"tsp_melee\snd\swing1.ogg"};
					soundImpact[] = {"tsp_melee\snd\impact1.ogg"};
					soundKnockout[] = {"tsp_melee\snd\knockout1.ogg"};
				};
			};
			class alt: main {class v1: v1 {}};
			class kick {
				class v1 {
					animation[] = {"Animation", "tsp_melee_pistolKick"};
					damage[] = {"punch", {0.3, 0.4, 0.5}, 0.5};
					damageEnviroment[] = {1, 0.75, 0.1, 0.05, 0};
					reach = 2;
					angle = 50;
					timing[] = {0, 0.25, 0.3};
					soundSwing[] = {"tsp_melee\snd\swing1.ogg"};
					soundImpact[] = {"tsp_melee\snd\impact1.ogg"};
					soundKnockout[] = {"tsp_melee\snd\knockout1.ogg"};
				};
			};
		};
	};

	//-- Pistol slot
	class Pistol;
	class Pistol_Base_F: Pistol	{class WeaponSlotsInfo;};
	class tsp_meleeWeapon_knifeUp: Pistol_Base_F {
		modelOptics = "";
		useModelOptics = true;
		fireLightIntensity = 0;
		magazines[] = {};
		weaponInfoType = "RscWeaponEmpty";			
		handAnim[]={"OFP2_ManSkeleton","\tsp_melee\anim\knifeWpnRestUp.rtm"};	
		class WeaponSlotsInfo {
			mass = 10;
			holsterScale = 0;	
		};
		class meleeInfo {
			moveset = 1;
			movesetRest = "knife";
			movesetReady = "default";
			class ready {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_knifeReadyUp"};
				};
			};
			class block {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_knifeBlock"};
					timing[] = {0, 0, 1.2};
					blockableDamage[] = {
						{"punch", 0.8, "tsp_melee\snd\impact1.ogg"},
						{"stab", 0.5, "tsp_melee\snd\slice1.ogg"}
					};
				};                     
			};
			class main {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_knifeSlashUp"};
					damage[] = {"stab", {0.4, 0.5, 0.6}, 1};  //-- Type, quantity, knockout chance
					damageEnviroment[] = {0.6, 0.05, 0, 0, 0};
					reach = 1.5;
					angle = 70;
					timing[] = {0.1, 0.4, 0.5};  //-- Time to swing, time to impact, total duration
					soundSwing[] = {"tsp_melee\snd\swing1.ogg"};
					soundImpact[] = {"tsp_melee\snd\stab1.ogg","tsp_melee\snd\stab2.ogg"};
					soundKnockout[] = {"tsp_melee\snd\stab3.ogg"};
				};
			};
			class alt {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_knifeStabUp"};
					damage[] = {"stab", {0.6, 0.7, 0.8}, 1};  //-- Type, quantity, knockout chance
					damageEnviroment[] = {0.6, 0.05, 0, 0, 0};
					reach = 1.5;
					angle = 60;
					timing[] = {0.3, 0.5, 0.6};  //-- Time to swing, time to impact, total duration
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
	class tsp_meleeWeapon_knifeDown: tsp_meleeWeapon_knifeUp {
		handAnim[]={"OFP2_ManSkeleton","\tsp_melee\anim\knifeWpnRestDown.rtm"};	
		class meleeInfo: meleeInfo {
			moveset = 1;
			movesetRest = "knife";
			movesetReady = "default";
			class ready {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_knifeReadyDown"};
				};
			};
			class block: block {};
			class main {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_knifeSlashDown"};
					damage[] = {"stab", {0.4, 0.5, 0.6}, 1};  //-- Type, quantity, knockout chance
					damageEnviroment[] = {0.6, 0.05, 0, 0, 0};
					reach = 1.5;
					angle = 70;
					timing[] = {0.1, 0.4, 0.5};  //-- Time to swing, time to impact, total duration
					soundSwing[] = {"tsp_melee\snd\swing1.ogg"};
					soundImpact[] = {"tsp_melee\snd\stab1.ogg","tsp_melee\snd\stab2.ogg"};
					soundKnockout[] = {"tsp_melee\snd\stab3.ogg"};
				};
			};
			class alt: alt {
				class v1: v1  {animation[] = {"Gesture", "tsp_melee_knifeStabDown"};};
				class v2: v1 {animation[] = {"Gesture", "tsp_melee_knifeStabDown2"};};
			};
			class kick: kick {};
		};
	};

	//-- Attachment slots
	class bipod_01_F_snd;
	class tsp_meleeWeapon_bipod: bipod_01_F_snd {
		scope = 0;
		class itemInfo {hasBipod = false; type = 302; mass = 10;};
		class meleeInfo {
			class ready {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_rifleReady"};
				};
			};
			class block {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_rifleBlock"};
					timing[] = {0, 0, 1.3};
					blockableDamage[] = {
						{"punch", 0.9, "tsp_melee\snd\impact1.ogg"},
						{"stab", 0.7, "tsp_melee\snd\slice1.ogg"}
					};
				};                     
			};
			class main {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_rifleJab"};
					damage[] = {"stab", {0.6, 0.7, 0.8}, 1};
					damageEnviroment[] = {1, 0.05, 0, 0, 0};
					reach = 3;
					angle = 40;
					timing[] = {0.05, 0.1, 0.5};
					soundSwing[] = {"tsp_melee\snd\swing1.ogg"};
					soundImpact[] = {"tsp_melee\snd\stab1.ogg","tsp_melee\snd\stab2.ogg"};
					soundKnockout[] = {"tsp_melee\snd\stab3.ogg"};
				};
			};
            class alt {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_rifleButt"};
					damage[] = {"punch", {0.2, 0.3, 0.4}, 1};
					damageEnviroment[] = {0.9, 0.1, 0.05, 0, 0};
					reach = 2;
					angle = 70;
					timing[] = {0.3, 0.6, 1};
					soundSwing[] = {"tsp_melee\snd\swing1.ogg"};
					soundImpact[] = {"tsp_melee\snd\impact1.ogg"};
					soundKnockout[] = {"tsp_melee\snd\knockout1.ogg"};
				};
			};
			class kick {
				class v1 {
					animation[] = {"Animation", "tsp_melee_rifleKick"};
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
	class inventoryFlashLightItem_Base_F;
	class tsp_meleeWeapon_pointer: tsp_meleeWeapon_bipod {
		class itemInfo: inventoryFlashLightItem_Base_F {class Pointer {};class FlashLight {}; mass = 10;};
		class meleeInfo: meleeInfo {};
	};

	//-- Launcher slot
	class launch_RPG32_F;
	class tsp_meleeWeapon_axe: launch_RPG32_F {
		scope = 0;
		modelOptics = "";
		useModelOptics = true;
		fireLightIntensity = 0;		
		magazines[] = {};
		weaponInfoType = "RscWeaponEmpty";
		handAnim[] = {"OFP2_ManSkeleton","\tsp_melee\anim\axeWpnRest.rtm"};
		class meleeInfo {
			class ready {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_axeReady"};
				};
			};
			class block {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_axeBlock"};
					timing[] = {0, 0, 0.9};
					blockableDamage[] = {
						{"punch", 0.9, "tsp_melee\snd\impact1.ogg"},
						{"stab", 0.9, "tsp_melee\snd\slice1.ogg"}
					};
				};                     
			};
			class main {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_axeChop"};
					damage[] = {"stab", {0.7, 0.8, 0.9}, 1};
					damageEnviroment[] = {1, 0.3, 0.3, 0.1, 0};
					reach = 2.5;
					angle = 60;
					timing[] = {0.2, 0.4, 0.9};
					soundSwing[] = {"tsp_melee\snd\swing1.ogg"};
					soundImpact[] = {"tsp_melee\snd\stab1.ogg","tsp_melee\snd\stab2.ogg"};
					soundKnockout[] = {"tsp_melee\snd\stab3.ogg"};
				};
			};
            class alt {
				class v1 {
					animation[] = {"Gesture", "tsp_melee_axeSlash"};
					damage[] = {"stab", {0.8, 0.85, 0.9}, 1};
					damageEnviroment[] = {1, 0.3, 0.3, 0.1, 0};
					reach = 2.5;
					angle = 60;
					timing[] = {0.2, 0.4, 1};
					soundSwing[] = {"tsp_melee\snd\swing1.ogg"};
					soundImpact[] = {"tsp_melee\snd\stab1.ogg","tsp_melee\snd\stab2.ogg"};
					soundKnockout[] = {"tsp_melee\snd\stab3.ogg"};
				};
			};
			class kick {
				class v1 {
					animation[] = {"Animation", "tsp_melee_axeKick"};
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

//-- ANIMATIONS
class CfgMovesBasic {
    class default;
    class DefaultDie;
    class ManActions {
		tsp_melee_rifleKick = "tsp_melee_rifleKick";
		tsp_melee_pistolKick = "tsp_melee_pistolKick";
		tsp_melee_fistKick = "tsp_melee_fistKick";
		tsp_melee_knifeKick = "tsp_melee_knifeKick";
		tsp_melee_axeKick = "tsp_melee_axeKick";
		tsp_melee_rifleButt[] = {"tsp_melee_rifleButt", "Gesture"};
		tsp_melee_rifleJab[] = {"tsp_melee_rifleJab", "Gesture"};
		tsp_melee_rifleReady[] = {"tsp_melee_rifleReady", "Gesture"};		
		tsp_melee_rifleBlock[] = {"tsp_melee_rifleBlock", "Gesture"};
		tsp_melee_pistolWhip[] = {"tsp_melee_pistolWhip", "Gesture"};
		tsp_melee_pistolReady[] = {"tsp_melee_pistolReady", "Gesture"};		
		tsp_melee_pistolBlock[] = {"tsp_melee_pistolBlock", "Gesture"};
		tsp_melee_fistPunchRight[] = {"tsp_melee_fistPunchRight", "Gesture"};
		tsp_melee_fistPunchLeft[] = {"tsp_melee_fistPunchLeft", "Gesture"};
		tsp_melee_fistReady[] = {"tsp_melee_fistReady", "Gesture"};		
		tsp_melee_fistBlock[] = {"tsp_melee_fistBlock", "Gesture"};
		tsp_melee_knifeSlashUp[] = {"tsp_melee_knifeSlashUp", "Gesture"};
		tsp_melee_knifeSlashUp2[] = {"tsp_melee_knifeSlashUp2", "Gesture"};
		tsp_melee_knifeSlashDown[] = {"tsp_melee_knifeSlashDown", "Gesture"};
		tsp_melee_knifeStabUp[] = {"tsp_melee_knifeStabUp", "Gesture"};
		tsp_melee_knifeStabDown[] = {"tsp_melee_knifeStabDown", "Gesture"};
		tsp_melee_knifeStabDown2[] = {"tsp_melee_knifeStabDown2", "Gesture"};
		tsp_melee_knifeReadyUp[] = {"tsp_melee_knifeReadyUp", "Gesture"};
		tsp_melee_knifeReadyDown[] = {"tsp_melee_knifeReadyDown", "Gesture"};
		tsp_melee_knifeBlock[] = {"tsp_melee_knifeBlock", "Gesture"};
		tsp_melee_axeChop[] = {"tsp_melee_axeChop", "Gesture"};
		tsp_melee_axeSlash[] = {"tsp_melee_axeSlash", "Gesture"};
		tsp_melee_axeReady[] = {"tsp_melee_axeReady", "Gesture"};	
		tsp_melee_axeBlock[] = {"tsp_melee_axeBlock", "Gesture"};	
	};
};

class CfgMovesMaleSdr: CfgMovesBasic {
    class States {
        class CutSceneAnimationBase;
        class tsp_melee_rifleKick: CutSceneAnimationBase {
			canReload = false;
			head = "headDefault";
			speed = 1.7;	
			interpolationSpeed = 2;			
			file="tsp_melee\anim\rifleKick.rtm";
			InterpolateTo[] = {"AmovPercMstpSrasWrflDnon", 1};
			InterpolateFrom[] = {"AmovPercMstpSrasWrflDnon", 1};
			leftHandIKCurve[] = {1};
			rightHandIKCurve[] = {1};			
			weaponIK = 1;
		};
		class tsp_melee_pistolKick: tsp_melee_rifleKick {
			file="tsp_melee\anim\pistolKick.rtm";
			InterpolateTo[] = {"AmovPercMstpSrasWpstDnon", 1};
			InterpolateFrom[] = {"AmovPercMstpSrasWpstDnon", 1};
			leftHandIKCurve[] = {0,1, 0.2,0, 0.8,0, 1,1};
			showHandgun = true;
			weaponIK = 0;
		};
		class tsp_melee_fistKick: tsp_melee_rifleKick {
			file="tsp_melee\anim\fistKick.rtm";
			InterpolateTo[] = {"AmovPercMstpSnonWnonDnon", 1};
			InterpolateFrom[] = {"AmovPercMstpSnonWnonDnon", 1};
			leftHandIKCurve[] = {0};
			rightHandIKCurve[] = {0};
			weaponIK = 0;
		};
		class tsp_melee_knifeKick: tsp_melee_pistolKick {
			file="tsp_melee\anim\knifeKick.rtm";
			leftHandIKCurve[] = {0};
			rightHandIKCurve[] = {0};
		};	
		class tsp_melee_axeKick: tsp_melee_fistKick {
			InterpolateTo[] = {"AmovPercMstpSrasWlnrDnon", 1};
			InterpolateFrom[] = {"AmovPercMstpSrasWlnrDnon", 1};
			leftHandIKCurve[] = {1};
			rightHandIKCurve[] = {1};
			weaponIK = 4;
		};	
	};
};

class CfgGesturesMale {
	skeletonName = "OFP2_ManSkeleton";
	class Default {};
	class States {
		class GestureNo;
		class tsp_melee_rifleButt: GestureNo {	
			file = "tsp_melee\anim\rifleButt.rtm";
			mask = "meleeRifle";
			interpolationSpeed = 5;
			speed = 1;			
			leftHandIKCurve[] = {1};
			rightHandIKCurve[] = {1};			
			canPullTrigger = false;		
			enableBinocular = false;
			enableMissile = false;
			enableOptics = false;
		};
		class tsp_melee_rifleJab: tsp_melee_rifleButt {	
			file = "tsp_melee\anim\rifleJab.rtm";
			speed = 2;
		};
		class tsp_melee_rifleReady: tsp_melee_rifleButt {	
			file = "tsp_melee\anim\rifleReady.rtm";
			interpolationSpeed = 3;	
			speed = 0.5;					
			looped = true;			
		};
		class tsp_melee_rifleBlock: tsp_melee_rifleButt {	
			file = "tsp_melee\anim\rifleBlock.rtm";
			interpolationSpeed = 4;
			speed = 0.5;
		};
		class tsp_melee_pistolWhip: tsp_melee_rifleButt {	
			file = "tsp_melee\anim\pistolWhip.rtm";
			mask = "meleePistol";
			interpolationSpeed = 3;
			speed = 1.5;
			leftHandIKCurve[] = {0,1, 0.2,0, 0.8,0, 1,1};			
		};
		class tsp_melee_pistolReady: tsp_melee_pistolWhip {	
			file = "tsp_melee\anim\pistolReady.rtm";
			mask = "meleePistol_noHands";
			interpolationSpeed = 3;
			speed = 0.5;
			looped = true;	
			leftHandIKCurve[] = {1};
			rightHandIKCurve[] = {1};
		};
		class tsp_melee_pistolBlock: tsp_melee_pistolWhip {	
			file = "tsp_melee\anim\pistolBlock.rtm";
			speed = 0.5;
			canPullTrigger = true;
			disableWeapons = false;	
		};
		class tsp_melee_fistPunchRight: tsp_melee_rifleButt {	
			file = "tsp_melee\anim\fistPunchRight.rtm";
			mask = "meleeFist";
			interpolationSpeed = 3;
			speed = 3.0;			
		};
		class tsp_melee_fistPunchLeft: tsp_melee_fistPunchRight {	
			file = "tsp_melee\anim\fistPunchLeft.rtm";	
		};
		class tsp_melee_fistReady: tsp_melee_fistPunchRight {	
			file = "tsp_melee\anim\fistReady.rtm";
			speed = 0.5;
			looped = true;			
		};
		class tsp_melee_fistBlock: tsp_melee_fistPunchRight {	
			file = "tsp_melee\anim\fistBlock.rtm";
			speed = 1.0;			
		};
		class tsp_melee_knifeSlashUp: tsp_melee_fistPunchRight {	
			file = "tsp_melee\anim\knifeSlashUp.rtm";	
			mask = "meleeKnife";
			speed = 2;
			leftHandIKCurve[] = {0};
			rightHandIKCurve[] = {0};	
		};
		class tsp_melee_knifeSlashUp2: tsp_melee_knifeSlashUp {	
			file = "tsp_melee\anim\knifeSlashUp2.rtm";	
		};
		class tsp_melee_knifeSlashDown: tsp_melee_knifeSlashUp {	
			file = "tsp_melee\anim\knifeSlashDown.rtm";	
			speed = 1.35;
		};
		class tsp_melee_knifeStabUp: tsp_melee_knifeSlashUp {	
			file = "tsp_melee\anim\knifeStabUp.rtm";	
			speed = 1.5;
		};
		class tsp_melee_knifeStabDown: tsp_melee_knifeStabUp {	
			file = "tsp_melee\anim\knifeStabDown.rtm";
			speed = 1.7;
			rightHandIKBeg = 1;
			rightHandIKCurve[] = {1};	
			rightHandIKEnd = 1;
		};
		class tsp_melee_knifeStabDown2: tsp_melee_knifeStabDown {	
			file = "tsp_melee\anim\knifeStabDown2.rtm";
		};
		class tsp_melee_knifeReadyUp: tsp_melee_knifeSlashUp {	
			file = "tsp_melee\anim\knifeReadyUp.rtm";
			looped = true;			
		};
		class tsp_melee_knifeReadyDown: tsp_melee_knifeReadyUp {	
			file = "tsp_melee\anim\knifeReadyDown.rtm";
			rightHandIKBeg = 1;
			rightHandIKCurve[] = {1};	
			rightHandIKEnd = 1;
		};
		class tsp_melee_knifeBlock: tsp_melee_knifeSlashUp {	
			file = "tsp_melee\anim\knifeBlock.rtm";
			speed = 0.1;
		};
		class tsp_melee_axeChop: tsp_melee_rifleButt {	
			file = "tsp_melee\anim\axeChop.rtm";
			mask = "meleeAxe";		
		};
		class tsp_melee_axeSlash: tsp_melee_axeChop {	
			file = "tsp_melee\anim\axeSlash.rtm";	
		};
		class tsp_melee_axeReady: tsp_melee_axeChop {	
			file = "tsp_melee\anim\axeReady.rtm";
			mask = "meleeAxe";
			interpolationSpeed = 3;
			looped = true;			
		};
		class tsp_melee_axeBlock: tsp_melee_axeChop {	
			file = "tsp_melee\anim\axeBlock.rtm";	
		};
	};
	class BlendAnims {
		meleePistol[] = {
			"LeftShoulder",
			1,
			"LeftArm",
			1,
			"LeftArmRoll",
			1,
			"LeftForeArm",
			1,
			"LeftForeArmRoll",
			1,
			"LeftHand",
			1,
			"LeftHandRing",
			1,
			"LeftHandPinky1",
			1,
			"LeftHandPinky2",
			1,
			"LeftHandPinky3",
			1,
			"LeftHandRing1",
			1,
			"LeftHandRing2",
			1,
			"LeftHandRing3",
			1,
			"LeftHandMiddle1",
			1,
			"LeftHandMiddle2",
			1,
			"LeftHandMiddle3",
			1,
			"LeftHandIndex1",
			1,
			"LeftHandIndex2",
			1,
			"LeftHandIndex3",
			1,
			"LeftHandThumb1",
			1,
			"LeftHandThumb2",
			1,
			"LeftHandThumb3",
			1,
			"RightShoulder",
			1,
			"RightArm",
			1,
			"RightHand",
			1,
			"RightArmRoll",
			1,
			"RightForeArm",
			1,
			"RightForeArmRoll",
			1,
			"Spine",
			0.2,
			"Spine1",
			0.3,
			"Spine2",
			1,
			"Spine3",
			1
		};
		meleePistol_noHands[] = {
			"LeftShoulder",
			1,
			"LeftArm",
			1,
			"LeftArmRoll",
			1,
			"LeftForeArm",
			1,
			"LeftForeArmRoll",
			1,
			"LeftHand",
			1,
			"RightShoulder",
			1,
			"RightArm",
			1,
			"RightHand",
			1,
			"RightArmRoll",
			1,
			"RightForeArm",
			1,
			"RightForeArmRoll",
			1,
			"Spine",
			0.2,
			"Spine1",
			0.3,
			"Spine2",
			1,
			"Spine3",
			1
		};
		meleeRifle[] = {
			"weapon",
			1,
			"Spine",
			1,
			"Spine1",
			1,
			"Spine2",
			1,
			"Spine3",
			1
		};	
		meleeFist[] = {
			"LeftShoulder",
			0.5,
			"LeftArm",
			1,
			"LeftArmRoll",
			1,
			"LeftForeArm",
			1,
			"LeftForeArmRoll",
			1,
			"LeftHand",
			1,
			"LeftHandRing",
			1,
			"LeftHandPinky1",
			1,
			"LeftHandPinky2",
			1,
			"LeftHandPinky3",
			1,
			"LeftHandRing1",
			1,
			"LeftHandRing2",
			1,
			"LeftHandRing3",
			1,
			"LeftHandMiddle1",
			1,
			"LeftHandMiddle2",
			1,
			"LeftHandMiddle3",
			1,
			"LeftHandIndex1",
			1,
			"LeftHandIndex2",
			1,
			"LeftHandIndex3",
			1,
			"LeftHandThumb1",
			1,
			"LeftHandThumb2",
			1,
			"LeftHandThumb3",
			1,
			"RightShoulder",
			0.5,
			"RightArm",
			1,
			"RightArmRoll",
			1,
			"RightForeArm",
			1,
			"RightForeArmRoll",
			1,
			"RightHand",
			1,
			"RightHandRing",
			1,
			"RightHandPinky1",
			1,
			"RightHandPinky2",
			1,
			"RightHandPinky3",
			1,
			"RightHandRing1",
			1,
			"RightHandRing2",
			1,
			"RightHandRing3",
			1,
			"RightHandMiddle1",
			1,
			"RightHandMiddle2",
			1,
			"RightHandMiddle3",
			1,
			"RightHandIndex1",
			1,
			"RightHandIndex2",
			1,
			"RightHandIndex3",
			1,
			"RightHandThumb1",
			1,
			"RightHandThumb2",
			1,
			"RightHandThumb3",
			1
		};
		meleeKnife[] = {
			"Neck",
			1,
			"Spine",
			1,
			"Spine1",
			1,
			"Spine2",
			1,
			"Spine3",
			1,
			"LeftShoulder",
			1,
			"LeftArm",
			1,
			"LeftArmRoll",
			1,
			"LeftForeArm",
			1,
			"LeftForeArmRoll",
			1,
			"LeftHand",
			1,
			"LeftHandRing",
			1,
			"LeftHandPinky1",
			1,
			"LeftHandPinky2",
			1,
			"LeftHandPinky3",
			1,
			"LeftHandRing1",
			1,
			"LeftHandRing2",
			1,
			"LeftHandRing3",
			1,
			"LeftHandMiddle1",
			1,
			"LeftHandMiddle2",
			1,
			"LeftHandMiddle3",
			1,
			"LeftHandIndex1",
			1,
			"LeftHandIndex2",
			1,
			"LeftHandIndex3",
			1,
			"LeftHandThumb1",
			1,
			"LeftHandThumb2",
			1,
			"LeftHandThumb3",
			1,
			"RightShoulder",
			1,
			"RightArm",
			1,
			"RightArmRoll",
			1,
			"RightForeArm",
			1,
			"RightForeArmRoll",
			1,
			"RightHand",
			1,
			"RightHandRing",
			1,
			"RightHandPinky1",
			1,
			"RightHandPinky2",
			1,
			"RightHandPinky3",
			1,
			"RightHandRing1",
			1,
			"RightHandRing2",
			1,
			"RightHandRing3",
			1,
			"RightHandMiddle1",
			1,
			"RightHandMiddle2",
			1,
			"RightHandMiddle3",
			1,
			"RightHandIndex1",
			1,
			"RightHandIndex2",
			1,
			"RightHandIndex3",
			1,
			"RightHandThumb1",
			1,
			"RightHandThumb2",
			1,
			"RightHandThumb3",
			1
		};
		meleeAxe[] = {
			"Launcher",
			1
		};	
	};
};