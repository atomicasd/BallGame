#pragma once

enum CompCommands
{
	COMMAND_DIE,
	COMMAND_REMOVE,
	COMMAND_TAKEDAMAGE,
	COMMAND_TAKEPARENTEDDAMAGE,
	COMMAND_CONVERTDAMAGE, // other components can have protection against types of damage, we need them to convert it to pure
	COMMAND_TAKEBLAST, //Take blast from explosion
	COMMAND_SPAWNOBJECT

};