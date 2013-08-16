//                         _         _                   _                _        ______ 
//                        | |       | |                 | |              | |       | ___ \
//   _ __ ___    __ _   __| |  ___  | |__   _   _   ___ | | __ ___   ___ | |_  ___ | |_/ /
//  | '_ ` _ \  / _` | / _` | / _ \ | '_ \ | | | | / __|| |/ // _ \ / _ \| __|/ _ \|    / 
//  | | | | | || (_| || (_| ||  __/ | |_) || |_| | \__ \|   <|  __/|  __/| |_|  __/| |\ \ 
//  |_| |_| |_| \__,_| \__,_| \___| |_.__/  \__, | |___/|_|\_\\___| \___| \__|\___|\_| \_|
//                                           __/ |                                        
//                                          |___/                                          


private["_display","_btnRespawn","_btnAbort","_timeOut","_timeMax","_isDead","_weapons","_newtime","_state"];
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
		_state = currentWeapon player; //checks to see if player has a pistol
		_weapons = ['glock17_EP1','Colt1911','M9','M9SD','Makarov','MakarovSD','revolver_EP1','Sa61_EP1','UZI_EP1']; //players cannot abort while holding a pistol
		_newtime = 300; //used this, because after _timeMax was done player was able to abort

		
		dayz_lastCheckSave = time;
		
		if(r_player_dead) exitWith {_btnAbort ctrlEnable true;};
		if(r_fracture_legs) exitWith {_btnRespawn ctrlEnable true; _btnAbort ctrlEnable true;};
	
		
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
				case (_state in _weapons && _timeMax <= _newtime) : {
				   _btnAbort ctrlEnable false;
					cutText ["-ANTIDUPE- Switch to primary weapon, or drop pistol, or put pistol in backpack to log out -ANTIDUPE-", "PLAIN"];
				};	
				default {
					_btnAbort ctrlEnable true;
					cutText ["Thank You For Playing In The Den", "PLAIN DOWN"];				
				};
			};
			sleep .1;
			_timeOut = _timeOut + 1;
		};
		cutText ["", "PLAIN DOWN"];
