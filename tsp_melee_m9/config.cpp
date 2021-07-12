class CfgPatches {
	class tsp_melee_m9 {
		requiredAddons[] = {"tsp_melee"};
		units[] = {};
	};
};

class Extended_PostInit_EventHandlers {
    class melee_m9 {init = "['tsp_meleeWeapon_m9','tsp_meleeWeapon_m9_bipod'] call tsp_fnc_melee_bayonetSwap;";};
};

class rhs_western_rifle_underbarrel_slot;
class rhs_western_rifle_underbarrel_slot_import: rhs_western_rifle_underbarrel_slot {class compatibleItems;};
class CfgWeapons {
	class tsp_meleeWeapon_knifeDown;
	class tsp_meleeWeapon_m9: tsp_meleeWeapon_knifeDown	{
		scope = 2;
		model = "\tsp_melee_m9\m9.p3d";
		picture = "\tsp_melee_m9\gui\ui.paa";
		displayname = "M9 Bayonet";
		descriptionShort = "US Army standard issue bayonet";
	};
	class tsp_meleeWeapon_bipod;
	class tsp_meleeWeapon_m9_bipod: tsp_meleeWeapon_bipod {
		scope = 2;
		displayname = "M9 Bayonet";
		descriptionShort = "US Army standard issue bayonet";
		model = "\tsp_melee_m9\m9bipod.p3d";
		picture = "\tsp_melee_m9\gui\ui.paa";
	};

	class Rifle_Base_F;
	class arifle_MX_Base_F: Rifle_Base_F {class WeaponSlotsInfo;};
	class rhs_weap_m4_Base: arifle_MX_Base_F {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class underBarrelSlot: rhs_western_rifle_underbarrel_slot_import {
				class compatibleItems: compatibleItems {tsp_meleeWeapon_m9_bipod = 1;};
			};
		};
	};
	class rhs_weap_m4a1: rhs_weap_m4_Base {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class underBarrelSlot: underBarrelSlot {
				class compatibleItems;
			};
		};
	};
	class rhs_weap_m4a1_blockII: rhs_weap_m4a1 {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class underBarrelSlot: underBarrelSlot {
				class compatibleItems: compatibleItems {tsp_meleeWeapon_m9_bipod = 0;};
			};
		};
	};
	class rhs_weap_hk416d10: rhs_weap_m4a1 {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class underBarrelSlot: underBarrelSlot {
				class compatibleItems: compatibleItems {tsp_meleeWeapon_m9_bipod = 0;};
			};			
		};
	};
};
