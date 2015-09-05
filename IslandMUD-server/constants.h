/* Jim Viebke
Feb 14, 2015 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <map>
#include <vector>

using namespace std;

class Constants; // forward declaring...

typedef Constants C; // ...in order to put this up here

class Constants
{
public:

	// general
	const static int
		GROUND_INDEX,
		VIEW_DISTANCE,

		WORLD_X_DIMENSION,
		WORLD_Y_DIMENSION,
		WORLD_Z_DIMENSION,

		DEFAULT_SPAWN_X,
		DEFAULT_SPAWN_Y,
		DEFAULT_SPAWN_Z;

	// game data locations
	static const string game_directory;
	static const string world_terrain_file_location;
	static const string world_biome_file_location;
	static const string room_directory;
	static const string user_data_directory;

	// faction IDs
	const static string PC_FACTION_ID; // players ("PCs")
	const static string NPC_NEUTRAL_FACTION_ID; // neutral island inhabitants
	const static string NPC_HOSTILE_FACTION_ID; // antagonists

	// map symbols
	const static char
		PLAYER_CHAR,
		NPC_NEUTRAL_CHAR,
		WATER_CHAR,
		LAND_CHAR,
		FOREST_CHAR,
		ITEM_CHAR,
		CHEST_CHAR,
		RUBBLE_CHAR;

	const static string
		// engine signals
		GOOD_SIGNAL,
		BAD_SIGNAL,

		// item IDs
		BAD_ITEM_ID,

		SMELTER_ID,
		FORGE_ID,
		ANVIL_ID,
		DEBRIS_ID, // collapsed ceilings

		// item IDs -> materials
		WOOD_ID,
		STONE_ID,
		VINE_ID,
		STICK_ID,
		BRANCH_ID,
		ARROW_ID,
		ARROWHEAD_ID,
		BOARD_ID,

		// item IDs -. other
		TREE_ID,
		CHEST_ID,
		LOG_ID,

		// item IDs -> equipment
		AXE_ID,
		STAFF_ID,
		SWORD_ID,
		BOW_ID,
		TORCH_ID,
		HAMMER_ID,

		// commands
		BAD_COMMAND,

		// action commands
		LOGIN_COMMAND,
		LOGOUT_COMMAND,
		HELP_COMMAND,
		CRAFT_COMMAND,
		TAKE_COMMAND,
		EQUIP_COMMAND,
		ITEM_COMMAND, // view equipped item
		DEQUIP_COMMAND,
		MOVE_COMMAND,
		DROP_COMMAND,
		INSERT_COMMAND,
		FROM_COMMAND,
		CONSTRUCT_COMMAND, // room sides
		WAIT_COMMAND, // dev only. World is real-time.
		WITH_COMMAND,
		PRINT_RECIPES_COMMAND, // dev only. No full recipe printout in normal game.
		ATTACK_COMMAND,

		// direction commands/IDs
		NORTH,
		NORTH_EAST,
		EAST,
		SOUTH_EAST,
		SOUTH,
		SOUTH_WEST,
		WEST,
		NORTH_WEST,

		// floor and ceiling IDs + directions
		FLOOR,
		CEILING,

		UP,
		DOWN,

		// doors and walls
		SURFACE,
		WALL,
		DOOR,

		// room xml
		XML_ROOM,
		XML_IS_WATER,
		XML_ITEM,
		XML_ITEM_HEALTH,
		XML_SURFACE,
		XML_SURFACE_HEALTH,
		XML_SURFACE_DIRECTION,
		XML_SURFACE_MATERIAL,
		XML_DOOR,
		XML_DOOR_HEALTH,
		XML_DOOR_MATERIAL,
		XML_DOOR_FACTION,
		XML_CHEST,
		XML_CHEST_HEALTH,
		XML_CHEST_EQUIPMENT,
		XML_CHEST_MATERIALS,
		XML_CHEST_MATERIALS_COUNT,

		// user data xml
		XML_USER_STATUS,
		XML_USER_STATUS_CURRENT_HEALTH,
		XML_USER_LOCATION,
		XML_USER_LEVELS,
		XML_USER_EQUIPMENT,
		XML_USER_MATERIALS,
		XML_USER_MATERIAL_COUNT,

		// user level xml
		XML_LEVEL_SWORDSMANSHIP,
		XML_LEVEL_ARCHERY,
		XML_LEVEL_FOREST_VISIBILITY,
		XML_LEVEL_HEALTH_MAX,

		// user health xml
		XML_CURRENT_HEALTH;

	// item health/integrity
	static const int
		DEFAULT_ITEM_MIN_HEALTH,
		DEFAULT_ITEM_MAX_HEALTH;

	// int to char conversion
	static const vector<char> numbers;

	// surface information
	static const vector<string> surface_ids;
	static const vector<string> direction_ids;
	static const vector<string> primary_direction_ids; // NESW
	static const map<string, string> opposite_surface_id;
	static const map<string, string> opposite_direction_id;

	// maps material IDs to the material count required to make a surface
	// therefore also acts as the list of valid construction surfaces (see implementation)
	const static map<string, unsigned> SURFACE_REQUIREMENTS;
	const static map<string, unsigned> DOOR_REQUIREMENTS;

	// box drawing (more explaination at implementation)

	const static char
		NW_CORNER,
		NE_CORNER,
		SW_CORNER,
		SE_CORNER,

		NES_CORNER,
		ESW_CORNER,
		NSW_CORNER,
		NEW_CORNER,

		NESW,

		NS_WALL,
		WE_WALL,

		NS_DOOR,
		WE_DOOR;

	// more box drawing

	const static vector<char> CORNERS;

	// walls, ceiling, and floor - min and max health

	const static int
		MIN_SURFACE_HEALTH,
		MAX_SURFACE_HEALTH,
		MAX_DOOR_HEALTH;

	const static map<string, map<string, int>> damage_tables;

	// AI constants
	const static int
		AI_MAX_OBJECTIVE_ATTEMPTS; // the point at which an AI must return control

	const static int
		// AI movement costs
		AI_MOVEMENT_COST,
		AI_MOVEMENT_COST_DIAGONAL,
		AI_MOVEMENT_COST_FOREST,
		AI_MOVEMENT_COST_FOREST_DIAGONAL,

		// levels
		SWORDSMANSHIP_LEVEL_MIN,
		SWORDSMANSHIP_LEVEL_MAX,
		ARCHERY_LEVEL_MIN,
		ARCHERY_LEVEL_MAX,
		FOREST_VISIBILITY_LEVEL_MIN,
		FOREST_VISIBILITY_LEVEL_MAX,
		HEALTH_MIN, // explaination in source
		FULL_HEALTH_MIN,
		FULL_HEALTH_MAX;

	// AI objective keywords
	const static string
		AI_OBJECTIVE_ACQUIRE,
		AI_OBJECTIVE_GOTO,
		AI_OBJECTIVE_CONSTRUCT;

	const static int
		MAX_CHEST_HEALTH;

	// NPC types
	const static string
		AI_TYPE_FIGHTER,
		AI_TYPE_WORKER,
		AI_TYPE_BLACKSMITH,
		AI_TYPE_WATCH_GUARD,
		AI_TYPE_PATROL_GUARD,
		AI_TYPE_MINER;

	const static int
		FORTRESS_PARTITION_MIN_SIZE,
		FORTRESS_MIN_X,
		FORTRESS_MAX_X,
		FORTRESS_MIN_Y,
		FORTRESS_MAX_Y;
};

#endif
