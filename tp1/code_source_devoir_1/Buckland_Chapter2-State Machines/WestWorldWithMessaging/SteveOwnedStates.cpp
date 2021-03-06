#include "SteveOwnedStates.h"
#include "fsm/State.h"
#include "Steve.h"
#include "Locations.h"
#include "messaging/Telegram.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "Time/CrudeTimer.h"
#include "EntityNames.h"

#include <iostream>
using std::cout;


#ifdef TEXTOUTPUT
#include <fstream>
#include "SteveOwnedStates.h"
#include "MinerOwnedStates.h"
extern std::ofstream os;
#define cout os
#endif

//-------------------------------------------------------------------------Drinking

Drinking * Drinking::Instance()
{
	static Drinking instance;

	return &instance;
}

void Drinking::Enter(Steve * steve)
{
	cout << "\n" << GetNameOfEntity(steve->ID()) << ": " << "'This beer is so good !'";
}

void Drinking::Execute(Steve * steve)
{
	cout << "\n" << GetNameOfEntity(steve->ID()) << ": " << "execute drinking!!";

	if ((rand()) / (RAND_MAX + 1.0) < 0.1) {
		steve->GetFSM()->ChangeState(Drunk::Instance());
	}
}

void Drinking::Exit(Steve * steve)
{
	cout << "\n" << GetNameOfEntity(steve->ID()) << ": " << "exit drinking!";
}

bool Drinking::OnMessage(Steve * agent, const Telegram & msg)
{
	return false;
}



//-------------------------------------------------------------------------Drunk

Drunk* Drunk::Instance()
{
	static Drunk instance;

	return &instance;
}


void Drunk::Enter(Steve* steve)
{
	cout << "\n" << GetNameOfEntity(steve->ID()) << ": " << "I am drunk maybe!";
	
}

void Drunk::Execute(Steve* steve)
{
	cout << "\n" << GetNameOfEntity(steve->ID()) << ": " << "'Bob, you are full of shit!'";

	
	
	//Defy Steve
	Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY, //time delay
		steve->ID(),        //ID of sender
		ent_Miner_Bob,            //ID of recipient
		Msg_Defy,   //the message
		NO_ADDITIONAL_INFO);
}

void Drunk::Exit(Steve* steve)
{
	cout << "\n" << GetNameOfEntity(steve->ID()) << ": " << "Leaving drunk state";
}


bool Drunk::OnMessage(Steve* steve, const Telegram& msg)
{
	//send msg to global message handler
	switch (msg.Msg)
	{
	case Msg_BeHit:
	{
		SetTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "\nMessage received by " << GetNameOfEntity(steve->ID()) <<
			" it is so hurt: ";

		steve->GetFSM()->ChangeState(Fighting::Instance());
		
	}

	return true;

	}//end switch

	return false;
}

Fighting * Fighting::Instance()
{
	static Fighting instance;

	return &instance;
}


void Fighting::Enter(Steve * steve)
{
	cout << "\n" << GetNameOfEntity(steve->ID()) << ": " << "'Okay Bob, let's fight you and me !'";
}

void Fighting::Execute(Steve * steve)
{
	cout << "\n" << GetNameOfEntity(steve->ID()) << ": " << "Steve and Bob are fighting !";
	steve->GetFSM()->ChangeState(Drinking::Instance());
}

void Fighting::Exit(Steve * steve)
{
	cout << "\n" << GetNameOfEntity(steve->ID()) << ": " << "Fight stops!";
}

bool Fighting::OnMessage(Steve * agent, const Telegram & msg)
{
	return false;
}
