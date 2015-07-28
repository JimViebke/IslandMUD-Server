/* Jim Viebke
Feb 16 2015 */

#include "parse.h"

map<string, string> Parse::dict; // first string maps to second string

void Parse::initialize()
{
	// map various possible user-input strings to the constant ID used throughout the engine

	if (dict.size() == 0)
	{
		cout << "\nLoading parse dictionary...";

		// test commands
		P::dict["recipe"] = P::dict["recipes"] = C::PRINT_RECIPES_COMMAND;

		// verbs
		P::dict["help"] = P::dict["h"] = P::dict["q"] = P::dict["?"] = P::dict["assist"] = C::HELP_COMMAND;
		// P::dict["login"] = C::LOGIN_COMMAND; // not used yet
		P::dict["logout"] = P::dict["quit"] = P::dict["leave"] = C::LOGOUT_COMMAND;
		P::dict["move"] = P::dict["m"] = P::dict["walk"] = P::dict["run"] = P::dict["head"] = P::dict["go"] = P::dict["continue"] = C::MOVE_COMMAND;
		P::dict["take"] = P::dict["get"] = P::dict["pick"] = P::dict["choose"] = P::dict["grab"] = P::dict["acquire"] = C::TAKE_COMMAND;
		P::dict["equip"] = P::dict["weild"] = P::dict["wield"] = P::dict["ready"] = C::EQUIP_COMMAND;
		P::dict["dequip"] = P::dict["deequip"] = P::dict["unequip"] = P::dict["unwield"] = P::dict["unweild"] = P::dict["store"] = C::DEQUIP_COMMAND;
		P::dict["craft"] = P::dict["make"] = P::dict["create"] = P::dict["fashion"] = C::CRAFT_COMMAND;
		P::dict["drop"] = P::dict["release"] = P::dict["unhand"] = C::DROP_COMMAND;
		P::dict["wait"] = P::dict["pause"] = P::dict["consider"] = P::dict["delay"] = C::WAIT_COMMAND;
		P::dict["with"] = C::WITH_COMMAND;
		P::dict["construct"] = P::dict["build"] = P::dict["erect"] = C::CONSTRUCT_COMMAND;
		P::dict["attack"] = P::dict["smash"] = P::dict["strike"] = P::dict["bash"] = P::dict["break"] = P::dict["damage"] = P::dict["stab"] = P::dict["slash"] = C::ATTACK_COMMAND;
		
		// items
		P::dict["tree"] = C::TREE_ID;
		P::dict["smelter"] = C::SMELTER_ID;
		P::dict["forge"] = C::FORGE_ID;
		P::dict["anvil"] = C::ANVIL_ID;

		// items -> materials
		P::dict["stone"] = P::dict["rock"] = C::STONE_ID;
		P::dict["branch"] = P::dict["branches"] = C::BRANCH_ID;
		P::dict["stick"] = C::STICK_ID;
		P::dict["vine"] = C::VINE_ID;
		P::dict["arrow"] = C::ARROW_ID;
		P::dict["arrowhead"] = C::ARROWHEAD_ID;

		// items -> tools
		P::dict["bow"] = C::BOW_ID;
		P::dict["staff"] = C::STAFF_ID;
		P::dict["axe"] = C::AXE_ID;
		P::dict["sword"] = C::SWORD_ID;
		P::dict["hammer"] = C::HAMMER_ID;

		// directions
		P::dict["n"] = P::dict["north"] = C::NORTH;
		P::dict["ne"] = P::dict["northeast"] = C::NORTH_EAST;
		P::dict["e"] = P::dict["east"] = C::EAST;
		P::dict["se"] = P::dict["southeast"] = C::SOUTH_EAST;
		P::dict["s"] = P::dict["south"] = C::SOUTH;
		P::dict["sw"] = P::dict["southwest"] = C::SOUTH_WEST;
		P::dict["w"] = P::dict["west"] = C::WEST;
		P::dict["nw"] = P::dict["northwest"] = C::NORTH_WEST;
		P::dict["u"] = P::dict["up"] = P::dict["upward"] = P::dict["upwards"] = P::dict["upstairs"] = C::UP;
		P::dict["d"] = P::dict["down"] = P::dict["downward"] = P::dict["downwards"] = P::dict["downstairs"] = C::UP;

		// surfaces not already in directions
		P::dict["floor"] = P::dict["ground"] = C::FLOOR;
		P::dict["ceiling"] = C::CEILING;

		// Look Mr. Frodo! A
		P::dict["door"] = C::DOOR;
		P::dict["wall"] = P::dict["surface"] = C::WALL;
	}
}

vector<string> Parse::tokenize(const string & s)
{
	// converts an input string to vector of "engine official" keywords/commands

	cout << "\nDEBUG inside parse.tokenize: "; // debugging

	// convert the (space-delimited) user input to a vector of strings (one word per element)
	stringstream ss(s);
	const istream_iterator<string> begin(ss);
	const istream_iterator<string> end;
	vector<string> strings(begin, end);

	R::print(strings); // debugging

	R::to_lower_case(strings); // convert all input to lower case

	for (string & word : strings) // for each word
	{
		// replace each word with the engine keyword, or C::BAD_COMMAND
		word = (dict.find(word) != dict.end()) ? dict.find(word)->second : C::BAD_COMMAND;
	}

	return strings;
}
