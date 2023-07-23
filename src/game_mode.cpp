#include "game_mode.h"

void GameMode::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("get_player_prefab"), &GameMode::get_player_prefab);
	ClassDB::bind_method(D_METHOD("set_player_prefab", "prefab"), &GameMode::set_player_prefab);

	ADD_PROPERTY(
		PropertyInfo(Variant::OBJECT, "player_prefab"),
		"set_player_prefab",
		"get_player_prefab"
	);
}

void GameMode::_ready()
{
	player_node = player_prefab->instantiate();
	add_child(player_node);
}

Ref<PackedScene> GameMode::get_player_prefab()
{
	return player_prefab;
}

void GameMode::set_player_prefab(Ref<PackedScene> scene)
{
	player_prefab = scene;
}

