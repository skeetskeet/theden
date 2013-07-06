private["_display","_btnRespawn","_btnAbort","_timeOut","_timeMax","_isDead","_weapons","_newtime","_state","_closeit"];
	disableSerialization;
		waitUntil {
			_display = findDisplay 49;
			!isNull _display;
		};
		_btnRespawn = _display displayCtrl 1010;
		_btnAbort = _display displayCtrl 104;
		_btnRespawn ctrlEnable false;
		_btnAbort ctrlEnable false;
		_timeOut = 0;
		_timeMax = 10;
		_state = currentWeapon player;
		_weapons = ['glock17_EP1','Colt1911','M9','M9SD','Makarov','MakarovSD','revolver_EP1','Sa61_EP1','UZI_EP1'];
		_newtime = 300;
		//_closeit = _display closeDisplay 49;

		
		dayz_lastCheckSave = time;
		
		if(r_player_dead) exitWith {_btnAbort ctrlEnable true;};
		if(r_fracture_legs) exitWith {_btnRespawn ctrlEnable true; _btnAbort ctrlEnable true;};
		//if(_state in _weapons) exitWith { 
		//	_closeit;
		//	cutText ["-SKEETERS ANTIDUPE- Switch to primary weapon, or drop pistol, or put pistol in backpack to log out -SKEETERS ANTIDUPE-", "PLAIN"];
		//};	
			
		//force gear save
		if (time - dayz_lastCheckSave > 10) then {
			call dayz_forceSave;
		};			
					
		while {!isNull _display} do {
			switch true do {
				case ({isPlayer _x} count (player nearEntities ["AllVehicles", 6]) > 1) : {
					_btnAbort ctrlEnable false;
					cutText [localize "str_abort_playerclose", "PLAIN DOWN"];
				};
				case (_timeOut < _timeMax && count (player nearEntities ["zZombie_Base", 35]) > 0) : {
					_btnAbort ctrlEnable false;
					cutText [format [localize "str_abort_zedsclose", (_timeMax - _timeOut)], "PLAIN DOWN"];
				};
				case (player getVariable["combattimeout", 0] >= time) : {
					_btnAbort ctrlEnable false;
					cutText [localize "str_abort_playerincombat", "PLAIN DOWN"];					
				};
				case (_state in _weapons) : {
				    _display closeDisplay 49;
					//cutText ["-SKEETERS ANTIDUPE- Switch to primary weapon, or drop pistol, or put pistol in backpack to log out -SKEETERS ANTIDUPE-", "PLAIN"];
					//hint ("-SKEETERS ANTIDUPE- Switch to primary weapon, or drop pistol, or put pistol in backpack to log out -SKEETERS ANTIDUPE-");
					titleText ["-SKEETERS ANTIDUPE- Switch to primary weapon, or drop pistol, or put pistol in backpack to log out -SKEETERS ANTIDUPE-", "PLAIN", "5"];
				};	
				default {
					_btnAbort ctrlEnable true;
					cutText ["Thank You For Playing In The Den", "PLAIN DOWN"];				
				};
			};
			//sleep 0.0001;
			_timeOut = _timeOut + 1;
		};
		cutText ["", "PLAIN DOWN"];
