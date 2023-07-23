#include "game.h"

void Game::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("set_region", "_region"), &Game::set_region);
	ClassDB::bind_method(D_METHOD("get_region"), &Game::get_region);

	ADD_PROPERTY(
		PropertyInfo(Variant::NODE_PATH, "region"),
		"set_region",
		"get_region"
	);
}

NodePath Game::get_region()
{
	return region;
}

void Game::set_region(NodePath _region)
{
	region = _region;
}

void Game::_ready()
{
	region_ptr = get_node<NavigationRegion3D>(region);
	if (region_ptr != nullptr)
	{
		region_ptr->bake_navigation_mesh();
		UtilityFunctions::print("Nav Mesh Baked!");
	}
}