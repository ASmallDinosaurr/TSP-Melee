class CfgPatches {
	class tsp_melee_okc {
		requiredAddons[] = {"cba_common","tsp_melee"};
		units[] = {};
	};
};

class Extended_PostInit_EventHandlers {
    class melee_okc {init = "['tsp_meleeWeapon_okc','tsp_meleeWeapon_okc_bipod'] call tsp_fnc_melee_bayonetSwap;";};
};

class rhs_western_rifle_underbarrel_slot;
class rhs_western_rifle_underbarrel_slot_import: rhs_western_rifle_underbarrel_slot {class compatibleItems;};
class CfgWeapons {
	class Pistol_Base_F;
	class tsp_meleeWeapon_knifeUp: Pistol_Base_F {
		class meleeInfo {
			class alt {class v1;};
		};
	};
	class tsp_meleeWeapon_okc: tsp_meleeWeapon_knifeUp {
		scope = 2;
		model="\tsp_melee_okc\okc.p3d";
		picture="\tsp_melee_okc\gui\ui.paa";
		displayname="OKC-3S Bayonet";
		descriptionShort="USMC standard issue bayonet";
		class meleeInfo: meleeInfo {
			class alt: alt {class v1: v1 {damage[] = {0.6,0.7,0.8};};};
		};
	};

	class tsp_meleeWeapon_bipod;
	class tsp_meleeWeapon_okc_bipod: tsp_meleeWeapon_bipod {
		scope = 2;
		displayname="OKC-3S Bayonet";
		descriptionShort="USMC standard issue bayonet";
		model="\tsp_melee_okc\okcbipod.p3d";
		picture="\tsp_melee_okc\gui\ui.paa";
	};

	class Rifle_Base_F;
	class arifle_MX_Base_F: Rifle_Base_F {class WeaponSlotsInfo;};
	class rhs_weap_m4_Base: arifle_MX_Base_F {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class underBarrelSlot: rhs_western_rifle_underbarrel_slot_import {
				class compatibleItems: compatibleItems {tsp_meleeWeapon_okc_bipod = 1;};
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
				class compatibleItems: compatibleItems {tsp_meleeWeapon_okc_bipod = 0;};
			};
		};
	};
	class rhs_weap_hk416d10: rhs_weap_m4a1 {
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class underBarrelSlot: underBarrelSlot {
				class compatibleItems: compatibleItems {tsp_meleeWeapon_okc_bipod = 0;};
			};			
		};
	};
};