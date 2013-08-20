
disableSerialization;
if ((ctrlText ((findDisplay 63) displayCtrl 101) == 'Side Channel')) then
{
	[] spawn
	{
		if (isNil "disconnect_timer") then {disconnect_timer = 0};
		if (disconnect_timer == 0) then {
			disconnect_timer = 1;
			sleep 1.25;//Combat log fix. Disconnects after talking on side continously for 6 seconds.
			disconnect_timer = 0;
		};
	};
	[] spawn
	{
		sleep 30;//Resets their strikes after this time.
		disconnect_me = 0;
		warn_one 	= nil;
		warn_two 	= nil;
		warn_three 	= nil;
		warn_last 	= nil;
	};
	really_loud_sounds =
	{
		[60,15] call fnc_usec_pitchWhine;
		for "_i" from 1 to 15 do {playSound format ['%1',_this select 0];};
	};
	double_cut =
	{
		1 cutText [format ["%1",_this select 0],"PLAIN DOWN"];
		2 cutText [format ["%1",_this select 0],"PLAIN"];
	};
	slap_them =
	{
		_randomnr = [2,-1] call BIS_fnc_selectRandom;
		(vehicle player) SetVelocity [_randomnr * random (4) * cos getdir (vehicle player), _randomnr * random (4) * cos getdir (vehicle player), random (4)];
	};
	if (isNil "disconnect_me") then {disconnect_me = 0;} else {sleep 0.25;if (disconnect_timer == 1) exitWith {};disconnect_me = disconnect_me + 1;};
	if (disconnect_me == 0) then
	{
		if (isNil 'warn_one') then
		{
			warn_one = true;
			systemChat ('Please do not use voice on sidechat, this is your first warning.');
			[] spawn slap_them;
			["beat04"] spawn really_loud_sounds;
			["NO VOICE ON SIDE"] spawn double_cut;
		};
	};
	if (disconnect_me == 1) then
	{
		if (isNil 'warn_two') then
		{
			warn_two = true;
			systemChat ('Please do not use voice on sidechat, this is your second warning..');
			[] spawn slap_them;
			["beat04"] spawn really_loud_sounds;
			["NO VOICE ON SIDE"] spawn double_cut;
		};
	};
	if (disconnect_me == 2) then
	{
		if (isNil 'warn_three') then
		{
			warn_three = true;
			systemChat ('PLEASE DO NOT USE VOICE ON SIDECHAT!! This is your LAST warning!');
			systemChat ('You will be frozen and then disconnected!');
			[] spawn slap_them;
			["beat04"] spawn really_loud_sounds;
			["NO VOICE ON SIDE! This is your LAST warning!"] spawn double_cut;
		};
	};
	if (disconnect_me >= 3) then
	{
		if (isNil 'warn_last') then
		{
			warn_last = true;
			playMusic ["PitchWhine",0];
			[] spawn slap_them;
			["beat04"] spawn really_loud_sounds;
			["We warned you..."] spawn double_cut;
			1 fademusic 10;
			1 fadesound 10;
			disableUserInput true;
			startLoadingScreen ["You are being disconnected", "DayZ_loadingScreen"];
			progressLoadingScreen 0.2;sleep 2;["All_Haha"] spawn really_loud_sounds;
			progressLoadingScreen 0.4;sleep 2.25;
			progressLoadingScreen 0.6;sleep 2;["All_Haha"] spawn really_loud_sounds;
			progressLoadingScreen 0.8;sleep 2.25;
			progressLoadingScreen 1.0;sleep 2;["All_Haha"] spawn really_loud_sounds;
			endLoadingScreen;
			sleep 0.5;
			disableUserInput false;
			endMission "LOSER";
		};
	};
};
