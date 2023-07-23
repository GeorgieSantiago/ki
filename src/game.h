#ifndef COQUI_GAME_H
#define COQUI_GAME_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/directional_light3d.hpp>
#include <godot_cpp/classes/world_environment.hpp>
#include <godot_cpp/classes/navigation_region3d.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

class Game : public Node
{
	GDCLASS(Game, Node)
protected:
	static void _bind_methods();
public:

	NavigationRegion3D* region_ptr;
	NodePath region;
	NodePath get_region();
	void set_region(NodePath _region);
	void _ready() override;
};

#endif
